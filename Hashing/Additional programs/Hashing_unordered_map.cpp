#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int choice;
    vector<int> input;
    cout << "Enter the number of elements to be inserted: ";
    int n;
    cin >> n;
    cout << "Enter the elements to be inserted: ";
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
    unordered_map<int, int> frequencyMap;
    for ( auto element : input) {
        frequencyMap[element]++;
    }
    for ( auto pair : frequencyMap) {
        cout << pair.first << " - " << pair.second << endl;
    }
    return 0;
}
