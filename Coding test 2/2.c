#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int value;
    struct node *next;
} Node;
void menu();
Node* create_list();
Node* insert_before(Node *temp, int key, int value);
Node* delete_front(Node *temp);
Node* copy_list_recursive(Node *copy);
int front(Node *temp);
Node* print_reverse(Node *list);
void print_list(Node *temp);
int main()
{
    menu();
    return 0;
}
void menu()
{
    Node *head = NULL;
    Node *list = NULL;
    head = create_list();
    int value, option;
    do
    {
        system("cls");
        printf("1. Insert Before\n");
        printf("2. Delete Before\n");
        printf("3. Copy Recursively\n");
        printf("4. Front\n");
        printf("5. Reverse\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your Option : ");
        scanf("%d", &option);
        if(option == 1)
        {
            int key;
            Node *head = NULL;
            head = create_list();
            print_list(head);
            scanf("%d",&key);
            head = insert_before(head, key, 100);
            print_list(head);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 2)
        {
            printf("Display List: ");
            print_list(head);
            head = delete_front(head);
            printf("After Front Delete from List 1: ");
            print_list(head);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if (option == 3)
        {
            printf("Display List 1: ");
            print_list(head);
            list = copy_list_recursive(head);
            printf("After Copy Recursively from List 1: ");
            print_list(list);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 4)
        {
            printf("%d\n", front(head));
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 5)
        {
            printf("Display List: ");
            print_list(head);
            head = print_reverse(head);
            printf("Display List 1 in Reverse: ");
            print_list(head);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 6)
        {
            printf("Display List: ");
            print_list(head);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if (option == 7)
        {
            exit(0);
        }
        else
        {
            printf("\nInvalid Option, Please Option Between '1 to 7'");
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
    }
    while(option != 7);
}
Node* create_list()
{
    Node *a, *b, *c, *d;
    a = (Node *) malloc(sizeof(Node));
    b = (Node *) malloc(sizeof(Node));
    c = (Node *) malloc(sizeof(Node));
    d = (Node *) malloc(sizeof(Node));
    a->value = 1;
    a->next = b;
    b->value = 2;
    b->next = c;
    c->value = 3;
    c->next = d;
    d->value = 4;
    d->next = NULL;
    return a;
}
int front(Node *temp){
    if(temp!=NULL){
        return temp->value;
    }
}
Node* delete_front(Node *temp)
{
    if(temp)
    {
        Node *new_head = NULL;
        new_head = temp->next;
        free(temp);
        return new_head;
    }
    else
        printf("Underflow Linked List");
    return temp;
}
Node* copy_list_recursive(Node *copy)
{
    if(copy == NULL)
        return NULL;
    Node temp = (Node) malloc(sizeof (Node));
    temp->value = copy->value;
    temp->next = copy_list_recursive(copy->next) ;
    return temp;
}
Node* insert_before(Node *temp, int key, int value)
{
    Node *prev, *head = temp;
    int i = 0;
    int j = 0;
    while(temp)
    {
        if(temp->value == key)
        {
            if(temp == head)
            {
                Node new_node = (Node) malloc(sizeof(Node*)) ;
                new_node->value = value;
                new_node->next = temp;
                i++;
                return new_node;
            }
            else
            {
                Node new_node = (Node) malloc(sizeof(Node*));
                new_node->value = value;
                new_node->next = temp;
                prev->next = new_node;
                j++;
                return head;
            }
        }
        prev = temp;
        temp = temp->next;
    }
    if(i<1 || i>4 || j<1 || j>4)
    {
        printf("Index out of range\n");
        printf("Element Not Found\n");
    }
    return head;
}
Node* print_reverse(Node *list)
{
    Node *first, *current, *temp;
    first = list;
    current = list->next;
    first->next = NULL;
    while(current)
    {
        temp = current->next;
        current->next = first;
        first = current;
        current = temp;
    }
    return first;
}
void print_list(Node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("\n");
}
