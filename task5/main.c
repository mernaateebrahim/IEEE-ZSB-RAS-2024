//Assignment 1
//1
/*
#include <stdio.h>
#include <stdlib.h>
#define no_student 1
typedef struct student_inf {
    unsigned int number :4;
    char name[40];
   unsigned int age :8;
    char address[100];
   unsigned int mark :3;
} student;
student get_data(void);
void print_student_inf(student s[], int size);
int main()
{
student s[no_student];
for (int i = 0; i < no_student; i++) {
        printf("Enter student %d information:\n", i + 1);
        s[i]=get_data();
}
printf("---------------------\n");
 print_student_inf(s, no_student);
  printf("The size of struct student_info: %ld\n", sizeof(student));
    return 0;
}
student get_data(void){
    unsigned int temp_num,temp_age,temp_mark;
    student s;
        printf("Number: ");
        scanf("%u", &temp_num);
        s.number=temp_num;
        fflush(stdin);
        printf("Name: ");
       gets(s.name);
        printf("Age: ");
        scanf("%u", &temp_age);
        s.age=temp_age;
        printf("Address: ");
        scanf("%s", s.address);
        printf("Mark: ");
        scanf("%u", &temp_mark);
        s.mark=temp_mark;
        return s;
}
void print_student_inf(student s[], int size) {

    for (int i = 0; i < size; i++) {
        printf("Information of student %u\n", i + 1);
        printf("Number: %u\n", s[i].number);
        printf("Name: %s\n", s[i].name);
        printf("Age: %u\n", s[i].age);
        printf("Address: %s\n",s[i].address);
        printf("Mark: %u\n", s[i].mark);
        printf("    ******    \n");
    }}
*/
//2
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    float real;
    float imaginary;
}complex;
void addComplex(complex c1,complex c2);
int main()
{ complex c1;complex c2;
    printf("Enter  real and imaginary the first complex number:\n ");
   scanf("%f %f",&c1.real,&c1.imaginary);
     printf("Enter  real and imaginary the second complex number:\n ");
   scanf("%f %f",&c2.real,&c2.imaginary);
   addComplex(c1,c2);
    return 0;
}
void addComplex(complex c1,complex c2){
   float real=c1.real+c2.real;
   float imaginary=c1.imaginary+c2.imaginary;
printf("Sum of two complex Numbers =%.2f+%.2fi",real,imaginary);
}
*/
//3
/*
#include <stdio.h>
#include <stdlib.h>
typedef int INT;
typedef float FLOAT;
typedef short SHORT;
typedef long LONG;
typedef double DOUBLE;
typedef char CHAR;
int main()
{
 INT i=1;
 FLOAT f=1.3;
 SHORT s=10;
 LONG l=100;
 DOUBLE d=1000;
 CHAR c='m';
 printf("The size of char=%lu\n",sizeof(c));
 printf("The size of short=%lu\n",sizeof(s));
 printf("The size of integer=%lu\n",sizeof(i));
 printf("The size of float=%lu\n",sizeof(f));
 printf("The size of long=%lu\n",sizeof(l));
 printf("The size of double=%lu\n",sizeof(d));

    return 0;
}
*/
//Assignment 2
/*
#include <stdio.h>
#include <stdlib.h>

enum operations { ADD='+', SUBTRACT='-', MULTIPLY='*', DIVIDE='/', BIT_AND='&', BIT_OR='|', LOGICAL_NOT='!' };

int main() {
    float operand1, operand2;
    char operation;

    printf("Enter the first number:\n");
    scanf("%f", &operand1);

    printf("Enter operation (+,-,*,/,&,|,!): ");
    scanf(" %c", &operation); // Notice the space before %c

    printf("Enter the second number:\n");
    scanf("%f", &operand2);

    switch (operation) {
        case ADD:
            printf("Sum is %f\n", operand1 + operand2);
            break;
        case SUBTRACT:
            printf("Difference is %f\n", operand1 - operand2);
            break;
        case MULTIPLY:
            printf("Multiplication is %f\n", operand1 * operand2);
            break;
        case DIVIDE:
            if (operand2 == 0)
                printf("Cannot divide by zero\n");
            else
                printf("Divide is %f\n", operand1 / operand2);
            break;
        case BIT_AND:
            printf("Bit And is %d\n", (int)operand1 & (int)operand2);
            break;
        case BIT_OR:
            printf("Bit Or is %d\n", (int)operand1 | (int)operand2);
            break;
        case LOGICAL_NOT:
            printf("LOGICAL NOT is %d\n", !(int)operand1);
            break;
        default:
            printf("Invalid operation\n");
    }

    return 0;
}

*/
/*The size of the enum with the initial members (ADD, SUBTRACT, MULTIPLY, DIVIDE, BITWISE_AND, BITWISE_OR, BITWISE_XOR, LOGICAL_NOT) would typically be 4 bytes (32 bits) because enum values are generally represented as integers.

- If you add more members to the enum, the size would likely remain the same (4 bytes) because enums are typically represented using integers, and the size of an integer is usually fixed (4 bytes on most systems). Each additional member would increment the integer value by 1, but it wouldn't affect the size in bytes.*/


//Assignment 3
//1
/*
#include <stdio.h>
#include <stdlib.h>

#define ASCENDING_SORT 1
#define DESCENDING_SORT 2

int* sortDescending(int *arr, int size);
int* sortAscending(int *arr, int size);

int main() {
    int n, *arr, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

#ifdef ASCENDING_SORT
    arr = sortAscending(arr, n);
#elif defined DESCENDING_SORT
    arr = sortDescending(arr, n);
#else
    printf("No sorting option defined.\n");
#endif

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}
int* sortAscending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}
int* sortDescending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}
*/
//2
/*
#include <stdio.h>
#include <stdlib.h>
#define ADD(x, y) (x + y)
#define SUBTRACT(x, y) (x - y)

int main() {
    int op, a, b;

    printf("Enter 1 for addition, 2 for subtraction: ");
    scanf("%d", &op);

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    switch(op) {
        case 1:
            printf("Result of addition: %d\n", ADD(a, b));
            break;
        case 2:
            printf("Result of subtraction: %d\n", SUBTRACT(a, b));
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
*/
