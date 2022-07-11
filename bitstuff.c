#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
void rec(int msg[],int len);
void send();
int main() {
    send();
}
void send()
{
    int n;
   int result[150];
   
    printf("enter the number of frames to be sent\n");
    scanf("%d",&n);
     int message[n];
    printf("enter the frames value\n");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&message[i]);
    }

    result[0] = 0;
    result[1] = 1;
    result[2] = 1;
    result[3] = 1;
    result[4] = 1;
    result[5] = 1;
    result[6] = 1;
    result[7] = 0;


    int j = 8;
     int count0=0;
    int count1=0;
    int ins0=0;

    for(int i =0;i<n;i++)
    {
        if(message[i]==0)
        {
            result[j++] = message[i];
            count1=0;
            count0=1;
        }
        else 
        {
            if(count1==5 && count0==1)
            {
               result[j++] = 0;
               ins0++;
               result[j++]=message[i];
               count0=0;
               count1=0;
            }
            else{
                result[j++]=message[i];
                count1++;
            }
        }
    }
    result[j++]=0;
	result[j++]=1;
	result[j++]=1;
	result[j++]=1;
	result[j++]=1;
	result[j++]=1;
	result[j++]=1;
	result[j++]=0;
	int l1=16+n+count0;
	printf("The total length is: %d\n",l1);
	printf("The frame is\n");
	for(int i=0;i<j;i++)
	{
		printf("%d",result[i]);
	}	
	

    printf("\n");
    int len = 8+n+ins0;
    printf("length of the frames are %d\n", len);
    printf("\nthe sent frames are ");
    for(int i =0;i<len;i++)
    {
        printf("%d",result[i]);
    }
    rec(result,len);


}
void rec(int msg[],int len)

{
    int j =0;
int result[150];
int count1 = 0;
    for(int i =8;i<len;i++)
    {
        if(msg[i]==1)
        {
           result[j++] = msg[i];
           count1++;
         }
         else 
         {
            if(count1==5)
            {
                i++;
                result[j++] = msg[i];
                count1 = 0;

            }
            else 
            {
                result[j++] = msg[i];
                count1++;
            }
         }
    }
    printf("\nlength of the message is : %d\n ", j);
    printf("\nmessage received is : ");
    for(int i =0;i<j;i++)
    {
        printf("%d",result[i]);
    }
}