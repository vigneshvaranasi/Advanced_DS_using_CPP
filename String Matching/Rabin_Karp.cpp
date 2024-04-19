#include<bits/stdc++.h>
using namespace std;

void rabinKarp( string text,  string pattern) {
    int n = text.length(), m = pattern.length();
    int d = 256, q = 101;
    int h = 1, p = 0, t = 0;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;
    
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t += q; 
        }
    }
}

int main() {
    int choice;
    cout << "1. From File\n2. From User\nEnter Choice: ";
    cin >> choice;
    cin.ignore(); 
    string text, pattern;
    if (choice == 1) {
        ifstream file("input.txt");
        if (!file.is_open()) {
            cout << "Error: Could not open file!" << endl;
            return 1;
        }
        getline(file, text);
        file.close();
    } 
    else {
        cout << "Enter Text: ";
        getline(cin, text);
    }
    cout << "Enter Pattern: ";
    getline(cin, pattern);
    rabinKarp(text, pattern);
    return 0;
}