
//we will create factory, which will take care of object creation.

#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
    public:
        virtual void createVehicle()=0;  //pure virtual function.

};

class Car: public Vehicle
{
    public:
        void createVehicle()
        {
            cout<<"creating car"<<endl;
        }
};

class Bike: public Vehicle
{
    public:
        void createVehicle()
        {
            cout<<"creating bike"<<endl;
        }
};

class VehicleFactory
{
    public:
        static Vehicle* getVehicle(string vehicleType);
};

Vehicle* VehicleFactory::getVehicle(string vehicleType)
{
    Vehicle *vehicle;
    if(vehicleType=="car")
    {
        vehicle=new Car();
    }
    else if (vehicleType == "bike")
    {
        vehicle=new Bike();
    }
    return vehicle;
}

//client code
int main()
{
    string vehicleType;
    cout<<"Enter vehicle type (car/bike) :";
    cin>>vehicleType;

    Vehicle *vehicle = VehicleFactory::getVehicle(vehicleType);

    vehicle->createVehicle();

    return 0;
}
