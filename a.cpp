#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;


int getSeconds(string time) {
	int H = stoi(time.substr(0, 2));
	int M = stoi(time.substr(3, 2));
	int S = stoi(time.substr(6, 2));
	int total_time = S + (M * 60) + (H * 60 * 60);
	return total_time;
}

string getString(int time) {
	return (time < 10) ? "0" + to_string(time) : to_string(time);
}

string getTimeFormat(int time) {
	int H = time / 3600;
	time %= 3600;
	int M = time / 60;
	time %= 60;
	int S = time;
	string hr = getString(H);
	string min = getString(M);
	string sec = getString(S);
	return hr + ":" + min + ":" + sec;
}

bool isValid(string time) {
	map<char,int> m;
	for(char ch : time) {
		if(ch == ':') continue;
		m[ch]++;
	}
	return m.size() <= 2; 
}

int main() {
	string s = "00:59:09";
	string t = "01:01:11";
	int timeS = getSeconds(s);
	int timeT = getSeconds(t);
	if(timeS < timeT) swap(timeS, timeT);
	int answer = 0;

	for(int time = timeT; time <= timeS; time++) {
		string timestamp = getTimeFormat(time);
		cout << timestamp << endl;
		if(isValid(timestamp)) {
			answer++;
		}
	}
	cout << "answer : " << answer << endl;
	return 0;
}
