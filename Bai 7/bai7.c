#include<stdio.h>
#include<stdlib.h>
  
// Link list node
struct Node
{
    int data;
    struct Node* next;
};
  
// The function removes duplicates 
// from a sorted list 
void removeDuplicates(struct Node* head)
{
    // Pointer to traverse the linked list 
    struct Node* current = head;
  
    // Pointer to store the next pointer 
    // of a node to be deleted
    struct Node* next_next; 
    
    // Do nothing if the list is empty 
    if (current == NULL) 
       return; 
  
    // Traverse the list till last node 
    while (current->next != NULL) 
    {
       // Compare current node with next node 
       if (current->data == current->next->data) 
       {
           // The sequence of steps is important
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;  
       }
  
       // This is tricky: only advance 
       // if no deletion
       else 
       {
          current = current->next; 
       }
    }
}
  
// UTILITY FUNCTIONS 
// Function to insert a node at the
// beginning of the linked list 
void push(struct Node** head_ref, 
          int new_data)
{
    // Allocate node 
    struct Node* new_node =
           (struct Node*) malloc(sizeof(struct Node));
              
    // Put in the data  
    new_node->data  = new_data;
                  
    // Link the old list off the new node 
    new_node->next = (*head_ref);     
          
    // Move the head to point to the 
    // new node 
    (*head_ref) = new_node;
}
  
// Function to print nodes in a given 
// linked list 
void printList(struct Node *node)
{
    while (node!=NULL)
    {
       printf("%d ", node->data);
       node = node->next;
    }
} 
  
// Driver code
int main()
{
    // Start with the empty list 
    struct Node* head = NULL;
    
   
    push(&head, 2);
    push(&head, 2);
    push(&head, 3);  
    push(&head, 3);
    push(&head, 3);
    push(&head, 5);
    push(&head, 5);
    push(&head, 5);
    push(&head, 5);     
    push(&head, 6);
    push(&head, 7);                                 
  
    printf(
    "Linked list before duplicate removal  ");
    printList(head); 
  
    // Remove duplicates from linked list 
    removeDuplicates(head); 
  
    printf(
    "Linked list after duplicate removal ");         
    printList(head);            
    
    return 0;
}