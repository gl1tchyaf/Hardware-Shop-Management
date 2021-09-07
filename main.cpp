#include <bits/stdc++.h>
#include <string.h>
#include "LinkedListProduct.h"
#include "StackClass.h"

using namespace std;

LinkedListProduct linkedListProduct;
StackClass stClass;

StackClass::StackClass(){

stackPtr=NULL;

}

StackClass::~StackClass(){

item *p1;
item *p2;

p1=stackPtr;

while(p1!=NULL){

    p2=p1;

    p1=p1->previous;
    p2->previous=NULL;
    delete p2;

}

}

void StackClass::push(string name,string date,double Sellingprice,double Buyingprice,string buyer,string seller,int productNumber){

item *lt=new item;

lt->name=name;
lt->date=date;
lt->Sellingprice=Sellingprice;
lt->Buyingprice=Buyingprice;
lt->buyer=buyer;
lt->seller=seller;
lt->productNumber=productNumber;

if(stackPtr==NULL){

    stackPtr=lt;

    stackPtr->previous=NULL;

}else{

lt->previous=stackPtr;

stackPtr=lt;

}

}

void StackClass::readItem(item *it){

cout<<"Name: "<<it->name<<endl;
cout<<"Date: "<<it->date<<endl;
cout<<"Buying Price: "<<it->Buyingprice<<endl;
cout<<"Selling Price: "<<it->Sellingprice<<endl;
cout<<"Seller: "<<it->seller<<endl;
cout<<"Buyer: "<<it->buyer<<endl;
cout<<"Product number: "<<it->productNumber<<endl;

}

void StackClass::pop(){

if(stackPtr==NULL){

    cout<<"There is nothing to delete"<<endl;

}else{

item *p=stackPtr;

readItem(p);

stackPtr=stackPtr->previous;

p->previous=NULL;

delete p;

}

}

void StackClass::print(){

item *p=stackPtr;

while(p!=NULL){

cout<<"\n               Information         "<<endl<<endl;

    readItem(p);

    cout<<endl;
    cout<<endl;

    p=p->previous;

}

}

LinkedListProduct::LinkedListProduct(){

head=NULL;
temp=NULL;
current=NULL;

}

void LinkedListProduct::AddData(string name,double Sellingprice,double Buyingprice,string buyer,string seller,int month,int date,int year,int productNumber){

Node *n=new Node;

n->next=NULL;

n->name=name;
n->date=date;
n->Buyingprice=Buyingprice;
n->buyer=buyer;
n->month=month;
n->seller=seller;
n->productNumber=productNumber;
n->year=year;
n->Sellingprice=Sellingprice;

if(head!=NULL){

    current=head;

    while(current->next!=NULL){

        current=current->next;

    }

    current->next=n;

}else{

head=n;

}

}

void LinkedListProduct::deleteData(int productNumber){

node delPtr=NULL;

temp=head;
current=head;

while(current!=NULL && current->productNumber!=productNumber){

    temp=current;

    current=current->next;

}

if(current==NULL){

    cout<<productNumber<<" is not at here: "<<endl;

    delete delPtr;

}else{

delPtr=current;

current=current->next;

temp->next=current;

delete delPtr;

cout<<"The data is deleted"<<endl;

}

}

void LinkedListProduct::deleteData1(int productNumber){

node delPtr=NULL;

temp=head;
current=head;

while(current!=NULL ){

    temp=current;

    if(current->productNumber==productNumber){

    cout<<"product: "<<current->productNumber;

        linkedListProduct.deleteData(productNumber);

        string date11=( to_string( current->date )+"/" );
        string date12=(  date11+to_string( current->month ) );
        string date13=( date12+"/" );
        string date1=( date13+to_string( current->year ) );

        stClass.push( current->name, date1, current->Sellingprice, current->Buyingprice, current->buyer, current->seller,productNumber);
return;
    }

    current=current->next;

}

if(current==NULL){

    cout<<productNumber<<" is not at here: "<<endl;

    delete delPtr;

}else{

delPtr=current;

current=current->next;

temp->next=current;

delete delPtr;

cout<<"The data is deleted"<<endl;

}

}

void LinkedListProduct::seeData(){

current=head;

while(current!=NULL){

cout<<"\n               Information         "<<endl<<endl;

cout<<"Name: "<<current->name<<endl;
cout<<"Date: : "<<current->date<<"/"<<current->month<<"/"<<current->year<<endl;
cout<<"Buying Price: "<<current->Buyingprice<<endl;
cout<<"Buying Price: "<<current->Sellingprice<<endl;
cout<<"Product Number: "<<current->productNumber<<endl;
cout<<"Buyer: "<<current->buyer<<endl;
cout<<"Seller: "<<current->seller<<endl;

    current=current->next;

}

cout<<endl<<endl;

}

int menu(){

int choice;

cout<<"Menu"<<endl;

cout<<"1: Add Product"<<endl;
cout<<"2: Take Order"<<endl;
cout<<"3: See Product's"<<endl;
cout<<"4: See Order's"<<endl;
cout<<"5: Monthly search"<<endl;
cout<<"6: Delete Product"<<endl;
cout<<"7: Exit"<<endl;

cout<<"Enter your choice: ";
cin>>choice;

return choice;

}

string name;
double Sellingprice;
double Buyingprice;
string buyer,seller;

int month,date,year,productNumber;

int main(){

int choice,number;

do{

    choice=menu();

    switch(choice){

case 1:

cout<<"Enter the name: ";
    cin>>name;

    cout<<"Enter the date: ";
    cin>>date;

    cout<<"Enter month: ";
    cin>>month;

    cout<<"Enter the year: ";
    cin>>year;

    cout<<"Enter the buying price: ";
    cin>>Buyingprice;

    cout<<"Enter the selling price: ";
    cin>>Sellingprice;

    cout<<"Enter the buyer: ";
    cin>>buyer;

    cout<<"Enter the seller: ";
    cin>>seller;

    cout<<"Enter the product number: ";
    cin>>productNumber;

linkedListProduct.AddData( name, Sellingprice, Buyingprice, buyer, seller, month, date, year, productNumber);

    break;

case 2:

cout<<"Enter the ordered product: ";
cin>>number;

linkedListProduct.deleteData1(number-1);

    break;

case 3:

cout<<"--------------------------------------------"<<endl;


    linkedListProduct.seeData();


    cout<<"--------------------------------------------"<<endl;

    break;

case 4:

    stClass.print();

    break;

case 6:

    int number;

    cout<<"Enter your product number: ";
    cin>>number;

    linkedListProduct.deleteData(number);

    break;

    }

}while(choice!=7);

}
