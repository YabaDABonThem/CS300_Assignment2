#include <iostream>
#include "SLLString.h"

using namespace std;

void TestAssignment() {
    cout << "assign instance 2 to instance 1" << endl;
	SLLString mystring1("");
	SLLString mystring2("pie");
	mystring1 += mystring2;

	cout << "string 1: " << mystring1 << endl;
}

void TestAssignment2() {
    cout << "assign instance 2 to instance 1" << endl;
	SLLString mystring1("apple");
	SLLString mystring2("");
	mystring1 += mystring2;

	cout << "string 1: " << mystring1 << endl;
}

void TestCopyConstructor() {
    SLLString mystring1("pie");
	SLLString mystring2(mystring1);
}

int main()
{
    SLLString str("Hello world!");
    SLLString newStr("Mr. Dude here!");
    
    cout << newStr << endl;
    
    newStr = str;
    newStr += SLLString(" CS@BC");

    cout << newStr << endl;

    newStr[6] = 'W';
    cout << newStr << endl;

    int loc = newStr.findSubstring("World");
    cout << loc << endl; // 6

    SLLString hi("hello");
    int loc2 = hi.findSubstring("lo");
    cout << loc2 << endl; // 3
    loc2 = hi.findSubstring("lol");
    cout << loc2 << endl; // -1

    newStr.erase('l');      //erase the letter l.
    cout << newStr << endl; // Heo Word! CS@BC

    newStr.erase('C');
    cout << newStr << endl; // Heo Word! S@B

    SLLString().erase('c');
    
    TestAssignment();
    TestAssignment2();
    TestCopyConstructor();
    return 0;
}