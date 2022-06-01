//strcpy 사용

#include <iostream>
#include <string.h>
//#include "CAT.hpp"
using namespace std;


int main(){
    char string1[]="No man is an island";
    char string2[80];

    strcpy(string2,string1);

    cout<<"string1: "<<string1<<endl;
    cout<<"string2: "<<string2<<endl;
    return 0;
}