set(winde_compositor_SRCS
    compositor.cpp
    effects.cpp
    animations.cpp
)

add_library(winde-compositor STATIC ${winde_compositor_SRCS})

target_link_libraries(winde-compositor
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::X11Extras
    KF5::WindowSystem
    KF5::ConfigCore
    ${X11_LIBRARIES}
) 