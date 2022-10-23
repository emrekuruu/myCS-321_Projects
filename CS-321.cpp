#include <iostream>

using namespace std;

int step = 0;
int cStep = 0;

template<typename T>
using oneInt = T (*)(T);

template<typename T>
using twoInt = T (*)(T,T);



template<typename T>
struct Fahrenheit;


template<typename T>
struct Celcius{
    T C;
    Celcius(T c):C(c){print();}
    Celcius(Fahrenheit<T> f);



    void operator=(Fahrenheit<T> f);


    void print(){cStep++;
                std::cout<<"\nStep: "<<cStep<<"\n"<<this->C<<" Celcius"<<std::endl;}

};

template<typename T>
struct Fahrenheit{
    T F;
    Fahrenheit(T f):F(f){print();}

    void print(){
        cStep++;
        std::cout<<"\nStep: "<<cStep<<"\n"<<this->F<<" Fahrenheit"<<std::endl;}

};



template<typename T>
void Celcius<T>::operator=(const Fahrenheit<T> f1){
        this->C = (f1.F - 32)/180*100;
        print();
}


template<typename T>
Celcius<T>::Celcius(Fahrenheit<T> f){
    std::cout<<("\nThis is a Construcation");
    this->C = (f.F-32)/180*100;
    print();
}



Celcius<double> operator"" _c(long double value){
    return Celcius<double>(value);
}


Fahrenheit<double> operator"" _f(long double value){
    return Fahrenheit<double>(value);
}


template<typename T>
struct Vector{
    int dimentionNum;
    T* content;

    Vector(){}

    Vector(int dimention,T* y){
        this->dimentionNum = dimention;
        this->content = y;
        print();
    }

    Vector(const Vector& v2){
         this->dimentionNum = v2.dimentionNum;
         this->content = v2.content;
         std::cout<<"\nI am being copy constructed";
         print();
     }

    ~Vector(){
        delete[] content;
    }
    void print(){
            step++;
            std::cout<<"\nStep: "<<step<<std::endl;
            for(int i = 0; i < this->dimentionNum; i++){
                std::cout<<this->content[i]<<std::endl;
            }
     }


};

template<typename T>
bool operator+(Vector<T>& v,const Vector<T>& v2){


    if(v.dimentionNum != v2.dimentionNum){
        step++;
        std::cout<<"\nAddition cannot be done dimensions do not match!"<<"The step failed is: " <<step<<std::endl;
        return false;
       }

    for(int i = 0; i < v.dimentionNum; i++){
        v.content[i] += v2.content[i];
    }
    v.print();

    return true;
}

template<typename T>
void for_each(Vector<T>& container, oneInt<T> function){
    auto size = container.dimentionNum;
    for(int i = 0; i < size; i++){
        container.content[i] = function(container.content[i]);
    }
}

int increment(int x){
    x++;
    return x;
}

int Double(int x){
    x=x*2;
    return x;
}
int Square(int x){
    x=x*x;
    return x;
}

int main()
{

   //number of Dimentions
   auto x = 4;
   auto y = 4;

   int content1[4] = {1,2,3,4};
   int content2[5] = {-1,2,4,5,6};

   //Step1
   auto v1 = Vector<int>(x,content1);

   //Step2

   auto v2 = Vector<int>(y,content2);

   //Step3
   auto v3 = Vector<int>(v2);


   //Step4
   auto is_okay = v1+v3;
   if(is_okay){std::cout<<"\nNew V1 values";v1.print();}


   // END OF vector part
   // START OF FUNCTION POINTERS

   for_each<int>(v1,Square);
   v1.print();

   // END OF FUNCTION POINTERS

   //Step 1
   auto c1 = Celcius<double>(12);

   //Step 2
   auto f1 = Fahrenheit<double>(59.5);

   //Step 3
   c1 = f1;

   //Step 4
   auto c2 = Celcius<double>(f1);

   //Step 5
   auto c3 = 11.5_c;

   //Step 6
   auto f2 = 75.0_f;

   //Step 7
   c3 = f2;

   //END OF CELCIUS-FAHRENHEIT EXAMPLE
