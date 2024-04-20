#include <bits/stdc++.h>
using namespace std;

priority_queue<int> max_heap;

void insertion(int element) {
    max_heap.push(element);
}

void deletion() {
    if (max_heap.empty()) {
        cout << "Heap is Empty" << endl;
    } else {
        cout << "Deleted Element is: " << max_heap.top() << endl;
        max_heap.pop();
    }
}

void maxElement() {
    if (max_heap.empty()) {
        cout << "Heap is Empty" << endl;
    } else {
        cout << "Maximum Element is: " << max_heap.top() << endl;
    }
}

void minElement() {
    if (max_heap.empty()) {
        cout << "Heap is Empty" << endl;
    } 
    else {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        while (!max_heap.empty()) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        int min_val = min_heap.top();
        cout << "Minimum Element is: " << min_val << endl;
        while (!min_heap.empty()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
}


void display() {
    if (max_heap.empty()) {
        cout << "Heap is Empty" << endl;
    } 
    else {
        priority_queue<int> temp;
        temp = max_heap;
        cout << "Heap elements: ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
}

void peek() {
    if (max_heap.empty()) {
        cout << "Heap is Empty" << endl;
    } else {
        cout << "Peek Element is: " << max_heap.top() << endl;
    }
}

void mergeHeaps() {
    int size, element;
    cout << "Enter the size of heap2: ";
    cin >> size;
    cout << "Enter the elements of heap2: ";
    for (int i = 0; i < size; i++) {
        cin >> element;
        max_heap.push(element);
    }
    cout << "Merged Heap: ";
    display();
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
        cout << "8. Merge Heaps" << endl;
        cout << "9. Exit" << endl;
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
                cout << "Heap Size is: " << max_heap.size() << endl;
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
                mergeHeaps();
                break;
            }
            case 9: {
                exit(0);
            }
        }
    }
    return 0;
}
