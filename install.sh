#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to print status messages
print_status() {
    echo -e "${GREEN}[*]${NC} $1"
}

print_error() {
    echo -e "${RED}[!]${NC} $1"
}

print_warning() {
    echo -e "${YELLOW}[!]${NC} $1"
}

# Check if script is run as root
if [ "$EUID" -ne 0 ]; then
    print_error "Please run this script as root (sudo ./install.sh)"
    exit 1
fi

# Detect distribution
if [ -f /etc/os-release ]; then
    . /etc/os-release
    DISTRO=$ID
    
    # Check for Debian-based distributions
    if [ -f /etc/debian_version ]; then
        DEBIAN_BASED=true
    fi
else
    print_error "Could not detect Linux distribution"
    exit 1
fi

# Clean build directory if it exists
clean_build() {
    if [ -d "build" ]; then
        print_status "Cleaning previous build directory..."
        rm -rf build
    fi
}

# Install dependencies based on distribution
install_dependencies() {
    if [ "$DISTRO" = "kali" ] || [ "$DEBIAN_BASED" = "true" ]; then
        print_status "Installing dependencies for Kali/Debian-based system..."
        apt update
        apt install -y build-essential cmake extra-cmake-modules \
            qtbase5-dev libkf5windowsystem-dev libkf5configwidgets-dev \
            libkf5coreaddons-dev libkf5notifications-dev libkf5plasma-dev \
            kwin-x11 picom dunst git \
            qttools5-dev libkf5crash-dev libkf5dbusaddons-dev \
            libkf5declarative-dev libkf5xmlgui-dev libkf5iconthemes-dev \
            libkf5package-dev libkf5parts-dev libkf5textwidgets-dev \
            libqt5x11extras5-dev qtdeclarative5-dev \
            libkf5activities-dev libkf5kio-dev libkf5newstuff-dev \
            libxcb-util0-dev libkf5globalaccel-dev libdbus-1-dev \
            libqt5svg5-dev qttools5-dev-tools
        
        # Check if installation was successful
        if [ $? -ne 0 ]; then
            print_warning "Some packages might be missing. Trying alternative repositories..."
            # Add KDE Neon repository as fallback for missing packages
            echo "deb http://archive.neon.kde.org/release focal main" | tee /etc/apt/sources.list.d/neon.list
            wget -qO - https://archive.neon.kde.org/public.key | apt-key add -
            apt update
            apt install -y build-essential cmake extra-cmake-modules \
                qtbase5-dev libkf5windowsystem-dev libkf5configwidgets-dev \
                libkf5coreaddons-dev libkf5notifications-dev libkf5plasma-dev \
                kwin-x11 picom dunst git \
                libqt5x11extras5-dev qtdeclarative5-dev
        fi
    elif [ "$DISTRO" = "ubuntu" ] || [ "$DISTRO" = "debian" ]; then
        print_status "Installing dependencies for Ubuntu/Debian..."
        apt update
        apt install -y build-essential cmake extra-cmake-modules \
            qtbase5-dev libkf5windowsystem-dev libkf5configwidgets-dev \
            libkf5coreaddons-dev libkf5notifications-dev libkf5plasma-dev \
            kwin-x11 picom dunst git \
            libqt5x11extras5-dev qtdeclarative5-dev
    elif [ "$DISTRO" = "fedora" ]; then
        print_status "Installing dependencies for Fedora..."
        dnf install -y cmake extra-cmake-modules qt5-qtbase-devel \
            kf5-kwindowsystem-devel kf5-kconfigwidgets-devel \
            kf5-kcoreaddons-devel kf5-knotifications-devel kf5-plasma-devel \
            kwin picom dunst git \
            qt5-qtx11extras-devel qt5-qtdeclarative-devel
    elif [ "$DISTRO" = "arch" ] || [ "$DISTRO" = "manjaro" ]; then
        print_status "Installing dependencies for Arch/Manjaro..."
        pacman -Sy --noconfirm base-devel cmake extra-cmake-modules qt5-base \
            kwindowsystem kconfigwidgets kcoreaddons knotifications plasma-framework \
            kwin picom dunst git \
            qt5-x11extras qt5-declarative
    else
        print_error "Unsupported distribution: $DISTRO"
        print_warning "You can try installing the following packages manually:"
        echo "- build-essential or base-devel"
        echo "- cmake"
        echo "- extra-cmake-modules"
        echo "- Qt5 development packages (including X11Extras)"
        echo "- KDE Frameworks 5 development packages"
        echo "- kwin"
        echo "- picom"
        echo "- dunst"
        exit 1
    fi
}

# Create necessary directories
setup_directories() {
    print_status "Creating necessary directories..."
    mkdir -p /usr/share/winde/wallpapers
    mkdir -p /usr/share/winde/themes
    mkdir -p /etc/winde
}

# Initialize git repository if needed
init_git() {
    print_status "Initializing git repository..."
    if [ ! -d ".git" ]; then
        git init
        git add .
        git commit -m "Initial commit"
    fi
}

# Build and install WinDE
build_winde() {
    print_status "Building WinDE..."
    
    # Create build directory
    mkdir -p build
    cd build

    # Configure with CMake
    print_status "Running CMake configuration..."
    cmake .. || {
        print_error "CMake configuration failed"
        print_warning "Please check if all dependencies are installed correctly"
        cd ..
        exit 1
    }

    # Build
    print_status "Compiling WinDE..."
    make -j$(nproc) || {
        print_error "Build failed"
        print_warning "Please check the error messages above"
        cd ..
        exit 1
    }

    # Install
    print_status "Installing WinDE..."
    make install || {
        print_error "Installation failed"
        print_warning "Please check if you have sufficient permissions"
        cd ..
        exit 1
    }

    cd ..
}

# Set up session
setup_session() {
    print_status "Setting up WinDE session..."
    
    # Make session script executable
    if [ -f /usr/bin/winde-session ]; then
        chmod +x /usr/bin/winde-session
    else
        print_warning "Session script not found in /usr/bin/winde-session"
        print_status "Copying session script..."
        cp src/winde/session/winde-session /usr/bin/
        chmod +x /usr/bin/winde-session
    fi

    # Create session file
    if [ -d /usr/share/xsessions ]; then
        cp winde-session.desktop /usr/share/xsessions/
    else
        mkdir -p /usr/share/xsessions
        cp winde-session.desktop /usr/share/xsessions/
    fi
}

# Main installation process
main() {
    print_status "Starting WinDE installation..."
    
    # Clean previous build
    clean_build
    
    # Initialize git repository
    init_git
    
    # Install dependencies
    install_dependencies

    # Setup directories
    setup_directories

    # Build and install
    build_winde

    # Setup session
    setup_session

    print_status "Installation complete!"
    print_status "You can now select 'WinDE' from your login screen"
    print_warning "Please log out and select WinDE from your session menu to start using it"
}

# Start installation
main 