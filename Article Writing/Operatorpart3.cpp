class fraction{
    public : 
    int numerator;
    int denominator;

    fraction(){
        numerator = 1;
        denominator = 1;
    }
    fraction(int a,int b){
        numerator = a;
        denominator = b;
    }
/*-------------------------Operators-------------------------------*/
    fraction operator* (fraction f2);
    bool operator>= (fraction f2);
    fraction& operator++();
    fraction operator++(int);
};

fraction :: fraction operator* (fraction f2){
    int n,d;
    n = (this -> numerator) * f2.numerator;
    d = (this -> denominator) * f2.denominator;
    fraction f3(n,d);
    return f3;
}

bool fraction :: operator>= (fraction f2){
    return this -> numerator == f2.numerator && this -> denominator == f2.denominator;
}

fraction& fraction :: operator++(){
    this -> numerator += this -> denominator;
    return (*this);
}