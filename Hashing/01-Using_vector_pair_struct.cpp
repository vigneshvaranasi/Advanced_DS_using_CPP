#include<bits/stdc++.h>
using namespace std;
struct Data {
    int key;
    int value;
};
vector<pair<int, Data>> hashTable;
int hashcode(int key, int capacity) {
    return key % capacity;
}
void insert(int key) {
    int index = hashcode(key, hashTable.capacity());
    // Lambda Function in C++
    auto it = find_if(hashTable.begin(), hashTable.end(), [key](auto& pair) {
        return pair.first == key;
    });

    if (it == hashTable.end()) {
        hashTable.emplace_back(key, Data{index,key});
        cout << "\nKey (" << key << ") has been inserted\n";
    } 
    else {
        cout << "\nKey (" << key << ") already present, hence not updating its value\n";
    }
}
void remove_element(int key) {
    auto it = find_if(hashTable.begin(), hashTable.end(), [key](auto& pair) {
        return pair.first == key;
    });

    if (it != hashTable.end()) {
        hashTable.erase(it);
        cout << "\nKey (" << key << ") has been removed\n";
    } else {
        cout << "\nThis key does not exist\n";
    }
}
void display() {
    cout<<"Used value\t"<<"Hashed key\t"<<"value"<<endl;
    for (auto& entry : hashTable) {
        cout<<entry.first<<" \t\t"<< entry.second.key <<"\t\t"<< entry.second.value <<"\n";
    }
}
int hashtablesize() {
    return hashTable.size();
}
int main() {
    int choice, key, n, c;

    cout << "Enter the capacity of the hash table: ";
    int capacity;
    cin >> capacity;
    hashTable.reserve(capacity);
    do {
        cout << "\nImplementation of Hash Table in C++ using vector\n\n";
        cout << "MENU-:\n1.Inserting item in the Hash Table\n"
                     "2.Removing item from the Hash Table\n"
                     "3.Check the size of Hash Table\n"
                     "4.Display a Hash Table\n\n"
                     "Please enter your choice -:";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Inserting element in Hash Table\nEnter key -:";
                cin >> key;
                insert(key);
                break;
            case 2:
                cout << "Deleting in Hash Table\nEnter the key to delete-:";
                cin >> key;
                remove_element(key);
                break;
            case 3:
                n = hashtablesize();
                cout << "Size of Hash Table is-:" << n << "\n";
                break;
            case 4:
                display();
                break;
            default:
                cout << "Wrong Input\n";
        }

        cout << "\nDo you want to continue? (press 1 for yes)\t";
        cin >> c;

    } while (c == 1);

    return 0;
}