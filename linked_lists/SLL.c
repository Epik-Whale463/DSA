#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head; //global variable representing head node
void Insert(int x)
{
    struct Node* temp  = (struct Node*) malloc(sizeof(struct Node));
    (*temp).data = x;
    (*temp).next = head;
    head = temp;
}

void Print(){
    struct Node* temp = head;
    printf("Linked List is \n");
    while (temp != NULL)
    {
        printf(" %d ", (*temp).data);
        temp = (*temp).next;
    }
    printf("\n");
}

int main(void){

    head = NULL; // Initially head is pointing to NULL , ie , size of LL is zero
    int i,n,x;
    printf("How many numbers to insert?");
    scanf("%d",&n);

    for (i=0; i<n; i++){
        printf("Enter the number : ");
        scanf("%d",&x);

        Insert(x);
        Print();
    }

    return 0;
}