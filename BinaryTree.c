#include "BinaryTree.h"
//#include "Queue.h"
//_arrΪ���飬numΪԪ�ظ�����iΪԪ���±�

BTNode* BuyNodeTree(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	assert(newNode);
	newNode->_data = x;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}

BTNode* BinaryTreeCreate(BTDataType* a, int num, int* i)  //ǰ��VLR �����飬Ԫ�ظ�����Ԫ���±�
{
	if (a[*i] != '#'&& (*i)<num)
	{
		BTNode* root = BuyNodeTree(a[*i]);
		(*i)++;
		root->_left = BinaryTreeCreate(a, num, i);
		(*i)++;
		root->_right = BinaryTreeCreate(a, num, i);
		return root;
	}
	else
		return NULL;
}

int BinaryTreeNodeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeNodeSize(root->_left) + BinaryTreeNodeSize(root->_right) + 1;
}
//����������
void BinaryTreeDestory(BTNode* root)
{
	if (root==NULL)
	{
		return;
	}
	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL && root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

int BinaryTreeDepth(BTNode* root)                   //�����������
{
	if (root == NULL)
		return 0;
	int _left = BinaryTreeDepth(root->_left) + 1;
	int _right = BinaryTreeDepth(root->_right) + 1;
	return _left > _right ? _left : _right;
}

BTNode* FindBinaryTreeNode(BTNode* root, BTDataType x)   //���ҽ��
{
	BTNode* _left;
	BTNode*  _right;
	if (root == NULL || root->_data == x)
		return root;
	_left = FindBinaryTreeNode(root->_left, x);
	if (_left)
		return _left;
	_right = FindBinaryTreeNode(root->_right, x);
	if (_right)
		return _right;
	return NULL;
}
void BinaryTreePrevOrder(BTNode* root)                //ǰ�����
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)					//�������
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)					//�������
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode* root)				//�������
{
	Queue q;                                        //����һ������
	QueueInit(&q);
	if (root == NULL)
		return;
	QueuePush(&q, root);
	while (QueueEmpty(&q))                         //���в�Ϊ�գ��ͻ���Ԫ��
	{
		BTNode* front = QueueFront(&q);
		if (front->_left)                          //������Ԫ�ص���ָ������Ϊ�գ�����ָ���Ԫ��ѹ�����
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)                        //��ָ��ͬ��
		{
			QueuePush(&q, front->_right);
		}
		printf("%c ", front->_data);              //����������Ԫ��
		QueuePop(&q);                             //pop����Ԫ��
	}
}
int BinaryTreeComplete(BTNode* root)                  //�ж��ǲ�����ȫ������
{
	int flag = 0;               //���ѹ���һ����ָ��󣬺�߻���Ԫ�أ�������ȫ������
	Queue q;
	QueueInit(&q);              //���ѹ���һ����ָ��󣬺�߶��ǿ�ָ�룬������ȫ������
	if (root == NULL)
		return 1;
	QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		if (front != NULL)
		{
			if (flag == 1)                          
				return 0;
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else
		{
			flag = 1;						//��¼������ѹ��ĵ�һ����ָ��
		}
		QueuePop(&q);
	}
	return 1;
}

void BinaryTreePrint(BTNode* root)
{
	if (root == NULL)
		return;
	else
	{
		printf("%c ", root->_data);
		BinaryTreePrint(root->_left);
		BinaryTreePrint(root->_right);
	}
}

void BinaryTreePrevOrderNoD(BTNode* root)                //ǰ������ǵݹ�
{
	Stack s;
	StackInit(&s);
	BTNode* cur = root;                        //cur��ָ��һ�����ĸ��ڵ�
	if (root == NULL)
	{
		printf("��Ϊ�գ�\n");
		return;
	}
	while (cur || StackEmpty(&s))
	{
		//�ȷ�����������
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//curΪ�գ���pop�����ٷ���top������
		BTNode* top = StackTop(&s);
		StackPop(&s);
		//�������������
		cur = top->_right;
	}
}

void BinaryTreeInOrderNoD(BTNode* root)					//��������ǵݹ�
{
	Stack s;
	StackInit(&s);
	BTNode* cur = root;                        //cur��ָ��һ�����ĸ��ڵ�
	if (root == NULL)
	{
		printf("��Ϊ�գ�\n");
		return;
	}
	while (cur || StackEmpty(&s))
	{
		//����������ڵ�
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		BTNode* top = StackTop(&s);
		printf("%c ", top->_data);
		StackPop(&s);
		cur = top->_right;
	}
}

void BinaryTreePostOrderNoD(BTNode* root)					//��������ǵݹ�
{
	BTNode* top;
	BTNode* prev=NULL;
	Stack s;
	StackInit(&s);
	BTNode* cur = root;                        //cur��ָ��һ�����ĸ��ڵ�
	if (root == NULL)
	{
		printf("��Ϊ�գ�\n");
		return;
	}
	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//�����curʼ��Ϊ��
		top = StackTop(&s);
		if (top->_right == NULL||top->_right == prev)  //һ�����ʹ��ҽڵ㣬�Ϳ��Ա������ڵ���
		{
			printf("%c ", top->_data);
			prev = top;                     //�����һ�η��ʵĽڵ�,�����ʸ��ڵ�֮ǰ��Ҫ���������ڵ�
			StackPop(&s);
		}
		else
		{
			cur = top->_right;
		}
	}
}

void BinaryTreeJingXiang(BTNode* root)                     //�������ľ���
{
	BTNode* tmp;
	if (root == NULL)
		return;
	tmp = root->_left;
	root->_left = root->_right;
	root->_right = tmp;
	BinaryTreeJingXiang(root->_left);
	BinaryTreeJingXiang(root->_right);
}