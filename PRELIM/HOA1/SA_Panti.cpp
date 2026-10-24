#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void SN(double &val1, double &val2) {
    double temp = val1;
    val1 = val2;
    val2 = temp;
}

double KTF(double kelvin) {
    return (kelvin - 273.15) * 9.0 / 5.0 + 32.0;
}

double CD(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double CA(double sideA, double sideB, double sideC) {
    double semiPerim = (sideA + sideB + sideC) / 2.0;
    return sqrt(semiPerim * (semiPerim - sideA) * (semiPerim - sideB) * (semiPerim - sideC));
}

double CP(double sideA, double sideB, double sideC) {
    return sideA + sideB + sideC;
}

int main() {
    double firstNum = 10.5, secondNum = 25.8;
    cout << "Original: A = " << firstNum << ", B = " << secondNum << endl;
    SN(firstNum, secondNum);
    cout << "Swapped: A = " << firstNum << ", B = " << secondNum << endl;

    double originalKelvin = 300.0;
    cout << originalKelvin << " Kelvin = " << KTF(originalKelvin) << " Fahrenheit" << endl;

    double ptA_x = 0, ptA_y = 0;
    double ptB_x = 3, ptB_y = 4;
    double lineLength = CD(ptA_x, ptA_y, ptB_x, ptB_y);
    cout << "The straight-line distance is: " << lineLength << endl;
    double vertexA_x = 0, vertexA_y = 0;
    double vertexB_x = 4, vertexB_y = 0;
    double vertexC_x = 2, vertexC_y = 3;
    double side1 = CD(vertexA_x, vertexA_y, vertexB_x, vertexB_y);
    double side2 = CD(vertexB_x, vertexB_y, vertexC_x, vertexC_y);
    double side3 = CD(vertexC_x, vertexC_y, vertexA_x, vertexA_y);
    cout << "Calculated sides: " << side1 << ", " << side2 << ", " << side3 << endl;
    cout << "Total Area      : " << CA(side1, side2, side3) << endl;
    cout << "Total Perimeter : " << CP(side1, side2, side3) << endl;

    return 0;
}