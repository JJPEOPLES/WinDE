cmake_minimum_required(VERSION 3.16)
project(WinDE VERSION 0.1.0 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required KDE packages
find_package(ECM 5.90.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)
include(ECMSetupVersion)
include(ECMGenerateHeaders)
include(ECMQtDeclareLoggingCategory)

# Find Qt packages
find_package(Qt5 REQUIRED COMPONENTS 
    Core
    Gui
    Widgets
    DBus
    X11Extras
)

# Find KDE Frameworks
find_package(KF5 REQUIRED COMPONENTS
    Config
    CoreAddons
    I18n
    WindowSystem
    Plasma
    PlasmaQuick
    KIO
    Notifications
)

# Find X11 libraries
find_package(X11 REQUIRED)

# Subdirectories
add_subdirectory(src/winde/shell)
add_subdirectory(src/winde/panel)
add_subdirectory(src/winde/window-manager)
add_subdirectory(src/winde/settings)
add_subdirectory(src/winde/compositor)
add_subdirectory(src/winde/session)

# Installation paths
install(FILES winde-session.desktop DESTINATION ${KDE_INSTALL_DATADIR}/xsessions)
install(FILES winde-settings.desktop DESTINATION ${KDE_INSTALL_DATADIR}/applications) 