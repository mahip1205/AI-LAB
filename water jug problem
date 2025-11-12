#include <iostream>
using namespace std;

int main() {
    int cap[3], target;
    int jug[3];

    cout << "Enter capacity of Jug A: ";
    cin >> cap[0];
    cout << "Enter capacity of Jug B: ";
    cin >> cap[1];
    cout << "Enter capacity of Jug C: ";
    cin >> cap[2];

    cout << "Enter target amount: ";
    cin >> target;

    jug[0] = 0; 
    jug[1] = 0; 
    jug[2] = cap[2];

    cout << "\nSteps:\n";

    for (int step = 0; step < 20; step++) {
        cout << "(" << jug[0] << ", " << jug[1] << ", " << jug[2] << ")\n";

        if (jug[0] == target || jug[1] == target || jug[2] == target) {
            cout << "Target achieved!\n";
            break;
        }

        int from = 2, to = 0;
        int pourAmount = min(jug[from], cap[to] - jug[to]);
        jug[from] -= pourAmount;
        jug[to] += pourAmount;

        if (jug[0] > 0 && jug[1] < cap[1]) {
            pourAmount = min(jug[0], cap[1] - jug[1]);
            jug[0] -= pourAmount;
            jug[1] += pourAmount;
        }

        if (jug[1] > 0 && jug[2] < cap[2]) {
            pourAmount = min(jug[1], cap[2] - jug[2]);
            jug[1] -= pourAmount;
            jug[2] += pourAmount;
        }
    }

    return 0;
}
