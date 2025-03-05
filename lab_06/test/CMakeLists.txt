find_package(cmocka REQUIRED)
find_package(tui REQUIRED)

enable_testing()
include(CTest)

include_directories(${CONAN_INCLUDE_DIRS_CMOCKA}/include)

add_library(
	test_exe STATIC
	common_test.c
	../src/common.c ../src/common.h
)

target_link_libraries(test_exe cmocka::cmocka)
target_include_directories(test_exe PUBLIC ../src)
