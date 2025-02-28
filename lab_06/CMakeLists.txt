cmake_minimum_required(VERSION 3.15)
project(lab_06 C)

add_executable(lab_06 src/main.c)

install(
	TARGETS lab_06 DESTINATION "."
	RUNTIME DESTINATION bin
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
)

add_subdirectory(src)
target_link_libraries(lab_06 exe)
