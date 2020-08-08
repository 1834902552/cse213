include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;

void insert_after(Node **temp, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node* last = *temp;

    new_node->data = data;
    new_node->next = NULL;

    if (*temp == NULL)
    {
        *temp = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void printList(Node * head)
{
    while(head)
    {
        printf("%d ", head->data );
        head = head->next;
    }

    printf("\n");
}
void copylist(Node **copy, Node **temp)
{
    *copy=*temp;
    printf("\n");
}

Node * MergeLists(Node *list1, Node *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    Node *head;
    if (list1->data < list2->data)
    {
        head = list1;
    }
    else
    {
        head = list2;
        list2 = list1;
        list1 = head;
    }

    while(list1->next && list2)
    {
        if (list1->next->data > list2->data)
        {
            Node *tmp = list1->next;
            list1->next = list2;
            list2 = tmp;
        }
        list1 = list1->next;
    }
    if (!list1->next)
        list1->next = list2;
    return head;
}
Node *back_after(Node **temp)
{
    Node *ptr,*ptr1;
    Node *head=*temp;
    if(head == NULL)
    {
        printf("\nlist is empty");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }

    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1->next = NULL;
        free(ptr);
    }
}
int main()
{
    Node * temp1 = NULL;
    Node * temp2 = NULL;
    Node * copy = NULL;
    int carry = 0 ;
    insert_after(&temp1,7);
    insert_after(&temp1,6);
    insert_after(&temp1,4);
    insert_after(&temp1,3);
    insert_after(&temp2,10);
    insert_after(&temp2,8);
    insert_after(&temp2,1);
    printf("\nprint list one: ");
    printList(temp1);
    printf("\nprint list two: ");
    printList(temp2);
    printf("\nMarge two List : ");
    temp1 = MergeLists(temp1,temp2);
    printList(temp1);
    printf("\nDelete After : ");
    back_after(&temp1);
    printList(temp1);
    printf("\nCopy list : ");
    copylist(&copy,&temp1);
    printList(copy);
    printf("\nClear List -\n");
    temp1=NULL;
    return 0;
}
