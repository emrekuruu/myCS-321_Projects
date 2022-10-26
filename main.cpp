#include <iostream>

using namespace std;

int step = 0;


using multiply = int (*) (int);


struct Fraction{

    int up;
    int down;


    Fraction(int up, int down):up(up),down(down){

    }

    Fraction():up(0),down(1){

    }
    Fraction(int n):up(n),down(1){

    }

    operator double(){
        return value();
    }

    double value(){
         return ((double)this->up/this->down);
    }


};

void print(const Fraction& f){
    cout<<f.up<<"/"<<f.down<<endl;
}

void mult(multiply function,Fraction& f){
    f.up = function(f.up);
    f.down = function(f.down);
}

int multBy2(int x){
    return x*2;
}

int multBy3(int x){
    return x*3;}

Fraction operator"" _frac(long double value)
{
    return Fraction((int)value);
}


struct Vector2d{
    int x;
    int y;
    char* c;

    Vector2d(int x,int y){
      this->x = x;
      this->y = y;
      c = new char[1000];
    }

    Vector2d(){

    }

    ~Vector2d(){
        delete[] c;
    }

};


void print(const Vector2d& A){
    cout<<A.x<<" "<<A.y<<endl;
}

Vector2d add(const Vector2d& v1,const Vector2d& v2){
    Vector2d result;
    result.x = v1.x+v2.x;
    result.y = v1.y+v2.y;
    return result;
}

int main()
{

    Vector2d A = Vector2d();
    A.x = 1;
    A.y = 2;

    Vector2d B = Vector2d(3,4);

    print(A);
    print(B);

    auto C = add(A,B);
    print(C);


        Fraction f(10, 3);
        auto f1 = Fraction(10, 3);

        auto f2 = Fraction(10);
        auto f3 = Fraction();

        std::cout << f1.value() << std::endl;
        std::cout << (double)f1 << std::endl;

        double d;
        d = f1;

        print(f1);
        print(f2);
        print(f3);

        f1 = f3; // assignment
        auto f4 = f3; // copy construction
        f4 = f1; // assignment
        auto f5 = Fraction(f3); // copy construction  // Fraction(f3.n, f3.d);


        print(f1);
        print(f4);


        auto f6 = 10.0_frac;
        print(f6);

        mult(multBy3,f6);
        print(f6);

  ;


   return 0;
}
