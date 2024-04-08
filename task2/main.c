/*#include <stdio.h>
#include <stdlib.h>
int main()
{
int *p1;
char *p2;
long long *p3;
int n1=1;
char n2='a';
long long n3=3;
p1=&n1;
p2=&n2;
p3=&n3;
printf("Address of pointer1 before incrementing =%u \n",p1);
printf("Address of pointer2 before incrementing =%u \n",p2);
printf("Address of pointer3 before incrementing =%u \n",p3);
p1++;
p2++;
p3++;
printf("Address of pointer1 after incrementing =%u \n",p1);
printf("Address of pointer2 after incrementing =%u \n",p2);
printf("Adress of pointer3 after incrementing =%u \n",p3);
 return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int HEXvalue=0x123123;
    int *ptr;
    ptr=&HEXvalue;
    printf("the value before incrementing=0x%x\n",*ptr);
    printf("the value after incrementing \n");
    printf("*ptr++=0x%x\n",*ptr++);
   printf("*++ptr=0x%x\n",*++ptr);
   printf("++*ptr=0x%x\n",++*ptr);

}
*/
/*
#include <stdio.h>
#include <stdlib.h>
int increment(int a);
int main()
{
 int(*ptr)(int);

  ptr=&increment;
  printf("The increment by function is=%d",(*ptr)(5));

}
int increment(int a){
return (a+1);
}
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
 int arr[]={100,200,300,400,500,600};
 int *ptr=arr;
 for(i=0;i<6;i++){
    printf("Value %d =%d\n",i+1,*ptr++);
 }
}







