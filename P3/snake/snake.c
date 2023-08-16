#include "snake.h"

/*
[GIVEN] Displays the menu screen and highlights the active menu entry.
*/
void display_menu(game *g) {
    char *menu_text[4] = {"MENU", "Start", "Archived snakes", "Exit"};
    assert(g);
    clear();
    printw("SNAKE\n\n");
    for (int i = 0; i < 4; i++) {
        if (i == g->menu_index) {
            printw("\t***%s***\n", menu_text[i]);
        } else {
            printw("\t   %s\n", menu_text[i]);
        }
    }
    refresh();
}

/*
[GIVEN] Displays the game screen including the board and snake.
*/
void display_game(game *g) {
    // Assert game
    assert(g);
    // Clear what was previously on the screen
    clear();
    // Show the score
    printw("Score: %d\n", g->score);
    // Top wall
    for (int x = 0; x < g->width + 2; x++) {
        addch(WALL);
    }
    printw("\n");
    // Playing field
    for (int y = 0; y < g->height; y++) {
        addch(WALL);
        for (int x = 0; x < g->width; x++) {
            addch(g->board[y][x]);
        }
        addch(WALL);
        printw("\n");
    }
    // Bottom wall
    for (int x = 0; x < g->width + 2; x++) {
        addch(WALL);
    }
    // Show start message if snake is not moving
    if (g->snake->direction == -1) {
        printw("\nPress any key to start!\n");
    }
    // Display the new screen
    refresh();
    return;
}

/*
Displays the snake archive.
*/
void display_archive(game *g) {

}

/*
[GIVEN] Updates the menu position and game state based on the action.
*/
void update_menu(game *g, int action) {
    assert(g);
    if (action == UP && g->menu_index > 0) {
        g->menu_index--;
    } else if (action == DOWN && g->menu_index < 3) {
        g->menu_index++;
    } else if (action == ENTER) {
        g->state = g->menu_index;
    }
}

/*
Moves the snake in its direction and checks if there are collisions. Returns false if there are collisions.
Note: this function does not display anything.
*/
bool update_game(game *g) {
    return false;
}

/*
Initializes the game with an empty board and a snake of length 1 in the top left corner.
*/
game *new_game(int width, int height) {
    return NULL;
}

/*
Creates an empty board (used by NewGame).
*/
char **new_board(int width, int height) {
    return NULL;
}

/*
Create snake in starter position with empty stomach (used by init_game and reset_game).
*/
snake *new_snake() {
    return NULL;
}

/*
Resets the game so a new game can be played.
*/
void reset_game(game *g) {

}

/*
Deletes all the memory used by the game.
*/
void delete_game(game *g) {

}

/*
Deletes/frees the memory of the snake. (used by delete_game)
*/
void delete_snake(snake *s) {

}

/*
Moves the snake towards the new coordinates.
*/
void move_snake(snake *s, int new_y, int new_x) {

}

/*
Resizes the snake. (used by grow_snake)
 - If the snake grows, this function adds empty segments at the back of the snake and its stomach.
 - If the snake shrinks, this function removes segments from the back of the snake and its stomach.
*/
void resize_snake(snake *s, int new_length) {

}

/*
Grows the snake towards specified coordinates and adds the food to the stomach.
*/
void grow_snake(snake *s, int new_y, int new_x, char food) {

}

/*
Draws the snake onto the board.
Note that this does not display the new board or snake yet.
*/
void draw_snake(snake *s, char **board) {

}

/*
Clears the snake from the board: set all places where the snake is drawn to ' '.
Note: this leaves the food on the board.
*/
void undraw_snake(snake *s, char **board) {

}

/*
Generates new food on the board if previous one was found.
*/
void generate_food(game *g) {

}

/*
Returns a deep copy of the snake (used by archive_snake).
*/
snake *copy_snake(snake *s) {
    return NULL;
}

/*
Adds the snake to the archived snakes list.
*/
void archive_snake(game *g, char *name) {

}
