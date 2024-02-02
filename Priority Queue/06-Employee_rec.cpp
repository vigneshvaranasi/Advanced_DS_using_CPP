#include <iostream>
#include <queue>
using namespace std;
class employee
{
public:
    int empid;
    string ename;
    string designation;
    int age;
    float height;
    void read(int id, string name, string des, int a, float h)
    {
        empid = id;
        ename = name;
        designation = des;
        age = a;
        height = h;
    }
    void display()
    {
        cout << "The employee Details:-" << endl;
        cout << "Emplyee ID          :" << empid << endl;
        cout << "Emplyee name        :" << ename << endl;
        cout << "Employee Designation:" << designation << endl;
        cout << "Employee Age        :" << age << endl;
        cout << "Employee Height     :" << height << endl;
    }
};
int main()
{
    int n,id,a;
    string name, des;
    float h;
    priority_queue<int, vector<int>, greater<int>> ageQueue;
    cout << "Enter the number of employees: " << endl;
    cin >> n;
    employee e[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter employee id,Name,Designtion,Age,Height respectively:" << endl;
        cin >> id >> name >> des >> a >> h;
        ageQueue.push(a);
        e[i].read(id, name, des, a, h);
    }
    int i = 0;
    while (!ageQueue.empty())
    {
        while (ageQueue.top() != e[i].age)
            i++;
        if (ageQueue.top() == e[i].age)
        {
            e[i].display();
            ageQueue.pop();
            i = 0;
        }
    }
}