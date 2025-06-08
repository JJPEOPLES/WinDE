# WinDE - Windows-like Desktop Environment

WinDE is a custom desktop environment that aims to provide a Windows-like experience while being built on modern Linux technologies. It uses KDE Frameworks for the underlying functionality while providing a completely custom shell and user experience that closely mimics Windows.

## Features

- Custom shell implementation that looks and feels like Windows
- Windows-style taskbar with start menu
- Window management with Windows-like decorations
- System tray with Windows-style notifications
- Desktop icons and right-click context menus
- Windows-style file manager integration
- Modern compositor effects

## Dependencies

### Build Dependencies
- CMake (>= 3.16)
- Qt5 (>= 5.15)
- KDE Frameworks 5 (>= 5.90)
- Extra CMake Modules
- C++ compiler with C++17 support

### Runtime Dependencies
- X11 or Wayland
- KWin (window manager)
- Picom (compositor)
- D-Bus
- dunst (notifications)

## Building from Source

1. Install the required dependencies:

```bash
# For Ubuntu/Debian
sudo apt install build-essential cmake extra-cmake-modules \
    qtbase5-dev libkf5windowsystem-dev libkf5configwidgets-dev \
    libkf5coreaddons-dev libkf5notifications-dev libkf5plasma-dev \
    kwin-x11 picom dunst

# For Fedora
sudo dnf install cmake extra-cmake-modules qt5-qtbase-devel \
    kf5-kwindowsystem-devel kf5-kconfigwidgets-devel \
    kf5-kcoreaddons-devel kf5-knotifications-devel kf5-plasma-devel \
    kwin picom dunst
```

2. Clone the repository:
```bash
git clone https://github.com/yourusername/WinDE.git
cd WinDE
```

3. Create build directory and compile:
```bash
mkdir build
cd build
cmake ..
make -j$(nproc)
```

4. Install:
```bash
sudo make install
```

## Installation

After building and installing, WinDE will be available as a session option in your display manager (login screen). Simply select "WinDE" from the session menu before logging in.

## Configuration

WinDE uses standard XDG configuration directories. User-specific configuration files are stored in:
- `~/.config/winde/` - Main configuration directory
- `~/.local/share/winde/` - Data files

## Contributing

Contributions are welcome! Please feel free to submit pull requests or create issues for bugs and feature requests.

## License

This project is licensed under the GNU General Public License v3.0 - see the LICENSE file for details.

## Acknowledgments

- KDE Community for the excellent frameworks
- Qt Company for Qt
- Various open-source projects that make this possible 