#include "asteroids.h"

struct ship_action move_ship(int field[][FIELD_WIDTH], void *ship_state) {
    struct ship_action action = {MOVE_NO, NULL};

    // Initialize the state if it's the first call
    if (ship_state == NULL) {
        ship_state = malloc(sizeof(int)); // Allocate memory for state
        *(int *)ship_state = FIELD_HEIGHT / 2; // Start in the middle
    }

    int ship_row = *(int *)ship_state;

    // Analyze the field to decide the best action
    int can_move_up = (ship_row > 0) && (field[ship_row - 1][0] == 0);
    int can_move_down = (ship_row < FIELD_HEIGHT - 1) && (field[ship_row + 1][0] == 0);

    // Simple strategy: move to a safe lane
    if (can_move_down && !can_move_up) {
        action.move = MOVE_DOWN;
    } else if (can_move_up && !can_move_down) {
        action.move = MOVE_UP;
    } else {
        action.move = MOVE_NO; // Stay in place
    }

    action.state = ship_state; // Return the state
    return action;
}