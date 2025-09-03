cmake_minimum_required(VERSION 3.15)
project(lab_00 C)


add_executable(lab_00 src/main.c)
add_executable(test_suite test/main.c)


add_subdirectory(src)
target_link_libraries(lab_00 exe)

add_subdirectory(test)
target_link_libraries(test_suite test_exe)

install(
	TARGETS lab_00 DESTINATION "."
	RUNTIME DESTINATION bin
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
)
