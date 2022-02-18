# C++学习笔记
1. 类的static const成员  
- static成员的初始化必须在类外，即先定义后声明  
```
class A
{
    private:
        static const int value=10;  //也可以在类外使用const int A::value=10;
        static int svalue;
    public:
    A(){}

    int getValue()
    {
        return value;
    }

    int getSvalue()
    {
        return svalue;
    }
};


int A::svalue=20;
```    
- const修饰成员函数时：  
```
class A
{
    private:
    int a;
    public:
    int getA() const    //这里代表getA()函数不会修改A对象
    {
        return a;
    }
}
```  
```
class A
{
    const A operate*(const A& lhs, const A& rhs)
    {
        ...
    }
    //这里函数的返回值用const修饰代表该函数返回一个右值。避免出现：(a*b)=c的错误出现
}
```  
```
//两个成员函数如果是常量性不同，可以被重载
class A
{
    private:
        int value;
    public:
    A():value(0){}

    int getValue() const
    {
        std::cout<<"const"<<std::endl;
        return value;
    }

    int getValue()
    {
        std::cout<<"non const"<<std::endl;
        return value;
    }
};

int main()
{
    A a;
    a.getValue();   //输出non const
    const A b;
    b.getValue();   //输出const
    return 0;
}
//但是const对象只能调用const成员函数
```
2.析构函数可以（有时候必须）定义为虚函数，而构造函数不行。（因为构造函数要明确知道它构造的是哪个对象）  
3.虚函数，当一个类的析构函数被定义为纯虚函数时，必须为这个纯虚函数提供一个定义：
```
class A
{
    public:
    virtual ~A()=0;
};

class B:public A
{
    public:
    ~B() override {std::cout<<"~B"<<std::endl;}
};

A::~A(){}       /为纯虚函数提供定义

int main()
{
    A *a = new B;
    delete a;
    return 0;
}

```  
4.函数重载决议  
C++编译器读到一个函数调用语句时，必须从目前已看到的同名函数中选出最佳函数  
```  
void foo(int)
{
    cout<<"int"<<endl;
}

void bar()
{
    foo('a');
}

void foo(char)
{
    cout<<"char"<<endl;
}

int main()
{
    bar();//输出int
	return 0;
}  
```  
5.函数返回类型不参加重载，这里会有一个问题  
```
#file.cpp
int foo()
{
    std::cout<<"int foo"<<std::endl;

}

#main.cpp
void foo(); //注意这里，返回类型不一样

int main()
{
    foo();  //链接器捕捉不到这个错误，编译成功，输出int foo
	return 0;
}
```  
6.强弱符号的应用  
- 不允许强符号被多次定义，如果有多个强符号定义，则链接器报符号重定义  
- 如果一个符号在某个目标文件中是强符号，在其他文件中都是弱符号，那么选择强符号  
- 如果一个符号在所有目标文件中都是弱符号，那么选择其中占用空间最大的一个  
```
#file.cpp
void msg()
{
    std::cout<<"strong"<<std::endl;
}

#main.cpp
__attribute__((weak)) void msg()
{
    cout<<"weak"<<endl;
}

int main()
{
    msg();
	return 0;
}
```  
- g++ main.cpp 时运行输出weak  
- g++ main.cpp file.cpp 时输出strong  
  
7.虚函数作为接口时产生的二进制不兼容和虚函数表初探  
- file.h
```

class Father
{
    public:
        virtual void funLint(double a) = 0;//后增加
        virtual void funLint(int a) = 0;
        virtual void funLint(char a) = 0;
        virtual void funRint(double a) = 0;//后增加
        virtual void funRint(int a) = 0;
        virtual void funRint(char a) = 0;
        virtual void funAint(double a) = 0;//后增加
        virtual void funAint(int a) = 0;
        virtual void funAint(char a) = 0;
        virtual ~Father() = 0;
};

Father::~Father() { }

class Child1:public Father
{
    public:
        void funLint(double a) override;//后增加
        void funLint(int a) override;
        void funLint(char a) override;
        void funRint(double a) override;//后增加
        void funRint(int a) override;
        void funRint(char a) override;
        void funAint(double a) override;//后增加
        void funAint(int a) override;
        void funAint(char a) override;
        ~Child1() override;
};
```  
- file.cpp  
```
#include <iostream>
#include "file.h"

void Child1::funLint(double a)//后增加
{
    std::cout<<"child1 funLdouble"<<std::endl;
}

void Child1::funLint(int a)
{
    std::cout<<"child1 funLint"<<std::endl;
}

void Child1::funLint(char a)
{
    std::cout<<"child1 funLchar"<<std::endl;
}

void Child1::funRint(double a)//后增加
{
    std::cout<<"child1 funRdouble"<<std::endl;
}

void Child1::funRint(int a)
{
    std::cout<<"child1 funRint"<<std::endl;
}

void Child1::funRint(char a)
{
    std::cout<<"child1 funRchar"<<std::endl;
}

void Child1::funAint(double a)//后增加
{
    std::cout<<"child1 funAdouble"<<std::endl;
}

void Child1::funAint(int a)
{
    std::cout<<"child1 funAint"<<std::endl;
}

void Child1::funAint(char a)
{
    std::cout<<"child1 funAchar"<<std::endl;
}

Child1::~Child1()
{
    std::cout<<"~child1"<<std::endl;
}
```  
- main.cpp
```
#include "file.h"
#include <iostream>

int main()
{
    std::cout<<sizeof(Father)<<std::endl;// pvptr大小：8

    typedef void(*func)(void);
    Father* f = new Child1;
    f->funAint(1);  //测试二进制兼容
    //以下测试虚函数表
    long* pvptr = (long*)f;
    long* vptr = (long*)*pvptr;
    func func1 = (func)vptr[0];
    func func2 = (func)vptr[8];
    func1();
    func2();
    delete f;
	return 0;
}
```
在以上代码中，先把后增加之前的file.cpp编译成动态链接库
```
g++ -fPIC -shared file.cpp -o libfile.so -std=c++11
```
而后编译main.cpp使用该库
```
g++ -o test main.cpp -l file -L . -std=c++11
```
在修改file.*之前运行正常，输出：
```
$ ./test                                             
child1 funAint
~child1
```
然而在修改了file.*之后，输出错误
```
$ ./test
child1 funRint
child1 funAint
```
其本质原因就是c++以vtable[offset]的方式实现虚函数调用，而offset又是根据虚函数声明的位置隐式确定的，增加几行代码之后造成offset的排列发生了变化，现有的二进制文件无法再用旧的offset调用到正确的函数[^1]  

[^1]: Linux多线程服务端编程，p440

