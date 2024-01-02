#include<bits/stdc++.h>
using namespace std;
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
        void insert(int key)
        {
            vec[hashcode(key)]=key;
            cout << "\nKey (" << key << ") has been inserted\n";
        }
        void remove_element(int key)
        {
            auto it = find(vec.begin(),vec.end(),key);
            if (it != vec.end()) 
            {
                *it=0;
                cout << "\nKey (" << key << ") has been removed\n";
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
            cout<<"Hashed key\t"<<"value"<<endl;
            int index = 0;
            for (auto it = vec.begin(); it != vec.end(); ++it) {
                cout << index << "\t\t" << *it << endl;
                ++index;
            }
        }
    friend int prime_number(Hashtable);
};
int is_prime(int a)
{
    int i;
    if(a==2)
    return a;
    else {
        for(i=3;i<=a/2;i++)
        {
            if(a%i==0)
            break;
        }
        if(i>a/2)
        return 1;
        else return 0;
    }
}
int prime_number(Hashtable h){
        int a= h.capacity;
        while(a>0){
            int x=is_prime(a);
            if(x==1)
            return a;
            else a--;
        }
    }

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