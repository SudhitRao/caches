#include <iostream>
#include "../includes/lrucache.hpp"


int main() {
    std::cout << "Program started" << std::endl;
    LRUCache cache(5);
    cache.put(1, 'a');
    cache.put(2, 'b');
    cache.put(3, 'c');
    cache.put(4, 'd');
    std::cout << cache << std::endl;
    cache.put(5, 'e');
    cache.put(6, 'f');
    std::cout << cache << std::endl;
    cache.get(2);
    std::cout << cache << std::endl;
    cache.put(7, 'g');
    std::cout << cache << std::endl;

    return 0;
}