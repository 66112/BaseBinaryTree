#include "Queue.h"
#include "BinaryTree.h"
QueueNode* BuyNode(QueDataType x)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(struct QueueNode));
	assert(newNode);
	newNode->data = x;
	newNode->_next = NULL;
	return newNode;
}
void QueueInit(Queue* q)
{
	assert(q);
	q->_head = q->_tail = NULL;
}
void QueuePush(Queue* q, QueDataType x)
{
	if (q->_head==NULL)
		q->_head = q->_tail=BuyNode(x);
	else
	{
		q->_tail->_next = BuyNode(x);
		q->_tail = q->_tail->_next;
	}
}
void QueuePop(Queue* q)
{
	QueueNode* flag = q->_head;
	q->_head = q->_head->_next;
	free(flag);
}
QueDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_head->data;
}
QueDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_tail->data;
}
size_t QueueSize(Queue* q)
{
	size_t cout = 0;
	while (q->_head)
	{
		cout++;
		q->_head = q->_head->_next;
	}
	return cout;
}
int QueueEmpty(Queue* q)
{
	return q->_head==NULL ? 0 : 1;
}
void QueueDestory(Queue* q)
{
	assert(q);
	while (q->_head)
	{
		QueueNode* del = q->_head;
		q->_head = q->_head->_next;
		free(del);
	}
}
