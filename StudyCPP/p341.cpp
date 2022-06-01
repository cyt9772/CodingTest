//배영에서 상수형과 나열형

#include <iostream>
using namespace std;

int main(){
    enum WeekDays {Sun, Mon, Tue, Wed, Thu, Fri, Sat, DaysInWeek};
    int ArrayWeek[DaysInWeek]={10,20, 30,40,50,60};

    cout<<"The value at Tuesday is: "<<ArrayWeek[Tue];

    return 0;
}