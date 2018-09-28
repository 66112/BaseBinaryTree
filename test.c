#include "BinaryTree.h"
void testCreate()
{
	BTDataType arr[] = { 'A', 'B', 'D', '#', '#', '#','C', 'E', '#', '#','F'};
	int num = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	BTNode* root=BinaryTreeCreate(arr, num, &i);
	//int a = BinaryTreeLeafSize(root);
	//int x = BinaryTreeLevelKSize(root,8);
	//BinaryTreePrevOrder(root);             //ǰ�����
	//printf("\n");
	//BinaryTreePrevOrderNoD(root);			 //ǰ��ǵݹ�
	//printf("\n");
	//BinaryTreeInOrder(root);				//�������
	//printf("\n");
	//BinaryTreeInOrderNoD(root);           //����ǵݹ�
	//printf("\n");					
	//BinaryTreePostOrder(root);				//�������
	//printf("\n");
	//BinaryTreePostOrderNoD(root);	            //����ǵݹ�
	//printf("\n");								
	//BTNode* find1=FindBinaryTreeNode(root, 'X');   //���ҽ��
	//BTNode* find2 = FindBinaryTreeNode(root, 'G');   //���ҽ��
	//BinaryTreeLevelOrder(root);
	//int a=BinaryTreeComplete(root);
	//printf("%d\n", a);
	//printf("������ȣ�%d\n", BinaryTreeDepth(root));
	BinaryTreeJingXiang(root);                     //�������ľ���
	BinaryTreePrint(root);
	BinaryTreeDestory(root);
}
int main()
{
	testCreate();
	return 0;
}