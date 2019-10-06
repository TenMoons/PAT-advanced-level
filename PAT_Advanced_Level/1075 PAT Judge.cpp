#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 10010;
struct student {
	int id;  // ׼��֤��
	int score[6];  // ÿ��ĵ÷�
	bool flag;  // �Ƿ�����ͨ��������ύ
	int sum;  // �ܷ�
	int ac;  // AC��
}s[maxn];
int n, k, m;
int score[6];

bool cmp(student a, student b) {
	if (a.sum != b.sum)
		return a.sum > b.sum;
	else if (a.ac != b.ac)
		return a.ac > b.ac;
	else
		return a.id < b.id;
}

void init() {
	for (int i = 1; i <= n; i++) {
		s[i].id = i;
		s[i].sum = 0;
		s[i].ac = 0;
		s[i].flag = false;
		memset(s[i].score, -1, sizeof(s[i].score));
	}
}

int main() {
	scanf("%d %d %d", &n, &k, &m);
	init();
	for (int i = 1; i <= k; i++)
		scanf("%d", &score[i]);
	int uid, pid, sc;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &uid, &pid, &sc);
		if (sc != -1)  // ����ͨ��
			s[uid].flag = true;
		if (sc == -1 && s[uid].score[pid] == -1)  // ������󣬸������Ϊ0��
			s[uid].score[pid] = 0;
		if (sc == score[pid] && s[uid].score[pid] < score[pid])
			s[uid].ac++;  // AC����1
		if (sc > s[uid].score[pid])
			s[uid].score[pid] = sc;  // ���¸�����߷���
	}
	for (int i = 1; i <= n; i++)  // �����ܷ�
		for (int j = 1; j <= k; j++)
			if (s[i].score[j] != -1)
				s[i].sum += s[i].score[j];
	sort(s + 1, s + n + 1, cmp);
	int r = 1;
	for (int i = 1; i <= n && s[i].flag == true; i++){
		if (i > 1 && s[i].sum != s[i - 1].sum)
			r = i;
		printf("%d %05d %d", r, s[i].id, s[i].sum);
		for (int j = 1; j <= k; j++) {
			if (s[i].score[j] == -1)
				printf(" -");  // δͨ������
			else
				printf("% d", s[i].score[j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}