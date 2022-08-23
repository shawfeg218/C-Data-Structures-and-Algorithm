#include <stdio.h>
#include <stdlib.h>

typedef struct node * treePointer;
struct node {
    int data;
    treePointer leftChild, rightChild;
};
treePointer modifiedSearch(treePointer tree, int key);
void insert(treePointer * node, int key);
void deleteRightMax(treePointer * ptr);
void inorder(treePointer * ptr);
int main(void){
    treePointer root=NULL;
    int a[8];
    for(int i=0; i<8; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<8; i++){
        insert(&root,a[i]);
    }
    inorder(&root);
    printf("\n");
    deleteRightMax(&root);
    inorder(&root);

    return 0;
}

treePointer modifiedSearch(treePointer tree, int key){
    treePointer current, temp;
    if(!tree){
        return NULL;
    }else{
        current=tree;
    }

    if(key==current->data){
        return NULL;
    }
    if(key<current->data){
        temp=current->leftChild;
    }else{
        temp=current->rightChild;
    }

    while(temp){
        current = temp;
        if(key==current->data){
            return NULL;
        }
        if(key<current->data){
            temp=current->leftChild;
        }else{
            temp=current->rightChild;
        }
    }
    return current;
}
void insert(treePointer * node, int key){
    treePointer ptr;
    treePointer temp = modifiedSearch(*node,key);
    if(temp){
        ptr=(treePointer) malloc (sizeof (node));
        ptr->data = key;
        ptr->leftChild=ptr->rightChild=NULL;
        if(key<temp->data){
            temp->leftChild = ptr;
        }else{
            temp->rightChild = ptr;
        }
    }else{//temp=NULL
        if(!(*node)){
            ptr=(treePointer) malloc (sizeof (node));
            ptr->data = key;
            ptr->leftChild=ptr->rightChild = NULL;
            *node = ptr;
        }
    }
}

void deleteRightMax(treePointer * ptr){
    treePointer temp=*ptr;
    treePointer pre;
    if(temp->rightChild==NULL){
        printf("The node has no right subtree");
        return;
    }else{
        pre=temp;
        temp=temp->rightChild;
        while(temp->rightChild!=NULL){
            pre=temp;
            temp=temp->rightChild;
        }

        if(temp->rightChild==NULL && temp->leftChild==NULL){
            pre->rightChild=NULL;
        }
        if(temp->rightChild==NULL && temp->leftChild!=NULL){
            pre->rightChild=temp->leftChild;
        }

        free(temp);

    }

    return;
}

void inorder(treePointer * ptr){
    if(*ptr){
        inorder(&(*ptr)->leftChild);
        printf("%d ",(*ptr)->data);
        inorder(&(*ptr)->rightChild);
    }
}
