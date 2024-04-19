#include <iostream>
#include <list>
#include <cmath>
using namespace std;
static int count = 0;
bool isPrime(int num) {
    int count = 0;
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            count++;
        }
    }
    return count == 2;
}

int prime_number(int capacity)
{
    while (true)
    {
        if (isPrime(capacity))
            return capacity;
        else
            --capacity;
    }
}
class Data
{
public:
    int keyValue;
    int keyCount;
};

class Hashtable
{
public:
    int capacity, fun;
    list<Data> lst;

    Hashtable(int capacity_, int fun_)
    {
        capacity = capacity_;
        fun = fun_;
        lst.resize(capacity);
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            it->keyValue = 0;
            it->keyCount = 0;
        }
    }

    int funselect(int key)
    {
        int hash_index = 0;
        int r = 0;
        int i = 0, j = 0, sum = 0;
        double con = 0.5;

        switch (fun)
        {
        case 1:
            return key % capacity;
        case 2:
        {
            int pow = key * key;
            int number = pow;
            string str = to_string(pow);
            int a = str.size();
            if (a % 2 == 0)
            {
                cout << "The square of the number is even, taking the 3rd digit from last " << endl;
                while (pow > 0 && i <= 3)
                {
                    r = pow % 10;
                    pow = pow / 10;
                    i++;
                }
                hash_index = r;
            }
            else if (a == 1)
                hash_index = key;
            else
            {
                cout << "Taking the middle digit of the square of the number" << endl;
                while (number > 0 && j <= 2)
                {
                    r = number % 10;
                    number = number / 10;
                    j++;
                }
                hash_index = r;
            }
            break;
        }
        case 3:
            while (key > 0)
            {
                r = key % 10;
                sum += r;
                key = key / 10;
            }
            if (sum >= capacity)
                hash_index = sum % capacity;
            else
                hash_index = sum;
            break;
        case 4:
            hash_index = floor(capacity * ((con * key) - floor(con * key)));
            break;
        default:
            cout << "Wrong Input\n";
            exit(0);
        }

        return hash_index;
    }
    void rehash()
    {
        int new_capacity = prime_number(2 * capacity);
        list<Data> new_lst;
        new_lst.resize(new_capacity);
        for (auto it = new_lst.begin(); it != new_lst.end(); ++it)
        {
            it->keyValue = 0;
            it->keyCount = 0;
        }
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            int index = funselect(it->keyValue);
            auto it1 = next(new_lst.begin(), index);
            it1->keyValue = it->keyValue;
            it1->keyCount = it->keyCount;
        }
        lst = new_lst;
        capacity = new_capacity;
    }

    void insert(int key)
    {
        int index = funselect(key);
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            if (it->keyValue == key)
            {
                cout << "\nKey (" << key << ") already exists\n";
                it->keyCount++;
                return;
            }
        }
        count++;
        auto it = next(lst.begin(), index);
        it->keyValue = key;
        it->keyCount++;
        cout << "\nKey (" << key << ") has been inserted\n";
        int loadfactor = count / capacity;
        if (loadfactor >= 0.75)
        {
            cout << "Rehashing" << endl;
            rehash();
        }
    }

    void remove_element(int key)
    {
        int index = funselect(key);
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            if (it->keyValue == key && it->keyCount > 0)
            {
                it->keyCount--;
                cout << "\nKey (" << key << ") has been removed\n";
                return;
            }
        }
        cout << "\nThis key does not exist\n";
    }
    int hashtablesize()
    {
        return lst.size();
    }
    void display()
    {
        cout << "Hashed key\t"
             << "key\t"
             << "Count" << endl;
        int i = 0;
        for (auto it = lst.begin(); it != lst.end(); ++it, i++)
        {
            cout << i << "\t\t" << it->keyValue << "\t" << it->keyCount << endl;
        }
    }
    void search(int key)
    {
        int index = funselect(key);
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            if (it->keyValue == key)
            {
                cout << "\nKey (" << key << ") found at index " << index << endl;
                return;
            }
        }
        cout << "\nKey (" << key << ") not found\n";
    }
};

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
        cout << "\nImplementation of Hash Table in C++ using list\n\n";
        cout << "MENU-:\n1. Inserting item in the Hash Table\n"
             << "2. Removing item from the Hash Table\n"
             << "3. Check the size of Hash Table\n"
             << "4. Display a Hash Table\n"
             << "5. Search an element in Hash Table\n" 
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
        case 5:
            cout << "Enter the key to search-:";
            cin >> key;
            obj.search(key);
            break;
        default:
            cout << "Wrong Input\n";
        }

        cout << "\nDo you want to continue? (press 1 for yes)\t";
        cin >> c;
    } while (c == 1);

    return 0;
}
