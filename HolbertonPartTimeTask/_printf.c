#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

// func to count the length of the string
int countStrLength (char * str){
    int length = 0;
    while (str != NULL && str[length]!='\0'){
        length++;
    }
    return length;
}
// same as sprintf but implemented it my own since it is not mentioned to use it
char* convertIntToStr(int num, bool isSigned){
    char numInStrReverse [12];
    int currentStrIndex = 0;
    bool isNeg = false;
    if (isSigned && num <0){
        isNeg = true;
        num = 0-num;
    }
    if (num == 0){
        numInStrReverse[currentStrIndex]='0';
        currentStrIndex++;
    }

    while (num>0){
        int lastDigit = num%10;
        numInStrReverse[currentStrIndex] = (char)(lastDigit+'0');
        currentStrIndex++;
        num/=10;
    }
    if (isSigned && isNeg){
        numInStrReverse[currentStrIndex] = '-';
        currentStrIndex++;
    }
    char *numInStr = (char *)malloc(currentStrIndex + 1 * sizeof(char));

    for (int i = 0 ;i<currentStrIndex; i++){
        numInStr[currentStrIndex - i - 1] = numInStrReverse[i];
    }
    numInStr[currentStrIndex] = '\0';
    return numInStr;

}
// func to handle decimal to binary conversion
char* numericConversion(int num, char conversionType){
    int conversionNumLimit = 20;
    char numReverse [conversionNumLimit];
    int currentLength= 0;
    if (num == 0){
        numReverse[currentLength] = '0';
        currentLength++;
    }
    int conversionDivider;
    if (conversionType == 'b') conversionDivider = 2;
    else if (conversionType == 'x' || conversionType == 'X') conversionDivider = 16;
    else if (conversionType == 'o') conversionDivider = 8;

    while(num >0){
        numReverse[currentLength] = (char)((num % conversionDivider)+'0') ;
        num = num/conversionDivider;
        currentLength++;
    }
    char *numInSTR = (char *)malloc(currentLength * sizeof(char));
    for (int i = 0 ;i<currentLength; i++){
        numInSTR[currentLength - i - 1] = numReverse[i];
    }
    numInSTR[currentLength] = '\0';
    return numInSTR;
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
            case 'd':
            case 'i':{
                int intArgument = va_arg(listPtr,signed int);
                char * intArgumentAsStr = convertIntToStr (intArgument, true);
                int argumentLength  = countStrLength(intArgumentAsStr);
                write(1, intArgumentAsStr, argumentLength);
                numOfCharsPrinted+=argumentLength;
                break;
            }
            case 'b':
            case 'x':
            case 'X':
            case 'o':{
                int intArgument = va_arg(listPtr,int);
                char * argument = numericConversion (intArgument, specifier);
                int argumentLength = countStrLength(argument);
                write(1, argument, argumentLength);
                numOfCharsPrinted+=argumentLength;
                break;
            }
            case 'u':{
                int intArgument = va_arg(listPtr,unsigned int);
                char * argument = convertIntToStr (intArgument, false);
                int argumentLength = countStrLength(argument);
                write(1, argument, argumentLength);
                numOfCharsPrinted+=argumentLength;
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
