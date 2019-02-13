#include <stdio.h>
#include <stdio.h>

void func()
{
    printf("func\n");
}

void test01()
{
    printf("函数入口地址：%p\n",func);
    void(*p)()=func;//函数指针
    p();
}

//定义函数指针
int myfunc(int a,char b)
{
    printf("myfunc(%d,%c)\n",a,b);
}
void test02()
{
    //定义函数类型，通过类型来定义函数指针
    typedef int(FUN_TYPE)(int,char);
    FUN_TYPE *p=myfunc;
    //调用函数指针的两种方式
    p(1,'a');
    (*p)(1,'b');

    //2.直接定义函数指针类型
    typedef  int(*FUN_P)(int,char);
    FUN_P fp=myfunc;
    fp(30,'c');
    //fp=func;

    //3.
    int (*pFunc3)(int ,char)=myfunc;
    pFunc3(40,'d');

}


int con1(int a,int b)
{
    printf("a+b\n");
    return a+b;
}

int con2(int a,int b)
{
    printf("a-b\n");
    return a-b;
}

void test03()
{
    int(*pFunc)(int ,int )=con1;
    pFunc(1,2);
}

void doLogic(int a,int b,int(*p)(int,int))
{
    printf("---------------doLogic-----------------\n");
    int res=p(a,b);
}

void test04()
{
    doLogic(1,2,con2);
}


//函数指针组
void fun1()
{
    printf("fun1\n");
}

void fun2()
{
    printf("fun2\n");
}

void fun3()
{
    printf("fun3\n");
}

void test05()
{
    printf("-------------------test05---------------------------\n");
    void (*pFun[3])();
    pFun[0]=fun1;
    pFun[1]=fun2;
    pFun[2]=fun3;
    pFun[0]();
    pFun[1]();
    pFun[2]();
    for(int i=0;i<3;++i)
    {
        pFun[i]();
    }
}

//函数指针做函数参数（回调函数）
void printAllArray(void *arr, int elementSize,int len,void(*print)(void *))
{
    char *start=(char*)arr;
    for(int i=0;i<len;++i)
    {
        char *current=start+i*elementSize;
        print(current);
    }
}

void printInt(void *data)
{
    int *a=(int *)data;
    printf("printInt:%d\n",*a);
}

struct Person
{
    char name[64];
    int age;
};

void printPerson(void *data)
{
    struct Person*p=(struct Person*)data;
    printf("name:%s    age:%d\n",p->name,p->age);
}

void test06()
{
    int arrInt[]={1,2,3,4};
    printAllArray(arrInt, sizeof(arrInt[0]),4,printInt);
    struct Person arrPersons[]={
            {"name1",10},
            {"name2",12},
            {"name3",13}
    };
    printAllArray(arrPersons, sizeof(arrPersons[0]),3,printPerson);
}

int main()
{
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    printf("Hello, World!\n");
    return 0;
}