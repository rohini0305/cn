#include<stdio.h>
int main()
{
	char str[100];
	char dest[100];
	int i=0,j=0;
	printf("enter the message you wanna send\n");
	scanf("%s",str);
	dest[j]='$';
	j++;
	while(str[i]!='\0')
	{
		if(str[i]=='@'||str[i]=='#'||str[i]=='$'||str[i]=='&')
		{
			dest[j]='@';
			j++;
		}
			dest[j++]=str[i++];
	}
	dest[j++]='$';
	dest[j]='\0';
	printf("the msg after stuffing is %s",dest);
	return 0;
}
