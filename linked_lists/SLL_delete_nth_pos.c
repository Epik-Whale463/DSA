// Delete node at nth position
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head;

void Insert_at_n(int data, int n){
    struct Node* temp1 = (struct Node*) malloc(sizeof(struct Node*));
    (*temp1).data = data;
    (*temp1).next = NULL;

    if (n ==1){
        (*temp1).next = head;
        head = temp1;
        return; 
    }

    struct Node* temp2 = head;
    for (int i=0; i < n-2; i++){
        temp2 = (*temp2).next;
    }

    (*temp1).next = (*temp2).next;
    (*temp2).next = temp1;


}
void Insert_at_start(int data){
    struct Node* temp1 = (struct Node*) malloc(sizeof(struct Node*));
    (*temp1).data = data;
    (*temp1).next = NULL;
    (*temp1).next = head;
    head = temp1;
}
void Delete(int n){
    struct Node* temp1 = head;
    if (n ==1){
        head = (*temp1).next;
        free(temp1);
        return;
    }

    for (int i=0; i < n-2; i++){
        temp1 = (*temp1).next;
    }
    struct Node* temp2 = (*temp1).next;
    (*temp1).next = (*temp2).next;
    free(temp2);
}

void Delete_with_val(int data){
    struct Node* temp1 = head;
    if ((*temp1).data == data){
        head = (*temp1).next;
        free(temp1);
        return;
    }
       while((temp1->next != NULL) && (temp1->next->data != data)){
        temp1 = (*temp1).next;
    }

    if (temp1->next == NULL){
        printf("Data element not found the in the linked list\n");
        return;
    }

    struct Node* temp2 = (*temp1).next;
    (*temp1).next = (*temp2).next;
    free(temp2);

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
    Print();

    int pos;
    int val;
    //printf("Enter a position to delete : ");
    //scanf("%d",&pos);
    printf("Enter the value to delete : ");
    scanf("%d",&val);
    Delete_with_val(val);
    Print();
    return 0;
}