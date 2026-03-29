// Implementing Application of monte carlo method
// Activity 1:
// a) calculate the value of pi using monte carlo method
// b) calculate the error percentage

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


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define SEED 35791246

int main() {
    int i, iterations;
    int square_point = 0, circle_point = 0;
    double x, y, z;
    double pi, error;
    double trueValueOfPI = 3.141592;

    printf("\nEnter number of iterations: ");
    scanf("%d", &iterations);

    srand(SEED);

    for(i = 0; i < iterations; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        z = x*x + y*y;

        if(z <= 1)
            circle_point++;

        square_point++;
    }

    pi = 4 * ((double)circle_point / square_point);

    error = fabs((trueValueOfPI - pi) / trueValueOfPI) * 100;

    printf("\nEstimated Value of PI = %lf\n", pi);
    printf("True Value of PI = %lf\n", trueValueOfPI);
    printf("Error Percentage = %.4lf%%\n", error);

    return 0;
}