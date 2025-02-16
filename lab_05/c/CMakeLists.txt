cmake_minimum_required(VERSION 3.15)
project(lab_05 C)

add_executable(
	lab_05 
	src/main.c
	src/counter.c src/counter.h
	src/factorize.c src/factorize.h
	src/prime.c src/prime.h
)

install(
	TARGETS lab_05 DESTINATION "."
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

add_subdirectory(test)
