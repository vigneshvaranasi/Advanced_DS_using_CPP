#include<bits/stdc++.h>
using namespace std;
vector<int> heap1, heap2,mergedHeap;
void heapify(vector<int> heap)
{
    for (int i = 1; i < heap.size(); i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (heap[childIndex] < heap[parentIndex])
            {
                swap(heap[childIndex], heap[parentIndex]);
                childIndex = parentIndex;
            }
            else
                break;
        }
    }
}
void mergeHeaps()
{
    for (int i = 0; i < heap1.size(); i++)
        mergedHeap.push_back(heap1[i]);
    for (int i = 0; i < heap2.size(); i++)
        mergedHeap.push_back(heap2[i]);
    heapify(mergedHeap);
    for (int i = 0; i < mergedHeap.size(); i++)
        cout << mergedHeap[i] << " ";
    cout << endl;
}
int main()
{
    int n1, n2,element;
    cout<<"Enter the size of heap1: ";
    cin >> n1;
    cout<<"Enter the elements of heap1: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> element;
        heap1.push_back(element);
    }
    cout<<"Enter the size of heap2: ";
    cin >> n2;
    cout<<"Enter the elements of heap2: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> element;
        heap2.push_back(element);
    }
    mergeHeaps();
    return 0;
}