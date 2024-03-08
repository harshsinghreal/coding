#include<Stdio.h>
#include<conio.h>

void  main(){
    int foo= 100;
   // printf("foo = %d in dec %x in hex",foo,foo);
    char buff[20] = "hello m %nworld";
    printf(buff,&foo);
  //  printf("geeks%n for geeks",&foo);
    printf("%d",foo);
   // printf("hi");
}