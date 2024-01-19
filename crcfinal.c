#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,div_len,msglen;
	char a[100],div[50],temp[50],quot[50],rem[50],b[50];
	printf("Enter dataword=");
	gets(a);
	printf("Enter divisor=");
	gets(div);
	div_len=strlen(div);
	msglen=strlen(a);
	strcpy(b,div);
	for(i=0;i<div_len-1;i++)
	{
		a[msglen+1]='0';
	}
	for(i=0;i<div_len;i++)
	{
		temp[i]=a[i];
	}
	for(i=0;i<msglen;i++)
	{
		quot[i]=temp[0];
		if(quot[i]=='0')
		{
		    for(j=0;j<div_len;j++)
		    {
			  div[j]='0';
		    }
	    }
		else
		{
			for(j=0;j<div_len;j++)
			{
				div[j]=b[j];
			}
		}
		for(j=div_len-1;j>0;j--)
		{
			if(temp[j]==div[j])
			{
				rem[j-1]='0';
			}
			else
			{
				rem[j-1]='1';
			}
		}
		rem[div_len-1]=a[i+div_len];
		strcpy(temp,rem);
	}
	strcpy(rem,temp);
	printf("\nRemainder is=");
	for(i=div_len-1;i>=0;i--)
	{
		printf("%c",rem[i]);
	}
	printf("\ncodeword is=");
	for(i=msglen;i>=0;i--)
	{
		printf("%c",a[i]);
	}
	for(i=div_len-1;i>=0;i--)
	{
		printf("%c",rem[i]);
	}
}
