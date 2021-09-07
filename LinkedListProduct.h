#include <bits/stdc++.h>

using namespace std;

class LinkedListProduct{

private:

struct Node{

string name;
double Sellingprice;
double Buyingprice;
string buyer,seller;

int month,date,year,productNumber;

Node *next;

}    ;

    typedef struct Node *node;

    node head;
    node current;
    node temp;

public:

LinkedListProduct();

void AddData(string name,double Sellingprice,double Buyingprice,string buyer,string seller,int month,int date,int year,int productNumber);

void seeData();

void deleteData(int productNumber);
void deleteData1(int productNumber);

};

