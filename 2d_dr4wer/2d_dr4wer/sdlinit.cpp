#include "linker.h"
#include <SDL.h>

namespace dr4wer {

	const int window_width = 1200;
	const int window_height = 1000;

	bool drawdata(int pointpositionX, int pointpositionY) {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("Fatal Error: %d \n", SDL_GetError());
			return 1;
		}
		SDL_Window *window = SDL_CreateWindow("Graph", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_width, window_height, SDL_WINDOW_RESIZABLE);
		if (window == NULL) {
			SDL_Quit();
			printf("Fatal Error: %d \n", SDL_GetError());
			return 2;
		}
		SDL_Renderer *renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == NULL) {
			SDL_Quit();
			printf("Fatal Error: %d \n", SDL_GetError());
			return 3;
		}

		SDL_Event event;

		bool quit = false;

		while (!quit) {
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					quit = true;
				}
			}

			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0xFF);
			SDL_RenderDrawPoint(renderer, pointpositionX, pointpositionY);
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
			SDL_RenderPresent(renderer);
		}

		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		printf("Bye, oo \n");
		return 0;

		return 0;
	}
}