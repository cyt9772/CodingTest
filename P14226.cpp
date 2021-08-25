#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int state14226[1001][1001]; //걸리는 시간

//1.화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다./
//2.클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
//3.화면에 있는 이모티콘 중 하나를 삭제한다


int P14226(int param) {
	//화면에 표시하려는 이모티콘의 개수
	int n;
	n = param;
//	cin >> n;

	//state 초기화
	memset(state14226, -1, sizeof(state14226));

	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));  //초기 화면에는 1개

	state14226[1][0] = 0; //초기 시간은 0

	while (!q.empty()) {
		int s, c; //s는 화면에 표시되는 이모티콘 개수, c는 클립보드의 이모티콘 개수
		tie(s, c) = q.front();
		q.pop();
		
		//1.화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
		if (state14226[s][s] == -1)  //모두 복사하면 클립보드 덮어쓰기이고, 방문한 적이 없어야 함.
		{
			state14226[s][s] = state14226[s][c] + 1; //시간은 현재 time +1
			q.push(make_pair(s, s)); //q에 push
		}

		//2.클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
		//기존 화면의 개수에 클립보드의 개수 추가 && 추가된 개수가 n보다 작거나 같아야 함
		if ((s + c) <= n )
		{
			if (state14226[s + c][c] == -1) {
				state14226[s + c][c] = state14226[s][c] + 1; //시간은 현재 time +1
				q.push(make_pair(s + c, c)); //q에 push
			}
		}

		//3.화면에 있는 이모티콘 중 하나를 삭제한다
		//현재 화면의 개수 -1, 클립보드는 그대로, 
		if (state14226[s -1][c] == -1 && (s -1) >= 0)
		{
			state14226[s -1][c] = state14226[s][c] + 1; //시간은 현재 time +1
			q.push(make_pair(s -1, c)); //q에 push
		}
	}

	int ans = 1000*1000;
	for (int i = 0; i <= n; i++) {
		if (state14226[n][i] != -1) //방문한 적이 있다면
		{
			ans = min(ans, state14226[n][i]);
		}
	}

	cout << ans << endl;
	return 0;
}
