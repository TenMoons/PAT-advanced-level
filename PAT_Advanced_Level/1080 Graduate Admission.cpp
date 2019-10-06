#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 40001;
struct student {
	int id;  // �������
	int ge;  // GE����
	int gi;  // GI����
	int final;  // ������  
	int sch[5];  // ־ԸѧУ
	bool flag;  // �����Ƿ�¼ȡ
	int r;
}s[maxn];

struct school {
	int quota;  // �ƻ���������
	int count;  // ����������
	int id[maxn];  // ��¼ȡѧ����id
	int last;  // �����ƻ������һ����id
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
	for (int i = 0; i < m; i++) {  // ����ƻ���������
		scanf("%d", &sc[i].quota);
		sc[i].count = 0;
		sc[i].last = -1;
	}
	for (int i = 0; i < n; i++) {
		s[i].id = i;
		scanf("%d %d", &s[i].ge, &s[i].gi);
		s[i].final = s[i].ge + s[i].gi;  // ����������
		s[i].flag = false;
		for (int j = 0; j < k; j++)
			scanf("%d", &s[i].sch[j]);
	}
	sort(s, s + n, cmp);  // ����
	for (int i = 0; i < n; i++) {  // ����������
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
				sc[cho].id[num] = i;  // ¼ȡ����
				sc[cho].last = i;
				sc[cho].count++;
				break;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (sc[i].count > 0) {
			sort(sc[i].id, sc[i].id + sc[i].count, cmp2);  // ��ID����
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