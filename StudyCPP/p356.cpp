//strncpy 사용

#include <iostream>
#include <string.h>
//#include "CAT.hpp"
using namespace std;


int main(){
    const int MAXLENGTH=80;
    char string1[]="No man is an island";
    char string2[MAXLENGTH+1];

    strncpy(string2,string1,MAXLENGTH);

    cout<<"string1: "<<string1<<endl;
    cout<<"string2: "<<string2<<endl;
    return 0;
}