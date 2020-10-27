#include <vector>
#include <iostream>
using namespace std ;

class PString
{
private:
    int ntotal_;
    int nutile_;
    char *p_;
public:
    PString();
    PString(const char *a);
    PString(const PString &a);

    ~PString();
    void debug();
    PString& operator=(const PString &a);
    PString& operator+=(const char c);
    PString& operator+=(const char* c);
    friend PString operator+(PString& a, PString& b);

    friend ostream& operator<<(ostream& o, const PString& a);
    friend istream& operator>>(istream& i,  PString& a);

    char operator[](int index) const noexcept(false);
    char& operator[](int index) noexcept(false);

    int size() const;
};
