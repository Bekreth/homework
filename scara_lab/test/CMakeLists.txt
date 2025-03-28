find_package(cmocka REQUIRED)

enable_testing()
include(CTest)

include_directories(${CONAN_INCLUDE_DIRS_CMOCKA}/include)

add_library(
	test_exe STATIC
	scara_test.c scara_test.h
)

target_link_libraries(test_exe cmocka::cmocka)
target_include_directories(test_exe PUBLIC ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(kinematics)
