#include <Arduino.h>
#include<String.h>
#include "weather.h"

String s_response;
float temperature_kelvin;
float temperature_celcius;
float temperature_far;

Weather::Weather(char* response)
{
 _response = response;
  s_response = (String)response;
  Serial.println("weather.h");

}


String Weather::city_name(char* _response)
{
          int i = 0;
          while (_response[i] != 'n' || _response[i + 1] != 'a' || _response[i + 2] != 'm' || _response[i + 3] != 'e' )
            i++;
          String s_response = (String)_response;
          String city_name = s_response.substring(i + 7);
          int j = 0;
          // Serial.println(city_name);
          while (city_name.charAt(j) != '"')
            j++;
          city_name = city_name.substring(0, j);
          return(city_name);
}
String Weather::country_name(char* _response)
{
          int i = 0;
          while (_response[i] != 'c' || _response[i + 1] != 'o' || _response[i + 2] != 'u' || _response[i + 3] != 'n' || _response[i + 4] != 't' || _response[i + 5] != 'r' || _response[i + 6] != 'y')
            i++;
          String country = s_response.substring(i + 10);
          int j = 0;
          //Serial.println(country);
          while (country.charAt(j) != '"')
            j++;
          country = country.substring(0, j);
          return(country);
}
float Weather::temp_k(char* _response)
{
          int i = 0;
          while (_response[i] != 't' || _response[i + 1] != 'e' || _response[i + 2] != 'm' || _response[i + 3] != 'p' )
            i++;
          String city_temp = s_response.substring(i + 6);
          int j = 0;
          //Serial.println(city_temp);
          while (city_temp.charAt(j) != ',')
            j++;
          city_temp = city_temp.substring(0, j);
          temperature_kelvin = (city_temp.toFloat());
          return(temperature_kelvin);
}
float Weather::temp_c()
{
   temperature_celcius = temperature_kelvin - 273.15;
   return(temperature_celcius);
}
float Weather::temp_f()
{
  temperature_far = (temperature_celcius * 9 / 5) + 32;
  return(temperature_far);
}
String Weather::city_cond(char* reaponse)
{
          int i = 0;
          while (_response[i] != 'm' || _response[i + 1] != 'a' || _response[i + 2] != 'i' || _response[i + 3] != 'n' )
            i++;
          String city_cond = s_response.substring(i + 7);
          int j = 0;
          //Serial.println(city_cond);
          while (city_cond.charAt(j) != '"')
            j++;
          city_cond = city_cond.substring(0, j);
          return(city_cond);
}
String Weather::city_desc(char* reaponse)
{
          int i = 0;
          
          while (_response[i] != 'd' || _response[i + 1] != 'e' || _response[i + 2] != 's' || _response[i + 3] != 'c' || _response[i + 4] != 'r' || _response[i + 5] != 'i' || _response[i + 6] != 'p' || _response[i + 7] != 't' )
            i++;
          String city_desc = s_response.substring(i + 14);
          int j = 0;
          //Serial.println(city_desc);
          while (city_desc.charAt(j) != '"')
            j++;
          city_desc = city_desc.substring(0, j);
          return(city_desc);
}
String Weather::atm_pressure(char* _response)
{
          int i = 0;
          while (_response[i] != 'p' || _response[i + 1] != 'r' || _response[i + 2] != 'e' || _response[i + 3] != 's' || _response[i + 4] != 's' || _response[i + 5] != 'u' || _response[i + 6] != 'r' || _response[i + 7] != 'e' )
            i++;
          String atm_pressure = s_response.substring(i + 10);
          int j = 0;
          // Serial.println(atm_pressure);
          while (atm_pressure.charAt(j) != ',')
            j++;
          atm_pressure = atm_pressure.substring(0, j);
          return(atm_pressure);
}
String Weather::humidity(char* _response)
{
          int i = 0;
          while (_response[i] != 'h' || _response[i + 1] != 'u' || _response[i + 2] != 'm' || _response[i + 3] != 'i' || _response[i + 4] != 'd' || _response[i + 5] != 'i' || _response[i + 6] != 't' || _response[i + 7] != 'y')
            i++;
          String humidity = s_response.substring(i + 10);
          int j = 0;
          //Serial.println(humidity);
          while (humidity.charAt(j) != ',')
            j++;
          humidity = humidity.substring(0, j);
          return(humidity);
}
String Weather::clouds(char* _response)
{
          int i = 0;
          while (_response[i] != 'c' || _response[i + 1] != 'l' || _response[i + 2] != 'o' || _response[i + 3] != 'u' || _response[i + 4] != 'd' || _response[i + 5] != 's' || _response[i + 6] != '"' || _response[i + 7] != ':' || _response[i + 8] != '{' || _response[i + 9] != '"')
            i++;
          String clouds = s_response.substring(i + 14);
          int j = 0;
          //Serial.println(clouds);
          while (clouds.charAt(j) != '}')
            j++;
          clouds = clouds.substring(0, j);
          return(clouds);
          
}

