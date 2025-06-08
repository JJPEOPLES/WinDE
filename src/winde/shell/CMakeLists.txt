set(winde_shell_SRCS
    main.cpp
    windeshell.cpp
    shellwindow.cpp
)

add_executable(winde-shell ${winde_shell_SRCS})

target_link_libraries(winde-shell
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::DBus
    Qt5::X11Extras
    KF5::ConfigCore
    KF5::CoreAddons
    KF5::I18n
    KF5::WindowSystem
    KF5::Plasma
    KF5::PlasmaQuick
    ${X11_LIBRARIES}
)

install(TARGETS winde-shell ${KDE_INSTALL_TARGETS_DEFAULT_ARGS}) 