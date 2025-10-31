#include <iostream>
#include <string>
using namespace std;

class Time{
        private:
        int S1; int M1; int H1; int D1;

        public:
        Time(int sec, int min, int hour, int day){
                if (0 <= sec && sec <= 999){
                        S1 = sec;
                }
                if (0 <= min && min <= 999){
                        M1 = min;
                }
                if (0 <= hour && hour <= 999){
                        H1 = hour;
                }
                if (0 <= day && day <= 999){
                        D1 = day;
                }
        }

        void add(const Time& a){
                S1 += a.S1;
                M1 += a.M1;
                H1 += a.H1;
                D1 += a.D1;

                M1 += S1 / 60;
                S1 = S1 % 60;

                H1 += M1 / 60;
                M1 = M1 % 60;

                D1 += H1 / 24;
                H1 = H1 % 24;
        }

        void substract(const Time& b){
                S1 -= b.S1;
                M1 -= b.M1;
                H1 -= b.H1;
                D1 -= b.D1;

                while (S1 < 0){
                        S1 += 60;
                        M1 -= 1;
                }

                while (M1 < 0){
                        M1 +=60;
                        H1 -= 1;
                }


                while (H1 <= 0){
                        H1 +=24;
                        D1 -= 1;
                }

                M1 += S1 / 60;
                S1 = S1 % 60;

                H1 += M1 / 60;
                M1 = M1 % 60;

                D1 += H1 / 24;
                H1 = H1 % 24;
        }
        void print(){
                cout << S1 << " seconds " << M1 << " minutes " << H1 << " hours " << D1 << " days" << endl;
        }

};

int main(){
        int s1, m1, h1, d1;
        cin >> s1 >> m1 >> h1 >> d1;
        Time time(s1, m1, h1, d1);
        char sign;
        cin >> sign;

        if (sign == '+'){
                int s2, m2, h2, d2;
                cin >> s2 >> m2 >> h2 >> d2;
                Time addition(s2, m2, h2, d2);
                time.add(addition);
        } else if (sign == '-'){
                int s2, m2, h2, d2;
                cin >> s2 >> m2 >> h2 >> d2;
                Time substraction(s2, m2, h2, d2);
                time.substract(substraction);
        }

        time.print();
        return 0;
}
