#include <stdio.h>
void findClassAndNetworkInfo(int ip[4]);
int main() 
{
    int ip[4];
    printf("Enter IP Address (e.g,192.168.1.1): ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    if (ip[0]<0||ip[1]<0||ip[2]<0||ip[3]<0||ip[0]>255||ip[1]>255||ip[2]>255||ip[3]>255) 
	{
        printf("Invalid IP address.\n");
        return 1;
    }
    findClassAndNetworkInfo(ip);
    return 0;
}
void findClassAndNetworkInfo(int ip[4])
 {
	char classIP;
    if(ip[0]>=0&&ip[0]<=127)
	{
        classIP='A';
   	} 
    else if(ip[0]>=128&&ip[0]<=191)
	{
        classIP='B';
   	} 
    else if(ip[0]>=192&&ip[0]<=223)
    {
        classIP='C';
    }
    else if(ip[0]>=224&&ip[0]<=239)
    {
        classIP='D';
	} 
    else if(ip[0]>=240&&ip[0]<=255)
	{
        classIP='E';
    } 
    else 
    {
        classIP='U';  
    }
    printf("IP Class: %c\n", classIP);
    int netID[4]={0};
    int hostID[4]={0};
    switch(classIP)
   	{
        case 'A':
            netID[0] = ip[0];
            hostID[1] = ip[1];
            hostID[2] = ip[2];
            hostID[3] = ip[3];
            break;
        case 'B':
            netID[0] = ip[0];
            netID[1] = ip[1];
            hostID[2] = ip[2];
            hostID[3] = ip[3];
            break;
        case 'C':
            netID[0] = ip[0];
            netID[1] = ip[1];
            netID[2] = ip[2];
            hostID[3] = ip[3];
            break;
    	default:
            printf("Class %c does not have specific network and host IDs.\n", classIP);
            return;
	}
    printf("Network ID: %d.%d.%d.%d\n", netID[0], netID[1], netID[2], netID[3]);
    printf("Host ID: %d.%d.%d.%d\n", hostID[0], hostID[1], hostID[2], hostID[3]);
    if (classIP=='A')
	{
		printf("Default Mask is :255.0.0.0");
	}
	if (classIP=='B')
	{
		printf("Default Mask is :255.255.0.0");
	}
	if (classIP=='C')
	{
		printf("Default Mask is :255.255.255.0");
	}
	if (classIP=='D'||classIP=='E')
	{
		printf("There is No Defaut Mask for class %c",classIP);
	}
}
