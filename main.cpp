#include <vector>
#include <iostream>
#include "MyAllocator.h"
#include "MyQueue.h"
#include <deque>

int main() {
    MyQueue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    
    std::cout << "Queue size: " << queue.size() << std::endl;
    std::cout << "Front element: " << queue.front() << std::endl;
    std::cout << "Back element: " << queue.back() << std::endl;
    


    queue.push(10);
    queue.push(20);
    queue.push(30);
    // Check begin and end methods
    MyQueue<int>::iterator it = queue.begin();
    MyQueue<int>::iterator endIt = queue.end();
    while (it != endIt) {
        std::cout << *it << " ";
        ++it;
    }
}


