#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	string s;
	getline(cin, s);
	int num = 1,i=0,j;
	char t = ' ';
		for(char ch : s)
			if (ch == t) 
				num++;//ͳ�Ƶ�������num
	cout << "��������Ϊ��"<<num << endl;
	string w,lw;
	vector<string>words;
	for (char c : s) {
		if (c == ' '|| c == '.' || c == '!' || c == '?') {
			words.push_back(w);
			w.clear();
		} 
		else {
			w += c;
		}
		}
	int max=0;
	for (const string& w : words) {
		if (w.size() > max) {
			max = w.size();
			lw = w;
		}
	}
	cout << "ÿ�����ʵĳ���Ϊ��" << endl;
	for (auto p = words.begin(); p != words.end(); p++) {
		cout << (*p).size() << endl;
	    }
	sort(words.begin(), words.end());
	cout << "��ĵ����ǣ�" << lw << endl << "�䳤��Ϊ��" << max << endl;
	cout << "���е��ʰ��������" << endl;
	for (const string& w : words)
		cout << w << endl;
	return 0;
	}
	
	
	
	//for (j = 0; j < s.size(); j++) {
		//if(s[j]==' ')
		//string v = s.substr(1, j);
		//	}