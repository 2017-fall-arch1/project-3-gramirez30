#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_play_sound();

extern int player_scored;
extern int game_over;

#endif // included
