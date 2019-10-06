#include<cstdio>
#include<algorithm>
using namespace std;

struct gasStation {
	double pi;  // �ü���վ�ĵ���
	double di;  // �ü���վ�뺼�ݵľ���
}s[510];
const int INF = 1000000000;
bool cmp(gasStation a, gasStation b) {
	return a.di < b.di;
}

int main() {
	int N;
	double Cmax, D, Davg;  // Cmax���������������D��·�̣�Davg��ÿ�������ܵľ��룬N�Ǽ���վ����, need��������Щ������Ҫ���͵�����
	scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf%lf", &s[i].pi, &s[i].di);
	}
	s[N].pi = 0;
	s[N].di = D;
	sort(s, s + N, cmp);  // ������������
	if (s[0].di != 0)
		printf("The maximum travel distance = 0.00\n");  // �޷�����
	else {
		int now = 0;  // ��ǰ�ļ���վ���
		double sum = 0, nowTank = 0;  // �ܻ��ѣ���ǰ����
		double MAX = Cmax * Davg;  // ���������ܵ���Զ·��
		while (now < N) {
			int k = -1;  // ��һվ
			double pmin = INF;
			for (int i = now + 1; i <= N && s[i].di - s[now].di <= MAX; i++) {
				if (s[i].pi < pmin) {  // ѡ���ͼ���͵ļ���վ
					pmin = s[i].pi;
					k = i;
					if (pmin < s[now].pi)  // ����ȵ�ǰ���ͼ۵ͣ���ֱ���ж�ѭ����ǰ���ü���վ
						break;
				}
			}
			if (k == -1) break;  // MAX�������޼���վ
			double need = (s[k].di - s[now].di) / Davg;  // ������һ������վ��Ҫ�õ�����
			if (pmin < s[now].pi) {  // �����վ�۸�ͣ���ֻ�ӵ���k����
				if (nowTank < need) {  // ʣ�����������Ե�����һ������վ������Ҫ�ڵ�ǰվ����
					sum += (need - nowTank) * s[now].pi;
					nowTank = 0;  // ������һ��վ�������ù�
				}
				else
					nowTank -= need;
			}
			else {  // ��վ�۸�ߣ����ڱ�վ����
				sum += (Cmax - nowTank) * s[now].pi;  // ��һվ�ͼ۱ȵ�ǰ�ߣ����ڵ�ǰվ���ͼ���
				nowTank = Cmax - need;
			}
			now = k;  // ���µ�ǰվ�ı��
		}
		if (now == N)  // �������յ�
			printf("%.2f\n", sum);
		else
			printf("The maximum travel distance = %.2f\n", s[now].di + MAX);
	}
	return 0;
}
