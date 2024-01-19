#include <stdio.h>
int main()
{
	char ch; 
	printf("Enter a character");
	scanf("%c", &ch);
	int i;

	int a = ch;
	printf("\n The ascii value of the ch variable is : %d\n", a);
	int divisor[4] = {1, 0, 0, 1};
	int dividend[20] = {1, 1, 1, 1, 1};
	int divisor_len = sizeof(divisor) / sizeof(int);
	int dividend_len = sizeof(dividend) / sizeof(int);
	printf("dividend_len=%d\n ", dividend_len);
	for (i = 0; i <= divisor_len; i++)
	{
		dividend[dividend_len + 1] = 0;
		dividend_len++;
	}
	for (i = 0; i <= dividend_len; i++)
	{
		printf("%d ", dividend[i]);
	}
	return 0;
}
