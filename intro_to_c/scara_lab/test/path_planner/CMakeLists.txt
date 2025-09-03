find_package(cmocka REQUIRED)

enable_testing()
include(CTest)

include_directories(${CONAN_INCLUDE_DIRS_CMOCKA}/include)

add_library(
	test_path_planner STATIC
	path_planner_test.h path_planner_test.c
)

target_link_libraries(test_path_planner cmocka::cmocka)
target_include_directories(
	test_path_planner PUBLIC 
	${PROJECT_SOURCE_DIR}/src/kinematics
	${PROJECT_SOURCE_DIR}/src/path_planner
)
