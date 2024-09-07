#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* next;
    int data;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void printLL(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* sortLL(Node* head) {
    // Find the first occurrence of 0, 1, and 2
    Node* prev0 = nullptr;
    Node* prev1 = nullptr;
    Node* prev2 = nullptr;

    Node* temp = head;

    // Traverse and set pointers for first 0, 1, and 2
    while (temp) {
        if (!prev0 && temp->data == 0) prev0 = temp;
        if (!prev1 && temp->data == 1) prev1 = temp;
        if (!prev2 && temp->data == 2) prev2 = temp;
        temp = temp->next;
    }
    Node* prev0Copy = prev0;

    // If there is no 0, 1, or 2, return the list as it is
    if (!prev0 || !prev1 || !prev2) return head;

    // Reset temp to head to traverse the list again
    temp = head;

    // Linking 0s
    Node* zeroTail = prev0; // Tail of the 0s
    temp = prev0->next;
    while (temp) {
        if (temp->data == 0) {
            zeroTail->next = temp;
            zeroTail = temp;
        }
        temp = temp->next;
    }

    // Linking 1s
    Node* oneTail = prev1; // Tail of the 1s
    temp = prev1->next;
    while (temp) {
        if (temp->data == 1) {
            oneTail->next = temp;
            oneTail = temp;
        }
        temp = temp->next;
    }

    // Linking 2s
    Node* twoTail = prev2; // Tail of the 2s
    temp = prev2->next;
    while (temp) {
        if (temp->data == 2) {
            twoTail->next = temp;
            twoTail = temp;
        }
        temp = temp->next;
    }

    // Now join the parts: 0s -> 1s -> 2s
    zeroTail->next = prev1;
    oneTail->next = prev2;
    twoTail->next = nullptr;  // End the list

    return prev0Copy;
}

int main() {
    vector<int> arr = {1, 0, 1, 2, 0, 2, 1};
    Node* head = new Node(arr[0]);
    Node* mover = head;

    // Convert array into a linked list
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    // Sort the linked list
    Node* newNode = sortLL(head);

    // Print the sorted linked list
    printLL(newNode);

    return 0;
}
