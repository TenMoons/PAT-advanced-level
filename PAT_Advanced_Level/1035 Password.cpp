#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

struct user {
	char name[11];
	char pswd[11];
	bool con = false;
}u[1001];

int main() {
	int N;
	int count = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s %s", u[i].name, u[i].pswd);
		int len = strlen(u[i].pswd);
		int flag = 0;
		for (int j = 0; j < len; j++) {
			if (u[i].pswd[j] == 'l' || u[i].pswd[j] == '1' || u[i].pswd[j] == 'O' || u[i].pswd[j] == '0')
				u[i].con = true;
			if (u[i].pswd[j] == 'l')  // modify
				u[i].pswd[j] = 'L';
			else if (u[i].pswd[j] == '1')
				u[i].pswd[j] = '@';
			else if (u[i].pswd[j] == 'O')
				u[i].pswd[j] = 'o';
			else if (u[i].pswd[j] == '0')
				u[i].pswd[j] = '%';
		}
		if (u[i].con == true) 
			count++;		
	}
	if (N == 1 && count == 0)
		printf("There is 1 account and no account is modified\n");
	else if (count == 0)
		printf("There are %d accounts and no account is modified\n", N);
	else {
		printf("%d\n", count);
		for (int i = 0; i < N; i++) {
			if (u[i].con == true)
				printf("%s %s\n", u[i].name, u[i].pswd);
		}
	}
	system("pause");
	return 0;
}