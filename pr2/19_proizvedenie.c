#include <stdio.h>

int main (void)
{
	int n, x = 0;
	int proizved = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &x);
		proizved = proizved * x;
	}

	printf("%d\n", proizved);

	return 0;

}
