// Modify the above program ans ask user to input N floating point numbers between 0.00 and 1.00 individually. Determine in which interval the given number lies and calcualte the Chi value.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int k, n = 100;
    float nums[100];
    float observed[20] = {0};
    float expected, chi_square = 0.0;
    float tabulated;
    int i, j;

    srand(time(0));

    printf("\n100 Generated Random Numbers:\n");
    for (i = 0; i < n; i++) {
        nums[i] = (float)rand() / RAND_MAX;
        printf("%.4f    ", nums[i]);
        if ((i + 1) % 5 == 0) printf("\n");
    }

    printf("\nEnter number of intervals (k): ");
    scanf("%d", &k);

    printf("Enter tabulated chi-square value: ");
    scanf("%f", &tabulated);

    float groups[20][100];
    int   count[20] = {0};

    for (i = 0; i < n; i++) {
        j = (int)(nums[i] * k);
        if (j == k) j = k - 1;
        observed[j]++;
        groups[j][count[j]++] = nums[i];
    }

    printf("\n%-12s %-16s %s\n", "Interval", "Range", "Numbers");
    printf("----------------------------------------------------------------------\n");
    for (i = 0; i < k; i++) {
        printf("%-12d (%.2f - %.2f)   ", i + 1, (float)i / k, (float)(i + 1) / k);
        for (j = 0; j < count[i]; j++)
            printf("%.4f  ", groups[i][j]);
        printf("\n");
    }

    expected = (float)n / k;

    printf("\n%-12s %-12s %-12s %-12s\n", "Interval", "Observed", "Expected", "(O-E)^2/E");
    printf("-------------------------------------------------------\n");

    for (i = 0; i < k; i++) {
        float diff = observed[i] - expected;
        float chi_i = (diff * diff) / expected;
        chi_square += chi_i;
        printf("%-12d %-12.0f %-12.2f %-12.4f\n", i + 1, observed[i], expected, chi_i);
    }

    printf("-------------------------------------------------------\n\n");

    int df = k - 1;
    printf("H0 : Numbers are uniformly distributed\n");
    printf("H1 : Numbers are NOT uniformly distributed\n\n");
    printf("Degrees of freedom    : %d\n", df);
    printf("Tabulated value       : %.4f\n", tabulated);
    printf("Chi-Square calculated : %.4f\n\n", chi_square);

    if (chi_square > tabulated)
        printf("Result: Reject H0 (%.4f > %.4f) - Numbers are NOT uniformly distributed\n", chi_square, tabulated);
    else
        printf("Result: Fail to Reject H0 (%.4f <= %.4f) - Numbers are uniformly distributed\n", chi_square, tabulated);

    return 0;
}