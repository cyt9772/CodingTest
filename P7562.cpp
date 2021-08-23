#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>


using namespace std;

int dx7562[] = { -2,-1, 1, 2,  2,  1, -1, -2 };
int dy7562[] = { 1,   2, 2, 1, -1, -2, -2, -1};
int dist7562[301][301];


int P7562() {

	int T; //test case
	cin >> T;
	
	while (T--) {
		int N; //가로, 세로(정사각형)
		cin >> N;
	
		memset(dist7562, -1, sizeof(dist7562));

		int startX, startY;
		int targetX, targetY;

		cin >> startX >> startY;
		cin >> targetX >> targetY;

		startX++;
		startY++;
		targetX++;
		targetY++;
		
		queue<pair<int, int>> q;
		q.push(make_pair(startX, startY));
		dist7562[startX][startY] = 0;

		while (!q.empty()) { 
			int x = q.front().first;
			int y = q.front().second;

			q.pop();
			for (int k = 0; k < 8; k++) {
				int nx = x + dx7562[k];
				int ny = y + dy7562[k];
				if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
					if (dist7562[nx][ny] == -1) {
							q.push(make_pair(nx, ny));
							dist7562[nx][ny] = dist7562[x][y] + 1;
					}
				}
			}//end k
		} //end while

		cout << dist7562[targetX][targetY] << endl;
	}
	return 0;
}