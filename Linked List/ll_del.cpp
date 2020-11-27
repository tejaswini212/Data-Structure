#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};

void push(Node **head_ref,int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node *node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<"\n";
}

void del_key(Node **head_ref,int key){
    Node *temp=*head_ref;
    Node *prev=NULL;
    if(temp!=NULL && temp->data==key){
        *head_ref = temp->next;
        delete temp;
        return;
    }
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp = temp->next;
    }
    if(temp==NULL)
        return;
    prev->next=temp->next;
    delete temp;
}

void del_pos(Node **head_ref,int pos){
    if(*head_ref==NULL) return;
    Node *temp=*head_ref;
    if(pos==0){
        *head_ref=temp->next;
        delete temp;
        return;
    }    
    for(int i=0;temp!=NULL && i<pos-1;i++)
        temp=temp->next;
    if(temp==NULL || temp->next==NULL)
        return;
    Node *nxt = temp->next->next;
    delete temp->next;
    temp->next=nxt;
}

int main(){
    Node *head=NULL;
    push(&head,5);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    cout<<"List is ";
    printList(head);
    del_key(&head,2);
    cout<<"List is ";
    printList(head);
    del_pos(&head,2);
    cout<<"List is ";
    printList(head);
    return 0;
}
