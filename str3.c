#include "monty.h"

/**
 * intToString - Convert an integer to a string
 * @num: The number to convert
 * Return: A pointer to the resulting string, or NULL on failure
 */
char *intToString(int num)
{
    long numValue = 0;
    unsigned int tempValue;
    int strLength = 0;
    char *resultString;

    tempValue = getAbsoluteValue(num);
    strLength = calculateStringLength(tempValue, 10);

    if (num < 0 || numValue < 0)
        strLength++;
    
    resultString = malloc(strLength + 1);
    if (!resultString)
        return (NULL);

    fillString(tempValue, 10, resultString, strLength);
    if (num < 0 || numValue < 0)
        resultString[0] = '-';

    return (resultString);
}

/**
 * getAbsoluteValue - Get the absolute value of an integer
 * @integerValue: The integer to find the absolute value of
 * Return: The absolute value as an unsigned integer
 */
unsigned int getAbsoluteValue(int integerValue)
{
    if (integerValue < 0)
        return (-(unsigned int)integerValue);
    return ((unsigned int)integerValue);
}

/**
 * calculateStringLength - Calculate the length of a string representation of an unsigned integer
 * @num: The number to find the length for
 * @base: The base of the number representation used by the buffer
 * Return: The length of the string
 */
int calculateStringLength(unsigned int num, unsigned int base)
{
    int length = 1;

    while (num > base - 1)
    {
        length++;
        num /= base;
    }
    return (length);
}

/**
 * fillString - Fill a character buffer with the string representation of an unsigned integer
 * @num: The number to convert to a string
 * @base: The base number
 * @buffer: The buffer to be filled
 * @bufferSize: The size of the buffer
 * Return: void
 */
void fillString(unsigned int num, unsigned int base, char *buffer, int bufferSize)
{
    int remainder, index = bufferSize - 1;

    buffer[bufferSize] = '\0';
    while (index >= 0)
    {
        remainder = num % base;
        if (remainder > 9)
            buffer[index] = remainder + 87;
        else
            buffer[index] = remainder + '0';
        num /= base;
        index--;
    }
}

/**
 * isDigit - Check if a string is composed of digits
 * Return: 1 if the string contains only digits, 0 otherwise
 */
int isDigit(void)
{
    int i = 0;

    if (globalvar.token2[0] == '-' || globalvar.token2[0] == '+')
        i++;
    while (globalvar.token2[i])
    {
        if (isdigit(globalvar.token2[i]) == 0)
            return (0);
        i++;
    }
    return (1);
}
