#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 10010;
string s[maxn];

bool cmp(string a, string b) {
	return a + b < b + a;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n, cmp);
	string ans;
	for (int i = 0; i < n; i++)
		ans += s[i];  // 拼接
	while (ans.size() != 0 && ans[0] == '0')
		ans.erase(ans.begin());  // 去掉前导0
	if (ans.size() == 0)
		printf("0\n");
	else
		cout << ans;
	return 0;
}
