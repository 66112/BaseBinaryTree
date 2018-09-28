#include "BinaryTree.h"
void testCreate()
{
	BTDataType arr[] = { 'A', 'B', 'D', '#', '#', '#','C', 'E', '#', '#','F'};
	int num = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	BTNode* root=BinaryTreeCreate(arr, num, &i);
	//int a = BinaryTreeLeafSize(root);
	//int x = BinaryTreeLevelKSize(root,8);
	//BinaryTreePrevOrder(root);             //前序遍历
	//printf("\n");
	//BinaryTreePrevOrderNoD(root);			 //前序非递归
	//printf("\n");
	//BinaryTreeInOrder(root);				//中序遍历
	//printf("\n");
	//BinaryTreeInOrderNoD(root);           //中序非递归
	//printf("\n");					
	//BinaryTreePostOrder(root);				//后序遍历
	//printf("\n");
	//BinaryTreePostOrderNoD(root);	            //后序非递归
	//printf("\n");								
	//BTNode* find1=FindBinaryTreeNode(root, 'X');   //查找结点
	//BTNode* find2 = FindBinaryTreeNode(root, 'G');   //查找结点
	//BinaryTreeLevelOrder(root);
	//int a=BinaryTreeComplete(root);
	//printf("%d\n", a);
	//printf("树的深度：%d\n", BinaryTreeDepth(root));
	BinaryTreeJingXiang(root);                     //二叉树的镜像
	BinaryTreePrint(root);
	BinaryTreeDestory(root);
}
int main()
{
	testCreate();
	return 0;
}