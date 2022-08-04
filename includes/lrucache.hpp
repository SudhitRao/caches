#ifndef LRU_CACHE_HPP
#define LRU_CACHE_HPP

#include <map>
#include <iostream>
#include "node.hpp"


class LRUCache {

    public:
        LRUCache(size_t max);
        void put(int key, char val);
        char get(int key);
        friend std::ostream& operator<<(std::ostream& os, const LRUCache cache);

    private:
        size_t _max; //min size is 2
        size_t n; 
        Node* head = nullptr;
        Node* tail = nullptr;
        std::map<int, Node*> mymap;
};

std::ostream& operator<<(std::ostream& os, const LRUCache cache);

#endif