#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int sherlockAndAnagrams(string s) {
    int n = s.length();
    unordered_map<string, int> substringFrequency;
    for (int i = 0; i < n; i++) 
    {
        string substring;
        for (int j = i; j < n; j++) 
        {
            substring = s.substr(i, j - i + 1);
            sort(substring.begin(), substring.end());
            substringFrequency[substring]++;
        }
    }
    int count = 0;
    for (auto& entry : substringFrequency) {
        int freq = entry.second;
        count += (freq * (freq - 1)) / 2;
    }

    return count;
}

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        int result = sherlockAndAnagrams(s);
        cout << result << endl;
    }
    return 0;
}