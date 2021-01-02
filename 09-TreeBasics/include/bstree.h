#pragma once

struct BSTNode {
	int data;
	BSTNode *left;
	BSTNode *right;
	BSTNode *parent;
    void initialize(int, BSTNode*);
    void destroy();
    void add(int, BSTNode*);
};

struct BSTree {
	BSTNode *root;
    void initialize();
    void add(int);
    BSTNode* remove(int);
    BSTNode* search(int);
    void print_tree();
    void destroy();
};