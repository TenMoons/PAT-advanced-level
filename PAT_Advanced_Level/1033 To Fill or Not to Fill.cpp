#include<cstdio>
#include<algorithm>
using namespace std;

struct gasStation {
	double pi;  // 该加油站的单价
	double di;  // 该加油站与杭州的距离
}s[510];
const int INF = 1000000000;
bool cmp(gasStation a, gasStation b) {
	return a.di < b.di;
}

int main() {
	int N;
	double Cmax, D, Davg;  // Cmax是油箱最大容量，D是路程，Davg是每升油能跑的距离，N是加油站总数, need是跑完这些公里需要的油的升数
	scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf%lf", &s[i].pi, &s[i].di);
	}
	s[N].pi = 0;
	s[N].di = D;
	sort(s, s + N, cmp);  // 按单价升序排
	if (s[0].di != 0)
		printf("The maximum travel distance = 0.00\n");  // 无法出发
	else {
		int now = 0;  // 当前的加油站编号
		double sum = 0, nowTank = 0;  // 总花费，当前油量
		double MAX = Cmax * Davg;  // 加满油能跑的最远路程
		while (now < N) {
			int k = -1;  // 下一站
			double pmin = INF;
			for (int i = now + 1; i <= N && s[i].di - s[now].di <= MAX; i++) {
				if (s[i].pi < pmin) {  // 选出油价最低的加油站
					pmin = s[i].pi;
					k = i;
					if (pmin < s[now].pi)  // 如果比当前的油价低，则直接中断循环，前往该加油站
						break;
				}
			}
			if (k == -1) break;  // MAX距离内无加油站
			double need = (s[k].di - s[now].di) / Davg;  // 到达下一个加油站需要得到油量
			if (pmin < s[now].pi) {  // 如果下站价格低，则只加到达k的油
				if (nowTank < need) {  // 剩余油量不足以到达下一个加油站，则需要在当前站加油
					sum += (need - nowTank) * s[now].pi;
					nowTank = 0;  // 到达下一个站后油量用光
				}
				else
					nowTank -= need;
			}
			else {  // 下站价格高，则在本站加满
				sum += (Cmax - nowTank) * s[now].pi;  // 下一站油价比当前高，则在当前站把油加满
				nowTank = Cmax - need;
			}
			now = k;  // 更新当前站的编号
		}
		if (now == N)  // 到达了终点
			printf("%.2f\n", sum);
		else
			printf("The maximum travel distance = %.2f\n", s[now].di + MAX);
	}
	return 0;
}
