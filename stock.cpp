

#include <Arduino.h>
#include<String.h>
#include "Stock.h"

Stock::Stock(char* lower)
{
  _lower = lower;

}

String Stock::Comparison(char* _lower)
{
  
    int i = 0;
    while(_lower[i] != 'o' || _lower[i + 1] != 'f')
     i++;
    String result = (String)_lower;
    result = result.substring(i + 3);
    return(result);
    
}
void Stock::result(String payload)
{
  for (int j = 0 ; j < 7; j++)
          {
            int i = 0;
            while (payload.charAt(i) != '"')
            {
              i++;

            }
            i++;
            payload = payload.substring(i);
          }
          int i = 0;
          while (payload.charAt(i) != '"')
            i++;
          String Stock_Name = payload.substring(0, i);
          Serial.print("Stock Name: "); Serial.println(Stock_Name);

          for (int j = 0 ; j < 4; j++)
          {
            int i = 0;
            while (payload.charAt(i) != '"')
            {
              i++;

            }
            i++;
            payload = payload.substring(i);
          }
          i = 0;
          while (payload.charAt(i) != '"')
            i++;
          String Broker_Name = payload.substring(0, i);
          Serial.print("Broker: "); Serial.println(Broker_Name);

          for (int j = 0 ; j < 4; j++)
          {
            int i = 0;
            while (payload.charAt(i) != '"')
            {
              i++;

            }
            i++;
            payload = payload.substring(i);
          }
          i = 0;
          while (payload.charAt(i) != '"')
            i++;
          String Stock_Price = payload.substring(0, i);
          Serial.print("Stock Price: "); Serial.println(Stock_Price);  
      }


          




