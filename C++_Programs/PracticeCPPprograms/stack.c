#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode{
	int data;
	struct StackNode* next;
};

struct StackNode * newNode(int data){
	struct StackNode* stackNode = (struct StackNode*) malloc(sizeof(stackNode));
	stackNode->data;
	stackNode->next = NULL;
	return stackNode;
};

int isEmpty(struct StackNode *root){
	return !root;
}

void push(struct StackNode** root, int data){
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	printf("%d pushed into the stack\n", data);
}

int pop(struct StackNode** root){
	if(isEmpty(*root))
		printf("The Stack is already empty\n");
	struct StackNode * temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);
	return popped;
}

int peek(struct StackNode* root){
	if(isEmpty(root))
		printf("The stack is empty\n");
	return root->data;
}


void main(){
	struct StackNode* root = NULL;
	push(&root,10);
	push(&root,20);
	push(&root,30);
	return;
}