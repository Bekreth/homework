cmake_minimum_required(VERSION 3.15)
project(lab_05 C)
find_package(tui REQUIRED)

add_executable(
	lab_05 
	src/main.c
	src/counter.c src/counter.h
	src/factorize.c src/factorize.h
	src/prime.c src/prime.h
	src/table.c	src/table.h
)

install(
	TARGETS lab_05 DESTINATION "."
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

add_subdirectory(test)
add_subdirectory(src/cache)

target_link_libraries(lab_05 cache)
target_link_libraries(lab_05 tui::tui)
