#include <iostream>

using namespace std;


class Animal
{
protected:
    string food;
    string location;
    string color;
public:
     virtual void eat() = 0;
     virtual void makeNoise() = 0;
     virtual void sleep() = 0;

};

class Mammal: public virtual Animal
{
public:
    void doSomethingTypicalForMammal()
    {
        cout<<"doing something typical for mammal"<<endl;
    }
};

class Canine : public virtual Animal
{
public:
    void roam()
    {
        cout<<"roam like canine"<<endl;
    }
};

class Feline : public virtual Animal
{
public:
    void roam()
    {
        cout<<"roam like feline"<<endl;
    }
};

class RoboPet : protected Animal
{
public:
    void play()
    {
        cout<<"playing..."<<endl;
    }
};


class WingedAnimal: public virtual Animal
{
public:
    void flapping(){cout<<"flap flap"<<endl;}
};

class Bat : public Mammal, public WingedAnimal
{
public:
    void makeNoise(){cout<<"bat making noise..."<<endl;}
    void eat(){cout<<"bat eating..."<<endl;}
    void sleep(){cout<<"bat sleeping zzzz..."<<endl;}
};

class Wolf : public Mammal, public Canine
{
public:
    void makeNoise(){cout<<"Wolf making noise..."<<endl;};
    void eat(){cout<<"Wolf eating..."<<endl;}
    void sleep(){cout<<"Wolf sleeping zzzz..."<<endl;}
};

class Dog : public Mammal, public Canine
{
public:
    void makeNoise(){cout<<"Dog making noise..."<<endl;};
    void eat(){cout<<"Dog eating..."<<endl;}
    void sleep(){cout<<"Dog sleeping zzzz..."<<endl;}
};

class Cat : public Mammal, public Feline
{
public:
    void makeNoise(){cout<<"Cat making noise..."<<endl;};
    void eat(){cout<<"Cat eating..."<<endl;}
    void sleep(){cout<<"Cat sleeping zzzz..."<<endl;}
};

class Lion : public Mammal, public Feline
{
public:
    void makeNoise(){cout<<"Lion making noise..."<<endl;};
    void eat(){cout<<"Lion eating..."<<endl;}
    void sleep(){cout<<"Lion sleeping zzzz..."<<endl;}
};

class RoboDog : public RoboPet
{
public:
    void makeNoise(){cout<<"RoboDog making noise..."<<endl;};
    void eat(){cout<<"RoboDog eating..."<<endl;}
    void sleep(){cout<<"RoboDog sleeping zzzz..."<<endl;}
};




int main()
{
    Bat *bat = new Bat();
    bat->eat();
    bat->makeNoise();
    bat->flapping();
    bat->sleep();
    Dog *dog = new Dog();
    dog->eat();
    dog->makeNoise();
    dog->roam();
    Cat *cat = new Cat();
    cat->eat();
    cat->makeNoise();
    cat->roam();
    RoboDog *rdog = new RoboDog();
    rdog->eat();
    rdog->makeNoise();
    rdog->play();
    rdog->sleep();
    return 0;
}
