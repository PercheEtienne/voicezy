#include "buzzer.h"

void playMario()
{
    int pin = 1;
    softToneCreate (pin) ;
    int noteDuration;
    int pauseBetweenNotes;
    int thisNote;
    int size = sizeof(melody) / sizeof(int);
    printf("Mario Theme");
    for (thisNote = 0; thisNote < size; thisNote++) {
        // to calculate the note duration, take one second
        // divided by the note type.
        noteDuration = 1000 / tempo[thisNote];
        softToneWrite (pin, melody[thisNote]);
        delay(noteDuration);
        softToneWrite (pin, 0);
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
    }
}