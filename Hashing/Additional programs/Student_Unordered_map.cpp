#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main() {
    unordered_map<int, vector<string>> student_map;
    while (true) {
        cout << "1. Add student details\n";
        cout << "2. Search for student details\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                vector<string> student_details;

                int roll_number;
                cout << "Enter student roll number: ";
                cin >> roll_number;

                cout << "Enter student Name: ";
                cin.ignore();
                string name;
                getline(cin, name);
                student_details.push_back(name);

                cout << "Enter student Department: ";
                string department;
                cin >> department;
                student_details.push_back(department);

                cout << "Enter student Section: ";
                string Section;
                cin >> Section;
                student_details.push_back(Section);

                student_map[roll_number] = student_details;
                break;
            }
            case 2: {
                int roll_number;
                cout << "Enter the student roll number to search: ";
                cin >> roll_number;

                auto it = student_map.find(roll_number);
                if (it != student_map.end()) {
                    cout << "Student details for Roll Number " << roll_number << ": ";
                    for (auto details : it->second) {
                        cout << details << " ";
                    }
                    cout << endl;
                } else {
                    cout << "Student with Roll Number " << roll_number << " not found." << endl;
                }
                break;
            }
            case 3:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
    return 0;
}
