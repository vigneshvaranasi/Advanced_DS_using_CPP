#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Data
{
public:
    int key;
    int value;
};

class Hashtable
{
public:
    int capacity, fun;
    vector<Data> vec;

    Hashtable(int capacity_, int fun_)
    {
        capacity = capacity_;
        fun = fun_;
        vec.resize(capacity);
        for (int i = 0; i < capacity; i++)
        {
            vec[i].key = 0;
            vec[i].value = 0;
        }
    }

    int funselect(int key)
    {
        if (vec.size() < capacity)
        {
            cout << "Error: Vector size is less than the specified capacity\n";
            exit(1);
        }
        switch (fun)
        {
        case 1:
            return key % capacity;
        case 2:
            return 0;
        case 3:
            return 0;
        case 4:
            return 0;
        default:
            cout << "Wrong Input\n";
            exit(0);
        }
    }

    void insert(int key)
    {
        int index = funselect(key);
        if (vec[index].key != 0)
        {
            cout << "\nKey (" << key << ") already exists\n";
            vec[index].value++;
        }
        else
        {
            vec[index].key = key;
            vec[index].value++;
            cout << "\nKey (" << key << ") has been inserted\n";
        }
    }

    void remove_element(int key)
    {
        int index = funselect(key);
        if (vec[index].key == key)
        {
            vec[index].key = 0;
            vec[index].value--;
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
        cout << "Index\t"
             << "Hashed key\t"
             << "Count" << endl;
        for (int i = 0; i < capacity; i++)
        {
            cout << i << "\t" << vec[i].key << "\t\t" << vec[i].value << endl;
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
    while (true)
    {
        if (is_prime(capacity))
            return capacity;
        else
            --capacity;
    }
}

int main()
{
    int choice, key, capacity, n, c, fun;

    cout << "Enter the capacity of the hash table: ";
    cin >> capacity;

    cout << "\nWhich Hash Function to Use:\n";
    cout << "1. Division Method\n"
         << "2. Mid Square Method\n"
         << "3. Folding Method\n"
         << "4. Multiplication Method\n\n"
         << "Please enter your choice -:";
    cin >> fun;
    capacity = prime_number(capacity);
    Hashtable obj(capacity, fun);
    cout << "Nearest Prime Number is:" << capacity << endl;

    do
    {
        cout << "\nImplementation of Hash Table in C++ using vector\n\n";
        cout << "MENU-:\n1. Inserting item in the Hash Table\n"
             << "2. Removing item from the Hash Table\n"
             << "3. Check the size of Hash Table\n"
             << "4. Display a Hash Table\n"
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
