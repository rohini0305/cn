#include<stdio.h>
#include<string.h>
void bitStuffing(char data[], char stuffedData[]);
int main() 
{
	int i;
    char data[100], stuffedData[200], unstuffedData[100];
    printf("Enter the binary data: ");
    scanf("%s", data);
    bitStuffing(data, stuffedData);
    printf("Data after bit stuffing with flags: %s\n", stuffedData);
    printf("data after unstuffing:\n");
    for (i = 0; i < strlen(data); i++)
    {
    	printf("%c",data[i]);
	}
    return 0;
}
void bitStuffing(char data[], char stuffedData[]) 
{
    int i, count = 0, j = 0;
    char flag[] = "01111110";
    for (i = 0; i < strlen(flag); i++) 
	{
        stuffedData[j++] = flag[i];
    }

    for (i = 0; i < strlen(data); i++) 
	{
        stuffedData[j++] = data[i];

        if (data[i] == '1') 
		{
            count++;

            if (count == 5) 
			{
                stuffedData[j++] = '0';
                count = 0;
            }
        } else 
		{
            count = 0;
        }
    }
    for (i = 0; i < strlen(flag); i++) 
	{
        stuffedData[j++] = flag[i];
    }
    stuffedData[j] = '\0';
}

void bitUnstuffing(char stuffedData[], char unstuffedData[])
{
    int i, count = 0, j = 0;
    char flag[] = "01111110";
    i = strlen(flag);
    while (i < strlen(stuffedData) - strlen(flag)) 
	{
        if (strncmp(stuffedData + i, flag, strlen(flag)) == 0) 
		{
            i += strlen(flag);
        }
		else 
		{
            unstuffedData[j++] = stuffedData[i++];
            if (stuffedData[i - 1] == '1') 
			{
                count++;

                if (count == 5) 
				{
                    i++;
                    count = 0;
                }
            } else 
			{
                count = 0;
            }
        }
    }

    unstuffedData[j] = '\0';
}
