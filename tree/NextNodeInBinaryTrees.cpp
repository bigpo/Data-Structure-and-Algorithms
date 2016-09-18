//����һ�������������е�һ����㣬����ҳ������������һ����㣿
//���еĽڵ�����������ֱ�ָ�����Һ��ӵ�ָ���⣬����һ��ָ�򸸽ڵ��ָ�롣

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
    //����һ�ö�����;

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

    //������һ���ڵ㡣���湹���Ķ����������������Ϊ
    // d b h e i a f c g
    // 4 2 8 5 9 1 6 3 7
    BinaryTreeNode* NextTreeNode = GetNext(d); //��һ���ڵ�Ϊb
    cout << NextTreeNode->value << endl; //ֵΪ2

    NextTreeNode = GetNext(i); //i����һ���ڵ�Ϊa
    cout << NextTreeNode->value << endl; //ֵΪ1

    return 0;
}

BinaryTreeNode* GetNext(BinaryTreeNode* pTree) {
    if (pTree == NULL)
        return NULL;
    BinaryTreeNode* pNext;

    if (pTree->right != NULL) { //����ڵ����������Ϊ�գ����������������ӽڵ�Ϊ��һ���ڵ�
        BinaryTreeNode* pRight = pTree->right;
        while (pRight->left != NULL)
            pRight = pRight->left;
        pNext = pRight;
    }

    else if (pTree->parent != NULL) {
        BinaryTreeNode* pCurrent = pTree;
        BinaryTreeNode* pParent = pTree->parent; //��Ӧ��û���Һ��ӣ��Ҹýڵ��Ǹ��ڵ�����ӵ����
        while (pParent != NULL && pCurrent == pParent->right) { //��Ӧ��û���Һ��ӣ��Ҹýڵ�ʱ���ڵ���Һ��ӵ����
            pCurrent = pParent;
            pParent = pParent->parent; //���ϱ�����ֱ���ýڵ��Ǹ��ڵ�����ӣ�
        }

        pNext = pParent; //����һ���ڵ㼴Ϊ�ýڵ�ĸ��ڵ㡣
    }

    return pNext;
}
