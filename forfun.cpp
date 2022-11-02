#include <iostream>

using namespace std;


using TwoInt = int(*)(int,int);

template<typename T>
struct Vector{
    int dimension;
    int* content;

    Vector(int x):dimension(x){
        content = new T[dimension];
    }

    void operator() (){
        print();
    }
    void fillVector(){
        for(int i = 0; i < dimension ; i++){
            content[i] = i;
        }
    }
    void print(){
        for(int i = 0; i < dimension ; i++){
            cout<<content[i]<<" ";
        }
        cout<<" "<<endl;
    }
};


struct DoSomethingByX{
    int amount;
    TwoInt func;

    DoSomethingByX(int amount, TwoInt func):amount(amount),func(func){ }


    template<typename T>
    void operator()(T& container){
        for(int i = 0; i < container.dimension; i++){
            container.content[i] = func(i,amount);
        }
    }

};

template<typename T,typename Func>
void transform(T& container,Func func ){
    func(container);
}

int IncrementByX(int value,int amount){
    value = value+amount;
    return value;
}

int MultiplyByX(int value,int amount){
    value = value*amount;
    return value;
}

int main()
{

    auto v = Vector<int>(10);
    v.fillVector();
    v();

    
    
    auto increment = DoSomethingByX(5,IncrementByX);
    transform(v,increment);
    v();



    auto increment2 = DoSomethingByX(5,MultiplyByX);
    transform(v,increment2);
    v();
    
    auto increment44 = [amount = 44]<typename T>(T& container){
        for(int i = 0; i < container.dimension; i++){
            container.content[i] = IncrementByX(container.content[i],amount);
        }
    };
    
    transform(v,increment44);
    v();


    
auto v = vector<int>{1,2,3};
auto s = string("Emre");


for(auto it = s.begin(); it != s.end(); it++){
 cout<<*it<<endl;
}


for(auto it : s){
   cout<< it<<endl;
}



   return 0;
}
