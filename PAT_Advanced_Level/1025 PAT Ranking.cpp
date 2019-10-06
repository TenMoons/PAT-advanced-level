#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

struct testee {
	char registration[14];
	int score;
	int local_rank;
	int location_num;
}test[30001];

bool cmp(testee a, testee b) {
	if (a.score != b.score)
		return a.score > b.score;
	else return strcmp(a.registration, b.registration) < 0;  // 同分数的按注册号非降序排列
}

int main() {
	int N;
	int count = 0; // 考生总数
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int K;
		scanf("%d", &K);
		for (int j = 0; j < K; j++) {
			scanf("%s %d", test[count].registration, &test[count].score);
			test[count].location_num = i + 1;
			count++;
		}
		sort(test + count - K, test + count, cmp);  // 对当前考场排序
		test[count - K].local_rank = 1;
		for (int j = count - K + 1; j < count; j++) {
			if (test[j].score == test[j - 1].score)
				test[j].local_rank = test[j - 1].local_rank;
			else
				test[j].local_rank = j + 1 - (count - K);
		}
	}
	printf("%d\n", count);
	sort(test, test + count, cmp);
	int r = 1; // total rank
	for (int i = 0; i < count; i++) {
		if(i > 0 && test[i].score != test[i - 1].score)
			r = i + 1;
		printf("%s ", test[i].registration);
		printf("%d %d %d\n", r, test[i].location_num, test[i].local_rank);
	}
	system("pause");
	return 0;
}