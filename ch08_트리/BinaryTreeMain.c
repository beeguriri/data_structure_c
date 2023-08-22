#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode *bt) {

    if(bt==NULL)
        return;

    InorderTraverse(bt->left);
    printf("%d ", bt->data);
    InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode *bt) {

    if(bt==NULL)
        return;

    printf("%d ", bt->data);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode *bt) {

    if(bt==NULL)
        return;

    PostorderTraverse(bt->left);
    PostorderTraverse(bt->right);
    printf("%d ", bt->data);

}

int main(void) {

    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);

    MakeLeftSubTree(bt1, bt2); //bt2를 bt1의 왼쪽 자식 노드로
    MakeRightSubTree(bt1, bt3); //bt3를 bt1의 오른쪽 자식 노드로
    MakeLeftSubTree(bt2, bt4); //bt4를 bt2의 왼쪽 자식 노드로

    printf("중위순회: ");
    InorderTraverse(bt1);
    printf("\n");
    printf("전위순회: ");
    PreorderTraverse(bt1);
    printf("\n");
    printf("후위순회: ");
    PostorderTraverse(bt1);
    printf("\n");

    return 0;
}