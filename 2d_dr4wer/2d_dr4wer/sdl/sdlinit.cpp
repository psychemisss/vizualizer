#include "linker.h"

namespace dr4wer {
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	int window_width = 0;
	int window_height = 0;
	bool quit = false;

	bool sdl_init(int _window_width, int _window_height, const char *title) {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("Fatal Error: %d \n", SDL_GetError());
			return false;
		}
		window = SDL_CreateWindow("Graph", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _window_width, _window_height, SDL_WINDOW_RESIZABLE);
		if (window == NULL) {
			SDL_Quit();
			printf("Fatal Error: %d \n", SDL_GetError());
			return false;
		}
		window_width = _window_width;
		window_height = _window_height;
		renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == NULL) {
			SDL_Quit();
			printf("Fatal Error: %d \n", SDL_GetError());
			return false;
		}
		return true;
	}
	void handle_events() {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}
	void render() {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}
	void close() {
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		printf("Bye, oo \n");
	}
	void drawpoint(int pointpositionX, int pointpositionY) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderDrawPoint(renderer, pointpositionX, pointpositionY);
	}
}