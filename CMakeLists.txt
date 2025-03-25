cmake_minimum_required(VERSION 3.30)
project(my_lib)
set(CMAKE_CXX_STANDARD 14)
include_directories(cummulative_sum_2D)
include_directories(cummulative_sum_3D)
add_executable(my_lib main.cpp library.cpp
        "cummulative_sum_2D/cum_sum.cpp"
"cummulative_sum_3D/cum_sum_3D.cpp")
