#include <iostream>
#include <thread>
#include <vector>

int adder = 10;

void add(int n){
    int sum;
    std::cout<<"Initial input: "<< n << std::endl;

    sum = n + adder;
    std::cout<<"Final output (added number was 10): "<< sum << std::endl;
}

void print(int n, const std::string &str) {
    std::string msg = std::to_string(n) + " : " + str;
    std::cout << msg << std::endl;
}

int main() {

    std::vector<std::string> s = {
        " T.I.P. ",
        " Competent ",
        " Computer ",
        " Engineers"
};

    std::vector<std::thread> threads;

    for (int i = 0; i < s.size(); i++) {
        threads.push_back(std::thread(print, i, s[i]));
}

    for (auto &th : threads) {
        th.join();
}

//SUPPLEMENTARY 
    std::thread t1(add, 6);
    t1.join();

    std::thread t2(add, 7);
    t2.join();

    std::thread t3(add, 8);
    t3.join();
    
return 0;
}