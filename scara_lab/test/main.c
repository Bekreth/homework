#include "scara_test.h"
#include "forward_kinematics_test.h"
#include "inverse_kinematics_test.h"


int main() {
	int forward_kinematics_test_results = run_fk_tests();

	return forward_kinematics_test_results;
}
