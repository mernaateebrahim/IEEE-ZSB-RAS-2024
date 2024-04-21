//Assignment1
/*
#include <stdio.h>
#include <stdlib.h>
#define no_student 15

struct student_inf {
    int number;
    char name[40];
    int age;
    char address[100];
    float mark;
};

void print_student_inf(struct student_inf student[], int size);


int main() {
    struct student_inf students[no_student];

    for (int i = 0; i < no_student; i++) {
        printf("Enter student %d information:\n", i + 1);
        printf("Number: ");
        scanf("%d", &students[i].number);
        fflush(stdin);
        printf("Name: ");
       gets(students[i].name);
       fflush(stdin);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Address: ");
        scanf("%s", students[i].address);
        printf("Mark: ");
        scanf("%f", &students[i].mark);
    }

    print_student_inf(students, no_student);


    return 0;
}
void print_student_inf(struct student_inf student[], int size) {
    int counter=0;
    for (int i = 0; i < size; i++) {
        printf("Student %d\n", i + 1);
        printf("Number: %d\n", student[i].number);
        printf("Name: %s\n", student[i].name);
        printf("Age: %d\n", student[i].age);
        printf("Address: %s\n", student[i].address);
        printf("Mark: %f\n", student[i].mark);
        if(student[i].mark<12)
            counter++;
    }
    printf("The number of students with marks less than 12 is%d \n",counter);
    return 0;
}

*/
//Assignment3
//1
/*
#include <stdio.h>
#include <stdlib.h>
struct date {
    int day, month, year;
};

void compare(struct date d1, struct date d2);

int main() {
    struct date d1, d2;
    char date_str1[11], date_str2[11];

    printf("Enter the first date like-->dd/mm/yyyy:\n");
    scanf("%s", date_str1);
    sscanf(date_str1, "%d/%d/%d", &d1.day, &d1.month, &d1.year);

    printf("Enter the second date like-->dd/mm/yyyy\n");
    scanf("%s", date_str2);
    sscanf(date_str2, "%d/%d/%d", &d2.day, &d2.month, &d2.year);

    compare(d1, d2);

    return 0;
}

void compare(struct date d1, struct date d2) {
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        printf("Dates are equal");
    else
        printf("Dates are not equal");
}
*/
//2

#include <stdio.h>
#include <stdlib.h>
struct info{
char name[50];
int age;
};
int main()
{
struct info p={"Merna Atef",20};
struct info *ptr;
ptr=&p;
printf("The name of person is %s \n",ptr->name);
printf("The age of person is %d\n",ptr->age);
}




//Assignment3
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    struct test1 {
    int id;
    char name[40];
    char class_id;
    }t1;
    printf("the size of the struct:%d\n",sizeof(t1));
    struct test2 {
   char name[40];
    int id;
    char class_id;
    }t2;
 printf("the size of the struct after changing:%d\n",sizeof(t2));
}
*/
/*(the size of a struct depends on the arrangement and types of its members,
 as well as how the compiler chooses to determine the size.
In the first case, the size of the struct depends on the size and arrangement of its members.
 Even though the order of members is changed in the second case,
 the size of the struct might still be determined in the same way due to the rules the compiler follows for sizing structs)*/



