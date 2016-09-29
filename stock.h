#ifndef stock_h
#define stock_h

#include <Arduino.h>
#include<String.h>




class Stock
{
  public:
      Stock(char* lower);
      void result(String payload);
      String Comparison(char* lower);

  private:
      char* _lower;

};

#endif


