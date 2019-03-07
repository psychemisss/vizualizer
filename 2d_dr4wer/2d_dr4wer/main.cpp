#pragma warning
#include "sdl/linker.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define ERROR_MSG_SIZE 128

const int arr_size = 2095;
double arr1[arr_size];
double arr2[arr_size];
double arr3[arr_size];
int number_count = 0;
int arr_counter = 0;
double absolute_array[arr_size * 3];

struct dot {
	int x = 0;
	int y = 0;
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

void get_number(FILE *file, double *arr, int collum_number) {
	for (int i = 0; i < arr_size * 3; i++) {
		fscanf(file, "%lf ", &absolute_array[i]);
	}
	for (int j = collum_number; j < arr_size; j += 3) {
		arr[arr_counter] = absolute_array[j];
		printf("%lf\n", arr[arr_counter]);
		arr_counter++;
	}
	arr_counter = 0;
}

int main(int argc, char *argv[]) {
	FILE *f = fopen("assets/test_data.dat", "r");
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
		get_number(f, arr1, 0);
		get_number(f, arr2, 1);
		get_number(f, arr3, 2);
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
		current_point.x = arr2[0];
		current_point.y = window_height - arr3[0];
		for (int i = 0; i < arr_size; i++) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderDrawPoint(renderer, current_point.x - view_point_x, current_point.y);
			if (i != 0) {
				previous_point = current_point;
				current_point.x = arr2[i];
				current_point.y = window_height - arr3[i];
				SDL_RenderDrawLine(renderer, previous_point.x -view_point_x, previous_point.y, current_point.x - view_point_x, current_point.y);
			}
		}
		render(&renderer);
	}
	close(&window, &renderer);
	return 0;
}