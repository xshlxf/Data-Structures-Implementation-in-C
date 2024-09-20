/******************************************************************************
arboles con implementación de AVL
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node{
    int item;
    struct tree_node* left;
    struct tree_node* right;
    int height;
}TreeNode;

TreeNode *newNode (int data);
void insert(TreeNode *node, TreeNode *new);
int readFromKeyboard();
int getHeight(TreeNode *parent);
int inorder(TreeNode *parent, getHeight);
int type;

int main()
{
    TreeNode *root = NULL;
    TreeNode *new = NULL;
    int ans;
    do{
        printf("\n Press'1' to add a new int to the tree and any other Key to quit\n");
        scanf("%d", &ans);
        if (ans == 1){
            new = newNode(readFromKeyboard());
            if (root == NULL)
                root = new;
                root -> height += 1;
        }
        else{
            insert(root, new);
        }
    }while (ans ==1);
    
    return 0;
}

void insert (TreeNode *parent, TreeNode *new){
    int lh = getHeight(parent->left);
    int rh = getHeight(parent->right);
    if (lh == 0){
        parent -> left = new;
        printf("\n %d inserted at left of %d \n", new -> item, parent -> item);
    }
    else if(rh == 0){
        parent -> right = new ;
        printf("\n %d insertes at right of %d \n", new -> item, parent -> item);
    }
    
    else if(rh < lh)
        insert (parent -> right, new);
    else
        insert(parent -> left, new);
    parent -> height += 1;
}

int readFromKeyboard(){
    printf("\n enter int\n");
    int data;
    scanf("%d", &data);
    return data;
}

TreeNode *newNode(int data){
    TreeNode *new = (TreeNode *) malloc (sizeof(TreeNode));
    if (new == NULL){
        return NULL;
    } 
    else{
        new -> item = data;
        new -> left = NULL;
        new -> right = NULL;
        new -> height = 0;
        return new;
    }
}
int getHeight(TreeNode *parent){
    if(parent == NULL)
        return 0;
    int lbh = getHeight(parent -> left);
    int rbh = getHeight(parent -> right);
    
    if (lbh > rbh)
         return 1+lbh;
    else
        return 1+rbh;
}

int inorder(TreeNode *parent, getHeight){
    
}


