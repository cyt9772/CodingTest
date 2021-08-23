#include<iostream>
#include<queue>

using namespace std;

#define MAX 200000

bool visited1697[MAX + 1];
int dist1697[ MAX + 1 ];
queue<int> q1697;

void bfs1697( int n, int d) {
	q1697.push(n);
	visited1697[n] = true;
	dist1697[n] = d + 1;
}

int P1697() {
	int s, t; //s: start, t: target
	cin >> s >> t;

	visited1697[s] = true;
	dist1697[s] = 0;
	q1697.push(s);

	while (!q1697.empty()) {
		int now = q1697.front();
		q1697.pop();

		int next = now - 1;
		if (next >= 0 && visited1697[next]==false)
			bfs1697(next, dist1697[now]);

		next = now + 1;
		if (next < MAX && visited1697[next] == false)
			bfs1697(next, dist1697[now]);

		next = now *2;
		if (next < MAX && visited1697[next] == false)
			bfs1697(next, dist1697[now]);
	}

	cout << dist1697[t] << endl;

	return 0;
}

