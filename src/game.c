#include "game.h"
#include "circle.h"

void draw_grid(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, WHITE, MAX_ALPHA);
    // X
    for (int i = 1; i < 3; ++i) {
        SDL_RenderDrawLine(renderer, WIDTH/3 * i, 0, WIDTH/3 * i, HEIGHT);
    }
    // Y
    for (int i = 1; i < 3; ++i) {
        SDL_RenderDrawLine(renderer, 0, HEIGHT/3 * i, WIDTH, HEIGHT/3* i);
    }
}

int isempty(int cells[X_MAX_CELLS][Y_MAX_CELLS], int x, int y) {
    return (cells[x][y] != O && cells[x][y] != X) ? 1 : 0; 
}

void draw_cross(SDL_Renderer *renderer, int x, int y) {
    SDL_RenderDrawLine(renderer, (WIDTH/X_MAX_CELLS)*x, (HEIGHT/Y_MAX_CELLS)*y, (WIDTH/X_MAX_CELLS)*x + WIDTH/X_MAX_CELLS, (HEIGHT/Y_MAX_CELLS)*y + HEIGHT/Y_MAX_CELLS);

    SDL_RenderDrawLine(renderer, (WIDTH/X_MAX_CELLS)*x + WIDTH/X_MAX_CELLS, (HEIGHT/Y_MAX_CELLS)*y, (WIDTH/X_MAX_CELLS)*x, (HEIGHT/Y_MAX_CELLS)*y + HEIGHT/Y_MAX_CELLS);
}

void draw_moves(SDL_Renderer *renderer, int cells[X_MAX_CELLS][Y_MAX_CELLS]) {
    for (int x = 0; x < Y_MAX_CELLS; ++x) {
        for (int y = 0; y < X_MAX_CELLS; ++y) {
            if (!isempty(cells, x, y)) {
                if (cells[x][y] == X) {
                    draw_cross(renderer, x, y);
                }
                else if (cells[x][y] == O) {
                    SDL_RenderDrawCircle(renderer,((WIDTH/X_MAX_CELLS)*x + (WIDTH/X_MAX_CELLS)*x+(WIDTH/X_MAX_CELLS))/2,((HEIGHT/Y_MAX_CELLS)*y + (HEIGHT/Y_MAX_CELLS)*y + HEIGHT/Y_MAX_CELLS)/2,(WIDTH/X_MAX_CELLS)/2);
                }
            }
        }
    }
}
