/*
建造者模式，强调的是对象被一步一步构建，相同的步骤产生不同的对象
而且一般不直接返回对象
*/
#include <iostream>
#include <memory>

using namespace std;

class Builder
{
  public:
    virtual ~Builder() {}
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual void BuildPartC() = 0;
    virtual void BuildPartD() = 0;
};

class BuildHouse : public Builder
{
  public:
    void BuildPartA()
    {
        cout << "build house part A\n";
    }
    void BuildPartB()
    {
        cout << "build house part B\n";
    }
    void BuildPartC()
    {
        cout << "build house part C\n";
    }
    void BuildPartD()
    {
        cout << "build house part D\n";
    }
};

class BuildBridge : public Builder
{
  public:
    void BuildPartA()
    {
        cout << "build bridge part A\n";
    }
    void BuildPartB()
    {
        cout << "build bridge part B\n";
    }
    void BuildPartC()
    {
        cout << "build bridge part C\n";
    }
    void BuildPartD()
    {
        cout << "build bridge part D\n";
    }
};

class Director
{
  private:
    Builder *m_builder;

  public:
    Director(Builder *builder)
    {
        m_builder = builder;
    }
    void Create()
    {
        m_builder->BuildPartA();
        m_builder->BuildPartB();
        m_builder->BuildPartC();
        m_builder->BuildPartD();
    }
};

int main()
{
    Builder *house = new BuildHouse();
    Builder *bridge = new BuildBridge();

    Director d1(house);
    Director d2(bridge);

    d1.Create();
    d2.Create();
    delete house;
    delete bridge;
}