// Generate the N random number using Linear Congruential Method and test the uniformity of generated numbers using Chi-Square method. Before doing calculation of chi be sure that your generator has generated minimum 40 numbers.

#include <stdio.h>

int main() {
    long a, m, c, x0, n;
    float observed[20] = {0};
    float expected, chi_square = 0.0;
    float tabulated;
    int k, i, j;

    /* LCM Parameters */
    printf("=== Linear Congruential Method ===\n");
    printf("Formula: X(n+1) = (a * Xn + c) %% m\n\n");
    printf("Enter multiplier (a): ");
    scanf("%ld", &a);
    printf("Enter increment  (c): ");
    scanf("%ld", &c);
    printf("Enter modulus    (m): ");
    scanf("%ld", &m);
    printf("Enter seed      (X0): ");
    scanf("%ld", &x0);
    printf("Enter how many numbers to generate (N): ");
    scanf("%ld", &n);

    /* Minimum 40 check */
    if (n < 40) {
        printf("\nWarning: N = %ld is less than 40.\n", n);
        printf("Chi-Square test requires minimum 40 numbers.\n");
        printf("Setting N = 40.\n");
        n = 40;
    }

    /* Generate numbers */
    float nums[10000];
    long x = x0;
    printf("\nGenerated %ld Random Numbers:\n", n);
    for (i = 0; i < n; i++) {
        x = (a * x + c) % m;
        nums[i] = (float)x / m;
        printf("X[%3d] = %.4f    ", i + 1, nums[i]);
        if ((i + 1) % 5 == 0) printf("\n");
    }
    if (n % 5 != 0) printf("\n");

    /* Chi-Square inputs */
    printf("\nEnter number of intervals (k): ");
    scanf("%d", &k);
    printf("Enter tabulated chi-square value: ");
    scanf("%f", &tabulated);

    /* Group numbers into intervals */
    float groups[20][10000];
    int   count[20] = {0};

    for (i = 0; i < n; i++) {
        j = (int)(nums[i] * k);
        if (j == k) j = k - 1;
        observed[j]++;
        groups[j][count[j]++] = nums[i];
    }

    /* Print grouped interval table */
    printf("\n%-12s %-16s %s\n", "Interval", "Range", "Numbers");
    printf("----------------------------------------------------------------------\n");
    for (i = 0; i < k; i++) {
        printf("%-12d (%.2f - %.2f)   ", i + 1, (float)i / k, (float)(i + 1) / k);
        for (j = 0; j < count[i]; j++)
            printf("%.4f  ", groups[i][j]);
        printf("\n");
    }

    expected = (float)n / k;

    /* Chi-Square table */
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
    printf("Total numbers         : %ld\n", n);
    printf("Degrees of freedom    : %d\n", df);
    printf("Tabulated value       : %.4f\n", tabulated);
    printf("Chi-Square calculated : %.4f\n\n", chi_square);

    if (chi_square > tabulated)
        printf("Result: Reject H0 (%.4f > %.4f) - Numbers are NOT uniformly distributed\n", chi_square, tabulated);
    else
        printf("Result: Fail to Reject H0 (%.4f <= %.4f) - Numbers are uniformly distributed\n", chi_square, tabulated);

    return 0;
}