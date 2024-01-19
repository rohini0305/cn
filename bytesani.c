#include<stdio.h>
int main()
{
    int size, i, k;
    char flag, esc;
    printf("Enter your size of string:\n");
    scanf("%d",&size);
    char a[size];
    char code[size*2];
    printf("Enter your flag:\n");
    scanf(" %c",&flag);
    printf("Enter your escape character:\n");
    scanf(" %c",&esc);
    printf("Enter your string:\n");
    scanf("%s",a);
    printf("Encoded string: ");
    printf("%c",flag);
    for (i=0,k=0;a[i]!='\0';i++,k++)
    {
        if(a[i]=='@'||a[i]=='#'||a[i]=='$')
        {
            code[k]=esc;
            k=k+1;
            code[k]=a[i];
        }
        else if (a[i]==esc)
        {
            code[k]=esc;
            k = k + 1;
            code[k]=a[i];
        }
        else
        {
            code[k]=a[i];
        }
    }
    for(i=0;i<=k;i++)
    {
        printf("%c",code[i]);
    }
    printf("%c\n",flag);
    printf("code after unstuffing");
    for(i=0;i<size;i++)
    {
    	printf("\n%c",a[i]);
	}
    return 0;
}

