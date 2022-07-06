#include <bits/stdc++.h>
using namespace std;

class Fraction{
    int numerator;
    int denomenator;
    const int Factor;
    public:
/*---------------Constructors-------------*/
    Fraction() : Factor(1){
        this -> numerator = 1;
        this -> denomenator = 1;
    }
    Fraction(int numerator, int denomenator) : Factor(1){
        this -> numerator = numerator;
        this -> denomenator = denomenator;
        this -> numerator *= Factor;
    }
    Fraction(int numerator,int denomenator, int f);
/*--------------Functions------------------*/
    void simplify(){
        int g = __gcd(this -> numerator,this -> denomenator);
        this -> numerator /= g;
        this -> denomenator /= g;
    }
    void print();

/*--------------Operator Overloading-------------------------------*/

    Fraction operator+(Fraction F2);
    Fraction& operator=(Fraction F2);
    Fraction operator++();
    Fraction operator++(int);
};
 
Fraction :: Fraction(int numerator,int denomenator, int f) : Factor(f){
    this -> numerator = numerator;
    this -> denomenator = denomenator;
    this -> numerator *= Factor;
}

void Fraction :: print(){
    cout<<this -> numerator<<"/"<<this -> denomenator<<endl;
}

Fraction& Fraction :: operator=(Fraction F2){
    this -> numerator = F2.numerator;
    this -> denomenator = F2.denomenator;
    return (*this);
}

Fraction Fraction :: operator+(Fraction F2){
    int num = this -> denomenator * F2.numerator + this -> numerator*F2.denomenator;
    int denum = this -> denomenator*F2.denomenator;
    Fraction F3(num,denum);
    F3.simplify();
    return F3;
}

Fraction Fraction :: operator++(){ 
    this -> numerator = this -> numerator + this -> denomenator;
    return (*this);
}

Fraction Fraction :: operator++(int){
    int num = this -> numerator;
    this -> numerator = this -> numerator + this -> denomenator;
    Fraction F(num,this -> denomenator);
    return F;
}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

int num1,denum1,num2,denum2;
cin>>num1>>denum1>>num2>>denum2;

Fraction F1(num1,denum1);
Fraction F2(num2,denum2);
Fraction F3 = F1 + F2;
F3.print();
// Fraction F4 = ++F3;
// F4.print();
Fraction F4 = F3++;
F4.print();
F3.print();
return 0;
}