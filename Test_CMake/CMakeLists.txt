cmake_minimum_required(VERSION 3.16)


project(Test_CMake 
    VERSION 1.0
    LANGUAGES CXX    
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src)
add_subdirectory(apps)


