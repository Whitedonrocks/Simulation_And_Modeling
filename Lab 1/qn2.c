// c) Repeat the experiment for at least five different values of input iterations and tabulate the true value, the experiment's output, and the error percentage for each.

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

        pi[i] = 4 * ((double)circle_point / square_point);
        error[i] = fabs((trueValueOfPI - pi[i]) / trueValueOfPI) * 100;
    }

    printf("\nIterations\tTrue PI\t\tEstimated PI\tError (%%)\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%.6lf\t%.6lf\t%.4lf\n",
               iterations[i], trueValueOfPI, pi[i], error[i]);
    }

    return 0;
}