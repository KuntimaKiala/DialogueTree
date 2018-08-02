#include <iostream>
#include <cstdint>
#include <inttypes.h>

using namespace std;


void addOne(int *myPointer) ;
void addTwo(int &integer);
void addThree(int a) ;
int main(){

    // Stack
    int a = 5 ;
    int *pointer = nullptr ;
    pointer = &a ;


    cout << &*pointer << endl ;
    cout << *pointer << endl ;
    cout << &a << endl ;
    addOne( pointer) ;
    //a = 10 ;
    a+=1 ;
    cout << *pointer << endl ;
    cout << pointer << endl ;
    cout << &a << endl ;



    // Heap

 int *myPointer = nullptr ;
 myPointer = new int[1000];
cout << myPointer << endl ;
 delete[] myPointer ;


int *MyPointer = nullptr ;
MyPointer = new int ;
*MyPointer = a*2;
addOne(MyPointer) ;
cout << *MyPointer << endl ;
delete MyPointer ;



int integer = 0 ;
cout << integer << endl ;
addTwo(integer) ;
cout << integer << endl ;

int valor = 0 ;
cout << valor << endl;
addThree(valor) ;
cout << valor << endl;

    return 0;
}


void addOne(int *myPointer){
    *myPointer += 5 ;
}


void addTwo (int &integer){

 integer += 2 ;
}


void addThree(int a ) {
 a+=3 ;
}
