cmake_minimum_required(VERSION 3.3)
project(ProjectBuses)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Bus.cpp
    Bus.h
    BusLine.cpp
    BusLine.h
    Connection.cpp
    Connection.h
    Main.cpp
    Passenger.cpp
    Passenger.h
    FileTools.h
    FileTools.cpp
    Main.h
        TablePointers.h PassangerWithDiscount.cpp PassangerWithDiscount.h)

add_executable(ProjectBuses ${SOURCE_FILES})
