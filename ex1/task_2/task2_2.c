#include <stdio.h>
const int MAX_LENGTH = 1000;

void BS(char A[]){
    char BS_array[MAX_LENGTH+1];
    char vowels[]={'A','a','E','e','I','i','O','o','U','u'};
    int lengthofvowels = sizeof(vowels);
    int lengthofA = 0;
    
    for (lengthofA=0; A[lengthofA]!='\0'; lengthofA++); //es char[6] = ['h','e','l,'l',o','\0] the last character of every array is a \0, and as soon as the for loop arrives at that number: a[i] = \0 it stops the count and the right length is calculated

    int bs_index = 0;
    int is_vowel = 0;
    int i, j;

    for (i=0; i< lengthofA; i++)
    {

        is_vowel = 0;
    for (j = 0; j < lengthofvowels; j++)
    {
    
        if (A[i]==vowels[j])
        {           
            BS_array[bs_index] = A[i];
            BS_array[bs_index+1] = 'b';
            BS_array[bs_index+2] = A[i];
            bs_index +=3;
            is_vowel = 1;
            break;
        } 
    }      
        if (!is_vowel){

            BS_array[bs_index] = A[i];
            bs_index++;
       } 
    }
     
    printf("%s\n", BS_array); 
      
    
 }


int main(){
 
    char input_string[MAX_LENGTH+1];
    printf("Enter a string: ");
    scanf("%[^\n]s", input_string); // the [^\n] is needed if one wants to read a string that also has spaces (" ") in it.
    BS(input_string);

    
    
    return 0;  
}