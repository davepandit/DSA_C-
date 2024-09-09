#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
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
        
        Node* zeroHead = new Node(-1);
        Node* zero = zeroHead;
        
        Node* oneHead = new Node(-1);
        Node* one = oneHead;
        
        Node* twoHead = new Node(-1);
        Node* two = twoHead;
        
        //traverse the LL
        //if there is an one then attach it to the oneHead and so on
        while(temp){
            if(temp->data == 0){
                zero->next = temp;
                zero = temp;
            }
            else if(temp->data == 1){
                one->next = temp;
                one = temp;
            }
            else{
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        //all the individual LL has been created 
        
        zeroHead = zeroHead->next;
        oneHead = oneHead->next;
        twoHead = twoHead->next;
        
        //connect them 
        zero->next = oneHead;
        one->next = twoHead;
        two->next = nullptr;
        
        return zeroHead;
}

int main() {
    vector<int> arr = {1, 2, 0, 1, 2, 0, 0, 2};
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    //print the LL
    printLL(head);
    Node* newHead = sortLL(head);
    cout<<"\nAfter sorting the LL:\n";
    printLL(newHead);
    return 0;
}