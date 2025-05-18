#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node {
	void* x;
	void* y;
	void* r;
	Node* prev;
	Node* next;
};

typedef struct Info {
	int x;
	int y;
	int r;
}Info;

typedef struct labyrinth_graphs {
	int width, height;
	Node* adj_list;
	bool IsPath;
}graph;