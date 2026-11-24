
#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    vector<long long> prefix;

    ProductOfNumbers() {
        prefix.push_back(1);
    }

    void add(int num) {

        if (num == 0) {
            prefix.clear();
            prefix.push_back(1);
        }
        else {
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {

        int n = prefix.size();

        if (k >= n) {
            return 0;
        }

        return prefix[n - 1] / prefix[n - 1 - k];
    }
};

int main() {

    ProductOfNumbers obj;

    obj.add(3);
    obj.add(0);
    obj.add(2);
    obj.add(5);
    obj.add(4);

    cout << "Product of last 2 numbers: "
         << obj.getProduct(2) << endl;

    cout << "Product of last 3 numbers: "
         << obj.getProduct(3) << endl;

    cout << "Product of last 4 numbers: "
         << obj.getProduct(4) << endl;

    obj.add(8);

    cout << "Product of last 2 numbers: "
         << obj.getProduct(2) << endl;

    return 0;
}
make