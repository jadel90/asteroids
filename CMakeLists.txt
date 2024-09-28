cmake_minimum_required(VERSION 3.29)
project(asteroids C)

set(CMAKE_C_STANDARD 11)

# Manually specify the include and library paths
set(CURSES_INCLUDE_DIRS "C:/path/to/ncurses/include")
set(CURSES_LIBRARIES "C:/path/to/ncurses/lib/ncurses.a")

# Include directories
include_directories(${CURSES_INCLUDE_DIRS})

# Add the executable target
add_executable(asteroids
        asteroids.c
        move_ship.c)

# Link the ncurses library to the executable
target_link_libraries(asteroids ${CURSES_LIBRARIES})