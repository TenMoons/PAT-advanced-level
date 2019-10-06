#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100;
struct student {
	char name[11];
	char id[11];
	int grade;
}s[maxn];

bool cmp(student a, student b) {
	return a.grade > b.grade;
}

int main() {
	int n;
	int g1, g2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%s %s %d", s[i].name, s[i].id, &s[i].grade);
	scanf("%d %d", &g1, &g2);  // 输入成绩区间
	sort(s, s + n, cmp);  // 排序
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (s[i].grade >= g1 && s[i].grade <= g2) {
			flag = true;
			printf("%s %s\n", s[i].name, s[i].id);
		}
	}
	if (flag == false)
		printf("NONE\n");
	system("pause");
	return 0;
}