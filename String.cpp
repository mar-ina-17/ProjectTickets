#include "String.hpp"
#include "helpers.cpp"

String::String()
{
    this->data = nullptr;
    this->size = 0;
}

String::String(const String& other)
{
    emptyAndCreateString(this->data, other.size);

    this->size = other.size;
    strcpy(this->data, other.data);
}

String& String::operator=(const String& other)
{
    if(this != &other)
    {
        emptyAndCreateString(this->data, other.size);

        this->size = other.size;
        strcpy(this->data, other.data);
        
    }

    return *this;
}

String::~String()
{
    delete [] this->data;
}

String::String(size_t size)
{
    this->size = size;
    emptyAndCreateString(this->data, this->size);
}

String::String(const char* data)
{
    this->size = strlen(data);
    emptyAndCreateString(this->data, this->size);

    strcpy(this->data, data);
}

String& String::concat(const String& other)
{   
    strcat(this->data, other.data);
    this->size += other.size;

    return *this;
}

int String::compare(const String& other)
{ 
    return strcmp(this->data, other.data);
}

