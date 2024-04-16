/*
#include <stdio.h>
#include <stdlib.h>
float add(float n1,float n2);//add function prototype
float sub(float n1,float n2);//sub function prototype
float mul(float n1,float n2);//mul function prototype
float divi(float n1,float n2);//divi function prototype
int main()
{
    float num1,num2;
    int op;
    printf("1-Addtion\n2-Subtraction\n3-Multiplication\n4-Division\nEnter your choice:");
    scanf("%d",&op);
    printf("Enter the first number:");
    scanf("%f",&num1);
     printf("Enter the second number:");
    scanf("%f",&num2);

  float(*ptr)(float,float);//pointer to function
  switch(op) //to choice the operation
  {
  case 1:
    ptr=&add;
    printf("Result addition:%f",(*ptr)(num1,num2));
    break;

    case 2:
    ptr=&sub;
    printf("Result subtraction :%f",(*ptr)(num1,num2));
    break;
      case 3:
    ptr=&mul;
    printf("Result multiplication:%f",(*ptr)(num1,num2));
    break;
     case 4:
    ptr=&divi;
    printf("Result division:%f",(*ptr)(num1,num2));
    break;
     default:
        printf("Invalid operation");

  }

    return 0;
}
float add(float n1,float n2)//add function
{
    return n1+n2;
}
float sub(float n1,float n2)//sub function
{
    return n1-n2;
}
float mul(float n1,float n2)//mul function
{
    return n1*n2;
}
float divi(float n1,float n2)//divi function
{
    return n1/n2;
}
*/

#include <stdio.h>
#include <stdlib.h>
//functions marco
#define sum(n1,n2)(n1+n2)
#define sub(n1,n2)(n1-n2)
#define mul(n1,n2)(n1*n2)
#define divi(n1,n2)(n1/n2)
int main()
{
    float num1,num2;
    int op;
    printf("1-Addtion\n2-Subtraction\n3-Multiplication\n4-Division\nEnter your choice:");
    scanf("%d",&op);
    printf("Enter the first number:");
    scanf("%f",&num1);
     printf("Enter the second number:");
    scanf("%f",&num2);


  switch(op) //to choice the operation
  {
  case 1:
    printf("Result addition:%f",sum(num1,num2));//return addition
    break;

    case 2:

    printf("Result subtraction :%f",sub(num1,num2));//return subtraction
    break;
      case 3:

    printf("Result multiplication:%f",mul(num1,num2));//return multiplication
    break;
     case 4:

    printf("Result division:%f",divi(num1,num2));//return division
    break;
     default:
        printf("Invalid operation");

  }

    return 0;
}

/*
 normal if, else statements are used for making decisions in the program based on conditions that are evaluated at runtime,
while conditional compilation directives (#ifdef, #else, #endif) are used for including or excluding portions of code during the compilation process based on preprocessor macros.
if, else statements are used to control the flow of the program based on variables' values, while #ifdef, #else, #endif are used to control which parts of the code are included in the final executable based on preprocessor definitions.

*/
