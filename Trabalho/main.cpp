#include <iostream>
#include "Estructuras/mylist.h"
#include <time.h>

using namespace std;

int main()
{
    time_t time0;
    time_t time1;

    time(&time0);
    for(int i = 0; i < 200000; i++){std::cout << "i: " << i <<'\n';}
    time(&time1);

    cout << "The time1 is: " << time1 <<'\n';
    cout << "The time0 is: " << time0 <<'\n';
    double seconds = time1 - time0;

    cout<<"Time: "<<seconds<<endl;
    return 0;
}
