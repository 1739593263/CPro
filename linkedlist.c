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

void InsertFirst(int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val=value;
    newNode->next=head;
    head=newNode;
}

struct node* deleteFirst(){
    struct node *deletedNode = (struct node*)malloc(sizeof(struct node));
    deletedNode=head;
    head=head->next;
    return head;
};

struct node* find(int key){
    struct node* current = (struct node*)malloc(sizeof(struct node));
    current=head;
    for(int i=0; i<key; i++){
        current=current->next;
    }
    return current;
};

struct node* delete(int key){
    struct node* current = (struct node*)malloc(sizeof(struct node));
    struct node* previous = (struct node*)malloc(sizeof(struct node));
    current=head;
    if(key==0){
        deleteFirst();
        return current;
    }
    if(head == NULL) {
      return NULL;
    }
    for(int i=0; i<key; i++){
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
    return current;
};

void showList(struct node* head){
    printf("\n+++++++++");
    while(head!=NULL){
        printf("%d||",head->val);
        head=head->next;
    }
    printf("\n");
}
int length() {
   int length = 0;
   struct node *current;

   for(current = head; current != NULL; current = current->next) {
      length++;
   }

   return length;
}
void sort() {

   int i, j, k, tempData;
   struct node *current;
   struct node *next;

   int size = length();
   k = size ;
    // get the largest and the lowest in each round.
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;

      for ( j = 1 ; j < k ; j++ ) {

         if ( current->val > next->val ) {
            tempData = current->val;
            current->val = next->val;
            next->val = tempData;
         }

         current = current->next;
         next = next->next;
      }
   }
}


int main()
{
    printf("Hello World");
    showList(Create());
    int a;
    scanf("%d", &a);
    struct node* nn = delete(a);
    printf("deleted %d",nn->val);
    showList(head);

    scanf("%d", &a);
    struct node* aa = find(a);
    printf("find %d",aa->val);
    showList(head);
    return 0;
}
