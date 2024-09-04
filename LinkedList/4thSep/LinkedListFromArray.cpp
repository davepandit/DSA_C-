#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
};

int main() {
    vector<int> vec = {23, 56, 67, 78};
    Node* head = new Node(vec[0], nullptr);
    Node* mover = head;
    
    //traverse in the array 
    for(auto it = vec.begin()+1; it!=vec.end(); it++){
        Node* temp = new Node(*it, nullptr);
        mover->next = temp;
        mover = temp;
    }

    //print the linked list
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
    return 0;
}