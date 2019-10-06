#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 40001;
struct student {
	int id;  // 考生序号
	int ge;  // GE分数
	int gi;  // GI分数
	int final;  // 最后分数  
	int sch[5];  // 志愿学校
	bool flag;  // 该生是否录取
	int r;
}s[maxn];

struct school {
	int quota;  // 计划招生人数
	int count;  // 已招生人数
	int id[maxn];  // 已录取学生的id
	int last;  // 招生计划的最后一名的id
}sc[101];

int n, m, k;

bool cmp(student a, student b) {
	if (a.final != b.final)
		return a.final > b.final;
	else 
		return a.ge > b.ge;
}

bool cmp2(int a, int b) {
	return s[a].id < s[b].id;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {  // 输入计划招生人数
		scanf("%d", &sc[i].quota);
		sc[i].count = 0;
		sc[i].last = -1;
	}
	for (int i = 0; i < n; i++) {
		s[i].id = i;
		scanf("%d %d", &s[i].ge, &s[i].gi);
		s[i].final = s[i].ge + s[i].gi;  // 计算最后分数
		s[i].flag = false;
		for (int j = 0; j < k; j++)
			scanf("%d", &s[i].sch[j]);
	}
	sort(s, s + n, cmp);  // 排序
	for (int i = 0; i < n; i++) {  // 给考生排名
		if (i > 0 && s[i].final == s[i - 1].final && s[i].ge == s[i - 1].ge)
			s[i].r = s[i - 1].r;
		else
			s[i].r = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int cho = s[i].sch[j];
			int num = sc[cho].count;
			int last = sc[cho].last;
			if (num < sc[cho].quota || (last != -1 && s[i].r == s[last].r)) {
				sc[cho].id[num] = i;  // 录取该生
				sc[cho].last = i;
				sc[cho].count++;
				break;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (sc[i].count > 0) {
			sort(sc[i].id, sc[i].id + sc[i].count, cmp2);  // 按ID排序
			for (int j = 0; j < sc[i].count; j++) {
				printf("%d", s[sc[i].id[j]].id);
				if (j < sc[i].count - 1)
					printf(" ");
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}