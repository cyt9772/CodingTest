#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> inputData;
int printData[6];
bool checked[50];

void go(int idx, int cnt){
	if(cnt==6){ //6개를 다 찾음
		for(int i=0;i<6;i++){
			cout<<printData[i]<<" ";
		}
		cout<<endl;
		return;
	}

	for(int i=idx;i<inputData.size();i++){
		if(checked[i]) continue;
		checked[i]=true;
		printData[cnt]=inputData[i];
		go(i+1, cnt+1);
		checked[i]=false;
	}
}

int main() {
	while(true){
		int count=0, temp=0;
		cin>>count;
		if(count==0)
			break;
		for(int i=0;i<count;i++){
			cin>>temp;
			inputData.push_back(temp);
		}
		go(0,0);
		cout<<endl;
		
		//초기화
		inputData.clear();
		inputData.shrink_to_fit();
		for(int i=0;i<50;i++){
			checked[i]=false;
		}

	}
	return 0;
}