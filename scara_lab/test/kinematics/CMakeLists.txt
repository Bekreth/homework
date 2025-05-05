find_package(cmocka REQUIRED)

enable_testing()
include(CTest)

include_directories(${CONAN_INCLUDE_DIRS_CMOCKA}/include)

add_library(
	test_kinematics STATIC
	forward_kinematics_test.h forward_kinematics_test.c
	inverse_kinematics_test.h inverse_kinematics_test.c
)

target_link_libraries(test_kinematics cmocka::cmocka)
target_include_directories(
	test_kinematics PUBLIC 
	${PROJECT_SOURCE_DIR}/src/kinematics
)
