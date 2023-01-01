#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
}ListNode;
void addToList(ListNode **list, int value){
  ListNode *newNode=NULL;
  if(*list== NULL){
        newNode =  malloc(sizeof(ListNode));
        if(newNode == NULL){
            printf("ERROR\n");
            exit(1);
        }
        newNode->data = value;
        newNode->next = NULL;
            *list = newNode;
    }
    else{
        newNode= malloc(sizeof(ListNode));
        if(newNode == NULL){
            printf("ERROR\n");
            exit(1);
        }
        newNode->data = value; //sets  new values
        newNode->next = *list;//assigns to previous header
        *list = newNode; //sets new header
    }
}

int main() {
  ListNode *newList=NULL;
  addToList(&newList, 1);
  addToList(&newList, 4);
  return 0;
}