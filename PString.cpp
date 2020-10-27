#include "PString.h"
#include <iostream>
using namespace std ;

PString::PString()
{
    ntotal_ = 10;
    nutile_ = 0;
    p_ = new char[ntotal_];
    cout <<  "Construction PString sans paramètres adr =" << this << endl ;
}

PString::PString(const char *a){
    nutile_ = 0;
    int i = 0;
    while(a[i] != 0){
        nutile_ +=1;
        i++;
    }

    ntotal_ = nutile_ + 5;
    p_ = new char[ntotal_];
    for(int k  = 0; k<nutile_; k++){
        p_[k] = a[k];
    }
    cout <<  "Construction PString à partir d'une chaine C adr =" << this << endl ;
}

PString::PString(const PString &a){
    ntotal_ = a.ntotal_;
    nutile_ = a.nutile_;
    p_ = new char[ntotal_];

    for(int i = 0; i<nutile_; i++){
        p_[i] = a.p_[i];
    }

}

PString::~PString(){
    delete[] p_;
}
void PString::debug(){
    cout << "ntotal_ : " << ntotal_ << endl;
    cout << "nutile_ : " << nutile_ << endl;
    for(int i = 0; i < nutile_; i++){
        cout << p_[i] <<endl;
    }
}

PString& PString::operator=(const PString& a){
    ntotal_ = a.ntotal_;
    nutile_ = a.nutile_;

    for(int i = 0; i < nutile_; i++){
        p_[i] = a.p_[i];
    }

}

PString& PString::operator+=(const char c){
    //PString z(*this);
    ntotal_ += 1;
    nutile_ += 1;

    /*for(int i = 0; i < z.nutile_; i++){
        p_[i] = z.p_[i];
    }*/

    p_[nutile_-1] = c;
}

PString& PString::operator+=(const char* c){
    int i = 0;
    while(c[i] != 0){
        *this += c[i];
        i++;
    }
}

PString operator+(PString& a, PString& b){
    PString z(a);
    delete[] z.p_;

    z.ntotal_ += b.ntotal_;
    z.nutile_ += b.nutile_;
    z.p_ = new char[a.nutile_];
    for(int i = 0; i<z.nutile_; i++){
        if(i<a.nutile_) z.p_[i] = a.p_[i];
        else z.p_[i] = b.p_[i-b.nutile_];
    }
    return z;
}
ostream& operator<<(ostream& o, const PString& a){
    for(int i=0; i<a.nutile_; i++){
        o<<a.p_[i];
    }
    return o;
}

istream& operator>>(istream& i,  PString& a){
    char c;
    while(i.get(c) && c != ' ' && c != '\n' && c != '\t'){
        a += c;
    }
    return i;
}

char PString::operator[](int index) const{
    if(index>nutile_ || index < 0) throw out_of_range("out of range");
    return p_[index];
}

char& PString::operator[](int index){
    if(index>nutile_ || index < 0) throw out_of_range("out of range");
    return p_[index];
}

int PString::size() const{
    return nutile_;
}
