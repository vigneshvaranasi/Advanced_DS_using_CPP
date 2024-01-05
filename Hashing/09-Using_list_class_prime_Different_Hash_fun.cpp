#include <iostream>
#include <list>
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
    list<Data> lst;

    Hashtable(int capacity_, int fun_)
    {
        capacity = capacity_;
        fun = fun_;
        lst.resize(capacity);
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            it->key = 0;
            it->value = 0;
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

    void insert(int key)
    {
        int index = funselect(key);
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            if (it->key == key)
            {
                cout << "\nKey (" << key << ") already exists\n";
                it->value++;
                return;
            }
        }
        auto it = next(lst.begin(), index);
        it->key = key;
        it->value++;
        cout << "\nKey (" << key << ") has been inserted\n";
    }

    void remove_element(int key)
    {
        int index = funselect(key);
        for (auto it = lst.begin(); it != lst.end(); ++it)
        {
            if (it->key == key && it->value > 0)
            {
                    it->value--;
                    cout << "\nKey (" << key << ") has been removed\n";
                    return;
            }
        }
        cout << "\nThis key does not exist\n";
    }
    void display()
    {
        cout << "Hashed key\t"
             << "Value\t"
             << "Count" << endl;
        int i = 0;
        for (auto it = lst.begin(); it != lst.end(); ++it, i++)
        {
            cout << i << "\t" << it->key << "\t\t" << it->value << endl;
        }
    }
    int hashtablesize()
    {
        return lst.size();
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
        cout << "\nImplementation of Hash Table in C++ using list\n\n";
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
