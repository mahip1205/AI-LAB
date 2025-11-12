#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

double f(double x) {
    return -x*x + 6*x + 2;
}

int main() {
    srand(time(0));
    double x = rand() % 10; 
    double step = 0.1; 
    double fx = f(x);
    bool improved = true;

    cout << "Initial x: " << x << ", f(x): " << fx << endl;

    while (improved) {
        improved = false;
        double left = x - step, right = x + step;
        double f_left = f(left), f_right = f(right);

        if (f_left > fx) {
            x = left;
            fx = f_left;
            improved = true;
        } else if (f_right > fx) {
            x = right;
            fx = f_right;
            improved = true;
        }
    }

    cout << "\nLocal maximum at x = " << x << ", f(x) = " << fx << endl;
    return 0;
}
