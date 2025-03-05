find_package(tui REQUIRED)

add_library(
	exe STATIC
	common.c common.h
)

target_link_libraries(exe tui::tui)
