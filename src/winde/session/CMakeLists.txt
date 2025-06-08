set(winde_session_SRCS
    sessionmanager.cpp
)

add_library(winde-session STATIC ${winde_session_SRCS})

target_link_libraries(winde-session
    Qt5::Core
    Qt5::DBus
    KF5::ConfigCore
)

install(FILES winde-session DESTINATION ${CMAKE_INSTALL_BINDIR}
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
                  GROUP_READ GROUP_EXECUTE
                  WORLD_READ WORLD_EXECUTE) 