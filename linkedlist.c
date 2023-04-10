#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
    // struct node *prev;
    // struct node *next;
};

struct node * head;
struct node * Create(){
    struct node * end;
    struct node * point;
    point = (struct node*)malloc(sizeof(struct node));
    point->val=1;
    head=NULL;
    end=point;

    while(point->val!=10){
        //printf("\n+%d+",point->val);
        if(head==NULL){
            head=point;
        }else{
            end->next=point;
        }

        end=point;
        point=(struct node*)malloc(sizeof(struct node));
        point->val=(end->val)+1;
    }
    end->next=NULL;
    return head;
};

void showList(struct node* head){
    printf("\n+++++++++");
    while(head!=NULL){
        printf("%d\n",head->val);
        head=head->next;
    }
}


int main()
{
    printf("Hello World");
    showList(Create());
    return 0;
}
