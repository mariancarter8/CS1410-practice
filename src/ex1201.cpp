#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Calculator {
    private:
        T a, b;

    public:
        Calculator(int a, int b): a(a), b(b){}

        T add() const{ return a + b;}
        T subtract() const{ return a - b;}
        T multiply() const{ return a * b;}
        T divide() const{ 
            if(b == 0){
                throw runtime_error("Division by zero");
            }
            
            return a / b;
        }
    };

int main (){
    try{
        Calculator<double> c(10.0, 2.0);
        cout << c.add() << endl;
        cout << c.subtract() << endl;
        cout << c.multiply() << endl;
        cout << c.divide() << endl;

        Calculator<int> c1(4, 0);
        cout << c1.add() << endl;
        cout << c1.subtract() << endl;
        cout << c1.multiply() << endl;
        cout << c1.divide() << endl;

    } catch (const runtime_error& e) {
        cerr << "An exception happened: " << e.what() << endl;
    }


    return 0;
};