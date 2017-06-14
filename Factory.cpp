/*
工厂模式
*/
#include <memory>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
struct Product
{
    virtual void draw() = 0;
    virtual ~Product() { cout << "Base destructor\n"; }
};
struct ProductA : public Product
{
    void draw() { cout << "This is product A\n"; }
    ~ProductA() { cout << "A destructor\n"; }
};
struct ProductB : public Product
{
    void draw() { cout << "This is product B\n"; }
    ~ProductB() { cout << "B destructor\n"; }
};
struct ProductC : public Product
{
    void draw() { cout << "This is product C\n"; }
    ~ProductC() { cout << "C destructor\n"; }
};

struct Factory
{
    Product *getProduct(string s)
    {
        if (!s.compare("A"))
        {
            return new ProductA();
        }
        else if (!s.compare("B"))
        {
            return new ProductB();
        }
        else if (!s.compare("C"))
        {
            return new ProductC();
        }
        return nullptr;
    }
};

int main()
{
    //使用智能指针管理动态资源，程序结束自动释放资源
    //unique_ptr类没有拷贝构造函数，但是有移动构造函数
    Factory factory;
    vector<unique_ptr<Product>> ptrvec;
    unique_ptr<Product> proA(factory.getProduct("A"));
    unique_ptr<Product> proB(factory.getProduct("B"));

    ptrvec.push_back(move(proA));
    ptrvec.push_back(move(proB));
    ptrvec.push_back(unique_ptr<Product>(factory.getProduct("C")));

    for (auto &ptr : ptrvec)
    {
        ptr->draw();
    }
}