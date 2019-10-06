#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;


/* 假设A~Z为0~25，a~z为26~51,0~9为52~61，_为62*/


int main() {
	char s1[81], s2[81];
	int count1[63] = { 0 }, count2[63] = { 0 };
	scanf("%s", s1);
	int len1 = strlen(s1);
	scanf("%s", s2);
	int len2 = strlen(s2);
	for (int i = 0; i < len2; i++) {
		int tmp;
		if (s2[i] >= 'A' && s2[i] <= 'Z')
			tmp = s2[i] - 'A';
		else if (s2[i] >= 'a' && s2[i] <= 'z')
			tmp = s2[i] - 'a' + 26;
		else if (s2[i] >= '0' && s2[i] <= '9')
			tmp = s2[i] - '0' + 52;
		else
			tmp = 62;
		count2[tmp]++;
	}
	for (int i = 0; i < len1; i++) {
		int tmp;
		if (s1[i] >= 'A' && s1[i] <= 'Z')
			tmp = s1[i] - 'A';
		else if (s1[i] >= 'a' && s1[i] <= 'z')
			tmp = s1[i] - 'a' + 26;
		else if (s1[i] >= '0' && s1[i] <= '9')
			tmp = s1[i] - '0' + 52;
		else if (s1[i] == '_')
			tmp = 62;
		if (count2[tmp] == 0) {
			if (tmp >= 0 && tmp <= 25 && count1[tmp] == 0) {
				count1[tmp]++;
				printf("%c", 'A' + tmp);
			}
			else if (tmp >= 26 && tmp <= 51 && count1[tmp - 26] == 0) {
				printf("%c", 'A' + tmp - 26);
				count1[tmp - 26]++;
			}
			else if (tmp >= 52 && tmp <= 61 && count1[tmp] == 0) {
				printf("%d", tmp - 52);
				count1[tmp]++;
			}
			else if (tmp == 62 && count1[tmp] == 0) {
				printf("_");
				count1[tmp]++;
			}
		}
	}
	system("pause");
	return 0;
}