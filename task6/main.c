//Assignment1
//1
/*
#include <stdio.h>
#include <stdlib.h>

int main() {

    int* ptr1 = (int*)malloc(5 * sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation using malloc failed.\n");
        return 1;
    }
    printf("Memory allocated using malloc.\n");

    for (int i = 0; i < 5; i++) {
        ptr1[i] = i + 1;
    }
    printf("Values in memory allocated by malloc: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    int* ptr2 = (int*)calloc(5, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation using calloc failed.\n");
        free(ptr1);
        return 1;
    }
    printf("Memory allocated using calloc.\n");


    for (int i = 0; i < 5; i++) {
        ptr2[i] = i + 10;
    }
    printf("Values in memory allocated by calloc: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr2[i]);
    }
    printf("\n");

    int* ptr3 = (int*)realloc(ptr2, 10 * sizeof(int));
    if (ptr3 == NULL) {
        printf("Memory reallocation using realloc failed.\n");
        free(ptr1);
        free(ptr2);
        return 1;
    }
    printf("Memory reallocated using realloc.\n");


    for (int i = 0; i < 10; i++) {
        ptr3[i] = i + 20;
    }
    printf("Values in memory reallocated by realloc: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr3[i]);
    }
    printf("\n");


    free(ptr1);
    free(ptr3);

    return 0;
}
*/
//2
/*
#include <stdio.h>
#include <stdlib.h>

int main() {

    int* ptr1 = (int*)malloc(5 * sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation using malloc failed.\n");
        return 1;
    }
    printf("Memory allocated using malloc.\n");


    for (int i = 0; i < 5; i++) {
        ptr1[i] = i + 1;
    }
    printf("Values in memory allocated by malloc: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");


    int* ptr2 = (int*)calloc(5, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation using calloc failed.\n");
        free(ptr1);
        return 1;
    }
    printf("Memory allocated using calloc.\n");


    for (int i = 0; i < 5; i++) {
        ptr2[i] = i + 10;
    }
    printf("Values in memory allocated by calloc: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", ptr2[i]);
    }
    printf("\n");


    free(ptr2);


    int* ptr4 = (int*)malloc(10 * sizeof(int));
    if (ptr4 == NULL) {
        printf("Memory allocation using malloc failed.\n");
        free(ptr1);
        return 1;
    }
    printf("Memory allocated using malloc for ptr4.\n");


    for (int i = 0; i < 10; i++) {
        ptr4[i] = i + 20;
    }
    printf("Values in memory allocated by malloc for ptr4: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", ptr4[i]);
    }
    printf("\n");


    free(ptr1);
    free(ptr4);

    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int maxLength;
    int charFreq[256] = {0};

    printf("Enter the maximum length for the name: ");
    scanf("%d", &maxLength);

    printf("Enter your name (up to %d characters): ", maxLength);
    scanf(" %[^\n]s", name);

    for (int i = 0; i < strlen(name); i++) {
        charFreq[name[i]]++;
    }

    int maxFreq = 0;
    char mostRepeatedChar;
    for (int i = 0; i < 256; i++) {
        if (charFreq[i] > maxFreq) {
            maxFreq = charFreq[i];
            mostRepeatedChar = i;
        }
    }

    printf("Name: %s\n", name);
    printf("Most repeated character: %c\n", mostRepeatedChar);
    printf("Frequency of most repeated character: %d\n", maxFreq);

    return 0;
}
*/
//Assignment2
//1

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hour,minate,second;
    printf("enter time->(hh:mm:ss)");
    while(1){
        scanf("%d:%d:%d",&hour,&minate,&second);
        if((hour>=1&&hour<=12)&&(minate>=0&&minate<=60)&&(second>=0&&second<=60))
            break;
        else
             printf("Invalid time format. Please enter valid values.");
    }
    printf("\nEntered time is: %02d:%02d:%02d\n", hour, minate, second);

    return 0;
}

//2
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 100

int main() {
    char input[size];
    char stop_code[] = "!!";
    int seen[256] = {0};

    while (1) {
        printf("Enter a string: ");
        scanf("%s", input);

        if (strcmp(input, stop_code) == 0) {
            printf("Stop code entered. Exiting...\n");
            break;
        }

        int len = strlen(input);

        printf("Unique characters: ");
        for (int i = 0; i < len; i++) {
            if (!seen[input[i]]) {
                printf("%c", input[i]);
                seen[input[i]] = 1;
            }
        }

        for (int i = 0; i < 256; i++) {
            seen[i] = 0;
        }

        printf("\n");
    }

    return 0;
}
*/
//Assignment3

//2
/*
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* head = NULL;

void insert(int value);
void delet();
void print();

int main() {
    int value;
    char choice;

    while (1) {
        printf("Enter '+' to add, '-' to delete, 'p' to print, or 'x' to exit: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '+':
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case '-':
                delet();
                break;
            case 'p':
                print();
                break;
            case 'x':
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void insert(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->link = head;
    head = newNode;
}

void delet() {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct node* temp = head;
    head = head->link;
    free(temp);
}

void print() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");
}
*/
