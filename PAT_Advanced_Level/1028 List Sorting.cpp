#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct student {
	int id;
	char name[9];
	int grade; 
}stu[100001];

bool cmp1(student a, student b) {  // c=1,∞¥id≈≈–Ú
	return a.id < b.id;
}

bool cmp2(student a, student b) {  // c=2,∞¥–’√˚≈≈–Ú
	int s = strcmp(a.name, b.name);
	if (s != 0)
		return s < 0;
	else 
		return a.id < b.id;
}

bool cmp3(student a, student b) {
	if (a.grade != b.grade)
		return a.grade < b.grade;
	else
		return a.id < b.id;
}

int main() {
	int n, c;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++)
		scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].grade);
	if (c == 1)
		sort(stu, stu + n, cmp1);
	else if (c == 2)
		sort(stu, stu + n, cmp2);
	else 
		sort(stu, stu + n, cmp3);
	for (int i = 0; i < n; i++)
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	system("pause");
	return 0;
}