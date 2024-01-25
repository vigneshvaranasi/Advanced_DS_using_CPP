#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
void insertion(int element) {
    heap.push_back(element);
    int currentIndex = heap.size() - 1;
    while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;
        if (heap[currentIndex] < heap[parentIndex]) 
        {
            swap(heap[currentIndex], heap[parentIndex]);
            currentIndex = parentIndex;
        } 
        else 
            break;
    }
}

void deletion() 
{
    if (heap.size() <= 0) 
    {
        cout << "Heap is Empty" << endl;
    } 
    else 
    {
        cout << "Deleted Element is: " << heap[0] << endl;
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        int currentIndex = 0;
        while (currentIndex < heap.size()) 
        {
            int leftChild = 2 * currentIndex + 1;
            int rightChild = 2 * currentIndex + 2;
            if (leftChild >= heap.size())
                break;
            int minIndex = currentIndex;
            if (heap[leftChild] < heap[minIndex])
                minIndex = leftChild;
            if (rightChild < heap.size() && heap[rightChild] < heap[minIndex])
                minIndex = rightChild;
            if (minIndex == currentIndex)
                break;
            swap(heap[currentIndex], heap[minIndex]);
            currentIndex = minIndex;
        }
    }
}

void maxElement() {
    if (heap.size() > 0)
    {
        auto it = max_element(heap.begin(), heap.end());
        cout << "Maximum Element is: " << *it << endl;
    }
    else
        cout << "Heap is Empty" << endl;
}

void minElement() {
    if (heap.size() > 0) {
        cout << "Minimum Element is: " << heap[0] << endl;
    } else {
        cout << "Heap is Empty" << endl;
    }
}

void display() {
    if (heap.size() <= 0) {
        cout << "Heap is Empty" << endl;
    } else {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }
}

void peek() {
    if (heap.size() > 0)
        cout << "Peek Element is: " << heap[0] << endl;
    else
        cout << "Heap is Empty" << endl;
}

int main() {
    int choice, element;
    while (1) {
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Maximum Element" << endl;
        cout << "4. Minimum Element" << endl;
        cout << "5. Heap Size" << endl;
        cout << "6. Display Heap" << endl;
        cout << "7. Peek Element" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter the Element to Insert: ";
                cin >> element;
                insertion(element);
                break;
            }
            case 2: {
                deletion();
                break;
            }
            case 3: {
                maxElement();
                break;
            }
            case 4: {
                minElement();
                break;
            }
            case 5: {
                cout << "Heap Size is: " << heap.size() << endl;
                break;
            }
            case 6: {
                display();
                break;
            }
            case 7: {
                peek();
                break;
            }
            case 8: {
                exit(0);
            }
        }
    }
}
