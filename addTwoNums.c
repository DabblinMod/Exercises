#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * This is tagged, ListNode would be the tag of this struct
 */
 
 //If we made a typedef struct, it would make the ListNode name a data type of struct, not the tag of the struct
 /*Ex
 typedef struct tag{
		int val;
		struct tag *next;
 } type_name;
 
 so type_name replaces struct tag but it is NOT the tag for the struct
 */

struct ListNode{
    int val;
    struct ListNode *next;
};

//Utilize this Listnode to return a list that has the addition of two numbers from the args of two other lists.
//Any two nunmbers whose sum is greater than or equal to 10 will take the number difference of that number and add 1 to the next sum of two numbers.
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ptr1=l1, *ptr2=l2, *newList=NULL, *ptr3;
    /*Ptr1 and ptr2 are going to be used to loop through list1 (l1) & list2 (l2)
    ptr3 is going to be used to loop through newList*/
    if(l1==NULL && l2==NULL){//checks if either the list Structs are empty 
        return NULL;
    }
    while(ptr1 != NULL && ptr2 != NULL){
        if(newList==NULL){
            newList=malloc(sizeof(struct ListNode));
            newList->val=ptr1->val + ptr2->val;//2+5, 
            newList->next=NULL;
        }
        ptr3=newList;
        while(ptr3 != NULL){
            if(ptr3->val!=ptr1->val + ptr2->val){
                //check if the value exists in the list if it doesn't, make a new one
                ptr3->next=malloc(sizeof(struct ListNode));
                ptr3=ptr3->next;
                ptr3->val=ptr1->val + ptr2->val;
                ptr3->next=NULL;
            }
            else{
                ptr3=ptr3->next;
            }
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    //done making the new list
    ptr3=newList;//reassign pointer 3
    while(ptr3 !=NULL){
        if(ptr3->val >= 10){
            ptr3->val=ptr3->val - 10;
            ptr3->next->val+=1;
        }
        ptr3=ptr3->next;
    }
    return newList;
}

struct ListNode* createList(struct ListNode *list, int num){
    struct ListNode* itr=list;//iterate through list
    if(list==NULL){//list is empty, so add memory to create a value
        list=malloc(sizeof(struct ListNode));
        list->val=num;
        list->next=NULL;//assign the next node empty so it can be used to create a new one

    }//now you have something in the list, use else statement for when list is NOT empty
    else{
        while(itr != NULL){//loops through the list
            if(itr->next==NULL){
                itr->next=malloc(sizeof(struct ListNode));//when the next node is empty make a new node
                itr=itr->next;//move to the new node
                itr->val=num;//the next one's value should change
                itr->next=NULL;//assign null to the new node one's next
            }
            itr=itr->next; //moves to the next head
        }
    }
    return list; //returns the list of ndoes
}

void printList(struct ListNode *list){
    struct ListNode *ptr=list;
    if(list==NULL){
        printf("The List is empty. Nothing can be printed\n");
        return NULL;
    }
    else{
        printf("List: \n");
        while(ptr != NULL){
            printf("%d ", ptr->data);
            // if(ptr->next != NULL){
            //     printf("%d ", ptr->val);
            // } this prevents the last value from being printed since the next-> NULL; next points to NULL
            ptr=ptr->next;
        }
        printf("\n"); //add a newline at the end to prevent having it visible
    }
    return;
}

int main(void){
    struct ListNode *list1=NULL;
    struct ListNode *list2=NULL;    
    int arr1[]={1, 2, 3, 4, 5};
    int arr2[]= {2, 4, 5, 6, 7};
    int i;
    //we create a list struct
    for(i=0; i < 5; i++){
        printf("index: %d\n", arr1[i]);
        list1=createList(list1, arr1[i]);
    }
    for(i=0; i < 5; i++){
        list2=createList(list2, arr2[i]);
    }
    printList(list1);
    printList(list2);
    
    return 0;
}