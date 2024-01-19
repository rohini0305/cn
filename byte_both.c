#include <stdio.h>
int main()
{
	char data[100],sdata[100],rdata[100],rrdata[100];
	int i=0,j=1;
	printf ("$ is Flag and @ is Escape Character.\n");
	printf ("Enter the Message : ");
	scanf ("%s",&data);
	sdata[0]='$';
	while (data[i]!='\0')
	{
		if (data[i]=='$'||data[i]=='@')
		{
			sdata[j]='@';
			j++;
			sdata[j]=data[i];
		}
		else
		{
			sdata[j]=data[i];
		}
		i++;
		j++;
	}
	sdata[j]='$';
	sdata[j+1]='\0';
	printf ("Sending data .... %s",sdata);

	i=0;
	printf ("\n\n");
	while (sdata[i]!='\0')
	{
		rdata[i]=sdata[i];
		i++;
	}
	rdata[i]='\0';
	i=0;

	for(j=1;rdata[j]!='\0';j++)
	{
		if (rdata[j]=='@')
		{
			j++;
			rrdata[i]=rdata[j];
		}
		else if (rdata[j]=='$')
		{
			rrdata[i]=rdata[j+1];
		}
		else
		{
			rrdata[i]=rdata[j];
		}
	i++;

	}

	printf ("\nReceiving Data .... %s\n",rrdata);
}
