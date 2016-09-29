#include <Arduino.h>
#include<String.h>
#include "quote.h"
  
  
  char* ch1 = "&#8217;";
  char* ch2 = "&#8221;";
  char* ch3 = "&#8220;";

Quote::Quote(String payload)
{
  String _payload = payload;
}
String Quote::saying_response(String payload)
{


          
          payload.replace(ch1, "'");
          payload.replace("\u2019", "'");
          payload.replace(ch2, "\"");
          payload.replace(ch3, "\"");
          int i = 0;
          while (payload.charAt(i) != '>')
            i++;
          i++;
          payload = payload.substring(i);
          i = 0;
          while (payload.charAt(i) != '<')
            i++;

          String Quote = payload.substring(0, i);
          return(Quote);
          




          // Serial.println(payload);
}

String Quote::author_response(String payload)
{
 
          payload.replace(ch1, "'");
          payload.replace("\u2019", "'");
          payload.replace(ch2, "\"");
          payload.replace(ch3, "\"");
          // String first = payload.substring(0,i);
          //  Serial.println(first);
          // USE_SERIAL.println(payload);
          for (int j = 0 ; j < 5; j++)
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
          String Author = payload.substring(0, i); 
          return(Author);
}

