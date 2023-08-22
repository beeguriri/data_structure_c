#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode *MakeBTreeNode(void) {

    BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;

    return nd;
}

Data GetData(BTreeNode *bt) {
    return bt->data;
}

void SetData(BTreeNode *bt, Data data) {
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt) {
    return bt->left;
}
BTreeNode *GetRightSubTree(BTreeNode *bt) {
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) {

    //기존에 서브트리가 있으면, 기존 서브트리 삭제
    if(main->left != NULL)
        free(main->left);
    
    //새로 만든 서브트리 넣어줌
    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {

     //기존에 서브트리가 있으면, 기존 서브트리 삭제
    if(main->right != NULL)
        free(main->right);
    
    //새로 만든 서브트리 넣어줌
    main->right = sub;

}