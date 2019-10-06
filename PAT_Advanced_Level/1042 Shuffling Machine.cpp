#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

const int N = 54;
char mp[5] = { 'S', 'H', 'C', 'D', 'J' };  // 牌的编号
int start[N + 1], end[N + 1], next[N + 1];  // start是初始状态，end是变换后的状态，next是要求的变换序列

int main() {
	int K;  // repeat times
	scanf("%d", &K);
	for (int i = 1; i <= N; i++) // 初始化牌的编号
		start[i] = i;
	for (int i = 1; i <= N; i++)  // 变换序列
		scanf("%d", &next[i]);
	while (K-- > 0) {
		for (int i = 1; i <= N; i++)   //变换
			end[next[i]] = start[i];
		for (int i = 1; i <= N; i++)  // 为了下一次重复进行的迭代
			start[i] = end[i];
	}
	for (int i = 1; i <= N; i++) {
		start[i]--;
		if(i != N)
			printf("%c%d ", mp[start[i] / 13], start[i] % 13 + 1);
		else 
			printf("%c%d", mp[start[i] / 13], start[i] % 13 + 1);
	}
	system("pause");
	return 0;
}