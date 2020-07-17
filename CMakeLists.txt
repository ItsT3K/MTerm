cmake_minimum_required(VERSION 3.16)
project(MTerm)
add_executable(MTerm main.c)

find_package(PkgConfig REQUIRED)
pkg_check_modules(APP REQUIRED gtk+-3.0>=3.0 glib-2.0>=2.10 vte-2.91>=vte-2.0)

target_link_directories(MTerm PUBLIC ${APP_LIBRARY_DIRS})
target_link_libraries(MTerm ${APP_LIBRARIES})
target_include_directories(MTerm PUBLIC ${APP_INCLUDE_DIRS})