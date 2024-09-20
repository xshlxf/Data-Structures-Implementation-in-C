/******************************************************************************
arboles
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
void insert(TreeNode *node, TreeNode *new, int type);
int readFromKeyboard();
int getHeight(TreeNode *parent);
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
        }
        else{
            insert(root, new, type);
        }
    }while (ans ==1);
    
    return 0;
}

void insert (TreeNode *parent, TreeNode *new, int type){
    if (type == 0){
        parent -> left = new;
        printf("\n %d inserted at left of %d \n", new -> item, parent -> item);
    }
    else if(type == 1){
        parent -> right = new ;
        printf("\n %d insertes at right of %d \n", new -> item, parent -> item);
    }
}

int readFromKeyboard(){
    printf("\n insert to left (0) insert right (1)");
    scanf("%d", &type);
    
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
        return new;
    }
}
