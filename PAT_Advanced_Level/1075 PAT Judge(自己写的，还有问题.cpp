#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int score[6] = { 0 };  // 每题分值
struct student {
	int id;
	int prosc[6] = { -2, -2, -2, -2, -2, -2 };  // 各题得分
	int sum = 0;  // 总分
	int count = 0;  // AC的题目数
	int count2 = 0;  // 得分的题目数
	int r;  // 排名
}s[100001];

bool cmp(student a, student b) {
	if (a.sum != b.sum)
		return a.sum > b.sum;  // 按总分降序排序
	else if (a.count != b.count)
		return a.count > b.count;  // 若总分相同，则按AC题数降序排序
	else
		return a.id < b.id;  // 若AC数相同，则按id升序排序
}

int main() {
	int n, k, m;  // n为用户数，k为考题数，m为提交数
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= k; i++)
		scanf("%d", &score[i]);
	for (int i = 0; i < m; i++) {
		int uid, proid, pros = 0;
		scanf("%d %d %d", &uid, &proid, &pros);  // 输入用户uid， 提交题号proid，该题分数pros
		s[uid].id = uid;
		if (pros != -1)  //  若本题通过了编译，则提交题数加1
			s[uid].count2++;
		if (pros > s[uid].prosc[proid])  // 该题得分比之前的高，则更新得分
			s[uid].prosc[proid] = pros;
		if (s[uid].prosc[proid] == score[proid])  // AC数加1
			s[uid].count++;
	}
	for (int i = 1; i <= n; i++) {  // 计算总分
		for (int j = 1; j <= k; j++) {
			if(s[i].prosc[j] != -2 && s[i].prosc[j] != -1)
				s[i].sum += s[i].prosc[j];
		}
	}
	sort(s, s + n + 1, cmp);
	s[0].r = 1;
	for (int i = 1; i < n; i++) {  // 划分排名
		if (s[i].sum == s[i - 1].sum)
			s[i].r = s[i - 1].r;
		else
			s[i].r = i + 1;

	}
	for (int i = 0; i < n; i++) {
		if (s[i].count2 != 0) {
			printf("%d %05d %d", s[i].r, s[i].id, s[i].sum);
			for (int j = 1; j <= k; j++) {
				if (s[i].prosc[j] == -2)
					printf(" -");
				else if (s[i].prosc[j] == -1)
					printf(" 0");
				else printf(" %d", s[i].prosc[j]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}