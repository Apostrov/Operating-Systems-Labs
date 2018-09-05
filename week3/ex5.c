#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct Node Node;

struct Node
{
    Node *next;
    Node *past; //ex5 (optional)
    int data;
};

void print_list(Node *head)
{
    Node *current = head;
    do
    {
        printf("%d", current->data);
        current = current->next;
    } while(current != head);
    printf("\n");
}

void insert_list(Node *head, int data, int index)
{
    Node *current = head;
    if(head->next == head && index != 0)
    {
        perror("List out of range!");
        return;
    }
    for(int i = 0; i < index; i++)
    {
        current = current->next;
        if(current == head && head->next != head)
        {
            perror("List out of range!");
            return;
        }
    }
    Node *new = malloc(sizeof(Node));
    new->next = current->next;
    new->past = current->past;
    new->data = data;
    
    current->next = new;
}

void delete_node(Node *head, int index)
{
    Node *past = head;
    if(head->next == head && index != 0)
    {
        perror("List out of range!");
        return;
    }
    for(int i = 0; i < index - 1; i++)
    {
        past = past->next;
        if(past == head && head->next != head)
        {
            perror("List out of range!");
            return;
        }
    }
    Node *current = past->next;
    past->next = current->next;
    current->next->past = past;
    free(current);
}


int main()
{
    Node *head = malloc(sizeof(Node));
    head->next = head;
    head->past = head;
    head->data = -1;
    print_list(head);

    insert_list(head, 1, 0);
    insert_list(head, 2, 1);
    insert_list(head, 3, 2);
    insert_list(head, 4, 3);
    print_list(head);

    delete_node(head, 2);
    print_list(head);
    return 0;
}
