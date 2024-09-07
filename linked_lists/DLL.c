// DLL Implementation
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head; //global variable ~ pointer to head node 

struct Node* Get_new_node(int x){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    (*new_node).data = x;
    (*new_node).next = NULL;
    (*new_node).prev = NULL;
    return new_node;
}

void Insert_at_head(int x){
    struct Node* temp = Get_new_node(x);
    if (head == NULL){
        head = temp;
        return;
    }

    (*head).prev = temp;
    (*temp).next = head;
    head = temp;
}

void Print(){
    struct Node* temp = head;
    printf("Forward order : ");
    while (temp != NULL){
        printf("%d ", (*temp).data);
        temp = (*temp).next;
    }
    printf("\n");
}


int main(){
    return 0;
}