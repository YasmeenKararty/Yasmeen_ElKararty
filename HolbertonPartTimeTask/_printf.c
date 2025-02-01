#include <stdarg.h>
#include <unistd.h>

// func to count the length of the string
int countStrLength (char * str){
    int length = 0;
    while (str != NULL && str[length]!='\0'){
        length++;
    }
    return length;
}

int _printf(const char *format, ...){
    // variable to hold number of characters limit
    int charactersLimit = 1000;
    // variable to hold the number of characters printed
    int numOfCharsPrinted = 0;
    // holding the arguments
    va_list listPtr;
    va_start(listPtr, format);

    char *currentStr = (char *)malloc(charactersLimit * sizeof(char));
    int currentStrLength = 0;
    int index = 0;

    while (format[index]!= '\0'){
        // if current char is % this means a specifier is next
        if(format[index] =='%' ){
            // write text before specifier
            write(1, currentStr, currentStrLength);
            numOfCharsPrinted += currentStrLength;
            currentStrLength=0;
            free(currentStr);
            currentStr = (char *)malloc(1000 * sizeof(char));
            // hold the specfier
            char specifier = format[index+1];

            switch(specifier){
            case '%':
                write(1, "%", 1);
                numOfCharsPrinted++;
                break;
            case 'c':{
                char argument = va_arg(listPtr,int);
                write(1, &argument, 1);
                numOfCharsPrinted++;
                break;
            }
            case 's':{
                char * strArgument = va_arg(listPtr,char*);
                int strArgumentLength = countStrLength(strArgument);
                write(1, strArgument ,strArgumentLength);
                numOfCharsPrinted+= strArgumentLength;
                break;
            }

            }
            index+=2;
        }
        else{
            // if not a specifier append the string to the array
            currentStr[currentStrLength] = format[index];
            currentStrLength++;
            index++;
        }

    }
// if format string ended and there is still chars in the buffer write them
if (currentStrLength!=0){
    write(1, currentStr, currentStrLength);
    numOfCharsPrinted += currentStrLength;
    free(currentStr);
}
return numOfCharsPrinted;
}
