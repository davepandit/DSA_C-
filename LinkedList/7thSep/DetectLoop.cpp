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

bool detectLoop(Node* head){
    map<Node* , int> mpp;
    Node* temp = head;

    while(temp){
        if(mpp.find(temp) != mpp.end()){
            return true;
        }
        else{
            mpp[temp] = 1;
            temp = temp->next;
        }
    }

    return false;
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

    //detect a loop
    if(detectLoop(head)){
        //if it is true
        cout<<"True\n";
    }else{
        cout<<"False\n";
    }
    return 0;
}