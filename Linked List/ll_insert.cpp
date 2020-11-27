#include<bits/stdc++.h>
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

void insertAfter(Node *prev_node,int new_data){
    if(prev_node==NULL){
         cout<<"Prev node null";
         return;
    }
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(Node **head_ref,int new_data){
    Node *new_node = new Node();
    Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref==NULL)
    {
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    return;
}

void printList(Node *node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<"\n";
}

int main(){
    Node *head = NULL;
    cout<<head;
    append(&head, 6);
    append(&head, 7);
    append(&head, 9);
    push(&head, 4);
    push(&head, 1);
    insertAfter(head->next, 5);
    cout<<"List created:";
    printList(head);
    cout<<head<<"\n";
    cout<<head->next<<"\n";
    cout<<*(&head)<<"\n";
    cout<<*(&head->next)<<"\n";
    return 0;
}
