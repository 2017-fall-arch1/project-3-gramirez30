#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

//char selected_sound; // Song to be played

/* Diferent sounds for each switch on the Green board */
//short sound1[] = {659,622,659,622,659,494,587,523,440};
//short sound2[] = {988,1046,1174,1174,1046,988,880,784,784,880,988,988,880};
//short sound3[] = {880,784,880,698,880,659,880,587,880,523,880,587};
//short sound4[] = {932,0,932,932,1046,1046,932,880,784,698,0,698,784,698,784};

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

  while(sound_counter < 30000){
    buzzer_set_period(5000);
    sound_counter++;
  }
  buzzer_set_period(0);
  sound_counter = 0;
}
