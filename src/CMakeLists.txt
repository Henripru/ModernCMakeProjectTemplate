cmake_minimum_required(VERSION 3.16)

project(LibName)

# Create Library
add_library(${PROJECT_NAME} LibName.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include/)

# Install 
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib
    ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib
    RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
    )