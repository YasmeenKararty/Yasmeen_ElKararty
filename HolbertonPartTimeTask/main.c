#include <stdio.h>
#include <stdlib.h>

int main()
{
    // testing task 1
    int numOfCharsPrinted = _printf("Name: %s\nFirst Letter: %c\n%%\nTask 1 done!\n----------\n","Yasmeen",'Y');
    // testing task 2
    _printf("Number of chars Printed by s: %i\nNumber of chars Printed by i in negative: %i\nTask 2 done!\n----------\n",numOfCharsPrinted,-numOfCharsPrinted);
    // testing task 4
    _printf("Binary Num of 98 is : %b\nTask 3 done!\n----------\n",98);
    // testing task 5
    _printf("Unsigned int of 98: %u\nOctal representation of 98: %o\nHexdecimal representation of 98 using x: %x\nHexdecimal representation of 42267 using X: %X\nBinary representation of 98 is : %b\nTask 4 done!\n----------\n",98,98,98,42267,98);
    // testing task 7
    _printf("Testing S: %S\nTask 7 done!\n----------\n","Best \nSchool");

    return 0;
}
