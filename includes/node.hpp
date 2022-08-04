#ifndef LIST_HPP
#define LIST_HPP

struct Node {
    int key;
    char val = '\0';
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int key, char val): key(key), val(val) {}
};


#endif