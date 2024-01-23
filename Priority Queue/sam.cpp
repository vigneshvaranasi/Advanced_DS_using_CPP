#include <iostream>
#include <vector>
#include <algorithm>  // for std::swap

std::vector<int> heap;

void insertion(int element) 
{
    heap.push_back(element);
    int size = heap.size() - 1;
    while (size > 0 && heap[size] > heap[size / 2]) {
        std::swap(heap[size], heap[size / 2]);
        size = size / 2;
    }
}

int main() {
    insertion(50);
    std::cout<<heap.size();
    insertion(30);
    insertion(20);
    insertion(15);
    insertion(10);
    insertion(8);
    insertion(16);
    insertion(60);

    // Print the heap to check if elements are inserted correctly
    for (int i = 0; i < heap.size(); i++) {
        std::cout << heap[i] << " ";
    }

    return 0;
}
