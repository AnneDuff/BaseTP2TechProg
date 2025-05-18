#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "utils.h"
#include "main.h"
#include "stb_image.h"
#include "stb_image_write.h"

const char* img_names[] = {
	"31.bmp",
	"64.bmp",
	"128.bmp",
	"512.bmp",
	"45565.bmp",
	"braid2k.png",
	"combo400.png",
	"perfect2k.png"
};

const size_t img_names_len = sizeof(img_names) / sizeof(img_names[0]);

//Channels = RGB
//White = 255/255/255
//Black = 0/0/0

#define HEAP_SIZE 2048 * 2048 * 4
static uint8_t* heap = NULL;
static size_t heap_top = 0;

void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}

int heuristic(int x, int y, int x2, int y2) {
	return abs(x - x2) + abs(y - y2);
}

int main(int argc, char** argv) {
	heap = (uint8_t*)malloc(HEAP_SIZE);
	assert(heap != NULL);

	int width, height, channels;
	unsigned char* img = stbi_load("31.bmp", &width, &height, &channels, 0);
	if (img == NULL) {
		printf("Error in loading the image\n");
		exit(1);
	}
	printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

	/*for (int i = 0; i < width * height * channels; i += channels) {
		unsigned char r = img[i];
		unsigned char g = img[i + 1];
		unsigned char b = img[i + 2];
		if (r == 255) {
			img[i + 1] = 0;
			img[i + 2] = 0;
		}
	}*/
	/*for (int y = 0; y < width; y++) {
		for (int x = 0; x < width; ++x) {
			
		}
	}
	
	for (int i = 0; i < width * height * channels; i += channels) {
		unsigned char r = img[i];
		unsigned char g = img[i + 1];
		unsigned char b = img[i + 2];
		if (r == 255) {
			
		}
	}*/

	char filepath[_MAX_PATH] = { 0 };
	snprintf(filepath, _MAX_PATH, "solution_%s.bmp", img_names[0]);
	stbi_write_bmp(filepath, width, height, channels, img);
}