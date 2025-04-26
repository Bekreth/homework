add_library(
	kinematics STATIC
	kinematics.h
	limits.h
	scara_state.h
	coordinates.h
	forward_kinematics.c forward_kinematics.h
	inverse_kinematics.c inverse_kinematics.h
	path_divider.c path_divider.h
)

