#include <iostream>
using namespace std;
int main() {
    char ch[] = "stringhelloworld";
    char *ptr = ch;
    cout<<ptr++<<" "<<++ptr<<endl;
    return 0;
}