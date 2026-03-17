// Use monte carlo method to calcuate the probability of getting 3 ,6 or 9 heads in tossing of coin 10 times.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 int main()
 {
     int j,count=0, limit, i=0,head, tail;
     float y, answer, h=2.5;
        printf("Enter the number of iterations: ");
        scanf("%d", &limit);
        while(i<=limit)
        {
            i++;
            head=0;
            tail=0;
            for(j=0; j<10; j++)
            {
                y=(float)((rand()%65535)/65535.0f)*10;
                if(y<h)
                {
                    head++;
                }
                else
                {
                    tail++;
                }
            }
            if(head==3 || head==6 || head==9)
            {
                count++;
            }
        }
            answer=(float)count/limit;
            
            // Theoretical probability: P(3 heads) + P(6 heads) + P(9 heads)
            // Using binomial: C(10,3)*0.5^10 + C(10,6)*0.5^10 + C(10,9)*0.5^10
            double theoretical = (120.0 + 210.0 + 10.0) / 1024.0;  // (C(10,3) + C(10,6) + C(10,9)) / 2^10
            
            // Calculate error percentage
            double error = fabs((answer - theoretical) / theoretical) * 100.0;
            
            printf("The limit is %d\n", limit);
            printf("Experimental probability: %f\n", answer);
            printf("Theoretical probability: %f\n", theoretical);
            printf("Error percentage: %f%%\n", error);
    return 0;
}