#include "game.h"
#include "circle.h"

int toggle_turn(int turn) {
    return !turn;
}
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

void parse_input(Game *game, int x, int y) {
    int target_x = x/(WIDTH/X_MAX_CELLS);
    int target_y = y/(HEIGHT/Y_MAX_CELLS);
    
    if (game->board[target_x][target_y] == EMPTY) { 
        game->board[target_x][target_y] = game->turn; 

        if (win(game)) {
            game->is_game_finished = 1;
        }
        else game->turn = toggle_turn(game->turn);
    }

    if (istie(game)) {
        game->turn = TIE;
        game->is_game_finished = 1;
    }
}
void draw_cross(SDL_Renderer *renderer, int x, int y) {
    SDL_SetRenderDrawColor(renderer, RED, MAX_ALPHA);
    SDL_RenderDrawLine(renderer, (WIDTH/X_MAX_CELLS)*x, (HEIGHT/Y_MAX_CELLS)*y, (WIDTH/X_MAX_CELLS)*x + WIDTH/X_MAX_CELLS, (HEIGHT/Y_MAX_CELLS)*y + HEIGHT/Y_MAX_CELLS);

    SDL_RenderDrawLine(renderer, (WIDTH/X_MAX_CELLS)*x + WIDTH/X_MAX_CELLS, (HEIGHT/Y_MAX_CELLS)*y, (WIDTH/X_MAX_CELLS)*x, (HEIGHT/Y_MAX_CELLS)*y + HEIGHT/Y_MAX_CELLS);
}

int istie(Game *game) {
    for (int x = 0; x < X_MAX_CELLS; ++x) {
        for (int y = 0; y < Y_MAX_CELLS; ++y) {
            if (game->board[x][y] == EMPTY) {
                return 0;
            } 
        }
    }
    if (!win(game)) {
        return 1;
    }
    else {return 0;}
}
void draw_circle(SDL_Renderer *renderer, int x, int y) {
    SDL_SetRenderDrawColor(renderer, BLUE, MAX_ALPHA);
    SDL_RenderDrawCircle(renderer,((WIDTH/X_MAX_CELLS)*x + (WIDTH/X_MAX_CELLS)*x+(WIDTH/X_MAX_CELLS))/2,((HEIGHT/Y_MAX_CELLS)*y + (HEIGHT/Y_MAX_CELLS)*y + HEIGHT/Y_MAX_CELLS)/2,(WIDTH/X_MAX_CELLS)/2);
}
void draw_moves(SDL_Renderer *renderer, int cells[X_MAX_CELLS][Y_MAX_CELLS]) {
    for (int x = 0; x < X_MAX_CELLS; ++x) {
        for (int y = 0; y < Y_MAX_CELLS; ++y) {
            if (cells[x][y] != EMPTY) {
                if (cells[x][y] == X) {
                    draw_cross(renderer, x, y);
                }
                else if (cells[x][y] == O) {
                    draw_circle(renderer, x, y); 
                }
            }
        }
    }
}
int win(Game *game) {
    int sequence=0;

	for(int i=0; i<X_MAX_CELLS; i++) {
		if(game->board[i][0] == game->turn) {
			sequence = 1;

			for(int j=0; j<Y_MAX_CELLS; j++) {
				if(game->board[i][j] != game->turn) {
					sequence = 0;
				}
			}
		}

		if(sequence) {
			return(1);
		}
	}

	sequence = 0;

	for(int i=0; i<X_MAX_CELLS; i++) {
		if(game->board[0][i] == game->turn) {
			sequence = 1;

			for(int j=0; j<Y_MAX_CELLS; j++) {
				if(game->board[j][i] != game->turn) {
					sequence = 0;
				}
			}
		}

		if(sequence) {
			return(1);
		}
	}

	if(game->board[0][0] == game->turn) {
		sequence = 1;

		for(int i=0; i<X_MAX_CELLS; i++) {
			if(game->board[i][i] != game->turn) {
				sequence = 0;
			}
		}

		if(sequence) {
			return(1);
		}
	}

	if(game->board[0][Y_MAX_CELLS-1] == game->turn) {
		sequence = 1;

		for(int i=0; i<X_MAX_CELLS; i++) {
			if(game->board[i][Y_MAX_CELLS-1-i] != game->turn) {
				sequence = 0;
			}
		}

		if(sequence) {
			return(1);
		}
	}
	return(0);
}
