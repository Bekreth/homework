#include "scara_test.h"
#include "forward_kinematics_test.h"
#include "inverse_kinematics_test.h"


int main() {
	int forward_kinematics_test_results = run_fk_tests();
	int inverse_kinematics_test_results = run_ik_tests();

	return forward_kinematics_test_results;
}
