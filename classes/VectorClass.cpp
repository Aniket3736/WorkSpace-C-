#include <iostream>
using namespace std;
 
class Vector{
    int *arr;
    int size;
    int capacity;
    
    public:
    /*---------------------------Constructors-------------------------*/
    Vector();
    Vector(Vector& rhs);
    Vector(int c);
    Vector(int c,int init);

    /*---------------------------Functions----------------------------*/
    int Size();
    int Capacity();
    void PushBack(int value);
    void Print();
    /*----------------------------Operators----------------------------*/
    friend ostream& operator<<(ostream& ostr,Vector& rhs);
    bool operator==(Vector &rhs);
    bool operator!=(Vector &rhs);
    Vector& operator=(Vector &rhs);
    int& operator[](int index);
};

Vector :: Vector():
arr(new int[1]),
size(0),
capacity(1)
{
    //Do Nothing
}

Vector :: Vector(int c):
arr(new int[c]),
size(0),
capacity(c)
{
    //Do Nothing
}

Vector :: Vector(int c, int init):
arr(new int[c]),
size(0),
capacity(c)
{
    for(int i = 0; i<c; i++) arr[i] = init;
    size = c;
}

int Vector :: Size(){
    return this -> size;
}

void Vector :: Print(){
    cout<<"Size :"<<size<<endl;
    cout<<"Capacity :"<<capacity<<endl;
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void Vector :: PushBack(int value){
    if(size < capacity){
        this -> arr[size++] = value;
        return;
    }
    else{
        capacity *= 2;
        int *newarray = new int[capacity];
        for(int i = 0; i<size; i++){
            newarray[i] = arr[i];
        }
        newarray[size++] = value;
        delete [] arr;
        arr = newarray;
    }
}

Vector :: Vector(Vector& rhs):
arr(new int[rhs.Capacity()])
{
    size = rhs.Size();
    capacity = rhs.Capacity();
    for(int i = 0; i<rhs.Size(); i++){
        this -> arr[i] = rhs.arr[i];
    }
}

int Vector:: Capacity(){
    return this -> capacity;
}

ostream& operator<<(ostream& ostr,Vector& rhs){
    for(int i =0; i<rhs.Size(); i++){
        ostr <<rhs.arr[i];
    }
    ostr<<endl;
    ostr <<"size :"<<rhs.Size()<<endl;
    ostr<<"capacity :"<<rhs.Capacity()<<endl;
    return ostr;    
}

int& Vector :: operator[](int index){
    return arr[index];
}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif
// Vector arr1(1,8);
// arr1.Print();
// arr1.PushBack(5);
// arr1.Print();
// arr1.PushBack(9);
// arr1.Print();
Vector arr1(5,8);
Vector arr2(arr1);
arr2.Print();
return 0;
}