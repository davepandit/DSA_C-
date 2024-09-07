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

Node* removeNode(Node* head, int k){
    Node* temp = head;
    int length = 0, count = 0;
    //count the ele
    while(temp){
        length++;
    }

    temp = head;
    while(temp){
        count++;
        if(count == (length - k +1)){
            Node* front = temp;
            temp->data = front->data;
            temp->next = front->next; 
            front->next = NULL;

            free(front);
        }
        temp = temp->next;
    }

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

    Node* newNode = removeNode(head, 5);
    return 0;
}