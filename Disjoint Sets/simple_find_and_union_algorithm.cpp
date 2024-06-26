#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int findRoot(int x) {
    while (parent[x] != x) {
        x = parent[x];
    }
    return x;
}

void unionSets(int x, int y) {
  int xRoot = findRoot(x);
  int yRoot = findRoot(y);
  if (xRoot != yRoot) {
    if(xRoot < yRoot)
      parent[yRoot] = x;
    else
      parent[xRoot] = y;
  }
}

int main() {
    int numberOfElements;
    cout << "Enter the number of elements: ";
    cin >> numberOfElements;
    parent.resize(numberOfElements);
    for (int i = 0; i < numberOfElements; i++) {
        parent[i] = i;
    }

    int choice;
    do {
        cout << "\nMenu:\n1. Find\n2. Union\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int element;
                cout << "Enter the element: ";
                cin >> element;
                cout << "Parent of " << element << " is " << parent[element] << endl;
                cout << "Root of " << element << " is " << findRoot(element) << endl;
                break;
            }
            case 2: {
                int element1, element2;
                cout << "Enter two elements to union: ";
                cin >> element1 >> element2;
                unionSets(element1, element2);
                cout << "Union performed." << endl;
                break;
            }
            case 3:
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);

    return 0;
}