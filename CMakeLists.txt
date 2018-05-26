# General
cmake_minimum_required(VERSION 3.1)
project(tests)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
        set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_FOUND})
        set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_FOUND})
endif(CCACHE_FOUND)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED COMPONENTS Private)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Test REQUIRED)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
# compile forms
set(CMAKE_AUTOUIC ON)
# compile resources
set(CMAKE_AUTORCC ON)

# Tell CMake to create the helloworld executable
add_executable(${PROJECT_NAME}
	tests_main.cpp
	catch.hpp
    )

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)

target_compile_definitions(${PROJECT_NAME} PRIVATE -DQT_DEBUG -DQT_MESSAGELOGCONTEXT)
target_link_libraries(${PROJECT_NAME}
  Qt5::Core
  Qt5::Widgets
  Qt5::Gui
  Qt5::Test
)
