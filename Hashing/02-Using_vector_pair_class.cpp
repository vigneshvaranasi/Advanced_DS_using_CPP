#include<bits/stdc++.h>
using namespace std;

class HashTable {
private:
    vector<pair<int, int>> hashTable;

public:
    HashTable(int capacity) {
        hashTable.reserve(capacity);
    }
    int hashcode(int key)  {
        return key % hashTable.capacity();
    }
    void insert(int key) {
        int index = hashcode(key);
        // Lambda Function in C++
        auto it = find_if(hashTable.begin(), hashTable.end(), [key](auto& pair) {
            return pair.first == key;
        });
        if (it == hashTable.end()) {
            hashTable.emplace_back(key, index);
            cout << "\nKey (" << key << ") has been inserted\n";
        } else {
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

    void display()  {
        cout << "Used value\t" << "Hashed key\t" << "value\n";
        for ( auto& entry : hashTable) {
            cout << entry.first << " \t\t" << entry.second << "\t\t" << entry.first << "\n";
        }
    }

    int size()  {
        return hashTable.size();
    }
};

int main() {
    int choice, key, n, c;

    cout << "Enter the capacity of the hash table: ";
    int capacity;
    cin >> capacity;
    HashTable hashTable(capacity);

    do {
        cout << "\nImplementation of Hash Table in C++ using class\n\n";
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
                hashTable.insert(key);
                break;
            case 2:
                cout << "Deleting in Hash Table\nEnter the key to delete-:";
                cin >> key;
                hashTable.remove_element(key);
                break;
            case 3:
                n = hashTable.size();
                cout << "Size of Hash Table is-:" << n << "\n";
                break;
            case 4:
                hashTable.display();
                break;
            default:
                cout << "Wrong Input\n";
        }

        cout << "\nDo you want to continue? (press 1 for yes)\t";
        cin >> c;

    } while (c == 1);

    return 0;
}

