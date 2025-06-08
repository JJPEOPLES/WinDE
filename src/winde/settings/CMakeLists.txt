set(winde_settings_SRCS
    settingsmanager.cpp
    settingsdialog.cpp
    appearancepage.cpp
    taskbarpage.cpp
    systempage.cpp
)

add_library(winde-settings STATIC ${winde_settings_SRCS})

target_link_libraries(winde-settings
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    KF5::ConfigCore
    KF5::I18n
) 