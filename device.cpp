#include <iostream>
#include <string> 

using namespace std;

class Magaz  //базовый абстрактный класс
{
public:
    Magaz() {} //конструктор
    string tovar;
    virtual ~Magaz() {} //деструктор
    virtual void addTovar(string tovar) = 0; //виртуальный метод
    virtual string getTovar() = 0;
};

class Sklad1 : public Magaz  //дочерний класс
{
public:
    using Magaz::Magaz; //юзать конструктор базового класса
    virtual ~Sklad1()override {}
    virtual void addTovar(string tov)override; //свой переопределяемый метод добавления товара в дочернем классе
    virtual string getTovar()override;
};

class Sklad2 : public Magaz
{
public:
    using Magaz::Magaz;
    virtual ~Sklad2()override {}
    virtual void addTovar(string tov)override;
    virtual string getTovar()override;
};


int main()
{
    Sklad1  sklad1;
    Sklad2  sklad2;

    sklad1.addTovar("elektrovenik");
    sklad1.addTovar("smart nosokovirialka");

    sklad2.addTovar("parovaia myxoboika");

    cout << sklad1.getTovar() << endl;
    cout << sklad2.getTovar() << endl;
    //каждый склад выведет перечень только своих товаров

    return 0;
}

//переопределение виртуальных методов базового класса в дочерних
//именно в такой форме, а не в теле класса, иначе будет ошибка

void Sklad2::addTovar(string tov) {
    tovar.empty() ? tovar += tov : tovar += ", " + tov;
}

string Sklad2::getTovar() {
    return tovar;
}

void Sklad1::addTovar(string tov) {
    tovar.empty() ? tovar += tov : tovar += "," + tov;
}

string Sklad1::getTovar() {
    return tovar;
}