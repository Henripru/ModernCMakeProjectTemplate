add_executable(app app.cpp)
target_link_libraries(app PRIVATE LibName)
install(TARGETS app
    LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib
    ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib
    RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
    )