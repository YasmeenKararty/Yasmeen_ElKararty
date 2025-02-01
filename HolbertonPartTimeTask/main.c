#include <stdio.h>
#include <stdlib.h>

int main()
{
    // testing task 1
    int numOfCharsPrinted = _printf("Name: %s\nFirst Letter: %c\n%%\nTask 1 done!\n----------\n","Yasmeen",'Y');
    // testing task 2
    _printf("Number of chars Printed by s: %i\nNumber of chars Printed by i in negative: %i\nTask 2 done!\n----------\n",numOfCharsPrinted,-numOfCharsPrinted);



    return 0;
}
