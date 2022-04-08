#include <stdio.h>
int main()
{
    double d = 3.923;
    int i = 5;
    char ch = 'a';
    double* p_d = &d;
    int* p_i = &i;
    int* p_ch = &ch;

    //Teilaufgabe A
    printf("Teilaufgabe A: values\n");
    printf("Value of d: %lf\n", d);
    printf("Value of i: %d\n", i);
    printf("Value of ch: %c\n", ch);

    printf("Value of pointer to d: %p\n", p_d);
    printf("Value of pointer to i: %p\n", p_i);
    printf("Value of pointer to ch: %p\n", p_ch);
    printf("\n");
    
    //Teilaufgabe B
    printf("Teilaufgabe B: addresses\n");
    printf("Address of d: %p\n", &d);
    printf("Address of i: %p\n", &i);
    printf("Address of ch: %p\n", &ch);

    printf("Address of pointer p_d: %p\n", &p_d);
    printf("Address of pointer p_i: %p\n", &p_i);
    printf("Address of pointer p_ch: %p\n", &p_ch);
    printf("\n");
    
    //Teilaufgabe C
    printf("Teilaufgabe C: memory size (in bytes)\n");
    printf("Memory size of d: %lu Bytes\n", sizeof(d));
    printf("Memory size of i: %lu Bytes\n", sizeof(i));
    printf("Memory size of ch: %lu Bytes\n", sizeof(ch));

    printf("Memory size of p_d: %lu Bytes\n", sizeof(p_d));
    printf("Memory size of p_i: %lu Bytes\n", sizeof(p_i));
    printf("Memory size of p_ch: %lu Bytes\n", sizeof(p_ch));








    return 0;
}