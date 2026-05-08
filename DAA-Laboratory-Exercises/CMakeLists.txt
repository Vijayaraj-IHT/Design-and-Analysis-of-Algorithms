cmake_minimum_required(VERSION 3.20)
project(DAA_Laboratory_Exercises LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add each exercise subdirectory if it exists.
foreach(ex
  EX1_Brute_Force_Sorting
  EX2_Brute_Force_Search_and_Geometry
  EX3_Divide_and_Conquer
  EX4_Decrease_and_Conquer
  EX5_String_Matching
  EX6_Dynamic_Programming
  EX7_Greedy_Technique
  EX8_Backtracking
  EX9_Branch_and_Bound
)
  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${ex}/CMakeLists.txt")
    add_subdirectory(${ex})
  endif()
endforeach()

