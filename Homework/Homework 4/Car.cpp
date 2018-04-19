#include "Car.h"


Car::Car(int year, string name)
{
  yearModel = year;
  make = name;
  speed = 0;
}

int Car::getYearModel()
{
  return yearModel;
}

string Car::getMake()
{
  return make;
}

int Car::getSpeed()
{
  return speed;
}

void Car::accelerate()
{
  speed += 5;
}

void Car::brake()
{
  speed -= 5;
}
