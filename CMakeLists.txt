cmake_minimum_required(VERSION 2.8.9 FATAL_ERROR)
cmake_policy(VERSION 3.4)
project(support_private_dynamic_cast CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
set(CMAKE_CXX_STANDARD 11)
option(BASE_DEFAULT_VISIBILITY "Enables default visibility for the
base class" ON)

if(BASE_DEFAULT_VISIBILITY)
  add_definitions("-DBASE_DEFAULT_VISIBILITY")
endif()

add_library(base SHARED "base.cxx" "derived.cxx")
set_target_properties(base PROPERTIES CXX_VISIBILITY_PRESET hidden)

add_library(create SHARED "create.cxx")
target_link_libraries(create PUBLIC base)
set_target_properties(create PROPERTIES CXX_VISIBILITY_PRESET hidden)
add_executable(out "main.cxx")
target_link_libraries(out PRIVATE create)
