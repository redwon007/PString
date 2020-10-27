#include <iostream>
#include "PString.h"
using namespace std;

int main()
{
   PString a,b,c ;
    PString x("uvw");
    x.debug();

    PString y="abc";
    y.debug();

    PString w(y);
    w.debug();

    PString a1("Redwane"), b1, c1;
    c1=a1;
    a1.debug();
    b1.debug();
    c1.debug();

    PString a3("abcd");
    a3+='X';
    a3 += "chaine";

    a3.debug();

    PString a4="ab", b4="cd",c4;
    c4=a4+b4;
    c4.debug();

    PString a5="ab", b5="cd", c5;
    cout << "a=" << a5 << " b=" << b5 << " a+b=" << a5+b5 << endl;
    cout << a5[3]<< " " << b5[0] << endl;

    cout << a5.size()<<endl;
    PString a2("Redwane");
    a2+="zyyaaaaaaaaaaaaaaa";
    a2.debug();

    return 0;
}
