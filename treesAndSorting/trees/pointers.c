#include <stdio.h>
int main()
{
    int a=6;
    int *b=&a;
    int **c=&b;
    printf("%d \n",a);
    printf("%d \n",*b);
    printf("%d \n",**c);


     int *str; 
      { 
          
        int  a =65;  
        str = &a;  
      }  
      // a falls out of scope   
      // str is now a dangling pointer   
      printf("%d", *str);  

    return 0;

}