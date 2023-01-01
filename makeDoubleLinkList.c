#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int data;
	struct ListNode *next;
	struct ListNode *prev;
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
		newNode->prev=NULL;
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
		newNode->prev=NULL;
		*list=newNode;
	}
	else{//add a newNode to the list when not empty
		ptr=*list;
		ListNode *newNode=malloc(sizeof(ListNode));//make newNode
		if(newNode==NULL){
			printf("Error, something is wrong since no node was created\n");
			exit(3);
			// or could use fprintf(stderr, "Error, no memory allocated\n");
		}
		/*while(ptr!=NULL){//can add nodes to the list without replacing the first node as the header.
			if(ptr->next==NULL){
				newNode->data=value;
				newNode->next=NULL;
				ptr->next=newNode;//add newNode's new values to the list
				newNode->prev=ptr;//have the newly added point back to the last node
				break;//exit the loop
			}
			ptr=ptr->next; //move to next node
		}*/
		newNode->data=value;//add new value;
		newNode->next=ptr;//Assign it to the previous node
		newNode->prev=NULL; //shows the head node has no previous to go back to
		ptr->prev=newNode; //ensures the previous node, points to back to the new head node
		*list=newNode;//return the main pointer to the head of the list
	}
}
void display(ListNode **list){//print list contents
    ListNode *ptr; //moves through list
    if(*list==NULL){
        printf("Error in list. Is empty\n");
        exit(4);
    }
    else{
        ptr=*list;
        printf("List: \n");
        while(ptr!=NULL){
            printf("%d ", ptr->data);
            if(ptr->next==NULL){
                break;
            }
            ptr=ptr->next;//move to the next node
        }
        /*while(ptr!=NULL){
            printf("List: \n");
            printf("%d ", ptr->data);
            ptr=ptr-prev;
        }*/
    }


}

void displayReverse(ListNode **list){
       ListNode *ptr; //moves through list
    if(*list==NULL){
        printf("Error in list. Is empty\n");
        exit(4);
    }
    else{
        ptr=*list;
        while(ptr->next != NULL){//move pointer to the last node
            ptr=ptr->next;
        }
        //then reverse the printing process using prev
        printf("\nList: \n");
        while(ptr!=NULL){
            printf("%d ", ptr->data);
            ptr=ptr->prev;
        }
    }
}

void freeList(ListNode **list){
    ListNode *ptr;
    if(*list==NULL){
        printf("ERROR\n");
        exit(4);
    }


}

int main(void){
	ListNode *head=NULL;
	ListNode *l1=NULL;
	createList(&head, 1);
	addNode(&head, 5);
	addNode(&head, 2);
	addNode(&head, 3);
	addNode(&head, 4);
	display(&head);
	displayReverse(&head);
	return 0;
}
