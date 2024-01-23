#include<bits/stdc++.h>
using namespace std;
vector<int> heap;
void insertion(int element) {
    heap.push_back(element);
    int size = heap.size() - 1;
    while (size > 0 &&  heap[(size - 1) / 2] < heap[size]) 
    {
        swap(heap[size], heap[(size - 1) / 2]);
        size = (size - 1) / 2;
    }
}
void maxElement()
{
    if(heap.size()>1)
        cout<<"Maximum Element is: "<<heap[1]<<endl;
    else
        cout<<"Heap is Empty"<<endl;
}
void minElement()
{
    if(heap.size()>1)
        cout<<"Minimum Element is: "<<*min_element(heap.begin()+1,heap.end())<<endl;
    else
        cout<<"Heap is Empty"<<endl;
}
void display()
{
    if(heap.size()<=0)
    {
        cout<<"Heap is Empty"<<endl;
    }
    else
    {
        for(int i=0;i<heap.size();i++)
            cout<<heap[i]<<" ";
        cout<<endl;
    }
}
int main()
{
    int choice,element;
    while(1)
    {
        cout<<"1. Insertion"<<endl;
        cout<<"2. Deletion"<<endl;
        cout<<"3. Maximum Element"<<endl;
        cout<<"4. Minimum Element"<<endl;
        cout<<"5. Heap Size"<<endl;
        cout<<"6. Display Heap"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter the Element to Insert: ";
                cin>>element;
                insertion(element);
                break;
            }
            case 3:
            {
                maxElement();
                break;
            }
            case 4:
            {
                minElement();
                break;
            }
            case 5:
            {
                cout<<"Heap Size is: "<<heap.size()-1<<endl;
                break;
            }
            case 6:
            {
                display();
                break;
            }
            case 7:
            {
                exit(0);
            }

        }
    }
    
}
