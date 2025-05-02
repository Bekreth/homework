add_library(
	kinematics STATIC
	kinematics.h
	limits.h
	coordinates.c coordinates.h
	forward_kinematics.c forward_kinematics.h
	inverse_kinematics.c inverse_kinematics.h
	path.c path.h
)

