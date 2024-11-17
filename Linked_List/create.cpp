#include <bits/stdc++.h>

using namespace std;

class node {
    public:

    int val;
    node *next;


    node (int val){
      this->val = val;
      this->next = NULL;
    }

};

void printList(node *head)
{
  
    while(head!= NULL){
        cout << head->val << " ";
        head = head->next; 
    }
}

node * removeVal(node *head, int val)
{   // val always exists
    if(head==nullptr){
        return NULL;
    }
    //for removing the head element
    while (head != nullptr && head->val == val) {
        head = head->next;
    }

    node *current = head;
    node *prev = nullptr;
    
    while(current!=nullptr){
         if(current->val == val){
            prev->next = current->next;
         }
         prev = current;
         current = current->next;
    }
    return head;
}
int main(){

    ////////////////////////////////////
    node *head, *temp, *temp1, *temp2, *temp3;
    head = new node(1);   // 1 -> null
    temp = new node(2);   // 2-> null
    head->next = temp;    // head next null
    temp1 = new node(3);  // 3->null
    head->next->next = temp1;
    // temp->next = temp1;   // 
    temp2 = new node(4);  // 4->null
    temp1->next = temp2;
    temp3 = new node(5);  // 5->null
    temp2->next= temp3;
    // printList(head); 
    cout << "the end for creating linkedlist"<<endl;
    ///////////////////////////////////////////
    node *add;
    add = new node(6);
    head->next->next = add; // put address of new created element in the one before linked list element
    add->next = temp1; // put address of next element address in new created elements
    // printList(head);
    cout << "added the new element in the linked list"<<endl;
    /*add 9 to end of the linked list*/
    node *last;
    last = new node(9);
    temp3->next = last;
    // printList(head);
    cout << "added the new element at end of the linked list"<<endl;
    ///////////////////////////////////////////////

    /*Remove 4 from the list*/
    // temp1->next = temp3;
    node *head1 = removeVal(head,4);
    printList(head1);
    cout << "remove the 4 from the linked list"<<endl;

    ////////////////////////////////////////////////
    // change the value 5 to 12;
    temp3->val = 12;
    printList(head1);
    cout << "change to 12 from 5 the linked list"<<endl;


}