#include<bits/stdc++.h>
using namespace std;

void findPattern(string text, string pattern) {
    int n = text.length(), m = pattern.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    int choice;
    cout << "1. From File\n2. From User\nEnter Choice: ";
    cin >> choice;
    string text, pattern;
    if (choice == 1) {
        ifstream file("input.txt");
        getline(file, text);
        file.close();
    } 
    else {
        cout << "Enter Text: ";
        cin >> text;
    }
    cout << "Enter Pattern: ";
    cin >> pattern;
    findPattern(text, pattern);
    return 0;
}