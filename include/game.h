#include <SDL2/SDL.h>
#ifndef GAME_H
#define GAME_H

#define WIDTH 800
#define HEIGHT 800

#define X 0
#define O 1
#define TIE 2 
#define EMPTY 3

#define X_MAX_CELLS 3
#define Y_MAX_CELLS 3 

#define BLUE 0, 0, 255
#define WHITE 255, 255, 255
#define RED 255, 0, 0
#define BLACK 0, 0, 0
#define MAX_ALPHA 255

typedef struct {
    int board[X_MAX_CELLS][Y_MAX_CELLS];
    int turn;
    int is_game_finished;
} Game;
// Function definitions
int isempty(int cells[X_MAX_CELLS][Y_MAX_CELLS], int x, int y);
int win(Game *game);
int istie(Game *game);
int toggle_turn(int turn);
void draw_grid(SDL_Renderer *renderer);
void draw_moves(SDL_Renderer *renderer, int cells[X_MAX_CELLS][Y_MAX_CELLS]);
void draw_cross(SDL_Renderer *renderer, int x, int y);
void draw_circle(SDL_Renderer *renderer, int x, int y);
void parse_input(Game *game, int x, int y);
#endif
