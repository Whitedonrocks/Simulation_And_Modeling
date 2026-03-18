// FInding Cycle Length MOdify the above program (activity 1) and find the cycle length once you identify there is present of same random number as given in seed, you have to terminate your program.

// e.g. In activity 1 if you try to generate 20 random number, the number repeat after unique number (2,21,6,26,20,28,7,4,8,13,27,29,16,23,24,2,....) In this case your program should stop generating repeated random numbers.

#include<stdio.h>
#include<math.h>
int main()
{
    int R[100],a,c,m,i=0,n=0;
    printf("\nEnter the value of R[0]:");
    scanf("%d",&R[0]);
    printf("Enter the value of multiplier 'a':");
    scanf("%d",&a);
    printf("Enter the value of increment 'c':");
    scanf("%d",&c);
    printf("Enter the value of modulus 'm':");
    scanf("%d",&m);
    printf("Enter the number of random numbers to generate:");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        R[i]=(a*R[i-1]+c)%m;
    }
    printf("\nThe generated random numbers are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",R[i]);
        if(R[i+1]==R[0])
        {
            printf("\nCycle length is: %d\n",i+1);
            break;
        }
    }
    printf("\n");
    return 0;
}
