#include "lrucache.hpp"


LRUCache::LRUCache(size_t max) {
    _max = max;
    n = 0;
}

void LRUCache::put(int key, char val) {
    Node* node = new Node(key, val);
    mymap.insert({key, node});
    if (n == 0) {
        head = node;
        tail = node;
    } else if (n == 1) {
        head->next = node;
        tail = node;
        tail->prev = head;
    } else {
         if (n == _max) {
            Node* temp = head->next;
            mymap.erase(head->key);
            delete head;
            head = temp;
            n--;
        }
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    n++;
}


char LRUCache::get(int key) {
    if (mymap.count(key) == 0 || n == 0) {
        return '\0';
    }
    Node* recent = mymap[key];
    if (recent == tail) return recent->val;
    if (recent == head) {
        head = recent->next;
        head->prev = nullptr;
        tail->next = recent;
        recent->next = nullptr;
        recent->prev = tail;
        tail = recent;
        return recent->val;
    }

    recent->prev->next = recent->next;
    recent->next->prev = recent->prev;
    recent->next = nullptr;
    tail->next = recent;
    recent->prev = tail;
    tail = recent;

    return recent->val;
}

std::ostream& operator<<(std::ostream& os, const LRUCache cache) {
    if (!cache.head) {
        os << "Empty list\n";
        return os;
    }
    Node* curr = cache.head;
    while (curr) {
        os << curr->val;
        curr = curr->next;
        if (curr) os << "<-->";
    }
    return os;

}