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
g++ main.cpp 时运行输出weak  
g++ main.cpp file.cpp 时输出strong