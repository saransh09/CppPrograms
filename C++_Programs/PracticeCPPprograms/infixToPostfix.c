#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};
 
// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if (!stack) 
        return NULL;
 
    stack->top = -1;
    stack->capacity = capacity;
 
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
 
    if (!stack->array)
        return NULL;
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}
char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}
void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}
int isOperand(char ch){
    return (ch >='a' && ch<='z')||(ch>='A' && ch<='Z');
}
int Prec(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}
int infixToPostfix(char * exp){
    int i,k;
    struct Stack* stack = createStack(strlen(exp));
    if(!stack){
        return -1;
    }
    for(i=0,k=-1;exp[i];i++){
        if(isOperand(exp[i])){
            exp[++]
        }
    }
}