/*
Leetcode linked lists recap
*/

struct Node {
    int data;
    Node* next = nullptr;
    Node(int val) : data(val) {};
};

class MyLinkedList {
private:
    int size;
    Node* head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = nullptr;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size || !head) {
            return -1;
        }
        Node* curr = head;
        int curr_ind = 0;
        while (curr_ind != index) {            
            curr_ind++;
            curr = curr -> next;
        }
        return curr -> data;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        node -> next = head;
        head = node;
        size++;
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* curr = head;
        while (curr -> next) {
            curr = curr -> next;
        }
        
        curr -> next = new Node(val);
        size++;
        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        
        if (!head) {
            head = new Node(val);
            size++;
            return;
        }
        
        Node* curr = head;
        int curr_ind = 0;
        while (curr_ind + 1 != index) {            
            curr_ind++;
            curr = curr -> next;
        }
        
        Node* node = new Node(val);
        node -> next = curr -> next;
        curr -> next = node;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }
        Node* curr = head;
        int curr_ind = 0;
        while (curr_ind + 1 != index) {            
            curr_ind++;
            curr = curr -> next;
        }
        
        curr -> next = curr -> next -> next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */

