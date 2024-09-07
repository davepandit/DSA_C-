#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* back;
        Node* next;
        Node(int data1){
            data = data1;
            back = nullptr;
            next = nullptr;
        }
};

int main() {
    vector<int> arr = {1, 2, 4, 5, 6, 7};

    Node* head = new Node(arr[0]);
    Node* prev = head;

    //traverse the array
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;

        //move the prev
        prev = temp; 
    }

    //print the doubly linked list 
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}