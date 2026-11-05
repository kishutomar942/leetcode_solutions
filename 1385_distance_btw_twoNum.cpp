#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int count = 0;

    for (int i = 0; i < arr1.size(); i++) {
        bool valid = true;

        for (int j = 0; j < arr2.size(); j++) {
            if (abs(arr1[i] - arr2[j]) <= d) {
                valid = false;
                break;
            }
        }

        if (valid) {
            count++;
        }
    }

    return count;
}

int main() {
    vector<int> arr1 = {4, 5, 8};
    vector<int> arr2 = {10, 9, 1, 8};
    int d = 2;

    cout << "Distance Value: "
         << findTheDistanceValue(arr1, arr2, d);

    return 0;
}