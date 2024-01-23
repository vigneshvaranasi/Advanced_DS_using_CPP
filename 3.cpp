#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
void max_ele()
{
    if (v.size() > 1)
        cout << "The maximum element is: " << v[1] << endl;
    else
        cout << "THE HEAP IS EMPTY" << endl;
}
void min_ele()
{
    if (v.size() > 1)
        cout << "The minimum element is: " << *min_element(v.begin() + 1, v.end()) << endl;
    else
        cout << "THE HEAP IS EMPTY" << endl;
}
void heap_size()
{
    cout << "No. of elements are: " << v.size() - 1 << endl;
}
void adjust(int i, int high)
{
    int j = i * 2;
    int item = v[i];
    while (j <= high)
    {
        if ((j < high) && (v[j] < v[j + 1]))
            j = j + 1;
        if (item >= v[j])
            break;
        else
        {
            v[j / 2] = v[j];
            j = j * 2;
        }
    }
    v[j / 2] = item;
}

void insertion()
{
    int i = v.size() - 1;
    int item = v[i];
    while (i > 1 && v[i / 2] < item)
    {
        v[i] = v[i / 2];
        i = i / 2;
    }
    v[i] = item;
}
void deletion()
{
    if (v.size() <= 1)
    {
        cout << "HEAP IS EMPTY" << endl;
        return;
    }
    int x = v[1];
    v[1] = v[v.size() - 1];
    adjust(1, v.size() - 2);
    cout << x << " is deleted!" << endl;
    v.resize(v.size() - 1);
}
void display()
{
    for (int i = 1; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}
int main()
{
    int choice;
    int op;
    cout << "Do you want to perform operations?";
    cin >> choice;
    v.push_back(0);
    while (choice)
    {
        cout << "Enter the operation: 1.INSERTION\n 2.DELETION\n 3.DISPLAY\n 4.PEEK\n 5.MAXIMUM ELEMENT\n 6.MINIMUM ELEMENT\n 7.SIZE Enter the operation:";
        cin >> op;
        switch (op)
        {
        case 1:
        {
            cout << "Enter the element to be inserted:";
            int ele;
            cin >> ele;
            v.push_back(ele);
            insertion();
            break;
        }
        case 2:
            deletion();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "The peek element is: " << v[1] << endl;
            break;
        case 5:
            max_ele();
            break;
        case 6:
            min_ele();
            break;
        case 7:
            heap_size();
            break;
        default:
            cout << "Enter the correct operation!!" << endl;
        }
        cout << "Do you want to continue? (1/0)";
        cin >> choice;
    }
    return 0;
}