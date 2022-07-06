#include <iostream>
#include "calculation.h"

using namespace std;
using namespace Calculating;

int main(){
    cout<<"Enter the two numbers :";
    int a,b;
    cin>>a>>b;
    cout<<"Sum is :"<<add(a,b)<<endl;
    cout<<"Difference is :"<<subtract(a,b)<<endl;
    cout<<"multiplication is :"<<multiply(a,b)<<endl;
    cout<<"Division is :"<<divide(a,b)<<endl;
    return 0;
}