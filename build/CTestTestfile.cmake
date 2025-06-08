# CMake generated Testfile for 
# Source directory: /home/jjshandy6161/Public/WinDE
# Build directory: /home/jjshandy6161/Public/WinDE/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(appstreamtest "/usr/bin/cmake" "-DAPPSTREAMCLI=/usr/bin/appstreamcli" "-DINSTALL_FILES=/home/jjshandy6161/Public/WinDE/build/install_manifest.txt" "-P" "/usr/share/ECM/kde-modules/appstreamtest.cmake")
set_tests_properties(appstreamtest PROPERTIES  _BACKTRACE_TRIPLES "/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;168;add_test;/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;187;appstreamtest;/usr/share/ECM/kde-modules/KDECMakeSettings.cmake;0;;/home/jjshandy6161/Public/WinDE/CMakeLists.txt;13;include;/home/jjshandy6161/Public/WinDE/CMakeLists.txt;0;")
subdirs("src/winde/shell")
subdirs("src/winde/panel")
subdirs("src/winde/window-manager")
subdirs("src/winde/settings")
subdirs("src/winde/compositor")
subdirs("src/winde/session")
