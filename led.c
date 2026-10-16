#include "led.h"

// Initialize an individual LED struct and its status pointer
void init_led(LED *led, int id, int initial_state) {
    if (led == NULL) return;

    led->led_no = id;
    led->status = (int *)malloc(sizeof(int));
    if (led->status == NULL) {
        fprintf(stderr, "Memory allocation failed for LED %d status!\n", id);
        exit(EXIT_FAILURE);
    }
    *(led->status) = initial_state;
}

// Turn LED ON (Set)
void set_led(LED *led) {
    if (led && led->status) {
        *(led->status) = LED_ON;
    }
}

// Turn LED OFF (Reset)
void reset_led(LED *led) {
    if (led && led->status) {
        *(led->status) = LED_OFF;
    }
}

// Toggle LED state between 0 and 1
void toggle_led(LED *led) {
    if (led && led->status) {
        *(led->status) = (*(led->status) == LED_ON) ? LED_OFF : LED_ON;
    }
}

// Free dynamically allocated pointer inside the struct
void free_led(LED *led) {
    if (led && led->status) {
        free(led->status);
        led->status = NULL;
    }
}