#include "String.h"
#include "helpers.cpp"

String::String()
{
    this->size = 1;
	this->data = emptyAndCreateString(this->data, this->size);
}

String::String(const String& other)
{
    this->data = emptyAndCreateString(this->data, other.size);

    this->size = other.size;
    this->data = strcpy(this->data, other.data);
}

String& String::operator=(const String& other)
{
    if(this != &other)
    {
        this->data = emptyAndCreateString(this->data, other.size);

        this->size = other.size;
        this->data = strcpy(this->data, other.data);
        
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
    this->data = emptyAndCreateString(this->data, this->size);
}

String::String(const char* data)
{
    this->size = strlen(data);
    this->data = emptyAndCreateString(this->data, this->size);

    this->data = strcpy(this->data, data);
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

bool String::operator==(const String& other)
{
    bool result = false;
    if(this->size == other.size)
    {
        for(int i = 0; i < this->size; i++)
        {
            if(this->data[i] == other.data[i]) result = true;
            else return false;
        }
    }

    return result;
}

size_t String::getSize() const
{
    return this->size;
}

char String::operator[](size_t index) const
{
    return this->data[index]; 
}

char String::operator[](size_t index)
{
    return this->data[index];
}