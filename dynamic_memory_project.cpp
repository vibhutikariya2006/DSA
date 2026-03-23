#include<iostream>
using namespace std;

class Node{
   public:
   int data;
   Node* next;
   Node(int a){
    data = a;
    next = NULL;
   }
};

class DynamicMemory{
public:
Node* head;

 DynamicMemory(){
    head = NULL;
 }

 void display(){
    if(head == NULL){
        cout << "List is Empty ";
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << " NULL ";
 }

 void insert_at_begin(int val){
   Node* newNode = new Node(val);
   newNode->next = head;
   head = newNode;
 }

 void search(int val){
    bool found = false;
    int count = 0;
    Node* temp = head;
   while(temp->next != NULL){
    if(temp->data == val){
      cout << "Value is found  at " << count << endl;
      found = true;
       return;
    }
    count ++;
    temp = temp->next;
}

if(!found){
    cout << "Search Value not found " << endl;
}

 }

void delete_node(int val) {
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {

       
        if (temp->data == val) {

            if (prev == NULL) {
                head = temp->next;
            } 
            else {
                prev->next = temp->next;
            }

            delete temp;
            cout << "Deleted successfully" << endl;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Delete Value not found" << endl;
}

       void reverse(){
         if(head == NULL || head->next == NULL){
            cout << "List is empty " << endl;
            return;
        }

        Node* pre = NULL;
        Node* cur = head;
        Node* next = NULL;

        while (cur != NULL){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next; 
        }
        head = pre;
      
        
    }

};

int main(){
DynamicMemory d;
    d.insert_at_begin(50);
    d.insert_at_begin(40);
    d.insert_at_begin(80);
    d.insert_at_begin(45);
    d.search(10);
    d.delete_node(55);
    d.reverse();
    d.display();


};