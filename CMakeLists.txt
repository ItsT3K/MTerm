cmake_minimum_required(VERSION 3.16)
project(mterm)
add_executable(mterm main.c)

find_package(PkgConfig REQUIRED)
pkg_check_modules(APP REQUIRED gtk+-3.0>=3.0 glib-2.0>=2.10 vte-2.91>=vte-2.0)

target_link_directories(mterm PUBLIC ${APP_LIBRARY_DIRS})
target_link_libraries(mterm ${APP_LIBRARIES})
target_include_directories(mterm PUBLIC ${APP_INCLUDE_DIRS})
target_compile_definitions(mterm PUBLIC ICONPATH="${CMAKE_INSTALL_PREFIX}/share/icon.png")

install(TARGETS mterm DESTINATION bin)
install(FILES icon.png DESTINATION share)
install(FILES mterm.1.gz DESTINATION share/man/man1)
install(FILES pixifont2.ttf DESTINATION share/fonts)
