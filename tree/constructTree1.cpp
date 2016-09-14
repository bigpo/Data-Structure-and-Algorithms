//已知先序遍历序列和中序遍历序列重建二叉树
//代码参考《剑指offer》

#include <iostream>
#include <exception>
#include "tree.h"

using namespace std;

TreeNode* Construct(int* preOrder, int* inOrder, int length);
TreeNode* ConstructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder);

int main(int argc, char *argv[])
{
    int preOrder[] = {1,2,3,4,6,6,7};
    int inOrder[] = {3,4,2,1,6,5,7};

    int length = sizeof(preOrder)/sizeof(preOrder[0]);

    try {
        TreeNode* ConstructTree = Construct(preOrder, inOrder, length);

        //调用头文件中的先序遍历和中序遍历检验
        //二叉树的构建是否正确
        PreOrder(ConstructTree);
        cout << endl;

        InOrder(ConstructTree);
        cout << endl;
    }
    catch (const char* e) {
        cout << e << endl;
    }

    return 0;
}

TreeNode* Construct(int* preOrder, int* inOrder, int length) {
    if (preOrder == NULL || inOrder == NULL || length <= 0)
        return NULL;

    return ConstructCore(preOrder, preOrder+length-1, inOrder, inOrder+length-1);
}

TreeNode* ConstructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder) {

    int rootValue = startPreOrder[0]; //先序遍历的首节点即为二叉树的根节点
    TreeNode* root = new TreeNode();
    root->value = rootValue;
    root->left = NULL;
    root->right = NULL;

    if (startPreOrder == endPreOrder) { //只有一个节点的情况
        if (startInOrder == endInOrder
                && *startPreOrder == *startInOrder)
            return root;
        else
          throw "Invalid input.";
    }

    int *rootInOrder = startInOrder;
    while (rootInOrder < endInOrder //while循环执行完毕，应当已找到中序遍历序列中根节点的位置
               && *rootInOrder != rootValue)
        rootInOrder++;
    if (rootInOrder == endInOrder //如果没有找到，说明中序序列有误
            && *rootInOrder != rootValue)
       throw "Invalid input.";

    int leftLength = rootInOrder - startInOrder; //左子树中序序列的长度
    int rightLength = endInOrder - rootInOrder; //右子树的长度

    int* leftPreOrderEnd = startPreOrder + leftLength; //左子树在先序遍历序列中的终止位置

    if (leftLength > 0) {
        root->left = ConstructCore(startPreOrder+1, leftPreOrderEnd,
                                   startInOrder, rootInOrder-1);
    }

    if (rightLength > 0) {
        root->right = ConstructCore(leftPreOrderEnd+1, endPreOrder,
                                    rootInOrder+1, endInOrder);
    }

    return root;


}
