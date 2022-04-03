#include <stdio.h>

int sum(int a, int b){
	int tmp = a + b;
	return tmp;
}

int incr(){
	for (int i = 0; i<20; i+=2){
		printf("%d ",i);
	}
}

int main(){
	printf("Hello World \n");
	
	int nr = sum(1, 5);
	printf("the result is %d \n", nr);
	
	incr();
	
	return 0;
}
