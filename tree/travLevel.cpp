#include <iostream>
#include <stdlib.h>
#include <queue>
#include "tree.h"

using namespace std;

void travLevel(TreeNode* pTree); //层次遍历

int main() {
	TreeNode* BinTree = CreateBinTree();

	travLevel(BinTree);
	printf("\n");

	system("pause");
	return 0;
}

//**************层次遍历*******************************
void travLevel(TreeNode* pTree) {
	queue<TreeNode*> Q;
	Q.push(pTree);

	while (!Q.empty()) {
	
		TreeNode* pTree = Q.front();
		Q.pop(); //删除队首元素
		
		printf("%d ", pTree->value); //访问节点
		
		if (pTree->left)
			Q.push(pTree->left);
		if (pTree->right)
			Q.push(pTree->right);
	}
}
//******************************************************