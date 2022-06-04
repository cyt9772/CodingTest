    #include "String1.hpp"
    using namespace std;

    class Employee
    {

    public:
       Employee();
       Employee(const char*, const char*, const char*, long);
       ~Employee();
       Employee(const Employee&);
       Employee & operator= (const Employee &);

      const String & GetFirstName() const 
         { return itsFirstName; }
      const String & GetLastName() const { return itsLastName; }
      const String & GetAddress() const { return itsAddress; }
      long GetSalary() const { return itsSalary; }

      void SetFirstName(const String & fName) 
          { itsFirstName = fName; }
      void SetLastName(const String & lName) 
         { itsLastName = lName; }
      void SetAddress(const String & address) 
           { itsAddress = address; }
      void SetSalary(long salary) { itsSalary = salary; }
   private:
      String    itsFirstName;
      String    itsLastName;
      String    itsAddress;
      long      itsSalary;
   };

   Employee::Employee():
      itsFirstName(""),
      itsLastName(""),
      itsAddress(""),
      itsSalary(0)
   {}

   Employee::Employee(const char * firstName, const char * lastName,
      const char * address, long salary):
      itsFirstName(firstName),
      itsLastName(lastName),
      itsAddress(address),
      itsSalary(salary)
   {}

   Employee::Employee(const Employee & rhs):
      itsFirstName(rhs.GetFirstName()),
      itsLastName(rhs.GetLastName()),
      itsAddress(rhs.GetAddress()),
      itsSalary(rhs.GetSalary())
   {}

   Employee::~Employee() {}

   Employee & Employee::operator= (const Employee & rhs)
   {
      if (this == &rhs)
         return *this;

      itsFirstName = rhs.GetFirstName();
      itsLastName = rhs.GetLastName();
      itsAddress = rhs.GetAddress();
      itsSalary = rhs.GetSalary();

      return *this;
   }

    int main()
    {
       cout << "Creating Edie...\n";
       Employee Edie("Jane","Doe","1461 Shore Parkway", 20000);
       Edie.SetSalary(20000);
       cout << "Calling SetFirstName with char *...\n";
       Edie.SetFirstName("Edythe");
       cout << "Creating temporary string LastName...\n";
       String LastName("Levine");
      Edie.SetLastName(LastName);

      cout << "Name: ";
      cout << Edie.GetFirstName().GetString();
      cout << " " << Edie.GetLastName().GetString();
      cout << "\nAddress: ";
      cout << Edie.GetAddress().GetString();
      cout << "\nSalary: " ;
      cout << Edie.GetSalary();
      cout << endl;
    return 0;
   }

