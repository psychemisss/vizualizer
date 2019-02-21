#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#define NULL 0
	//Variables
extern double view_point_x;
extern double view_point_y;
extern bool quit;
	//Functions
bool sdl_init(SDL_Window **window, SDL_Renderer **renderer, SDL_Surface **src, SDL_Surface **dest, int window_width, int window_height, const char *title);
void handle_events();
void render(SDL_Renderer *renderer);
void close(SDL_Window *window, SDL_Renderer *renderer);

