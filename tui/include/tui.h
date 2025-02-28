#ifndef TUI_H
#define TUI_H

typedef struct ScreenLine {
	char* line;
	int line_length;
} ScreenLine;

typedef struct ScreenView {
	ScreenLine header;
	ScreenLine* content;
	int content_length;
	ScreenLine user_input_prompt;
} ScreenView;

void draw_screen_view(ScreenView);
void expand_content(ScreenView*, char*, int);
void free_screen_content(ScreenView*);

#endif
