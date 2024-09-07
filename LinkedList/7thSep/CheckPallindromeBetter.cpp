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

Node* reverseLL(Node* head){
    Node* temp = head;
    Node* curr;
    while(temp){
        static Node* prev = NULL;
        curr = temp;
        temp->next = prev;
        prev = temp;
        temp = curr->next;
    }
    cout<<"Here it is:"<<curr;
    printLL(curr);
    return curr;
}

bool checkPallindrome(Node* head){
    //toroise hare method
    Node* temp = head;
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = NULL;
    //now we must be at the second last or the last 
    cout<<"reached";
    Node* lastSideSeHead = reverseLL(slow->next);
    cout<<"Last side se head"<<lastSideSeHead->data<<endl;

    //now we have 2 separate LL and we can check for the first and the last
    Node* tail = lastSideSeHead;
    temp = head;
    while(temp){
        if(temp->data == tail->data){
            temp = temp->next;
            tail = tail->next;
        }else{
            return false;
        }
    }
    //then the LL is a pallindrome 
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