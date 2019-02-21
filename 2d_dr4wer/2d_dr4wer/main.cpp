#pragma warning
#include "sdl/linker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define ERROR_MSG_SIZE 128

int arr1[4];
double arr2[4];
double arr3[4];
int number_count = 0;

struct dot {
	double x = 0;
	double y = 0;
};

void fatal(char* msg) {
	char error_msg[ERROR_MSG_SIZE];
	strcpy(error_msg, "[Critical Error]: ");
	strncat(error_msg, msg, 83);
	perror(error_msg);
	exit(-1);
}

void *smart_malloc(unsigned int size) {
	void *ptr;
	ptr = malloc(size);
	if (ptr == NULL) {
		fprintf(stderr, "Error: Can't allocate memory");
		exit(-1);
	}
	return ptr;
}
	
void usage(char *program_name, char *filename) {
	printf("Usage: %s <data to add to %s>\n", program_name, filename);
	exit(0);
}

void get_number(FILE *file) {
	for (int i = 0; i < 12; i++) {
		if (number_count == 0) {
			fscanf(file, "%d, ", &arr1[i]);
			printf("Arr1 %d\n", arr1[i]);
		}
		else if (number_count == 1) {
			fscanf(file, "%lf, ", &arr2[i]);
			printf("Arr2 %lf\n", arr2[i]);
		}
		else if (number_count == 2) {
			fscanf(file, "%lf, ", &arr3[i]);
			printf("Arr3 %lf\n", arr3[i]);
		}
		number_count++;
		if (number_count > 2) {
			number_count = 0;
		}
	}
}

int main(int argc, char *argv[]) {
	FILE *f = fopen("assets/testing.dat", "r");
	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	SDL_Surface *src = nullptr;
	SDL_Surface *scaled = nullptr;
	SDL_Point current_point;
	SDL_Point previous_point;
	//Getting number from file
	if (!f)
		printf("SUKAAAAA");
	else {
		get_number(f);
		fclose(f);
	}
	//SDL setup
	if (sdl_init(&window, &renderer, &src, &scaled, 640, 480, "dr4wer") == false) {
		printf("SDL setup failed");
		return -1;
	}
	//Window loop
	while (!quit) {
		handle_events();
		current_point.x = arr2[0] * 10000;
		current_point.y = arr3[0] * 10000;
		for (int i = 0; i < 4; i++) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderDrawPoint(renderer, current_point.x, current_point.y);
			if (i != 0) {
				previous_point = current_point;
				current_point.x = arr2[i] * 10000;
				current_point.y = arr3[i] * 10000;
				SDL_RenderDrawLine(renderer, previous_point.x, previous_point.y, current_point.x, current_point.y);
			}
		}
		render(renderer);
	}
	close(window, renderer);
	return 0;
}