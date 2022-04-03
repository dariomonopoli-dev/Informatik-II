#include <stdio.h>
#define MAX_SIZE 1000

int count_vowels(char A[]) {
    int count = 0;
    int idx = 0;
    while (A[idx]!='\0') // \0 when it goes out of bound, it stops before
    {
        if (A[idx]=='A' ||A[idx]=='a'||A[idx]=='E'||A[idx]=='e'||A[idx]=='I'||A[idx]=='i'
        ||A[idx]=='O'||A[idx]=='o'||A[idx]=='U'||A[idx]=='u')
        {
        count+=1;
        }
        idx++;
    }
    return count;
}






int main(){
 
    char A[MAX_SIZE];
    printf("Input a string: ");
    gets(A);
    int x = count_vowels(A);
    printf("The string A has %d vowels", x);

    return 0;
}