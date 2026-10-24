#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

class Triangle {
private:
    double totalangle,angleA,angleB,angleC;
    double sideA,sideB,sideC;

public:
    Triangle(double A, double B, double C, double sA, double sB, double sC);
    void setProperties(double A, double B, double C, double sA, double sB, double sC);
    const bool validateTriangle();
    double CA(); 
    double CP(); 
    string CT(); 
};

int main() {
    Triangle set1(60, 90, 30, 3, 4, 5);

    if (set1.validateTriangle()) {
        cout << "The shape is a valid triangle" << endl;
        cout << "Area         : " << set1.CA() << endl;
        cout << "Perimeter    : " << set1.CP() << endl;
        cout << "Type         : " << set1.CT() << endl;
    } else {
        cout << "The shape is NOT a valid triangle" << endl;
    }

    return 0;
}

Triangle::Triangle(double A, double B, double C, double sA, double sB, double sC) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalangle = A + B + C;
    sideA = sA;
    sideB = sB;
    sideC = sC;
}

void Triangle::setProperties(double A, double B, double C, double sA, double sB, double sC) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalangle = A + B + C;
    sideA = sA;
    sideB = sB;
    sideC = sC;
}

const bool Triangle::validateTriangle() {
    return (totalangle <= 180.0);
}

double Triangle::CA() {
    double s = (sideA + sideB + sideC) / 2.0;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

double Triangle::CP() {
    return sideA + sideB + sideC;
}

string Triangle::CT() {
    if (angleA < 90 && angleB < 90 && angleC < 90) {
        return "Acute-angled";
    } else if (angleA > 90 || angleB > 90 || angleC > 90) {
        return "Obtuse-angled";
    } else {
        return "Others (Right-angled)";
    }
}