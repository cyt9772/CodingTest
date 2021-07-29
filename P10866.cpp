#include<iostream>

using namespace std;

int P10866() {
	int n;
	string cmd;
	int arg;

	int d[10000] = { 0, };
	int begin = 5000;
	int end = 5000;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if ((cmd == "push_front")|(cmd=="push_back")){
			cin >> arg;
		}

		if (cmd == "push_front") {
			d[begin] = arg;
			if (begin == end) end++;
			begin--;
		}

		if (cmd == "push_back") {
			d[end] = arg;
			if (begin == end) begin--;
			end++;
		}

		if (cmd == "pop_front") {
			if (begin == end) cout << -1 << endl;
			else {
				cout << d[begin+1] << endl;
				begin++;
			}
			if ((end - begin) == 1) end = begin;
		}

		if (cmd == "pop_back") {
			if (begin == end) cout << -1 << endl;
			else {
				cout << d[end-1] << endl;
				end--;
			}
			if ((end - begin) == 1) end = begin;
		}

		if (cmd == "front") {
			if (begin == end) cout << -1 << endl;
			else cout << d[begin + 1] << endl;
		}
		if (cmd == "back") {
			if (begin == end) cout << -1 << endl;
			else cout << d[end-1] << endl;
		}


		if (cmd == "size") {
			if (end == begin) cout << 0 << endl;
			else	cout << end - begin -1 << endl;
		}
		if (cmd == "empty") {
			if (begin == end) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	return 0;
}