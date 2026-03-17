// Implementing Application of monte carlo method
// Activity 1:
// a) calculate the value of pi using monte carlo method
// b) calculate the error percentage
// c) Repeat the experiment for at least five different values of input iterations and tabulate the true value, the experiment's output, and the error percentage for each.



//  Algorithm:
//  1. Initialize circle_points and square_points, interval to zero
//  2. generate random point 'x' (beteeen 0 and 1)
//  3. generate random point 'y (betweeen 0 and 1)
//  4. calculate d = x^2 + y^2
//  5. if d <= 1, increment circle_point.
//  6. increment interval, increment square point
//  7. if increment < No. of interations, repeat from step 2.
//  8. calculate, pi = 4 * (circle_points / square_points) 
//  9. Display the value


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SEED 35791246
#define TRUE_PI 3.14159265358979323846

int main()
{
    int iterations = 0, circle_points = 0, square_points = 0;
    double pi, z, x, y;
    int i = 0;

    printf("Enter the number of iterations to estimate PI: ");
    scanf("%d", &iterations);

    srand(SEED);

    for (i = 0; i < iterations; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;
        z = x * x + y * y;
        if (z <= 1) circle_points++;
        square_points++;
    }

    pi = 4 * (double)circle_points / (double)square_points;
    printf("\nEstimated value of PI : %.8lf\n", pi);
    printf("True value of PI      : %.8lf\n", TRUE_PI);
    printf("Error percentage      : %.6lf%%\n", fabs((pi - TRUE_PI) / TRUE_PI) * 100.0);

    int testCases[] = {100, 1000, 10000, 100000, 1000000, 10000000};
    int n = sizeof(testCases) / sizeof(testCases[0]);

    printf("\n--- Part (c): Experiment Across Multiple Iterations ---\n\n");
    printf("%-15s %-18s %-18s %-12s\n",
           "Iterations", "True Value (PI)", "Estimated PI", "Error (%)");
    printf("%s\n", "---------------------------------------------------------------");

    for (int t = 0; t < n; t++)
    {
        circle_points = 0;
        square_points = 0;

        srand(SEED); 

        for (i = 0; i < testCases[t]; i++)
        {
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;
            z = x * x + y * y;
            if (z <= 1) circle_points++;
            square_points++;
        }

        pi = 4 * (double)circle_points / (double)square_points;
        double error = fabs((pi - TRUE_PI) / TRUE_PI) * 100.0;

        printf("%-15d %-18.8lf %-18.8lf %-12.6lf\n",
               testCases[t], TRUE_PI, pi, error);
    }

    printf("\nObservation: As iterations increase by 10x,\n");
    printf("error decreases by ~sqrt(10) due to O(1/sqrt(N)) convergence.\n");

    return 0;
}

