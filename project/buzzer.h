#ifndef buzzer_included
#define buzzer_included

void buzzer_init();
void buzzer_set_period(short cycles);
void buzzer_play_sound();

extern char selected_sound;

#endif // included
