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

Node* returnStartingNode(Node* head){
    map<Node* , int> mpp;
    Node* temp = head;

    while(temp){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        else{
            mpp[temp] = 1;
            temp = temp->next;
        }
    }

    return nullptr;
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

    Node* startingNode = returnStartingNode(head);
    cout<<"The value of the starting Node is:"<<startingNode->data;
    return 0;
}