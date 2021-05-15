/******************************************************************************
/* Simple SingleTon Class 

*******************************************************************************/
#include <iostream>
using namespace std;

class SingleTon
{
    private : static SingleTon *instance;
              int count;
              SingleTon():count(1)
              {
              }
              
              ~SingleTon()
              {
              }
              
              SingleTon(const SingleTon &src)
              {
              }
              
             SingleTon& operator =(const SingleTon &src)
              {
              }
              
      
              
    public :  static SingleTon * GetInstance()
              {
                  if(instance == NULL)
                     instance = new SingleTon();
                  
                  return instance;                  
              }
              
              
              void process()
              {
                 count++;
              }
              
               void display()
              {
                  cout<<"Hello SingleTon() : "<<count<<" Address = "<<this<<endl;
              }
              
        
};

SingleTon * SingleTon::instance = NULL;

int main()
{
     SingleTon * pObj1 = SingleTon::GetInstance();
     pObj1->display();
     pObj1->process();
     SingleTon * pObj2 = SingleTon::GetInstance();
     pObj1->display();
     
    return 0;
}
