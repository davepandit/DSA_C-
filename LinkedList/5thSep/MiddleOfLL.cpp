#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* back;
        Node* next;
        Node(int data1){
            data = data1;
            back = nullptr;
            next = nullptr;
        }
};

Node* findMiddle(Node* head){
    int len = 0, count = 0, mid;
    Node* temp = head;
    //find the length of the LL
    while(temp){
        len++;
        temp = temp->next;
    }

    mid = len/2;

    temp = head;//bring the temp back
    while(temp){
        count++;
        if(count == mid + 1){
            return temp;
        }
        temp = temp->next;
    }

}

int main() {
    //this is the brute force 
    vector<int> arr = {1, 2, 4, 5, 6, 7};

    Node* head = new Node(arr[0]);
    Node* prev = head;

    //traverse the array
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;

        //move the prev
        prev = temp; 
    }

    //find the middle
    Node* middle = findMiddle(head);
    cout<<middle->data;
    return 0;
}