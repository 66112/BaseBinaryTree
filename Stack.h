#ifndef __STACK_H__
#define __STACK_H__
#include "BinaryTree.h"
#include <stdio.h>
#include <assert.h>
#define MAX_SIZE 100
typedef struct BTNode* StackDataType;
typedef struct Stack
{
	StackDataType _array[MAX_SIZE];
	size_t _top;       //Õ»¶¥
	size_t _size;	   //ÔªËØ¸öÊý
}Stack;
void StackInit(Stack* ps);
void StackPush(Stack* ps,StackDataType x);
void StackPop(Stack* ps);
StackDataType StackTop(Stack* ps);
size_t StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackDestroy(Stack* ps);
void Print(Stack* ps);

#endif  __STACK_H__