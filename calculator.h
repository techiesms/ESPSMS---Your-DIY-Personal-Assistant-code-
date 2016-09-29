#ifndef calculator_h
#define calculator_h

#include <Arduino.h>
#include<String.h>




class calculate
{
  public:
      calculate(char* lower);
      float calculator(char* lower);
  private:
      char* _lower;

};

#endif

