#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int state14226[1001][1001]; //�ɸ��� �ð�

//1.ȭ�鿡 �ִ� �̸�Ƽ���� ��� �����ؼ� Ŭ�����忡 �����Ѵ�./
//2.Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ� �Ѵ�.
//3.ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� �����Ѵ�


int P14226(int param) {
	//ȭ�鿡 ǥ���Ϸ��� �̸�Ƽ���� ����
	int n;
	n = param;
//	cin >> n;

	//state �ʱ�ȭ
	memset(state14226, -1, sizeof(state14226));

	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));  //�ʱ� ȭ�鿡�� 1��

	state14226[1][0] = 0; //�ʱ� �ð��� 0

	while (!q.empty()) {
		int s, c; //s�� ȭ�鿡 ǥ�õǴ� �̸�Ƽ�� ����, c�� Ŭ�������� �̸�Ƽ�� ����
		tie(s, c) = q.front();
		q.pop();
		
		//1.ȭ�鿡 �ִ� �̸�Ƽ���� ��� �����ؼ� Ŭ�����忡 �����Ѵ�.
		if (state14226[s][s] == -1)  //��� �����ϸ� Ŭ������ ������̰�, �湮�� ���� ����� ��.
		{
			state14226[s][s] = state14226[s][c] + 1; //�ð��� ���� time +1
			q.push(make_pair(s, s)); //q�� push
		}

		//2.Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ� �Ѵ�.
		//���� ȭ���� ������ Ŭ�������� ���� �߰� && �߰��� ������ n���� �۰ų� ���ƾ� ��
		if ((s + c) <= n )
		{
			if (state14226[s + c][c] == -1) {
				state14226[s + c][c] = state14226[s][c] + 1; //�ð��� ���� time +1
				q.push(make_pair(s + c, c)); //q�� push
			}
		}

		//3.ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� �����Ѵ�
		//���� ȭ���� ���� -1, Ŭ������� �״��, 
		if (state14226[s -1][c] == -1 && (s -1) >= 0)
		{
			state14226[s -1][c] = state14226[s][c] + 1; //�ð��� ���� time +1
			q.push(make_pair(s -1, c)); //q�� push
		}
	}

	int ans = 1000*1000;
	for (int i = 0; i <= n; i++) {
		if (state14226[n][i] != -1) //�湮�� ���� �ִٸ�
		{
			ans = min(ans, state14226[n][i]);
		}
	}

	cout << ans << endl;
	return 0;
}
