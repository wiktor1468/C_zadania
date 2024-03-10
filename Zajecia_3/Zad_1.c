#include <stdio.h>

// Function to calculate the binomial coefficient (wspolczynnik dwumianowy Newtona)
int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) //one way to choose 0 or n elements from a set.
        return 1;
    else
        return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
} /*Pascal's Triangle recurrence relation, where each element in the triangle is the sum of
 * the two elements directly above it in the previous row.
*/

int binWOrecurssion(int n, int k){
    if (k == 0 || k == n) //one way to choose 0 or n elements from a set.
        return 1;

    // Initialize result
    int result = 1;

    // C(n, k) = C(n, n-k)
    if (k > n - k)
        k = n - k;

    // Calculate C(n, k) using the formula C(n, k) = n! / (k! * (n-k)!)
    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}
void printPascalsTriangle(int numRows) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", binWOrecurssion(i, j));
        }
        printf("\n");
    }
}

int main() {
    int numRows;

    printf("Enter the number of rows for Pascal's Triangle: ");

    //validation
    char term;
    if(scanf("%d%c", &numRows, &term) != 2 || term != '\n') //scanf returns the number of successfully matched and assigned input
        printf("failure\n");
    else {
        printf("valid integer followed by enter key\n");
        printPascalsTriangle(numRows);
    }

    return 0;
}
