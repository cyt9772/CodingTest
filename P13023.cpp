#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool a10323[2000][2000];
vector<int> g10323[2000];
vector<pair<int, int>> edges10323;

int P13023() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        edges10323.push_back({ from, to });
        edges10323.push_back({ to, from });
        a10323[from][to] = a10323[to][from] = true;
        g10323[from].push_back(to);
        g10323[to].push_back(from);
    }
    m *= 2;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            // A -> B
            int A = edges10323[i].first;
            int B = edges10323[i].second;
            // C -> D
            int C = edges10323[j].first;
            int D = edges10323[j].second;
            if (A == B || A == C || A == D || B == C || B == D || C == D) {
                continue;
            }
            // B -> C
            if (!a10323[B][C]) {
                continue;
            }
            // D -> E
            for (int E : g10323[D]) { //D에서 갈 수 있는 방향 점검(E)
                if (A == E || B == E || C == E || D == E) {
                    continue;
                }
                cout << 1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';
    return 0;
}