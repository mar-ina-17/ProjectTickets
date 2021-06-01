#ifndef STRING_H
#define STRING_H
#include <iostream>
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
		int compare(const String& other);//const define operator>=& > operator=< & <

		bool operator==(const String&other) const;//const
		bool operator!=(const String&other) const;//const
		char operator[](size_t i) const;
		char& operator[](size_t i);

		

        friend std::istream& operator>>(std::istream& in, String&other)
        {   
			char*tmp;
			in.ignore();
			in.getline(tmp,1024);
			other.data = strcpy(other.data, tmp);
			other.size = strlen(other.data);
			return in;
        }

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

int String::compare(const String& other)
{ 
    return strcmp(this->data, other.data);
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

char String::operator[](size_t index) const
{
    return this->data[index]; 
}

char& String::operator[](size_t index)
{
    return this->data[index];
}


#endif
