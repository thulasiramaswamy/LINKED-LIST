#include <stdio.h>

typedef int (*f)(int, int);                 //declare typdef
f func[3] = {&add, &minus, &multiply};      //make array func of type f,
                                            //the pointer to a function
int add(int a, int b) {   return a + b ; }

int minus(int a, int b) {    return a - b ;  }

int multiply(int a, int b) {    return a * b ;  }
int main() 
{
  int i;
  for (i = 0; i < 3; ++i) 
   printf("%d\n", func[i](5, 4));
  return 0;
}
/************************************
#include <stdio.h>
void fun(int a)
{
	printf("Value of a is %d\n", a);
}
int main()
{
	// fun_ptr is a pointer to function fun()
	void (*fun_ptr)(int) = &fun;
	(*fun_ptr)(10);
	return 0;
}
#include <stdio.h>
void add(int a, int b) {	printf("Addition is %d\n", a+b);  }
void subtract(int a, int b) { 	printf("Subtraction is %d\n", a-b);  }
void multiply(int a, int b) { 	printf("Multiplication is %d\n", a*b); }
int main()
{
	// fun_ptr_arr is an array of function pointers
	void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
	unsigned int ch, a = 15, b = 10;
	printf("Enter Choice: 0 for add, 1 for subtract and 2 for multiply\n");
	scanf("%d", &ch);
	if (ch > 2) return 0;
	(*fun_ptr_arr[ch])(a, b);
	return 0;
}
*******************/
