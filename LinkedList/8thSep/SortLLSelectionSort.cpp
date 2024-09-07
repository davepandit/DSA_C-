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

void swap(Node* min, Node* temp){
    int curr;
    curr = temp->data;
    temp->data = min->data;
    min->data = curr;
}

Node* sortLL(Node* head){
    Node* temp = head;
    Node* mover;
    Node* min;
    //selection sort
    while(temp){
        min = temp;
        mover = temp;
        while(mover){
            if(mover->data <= min->data){
                min = mover;
            }
            mover = mover->next;
        }
        //swap the min and temp
        swap(min, temp);
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