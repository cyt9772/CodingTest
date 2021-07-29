#include <iostream>
using namespace std;

long long d2133[31];

int P2133() {
    int n;
    cin >> n;

    d2133[0] = 1;

    for (int i = 2; i <= n; i++) {
        d2133[i] = 3 * d2133[i - 2];
        for (int j = i - 4; j >= 0; j -= 2) {
            d2133[i] += 2 * d2133[j];
        }
    }

    cout << d2133[n] << endl;

    return 0;
}