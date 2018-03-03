// BinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


typedef struct treenode
{
	struct treenode *left;
	int data;
	struct treenode *right;
}NODE;

class tree{
public:
	NODE *root;
	NODE *create(NODE *ptr,int *d);
	void preorder(NODE *ptr);
	void inorder(NODE *ptr);
	void postorder(NODE *ptr);
};


NODE *tree::create(NODE *ptr,int *d)
{
	if(ptr==NULL)
	{
		ptr = (NODE*)malloc(sizeof(NODE));
		ptr ->left = ptr->right = NULL;
		ptr ->data = *d;
	}else
	{
		if(ptr->data>*d)
		{
			ptr->left = create(ptr->left,d);
		}else
		{
			ptr->right = create(ptr->right,d);
		}
	}
	return ptr;


}
void tree::preorder(NODE *ptr)
{
	if(ptr!=NULL){
		cout << ptr->data<<",";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void tree::inorder(NODE *ptr)
{
	if(ptr!=NULL){
		inorder(ptr->left);
		cout << ptr->data<<",";
		
		inorder(ptr->right);
	}
}
void tree::postorder(NODE *ptr)
{
	if(ptr!=NULL){
		
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data<<",";
	}
}
int _tmain(int argc, _TCHAR* argv[])
{

	tree t;
	int arr[] = {30,15,50,35,10,25,55,40,20};
	int value = 10;
	t.root = NULL;
	cout << "Hi let`s test the binary tree of this porject;\r\ncreat tree";
	for(int i=0;i<9;i++)
		t.root = t.create(t.root,&arr[i]);
	cout << "\r\npreorder:";
	t.preorder(t.root);
	cout << "\r\ninorder:";
	t.inorder(t.root);
	cout << "\r\npostorder:";
	t.postorder(t.root);
	system("pause");
	return 0;
}

