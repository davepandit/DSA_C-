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

int searchEleInLL(Node* head, int ele){
    //traverse the LL
    Node* temp = head;
    int flag;
    while(temp!=nullptr){
        if(temp->data == ele){
            flag = 1;
        }

        //move the pointer
        temp = temp->next;
    }

    if(flag == 1){
        return 0;
    }else{
        return -1;
    }
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

    //search for a linked list 
    int res = searchEleInLL(head, 6);

    if(res == -1){
        cout<<"Not Found!!";
    }else{
        cout<<"Found!!";
    }
    return 0;
}