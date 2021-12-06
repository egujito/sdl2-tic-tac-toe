#include "game.h"
#include <SDL2/SDL.h>
#include <stdio.h>

int end (int code, SDL_Window* w) {
    SDL_DestroyWindow(w);
    SDL_Quit();
    exit(code);
}
int main(void)
{
    Game game;
    game.turn = X;
    game.is_game_finished = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            game.board[i][j] = EMPTY; // NO VALID VALUE
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
		printf("Error while setting renderer in sdl2: %s\n", SDL_GetError());
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
                    parse_input(&game, e.button.x, e.button.y);
                    break;
				default: {}
			}
        }
        SDL_SetRenderDrawColor(renderer, BLACK, MAX_ALPHA);
        SDL_RenderClear(renderer);
        draw_grid(renderer);
        draw_moves(renderer, game.board);
        SDL_RenderPresent(renderer);
        if (game.is_game_finished) {
            switch(game.turn) {
                case X:
                    printf("X WON \n");
                    fflush(stdout);
                    system("sleep 5");
                    end(0, window);
                    break;
                case O:
                    printf("O WON \n");
                    fflush(stdout);
                    system("sleep 5");
                    end(0, window);
                    break;
                case TIE:
                    printf("No winner \n");
                    fflush(stdout);
                    system("sleep 5");
                    end(0, window);
                    break;
                default: {break;}
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
