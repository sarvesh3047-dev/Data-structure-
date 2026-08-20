#include <stdio.h>
struct Student {
int roll;
char name[30];
float marks;
};
void display(struct Student s[], int n) {
int i;
printf("\nRoll\tName\t\tMarks\n");
for (i = 0; i < n; i++)
printf("%d\t%-15s %.2f\n"
, s[i].roll, s[i].name, s[i].marks);
}
void linearSearch(struct Student s[], int n, int roll) {
int i;
for (i = 0; i < n; i++) {
if (s[i].roll == roll) {
printf("\nStudent Found:\n");
printf("Roll: %d\nName: %s\nMarks: %.2f\n"
,
s[i].roll, s[i].name, s[i].marks);
return;
}
}
printf("\nStudent not found.\n");
}
void insertionSort(struct Student s[], int n) {
int i, j;
struct Student key;
for (i = 1; i < n; i++) {
key = s[i];
j = i - 1;
while (j >= 0 && s[j].roll > key.roll) {
s[j + 1] = s[j];
j--;
}
s[j + 1] = key;
}
}
void selectionSort(struct Student s[], int n) {
int i, j, min;
struct Student temp;
for (i = 0; i < n - 1; i++) {
min = i;
for (j = i + 1; j < n; j++) {
if (s[j].roll < s[min].roll)
min = j;
}
temp = s[i];
s[i] = s[min];
s[min] = temp;
}
}
void shellSort(struct Student s[], int n) {
int gap, i, j;
struct Student temp;
for (gap = n / 2; gap > 0; gap /= 2) {
for (i = gap; i < n; i++) {
temp = s[i];
for (j = i; j >= gap &&
s[j - gap].roll > temp.roll; j -= gap) {
s[j] = s[j - gap];
}
s[j] = temp;
}
}
}
void binarySearch(struct Student s[], int n, int roll) {
int low = 0, high = n - 1, mid;
while (low <= high) {
mid = (low + high) / 2;
if (s[mid].roll == roll) {
printf("\nStudent Found:\n");
printf("Roll: %d\nName: %s\nMarks: %.2f\n"
,
s[mid].roll, s[mid].name, s[mid].marks);
return;
}
else if (roll < s[mid].roll)
high = mid - 1;
else
low = mid + 1;
}
printf("\nStudent not found.\n");
}
int main() {
struct Student s[MAX];
int n, i, choice, roll;
printf("Enter number of students: ");
scanf("%d"
, &n);
for (i = 0; i < n; i++) {
printf("\nEnter details of student %d:\n"
, i + 1);
printf("Roll No: ");
scanf("%d"
, &s[i].roll);
printf("Name: ");
scanf("%s"
, s[i].name);
printf("Marks: ");
scanf("%f"
, &s[i].marks);
}
do {
printf("\n\n--- STUDENT DATABASE ---
");
printf("\n1. Display");
printf("\n2. Linear Search");
printf("\n3. Insertion Sort");
printf("\n4. Selection Sort");
printf("\n5. Shell Sort");
printf("\n6. Binary Search");
printf("\n7. Exit");
printf("\nEnter choice: ");
scanf("%d"
, &choice);
switch (choice) {
case 1:
display(s, n);
break;
case 2:
printf("Enter roll number to search: ");
scanf("%d"
, &roll);
linearSearch(s, n, roll);
break;
case 3:
insertionSort(s, n);
printf("\nSorted using Insertion Sort:");
display(s, n);
break;
case 4:
selectionSort(s, n);
printf("\nSorted using Selection Sort:");
display(s, n);
break;
case 5:
shellSort(s, n);
printf("\nSorted using Shell Sort:");
display(s, n);
break;
case 6:
/* Binary search requires sorted data */
insertionSort(s, n);
printf("Enter roll number to search: ");
scanf("%d"
, &roll);
binarySearch(s, n, roll);
break;
case 7:
printf("\nExiting...
");
break;
default:
printf("\nInvalid choice!");
}
} while (choice != 7);
return 0;
}
