//给定一个二叉树和其中的一个结点，如何找出中序遍历的下一个结点？
//树中的节点除了有两个分别指向左右孩子的指针外，还有一个指向父节点的指针。

#include <iostream>

using namespace std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;
};



BinaryTreeNode* GetNext(BinaryTreeNode* pTree);

int main(int argc, char *argv[])
{
    //创建一棵二叉树;

    BinaryTreeNode* a = new BinaryTreeNode();
    BinaryTreeNode* b = new BinaryTreeNode();
    BinaryTreeNode* c = new BinaryTreeNode();
    BinaryTreeNode* d = new BinaryTreeNode();
    BinaryTreeNode* e = new BinaryTreeNode();
    BinaryTreeNode* f = new BinaryTreeNode();
    BinaryTreeNode* g = new BinaryTreeNode();
    BinaryTreeNode* h = new BinaryTreeNode();
    BinaryTreeNode* i = new BinaryTreeNode();

    a->parent = NULL;
    a->left = b;
    a->right = c;
    a->value = 1;

    b->parent = a;
    b->left = d;
    b->right = e;
    b->value = 2;

    c->parent = a;
    c->left = f;
    c->right = g;
    c->value = 3;

    d->parent = b;
    d->left = NULL;
    d->right = NULL;
    d->value = 4;

    e->parent = b;
    e->left = h;
    e->right = i;
    e->value = 5;

    f->parent = c;
    f->left = NULL;
    f->right = NULL;
    f->value = 6;

    g->parent = c;
    g->left = NULL;
    g->right = NULL;
    g->value = 7;

    h->parent = e;
    h->left = NULL;
    h->right = NULL;
    h->value = 8;

    i->parent = e;
    i->left = NULL;
    i->right = NULL;
    i->value = 9;

    //测试下一个节点。上面构建的二叉树中序遍历序列为
    // d b h e i a f c g
    // 4 2 8 5 9 1 6 3 7
    BinaryTreeNode* NextTreeNode = GetNext(d); //下一个节点为b
    cout << NextTreeNode->value << endl; //值为2

    NextTreeNode = GetNext(i); //i的下一个节点为a
    cout << NextTreeNode->value << endl; //值为1

    return 0;
}

BinaryTreeNode* GetNext(BinaryTreeNode* pTree) {
    if (pTree == NULL)
        return NULL;
    BinaryTreeNode* pNext;

    if (pTree->right != NULL) { //如果节点的右子树不为空，则右子树的最左孩子节点为下一个节点
        BinaryTreeNode* pRight = pTree->right;
        while (pRight->left != NULL)
            pRight = pRight->left;
        pNext = pRight;
    }

    else if (pTree->parent != NULL) {
        BinaryTreeNode* pCurrent = pTree;
        BinaryTreeNode* pParent = pTree->parent; //对应于没有右孩子，且该节点是父节点的左孩子的情况
        while (pParent != NULL && pCurrent == pParent->right) { //对应于没有右孩子，且该节点时父节点的右孩子的情况
            pCurrent = pParent;
            pParent = pParent->parent; //向上遍历，直到该节点是父节点的左孩子，
        }

        pNext = pParent; //则下一个节点即为该节点的父节点。
    }

    return pNext;
}
