#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <fstream>
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
	   String(const char* data);

		size_t getSize() const;

		String& concat(const String& other);

		bool operator==(const String&other) const;
		bool operator!=(const String&other) const;
		const char& operator[](size_t i) const;
		char& operator[](size_t i);

		//! an overloaded operator>> for console input String
        friend std::istream& operator>>(std::istream& in, String&other)
        {   
			  	char* c = new char[1000];
				in >> c;
				other = String(c);
				delete[] c;

			return in;
        }

		//! an overloaded operator<< for console output String
        friend std::ostream& operator<<(std::ostream& out, const String& other) 
        {
			if(other.data == nullptr)
			{
					out<<"Default"<<std::endl;
					return out;
			}
            for (size_t i = 0; i < other.size; ++i)
            {
                out << other.data[i];
            }

		    return out;
	    }

		//! an overloaded operator<< for file output String
		friend std::ofstream& operator<<(std::ofstream& of, String &other)
		{
			of<<other.data;
			return of;
		}

		//! an overloaded operator>> for file input String
		friend std::ifstream& operator>>(std::ifstream&inf, String&other)
		{	
			inf.getline(other.data, 1024);	
			other.size = strlen(other.data);							
			return inf;
		}

};

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

bool String::operator==(const String& other) const
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

bool String::operator!=(const String& other) const
{
  return !(*this == other);
}

size_t String::getSize() const
{
    return this->size;
}

const char& String::operator[](size_t index) const
{
    return this->data[index]; 
}

char& String::operator[](size_t index)
{
    return this->data[index];
}

#endif
