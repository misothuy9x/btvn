#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}Node;
Node* push(Node* head, int new_data){
	Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = head;
    new_node->prev = NULL;
    if (head != NULL)
        head->prev = new_node;
    head = new_node;
}
void Remove(struct Node** head_ref, struct Node* del){
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)
        *head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
}
void RemoveNode(struct Node** head_ref, int n){
    int i;
    if (*head_ref == NULL || n <= 0)
        return;
    struct Node* current = *head_ref;
    for (i = 1; current != NULL && i < n; i++)
        current = current->next;
    if (current == NULL)
        return;
    Remove(head_ref, current);
}
void printList(struct Node* node){
    Node *i;
    for(i=node; i!= NULL; i=i->next){
        printf("%d ",i->data);
    }  
    printf("\n");
}
int main(){
	struct Node* head = NULL,*i;
    int n,data,key,j=1;
    printf("Nhap day so: ");
    scanf("%d",&n);
    while(n-->0){
        scanf("%d",&data);
        head=push(head, data);
    }
    printList(head);
    printf("So can xoa:\n");
	scanf("%d",&key);
    for(i=head; i!= NULL; i=i->next){
        if (i->data==key){
            break;
        }
        j++;
    }
    RemoveNode(&head,j);
	printList(head);
	return 0;
}