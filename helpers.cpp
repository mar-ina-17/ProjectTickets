#ifndef helpers
#define helpers
#include <iostream>

char * emptyAndCreateString(char * str, size_t len)
{
    delete [] str;
    str = new (std::nothrow) char[len + 1];

        if(!str)
        {
            std::cout<<"memory allocation error"<<std::endl;
            throw std::bad_alloc();
        }

    return str;
}

size_t strlen ( const char * str )
{
    size_t i = 0;

        while (str[i])
        {
            ++i;
        }

    return i;
}


char * strcpy ( char * destination, const char * source )
{
    size_t len = strlen ( source );
    destination = emptyAndCreateString(destination, len);

        for( int i = 0; i < len; i++ )
        {
            destination[i] = source[i];
        }

    return destination;
}

char * strcat ( char * destination, const char * source )
{
    int j = 0;
    char * tmp = strcpy ( tmp, destination);
    size_t size = strlen ( tmp ) + strlen ( source ) + 1;
    emptyAndCreateString(destination, size );

        strcpy ( destination, tmp );

        for( int i = strlen ( tmp ); i < size; i++ )
        {
            destination[i] = source[j];
            j++;
        }

    return destination;
}

int strcmp ( const char * str1, const char * str2 )
{
    int i = 0, result = 0;
    while (str1[i] || str2[i])
    {
        if(str1[i] < str2[i])
        {
            result = -1;
        }
        else if(str1[i] > str2[i])
        {
            result = 1;
        }
       
        i++;
    }
    return result;
}
#endif