#ifndef STATE_INTENT_H
#define STATE_INTENT_H

Intent process_pen_up(Tokens*);
Intent process_pen_down(Tokens*);
Intent process_pen_color(Tokens*);
Intent process_speed(Tokens*);
Intent process_quit();

#endif
