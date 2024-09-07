#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        //constructor
        Node(int data1){
            data = data1;
            prev = nullptr;
            next = nullptr;
        }
};

Node* deleteNode(Node* head, int pos){
    Node* temp = head;
    int count = 0;

    //reach the pos
    while(temp){
        count++;
        if(count == pos){
            break;
        }
        else{
            temp = temp->next;
        }
    }

    //we are at the node that is to be deleted
    Node* back = temp->prev;
    Node* front = temp->next;

    back->next = front;
    front->prev = back;

    //free the node
    temp->next = nullptr;
    temp->prev = nullptr;

    free(temp);

    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    Node* head = new Node(arr[0]);
    Node* mover = head;

    //traverse the array 
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }

    //print the DLL
    cout<<"Before deleting the Node:\n";
    Node* temp = head;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;

    }

    Node* newHead = deleteNode(head, 3);

    cout<<"\nAfter deleting the Node:\n";
    temp = newHead;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;

    }
    
    return 0;
}