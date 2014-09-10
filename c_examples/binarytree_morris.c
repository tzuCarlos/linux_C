//  Morris Traversal
//
//  source:
//   http://www.geeksforgeeks.org/morris-traversal-for-preorder/ 
//   http://comsci.liu.edu/~murali/algo/Morris.htm  
//
#include <stdio.h>
#include <stdlib.h>


////////////////////////
struct Node { int Data;  struct Node *Left,*Right; int mark;};
int Insert(struct Node **root,int value);
void DeleteTree(struct Node *root);
void PrintTree(struct Node *root);


// Preorder traversal without recursion and without stack
void morrisTraversalPreorder(struct Node* root)
{
    while (root)
    {
        // If left child is null, print the current node data. Move to
        // right child.
        if (root->Left == NULL)
        {
            printf( "%d ", root->Data );
            root = root->Right;
        }
        else
        {
            // Find inorder predecessor
            struct Node* current = root->Left;
            while (current->Right && current->Right != root)
                current = current->Right;
 
            // If the right child of inorder predecessor already points to
            // this node
            if (current->Right == root)
            {
                current->Right = NULL;
                root = root->Right;
            }
 
            // If right child doesn't point to this node, then print this
            // node and make right child point to this node
            else
            {
                printf("%d ", root->Data);
                current->Right = root;
                root = root->Left;
            }
        }
    }
}
////////////////////////
void MorrisTraversal(struct Node *root)
	{  struct Node *p,*pre;

	if(root==0) { return; }

	for(p=root;p!=0;)
		{
		if(p->Left==0) { printf(" %d ",p->Data); p=p->Right; continue; }

		for(pre=p->Left;pre->Right!=0 && pre->Right!=p;pre=pre->Right) { }

		if(pre->Right==0)
			{ pre->Right=p; p=p->Left; continue; }
		else
			{ pre->Right=0; printf(" %d ",p->Data); p=p->Right; continue; }

		
		}
	}

////////////////////////////////////
int main(void)
{  struct Node *root=0; int i;

	
        Insert(&root,2);  
        Insert(&root,3);
        Insert(&root,1);

	// Recursive InOrder Traversal
	printf("Traversal:"); PrintTree(root); printf("\n");

	// InOrder with Lindstrom Traversal
	printf("Traversal:"); MorrisTraversal(root); printf("\n");
	
        printf(" post order :"); morrisTraversalPreorder(root); 
	DeleteTree(root); return 0;
}


/////////////////////////////////////
int Insert(struct Node **root,int value)// =1 on success, =0 on fail
	{  struct Node *p,*nw;
	if((nw=(struct Node *)malloc(sizeof(struct Node)))==0) { return 0; }

	nw->Data=value; nw->Left=nw->Right=0; nw->mark=0;

	if(*root==0) { (*root)=nw;  return 1; }

	for(p=*root; ; )
		{
		if(value<p->Data)
			{
			if(p->Left==0) { p->Left=nw; return 1; }
			p=p->Left;
			}
		else if(value>p->Data)
			{
			if(p->Right==0) { p->Right=nw; return 1; }
			p=p->Right;
			}
		else // We are trying to insert a value that exists in Strict BST
			{
			printf("Inserting Identical value into tree\n"); 
			free(nw); return 0; 
			}
		}
	}



////////////////////////////////////////
void DeleteTree(struct Node *root)
{
	if(root==0) { return; }
	DeleteTree(root->Left);  DeleteTree(root->Right);
	free(root);	
}


////////////////////////////////////////
void PrintTree(struct Node *root)
{
         // Perform Inorder Traversal of tree
	if(root==0) { return; }
	PrintTree(root->Left);
	printf(" %d ",root->Data);
	PrintTree(root->Right);
}
