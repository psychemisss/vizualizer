#include "linker.h"
double view_point_x = 0;
double view_point_y = 0;
int window_width = 0;
int window_height = 0;
bool quit = false;

bool sdl_init(SDL_Window **window, SDL_Renderer **renderer, SDL_Surface **src, SDL_Surface **dest, int _window_width, int _window_height, const char *title) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Fatal Error: %d \n", SDL_GetError());
		return false;
	}
	*window = SDL_CreateWindow("Graph", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _window_width, _window_height, SDL_WINDOW_RESIZABLE);
	if (window == NULL) {
		SDL_Quit();
		printf("Fatal Error: %d \n", SDL_GetError());
		return false;
	}
	*renderer = SDL_CreateRenderer(*window, -1, 0);
	if (renderer == nullptr) {
		SDL_Quit();
		printf("Fatal Error: %d \n", SDL_GetError());
		return false;
	}
	window_width = _window_width;
	window_height = _window_height;
	return true;
}
void handle_events() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			quit = true;
		}
		if (event.type = SDL_KEYDOWN) {
			if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
				if (view_point_x != 0) {
					view_point_x -= 10;
				}
			}
			else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
				view_point_x += 10;
			}
		}
	}
}
void render(SDL_Renderer **renderer) {
	if (*renderer == nullptr) {
		
	}
	SDL_SetRenderDrawColor(*renderer, 0, 0, 0, 255);
	SDL_RenderPresent(*renderer);
	SDL_RenderClear(*renderer);
}
void close(SDL_Window **window, SDL_Renderer **renderer) {
	SDL_DestroyWindow(*window);
	SDL_DestroyRenderer(*renderer);
	SDL_Quit();
	printf("Bye, oo \n");
}