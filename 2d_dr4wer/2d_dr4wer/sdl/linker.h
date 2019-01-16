#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#define NULL 0
namespace dr4wer {
	//Variables
	extern SDL_Window *window;
	extern SDL_Renderer *renderer;
	extern int window_width;
	extern int window_height;
	extern bool quit;
	//Functions
	bool sdl_init(int window_width, int window_height, const char *title);
	void handle_events();
	void render();
	void close();
	void drawpoint(int pointpositionX, int pointpositionY);
}

