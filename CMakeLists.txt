cmake_minimum_required(VERSION 2.6)
project(tsp-kp-2k17)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        Controller.cpp
        Controller.h
        Graph.cpp
        Graph.h
        Edge.cpp
        Edge.h
        Console.cpp
        Console.h
        Menu.cpp
        Menu.h
        File.cpp
        File.h
        Message.cpp
        Message.h
        Knapsack.cpp
        Knapsack.h
        Item.cpp
        Item.h
        ArrayList.cpp
        ArrayList.h
        TravellingSalesman.cpp
        TravellingSalesman.h)
add_executable(tsp-kp-2k17 ${SOURCE_FILES})
