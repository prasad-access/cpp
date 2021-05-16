#include <iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex mtx;
class SingleTon
{
    private : static SingleTon *instance;

              SingleTon()
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
              
    public :  

              //Optimised cod for better performance : Double check lock pattern
              static SingleTon * GetInstance()
              {
                  if(instance == NULL)
                  {
                     mtx.lock();
                     if(instance == NULL)
                     {
                       instance = new SingleTon();
                     }
                     mtx.unlock();
                     return instance;
                  }
                  else
                  {
                      return instance;
                  }
              }

              
               void display()
              {
                  std::cout<<"Hello SingleTon() : "<<" Address = "<<this<<endl;
              }
              
        
};

SingleTon * SingleTon::instance = NULL;


void  ThreadInstance()
{
    SingleTon * pObj = SingleTon::GetInstance();
    pObj ->display();
}


int main()
{
    
     SingleTon * pObj1 = SingleTon::GetInstance();
     pObj1->display();
     thread th = thread(ThreadInstance);
     SingleTon * pObj2 = SingleTon::GetInstance();
     pObj1->display();
     th.join();
     
    return 0;
}
