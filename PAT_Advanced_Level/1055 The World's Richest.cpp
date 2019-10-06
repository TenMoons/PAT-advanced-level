#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

struct person {
	char name[10];
	int age;
	int worth;
}p[100001];

bool cmp(person a, person b) {
	if (a.worth != b.worth)  // 按资产排序
		return a.worth > b.worth;
	else if (a.age != b.age)
		return a.age < b.age;
	else
		return strcmp(a.name, b.name) < 0;  // 资产相同则按姓名字母表排序
}

int main() {
	int n, k;  // n为总人数，k为查询分类数
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%s %d %d", p[i].name, &p[i].age, &p[i].worth);
	sort(p, p + n, cmp);
	for (int i = 0; i < k; i++) {
		int m, amin, amax;
		scanf("%d %d %d", &m, &amin, &amax);
		printf("Case #%d:\n", i + 1);
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (p[j].age >= amin && p[j].age <= amax) {
				printf("%s %d %d\n", p[j].name, p[j].age, p[j].worth);
				count++;
				if (count == m)
					break;
			}
		}
		if (count == 0)
			printf("None\n");
	}
	system("pause");
	return 0;
}