#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head;

struct Node* Insert(struct Node* head, int data){
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL) head = temp;
    else {
        struct Node* temp1 = head;
        while (temp1->next != NULL) temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
}

void Print(struct Node* h){
    if (h == NULL) return;
    printf("%d ",(*h).data);
    Print((*h).next);
}

void ReversePrint(struct Node* h){
    if (h == NULL) return;
    ReversePrint((*h).next);
    printf("%d ",h->data);
}

int main(void){
    struct Node* head = NULL; //local head variable

    head = Insert(head,2);
    Print(head);
    printf("\n");
    ReversePrint(head);
    return 0;
}