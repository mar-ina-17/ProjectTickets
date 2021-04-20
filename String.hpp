#pragma once
#include "helpers.cpp"
class String
{
    private:
        size_t size;
        char * data;

    public:
        String();
        String(const String&);
        String &operator=(const String &);
        ~String();

        String(size_t size);
        String(const char * data);

        String& concat(const String&);
        int compare(const String&);
        
        friend std::istream& operator>>(std::istream& in, String&other)
        {   
            std::cout<<"Enter string length: ";
            in>>other.size;

            std::cout<<"Enter the string: ";
            in.ignore();
            in.getline(other.data, other.size);

            return in;
        }

        friend std::ostream& operator<<(std::ostream& out, const String& other) 
        {
            for (size_t i = 0; i < other.size; ++i)
            {
                out << other.data[i];
            }
		    return out;
	    }
};


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

