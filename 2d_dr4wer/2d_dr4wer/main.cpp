#include "sdl/linker.h"
#include <iostream>

struct dot {
	int x = 0;
	int y = 0;
};

int main(int argc, char *argv[]) {
	dot current_dot;
	dot previous_dot;
	const int dot_array_size = 50;
	dot dot_array[dot_array_size];
	dr4wer::sdl_init(640, 480, "dr4wer");
	for (int i = 0; i < dot_array_size; i++) {
		dot_array[i].x = i * (dr4wer::window_width / dot_array_size);
		dot_array[i].y = rand() % (3 + dr4wer::window_height);
	}
	while (!dr4wer::quit) {
		dr4wer::handle_events();
		current_dot = dot_array[0];
		for (int i = 0; i < dot_array_size; i++) {
			dr4wer::drawpoint(dot_array[i].x, dot_array[i].y);
			if (i != 0) {
				previous_dot = current_dot;
				current_dot = dot_array[i];
				SDL_RenderDrawLine(dr4wer::renderer, previous_dot.x, previous_dot.y, current_dot.x, current_dot.y);
			}
		}
		dr4wer::render();
	}
	dr4wer::close();
	return 0;
}