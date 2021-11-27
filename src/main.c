#include "game.h"
#include <SDL2/SDL.h>
#include <stdio.h>

int main(void)
{
    int board[3][3]; 
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = 2; // NO VALID VALUE
        } 
    }
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Error while initializing sdl2: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}
	SDL_Window *window = SDL_CreateWindow("Test", 0, 0, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Error while initializing sdl2: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Event e;
	int exited = 0;
        
	while (!exited)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
				case SDL_QUIT:
					exited = 1;
					break;
                case SDL_MOUSEBUTTONDOWN:
                    //parse_input();
				default: {}
			}
			SDL_SetRenderDrawColor(renderer, BLACK, MAX_ALPHA);
			SDL_RenderClear(renderer);
			draw_grid(renderer);
            draw_moves(renderer, board);
			SDL_RenderPresent(renderer);
		}
    }
}
