#include<iostream>
using namespace std;
// class to immpliment the Queue funcitionalities
class Queue{
    public:
    int front;
    int rear;
    int size;
    int *arr;
    Queue(int size=1):size(size),rear(-1),front(-1),arr(new int (size)){}
    bool isEmpty();
    bool isFull();
    void EnQueue();
    void DeQueue();
    void Display();
};
//Fuction to check weather the Queue is empty or not will return Ture if it is empty
bool Queue::isEmpty(){
    return front==-1;
}
//fuction will return Ture if the Queue is Full
bool Queue::isFull(){
    return (rear+1)%size==front;
}

//function to insert element to the Queue
void Queue::EnQueue(){
    if(isFull()){cout<<"The Queue is Full Queue OverFlow occurs"<<endl;return;
    }
   int value;
    cout<<"Enter the value you want to add to the new Node "<<endl;
    cin>>value;
    if(isEmpty()){
        front++;
        rear++;
        arr[rear]=value;
    }
    rear=(rear+1)%size;
    arr[rear]=value;

}

//funtion to delete an element from the Queue
void Queue::DeQueue(){
    if(isEmpty()){cout<<"The Queue is Empty Queue Underflow occurs"<<endl;
    return ;}else{
        
            if(front==rear){
                rear=front=-1;
                return;
            }
        front=(front+1)%size;
       
        

    }
}
//This function will display the Queue
void Queue::Display(){
    if(isEmpty()){cout<<"The Queue is Empty can't Display any thing right now"<<endl;
    return ;}
    int temp=front;
    while(true){
        cout<<arr[temp]<<" ";
        if(temp==rear){break;}

        temp=(temp+1)%size;
    }
    cout<<endl;
}
// this is a menu funtion which will prompt the user the size of the Queue and display the menu 
void menu(){
    int size;
    cout<<"\n#####Welcome to the  the circualar Queue implimentation with arrys####"<<endl;
    cout<<"Enter the size of the Queue whatever you want to set"<<endl;
    cin>>size;
    Queue Q(size);
    int choice;
    do{
        
   
    cout<<"1.To EnQueue"<<endl;
    cout<<"2.To DeQueue"<<endl;
    cout<<"3.To print the Number of nodes present in the Queue"<<endl;
    
    cout<<"\nEnter your choice from 1-3"<<endl;
    cin>>choice;
    
    switch(choice){
    case 1:
    Q.EnQueue();
    break;
    case 2:
    Q.DeQueue();
    break;
    case 3:
    Q.Display();
    break;
    default:
    cout<<"YOu enterd wrong number re-Enter the choice"<<endl;
    
    
    }}while(choice>0&& choice<4);}


    int main(){

        menu();
        return 0;
    }
