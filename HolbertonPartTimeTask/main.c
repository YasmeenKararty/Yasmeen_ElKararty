#include <stdio.h>
#include <stdlib.h>

int main()
{
    // testing task 1
    int numOfCharsPrinted = _printf("Name: %s\nFirst Letter: %c\n%%\nTask 1 done!\n----------\n","Yasmeen",'Y');
    // using printf only here because %i is not implemented yet in _printf
    printf("Num of chars: %i\n",numOfCharsPrinted);

    return 0;
}
