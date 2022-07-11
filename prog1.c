#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
void rec();
char frames[1024];
int main()
{
    char buffer[256],temp[10];
    int n;
    printf("enter the number of frames to be sent \n");
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        bzero(buffer,256);
        printf("enter the  frames to be sent %d at index \n" ,(i+1));
        scanf("%s",buffer);
        int len = strlen(buffer);
        printf("the length of the frame is %d\n",len);
        sprintf(temp,"%d",len);
        strcat(frames,temp);
        strcat(frames,buffer);

    }
    rec();
}
void rec()
{
    printf("the frames received is %s\n",frames);
    int frameslen = strlen(frames);
   int i = 0;
   printf("the length of the frame received is %d\n",frameslen);
   printf("frames are as shown below...");
   while(i<frameslen)
   {
       char leninchar = frames[i++];
       int len = (int)leninchar - (int)'0';
       while(i<len)
       {
        printf("%c", frames[i++]);
        len--;
       }
       printf("\n");
   }


}