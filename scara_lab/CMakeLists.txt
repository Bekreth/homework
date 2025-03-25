cmake_minimum_required(VERSION 3.15)
project(scara_lab C)

add_executable(
	scara_lab 
	src/main.c
	${PROJECT_SOURCE_DIR}/src/network/network.h
	${PROJECT_SOURCE_DIR}/src/kinematics/kinematics.h
)
add_executable(test_suite test/main.c)

target_include_directories(
	scara_lab PRIVATE
	${PROJECT_SOURCE_DIR}/src/network/
)

target_include_directories(
	scara_lab PRIVATE
	${PROJECT_SOURCE_DIR}/src/kinematics/
)

install(
	TARGETS scara_lab DESTINATION "."
	RUNTIME DESTINATION bin
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
)

add_subdirectory(src)
target_link_libraries(scara_lab exe kinematics network)

add_subdirectory(test)
target_link_libraries(test_suite test_exe)

