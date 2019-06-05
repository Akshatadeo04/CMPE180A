#include <iostream>
using namespace std;

struct Nodetype{
    int data;
    Nodetype *link;
};

Nodetype *head = NULL;

void inserting(int i){
    if(head == NULL){
        Nodetype *newNode = new Nodetype;
        newNode->data = i;
        newNode->link = NULL;
        head = newNode;
    }
    else{
        Nodetype *current;
        current = head;
        while(current->link != NULL){
            current = current->link;
        }
        Nodetype *newNode = new Nodetype;
        newNode->data = i;
        newNode->link = NULL;
        current->link = newNode;
    }
}

void printall(){
    if(head == NULL){
        cout << "LL is empty.";
    }
    else{
        Nodetype *current;
        current = head;
        while(current != NULL){
            cout << current->data << " ";
            current = current->link;
        }
    }
}

void addMid(int add, int after){
    Nodetype *current = head;
    if(current == NULL) return;
    while(current->data != after){
        current = current->link;
    }
    Nodetype *temp = current->link;
    Nodetype *newnode = new Nodetype;
    newnode->data = add;
    newnode->link = temp;
    current->link = newnode;
}

void deleting(int del){
    Nodetype *current = head;
    if(current == NULL) return;
    while(current->link->data != del){
        current = current->link;
    }
    Nodetype *removing = current->link;
    current->link = current->link->link;
    delete removing;
    removing = NULL;
}

void printing_reverse(Nodetype *head){
    if(head == NULL) return ;
    printing_reverse(head->link);
    cout << head->data << " ";
}

int main()
{
    for(int i=0; i<5 ; i++){
        inserting(i);
    }
    printall();
    cout << endl << "adding element 5 at 2nd index";
    addMid(5,2);
    cout << endl;
    printall();
    cout << endl << "deleting element 3";
    deleting(3);
    cout << endl;
    printall();
    cout << endl << "printing in reverse order" << endl;
    printing_reverse(head);
    return 0;
}
