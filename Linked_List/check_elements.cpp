#include <bits/stdc++.h>

using namespace std;

class node {
    public:
    int val;
    node *next;

    node (int val){
        this->val = val;
        next = nullptr;
    }
};

class linkedlist {
    
    node* head;

    public :
    linkedlist (){
        head = nullptr;
    }
    
    void append(int val) {
        node *newnode = new node (val);
        if (head ==nullptr){
            head = newnode;
        }
        else
        {
            node *temp = head;
            while(temp->next != nullptr){
                  temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    void display(){
        node *head_ref = head;
        if (head_ref == nullptr){
            cout << "LinkedList is empty"<<endl;
        }

        while(head_ref!=nullptr){
            cout << head_ref->val<<" ";
            head_ref = head_ref->next;
        }
        std::cout<<endl;
    }

    void ispresent(int val){
        node * head_ref = head;
        if (head_ref == nullptr){
            cout << "element " << val << " is not present"<<endl;
            return;
        }

        while(head_ref!=nullptr){
            if(head_ref->val == val){
                cout << "element " << val << " is present"<<endl;
                return;
            }
            head_ref = head_ref->next;
        }
        cout << "element " << val << " is not present"<<endl;

    }

};

int main (){
    linkedlist list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);

    list.display();

    list.ispresent(9);
    list.ispresent(5);
}

