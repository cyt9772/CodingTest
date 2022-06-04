    //Listing 15.8 - friendly operators

    #include <iostream>
    #include <string.h>

    using namespace std;

    // Rudimentary string class
    class String
    {
       public:
         // constructors
         String();
         String(const char *const);
         String(const String &);
         ~String();

         // overloaded operators
         char & operator[](int offset);
         char operator[](int offset) const;
         String operator+(const String&);
         friend String operator+(const String&, const String&);
         void operator+=(const String&);
         String & operator= (const String &);

         // General accessors
         int GetLen()const { return itsLen; }
         const char * GetString() const { return itsString; }
//        static int ConstructorCount;
      private:
         String (int);         // private constructor
         char * itsString;
         unsigned short itsLen;
   };

// default constructor creates string of 0 bytes
   String::String()
   {
      itsString = new char[1];
      itsString[0] = '\0';
      itsLen=0;
      //cout << "\tDefault string constructor\n";
//      ConstructorCount++;
   }

   // private (helper) constructor, used only by
   // class methods for creating a new string of
   // required size.  Null filled.
   String::String(int len)
   {
      itsString = new char[len+1];
      for (int i = 0; i<=len; i++)
         itsString[i] = '\0';
      itsLen=len;
      //cout << "\tString(int) constructor\n";
//      ConstructorCount++;
   }

   // Converts a character array to a String
   String::String(const char * const cString)
   {
      itsLen = strlen(cString);
      itsString = new char[itsLen+1];
      for (int i = 0; i<itsLen; i++)
         itsString[i] = cString[i];
      itsString[itsLen]='\0';
      //cout << "\tString(char*) constructor\n";
//      ConstructorCount++;
   }

   // copy constructor
   String::String (const String & rhs)
   {
      itsLen=rhs.GetLen();
      itsString = new char[itsLen+1];
      for (int i = 0; i<itsLen;i++)
         itsString[i] = rhs[i];
      itsString[itsLen] = '\0';
      //cout << "\tString(String&) constructor\n";
  //    ConstructorCount++;
   }

   // destructor, frees allocated memory
   String::~String ()
   {
      delete [] itsString;
      itsLen = 0;
       //cout << "\tString destructor\n";
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
      for (int i = 0; i<itsLen;i++)
         itsString[i] = rhs[i];
      itsString[itsLen] = '\0';
      return *this;
     //cout << "\tString operator=\n";
  }

  //non constant offset operator, returns
  // reference to character so it can be
  // changed!
  char & String::operator[](int offset)
  {
     if (offset > itsLen)
        return itsString[itsLen-1];
     else
        return itsString[offset];
  }

  // constant offset operator for use
  // on const objects (see copy constructor!)
  char String::operator[](int offset) const
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
      int  totalLen = itsLen + rhs.GetLen();
      String temp(totalLen);
      int i;
      for (i = 0; i<itsLen; i++)
         temp[i] = itsString[i];
      for (int j = 0; j<rhs.GetLen(); j++, i++)
         temp[i] = rhs[j];
      temp[totalLen]='\0';
      return temp;
   }

   // creates a new string by adding
   // one string to another
   String operator+(const String& lhs, const String& rhs)
   {
      int  totalLen = lhs.GetLen() + rhs.GetLen();
      String temp(totalLen);
      int i;
      for (i = 0; i<lhs.GetLen(); i++)
         temp[i] = lhs[i];
      for (int j = 0; j<rhs.GetLen(); j++, i++)
         temp[i] = rhs[j];
      temp[totalLen]='\0';
      return temp;
   }

   int main()
   {
      String s1("String One ");
      String s2("String Two ");
      const char *c1 = { "C-String One " } ;
      String s3;
      String s4;
      String s5;

      cout << "s1: " << s1.GetString() << endl;
      cout << "s2: " << s2.GetString() << endl;
      cout << "c1: " << c1 << endl;
      s3 = s1 + s2;
      cout << "s3: " << s3.GetString() << endl;
      s4 = s1 + c1;
      cout << "s4: " << s4.GetString() << endl;
      s5 = c1 + s1;
      cout << "s5: " << s5.GetString() << endl;
    return 0;
   }
