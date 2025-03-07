find_package(tui REQUIRED)

add_library(
	exe STATIC
	common.c common.h
	conio.c conio.h
)

target_link_libraries(exe tui::tui)
