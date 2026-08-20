#include <stdio.h>
(int s[][3]) {
int i;
printf("\nRow\tCol\tValue\n");
for (i = 0; i <= s[0][2]; i++)
printf("%d\t%d\t%d\n"
, s[i][0], s[i][1], s[i][2]);
}
void transpose(int s[][3], int t[][3]) {
int i, j, k = 1;
t[0][0] = s[0][1];
t[0][1] = s[0][0];
t[0][2] = s[0][2];
for (i = 0; i < s[0][1]; i++) {
for (j = 1; j <= s[0][2]; j++) {
if (s[j][1] == i) {
t[k][0] = s[j][1];
t[k][1] = s[j][0];
t[k][2] = s[j][2];
k++;
}
}
}
}
void fastTranspose(int s[][3], int t[][3]) {
int rowTerms[MAX], startingPos[MAX];
int i, j, pos;
int rows = s[0][0];
int cols = s[0][1];
int terms = s[0][2];
t[0][0] = cols;
t[0][1] = rows;
t[0][2] = terms;
if (terms > 0) {
for (i = 0; i < cols; i++)
rowTerms[i] = 0;
for (i = 1; i <= terms; i++)
rowTerms[s[i][1]]++;
startingPos[0] = 1;
for (i = 1; i < cols; i++)
startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
for (i = 1; i <= terms; i++) {
j = s[i][1];
pos = startingPos[j]++;
t[pos][0] = s[i][1];
t[pos][1] = s[i][0];
t[pos][2] = s[i][2];
}
}
}
int main() {
int s[MAX][3], t[MAX][3], ft[MAX][3];
int rows, cols, i, j, value, k = 1;
printf("Enter number of rows and columns: ");
scanf("%d %d"
, &rows, &cols);
printf("Enter matrix elements:\n");
for (i = 0; i < rows; i++) {
for (j = 0; j < cols; j++) {
scanf("%d"
, &value);
if (value != 0) {
s[k][0] = i;
s[k][1] = j;
s[k][2] = value;
k++;
}
}
}
s[0][0] = rows;
s[0][1] = cols;
s[0][2] = k - 1;
printf("\nOriginal Sparse Matrix (Triplet Form):");
display(s);
transpose(s, t);
printf("\nSimple Transpose:");
display(t);
fastTranspose(s, ft);
printf("\nFast Transpose:");
display(ft);
return 0;
}
