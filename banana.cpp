#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Banana {
    double bananas, cost;
};

int main() {
    int n;
    double money;
    cout << "Enter number of banana piles: ";
    cin >> n;
    cout << "Enter total money you have: ";
    cin >> money;

    vector<Banana> arr(n);
    for (int i = 0; i < n; i++) {
        cout << "Bananas and cost of pile " << i+1 << ": ";
        cin >> arr[i].bananas >> arr[i].cost;
    }

    sort(arr.begin(), arr.end(), [](Banana a, Banana b) {
        return (a.bananas / a.cost) > (b.bananas / b.cost);
    });

    double total = 0;
    for (int i = 0; i < n && money > 0; i++) {
        if (money >= arr[i].cost) {
            total += arr[i].bananas;
            money -= arr[i].cost;
        } else {
            total += arr[i].bananas * (money / arr[i].cost);
            money = 0;
        }
    }

    cout << "\nMaximum bananas you can buy = " << total << endl;
    return 0;
}
