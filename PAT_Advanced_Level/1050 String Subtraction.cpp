#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

bool Hash[256] = {};

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	memset(Hash, false, sizeof(Hash));
	for (int i = 0; i < s2.length(); i++) {
		Hash[s2[i]] = true;  // ��ĸs2[i]����Ҫ��ɾȥ��
	}
	for (int i = 0; i < s1.length(); i++) {
		if (Hash[s1[i]] == false || s1[i] == ' ')
			printf("%c", s1[i]);
	}
	system("pause");
	return 0;
}