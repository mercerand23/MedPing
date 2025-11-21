cmake_minimum_required(VERSION 3.31)
project(Console_medPing_v2_0b)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp mpPatient.h randomBell.h medPing.cpp mp_InputOutput.cpp talk2chip.cpp
        medPing.h mp_InputOutput.h talk2chip.h History_medPing_Main.cpp
        mp_normalVitalSigns.h mpPatient.cpp randomBell.cpp)

add_executable(Console_medPing_v2_0b ${SOURCE_FILES})
