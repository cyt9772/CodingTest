#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int P13398() {
    int n;
    cin >> n;

    vector<int> a(n); //입력 데이터

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    vector<int> d(n); //n까지의 합의 최대값
    vector<int> dr(n); //n부터의 합의 최대값

    for (int i = 0; i < n; i++) {
        d[i] = a[i];
        if (i == 0) continue;
        if (d[i] < d[i - 1] + a[i]) {
            d[i] = d[i - 1] + a[i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        dr[i] = a[i];
        if (i == n - 1) continue;
        if (dr[i] < dr[i + 1] + a[i]) {
            dr[i] = dr[i + 1] + a[i];
        }
    }

    int ans = d[0];
    
    for (int i = 1; i < n; i++) {  //제거하지 않는 상태에서의 최대값 
        if (ans < d[i]) {
            ans = d[i];
        }
    }

    for (int i = 1; i < n - 1; i++) { //n을 제거한 상태에서 최대값 구하기
        if (ans < d[i - 1] + dr[i + 1]) {
            ans = d[i - 1] + dr[i + 1];
        }
    }
    cout << ans << '\n';
    return 0;
}