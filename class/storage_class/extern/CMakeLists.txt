# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyExecutable)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    01_extern.cpp
    02_extern.cpp
)

# Create an executable from the source files
add_executable(my_executable ${SOURCES})

# Optional: Link libraries here (if needed)
# target_link_libraries(my_executable <libraries>)
