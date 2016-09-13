#include <iostream>
#include <stdlib.h>
#include <stack>
#include "tree.h"

using namespace std;

void InOrder2(TreeNode* pTree); 
void goAlongLeftBranch(TreeNode* pTree, stack<TreeNode*> &s);

void InOrder3(TreeNode* pTree);

int main() {
	TreeNode* BinTree = CreateBinTree();
	
	//二叉树中序遍历
	InOrder3(BinTree);
	printf("\n");

	system("pause");
	return 0;
}


//**********************中序遍历迭代版1*****************************
void goAlongLeftBranch(TreeNode* pTree, stack<TreeNode*> &s) { 
	while (pTree) {          //区别于先序遍历迭代版，
		s.push(pTree);       //只压入当前节点
		pTree = pTree->left; //深入左子树
	}
}

void InOrder2(TreeNode* pTree) {
	stack<TreeNode*> s;
	while (true) {
		goAlongLeftBranch(pTree, s); //从当前节点出发，深入左侧分支，将节点逐批入栈
		if (s.empty())
			break;
		pTree = s.top();
		s.pop();

		printf("%d ", pTree->value); //访问栈顶节点的值
		pTree = pTree->right;
	}
}

//*******************************************************************




//**********************中序遍历迭代版2*****************************

void InOrder3(TreeNode* pTree) {   //与中序遍历的迭代版1等价
	stack<TreeNode*> s;
	while (true) {
		if (pTree) {
			s.push(pTree);
			pTree = pTree->left;
		}
		else if (!s.empty()) {
			pTree = s.top();
			s.pop();

			printf("%d ", pTree->value);
			pTree = pTree->right;
		}
		else
			break;
	}
	return;
}

//*******************************************************************