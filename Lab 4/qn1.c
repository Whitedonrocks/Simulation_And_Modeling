// Lab 4: Use KS Test for testing of Uniformity of given set of Data
//     Algorithm for KS test for Uniformity:
// Step1: Define the Hypothesis for Uniformity
// Ho: Ri~U[0,1] The numbers are uniformly distributed
// H1: Ri~U[0,1] The numbers are not uniformly distributed.
// Step2: Arrange the data in increasing order
// R1<=R2<=R3<=…………….<=Rn

// Step3: Compute D+ and D-:
// D+=max{(i/N)- Ri}, 1<=i<=N
// D-=max{(Ri- ((i-1)/N)}, 1<=i<=N
// Step4: Compute calculated D:
// D= max(D+, D-):
// Step5: Determine the for the given critical value i.e Dα (D alpha)
// Step 6: Check the if condition as below:
// if D>D alpha, then reject the null hypothesis Ho.
// else, accept the null hypothesis.

#include <stdio.h>
#include <stdlib.h>

// Function to sort array (Bubble Sort)
void sort(float arr[], int n) {
    int i, j;
    float temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, i;
    float R[100], Dplus[100], Dminus[100];
    float Dplus_max = 0.0, Dminus_max = 0.0, D, Dalpha;

    // Step 1: Input number of random numbers
    printf("Enter number of random numbers (N): ");
    scanf("%d", &N);

    // Step 2: Input random numbers
    printf("Enter %d random numbers (between 0 and 1):\n", N);
    for(i = 0; i < N; i++) {
        scanf("%f", &R[i]);
    }

    // Step 3: Sort the array
    sort(R, N);

    printf("\nSorted Data:\n");
    for(i = 0; i < N; i++) {
        printf("%.2f ", R[i]);
    }

    // Step 4: Calculate D+ and D-
    for(i = 0; i < N; i++) {
        Dplus[i] = ((float)(i + 1) / N) - R[i];
        Dminus[i] = R[i] - ((float)i / N);
    }

    // Step 5: Find D+max and D-max
    for(i = 0; i < N; i++) {
        if(Dplus[i] > Dplus_max)
            Dplus_max = Dplus[i];

        if(Dminus[i] > Dminus_max)
            Dminus_max = Dminus[i];
    }

    // Step 6: Calculate D
    D = (Dplus_max > Dminus_max) ? Dplus_max : Dminus_max;

    // Display results
    printf("\n\nD+ values:\n");
    for(i = 0; i < N; i++) {
        printf("%.3f ", Dplus[i]);
    }

    printf("\nD- values:\n");
    for(i = 0; i < N; i++) {
        printf("%.3f ", Dminus[i]);
    }

    printf("\n\nD+ max = %.3f", Dplus_max);
    printf("\nD- max = %.3f", Dminus_max);
    printf("\nD = %.3f", D);

    // Step 7: Input Dalpha
    printf("\n\nEnter tabulated value (Dalpha): ");
    scanf("%f", &Dalpha);

    // Step 8: Decision
    if(D < Dalpha) {
        printf("\n\nResult: Null Hypothesis[H0] cannot be rejected.\n");
        printf(" Ri~U[0,1] Numbers are uniformly distributed.\n");
    } else {
        printf("\n\nResult: Null Hypothesis[H0] is rejected.\n");
        printf(" Ri~U[0,1] Numbers are NOT uniformly distributed.\n");
    }

    return 0;
}
