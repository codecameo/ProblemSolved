#include <map>
/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    if(head == NULL) return false;
    map<Node*, bool> table;
    table[head] = true;
    while(head->next != NULL){
        head = head->next;
        if(table[head]) return true;
        table[head] = true;
    }

    return false;
}

