#include <iostream>
#include <stdlib.h>
#include <stack>
#include "tree.h"

using namespace std;

void PreOrder2(TreeNode* pTree); //先序遍历迭代版
void visitAlongLeftBranch(TreeNode* pTree, stack<TreeNode*>& s);

int main() {
	TreeNode* BinTree = CreateBinTree();

	//二叉树先序遍历
	PreOrder2(BinTree);
	printf("\n");


	system("pause");
	return 0;
}

//****************先序遍历迭代版********************
void PreOrder2(TreeNode* pTree) {
	stack<TreeNode*> s;
	while (true) {
		visitAlongLeftBranch(pTree, s);
		if (s.empty())
			break;
		pTree = s.top();
		s.pop();
	}
}

void visitAlongLeftBranch(TreeNode* pTree, stack<TreeNode*>& s) {
	while (pTree) {
		printf("%d ", pTree->value); //先访问节点
		if (pTree->right)            //将节点右子树入栈(若存在)
			s.push(pTree->right);
		pTree = pTree->left;         //深入左子树
	}
}

//**************************************************************