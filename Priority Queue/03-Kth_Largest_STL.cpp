#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> heap;
    int n, element;
    cout << "Enter Total Number of Elementrs in the heap:";
    cin >> n;
    cout << "Enter Heap Elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        heap.push_back(element);
    }
    make_heap(heap.begin(), heap.end());
    sort_heap(heap.begin(), heap.end());
    int k;
    cout << "Which Largest Element Do you Want:";
    cin >> k;
    cout << "Largest K'th Element Is:" << heap[n-k] << endl;
}