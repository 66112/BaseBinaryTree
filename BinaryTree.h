#pragma once
#include "Queue.h"
#include "Stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
typedef char BTDataType;
typedef struct BTNode
{
	struct BTNode* _left;
	struct BTNode* _right;
	BTDataType _data;
}BTNode;

//_arr��һ��ǰ�����������
BTNode* BinaryTreeCreate(BTDataType* a, int num, int* i); //ǰ�򴴽�������
void BinaryTreeDestory(BTNode* root);                    //���ٶ�����

int BinaryTreeNodeSize(BTNode* root);					//����������Ľڵ�
int BinaryTreeLeafSize(BTNode* root);					//�����������Ҷ�ڵ�
int BinaryTreeLevelKSize(BTNode* root, int k);			//����������ĵ�k��ڵ�
void BinaryTreePrint(BTNode* root);                               //��ӡ������
int BinaryTreeDepth(BTNode* root);                   //�����������

BTNode* FindBinaryTreeNode(BTNode* root, BTDataType x);   //���ҽ��
int BinaryTreeComplete(BTNode* root);                   //�ж��ǲ�����ȫ������

void BinaryTreePrevOrder(BTNode* root);                 //ǰ�����
void BinaryTreeInOrder(BTNode* root);					//�������
void BinaryTreePostOrder(BTNode* root);					//�������
void BinaryTreeLevelOrder(BTNode* root);				//�������

void BinaryTreePrevOrderNoD(BTNode* root);                 //ǰ������ǵݹ�
void BinaryTreeInOrderNoD(BTNode* root);					//��������ǵݹ�
void BinaryTreePostOrderNoD(BTNode* root);					//��������ǵݹ�
void BinaryTreeJingXiang(BTNode* root);                     //�������ľ���