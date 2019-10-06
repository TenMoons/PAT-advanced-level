#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct stu {
	char sno[9];  // 准考证号
	int dg;  // 德分
	int cg;  // 才分
	int sum = 0;  // 总分
	int flag;  // 考生类别
}student[100001];
int N, L, H;  // N:考生总数 L：录取最低分数线 H：优录分数线

bool cmp(stu a, stu b) {
	if (a.flag != b.flag)
		return a.flag < b.flag;  // 类别小者优先
	else if (a.sum != b.sum)
		return a.sum > b.sum;  // 类别相同，总分大者优先
	else if (a.dg != b.dg)
		return a.dg > b.dg;  // 类别相同且总分相同，德分高者优先
	else
		return strcmp(a.sno, b.sno) < 0;  // 类别相同且总分相同且德分相同，准考证号小者优先

}

int main() {
	scanf("%d %d %d", &N, &L, &H);
	int count = N;  // 达到最低分数线的考生人数
	for (int i = 0; i < N; i++) {
		scanf("%s %d %d", student[i].sno, &student[i].dg, &student[i].cg);
		student[i].sum = student[i].cg + student[i].dg;  // 德才总分
		if (student[i].dg < L || student[i].cg < L) {
			count--;  // 录取人数加一
			student[i].flag = 5;  // 未录取考生
		}

		// 给录取考生分类
		else if (student[i].cg >= H && student[i].dg >= H)
			student[i].flag = 1;  // 一类考生
		else if (student[i].dg >= H && student[i].cg < H)
			student[i].flag = 2;  // 二类考生
		else if (student[i].dg < H && student[i].cg < H && student[i].dg >= student[i].cg)
			student[i].flag = 3;  // 三类考生
		else
			student[i].flag = 4;  // 四类考生
	}
	sort(student, student + N, cmp);
	printf("%d\n", count);
	for (int i = 0; i < count; i++)
		printf("%s %d %d\n", student[i].sno, student[i].dg, student[i].cg);
	system("pause");
	return 0;
}