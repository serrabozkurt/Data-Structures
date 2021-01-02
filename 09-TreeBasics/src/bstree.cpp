#include <iostream>
#include "bstree.h"

using namespace std;

void BSTree::initialize(){
    root = NULL;
}

void BSTNode::initialize(int number, BSTNode* par){
    data = number;
    left = NULL;
    right = NULL;
    parent = par;
}

void BSTree::add(int number){
    if(root==NULL){
        root = new BSTNode;
        root->initialize(number, NULL);
    }
    else
        root->add(number, root);
}

void BSTNode::add(int number, BSTNode* par){
    if(number>data){
        if(right)
            right->add(number, right);
        else{
            right = new BSTNode;
            right->initialize(number, par);
        }
    }
    else if(number<data){
        if(left)
            left->add(number, left);
        else{
            left = new BSTNode;
            left->initialize(number, par);
        }
    }
}

BSTNode* BSTree::remove(int number){
    BSTNode* ptr = search(number);
    BSTNode* temp;
    BSTNode* leftst;
    BSTNode* rightst;

    if(ptr){
        leftst = ptr->left;
        rightst = ptr->right;
        if(!ptr->parent){
            if(leftst){
                root=leftst;
                leftst->parent=NULL;
                temp=leftst;
                while(temp->right)
                    temp = temp->right;
                temp->right = rightst;
                if(rightst) rightst->parent = temp;
            }
            else{
                root=rightst;
                rightst->parent=NULL;
            }
            return ptr;
        }

        if(leftst){
            if(ptr->parent->left == ptr)
                ptr->parent->left = leftst;
            else ptr->parent->right = leftst;
            leftst->parent = ptr->parent;
            temp=leftst;
            while(temp->right)
                temp = temp->right;
            temp->right = rightst;
            if(rightst) rightst->parent = temp;
        }
        else{
            if(ptr->parent->left == ptr)
                ptr->parent->left = rightst;
            else ptr->parent->right = rightst;
            if(rightst) rightst->parent = ptr->parent;
        }
    }

    return ptr;
}

BSTNode* BSTree::search(int number){
    BSTNode *ptr=root;

    while(ptr!=NULL){
        if(number>ptr->data)
            ptr = ptr->right;
        else if(number<ptr->data)
            ptr = ptr->left;
        else return ptr;
    }
    return ptr;
}

void inorder(BSTNode *nptr) {
  if (nptr) {
    inorder(nptr->left);
	cout << nptr->data << " ";
    inorder(nptr->right);
  }
}

void BSTree::print_tree(){
  inorder(root);
  cout << endl;
}

void BSTree::destroy(){
    root->destroy();
    delete root;
    root = NULL;
}

void BSTNode::destroy(){
    if(left) left->destroy();
    if(right) right->destroy();
    delete left;
    delete right; 
}

