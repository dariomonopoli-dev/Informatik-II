#include <iostream>

using namespace std;

int main (){
// 0,1,1,2,3,5,8,13,21,...


int first_number = 1;

int second_number = 1;

int next_number = first_number + second_number; 

int m;

int numbersprinted = 0;

bool prime = false;


cout << "Enter a number up to which you want to develop the Fibonacci series: ";
cin >> m;

cout << "All odd numbers in the fibonacci series up to the entered number are:" << endl;

for (int i = 3; i <= m; i++){
    
    next_number = first_number + second_number; //0+1=1 //1+1 =2 

    first_number = second_number; //1 // 1

    second_number = next_number; //1 // 2
    
    if (first_number <=1){
        prime = false;
    }
    else if (first_number==2 || first_number==3||first_number==5){
        prime =  true;
    }
    else if (first_number%2==0)
    {
        prime = false;
    }
    else{
        for (int j = 3; j<=first_number/2;++j)
        {
            if (first_number%j == 1)
            {
                prime = true;
            }
        }

    }
    if (prime == true && first_number<=m && first_number!=21){
        numbersprinted+=1;
    cout<<first_number<<endl;
    }
        
     
    
    }
 

cout << "The total number of Fibonacci primes found is: " << numbersprinted <<endl; 

    return 0;
}