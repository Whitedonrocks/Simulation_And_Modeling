// Apply all LCM (Additive, Multiplicative, Mixed) based on the input values of a and c (determine the type and generate the random number based on that.) In this case you can provide a choice to user which method they want to choose. Based on the choice you should apply the respective formulas.

#include<stdio.h>
#include<math.h>
int main()
{
    int R[100],a=0,c=0,m,i=0,n=0,choice;
    printf("\nEnter the value of R[0]:");
    scanf("%d",&R[0]);
    printf("Enter the value of modulus 'm':");
    scanf("%d",&m);
    printf("Enter the number of random numbers to generate:");
    scanf("%d",&n);
    printf("Choose the method to generate random numbers:\n1. Additive\n2. Multiplicative\n3. Mixed\n");
    scanf("%d",&choice);

    switch(choice) {
        case 1:
            printf("Enter the value of increment 'c':");
            scanf("%d",&c);
            break;
        case 2:
            printf("Enter the value of multiplier 'a':");
            scanf("%d",&a);
            break;
        case 3:
            printf("Enter the value of multiplier 'a':");
            scanf("%d",&a);
            printf("Enter the value of increment 'c':");
            scanf("%d",&c);
            break;
        default:
            printf("Invalid choice! Exiting.\n");
            return 1;
    }

    for(i=1;i<=n;i++)
    {
        switch(choice) {
            case 1: // Additive
                R[i] = (R[i-1] + c) % m;
                break;
            case 2: // Multiplicative
                R[i] = (a * R[i-1]) % m;
                break;
            case 3: // Mixed
                R[i] = (a * R[i-1] + c) % m;
                break;
        }
    }
    
    printf("\nThe generated random numbers are:\n");
    for(i=0;i<=n;i++)
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