#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* next;
        int data;
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* curr;
Node* reverseLL(Node* head){
    static Node* prev = NULL;

    //base condition
    if(head == NULL){
        return prev;
    }

    //preprocessing
    curr = head->next;
    head->next = prev;
    prev = head;
    head = curr;

    //call the function again
    reverseLL(head);   
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node*  head = new Node(arr[0]);
    Node* mover = head;

    //convert into a linked list
    for(int i=1; i<arr.size(); i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }


    Node* newHead = reverseLL(head);

    //print the LL
    Node* temp = newHead;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    return 0;
}