#include "binary_tools.h"
#include <stdio.h>

//------------------------------------------------------------------------------
void bt_print_1b(char aValue, char aIsEndl)
{
    for(int i = 7; i >= 0; --i)
        printf("%i", (aValue >> i) & 0b00000001);

    if(aIsEndl == 1)
        printf("\n");
}
//------------------------------------------------------------------------------
void bt_print_mark_1b(char aValue, unsigned char aMarkIndex, char aIsEndl)
{
    if(aMarkIndex > 7)
        return;

    for(int i = 7; i >= 0; --i)
    {
        if(i == aMarkIndex)
            printf("(%i)", (aValue >> i) & 0b00000001);
        else
            printf("%i", (aValue >> i) & 0b00000001);
    }

    if(aIsEndl == 1)
        printf("\n");
}
//------------------------------------------------------------------------------
void bt_print_2b(short aValue, char aIsEndl)
{
    bt_print_1b(aValue >> 8, 0);
    bt_print_1b(aValue, aIsEndl);
}
//------------------------------------------------------------------------------
void bt_print_mark_2b(short aValue, unsigned char aMarkIndex, char aIsEndl)
{
    if(aMarkIndex > 15)
        return;

    if(aMarkIndex <= 7)
    {
        bt_print_1b(aValue >> 8, 0);
        bt_print_mark_1b(aValue, aMarkIndex, aIsEndl);
    }
    else
    {
        bt_print_mark_1b(aValue >> 8, aMarkIndex - 8, 0);
        bt_print_1b(aValue, aIsEndl);
    }
}
//------------------------------------------------------------------------------
void bt_print_4b(int aValue, char aIsEndl)
{
    bt_print_2b(aValue >> 16, 0);
    bt_print_2b(aValue, aIsEndl);
}
//------------------------------------------------------------------------------
void bt_print_mark_4b(int aValue, unsigned char aMarkIndex, char aIsEndl)
{
    if(aMarkIndex > 31)
        return;

    if(aMarkIndex <= 15)
    {
        bt_print_2b(aValue >> 16, 0);
        bt_print_mark_2b(aValue, aMarkIndex, aIsEndl);
    }
    else
    {
        bt_print_mark_2b(aValue >> 16, aMarkIndex - 16, 0);
        bt_print_2b(aValue, aIsEndl);
    }
}
//------------------------------------------------------------------------------
char bt_isEven(int aValue)
{
    return !(aValue & 0b00000001);
}
//------------------------------------------------------------------------------
char bt_isOdd(int aValue)
{
    return (aValue & 0b00000001);
}
//------------------------------------------------------------------------------
int bt_invert_bit(int aValue, unsigned char aIndex)
{
    return (aValue ^ ( 1 << aIndex));
}
//------------------------------------------------------------------------------
int bt_set_bit(int aValue, unsigned char aIndex)
{
    return (aValue | ( 1 << aIndex));
}
//------------------------------------------------------------------------------
int bt_clear_bit(int aValue, unsigned char aIndex)
{
    return (aValue & ~( 1 << aIndex));
}
//------------------------------------------------------------------------------
int bt_test_bit(int aValue, unsigned char aIndex)
{
    if((aValue & (1 << aIndex)) != 0)
        return 1;
    return 0;
}


