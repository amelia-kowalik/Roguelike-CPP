cmake_minimum_required(VERSION 3.23)
project(lotr)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_HEADERS
        Game.h
        Level.h
        Character.h
        Tile.h
        Item.h
        )
set(PROJECT_SOURCES
        main.cpp
        Game.cpp
        Level.cpp
        Character.cpp
        Tile.cpp
        Item.cpp
        )

add_executable(lotr ${PROJECT_SOURCES} ${PROJECT_HEADERS})
