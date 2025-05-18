#include <stdio.h>
#include "main.h"

void insert(Node* head, Info* x, Info* y, Info* r) {
	Node* currNode = head;
	if (currNode->x == NULL) {
		currNode->x = x;
		currNode->y = y;
		currNode->r = r;
		return;
	}
	else {
		Node* n = allocate(sizeof(Node));
		n->x = x;
		n->y = y;
		n->r = r;
		n->prev = NULL;
		n->next = NULL;
		if (currNode->next != NULL) {
			n->next = currNode->next;
			currNode->next->prev = n;
		}
		currNode->next = n;
		n->prev = currNode;
	}
}