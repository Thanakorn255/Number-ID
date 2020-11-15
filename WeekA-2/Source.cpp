#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int sum = 0, a = 0, isnum = 1, checkdigit;
	char str[80], n;
	printf("Number (PIN) Checker :\n\n");
	printf("Enter PIN : ");
	gets_s(str);
	while (str[a]!='\0')
	{
		if ((str[a] < '0') || (str[a] > '9')) isnum = 0;
		a++;
	}
	printf("\nResult : ");
	if ((strlen(str) != 13) || (isnum == 0))
	{
		printf("Incorrect PIN\n");
		return 0;
	}
	for (a = 0;a < 12;a++)
	{
		n = str[a];
		sum = sum + atoi(&n) * (13 - a);
	}
	checkdigit = (11 - sum % 11) % 10;
	n = str[12];
	if (checkdigit == atoi(&n)) printf("Correct PIN\n");
	else printf("Incorrect PIN\n");
	return 0;
}