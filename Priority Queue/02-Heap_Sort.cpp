#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

void heapify(int size, int rootIndex) {
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    if (leftChild < size && vec[leftChild] > vec[largest])
        largest = leftChild;
    if (rightChild < size && vec[rightChild] > vec[largest])
        largest = rightChild;

    if (largest != rootIndex) {
        swap(vec[rootIndex], vec[largest]);
        heapify(size, largest);
    }
}

void heapSort(int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(size, i);
    for (int i = size - 1; i >= 0; i--) {
        swap(vec[0], vec[i]);
        heapify(i, 0);
    }
}

int main() {
    int numberOfElements;
    cout << "Enter the number of elements: ";
    cin >> numberOfElements;
    vec.reserve(numberOfElements);

    for (int i = 0; i < numberOfElements; i++) {
        int element;
        cin >> element;
        vec.push_back(element);
    }

    heapSort(numberOfElements);

    cout << "Sorted array is \n";
    for (int i = 0; i < numberOfElements; ++i)
        cout << vec[i] << " ";
    cout << "\n";

    return 0;
}
