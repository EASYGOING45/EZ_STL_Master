#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "abc";
    cout << s.find('a') << endl;
    cout << s + 'd' << endl;
    cout << s.at(1) << endl;
    cout << s[2] << endl;
}