#include <iostream>
#include <unordered_set>
using namespace std;

void PalindromicSubstrings(string s) 
{
    int n = s.size();
    unordered_set<string> set;
    for (int i = 0; i < n; i++) 
    {
        // Odd length palindromes
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) 
        {
            set.insert(s.substr(left, right - left + 1));
            left--;
            right++;
        }
        // Even length palindromes
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) 
        {
            set.insert(s.substr(left, right - left + 1));
            left--;
            right++;
        }
    }

    cout << "Palindromic Count: " << set.size() << endl;
    cout << "Palindromic Sub-strings: " << endl;
    for ( auto palindrome : set) {
        cout << palindrome << endl;
    }
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    PalindromicSubstrings(str);
    return 0;
}
