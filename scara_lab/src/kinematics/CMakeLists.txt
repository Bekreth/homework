add_library(
	kinematics STATIC
	kinematics.h
	limits.h
	scara_state.h
	forward_kinematics.c forward_kinematics.h
	inverse_kinematics.c inverse_kinematics.h
)

