#include<iostream>

using namespace std;

int P10845() {
	int n;
	string cmd;
	int arg;

	int d[10000] = { 0, };
	int begin = 0;
	int end = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> arg;
		}

		if (cmd == "push") {
			d[end] = arg;
			end++;
		}

		if (cmd == "front") {
			if (begin == end) cout << -1 << endl;
			else cout << d[begin] << endl;
		}
		if (cmd == "back") {
			if (begin == end) cout << -1 << endl;
			else cout << d[end-1] << endl;
		}
		if (cmd == "size") {
			cout << end-begin << endl;
		}
		if (cmd == "empty") {
			if (begin == end) cout << 1 << endl;
			else cout << 0 << endl;
		}
		if (cmd == "pop") {
			if (begin == end) cout << -1 << endl;
			else {
				cout << d[begin] << endl;
				begin++;
			}
		}
	}
	return 0;
}