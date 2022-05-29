//multi-return value with pointer

#include <iostream>
using namespace std;
typedef unsigned short USHORT;

short Factor(USHORT n, USHORT *pSquared, USHORT *pCubed);

int main(){
    USHORT number, squared, cubed;
    short error;

    cout<<"Enter a number (0-20): ";
    cin>>number;

    error=Factor(number, &squared, &cubed);

    if(!error){
        cout<<"number: "<<number<<endl;
        cout<<"squared: "<<squared<<endl;
        cout<<"cubed: "<<cubed<<endl;
    }else{
        cout<<"Error encountered\n";
    }

    return 0;
}

short Factor(USHORT n, USHORT *pSquared, USHORT *pCubed){
    short value=0;
    if(n>20){
        value=1;
    }else{
        *pSquared=n*n;
        *pCubed=n*n*n;
        value=0;
    }
    return 0;
    
}

