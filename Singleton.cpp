/*
单例模式，线程不安全的单例模式
*/
#include <iostream>
using namespace std;
class Singleton
{
  private:
    static Singleton *mSingleton;
    int data;
    Singleton() { data = 42; };

  public:
    int getData() 
    {
        return data;
    }
    static Singleton *getInstance()
    {
        if (!mSingleton)
        {
            mSingleton = new Singleton();
        }
        return mSingleton;
    }

    static void Destroy()
    {
        delete mSingleton;
        mSingleton = nullptr;
    }
};

Singleton *Singleton::mSingleton = nullptr;

int main()
{
    Singleton *ptr = Singleton::getInstance();
    cout << (ptr->getData());
    Singleton::Destroy();
}