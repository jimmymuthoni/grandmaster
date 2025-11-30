cmake_minimum_required(VERSION 3.16)
project(grandmaster LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Qt automatic tools
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Find Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Widgets Svg Multimedia)

# Copy stylesheet
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/assets/styles/styles.qss
    ${CMAKE_CURRENT_BINARY_DIR}/style.qss COPYONLY
)

# Source files
set(SOURCES
    src/main.cpp
    src/chessboard.cpp
    src/piece.cpp
    qresource.qrc
)

# Create executable
add_executable(grandmaster ${SOURCES})

# Link Qt6 libraries
target_link_libraries(grandmaster PRIVATE Qt6::Widgets Qt6::Svg Qt6::Multimedia)
