//
//  main.cpp
//  numword - spell out numbers
//
//  Transform numbers to strings as if we would pronounce them
//  3 - three
//  13 - thirteen
//  33 - thirty tree
//  343 - three hundred fourty three
//  13343 - thirteen thousand three hundred fourty three
//  Created by Claudiu Ghioc on 25.05.23.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Numword {
private:
    int n;
    unordered_map<int, string> map;
    void init_map(void) {
        //cout << "Initializing the map\n";
        map[0] = "zero";
        map[1] = "one";
        map[2] = "two";
        map[3] = "three";
        map[4] = "four";
        map[5] = "five";
        map[6] = "six";
        map[7] = "seven";
        map[8] = "eight";
        map[9] = "nine";
        map[10] = "ten";
        map[11] = "eleven";
        map[12] = "twelve";
        map[13] = "thirteen";
        map[14] = "fourteen";
        map[15] = "fifteen";
        map[16] = "sixteen";
        map[17] = "seventeen";
        map[18] = "eighteen";
        map[19] = "nineteen";
        map[20] = "twenty";
        map[30] = "thirty";
        map[40] = "fourty";
        map[50] = "fifty";
        map[60] = "sixty";
        map[70] = "seventy";
        map[80] = "eighty";
        map[90] = "ninety";
        map[100] = "hundred";
        map[1000] = "thousand";
        map[1000000] = "million";
        map[1000000000] = "billion";
    }
    
    string pronounce(int a) {
        if (map.count(a) > 0) {
            return map[a];
        } else if (a < 100) {
            return pronounce(a - a % 10) + " " + pronounce(a % 10);
        } else if (a < 1000) {
            return pronounce(a / 100) + " " + pronounce(100) + " " + pronounce(a % 100);
        } else if (a < 1000000) {
            return pronounce(a / 1000) + " " + pronounce(1000) + " " + pronounce(a % 1000);
        } else if (a < 1000000000) {
            return pronounce(a / 1000000) + " " + pronounce(1000000) + " " + pronounce(a % 1000000);
        } else {
            return pronounce(a / 1000000000) + " " + pronounce(1000000000) + " " + pronounce(a % 1000000000);
        }
        
        return "";
    }
    
public:
    Numword() {
        init_map();
    };
    Numword(int a) : n(a) {
        init_map();
    };
    ~Numword() {
        //cout << "Calling destructor\n";
        map.clear();
    };
    
    int getnum() {
        return n;
    }
    
    friend ostream& operator<<(ostream& s, Numword &num) {
        s << num.pronounce(num.getnum());
        return s;
    }
};

int main(int argc, const char * argv[]) {
    Numword nw {};
    // insert code here...
    cout << "Hello, World!\n";
    nw = 4; cout << "My number is " << nw.getnum() << " - " << nw << endl;
    nw = 14; cout << "My number is " << nw.getnum() << " - " << nw << endl;
    nw = 44; cout << "My number is " << nw.getnum() << " - " << nw << endl;
    nw = 444; cout << "My number is " << nw.getnum() << " - " << nw << endl;
    nw = 914; cout << "My number is " << nw.getnum() << " - " << nw << endl;
    nw = 1345; cout << "My number is " << nw.getnum() << " - " << nw << endl;
    nw = 113947; cout << "My number is " << nw.getnum() << " - " << nw << endl;
    nw = 2903947; cout << "My number is " << nw.getnum() << " - " << nw << endl;
    nw = 1987654321; cout << "My number is " << nw.getnum() << " - " << nw << endl;
    
    return 0;
}
