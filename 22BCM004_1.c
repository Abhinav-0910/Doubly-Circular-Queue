#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* next;
};

struct Queue{
    struct Node* f;
    struct Node* r;
};

void Queue(struct Queue* head){
    head->f=NULL;
    head->r=NULL;
}

void push(struct Queue*head, int data){

    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=data;
    newNode->next=NULL;

    if (is_empty(head)){
        head->f=newNode;
        head->r=newNode;
        newNode->next=newNode;
    }
    else{
        head->r->next=newNode;
        newNode->next=head->f;
        head->r=newNode;
    }
}

int Pop(struct Queue* head){

    if (is_empty(head))
        printf("-1\n");
    int value;
    struct Node* temp = head->f;
    if (head->f==head->r){
        head->f=head->r=NULL;
    }
    else{
        head->f=head->f->next;
        head->r->next=head->f;
    }
    value=temp->val;
    printf("Popped element is : %d\n", value);
    free(temp);
    return value;
}

int popRear(struct Queue* head){
    if (is_empty(head)){
        printf("%-1\n");
        return;
        }

    int value;
    struct Node* temp=head->f;
    struct Node* prev=NULL;

    while (temp->next!=head->f){
        prev=temp;
        temp=temp->next;
    }

    if (temp==head->f){
        head->f=head->r=NULL;
    }
    else{
        prev->next=head->f;
        head->r=prev;
    }

    value=temp->val;
    free(temp);
    printf("Popped element from rear is : %d\n", value);
}

int is_empty(struct Queue* head){
    return head->f==NULL;
}

void removeKElements(struct Queue* head, int m){
    for (int j=0;j<m;j++){
        if (is_empty(head)){
            printf("Queue is empty\n");
            break;
        }
        else
            Pop(head);
    }
    printf("Elements successfully deleted.\n");

    return;
}

void Print(struct Queue* head){
    if (is_empty(head))
        printf("-1\n");
    struct Node* curr=head->f;
    do{
        printf("%d ", curr->val);
        curr=curr->next;
    }
    while (curr!=head->f);
        printf("\n");
}

void RevR(struct Node* front, struct Node* rear){
    if (front==rear){
        printf("%d ", front->val);
        return;
    }
    RevR(front->next, rear);
    printf("%d ",front->val);
}

void PrintReverse(struct Queue* head){
    if (is_empty(head))
        return -1;
    RevR(head->f, head->r);
    printf("\n");
}

void Inject(struct Queue*head, int data){

    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=data;
    newNode->next=NULL;

    if (is_empty(head)){
        head->f=newNode;
        head->r=newNode;
        newNode->next=newNode;
    }
    else{
        newNode->next=head->f;
        head->f=newNode;
        head->r->next=newNode;
    }
}

int findElem(struct Queue* head, int index){
    if (is_empty(head)){
        printf("%-1\n");
        return 0;
        }
    struct Node* temp=head->f;
    int count=1;

    while (count<index){
        temp=temp->next;
        count++;
        if (temp==head->f){
            printf("-1\n");
            return 0;
        }
    }
    printf("value at %d index is : %d\n", index,temp->val);
    return temp->val;
}

int main(){
    int t, num, n;
    struct Queue head;
    Queue(&head);
    printf("Enter how many operation you want to do: \n");
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Enter the operation number to be performed.\n");
        printf("------------------------------------------------------------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Inject\n");
        printf("4. popRear\n");
        printf("5. Print\n");
        printf("6. PrintReverse\n");
        printf("7. findElement\n");
        printf("8. removeKElements\n\n");
         printf("------------------------------------------------------------");
        printf("\nEnter operation number : ");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter the value to be pushed at end : ");
                scanf("%d",&num);
                push(&head, num);
                break;
            case 2:
                Pop(&head);
                break;
            case 3:
                printf("Enter the value to be pushed at front: ");
                scanf("%d",&num);
                Inject(&head, num);
                break;
            case 4:
                popRear(&head);
                break;
            case 5:
                Print(&head);
                break;
            case 6:
                PrintReverse(&head);
                break;
            case 7:
                printf("Enter the position to be searched : ");
                scanf("%d",&num);
                findElem(&head, num);
                break;
            case 8:
                printf("Number of front values to be removed : ");
                scanf("%d",&num);
                removeKElements(&head, num);
                break;
            default:
                printf("Invalid Option !!");
                break;
        }
    }
    return 0;
}
