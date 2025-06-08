set(winde_panel_SRCS
    panel.cpp
    taskbar.cpp
    systray.cpp
    startbutton.cpp
    clock.cpp
)

add_library(winde-panel STATIC ${winde_panel_SRCS})

target_link_libraries(winde-panel
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::DBus
    Qt5::X11Extras
    KF5::WindowSystem
    KF5::ConfigCore
    KF5::Plasma
    KF5::PlasmaQuick
) 