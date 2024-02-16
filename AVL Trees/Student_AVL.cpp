#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Student
{
    int studentID;
    string studentName;
    string studentClass;
};

class AVLTree
{
    map<int, Student> studentMap;

public:
    void insert(Student newStudent)
    {
        studentMap[newStudent.studentID] = newStudent;
    }

    void search(int studentID)
    {
        if (studentMap.find(studentID) != studentMap.end())
        {
            Student s = studentMap[studentID];
            cout << "Name: " << s.studentName << endl;
            cout << "Class: " << s.studentClass << endl;
        }
        else
        {
            cout << "No student found with student ID " << studentID << endl;
        }
    }
};

int main()
{
    AVLTree studentTree;

    Student student1 = {1, "Vignesh", "LKG"};
    Student student2 = {2, "Eswar", "UKG"};
    Student student3 = {3, "Fakruddin", "1st"};
    Student student4 = {4, "Afzal", "2nd"};
    Student student5 = {5, "Thrinath", "3rd"};
    Student student6 = {6, "Panda", "4th"};
    Student student7 = {7, "Mahesh", "5th"};
    Student student8 = {8, "Pavan", "6th"};
    Student student9 = {9, "Susruth", "7th"};
    Student student10 = {10, "Dhanush", "8th"};

    studentTree.insert(student1);
    studentTree.insert(student2);
    studentTree.insert(student3);
    studentTree.insert(student4);
    studentTree.insert(student5);
    studentTree.insert(student6);
    studentTree.insert(student7);
    studentTree.insert(student8);
    studentTree.insert(student9);
    studentTree.insert(student10);

    int studentID;
    cout << "Enter student ID to search: ";
    cin >> studentID;

    studentTree.search(studentID);

    return 0;
}
