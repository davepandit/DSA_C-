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

bool checkPallindrome(Node* head){
    Node* temp = head;
    stack<int> s;

    //traverse the linked list
    while(temp){
        s.push(temp->data);
        temp = temp->next;
    }

    //compare the original with the stack 
    temp = head;
    while(temp){
        if(temp->data == s.top()){
            s.pop();
            temp = temp->next;
        }else{
            return false;
        }
    }
    //if we reach here then it is a pallindrome
    return true;
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 2, 1};
    Node*  head = new Node(arr[0]);
    Node* mover = head;

    //convert into a linked list
    for(int i=1; i<arr.size(); i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    bool res = checkPallindrome(head);
    if(res){
        cout<<"The LL is a Pallindrome!!";
    }else{
        cout<<"Not a Pallindrome!!";
    }
    return 0;
}