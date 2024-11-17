#include <bits/stdc++.h>

using namespace std;

class node {
    public:

    int val;
    node * next;

    node (int val){
        this->val = val;
        this->next = NULL;
    }

    node* reverse(node * head){
        node * current = head;
        node * temp = NULL;
        while(current!=NULL) {
        node* currentnode = current->next;
        current->next = temp;
        temp = current;
        current = currentnode;

        }
      return temp;
    }
};

int main (){

    node * head;
    head = new node(1);
    head->next = new node(2);
    head->next->next = new node (3);
    head->next->next->next = new node (4);
    
    node * current = head;
    while (current!=NULL){
        cout << "  " <<current->val;
        current = current->next;
    }
    std::cout << endl;

     // Reverse the linked list
    head = head->reverse(head);
    current = head;
    std:: cout << "reversed linked list ";
    while (current!=NULL){
        cout << " " << current->val;
        current = current->next;
        
    }
}

