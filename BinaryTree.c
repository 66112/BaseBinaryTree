#include "BinaryTree.h"
//#include "Queue.h"
//_arr为数组，num为元素个数，i为元素下标

BTNode* BuyNodeTree(BTDataType x)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	assert(newNode);
	newNode->_data = x;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}

BTNode* BinaryTreeCreate(BTDataType* a, int num, int* i)  //前序，VLR ，数组，元素个数，元素下标
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
//后序销毁树
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

int BinaryTreeDepth(BTNode* root)                   //计算树的深度
{
	if (root == NULL)
		return 0;
	int _left = BinaryTreeDepth(root->_left) + 1;
	int _right = BinaryTreeDepth(root->_right) + 1;
	return _left > _right ? _left : _right;
}

BTNode* FindBinaryTreeNode(BTNode* root, BTDataType x)   //查找结点
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
void BinaryTreePrevOrder(BTNode* root)                //前序遍历
{
	if (root == NULL)
		return;
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)					//中序遍历
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)					//后序遍历
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}

void BinaryTreeLevelOrder(BTNode* root)				//层序遍历
{
	Queue q;                                        //创建一个队列
	QueueInit(&q);
	if (root == NULL)
		return;
	QueuePush(&q, root);
	while (QueueEmpty(&q))                         //队列不为空，就还有元素
	{
		BTNode* front = QueueFront(&q);
		if (front->_left)                          //队列首元素的左指针若不为空，则将左指针的元素压入队列
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)                        //右指针同理
		{
			QueuePush(&q, front->_right);
		}
		printf("%c ", front->_data);              //遍历队列首元素
		QueuePop(&q);                             //pop出首元素
	}
}
int BinaryTreeComplete(BTNode* root)                  //判断是不是完全二叉树
{
	int flag = 0;               //如果压入第一个空指针后，后边还有元素，则不是完全二叉树
	Queue q;
	QueueInit(&q);              //如果压入第一个空指针后，后边都是空指针，则是完全二叉树
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
			flag = 1;						//记录队列中压入的第一个空指针
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

void BinaryTreePrevOrderNoD(BTNode* root)                //前序遍历非递归
{
	Stack s;
	StackInit(&s);
	BTNode* cur = root;                        //cur总指向一个树的根节点
	if (root == NULL)
	{
		printf("树为空！\n");
		return;
	}
	while (cur || StackEmpty(&s))
	{
		//先访问树的左树
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//cur为空，先pop掉，再访问top的右树
		BTNode* top = StackTop(&s);
		StackPop(&s);
		//子问题访问右树
		cur = top->_right;
	}
}

void BinaryTreeInOrderNoD(BTNode* root)					//中序遍历非递归
{
	Stack s;
	StackInit(&s);
	BTNode* cur = root;                        //cur总指向一个树的根节点
	if (root == NULL)
	{
		printf("树为空！\n");
		return;
	}
	while (cur || StackEmpty(&s))
	{
		//先入树的左节点
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

void BinaryTreePostOrderNoD(BTNode* root)					//后序遍历非递归
{
	BTNode* top;
	BTNode* prev=NULL;
	Stack s;
	StackInit(&s);
	BTNode* cur = root;                        //cur总指向一个树的根节点
	if (root == NULL)
	{
		printf("树为空！\n");
		return;
	}
	while (cur || StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->_left;
		}
		//这里的cur始终为空
		top = StackTop(&s);
		if (top->_right == NULL||top->_right == prev)  //一旦访问过右节点，就可以遍历根节点了
		{
			printf("%c ", top->_data);
			prev = top;                     //标记上一次访问的节点,即访问根节点之前，要访问右树节点
			StackPop(&s);
		}
		else
		{
			cur = top->_right;
		}
	}
}

void BinaryTreeJingXiang(BTNode* root)                     //二叉树的镜像
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