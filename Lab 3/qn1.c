// WAP to test either the given number random number are uniformly distributed or not. 

#include <stdio.h>

int main() {
    int k, n = 0;
    float observed[20];
    float expected, chi_square = 0.0;
    float tabulated;
    int i;

    printf("\nEnter number of intervals (k): ");
    scanf("%d", &k);

    printf("Enter observed frequency for each interval:\n");
    for (i = 0; i < k; i++) {
        printf("  Interval %d: ", i + 1);
        scanf("%f", &observed[i]);
        n += observed[i];
    }

    printf("Enter tabulated chi-square value: ");
    scanf("%f", &tabulated);

    expected = (float)n / k;

    /* Print table */
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