#include <iostream>
#include "queueLL.h"

int main(){
    qNode<char>* front=nullptr;
    qNode<char>* back=nullptr;

    std::cout<<"Enqueuing: "<<std::endl;
    enqueue('R',&front,&back);
    std::cout<<front->data<<" "<<back->data<<std::endl;
    enqueue('O',&front,&back);
    std::cout<<front->data<<" "<<back->data<<std::endl;
    enqueue('D',&front,&back);
    std::cout<<front->data<<" "<<back->data<<std::endl;
    enqueue('N',&front,&back);
    std::cout<<front->data<<" "<<back->data<<std::endl;
    enqueue('E',&front,&back);
    std::cout<<front->data<<" "<<back->data<<std::endl;
    enqueue('E',&front,&back);
    std::cout<<front->data<<" "<<back->data<<std::endl;

    std::cout<<"Front: "<<std::endl;
    checkFront(front);

    std::cout<<"Back: "<<std::endl;
    checkBack(back);

    std::cout<<"Display all: "<<std::endl;
    displayAll(&front,&back);
    std::cout<<std::endl;

    std::cout<<"Dequeuing: "<<std::endl;
    dequeue(&front,&back);
    std::cout<<front->data<<" "<<back->data<<std::endl;
    dequeue(&front,&back);
    std::cout<<front->data<<" "<<back->data<<std::endl;
    dequeue(&front,&back);
    std::cout<<front->data<<" "<<back->data<<std::endl;

    std::cout<<"Front: "<<std::endl;
    checkFront(front);

    std::cout<<"Back: "<<std::endl;
    checkBack(back);


    return 0;
}

