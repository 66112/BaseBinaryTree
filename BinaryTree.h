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

//_arr是一个前序遍历的数组
BTNode* BinaryTreeCreate(BTDataType* a, int num, int* i); //前序创建二叉树
void BinaryTreeDestory(BTNode* root);                    //销毁二叉树

int BinaryTreeNodeSize(BTNode* root);					//计算二叉树的节点
int BinaryTreeLeafSize(BTNode* root);					//计算二叉树的叶节点
int BinaryTreeLevelKSize(BTNode* root, int k);			//计算二叉树的第k层节点
void BinaryTreePrint(BTNode* root);                               //打印二叉树
int BinaryTreeDepth(BTNode* root);                   //计算树的深度

BTNode* FindBinaryTreeNode(BTNode* root, BTDataType x);   //查找结点
int BinaryTreeComplete(BTNode* root);                   //判断是不是完全二叉树

void BinaryTreePrevOrder(BTNode* root);                 //前序遍历
void BinaryTreeInOrder(BTNode* root);					//中序遍历
void BinaryTreePostOrder(BTNode* root);					//后序遍历
void BinaryTreeLevelOrder(BTNode* root);				//层序遍历

void BinaryTreePrevOrderNoD(BTNode* root);                 //前序遍历非递归
void BinaryTreeInOrderNoD(BTNode* root);					//中序遍历非递归
void BinaryTreePostOrderNoD(BTNode* root);					//后序遍历非递归
void BinaryTreeJingXiang(BTNode* root);                     //二叉树的镜像