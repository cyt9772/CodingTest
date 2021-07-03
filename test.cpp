#include <iostream>
using namespace std;

int n1, num[10002];

int test() {
    ios::sync_with_stdio(false);
    cin >> n1;
    for (int i = 1; i <= n1; i++) {
        cin >> num[i];
    }
    int tmp_add = n1;
    int tmp = num[n1];
    for (int i = n1; i >= 2; i--) {
        if (num[i - 1] < num[i]) {
            tmp_add = i - 1;
            tmp = num[i - 1];
            break;
        }
    }
    if (tmp_add == n1) {
        cout << -1;
        return 0;
    }
    for (int i = n1; i > tmp_add; i--) {
        if (tmp < num[i]) {
            int ch = num[tmp_add];
            num[tmp_add] = num[i];
            num[i] = ch;
            break;
        }
    }
    for (int i = tmp_add + 1; i <= n1 - 1; i++) {
        for (int j = i + 1; j <= n1; j++) {
            if (num[i] > num[j]) {
                int tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
        }
    }

    for (int i = 1; i <= n1; i++) {
        cout << num[i] << " ";
    }
    return 0;
}