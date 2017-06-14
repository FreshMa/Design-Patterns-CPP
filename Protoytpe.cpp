/*
原型模式：用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
重要的是拷贝
ps:为什么不直接使用复制构造函数呢？因为复制构造函数不能是virtual的，这样的话
通过一个指向派生类对象的基类指针无法正确获取一个派生类对象。
*/

#include<iostream>
#include<string>
using namespace std;

class Student
{
protected:
    int id;
    string name;
public:
    Student()
    {
        cout<<"student constructor\n";
    }
    virtual ~Student()
    {
        cout<<"student destructor\n";
    }
    virtual Student *Clone() = 0;
    virtual void Show() = 0;
};

class StudentTypeA:public Student
{
public:
    StudentTypeA(const int _id,const string _name)
    {
        this->id = _id;
        this->name = _name;
        cout<<"typeA constructor\n";
    }
    StudentTypeA(const StudentTypeA& stu)
    {
        this->id = stu.id;
        this->name = stu.name;
        cout<<"typeA copy constructor\n";
    }
    virtual StudentTypeA *Clone()
    {
        return new StudentTypeA(*this);
    }
    void Show()
    {
        cout<<"id:"<<id<<"\nname:"<<name<<endl;
    }
    ~StudentTypeA()
    {
        cout<<"typeA destructor\n";
    }
};

int main()
{
    Student *stu = new StudentTypeA(1,"LiMing");
    Student *stu2 = stu->Clone();

    stu->Show();
    delete stu;
    stu2->Show();
    delete stu2;
}