set(winde_wm_SRCS
    windowmanager.cpp
    windowdecorator.cpp
    effects.cpp
)

add_library(winde-wm STATIC ${winde_wm_SRCS})

target_link_libraries(winde-wm
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::X11Extras
    KF5::WindowSystem
    KF5::ConfigCore
    ${X11_LIBRARIES}
) 