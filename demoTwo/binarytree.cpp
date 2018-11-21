#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tree
 {
  int data;
  struct tree *left;
  struct tree *right;
 };
 typedef struct tree treenode;
 typedef treenode *btree;

btree insertnode(btree root,int value)
 {
  btree newnode;
  btree current;
  btree back;
  newnode=(btree)malloc (sizeof(treenode));
  newnode->data=value;
  newnode->left=NULL;
  newnode->right=NULL;

  if (root==NULL)
   {
    printf("\nIt is error!No element!\n");
    return newnode;
  else
   {
	current=root;
	while(current!=NULL)
	{
	 back=current;
	 if (current->data>value)
	  current=current->left;
	 else
	  current=current->right;
	}
   if (back->data>value)
	back->left=newnode;
   else
	back->right=newnode;
   }
  return root;
 }

btree createbtree(int *data,int len)
 {
  btree root=NULL;
  int i;

  for(i=0;i<len;i++)
   root=insertnode(root,data[i]);
  return root;
 }

void preorder(btree ptr)
 {
  if (ptr==NULL)
	 return ptr;
  printf("[%2d]==>",ptr->data);
  if(ptr->left!=NULL)
	preorder(ptr->left);
  if (ptr->right!=NULL)
	preorder(ptr->right);
 }

void midorder(btree ptr)
 {
  if (ptr==NULL)
	return ptr;
  if (ptr->left!=NULL)
	midorder(ptr->left);
  printf("[%2d]==>",ptr->data);
  if (ptr->right!=NULL)
	midorder(ptr->right);
 }

void postorder(btree ptr)
 {
  if (ptr==NULL)
	 return ptr;
  if (ptr->left!=NULL)
	postorder(ptr->left);
  if (ptr->right!=NULL)
	postorder(ptr->right);
  printf("[%2d]==>",ptr->data);
 }




void menushow()
 {
  puts("\n");
  printf("This is just a jinwei binary tree!\n");
  puts("<1>---List the source content of the tree.\n");
  puts("<2>---Show the content of the tree after proorder.\n");
  puts("<3>---Show the content of the tree after midorder.\n");
  puts("<4>---Show the content of the tree after postorder.\n");
  puts("<5>---Exit the program!\n");
  puts("\n\n");
  printf("Select one for running[1...5]:");
 }


void main()
 {
 int i,choice,yourchoice,len,flag;
 btree root=NULL;

 int data[101],value;
 flag=1; //signed the status of the while circle
 clrscr();

 printf ("\n Please input the elements of  binary tree(Exit for0'): \n");
	len=0;
	scanf ("%d", &value);
	while (value!=0)
	{
	   data[len]=value;
		len=len+1;
		scanf ("%d", &value);

	}

  root=createbtree(data,len);
  while(flag)
  {
   Home: menushow();
   scanf("%d",&choice);

   if(choice>5||choice<1)
	{
	 printf("Error!What you select is not exist!Please try again!\n");
	 printf("Press any key to continue......\n");
	 getch();
	 goto Home;
	}

   while(choice!=10)
   {
	switch(choice)
	{
	 case 1 :    printf("The source tree are:\n");
				 for(i=0;i<=len;i++)
				  if(data[i]!=0)
				  printf("[%2d]==>",data[i]);
				 choice=10;
				 break;

	 case 2 :  printf("The Previous_order of the tree are:\n");
				 preorder(root);
				 choice=10;
				 break;
	 case 3 :  printf("The Middle_order of the tree are:\n");
				 midorder(root);
				 choice=10;
				 break;
	 case 4 :  printf("The Post_order of the tree are:\n");
				 postorder(root);
				 choice=10;
				 break;
	 case 5 :  exit(1);
				 choice=10;
				 flag=0;
				 break;
	 }//switch circle ends
   }//while circle ends

  }//the bigger while circle enends
 }


