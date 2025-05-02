#include "scara_lab.h"

ScaraRobot new_scara_robot() {
	ScaraRobot robot = {
		.theta_1 = 0.0,
		.theta_2 = 0.0,
		.is_pen_down = true
	};
}
