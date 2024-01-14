#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> freqQuery(vector<vector<int>> queries) {
    vector<int> result;
    unordered_map<int, int> elementFrequency;
    unordered_map<int, int> frequencyCount;

    for (auto& query : queries) {
        int operation = query[0];
        int element = query[1];

        if (operation == 1) {
            int oldFreq = elementFrequency[element];
            elementFrequency[element]++;
            int newFreq = elementFrequency[element];
            frequencyCount[oldFreq]--;
            frequencyCount[newFreq]++;
        } else if (operation == 2) {
            int oldFreq = elementFrequency[element];
            if (oldFreq > 0) {
                elementFrequency[element]--;
                int newFreq = elementFrequency[element];
                frequencyCount[oldFreq]--;
                frequencyCount[newFreq]++;
            }
        } else if (operation == 3) {
            result.push_back(frequencyCount[element] > 0 ? 1 : 0);
        }
    }

    return result;
}

int main() {
    int q;
    cin >> q;
    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<int> result = freqQuery(queries);
    for (int res : result) {
        cout << res << endl;
    }
    return 0;
}
