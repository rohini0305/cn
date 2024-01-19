#include <stdio.h>
#include<stdlib.h>
int bi(int num)
{
    int binary = 0, temp = 1, rem;
    while (num > 0)
    {
        rem = num % 2;
        num = num / 2;
        binary = binary + temp * rem;
        temp *= 10;
    }
    return binary;
}
int dec(int num)
{
    int dv = 0, rem, temp=1;
    while (num > 0)
    {
        rem = num % 10;
        dv = dv + rem * temp;
        num = num / 10;
        temp *= 2;
    }
    return dv;
}
void main()
{
    int ch, n1, n2, n3, n4;
    while (1)
    {
        printf("\n1.Decimal to binary\n");
        printf("2.Binary to Decimal\n");
        printf("3.exit");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Decimal IP address:");
            scanf("%d.%d.%d.%d", &n1, &n2, &n3, &n4);
            if (n1 <= 255 && n2 <= 255 && n3 <= 255 && n4 <= 255)
            {
                n1 = bi(n1);
                n2 = bi(n2);
                n3 = bi(n3);
                n4 = bi(n4);
                printf("The binary IP adrress is:%d %d %d %d", n1, n2, n3, n4);
            }
            else
            {
                printf("Ip adrres is wrong!");
            }
            break;
        case 2:
            printf("Enter Decimal IP address:");
            scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
            n1 = dec(n1);
            n2 = dec(n2);
            n3 = dec(n3);
            n4 = dec(n4);
            printf("The decimal IP adrress is:%d.%d.%d.%d", n1, n2, n3, n4);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Enter valid choice");
        }
    }
}