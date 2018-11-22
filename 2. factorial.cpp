#include <stdio.h>
#include <Windows.h>

int fact(int);

void main() {
	system("color F0");
	int i;
	for (i = 1; i < 6; i++) {
		if(i<5)
			printf("%d!=%d\n", i, fact(i));
		else printf("fact(%d)=%d\n", i, fact(i));
	}
}

int fact(int n) {
	if (n <= 1)
		return 1;
	else
		return n * fact(n - 1);
}