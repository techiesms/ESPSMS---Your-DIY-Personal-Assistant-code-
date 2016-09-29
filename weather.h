#ifndef weather_h
#define weather_h

#include <Arduino.h>
#include<String.h>

class Weather
{
  public:
      Weather(char* response);
      float temp_c();
      float temp_f();
      float temp_k(char* response);
      String city_name(char* response);
      String country_name(char* response);
      String city_cond(char* response);
      String city_desc(char* response);
      String atm_pressure(char* response);
      String humidity(char* response);
      String clouds(char* response);
      

  private:
      char* _response;

};

#endif
