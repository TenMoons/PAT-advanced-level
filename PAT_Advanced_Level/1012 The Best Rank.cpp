#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct student {
	int id;
	int grade[4];
}stu[2001];

int Rank[10000000][4] = { 0 };
char course[4] = { 'A', 'C', 'M','E' };
int now;

bool cmp(student a, student b) {
	return a.grade[now] > b.grade[now];
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int flag = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = (stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3]) / 3;  // 平均分
	}
	for (now = 0; now < 4; now++) {
		sort(stu, stu + N, cmp);
		Rank[stu[0].id][now] = 1;  // 排完序，将分数最高的设为第一名
		for (int i = 1; i < N; i++) {
			if (stu[i].grade[now] == stu[i - 1].grade[now])
				Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];  // 同分则排名相同
			else
				Rank[stu[i].id][now] = i + 1;
		}
	}
	int query;
	for (int i = 0; i < M; i++) {
		scanf("%d", &query);
		if (Rank[query][0] == 0) 
			printf("N/A\n");
		else {
			int k = 0;
			for (int j = 0; j < 4; j++) {
				if (Rank[query][j] < Rank[query][k])
					k = j;
			}
			printf("%d %c\n", Rank[query][k], course[k]);
		}
	}
	

	system("pause");
	return 0;
}