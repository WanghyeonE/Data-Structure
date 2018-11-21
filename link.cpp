#include <stdio.h>
#include <malloc.h>

typedef struct node {
	void *dataPtr;
	struct node* link;
} NODE;

NODE* createNode(void * itemPtr);

int main(void)
{
	int* newData;
	int* nodeData;
	NODE* node;

	newData = (int*)malloc(sizeof(int));
	*newData = 7;
	node = createNode(newData);
	newData = (int*)malloc(sizeof(int));
	*newData = 75; 
	node->link = createNode(newData); 
	nodeData = (int*)node->dataPtr;
	printf("data1: %d\n", *nodeData);
	nodeData = (int*)node->link->dataPtr; 
	printf("data2: %d\n", *nodeData);
	return 0;
}

NODE* createNode(void* itemPtr)
{
	NODE* nodePtr = NULL;
	nodePtr = (NODE*)malloc(sizeof(NODE));
	nodePtr->dataPtr = itemPtr;
	nodePtr->link = NULL;
	return nodePtr;
}
