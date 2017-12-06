#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int player_scored = 0;
int game_over = 0;

void buzzer_init()
{
    /* 
       Direct timer A output "TA0.1" to P2.6.  
        According to table 21 from data sheet:
          P2SEL2.6, P2SEL2.7, anmd P2SEL.7 must be zero
          P2SEL.6 must be 1
        Also: P2.6 direction must be output
    */
    timerAUpmode();		/* used to drive speaker */
    P2SEL2 &= ~(BIT6 | BIT7);
    P2SEL &= ~BIT7; 
    P2SEL |= BIT6;
    P2DIR = BIT6;		/* enable output to speaker (P2.6) */
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles; 
  CCR1 = cycles >> 1;		/* one half cycle */
}

/* Plays a sound depending on the switch that was pressed */
void buzzer_play_sound(){

  static int sound_counter = 0; // Sound counter to play the sound
  
  if(sound_counter == 30){
    buzzer_set_period(0);
    player_scored = 0;
    game_over = 0;
    sound_counter = 0;
  }
  else{
    if(game_over){
      buzzer_set_period(7000);
    }
    else if(player_scored){
      buzzer_set_period(500);
    }
  }

  sound_counter++;
}
