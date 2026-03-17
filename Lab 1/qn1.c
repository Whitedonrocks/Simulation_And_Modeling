// Implementing Application of monte carlo method
// Activity 1:
// a) calculate the value of pi using monte carlo method
// b) calculate the error percentage
// c) Repeat the experiment for at least five different values of input iterations and tabulate the true value, the experiment's output, and the error percentage for each.


/*
 Algorithm:
 1. Initialize circle_points and square_points, interval to zero
 2. generate random point 'x' (beteeen 0 and 1)
 3. generate random point 'y (betweeen 0 and 1)
 4. calculate d = x^2 + y^2
 5. if d <= 1, increment circle_point.
 6. increment interval, increment square point
 7. if increment < No. of interations, repeat from step 2.
 8. calculate, pi = 4 * (circle_points / square_points) 
 9. Display the value
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define SEED 35791246

int main() {
    int n, i, j;
    int iterations[100];
    double pi[100], error[100];
    double trueValueOfPI = 3.141592;

    printf("Enter number of different iteration inputs: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter iteration value %d: ", i+1);
        scanf("%d", &iterations[i]);
    }

    srand(SEED);


    for(i = 0; i < n; i++) {
        int square_point = 0, circle_point = 0;
        double x, y, z;

        for(j = 0; j < iterations[i]; j++) {
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;

            z = x*x + y*y;

            if(z <= 1)
                circle_point++;

            square_point++;
        }

        pi[i] = 4 * ((double)circle_point / (double)square_point);
        error[i] = fabs((trueValueOfPI - pi[i]) / trueValueOfPI) * 100;
    }

    printf("\n");
    printf("Iterations\tTrue PI\t\tEstimated PI\tError Percentage\n");
    printf("\n");

    for(i = 0; i < n; i++) {
        printf("%d\t\t%lf\t%lf\t%.2lf\n",
               iterations[i], trueValueOfPI, pi[i], error[i]);
    }

    return 0;
}