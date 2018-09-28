#pragma once
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
typedef struct BTNode* QueDataType;   //结构体指针
typedef struct QueueNode
{
	QueDataType data;
	struct QueueNode* _next;
}QueueNode;
typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;
void QueueInit(Queue* q);
void QueuePush(Queue* q, QueDataType x);
void QueuePop(Queue* q);
QueDataType QueueFront(Queue* q);
QueDataType QueueBack(Queue* q);
size_t QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestory(Queue* q);