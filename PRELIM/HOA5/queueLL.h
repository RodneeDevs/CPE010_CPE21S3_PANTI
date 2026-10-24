#ifndef QUEUELL_H
#define QUEUELL_H

template <typename T>
class qNode{
    public:
        T data;
        qNode<T>* next;

};

template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode=new qNode<T>;
    newNode->data=newData;
    newNode->next=nullptr;
    return newNode;
};

template <typename T>
void enqueue(T newData,qNode<T>** frontPtr,qNode<T>** backPtr){
    qNode<T>* newNode=new_node(newData);

    if((*frontPtr)==nullptr&&(*backPtr)==nullptr){
        (*frontPtr)=newNode;
        (*backPtr)=newNode;
        return;
    }

    (*backPtr)->next=newNode;
    (*backPtr)=newNode;
}

template <typename T>
void dequeue(qNode<T>** frontPtr,qNode<T>** backPtr){
    qNode<T>* deleteNode=nullptr;
    deleteNode=(*frontPtr);

     if((*frontPtr)==nullptr&&(*backPtr)==nullptr){
        std::cout<<"The queue is empty\n";
        return;}

    if((*frontPtr)->next==nullptr&&(*backPtr)->next==nullptr){
        (*frontPtr)=nullptr;
        (*backPtr)=nullptr;
        delete deleteNode;
    }

    (*frontPtr)=(*frontPtr)->next;
    deleteNode->next=nullptr;
    delete deleteNode;
}

template<typename T>
void checkFront(qNode<T>* frontPtr){
    if((frontPtr)==nullptr) return;

    std::cout<<frontPtr->data<<std::endl;
}

template<typename T>
void checkBack(qNode<T>* backPtr){
    if((backPtr)==nullptr){
        std::cout<<"Front is empty"<<std::endl;
        return;
    }
    std::cout<<backPtr->data<<std::endl;
}

template<typename T>
void displayAll(qNode<T>** frontPtr,qNode<T>** backPtr){
    if((*frontPtr)==nullptr&&(*backPtr)==nullptr){
        std::cout<<"Queue is empty"<<std::endl;
        return;
    }
    qNode<T>* displayNode=nullptr;
    displayNode=(*frontPtr);

    while(displayNode->next!=nullptr){
        std::cout<<displayNode->data;
        displayNode=displayNode->next;
    }
    std::cout<<displayNode->data<<std::endl;
}

#endif