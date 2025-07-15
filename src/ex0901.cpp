#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

class Color{
    private:
        double r, g, b;

    public:
        Color():r(0.0), g(0.0), b(0.0){}
        Color(double r, double g, double b):r(r), g(g), b(b){}

        string toRGB() const{
            stringstream sout;
            sout << "rgb(" << static_cast<int>(r * 255) << "," << static_cast<int>(g * 255)
                << "," << static_cast<int>(b * 255) << ")";

            return sout.str();
        }

        string toHEX() const{ // #01AC03
            stringstream sout;
            sout << "#" << setfill('0') << hex 
                << setw(2) << static_cast<int>(r * 255) 
                << setw(2) << static_cast<int>(g * 255)
                << setw(2) << static_cast<int>(b * 255);

            return sout.str();
        }

        friend ostream& operator<<(ostream& out, const Color& c){
            out << c.toHEX();
            return out;
        }

        friend istream& operator>>(istream& in, Color& c){
            in >> c.r >> c.g >> c.b;
            return in;
        }

        double operator[](int index) const {
            switch(index){
                case 0: return r;
                case 1: return g;
                case 2: return b;
                default: return -1.0;
            }
        }

        double& operator[](int index) {
            switch(index){
                case 0: return r;
                case 1: return g;
                case 2: return b;
                default: throw -1.0;
            }
        }

        bool operator ==(const Color& c){
            return r == c.r && g == c.g && b == c.b;
        }
};

int main (){
    Color c; // Black
    Color c1(1.0, 0.25, .5);

    cout << c << endl; // <<(cout, c)
    cout << c1 << endl;

    cout << c.toRGB() << "---" << c.toHEX() << endl;
    cout << c1.toRGB() << "---" << c1.toHEX() << endl;

    Color c2;
    cout << "Enter a color (three values between 0.0 and 1.0):";
    cin >> c2;

    cout << "\nC1 red:" << c1[0] << endl; // read only
    cout << "\nC2 green:" << c1[1] << endl;
    cout << "\nC3 blue:" << c1[2] << endl;

    c2[1] = .6; //write

    if(c1 == c2){ // ==(c1, c2) belongs to a class we created so we use a member function becomes c1.== (c2)
        cout << "same" << endl;
    }else{
        cout << "different" << endl;
    }


    return 0;
}