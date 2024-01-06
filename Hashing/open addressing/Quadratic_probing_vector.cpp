#include<bits/stdc++.h>
using namespace std;
int count_=0;
int is_prime(int a) {
    if (a < 2)
        return 0;

    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
int prime_number(int capacity) {
    while (capacity > 0) {
        if (is_prime(capacity))
            return capacity;
        else
            --capacity;
    }
    return 0;
}
class Hashtable
{
    public:
        int capacity;
        vector<int> vec;
        Hashtable(int capacity_)
        {
            capacity=capacity_;
            vec.assign(capacity, 0);
        }
        int hashcode(int key) 
        {
            return key % capacity;
        }
        void rehash()
        {
            int newcapacity = capacity * 2;
            int newprime = prime_number(newcapacity);
            vector<int> newvec;
            newvec.resize(newprime);
            for (int i = 0; i < newprime; i++)
            {
                newvec[i]= 0;
            }
            for (int i = 0; i < capacity; i++)
            {
                if (vec[i] != 0)
                {
                    int index = hashcode(vec[i]);
                    newvec[index]= vec[i];
                }
            }
            vec = newvec;
            capacity = newprime;
        }
        int insert(int key)
        {
            int loadfactor = count_ / capacity;
            if (loadfactor >= 0.75)
            {
                cout << "Rehashing" << endl;
                rehash();
            }
            if(count_==capacity)
            {
                cout<<"Hashtable is full\n";
                return 0;
            }
            int collision=0;
            int index = hashcode(key);
            int fixindex=index;
            while (vec[index] != 0)
            {
                collision++;
                index = (fixindex + collision*collision)%capacity;
                if(vec[index]==0)
                {
                cout << "Collided and Inserted"<<endl;
                vec[index]=key;
                count_++;
                return 0;
                }
            }
            vec[hashcode(key)]=key;
            cout << "\nKey (" << key << ") has been inserted\n";           
            count_++;
            return 0;
        }
        void remove_element(int key)
        {
            auto it = find(vec.begin(),vec.end(),key);
            if (it != vec.end()) 
            {
                *it=0;
                cout << "\nKey (" << key << ") has been removed\n";
                count_--;
            } 
            else
                cout << "\nThis key does not exist\n";
        }
        int hashtablesize()
        {
            return vec.size();
        }
        void display()
        {
            cout<<"Hashed key\t"<<"Key"<<endl;
            int index = 0;
            for (auto it = vec.begin(); it != vec.end(); ++it) {
                cout << index << "\t\t" << *it << endl;
                ++index;
            }
        }
};

int main()
{
    int choice,key,capacity, n, c;
    cout << "Enter the capacity of the hash table: ";
    cin >> capacity;
    Hashtable obj(prime_number(capacity));
    cout<<"Nearst Prime Number is:"<<prime_number(capacity);
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