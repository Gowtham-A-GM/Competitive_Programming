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


Node* convertToLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* deleteHead(Node* head){
    if(head==NULL) return NULL;
    
    Node* temp = head;
    head = head->next;

    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node* deleteKthElement(Node* head, int k){
    if(head == nullptr) return nullptr;

    // to delete head or k==1
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // to delete kth element, or k>1
    int cnt = 0;
    Node *temp = head, *prev = nullptr;
    while(temp){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next; // prev->next = temp->next;
            delete temp; // free(temp);
            break;
        }
        prev = temp;
        temp = temp->next; 
    }

    return head;
}

Node* deleteElement(Node* head, int element){
    if(head == nullptr) return nullptr;

    // to delete head or k==1
    if(head->data==element){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // to delete based on a element, or k>1
    Node *temp = head, *prev = nullptr;
    while(temp){
        if(temp->data==element){
            prev->next = prev->next->next; // prev->next = temp->next;
            delete temp; // free(temp);
            break;
        }
        prev = temp;
        temp = temp->next; 
    }

    return head;
}

Node* insertHead(Node* head, int val){
    if(head==nullptr) return new Node(val, nullptr);

    Node* temp = new Node(val, head);
    return temp;
}

Node* insertTail(Node* head, int val){
    if(head==nullptr) return new Node(val, nullptr);

    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node(val, nullptr);
    temp->next = newNode;

    return head;
}

Node* insertAtKthElement(Node* head, int val, int idx){
    if(head==nullptr){
        if(idx==1) return new Node(val);
        else nullptr;
    }

    if(idx==1){
        return new Node(val, head);
    }

    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt==idx-1){
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

Node* insertBeforeElement(Node* head, int val, int beforeElement){
    if(head==nullptr) return nullptr;

    if(head->data==beforeElement){
        return new Node(val, head);
    }

    int cnt = 0;
    Node* temp = head;
    while(temp->next != nullptr){
        cnt++;
        if(temp->next->data == beforeElement){
            Node* newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

int main() {
    setupIO();

    vector<int> arr = {10, 20, 30, 40};
    Node* head = convertToLL(arr);
    
    // DELETION

    // Delete HEAD
    // head = deleteHead(head);
    // printLL(head); 
    
    // Delete TAIL
    // head = deleteTail(head);
    // printLL(head);

    // Delete ELEMENT at kth POSITION
    // head = deleteKthElement(head, 3);
    // printLL(head);

    // Delete based on ELEMENT
    // head = deleteElement(head, 20);
    // printLL(head);

    // INSERTION

    // Insert at HEAD
    // head = insertHead(head, 100);
    // printLL(head);
    
    // Insert at HEAD
    // head = insertTail(head, 200);
    // printLL(head);

    // Insert at kth POSITION
    // head = insertAtKthElement(head, 300, 3);
    // printLL(head);

    // Insert BEFORE ELEMENT
    head = insertBeforeElement(head, 300, 30);
    printLL(head);
        
    return 0;
}