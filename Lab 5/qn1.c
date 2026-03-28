// Lab 5: Implementation of Markov Process
// Activity 1: Implementation Coke vs. Pepsi Example for Markov Process
//     • Given that a person’s last cola purchase was Coke, there is a 90% chance that his next cola purchase will also be Coke.
//     • If a person’s last cola purchase was Pepsi, there is an 80% chance that his next cola purchase will also be Pepsi.
//             T  =[ 0.9  0.1 
// 	       0.2  0.8 ]
//             For the above answer the following questions
//   


//  STEP 1 : Take 2 by 2 matrix say T
//  Step 2 : Ask for after how many times we need a prob of choice (say N)
//  STEP 3: Multiply the transition matrix upto N times (T^N)
//  STEp 4: Pick the required index to get answer
//  step 5: display the answer

#include <stdio.h>

void multiply(float A[2][2], float B[2][2], float result[2][2]) {
    result[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    result[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    result[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    result[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
}

void multiplyVector(float P[2], float T[2][2], float result[2]) {
    result[0] = P[0]*T[0][0] + P[1]*T[1][0];
    result[1] = P[0]*T[0][1] + P[1]*T[1][1];
}

int main() {
    float T[2][2];
    printf("\nEnter the 2x2 transition matrix :\n");
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            printf("T[%d][%d]: ", i, j),
            scanf("%f", &T[i][j]);

    // Question 1
    int n1 = 2;
    printf("\nQ1: Probability that a Pepsi purchaser will buy Coke after 2 purchases.\n");
    float Tn[2][2], temp[2][2];
    // Copy T to Tn
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) Tn[i][j] = T[i][j];
    for(int step=1; step<n1; step++) {
        multiply(Tn, T, temp);
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) Tn[i][j] = temp[i][j];
    }
    printf("T^2 Matrix:\n");
    printf("\n        Coke     Pepsi\n");
    printf("Coke  %8.4f %8.4f\n", Tn[0][0], Tn[0][1]);
    printf("Pepsi %8.4f %8.4f\n", Tn[1][0], Tn[1][1]);
    printf("\nProbability (Pepsi -> Coke in 2 steps): %.4f\n", Tn[1][0]);

    // Question 2
    int n2 = 3;
    printf("\nQ2: Probability that a Coke purchaser will buy Pepsi after 3 purchases.\n");   // Reset Tn to T
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) Tn[i][j] = T[i][j];
    for(int step=1; step<n2; step++) {
        multiply(Tn, T, temp);
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) Tn[i][j] = temp[i][j];
    }
    printf("T^3 Matrix:\n");
    printf("\n        Coke     Pepsi\n");
    printf("Coke  %8.4f %8.4f\n", Tn[0][0], Tn[0][1]);
    printf("Pepsi %8.4f %8.4f\n", Tn[1][0], Tn[1][1]);
    printf("\nProbability (Coke -> Pepsi in 3 steps): %.4f\n", Tn[0][1]);

    // Question 3
    printf("\nQ3: Enter initial state distribution (Coke, Pepsi): ");
    float P0[2];
    scanf("%f %f", &P0[0], &P0[1]);
    int n3 = 3;
    // Reset Tn to T
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) Tn[i][j] = T[i][j];
    for(int step=1; step<n3; step++) {
        multiply(Tn, T, temp);
        for(int i=0;i<2;i++) for(int j=0;j<2;j++) Tn[i][j] = temp[i][j];
    }
    float Pn[2] = {0, 0};
    multiplyVector(P0, Tn, Pn);
    printf("\nAfter 3 steps (Coke, Pepsi): (%.4f, %.4f)\n", Pn[0], Pn[1]);

    return 0;
}