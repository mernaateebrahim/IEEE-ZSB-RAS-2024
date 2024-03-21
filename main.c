//Assignment1
/*
#include <stdio.h>
#include <stdlib.h>
int main() {
    int arr[] = {1,2,3,8,4,3,0,9,5,2,1,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int c = 0;

    for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (arr[i] == arr[j]) {
       c++;
        break;
    }
    }
    }

    printf("total number of duplicate elements: %d\n", c);

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
int main() {
    int arr[] = {1,2,3,8,4,3,0,9,5,2,1,8};
    int size = sizeof(arr) / sizeof(arr[0]);
   printf("unique element in the array:");
    for (int i = 0; i < size; i++) {
            int x=1;
    for (int j =0; j < size; j++) {
      if (arr[i]==arr[j]&&i!=j) {
          x=0;
    break;
    }
    }
    if(x)
    printf("%d",arr[i]);
    }
printf("\n");

    return 0;
}
*/
/*

#include <stdio.h>
#include <stdlib.h>
void count(int arr[], int size) {
    int freq[size];
    int x = -1;

    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = x;
            }
        }
        if (freq[i] != x) {
            freq[i] = count;
        }
    }

    printf("element   |   frequenc\n");
    printf("------------------------\n");
    for (int i = 0; i < size; i++) {
        if (freq[i] != x) {
            printf("%d         |       %d\n", arr[i], freq[i]);
        }
    }
}

int main() {
    int arr[] = {1,2,0,1,8,3,4,8,9,5,4,0,2,2,4,9,0,0,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    count(arr, size);

    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
int sum_numbers(int *n1,int *n2){
return*n1+*n2;
}
int main() {
    int n1,n2,sum;
    printf("enter first num:");
    scanf("%d",&n1);
     printf("enter second num:");
    scanf("%d",&n2);
    sum=sum_numbers(&n1,&n2);
    printf("sum numbers=%d",sum);
    return 0;
}
*/
//Assignment2
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
int x=29 ,y=3 ,z=20;
int *p,*q,*r;
p=&x;
q=&y;
r=&z;
printf("the value of\nx=%d\ny=%d\nz=%d\n",x,y,z);
printf("the address of\np=%u\nq=%u\nr=%u\n",p,q,r);
printf("the value of\np=%d\nq=%d\nr=%d\n",*p,*q,*r);
printf("Swapping pointers:\n");
r=p;p=q;q=r;
printf("the value of\nx=%d\ny=%d\nz=%d\n",x,y,z);
printf("the address of\np=%u\nq=%u\nr=%u\n",p,q,r);
printf("the value of\np=%d\nq=%d\nr=%d\n",*p,*q,*r);
}
*/




//Assignment3
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[50];
    printf("enter a string: ");
    gets(str);
     printf("your string is: %s",str);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[50];
    printf("enter a string: ");
    gets(str);
    printf("individual characters: \n");
    for(int i=0;i<strlen(str);i++){
     if(str[i]!='\n')
    printf("%c\n",str[i]);
    }
    return 0;
}
*/
/*
#include <stdio.h>

int compare(char str1[], char str2[]);

int main() {
    char str1[50];
    char str2[50];

    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    printf("The value of comparison is: %d\n", compare(str1, str2));


    return 0;
}

int compare(char str1[], char str2[]) {
int i;
     while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] < str2[i]) {
            return -1;
        }
        i++;
    }

    return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[50];
    char copy_str[50];
    printf("enter a string: ");
    gets(str);
    strcpy(copy_str,str);
printf("real string: %s\n",str);
printf("copy string: %s\n",copy_str);
    return 0;
}
*/
