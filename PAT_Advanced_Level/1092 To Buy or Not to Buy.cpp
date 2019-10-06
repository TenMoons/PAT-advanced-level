#define _CRT_SECURE_NO_WARNINGS
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

bool hashTable[256];  // 表示珠子是否在想要串中出现
int countn[256];

int main() {
	memset(hashTable, false, sizeof(hashTable));  // 初值为都没有出现过
	char s1[1010];
	int sumn = 0;  // 剩余的和还缺的
	scanf("%s", s1);  // 卖的珠串
	int len1 = strlen(s1);
	for (int i = 0; i < len1; i++) {
		countn[s1[i]]++;  // 统计每个颜色的珠子的数量
	}
	scanf("%s", s1);  // 需要的珠串
	bool flag = true;  // 是否满足
	int len = strlen(s1);
	for (int i = 0; i < len; i++) {  // 遍历s1，判断每一个颜色是否有
		hashTable[s1[i]] = true;  // 表示这个颜色是想要的
		if (countn[s1[i]] == 0) {  // 如果这个颜色摊主没有了
			flag = false;  // 已经不满足题意了
			sumn++; // 缺的珠子数加1
		}
		else
			countn[s1[i]]--;
	}
	if (flag == true)
		printf("Yes %d\n", len1 - len);
	else
		printf("No %d\n", sumn);  // 缺的珠子数
	system("pause");
	return 0;
}