#ifndef LED_H
#define LED_H

#include <stdio.h>
#include <stdlib.h>

// State representations
#define LED_OFF 0
#define LED_ON  1

// LED structure definition
typedef struct {
    int led_no;
    int *status; // Pointer to an integer holding current state (0 or 1)
} LED;

// Function Prototypes
void init_led(LED *led, int id, int initial_state);
void set_led(LED *led);
void reset_led(LED *led);
void toggle_led(LED *led);
void free_led(LED *led);

#endif // LED_H