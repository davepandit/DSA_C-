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

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* modifyLL(Node* head){

    if (!head || !head->next) {
        return head;
    }
    
    Node* odd = head;
    Node* even = head->next;

    while(odd->next != NULL && odd->next->next != NULL){
        Node* curr = odd;
        odd->next = odd->next->next;
        odd = curr->next->next;
    }

    odd->next = even;

    while(even->next != NULL && even->next->next != NULL){
        Node* curr = even;
        even->next = even->next->next;
        even = curr->next->next;
    }

    even->next = NULL;

    return head;
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

    Node* newHead = modifyLL(head);

    Node* temp = newHead;
    while(temp){
        cout<<temp->data<<" ";
    }
    return 0;
}

