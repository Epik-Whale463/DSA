#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

void Reverse(){
    struct Node* current, *prev, *next;
        current = head;
        prev = NULL;

    while (current != NULL){
        next = (*current).next;
        (*current).next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void Insert_at_start(int data){
    struct Node* temp1 = (struct Node*) malloc(sizeof(struct Node*));
    (*temp1).data = data;
    (*temp1).next = NULL;
    (*temp1).next = head;
    head = temp1;
}

void Print()
{
    struct Node* temp = head;
    printf("List is : ");
    while(temp != NULL){
        printf(" %d ",(*temp).data);
        temp = (*temp).next;
    }
    printf("\n");
}

int main(void){
    head = NULL;
    Insert_at_start(2);
    Insert_at_start(4);
    Insert_at_start(6);
    Insert_at_start(5);
    Insert_at_start(19);
    Insert_at_start(39);
    Print();

    Reverse(head);
    Print();

    return 0;
}