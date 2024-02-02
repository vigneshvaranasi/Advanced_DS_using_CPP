#include <bits/stdc++.h>
using namespace std;
vector<int> heap;
vector<int> priorityQueue;
void insertion(int element) {
    heap.push_back(element);
    int currentIndex = heap.size() - 1;
    while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;
        if (heap[currentIndex] > heap[parentIndex]) 
        {
            swap(heap[currentIndex], heap[parentIndex]);
            currentIndex = parentIndex;
        } 
        else 
            break;
    }
}
void heapify(int currentIndex) {
    int leftChild = 2 * currentIndex + 1;
    int rightChild = 2 * currentIndex + 2;
    int maxIndex = currentIndex;

    if (leftChild < heap.size() && heap[leftChild] > heap[maxIndex])
        maxIndex = leftChild;

    if (rightChild < heap.size() && heap[rightChild] > heap[maxIndex])
        maxIndex = rightChild;

    if (maxIndex != currentIndex) {
        swap(heap[currentIndex], heap[maxIndex]);
        heapify(maxIndex);
    }
}
void deletion() {
    if (heap.size() <= 0) {
        cout << "Heap is Empty" << endl;
    } 
    else {
        priorityQueue.push_back(heap[0]);
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        int currentIndex = 0;
        heapify(currentIndex);
    }
}

int main()
{
    int n,element;
    cout<<"Enter Total Number of Elementrs in the heap:";
    cin>>n;
    cout<<"Enter Heap Elements:";
    for(int i=0;i<n;i++)
    {
        cin>>element;
        insertion(element);
    }
    for(int i=0;i<n;i++)
    {
        deletion();
    }
    int k;
    cout<<"Which Largest Element Do you Want:";
    cin>>k;
    cout<<"Largest K'th Element Is:"<<priorityQueue[k-1]<<endl;
    
}