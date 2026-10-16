#include <stdio.h>
#include <stdlib.h>
#include "led.h"

// Helper function to print current state of all LEDs
void display_led_states(LED *leds, int n) {
    for (int i = 0; i < n; i++) {
        printf("[LED %d: %s] ", leds[i].led_no, *(leds[i].status) ? "ON" : "OFF");
    }
    printf("\n");
}

int main() {
    int n, m;

    printf("Enter number of LEDs (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid LED count.\n");
        return EXIT_FAILURE;
    }

    printf("Enter number of toggle cycles (m): ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        fprintf(stderr, "Invalid cycle count.\n");
        return EXIT_FAILURE;
    }

    // Dynamically allocate array of n LED structures
    LED *led_array = (LED *)malloc(n * sizeof(LED));
    if (led_array == NULL) {
        fprintf(stderr, "Failed to allocate memory for LED array.\n");
        return EXIT_FAILURE;
    }

    // Initialize: alternating pattern (Even index ON, Odd index OFF)
    for (int i = 0; i < n; i++) {
        int initial_state = (i % 2 == 0) ? LED_ON : LED_OFF;
        init_led(&led_array[i], i + 1, initial_state);
    }

    printf("\nInitial Configuration:\n");
    display_led_states(led_array, n);
    printf("--------------------------------------------------\n");

    // Toggle alternatively 'm' times
    for (int cycle = 1; cycle <= m; cycle++) {
        for (int i = 0; i < n; i++) {
            toggle_led(&led_array[i]);
        }
        printf("After Cycle %d: ", cycle);
        display_led_states(led_array, n);
    }

    // Deallocate memory: free internal pointers first, then the array
    for (int i = 0; i < n; i++) {
        free_led(&led_array[i]);
    }
    free(led_array);
    led_array = NULL;

    printf("\nMemory deallocated successfully.\n");
    return EXIT_SUCCESS;
}