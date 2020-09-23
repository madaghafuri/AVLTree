#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int height(struct node *r){
    if (r == NULL)
        return 0;

    return height;    
}

int max(int a, int b){
    return ((a > b) ? a : b);
}

int getbalance(struct node *r){
    if(r == NULL){
        return 0;
    }
    return height(r->left) - height(r->right);
}

struct node* leftrotate(struct node *r){
    struct node *a = r->right;
    struct node *y = a->left;

    a->left = r;
    r->right = y;

    a->height = 1 + max(height(a->left), height(a->right));
    r->height = 1 + max(height(a->left), height(a->right));

    return a; 
}

struct node* rightrotate(struct node *r){
    struct node *a = r->left;
    struct node *y = a->right;

    a->right = r;
    r->left = y;

    a->height = 1 + max(height(a->left), height(a->right));
    r->height = 1 + max(height(a->left), height(a->right));

    return a; 
}

struct node* new_node(int val){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;

    return temp;
}


struct node* insert(struct node *r , int val()){

    if(r == NULL) return new_node(val);

    if(val < r->data)
    r->left = insert(r->left, val);

    else if(val > r->data)
    r->right = insert(r->right, val);

    else
    {
        return r;
    }

    r->height = 1 + max(height(r->left), height(r->right));
    
    int balance = getbalance(r);
    
    //left - left
    if(balance > 1 && val < r->left->data){
        return rightrotate(r);
    }
    //left - right
    if(balance > 1 && val > r->left->data){
        r->left = leftrotate(r->left);
        return rightrotate(r);
    }
    //right - right
    if(balance < -1 && val > r->right->data){
        return leftrotate(r);
    }
    //right - left
    if(balance < -1 && val < r->right->data){
        r->right = rightrotate(r->right);
        return leftrotate(r);
    }
    return r;
}

void preorder(struct node *r){
    if(r == NULL){
        return;
    }
    printf("%d", r->data);
    preorder(r->left);
    preorder(r->right);
}

void searchNode(struct node *r, int value){
    if(r == NULL) return;
    searchNode(r -> left, value);
    if(r -> data == value){
        printf("Found it!\n");
        return;
    }
    searchNode( r -> right, value);
}

int main(){
    
    struct node *root = NULL;
    int inputNumber;


    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);
    
    printf("Preorder traversal of the AVL TREE is: \n");
    preorder(root);
    printf("\n\n");

    printf("Insert value to be searched: ");

    scanf("%d", &inputNumber);
    getchar();

    searchNode( root, inputNumber);
    getchar();

    return 0;
}
