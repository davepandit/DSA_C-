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

Node* sortLL(Node* head){
    Node* temp = head;
    multiset<int> s;
    while(temp){
        s.insert(temp->data);
        temp = temp->next;
    } 

    temp = head;
    for(auto it=s.begin(); it!=s.end(); it++){
        temp->data = *it;
        temp = temp->next;
    }

    return head;
}

int main() {
    vector<int> arr = {6, 4, 5, 2, 3, 1};
    Node*  head = new Node(arr[0]);
    Node* mover = head;

    //convert into a linked list
    for(int i=1; i<arr.size(); i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    Node* newHead = sortLL(head);

    printLL(newHead);
    return 0;
}