#include<bits/stdc++.h>
using namespace std;

void setupIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

class Node{
    public:
    int data;
    Node* next;

    Node(int data, Node* next){
        this->data = data;
        (*this).next = next;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

void printLL(Node* head){
    Node* temp = head;
    while(head){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* convertLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

Node* deleteHead(Node* head){
    if(head==NULL) return NULL;
    
    Node* temp = head;
    head = head->next;

    delete temp;
    return head;
}

int main() {
    setupIO();

    vector<int> arr = {10, 20, 30, 40};
    Node* head = convertLL(arr);
    
    // head = deleteHead(head);
    // printLL(head);   
    
    return 0;
}