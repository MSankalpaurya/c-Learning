#include <iostream>

using namespace std;

class Engine

{

private:
    string type;

public:
    Engine(string t)

    {

        type = t;

        cout << "Engine parameter Constructor" << endl;
    }

    Engine(const Engine &e)

    {

        this->type = e.type;

        cout << "Engine copy Constructor" << endl;
    }

    Engine()

    {

        cout << "Engine Constructor" << endl;
    }

    ~Engine()

    {

        cout << "Engine Destructor" << endl;
    }
};

class Car

{

private:
    Engine engine;

public:
    void setEngine(Engine e)

    {

        engine = e;
    }

    Car()

    {

        cout << "Car Constructor" << endl;
    }

    ~Car()

    {

        cout << "Car Destructor" << endl;
    }
};

class Ford : public Car

{

private:
    string name;

public:
    void setName(string n)

    {

        name = n;
    }

    Ford()

    {

        cout << "Ford Constructor" << endl;
    }

    ~Ford()

    {

        cout << "Ford Destructor" << endl;
    }
};

int main()
{

    Ford fordCar; //1

    Engine engine("V8"); //para

    fordCar.setName("Ford V8"); 

    fordCar.setEngine(engine); //copy

    return 0;
}