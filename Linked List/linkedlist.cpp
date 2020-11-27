#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

void printList(Node *n){
    while(n!=NULL){
        cout<< n->data <<" ";
        n = n->next;
    }
    cout<<"\n";
}

int main(){
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    
    
    head -> next = second; 
    second ->next = third;
    third -> next = NULL;
    
    head -> data = 2;
    second -> data = 5;
    third -> data = 9;   
    
   
    printList(head);
    
    return 0;
}
