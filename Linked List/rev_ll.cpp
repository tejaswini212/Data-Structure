#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};

void push(Node **head_ref, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node *node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<"\n";
}

void reverse_iter(Node **head_ref){
    Node *current = *head_ref;
    Node *prev=NULL, *nxt=NULL;
    while(current!=NULL){
        nxt = current->next;
        current->next = prev;
        prev=current;
        current=nxt;
    }
    *head_ref = prev;
}


int main()
{
    Node *head = NULL;
    cout<<head;
    push(&head, 6);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    cout << "Given linked list\n";
    printList(head);
 
    reverse_iter(&head);
 
    cout << "\nReversed Linked list \n";
    printList(head);
    
    return 0;
}


