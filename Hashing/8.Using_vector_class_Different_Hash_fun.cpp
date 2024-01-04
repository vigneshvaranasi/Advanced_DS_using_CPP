#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Hashtable {
public:
    int capacity, fun;
    vector<int> vec;

    Hashtable(int capacity_, int fun_) : capacity(capacity_), fun(fun_) {
        vec.assign(capacity, 0);
    }
    int funselect(int key) {
        switch (fun) {
            case 1:
                return key % capacity;
                break;
            case 2:
                break;

            default:
                cout << "Wrong Input\n";
                exit(0);
        }
    }

    void insert(int key) {
        vec[funselect(key)] = key;
        cout << "\nKey (" << key << ") has been inserted\n";
    }

    void remove_element(int key) {
        auto it = find(vec.begin(), vec.end(), key);
        if (it != vec.end()) {
            *it = 0;
            cout << "\nKey (" << key << ") has been removed\n";
        } else
            cout << "\nThis key does not exist\n";
    }

    int hashtablesize() const {
        return vec.size();
    }

    void display() const {
        cout << "Hashed key\t" << "value" << endl;
        int index = 0;
        for (auto it = vec.begin(); it != vec.end(); ++it) {
            cout << index << "\t\t" << *it << endl;
            ++index;
        }
    }
};

int main() {
    int choice, key, capacity, n, c, fun;

    cout << "Enter the capacity of the hash table: ";
    cin >> capacity;

    cout << "\nWhich Hash Function to Use:\n";
    cout << "1.Division Method\n"
         << "2.Mid Square Method\n"
         << "3.Folding Method\n"
         << "4.Multiplication Method\n\n"
         << "Please enter your choice -:";
    cin >> fun;

    Hashtable obj(capacity, fun);

    do {
        cout << "\nImplementation of Hash Table in C++ using vector\n\n";
        cout << "MENU-:\n1.Inserting item in the Hash Table\n"
             << "2.Removing item from the Hash Table\n"
             << "3.Check the size of Hash Table\n"
             << "4.Display a Hash Table\n"
             << "Please enter your choice -:";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Inserting element in Hash Table\nEnter key -:";
                cin >> key;
                obj.insert(key);
                break;
            case 2:
                cout << "Deleting in Hash Table\nEnter the key to delete-:";
                cin >> key;
                obj.remove_element(key);
                break;
            case 3:
                n = obj.hashtablesize();
                cout << "Size of Hash Table is-:" << n << "\n";
                break;
            case 4:
                obj.display();
                break;
            default:
                cout << "Wrong Input\n";
        }

        cout << "\nDo you want to continue? (press 1 for yes)\t";
        cin >> c;
    } while (c == 1);

    return 0;
}
