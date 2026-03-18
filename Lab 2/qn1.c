// Use Linear Congruential Method (LCM) to generate random numbers. Write A C program to generate random numbers.
// Your Program should ask for user input like how many digits, how many random numbers, initial value (RO),constant values: a and c
// Then calculate the Random number using Ri+1=(a*Ri+c) mod m where m should be determined based on the number of digits.
// Use : a=9 , c=3, m=31, R0=2
// and : {2,21,6,26,20,28,7,4,8}

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
    for(i=1;i<=n;i++)
    {
        R[i]=(a*R[i-1]+c)%m;
    }
    printf("\nThe generated random numbers are:\n");
    for(i=0;i<=n;i++)
    {
        printf("%d ",R[i]);
    }
    printf("\n");
    return 0;
}