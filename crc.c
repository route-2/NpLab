#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define N strlen(g)
char t[120],cs[120],g[] = "1101";
int i,f,c;
void xor()
{
    for(c=1;c<N;c++)
    {
        cs[c] = ((cs[c]=g[c])?'0':'1');
    }
}
void crc()
{
    for(i=0;i<N;i++)
    cs[i] = t[i];
   do {
    if(cs[0]=='1')
    xor();
    for(c=0;c<N-1;c++)
    {
        cs[c] = cs[c+1];
    }
    cs[c] = t[i++];
        
    }
    while (i<=f+N-1);
   
    
}
int main()
{
    printf("enter the polynomial to be computed\n");
    scanf("%s",t);
    printf("the generated polynoial is %s \n",g);
    f = strlen(t);// length of the divisor
    for(i=f;i<f+N-1;i++) // traverse thru the polynoial t till 4 + 4-1 which is till 8
    {
        t[i]='0';  // insert 0s in this case 3 zeroes after 
    }
    printf("\nthe modified polynomial is %s \n",t);
    crc();
}