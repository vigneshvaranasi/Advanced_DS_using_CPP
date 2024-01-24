#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
void insertion(int element) {
    heap.push_back(element);
    int currentIndex = heap.size() - 1;
    while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;
        if (heap[currentIndex] > heap[parentIndex]) {
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
        swap(heap[1], heap[heap.size() - 1]);
        heap.pop_back();
        int currentIndex = 1;
        while (currentIndex < heap.size())
        {
            int leftChild = 2 * currentIndex;
            int rightChild = 2 * currentIndex + 1;
            if (leftChild >= heap.size())
                break;
            int maxIndex = currentIndex;
            if (heap[maxIndex] < heap[leftChild])
                maxIndex = leftChild;
            if (rightChild < heap.size() && heap[maxIndex] < heap[rightChild])
                maxIndex = rightChild;
            if (maxIndex == currentIndex)
                break;
            swap(heap[currentIndex], heap[maxIndex]);
            currentIndex = maxIndex;
        }
    }
}
void maxElement()
{
    if (heap.size() > 1)
        cout << "Maximum Element is: " << heap[1] << endl;
    else
        cout << "Heap is Empty" << endl;
}
void minElement()
{
    if (heap.size() > 1)
    {
        auto it = min_element(heap.begin() + 1, heap.end());
        cout << "Minimum Element is: " << *it << endl;
    }
    else
        cout << "Heap is Empty" << endl;
}

void display()
{
    if (heap.size() <= 0)
    {
        cout << "Heap is Empty" << endl;
    }
    else
    {
        for (int i = 0; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }
}
void peek()
{
    if (heap.size() > 1)
        cout << "Peek Element is: " << heap[1] << endl;
    else
        cout << "Heap is Empty" << endl;
}

int main()
{
    int choice, element;
    while (1)
    {
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
        switch (choice)
        {
            case 1:
            {
                cout << "Enter the Element to Insert: ";
                cin >> element;
                insertion(element);
                break;
            }
            case 2:
            {
                deletion();
                break;
            }
            case 3:
            {
                maxElement();
                break;
            }
            case 4:
            {
                minElement();
                break;
            }
            case 5:
            {
                cout << "Heap Size is: " << heap.size() - 1 << endl;
                break;
            }
            case 6:
            {
                display();
                break;
            }
            case 7:
            {
                peek();
                break;
            }
            case 8:
            {
                exit(0);
            }
        }
    }
}
