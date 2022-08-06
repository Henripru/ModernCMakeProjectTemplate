cmake_minimum_required(VERSION 3.16)
project(tests)

add_executable(${PROJECT_NAME} tests.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/share/)
target_link_libraries(${PROJECT_NAME} PRIVATE LibName)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib
    ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib
    RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
    )
