#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
using namespace std;

class Car
{
	int yearModel;
	string make;
	int speed;
public:
	Car(int year, string name);
  int getYearModel();
  string getMake();
  int getSpeed();
  void accelerate();
  void brake();
};

#endif