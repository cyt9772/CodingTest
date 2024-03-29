#include <iostream>
#include <string.h>

using namespace std;

class String
{
public:
    // constructors
    String();
    String(const char *const);
    String(const String &);
    ~String();

    // overloaded operators
    char & operator[](unsigned short offset);
    char operator[](unsigned short offset) const;
    String operator+(const String&);
    void operator+=(const String&);
    String & operator= (const String &);

    // General accessors
    unsigned short GetLen()const { return itsLen; }
    const char * GetString() const { return itsString; }
private:
    String (unsigned short);         // private constructor
    char * itsString;
    unsigned short itsLen;
};


// default constructor creates string of 0 bytes
String::String()
{
    cout<<"Call String()\n";
    itsString = new char[1];
    itsString[0] = '\0';
    itsLen=0;
}

// private (helper) constructor, used only by
// class methods for creating a new string of
// required size. Null filled.
String::String(unsigned short len)
{
    itsString = new char[len+1];
    for (unsigned short i = 0; i<=len; i++)
        itsString[i] = '\0';
    itsLen=len;

}


// Converts a character array to a String
String::String(const char * const cString)
{
    itsLen = strlen(cString);
    itsString = new char[itsLen+1];
    for (unsigned short i = 0; i<itsLen; i++)
        itsString[i] = cString[i];
    itsString[itsLen]='\0';
}


// copy constructor
String::String (const String & rhs)
{
    itsLen=rhs.GetLen();
    itsString = new char[itsLen+1];
    for (unsigned short i = 0; i<itsLen;i++)
        itsString[i] = rhs[i];

    itsString[itsLen] = '\0';
}


// destructor, frees allocated memory
String::~String ()
{
    delete [] itsString;
    itsLen = 0;
}


// operator equals, frees existing memory
// then copies string and size
String& String::operator=(const String & rhs)
{
    if (this == &rhs)
        return *this;

    delete [] itsString;
    itsLen=rhs.GetLen();
    itsString = new char[itsLen+1];

    for (unsigned short i = 0; i<itsLen;i++)
        itsString[i] = rhs[i];

    itsString[itsLen] = '\0';
    return *this;
}


//nonconstant offset operator, returns
// reference to character so it can be
// changed!
char & String::operator[](unsigned short offset)
{
    if (offset > itsLen)
        return itsString[itsLen-1];
    else
        return itsString[offset];
}


// constant offset operator for use
// on const objects (see copy constructor!)
char String::operator[](unsigned short offset) const
{
    if (offset > itsLen)
        return itsString[itsLen-1];
    else
        return itsString[offset];
}


// creates a new string by adding current
// string to rhs
String String::operator+(const String& rhs)
{
    unsigned short  totalLen = itsLen + rhs.GetLen();
    String temp(totalLen);

    unsigned short i;
    for (i = 0; i<itsLen; i++)
        temp[i] = itsString[i];

    for (unsigned short j = 0; j<rhs.GetLen(); j++, i++)
        temp[i] = rhs[j];

    temp[totalLen]='\0';

    return temp;
}


// changes current string, returns nothing
void String::operator+=(const String& rhs)
{
    unsigned short rhsLen = rhs.GetLen();
    unsigned short totalLen = itsLen + rhsLen;
    String  temp(totalLen);
    unsigned short i;

    for (i = 0; i<itsLen; i++)
        temp[i] = itsString[i];

    for (unsigned short j = 0; j<rhs.GetLen(); j++, i++)
        temp[i] = rhs[i-itsLen];

    temp[totalLen]='\0';
    *this = temp;
}


