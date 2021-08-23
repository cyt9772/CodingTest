#include<iostream>
#include<queue>

using namespace std;

#define MAX13913 200000

bool visited13913[MAX13913 + 1];
int dist13913[ MAX13913 + 1 ];
queue<int> q13913;
int v13913[MAX13913 + 1];


void bfs13913( int p, int n, int d) { //p는 이전 now, n은 next, d는 거리
	q13913.push(n);
	visited13913[n] = true;
	dist13913[n] = d + 1;
	v13913[n] = p;  //next는 now로 부터 전달
}


void print13913(int start, int target)
{
	if (start != target)
		print13913(start, v13913[target]);
	cout << target << " ";
}

int P13913() {
	int s, t; //s: start, t: target
	cin >> s >> t;

	visited13913[s] = true;
	dist13913[s] = 0;
	q13913.push(s);

	while (!q13913.empty()) {
		int now = q13913.front();
		q13913.pop();

		int next = now - 1;
		if (next >= 0 && visited13913[next]==false)
			bfs13913(now, next, dist13913[now]);

		next = now + 1;
		if (next < MAX13913 && visited13913[next] == false)
			bfs13913(now, next, dist13913[now]);

		next = now *2;
		if (next < MAX13913 && visited13913[next] == false)
			bfs13913(now, next, dist13913[now]);
	}

	cout << dist13913[t] << endl;

	print13913(s, t);

	return 0;
}

