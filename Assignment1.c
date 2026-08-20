#include <stdio.h>
int main() {
int A[10][10], B[10][10], C[10][10];
int T[10][10];
int r1, c1, r2, c2, i, j, k;
printf("Enter rows and columns of Matrix A: ");
scanf("%d %d"
, &r1, &c1);
printf("Enter elements of Matrix A:\n");
for (i = 0; i < r1; i++)
for (j = 0; j < c1; j++)
scanf("%d"
, &A[i][j]);
printf("Enter rows and columns of Matrix B: ");
scanf("%d %d"
, &r2, &c2);
printf("Enter elements of Matrix B:\n");
for (i = 0; i < r2; i++)
for (j = 0; j < c2; j++)
scanf("%d"
, &B[i][j]);
if (r1 == r2 && c1 == c2) {
printf("\nAddition:\n");
for (i = 0; i < r1; i++) {
for (j = 0; j < c1; j++) {
C[i][j] = A[i][j] + B[i][j];
printf("%d "
, C[i][j]);
}
printf("\n");
}
printf("\nSubtraction:\n");
for (i = 0; i < r1; i++) {
for (j = 0; j < c1; j++) {
C[i][j] = A[i][j] - B[i][j];
printf("%d "
, C[i][j]);
printf("\n");
}
}
} else {
printf("\nAddition and subtraction not possible.\n");
}
if (c1 == r2) {
printf("\nMultiplication:\n");
for (i = 0; i < r1; i++) {
for (j = 0; j < c2; j++) {
C[i][j] = 0;
for (k = 0; k < c1; k++)
C[i][j] += A[i][k] * B[k][j];
printf("%d "
, C[i][j]);
}
printf("\n");
}
} else {
printf("\nMultiplication not possible.\n");
}
printf("\nTranspose of Matrix A:\n");
for (i = 0; i < c1; i++) {
for (j = 0; j < r1; j++) {
T[i][j] = A[j][i];
printf("%d "
, T[i][j]);
}
printf("\n");
}
return 0;
}
