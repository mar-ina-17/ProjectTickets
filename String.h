#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <ostream>
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

		bool operator==(const String&other);//const
		bool operator!=(const String&other);//const
		char operator[](size_t i) const;
		char& operator[](size_t i);
        
        friend std::istream& operator>>(std::istream& in, String&other)
        {   
			//change this;
			char tmp[200];
			in.ignore();
			in.getline(tmp, 200);

			size_t i = 0;

				while (tmp[i])
				{
					++i;
				}
		
			other.size = i;

			for(int i = 0; i < other.size; i++)
			{
				other.data[i] = tmp[i];
			}
				
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

#endif
