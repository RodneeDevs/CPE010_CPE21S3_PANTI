#include<iostream>
#include<iomanip>

int Sumoftwonum(int Fnum,int Snum);
void Greaternum(int Unum,int Dnum);
void Boolfunc(bool tralala,bool lalala);

int main(){

    std::cout<<"The sum of two numbers is: "<<Sumoftwonum(6,7)<<std::endl;
    Greaternum(6,9);
    Boolfunc(true,false);
}
int Sumoftwonum(int Fnum,int Snum){
    int sum=Fnum+Snum;
    return sum;
}
void Greaternum(int Unum,int Dnum){
    if(Unum<Dnum){
        std::cout<<Unum<<" is less than "<<Dnum<<std::endl;
    }else{
        std::cout<<Unum<<" is greater than "<<Dnum<<std::endl;
    }
}
void Boolfunc(bool tralala,bool lalala){
    std::cout << "Logical AND (a && b):    " << (tralala && lalala) << std::endl;
    std::cout << "Logical OR (a || b):     " << (tralala || lalala) << std::endl;
    std::cout << "Logical NOT (!a):        " << (!tralala) << std::endl;
    std::cout << "Logical NOT (!b):        " << (!lalala) << std::endl;
    std::cout << "Logical XOR (a ^ b):     " << (tralala ^ lalala) << std::endl;
}