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
				num++;//统计单词总数num
	cout << "单词总数为："<<num << endl;
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
	cout << "每个单词的长度为：" << endl;
	for (auto p = words.begin(); p != words.end(); p++) {
		cout << (*p).size() << endl;
	    }
	sort(words.begin(), words.end());
	cout << "最长的单词是：" << lw << endl << "其长度为：" << max << endl;
	cout << "所有单词按序输出：" << endl;
	for (const string& w : words)
		cout << w << endl;
	return 0;
	}
	
	
	
	//for (j = 0; j < s.size(); j++) {
		//if(s[j]==' ')
		//string v = s.substr(1, j);
		//	}