#include <stdio.h>
#include <stdlib.h>
 
// A linked list node
struct Node {
    int data;
    struct Node* next;
};
 

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
 

void deleteNode(struct Node** head_ref, int key)
{
    // Store head node
    struct Node *temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp); // Free memory
}
 
// This function prints contents of linked list starting
// from the given node
void printList(struct Node* node)
{
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}
 
// Driver code
int main(int argc, char const *argv[])
{

    // /* Start with the empty list */
    // struct Node* head = NULL;
 
    // push(&head, 7);
    // push(&head, 1);
    // push(&head, 3);
    // push(&head, 2);
 
    // puts("Created Linked List: ");
    // printList(head);
    // deleteNode(&head, 2);
    // puts("\nLinked List after Deletion of 1: ");
    // printList(head);
    // return 0;
    struct Node* head = NULL,*i;
    int n,data,arr[100],k=0;
    printf("Nhap n= ");
    scanf("%d",&n);
    while(n-->0){
        scanf("%d",&data);
        push(&head,data);
    }
    for(i=head; i!= NULL; i=i->next){
        if (i->data%2==0){
            arr[k]=i->data;
            k++;
        }
    }
    int j;
    for(j=0; j<k;j++){
        deleteNode(&head,arr[j]);
        }
    printf("Linked List after Deletion:\n");
    printList(head);
    return 0;
}