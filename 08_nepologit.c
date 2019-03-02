#include <stdio.h>

int main(void)
{
	int n, x, nepolog = 0;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf("%d", &x);
		if(x>=0)
		{
			nepolog++;
		
		}
	
	}

	printf("%d\n", nepolog);

	return 0;

}
