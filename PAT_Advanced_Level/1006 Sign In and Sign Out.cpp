#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>

struct person {
	char id[16];  // id number
	int inh, inm, ins, outh, outm, outs;  // sign in and sign out time 
}tmp, unlock, lock;

bool earlier(person a, person b) {
	if (a.inh == b.inh) {
		if (a.inm == b.inm)
			return a.ins <= b.ins;
		else
			return a.inm <= b.inm;
	}
	else
		return a.inh <= b.inh;
}

bool later(person a, person b) {
	if (a.outh == b.outh) {
		if (a.outm == b.outm) 
			return a.outs >= b.outs;
		else return a.outm >= b.outm;
	}
	else
		return a.outh >= b.outh;
}

void init() {
	unlock.inh = 23;
	unlock.inm = unlock.ins = 59;
	lock.outh = lock.outm = lock.outs = 0;
}

int main() {
	init();
	int n;
	scanf("%d", &n);
	while (n-- > 0) {
		scanf("%s %d:%d:%d %d:%d:%d", &tmp.id, &tmp.inh, &tmp.inm, &tmp.ins, &tmp.outh, &tmp.outm, &tmp.outs);
		if (earlier(tmp, unlock))
			unlock = tmp;
		if (later(tmp, lock))
			lock = tmp;
	}
	printf("%s %s", unlock.id, lock.id);
	system("pause");
	return 0;
}