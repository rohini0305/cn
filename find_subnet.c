#include <stdio.h>
#include <math.h>
void get_ip(int ip[4])
{
    printf("Enter ip adderss:");
    scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);
    printf("Your ip address is:%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}
void calculate_no_ip(int ip[4], int firstadd[4], int lastadd[4], int *noadd)
{
	int i;
	
    if (ip[0] >= 0 && ip[0] <= 127)
    {
        printf("\nIt is class A");
        int subclassA[4] = {255, 0, 0, 0};
        for (i = 0; i < 4; i++)
        {
            firstadd[i] = subclassA[i] & ip[i];
        }
        int lclassA[4] = {0, 0, 0, 255};
        for ( i = 0; i < 4; i++)
        {
            lastadd[i] = lclassA[i] | ip[i];
        }
        int n = 8;
        *noadd = (pow(2, (32 - n)));
    }
    else if (ip[0] >= 128 && ip[0] <= 191)
    {
        printf("\nIt is class B");
        int subclassB[4] = {255, 255, 0, 0};
        for ( i = 0; i < 4; i++)
        {
            firstadd[i] = subclassB[i] & ip[i];
        }
        int lclassB[4] = {0, 0, 255, 255};
        for ( i = 0; i < 4; i++)
        {
            lastadd[i] = lclassB[i] | ip[i];
        }
        int n = 16;
        *noadd = (pow(2, (32 - n)));
    }
    else if (ip[0] >= 192 && ip[0] <= 223)
    {
        printf("\nIt is class C");
        int subclassC[4] = {255, 255, 255, 0};
        for ( i = 0; i < 4; i++)
        {
            firstadd[i] = subclassC[i] & ip[i];
        }
        int lclassC[4] = {0, 0, 0, 255};
        for ( i = 0; i < 4; i++)
        {
            lastadd[i] = lclassC[i] | ip[i];
        }
        int n = 24;
        *noadd = (pow(2, (32 - n)));
    }
}
int main()
{
    int ip[4], firstadd[4], lastadd[4], noadd;
    get_ip(ip);
    calculate_no_ip(ip, firstadd, lastadd, &noadd);
    printf("\nFrist address is:%d.%d.%d.%d", firstadd[0], firstadd[1], firstadd[2], firstadd[3]);
    printf("\nThe total number address:%d", noadd);
    printf("\nLast address is:%d.%d.%d.%d", lastadd[0], lastadd[1], lastadd[2], lastadd[3]);

    return 0;
}
