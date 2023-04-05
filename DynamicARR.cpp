#include<stdio.h>
#include<iostream>
using namespace std;
class DynamicARR
{
private:
   int capacity;
   int lastindex;
   int *ptr;
    protected:
        void doublearry();
        void halfarray();
public:
    
    DynamicARR& operator=(DynamicARR &);
    DynamicARR();
    DynamicARR(DynamicARR &);
    void createarray(int); // For creation of Array
    void insert(int, int); // For Inserting Element
    void append(int);      // Inserting at End
    int getitem(int);      // To get an Element
    bool isempty();        // Check the Array is Empty or Not
    bool isfull();         // Check the Array is Full or Not
    void delte(int);       // Delete the Element
    void edit(int, int);   // Edit any Element
    int count();           // Count the element
    int getcapacity();     // Getting of Capacity of Array
    ~DynamicARR();
};
DynamicARR::DynamicARR()
{
    ptr=NULL;
}
int DynamicARR::getitem(int index)
{
    try{
        if(index<0 || index>lastindex)
        throw 1;
         return ptr[index];
    }
    catch(int e){
        if(e==1)
            cout<<"INVALID INDEX";
    }
    return -1;
}
 DynamicARR::~DynamicARR()
 {
    ptr=NULL;
 }
void DynamicARR::delte(int index)
{
    try{
        if(index<0||index>lastindex)
            throw 1;
        for(int i=index;i<=lastindex;i++)
            ptr[i]=ptr[i+1];
        lastindex--;
         if( capacity>1 && lastindex+1 <=capacity/2)
            halfarray();
    }
    catch(int e)
    {
        if(e==1)
            cout<<"\nInvalid Index or underflow";
    }
}
void DynamicARR::doublearry()
{
    int *temp;
    temp=new int[capacity*2];
    for(int i=0;i<=lastindex;i++)
        temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity*2;
}
void DynamicARR::edit(int index,int data)
{
    try{
            if(index<0|| index>lastindex)
                throw 1;
            ptr[index]=data;
}
catch(int e)
{
    if(e==1)
        cout<<"INVALID INDEX";
}
}
void DynamicARR::halfarray()
{
    int *temp;
    temp=new int[capacity/2];
    for(int i=0;i<=lastindex;i++)
            temp[i]=ptr[i];
    delete []ptr;
    ptr=temp;
    capacity/2;
}
void DynamicARR::createarray(int cap)
{
    capacity=cap;
    lastindex=-1;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
}
DynamicARR::DynamicARR(DynamicARR & arr)
{
     capacity=arr.capacity;
    lastindex=arr.lastindex;
    ptr=new int[capacity];
    for(int i=0;i<=lastindex;i++)
        ptr[i]=arr.ptr[i];
}
DynamicARR& DynamicARR::operator=(DynamicARR &arr)
{
    capacity=arr.capacity;
    lastindex=arr.lastindex;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[capacity];
    for(int i=0;i<=lastindex;i++)
        ptr[i]=arr.ptr[i];
    return (*this);
}
void DynamicARR::append(int data)
{
    if(isfull())
        doublearry();
    lastindex++;
    ptr[lastindex]=data;
}
void DynamicARR::insert(int data , int index)
{   try{
      if(index<0||index>lastindex+1)
        throw 1;
    if(isfull())
        doublearry();
    for(int i=lastindex;i>=index;i--)
        ptr[i+1]=ptr[i];
    ptr[index]=data;
    lastindex++;
}
catch(int e)
{
    if(e==1)
        cout<<"INVALID INDEX";
}
}
bool DynamicARR::isfull()
{
    return lastindex==capacity-1;
}
bool DynamicARR::isempty()
{
    return lastindex==-1;
}
int DynamicARR::count(){
    return lastindex+1;
}
int DynamicARR::getcapacity()
{
    return capacity;
}
int main()
{
    DynamicARR a,b;
    a.createarray(10);
    a.insert(31,3);
    b.createarray(5);
    b.append(40);
    b.getitem(3);
}
