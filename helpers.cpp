#ifndef helpers
#define helpers
#include <iostream>

//! empty a char* and allocates new memory
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

//! determines the size of a string
size_t strlen ( const char * str )
{
    size_t i = 0;

        while (str[i])
        {
            ++i;
        }

    return i;
}

//! makes a copy of one const char* array to another char* array 
//! but first call the emptyAndCreateString function to allocate memory for the new string
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

//! concatenates two strings into one but first makes a new tmp char* parameter
//! to hold ine of the strings so it can resize and then copy ist data back along with th eother string 
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
#endif