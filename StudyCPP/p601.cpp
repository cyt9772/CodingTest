    // Listing 17.3 Macro Expansion
    #include <iostream>
    using namespace std;
    
    #define CUBE(a) ( (a) * (a) * (a) )
    #define THREE(a) a * a * a

    int main()
    {
       long x = 5;
      long y = CUBE(x);
      long z = THREE(x);

      cout << "y: " << y << endl;
      cout << "z: " << z << endl;

      long a = 5, b = 7;
      y = CUBE(a+b);
      z = THREE(a+b);

      cout << "y: " << y << endl;
      cout << "z: " << z << endl;
    return 0;
   }