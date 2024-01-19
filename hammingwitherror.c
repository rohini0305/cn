#include<stdio.h>
#include<math.h>
int main()
{
	int d[8];
	int code[12];
	int r[4];
	int i,j;
	printf("enter your string:\n");
	for(i=0;i<8;i++)
	{
		scanf("%d",&d[i]);
	}
	r[0]=d[0]^d[1]^d[3]^d[4]^d[6];
	r[1]=d[0]^d[2]^d[3]^d[5]^d[6];
	r[2]=d[1]^d[2]^d[3]^d[7];
	r[3]=d[4]^d[5]^d[6]^d[7];
	int n=0,k=0;
	for(j=0;j<12;j++)
	{
		if((pow(2,n)-1)==j)	
		{
			code[j]=r[n];
			n++;
		}
		else
		{
			code[j]=d[k];
			k++;
		}
	}
	printf("the correct code word is: \n");
	for(i=0;i<12;i++)
	{
		printf("%d",code[i]);
	}
	int a[12];
	int h[4];
	int q[4];
	int pos=0;
	printf("enter your incorrect codeword");
	for(i=0;i<12;i++)
	{`
		scanf("%d",&a[i]);
	}
	h[0]=a[0]^a[2]^a[4]^a[6]^a[8]^a[10];
	h[1]=a[1]^a[2]^a[5]^a[6]^a[9]^a[10];
	h[2]=a[3]^a[4]^a[5]^a[6]^a[11];
	h[3]=a[7]^a[8]^a[9]^a[10]^a[11];
	for(j=0;j<4;j++)
	{
		q[j]=h[j]*pow(2,j);
		pos=pos+q[j];		
	}
	printf("error is in position %d",pos);
}
