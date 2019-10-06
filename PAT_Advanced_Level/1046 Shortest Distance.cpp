#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

const int MAX = 1000001;
int exits[MAX] = { 0 };  // array of exit
int dist[MAX] = { 0 };  // array of distance, dist[i] means the distance between exit[i] and exit[1]
int sum = 0;

int main() {
	int N;  // the number of exits
	int M;  // the number of QUERY
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {  // input
		scanf("%d", &exits[i]);
		sum += exits[i];
		dist[i] = sum;
		}
	scanf("%d", &M);
	int left, right;
	while (M-- > 0) {
		scanf("%d %d", &left, &right);
		if (left > right)   // exchange left and right to ensure right > left
			swap(left, right);		
		int temp = dist[right - 1] - dist[left - 1];
		printf("%d\n", min(temp, sum - temp));
	}
	system("pause");
	return 0;
}