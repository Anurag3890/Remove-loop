#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void remove_loop(struct Node* head){
    struct Node *slow=head,*fast=head;
    int loop=0;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){loop=1;break;}
    }
    if(!loop)return;
    slow=head;
    if(slow==fast){ // loop starts at head
        while(fast->next!=slow)fast=fast->next;
    } else {
        while(slow->next!=fast->next){slow=slow->next; fast=fast->next;}
    }
    fast->next=NULL;
}

void print_list(struct Node* head){
    while(head){printf("%d ",head->data); head=head->next;}
    printf("\n");
}

int main(){
    struct Node *head=malloc(sizeof(struct Node));
    struct Node *second=malloc(sizeof(struct Node));
    struct Node *third=malloc(sizeof(struct Node));
    head->data=10; head->next=second;
    second->data=20; second->next=third;
    third->data=30; third->next=second; // loop
    remove_loop(head);
    print_list(head);
    return 0;
}
