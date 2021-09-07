
#include <bits/stdc++.h>

#include <string>

using namespace std;

class StackClass{

private:

struct item{

string name,date;
double Sellingprice;
double Buyingprice;
string buyer,seller;

int productNumber;

item *previous;

}    ;

item *stackPtr;

public:

void push(string name,string date,double Sellingprice,double Buyingprice,string buyer,string seller,int productNumber);
void pop();
void readItem(item *it);
void print();

StackClass();
~StackClass();

};
