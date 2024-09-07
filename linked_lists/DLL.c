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

void Insert_at_tail(int x){
    struct Node* temp = Get_new_node(x);
    if (head == NULL){
        head = temp;
        return;
    }
    struct Node* temp1 = head;
    while ((*temp1).next != NULL){
        temp1 = (*temp1).next;
    }
    (*temp1).next = temp;
    (*temp).prev = temp1;
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

void ReversePrint(){
    struct Node* temp = head;
    if (temp == NULL) return;
    //reach the last node
    while ((*temp).next != NULL){
        temp = (*temp).next;
    }
    //print the node data in reverse order
    printf("Reverse order :");
    while (temp != NULL){
        printf("%d ",(*temp).data);
        temp = (*temp).prev;
    }
    printf("\n");
}

int main(){
    head = NULL; //empty list
    Insert_at_tail(2); Print(); ReversePrint();
    Insert_at_tail(3); Print(); ReversePrint();
    Insert_at_tail(4); Print(); ReversePrint();
    Insert_at_tail(5); Print(); ReversePrint();

    return 0;
}