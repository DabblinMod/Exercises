#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int data;
	struct ListNode *next;
} ListNode;
//we are going to create a new list, using ListNode

//createList(struct LisNode*) is going to be used to create the first node of a list and leave it empty.
void createList(ListNode **list, int value){
	if(*list==NULL){
		ListNode *newNode=malloc(sizeof(ListNode));
		if(newNode==NULL){//when this thing is broken and no neewNode is made
			printf("Error, new node was not created.\n");
			exit(1);
		}
		newNode->data=value;
		newNode->next=NULL;
		*list=newNode;
	}else{
		return;//exit the function and move things on
	}
}

void addNode(ListNode **list, int value){
	ListNode *ptr=NULL;//without NULL it is a wild pointer / wild leak
	//to loop through the list
	if(*list==NULL){ //if the list is empty
		ListNode *newNode=malloc(sizeof(ListNode));
		if(newNode==NULL){//when this thing is broken and no newNode is made
			printf("Error, new node was not created.\n");
			exit(2);
		}
		newNode->data=value;
		newNode->next=NULL;
		*list=newNode;
	}
	else{//add a newNode to the list when not empty
		ptr=*list;
		ListNode *newNode=malloc(sizeof(ListNode));//make newNode
		if(newNode==NULL){
			printf("Error, something is wrong since no node was created\n");
			exit(3);
		}
		/*while(ptr!=NULL){//can add nodes to the list without replacing the first node added as head.
			if(ptr->next==NULL){
				newNode->data=value;
				newNode->next=NULL;
				ptr->next=newNode;//add newNode's new values to the list
				break;//exit the loop
			}
			ptr=ptr->next; //move to next node
		}*/
		newNode->data=value;//add new value;
		newNode->next=ptr;//Assign it to the previous node
		*list=newNode;//return the main pointer to the head of the list
	}
}
void printList(ListNode *list){
	ListNode *ptr=list;
	if(list==NULL){
		printf("The List is empty. Nothing can be printed\n");
		//return NULL;
	}
	else{
		printf("List: \n");
		while(ptr != NULL){
			printf("%d ", ptr->data);
			ptr=ptr->next;
		}
		printf("\n"); //add a newline at the end to prevent having it visible
	}
	return;
}
int main(void){
	ListNode *head=NULL;
	ListNode *l1=NULL;
	createList(&head, 1);
	addNode(&head, 3);
	return 0;
}
