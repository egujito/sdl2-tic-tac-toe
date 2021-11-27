#include <SDL2/SDL.h>
#ifndef HEADER_FILE
#define HEADER_FILE

#define WIDTH 800
#define HEIGHT 800

#define X 0
#define O 1
#define TIE 2 

#define X_MAX_CELLS 3
#define Y_MAX_CELLS 3 

#define BLUE 0, 0, 255
#define WHITE 255, 255, 255
#define RED 255, 0, 0
#define BLACK 0, 0, 0
#define MAX_ALPHA 255

// Function definitions
int isempty(int cells[X_MAX_CELLS][Y_MAX_CELLS], int x, int y);
void draw_grid(SDL_Renderer *renderer);
void draw_moves(SDL_Renderer *renderer, int cells[X_MAX_CELLS][Y_MAX_CELLS]);
void draw_cross(SDL_Renderer *renderer, int x, int y);
#endif
