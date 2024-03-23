cmake_minimum_required(VERSION 3.27)
project(HW6)


set(CMAKE_OSX_SYSROOT /Library/Developer/CommandLineTools/SDKs/MacOSX14.sdk)
set(CMAKE_OSX_ARCHITECTURES arm64) # for M1 Macs, or remove if targeting multiple architectures
set(CMAKE_CXX_STANDARD 17)


add_executable(HW6_q1 gnf5628_HW6_q1.cpp
)

add_executable(HW6_q2 gnf5628_HW6_q2.cpp
)

add_executable(HW6_q3 gnf5628_HW6_q3.cpp
)

add_executable(HW6_q4 gnf5628_HW6_q4.cpp
)