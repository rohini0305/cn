#include<stdio.h>
#include<string.h>
int main()
{
	char str[100],ptr[100],dest[100];
	int i,j=0,count=0,len;
	printf("enter the bits");
	scanf("%s",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		if(str[i]=='1')
		{
			count++;
		}
		else
		{
			count=0;
		}
		dest[j]=str[i];
		j++;
		if(count==5&&str[i+1]=='1')
		{
			dest[j]='0';
			j++;
			count=0;
		}
	}
	dest[j]='\0';
	printf("stuffed data is\n 010101 %s 010101 ",dest);
	len=strlen(dest);
	for(i=0;i<len;i++)
	{
		if(dest[i]=='1')
		{
			count++;
		}
		else
		{
			count=0;
		}
		ptr[j]=dest[i];
		j++;
		if(count==5&&dest[i+1]=='1')
		{
			count=0;
			i++;
		}
	}
	ptr[j]='\0';
	printf("\ndata recieved is %s:",ptr);
}
