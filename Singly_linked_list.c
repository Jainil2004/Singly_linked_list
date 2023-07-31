#include <stdio.h>
#include <stdlib.h>

/*
GOAL OF THIS CODE:
Create a fully functional singly linked list.
1. there should be a function that adds a new node in the start of the list. 
2. there should be a function thats adds a new node in the end of the list.
3. there should be a function thats adds a new node in the middle of the list where ever the user wants the new node to be.
4. there should be a function that prints the whole list.
5. there should be a function that deletes a node from the start of the list.
6. there should be a function that deletes a node from the end of the list.
7. there should be a function that delters a node from the middle of the list whichever node user want to delete.
8. there should be a function that can tell if the particular data is present or not in the linked list.
*/

struct node
{
    int data;
    struct node* next;
};

struct node* list_initializer(int node1_data, int node2_data, int node3_data, int node4_data)
{
    struct node* node1 = (struct node*) malloc(sizeof(struct node));
    struct node* node2 = (struct node*) malloc(sizeof(struct node));
    struct node* node3 = (struct node*) malloc(sizeof(struct node));
    struct node* node4 = (struct node*) malloc(sizeof(struct node));

    node1->data = node1_data;
    node1->next = node2;

    node2->data = node2_data;
    node2->next = node3;

    node3->data = node3_data;
    node3->next = node4;

    node4->data = node4_data;
    node4->next = NULL;

    printf("node initialization successfull!!!\n");
    return node1;
}

struct node* begginning_node_adder(struct node* head, int new_node_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    if (new_node != NULL)
    {
        new_node->data = new_node_data;
        new_node->next = head;
    }
    printf("node addtion successful!!!\n");
    return new_node;
}

struct node* end_node_adder(struct node* head, int new_node_data)
{
    struct node* ptr = head;
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_node_data;
    new_node->next = NULL;

    if (new_node != NULL)
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    printf("node addtion successful!!!\n");
    return head;
}

struct node* middle_node_adder(struct node* head, int new_node_data, int node_finder_data)
{
    struct node* temp;
    struct node* ptr = head;
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_node_data;
    
    if (new_node != NULL)
    {
        while (ptr != NULL && ptr->data != node_finder_data)
        {
            ptr = ptr->next;
        }
        if (ptr != NULL)
        {
            temp = ptr->next;
            ptr->next = new_node;
            new_node->next = temp;
        }
        else
        {
            free(new_node);
            printf("\nNo node with finding data = \'%d\' found!!! ABORTING node addtion...\n\n", node_finder_data);
        }
    }
    printf("node addtion successful!!!\n");
    return head;
}

struct node* begginning_node_deleter(struct node* head)
{
    struct node* ptr = head;

    ptr = head->next;
    head->next = NULL;

    free(head);
    printf("node deletion successful!!!\n");
    return ptr;
}

struct node* end_node_deleter(struct node* head)
{
    struct node* ptr = head;

    while(ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    printf("node deletion successful!!!\n");
    return head;
}

void middle_node_deleter(struct node* head, int node_finder_data)
{
    struct node* ptr = head;

    while (ptr->next->data != node_finder_data)
    {
        ptr = ptr->next;
    }
    struct node* temp = ptr->next;
    ptr->next = ptr->next->next;
    free(temp);
    printf("node deletion successful!!!\n");
}

void list_printer(struct node* head)
{
    struct node* ptr = head;
    printf("HEAD -> ");
    while (ptr != NULL)
    {
        printf("%d -> ", (ptr->data));
        ptr = (ptr->next);
    }
    printf("NULL\n");
}

void node_checker(struct node* head, int node_finder_data)
{
    struct node* ptr = head;
    int node_location = 1;

    while (ptr != NULL)
    {
        if (ptr->data == node_finder_data)
        {
            printf("node with data = \'%d\' found at %dth node location in the list\n", ptr->data, node_location);
            return;
        }
        node_location = node_location + 1;
        ptr = (ptr->next);
    }
    printf("node with data = \'%d\' not found in the list\n", node_finder_data);   
}

int main()
{
    struct node* head;
    int mode = 0;
    int node1_data, node2_data, node3_data, node4_data;
    int new_node_data;
    int node_finder_data;
    printf("this program depicts the use of singly linked list and also features abstraction\n");

    printf("following are the Options avaliable for list manipulation:\n1.Initialize List.\n2.Add node in the beginning.\n3.Add node in the middle.\n4.Add node in the end.\n5.delete node in the beginning.\n6.delete node in the middle.\n7.delete node in the end.\n8.check if a node is present in the list.\n9.Print the Linked list.\n10.Exit \n11.print the operations panel again\n");
    

    while(mode != 10)
    {
    printf("please enter the operation you want to perform\n");
    scanf("%d", &mode);

    switch (mode)
    {
    case 1:
        printf("please enter the node data\n");
        printf("node1 data:\n");
        scanf("%d", &node1_data);
        printf("node2 data:\n");
        scanf("%d", &node2_data);
        printf("node3 data:\n");
        scanf("%d", &node3_data);
        printf("node4 data:\n");
        scanf("%d", &node4_data);

        head = list_initializer(node1_data, node2_data, node3_data, node4_data);
        break;
    case 2:
        printf("please enter the new node data:\n");
        scanf("%d", &new_node_data);
        head = begginning_node_adder(head, new_node_data);
        break;

    case 3:
        printf("please enter the new node data:\n");
        scanf("%d", &new_node_data);
        printf("please enter the data of the node after which you would like to add the new node:\n");
        scanf("%d", &node_finder_data);

        middle_node_adder(head, new_node_data, node_finder_data);
        break;

    case 4:
        printf("please enter the new node data:\n");
        scanf("%d", &new_node_data);
        head = end_node_adder(head, new_node_data);
        break;

    case 5:
        printf("deleting node in the beginning...\n");

        head = begginning_node_deleter(head);
        break;

    case 6:
        printf("please enter the data of the node you would like to delete:\n");
        scanf("%d", &node_finder_data);

        middle_node_deleter(head, node_finder_data);
        break;

    case 7:
        printf("deleting node in the end...\n");

        head = end_node_deleter(head);
        break;

    case 8:
        printf("please enter the data which you want to check:\n");
        scanf("%d", &node_finder_data);

        node_checker(head, node_finder_data);
        break;

    case 9:
        list_printer(head);
        break;

    case 10:
        goto exit;
        break;

    case 11:
        printf("Options avaliable for list manipulation:\n1.Initialize List.\n2.Add node in the beginning.\n3.Add node in the middle.\n4.Add node in the end.\n5.delete node in the beginning.\n6.delete node in the middle.\n7.delete node in the end.\n8.check if a node is present in the list.\n9.Print the Linked list.\n10.Exit \n11.print the operations panel again\n");
        break;

    default:
        printf("operation not found!!! please check the operations list and try again.\n");
        break;
    }
    }

    exit:
    return 0;
}

/*
    FOR TESTING ONLY
    head = list_initializer();
    // printf("%d", head);
    head = begginning_node_adder(head, 99);
    head = end_node_adder(head, 55);
    list_printer(head);
    head = begginning_node_adder(head, 999);
    head = end_node_adder(head, 555);
    list_printer(head);
    middle_node_adder(head, 2000, 20);
    middle_node_adder(head, 2374, 40);
    middle_node_adder(head, 13, 193);
    node_checker(head, 2374);
    list_printer(head);
    head = begginning_node_deleter(head);
    list_printer(head);
    end_node_deleter(head);
    list_printer(head);
    middle_node_deleter(head, 2374);
    list_printer(head);
*/