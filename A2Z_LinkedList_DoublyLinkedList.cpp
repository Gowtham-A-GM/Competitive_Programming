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
    Node* back;

    Node(int data, Node* next, Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->back = nullptr;
    }
};


Node* convertToDLL(vector<int>& arr){
    Node* head = new Node(arr[0], nullptr, nullptr);
    Node* prev = head;

    for(int i=1; i<arr.size(); i++){
        Node* newNode = new Node(arr[i], nullptr, prev);
        prev->next = newNode;
        prev = newNode;
    }

    return head;
}

void printDLL(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}


Node* deleteHead(Node* head){
    if(head==nullptr || head->next==nullptr){
        delete head;
        return nullptr;
    }

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;

    return head;
}

Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr){
        delete head;
        return nullptr;
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    Node* newTail = tail->back;
    tail->back = nullptr;
    newTail->next = nullptr;
    delete tail;

    return head;
}

Node* deleteKthElement(Node* head, int k){
    if(head==nullptr) return nullptr;

    int cnt = 0;
    Node* kthNode = head;
    while(kthNode != nullptr){
        cnt++;
        if(cnt == k){
            break;
        }
        kthNode = kthNode->next;
    }

    if(cnt<k || cnt>k) return head; // for not in range

    Node* prevNode = kthNode->back;
    Node* nextNode = kthNode->next;

    if(prevNode==nullptr && nextNode==nullptr){
        delete kthNode;
        return kthNode;
    }
    else if(prevNode==nullptr){
        return deleteHead(head);
    }
    else if(nextNode==nullptr){
        return deleteTail(head);
    }

    prevNode->next = nextNode;
    nextNode->back = prevNode;

    kthNode->next = nullptr;
    kthNode->back = nullptr;
    delete kthNode;

    return head;
}

void deleteNode(Node* node){ // node will not be HEAD
    Node* nextNode = node->next;
    Node* prevNode = node->back;

    if(nextNode==nullptr){ // its a TAIL Node
        prevNode->next = nullptr;
        node->back = nullptr;
        delete node;
        return;
    }

    prevNode->next = nextNode;
    nextNode->back = prevNode;

    node->next = node->back = nullptr;
    delete node;
}


Node* insertBeforeHead(Node* head, int val){
    if(head==nullptr){
        return new Node(val, nullptr, nullptr);
    }

    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}

Node* insertBeforeTail(Node* head, int val){
    if(head==nullptr || head->next==nullptr){
        return insertBeforeHead(head, val);
    }

    Node* tailNode = head;
    while(tailNode->next != nullptr){
        tailNode = tailNode->next;
    }

    Node* prevNode = tailNode->back;
    Node* newNode = new Node(val, tailNode, prevNode);

    tailNode->back = newNode;
    prevNode->next = newNode;

    return head;
}

Node* insertBeforeKthElement(Node* head, int val, int idx){
    if(idx==1) return insertBeforeHead(head, val);
    
    int cnt = 0;
    Node* temp = head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==idx) break;
        temp = temp->next;
    }
    Node* prevNode = temp->back;
    Node* newNode = new Node(val, temp, prevNode);
    prevNode->next = newNode;
    temp->back = newNode;
    return head;

}

void insertBeforeNode(Node* node, int val){
    Node* prevNode = node->back;
    Node* newNode = new Node(val, node, prevNode);
    prevNode->next = newNode;
    node->back = newNode;
}


int main() {
    setupIO();
    vector<int> arr = {10, 20, 30, 40};
    Node* head = convertToDLL(arr);
    // printDLL(head);

    // Delete HEAD
    // head = deleteHead(head);
    // printDLL(head);

    // Delete TAIL
    // head = deleteTail(head);
    // printDLL(head);

    // Delete ELEMENT at kth POSITION
    // head = deleteKthElement(head, 3);
    // printDLL(head);

    // Delete given NODE
    // deleteNode(head->next);
    // printDLL(head);

    // INSERTION

    // Insert before HEAD
    // head = insertBeforeHead(head, 100);
    // printDLL(head);
    
    // Insert before TAIL
    // head = insertBeforeTail(head, 200);
    // printDLL(head);

    // Insert before kth POSITION
    // head = insertBeforeKthElement(head, 300, 3);
    // printDLL(head);

    // Insert before given NODE
    // insertBeforeNode(head->next->next, 500);
    // printDLL(head);


    
    return 0;
}