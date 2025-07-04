#include "scara_test.h"

#include "kinematics_test.h"

#include "path_planner_test.h"


int main() {
	int forward_kinematics_test_results = run_fk_tests();
	int inverse_kinematics_test_results = run_ik_tests();
	int coordinate_test_results = run_coordinate_tests(); 
	int path_divider_test_results = run_path_tests();

	return forward_kinematics_test_results 
		&& inverse_kinematics_test_results 
		&& coordinate_test_results
		&& path_divider_test_results;
}
