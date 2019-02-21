#include <stdio.h>
#include <math.h>
#include <limits.h>

int main (void) 
{
	int a, b, z;

	scanf("%d%d", &a, &b);

	z = pow(a, b);

	if (z > INT_MAX) 
	{
		puts("z > INT_MAX");
	} 
	else 
	{
		printf("%d\n", z);
		
	}

	return 0;


}
