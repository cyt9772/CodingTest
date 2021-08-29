#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define MAX1261 100
using namespace std;

int map1261[MAX1261 + 1][MAX1261 + 1];
int dist1261[MAX1261 + 1][MAX1261 + 1];

int dx_1261[] = { 0, 0, -1, 1 };
int dy_1261[] = { -1, 1, 0, 0 };

int P1261() {
    int n, m;  //
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &map1261[i][j]);
            dist1261[i][j] = -1;
        }
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> next_queue;
    q.push(make_pair(0, 0));
    dist1261[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx_1261[i];
            int ny = y + dy_1261[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (dist1261[nx][ny] == -1) { //not visited
                    if (map1261[nx][ny] == 0) { //no weight
                        dist1261[nx][ny] = dist1261[x][y];
                        q.push(make_pair(nx, ny));
                    }
                    else { //weight
                        dist1261[nx][ny] = dist1261[x][y] + 1;
                        next_queue.push(make_pair(nx, ny));
                    }
                }
            }
        }

        if (q.empty()) {
            q = next_queue;
            next_queue = queue<pair<int, int>>();
        }
    }

    printf("%d\n", dist1261[n - 1][m - 1]);

    return 0;

}

