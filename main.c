#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STACK_MAX_SIZE 100
#define QUEUE_MAX_SIZE 100

using namespace std;

class tool{
private:
    string name;
    int price;
    string com;
public:
    tool(){
        name="Invalid";
        price=0;
        com="None";
    }
    tool(string n, int p, string c){
        name=n;
        price=p;
        com=c;
    }
    string getName(){
        return name;
    }
    int getPrice(){
        return price;
    }
    string getCom(){
        return com;
    }

};


struct listNode
{
    tool *item;
    listNode * next;
};

struct listNode * head;

void initializeList()
{
    head=0;
}

void insertItem(tool *item)
{
	struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = head;
	head = newNode ;
}

struct listNode * searchItem(string item)
{
	struct listNode * temp ;
	temp = head;
	while (temp != 0)
	{
		if (temp->item->getName() == item) return temp ;
		temp = temp->next ;
	}
	return 0 ;
}


class Stack{
private:
    tool stack[STACK_MAX_SIZE];
    int top;
public:
    Stack(){
        top=0;
    }
    bool push(tool item)
    {
        if(top == STACK_MAX_SIZE) return false ;
        stack[top] = item ;
        top++ ;
        return true ;
    }
    tool pop()
    {
        tool none;
        if(top == 0) return none;
        top-- ;
        return stack[top] ;
    }
    int getLength(){
        return top;
    }
    bool isEmpty(){
        if(top==0) return true;
        else return false;
    }
    bool isFull(){
        if(top==STACK_MAX_SIZE) return true;
        else return false;
    }

};

class Queue{
private:
    string queue[QUEUE_MAX_SIZE];
    int length,front,rear;
public:
    Queue(){
        length=0;
        front=0;
        rear=0;
    }
    bool enqueue(string item){
        if(length == QUEUE_MAX_SIZE) return false ;
        queue[front] = item ;
        front++ ;
        length++ ;
        return true ;
    }
    string dequeue(){
        if(length == 0) return 0 ;
        string item = queue[rear] ;
        rear++ ;
        length-- ;
        return item ;
    }
    int getLength(){
        return length;
    }
    bool isEmpty(){
        if(length==0) return true;
        else return false;
    }
    bool isFull(){
        if(length==QUEUE_MAX_SIZE) return true;
        else return false;
    }

};

int main(){
    initializeList();
    tool *blender=new tool("blender",1500,"Korea");
    tool *kettle=new tool("kettle",800,"Japan");
    tool *trimmer=new tool("trimmer",150,"Thailand");
    tool *toaster=new tool("toaster",200,"Vietnam");
    insertItem(blender);
    insertItem(kettle);
    insertItem(trimmer);
    insertItem(toaster);
}
