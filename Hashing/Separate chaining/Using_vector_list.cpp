#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
class Hashtable
{
public:
    int capacity;
    vector<list<int>> vec;

    Hashtable(int capacity_)
    {
        capacity = capacity_;
        vec.assign(capacity, list<int>());
    }

    int hashcode(int key)
    {
        return key % capacity;
    }

    void insert(int key)
    {
        vec[hashcode(key)].push_back(key);
        cout << "\nKey (" << key << ") has been inserted\n";
    }

    void remove_element(int key)
    {
        auto it = find(vec[hashcode(key)].begin(), vec[hashcode(key)].end(), key);
        if (it != vec[hashcode(key)].end())
        {
            vec[hashcode(key)].erase(it);
            cout << "\nKey (" << key << ") has been removed\n";
        }
        else
        {
            cout << "\nThis key does not exist\n";
        }
    }

    int hashtablesize()
    {
        return vec.size();
    }

    void display()
    {
        cout << "Hashed key\t"
             << "Values" << endl;
        int index = 0;
        for (auto bucket : vec)
        {
            cout << index << "\t\t";
            for (auto value : bucket)
            {
                cout << value << " ";
            }
            cout << endl;
            ++index;
        }
    }
};

int is_prime(int a)
{
    if (a < 2)
        return 0;

    for (int i = 2; i * i <= a; ++i)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

int prime_number(int capacity)
{
    while (capacity > 0)
    {
        if (is_prime(capacity))
            return capacity;
        else
            --capacity;
    }
    return 0;
}

int main()
{
    int choice, key, capacity, n, c;
    cout << "Enter the capacity of the hash table: ";
    cin >> capacity;
    Hashtable obj(prime_number(capacity));
    cout << "Nearest Prime Number is:" << prime_number(capacity);

    do
    {
        cout << "\nImplementation of Hash Table in C++ using vector\n\n";
        cout << "MENU-:\n1.Inserting item in the Hash Table\n"
             << "2.Removing item from the Hash Table\n"
             << "3.Check the size of Hash Table\n"
             << "4.Display a Hash Table\n\n"
             << "Please enter your choice -:";
        cin >> choice;

        switch (choice)
        {
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
