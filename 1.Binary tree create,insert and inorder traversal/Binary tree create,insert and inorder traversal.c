#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* left;
    struct node* right;
};

struct node* createNode(int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->value=value;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
};

struct node* insert(struct node*root,int value){
    if(root==NULL){
        return createNode(value);
    }

    if(value < root->value){
        root->left=insert(root->left,value);
    }else if(value > root->value){
        root->right=insert(root->right,value);
    }

    return root;
};

void inorderTraversal(struct node* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d  ",root->value);
        inorderTraversal(root->right);
    }

}

void freeTree(struct node* root){
    if(root!=NULL){
        free(root->left);
        free(root->right);
        free(root);
    }
}

int main(){
    struct node* root=NULL;

    root=insert(root,50);
    insert(root,30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal :\n");
    inorderTraversal(root);
    printf("\n");

    freeTree(root);

    return 0;
}
