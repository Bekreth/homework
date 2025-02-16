find_package(cmocka REQUIRED)

enable_testing()
include(CTest)

include_directories(${CONAN_INCLUDE_DIRS_CMOCKA}/include)

add_executable(
	test_suite 
	main.c
	factorize.c
)

target_link_libraries(test_suite cmocka::cmocka)
target_include_directories(test_suite PUBLIC ../src)

add_test(test_suite test_suite)
