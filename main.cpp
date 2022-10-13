#include <iostream>
#include "SLLString.h"

using namespace std;

int main()
{
    SLLString str("Hello world!");
    SLLString newStr("Mr. Dude here!");

    newStr = str;
    newStr += SLLString(" CS@BC");

    newStr[6] = 'W';

    int loc = newStr.findSubstring("World");
    cout << loc << endl; // 6

    SLLString hi("hello");
    int loc2 = hi.findSubstring("lo");
    cout << loc2 << endl;

    newStr.erase('l');      //erase the letter l.
    cout << newStr << endl; // Heo Word! CS@BC

    newStr.erase('C');
    cout << newStr << endl; // Heo Word! S@B

    return 0;
}