#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

int main(){
    std::queue<char> myQ;
    myQ.push('R');
    myQ.push('O');
    myQ.push('D');
    myQ.push('N');
    myQ.push('E');
    myQ.push('E');
    display(myQ);

    std::cout<<"Queue empty status: "<<myQ.empty()<<std::endl;
    std::cout<<"Queue size: "<<myQ.size()<<std::endl;
    std::cout<<"Queue front: "<<myQ.front()<<std::endl;
    std::cout<<"Queue back: "<<myQ.back()<<std::endl;
    std::cout<<"Popping front: "<<std::endl;
    myQ.pop();
    display(myQ);
    std::cout<<"Pushing to back: "<<std::endl;
    myQ.push('R');
    display(myQ);

    return 0;
}

void display(std::queue<char> copyQ){
    std::queue<char> c=copyQ;
    while(!c.empty()){
        std::cout<<" "<<c.front();
        c.pop();
    }
    std::cout<<std::endl;
}

