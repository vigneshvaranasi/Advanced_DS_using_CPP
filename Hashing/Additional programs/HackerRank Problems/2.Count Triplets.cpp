#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long countTriplets(vector<long> arr, long r) {
    unordered_map<long, long> count, left, right;
    long tripletsCount = 0;

    for (long num : arr) {
        tripletsCount += right[num];
        right[num * r] += count[num];
        count[num * r]++;
        left[num]++;
    }

    return tripletsCount;
}

int main() {
    long n, r;
    cin >> n >> r;

    vector<long> arr(n);
    for (long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long result = countTriplets(arr, r);
    cout << result << endl;

    return 0;
}
