#pragma once

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
};

//创建一棵二叉树，主要用于测试
TreeNode* CreateBinTree() {
	TreeNode* pA = new TreeNode();
	TreeNode* pB = new TreeNode();
	TreeNode* pC = new TreeNode();
	TreeNode* pD = new TreeNode();
	TreeNode* pE = new TreeNode();
	TreeNode* pF = new TreeNode();
	TreeNode* pG = new TreeNode();

	pA->value = 1;
	pB->value = 2;
	pC->value = 3;
	pD->value = 4;
	pE->value = 5;
	pF->value = 6;
	pG->value = 7;

	pA->left = pB;
	pA->right = pE;
	pB->left = pC;
	pB->right = NULL;
	pC->left = NULL;
	pC->right = pD;
	pD->left = NULL;
	pD->right = NULL;
	pE->left = pF;
	pE->right = pG;
	pF->left = NULL;
	pF->right = NULL;
	pG->left = NULL;
	pG->right = NULL;

	return pA;
}


//先序打印二叉树
void PreOrder(TreeNode* pTree) {
	if (pTree == NULL)
		return;

	printf("%d ", pTree->value);
	PreOrder(pTree->left);
	PreOrder(pTree->right);
}

//中序打印二叉树
void InOrder(TreeNode* pTree) {
	if (pTree == NULL)
		return;

	InOrder(pTree->left);
	printf("%d ", pTree->value);
	InOrder(pTree->right);
}

//后序打印二叉树
void PostOrder(TreeNode* pTree) {
	if (pTree == NULL)
		return;

	PostOrder(pTree->left);
	PostOrder(pTree->right);
	printf("%d ", pTree->value);
}

