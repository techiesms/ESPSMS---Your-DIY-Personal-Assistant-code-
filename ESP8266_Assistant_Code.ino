/*
 * This is the code of Making your own personal assistant for ESP8266 12e board.
 *
 * This code is written and tested by Sachin Soni. This code is open for all so anyone can use it.
 *
 *  Visit my website,
 *  www.techiesms.com
 *  to know more about this and other electronic projects tutorials.
 *
 *
 *        techiesms
 *  explore | learn | share
 *
*/


//------------------------------------------------- necesarry libraries
#include<String.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include "constants.h"

//------------------------------------------------- Optional libraries(include according to requirement of your project)

#include "stock.h"
#include "calculator.h"
#include "Quote.h"
#include "weather.h"



char* response = " ";
String res = "";
String RAILWAY_API_KEY = "YOUR_RAILWAY_API_KEY";//---------- API key for www.railwayapi.com
String WEATHER_API_KEY = "YOUR_WEATHER_API_KEY";//---------- API key for api.openweathermap.org



ESP8266WiFiMulti WiFiMulti;

void setup() {

  Serial.begin(115200);

  pinMode(lightt, OUTPUT);//---------- Appilance1 to be controlled
  pinMode(fann, OUTPUT); //----------- Appilance2 to be controlled

  WiFiMulti.addAP("SSID NAME", "Password"); //---------- Write you SSID and Password of yout router
}

void loop() {

  if ((WiFiMulti.run() == WL_CONNECTED)) //---------- If connected to the router than go inside
  {

    Serial.println("Ask your question:");
    Serial.println("\n");

    //------------------------------------------------- Reading the String from the Serial, word by word.
    while (!Serial.available());
    while (Serial.available())
    {
      char add = Serial.read();
      res = res + add;
      delay(1);
    }
    response = &res[0];


    //------------------------------------------------- Converting every character of the String in lower form
    const int length = strlen( response ); // get the length of the text
    char* lower = ( char* )malloc( length + 1 ); // allocate 'length' bytes + 1 (for null terminator) and cast to char*
    lower[ length ] = 0; // set the last byte to a null terminator
    //------------------------------------------------- copy all character bytes to the new buffer using tolower
    for ( int i = 0; i < length; i++ )
    {
      lower[ i ] = tolower( response[ i ] );
    }

    Serial.println(lower);// printin the String in lower character form
    Serial.println("\n");



    //***************************** From here, different cases will start for different purposes *****************************//





    if (strstr(lower, que1) || strstr(lower, que2) || strstr(lower, que3) ||
        strstr(lower, que4) || strstr(lower, que5) || strstr(lower, que6) || strstr(lower, que7) ||
        strstr(lower, que8) || strstr(lower, que9))
    {
      if ((WiFiMulti.run() == WL_CONNECTED)) {
        Serial.println("Processing....");

        HTTPClient http; //stringOne.startsahdith("HTTP/1.1")

        http.begin("api.thingspeak.com", 80, "/apps/thinghttp/send_request?api_key=39D61DPXIY3K4DQL"); //HTTP
        int httpCode = http.GET();

        // httpCode will be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled


          // file found at server
          if (httpCode == HTTP_CODE_OK) {
            String payload = http.getString();
            Serial.println("\n");
            Serial.println(payload);
            Serial.println("\n");
          }
        } else {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
        response = "";
        res = "";
      }
    }




    else if ( strstr(lower, que10) || strstr(lower, que11) || strstr(lower, que12) || strstr(lower, que13))
    {
      if ((WiFiMulti.run() == WL_CONNECTED)) {
        Serial.println("Processing....");

        HTTPClient http; //stringOne.startsahdith("HTTP/1.1")

        http.begin("api.thingspeak.com", 80, "/apps/thinghttp/send_request?api_key=366ZP8SF6ZS3UMZL"); //HTTP
        int httpCode = http.GET();

        // httpCode will be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled


          // file found at server
          if (httpCode == HTTP_CODE_OK) {
            String payload = http.getString();
            Serial.println("\n");
            Serial.println(payload);
          }

        } else {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
        response = "";
        res = "";
      }
    }


    else if (strstr(lower, que14) || strstr(lower, que15) || strstr(lower, que16))
    {
      if ((WiFiMulti.run() == WL_CONNECTED)) {
        Serial.println("Processing....");

        HTTPClient http; //stringOne.startsahdith("HTTP/1.1")

        http.begin("api.thingspeak.com", 80, "/apps/thinghttp/send_request?api_key=PKHTTDCEHB7PR1IB"); //HTTP
        int httpCode = http.GET();

        // httpCode will be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled


          // file found at server
          if (httpCode == HTTP_CODE_OK) {
            String payload = http.getString();
            Serial.println("\n");
            Serial.println(payload);
            Serial.println("\n");
          }
        } else {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
        response = "";
        res = "";
      }
    }

    else if (strstr(lower, Name1) || strstr(lower, Name2) || strstr(lower, Name3) ||
             strstr(lower, Name4) || strstr(lower, Name5) || strstr(lower, Name6) || strstr(lower, Name7))
    {
      if ((WiFiMulti.run() == WL_CONNECTED)) {
        Serial.println("Processing....");

        HTTPClient http; //stringOne.startsahdith("HTTP/1.1")

        http.begin("api.thingspeak.com", 80, "/apps/thinghttp/send_request?api_key=AKEWCGNBEYXH8FJ3"); //HTTP
        int httpCode = http.GET();

        // httpCode will be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled


          // file found at server
          if (httpCode == HTTP_CODE_OK) {
            String payload = http.getString();
            Serial.println("\n");
            Serial.println(payload);
            Serial.println("\n");
          }
        } else {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
        response = "";
        res = "";
      }
    }

    else if (strstr(lower, aim1) || strstr(lower, aim2) || strstr(lower, aim3) || strstr(lower, aim4))
    {
      if ((WiFiMulti.run() == WL_CONNECTED)) {
        Serial.println("Processing....");

        HTTPClient http; //stringOne.startsahdith("HTTP/1.1")

        http.begin("api.thingspeak.com", 80, "/apps/thinghttp/send_request?api_key=W2NKTO59K941TF8H"); //HTTP
        int httpCode = http.GET();

        // httpCode will be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled


          // file found at server
          if (httpCode == HTTP_CODE_OK) {
            String payload = http.getString();
            Serial.println("\n");
            Serial.println(payload);
            Serial.println("\n");
          }
        } else {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
        response = "";
        res = "";
      }
    }

    else if (strstr(lower, que17) || strstr(lower, que18))
    {
      if ((WiFiMulti.run() == WL_CONNECTED)) {
        Serial.println("Processing....");

        HTTPClient http; //stringOne.startsahdith("HTTP/1.1")

        http.begin("api.thingspeak.com", 80, "/apps/thinghttp/send_request?api_key=KMZUYWUTTW59ZJ2M"); //HTTP
        int httpCode = http.GET();

        // httpCode will be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled


          // file found at server
          if (httpCode == HTTP_CODE_OK) {
            String payload = http.getString();
            Serial.println("\n");
            Serial.println(payload);
            Serial.println("\n");
          }
        } else {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
        response = "";
        res = "";
      }
    }

    else if (strstr(lower, cal))
    {
      calculate calci(lower);
      float answer = calci.calculator(lower);
      Serial.println("\n");
      Serial.println(answer);
      Serial.println("\n");
      response = "";
      res = "";
    }






    else if (strstr(lower, weather))
    {
      int i = 0;
      while (lower[i] != 'o' || lower[i + 1] != 'f')
        i++;

      String result = (String)lower;
      result = result.substring(i + 3);
      result = result.substring(0, result.length() - 2);

      if ((WiFiMulti.run() == WL_CONNECTED)) {
        Serial.println("Processing....");

        HTTPClient http; //stringOne.startsahdith("HTTP/1.1")

        http.begin("http://api.openweathermap.org/data/2.5/weather?q=" + result + "&APPID=" + WEATHER_API_KEY); //HTTP
        int httpCode = http.GET();

        // httpCode ahd ill be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled


          // file found at server
          if (httpCode == HTTP_CODE_OK) {
            String payload = http.getString();
            char* response = &payload[0];
            Weather weather(response);
            float temp_k = weather.temp_k(response);
            float temp_c = weather.temp_c();
            float temp_f = weather.temp_f();
            String city_name = weather.city_name(response);
            String country_name = weather.country_name(response);
            String city_desc = weather.city_desc(response);
            String city_cond = weather.city_cond(response);
            String humidity = weather.humidity(response);
            String clouds = weather.clouds(response);
            String atm_pressure = weather.atm_pressure(response);

            Serial.println("\n");
            Serial.print("City: "); Serial.println(city_name);
            Serial.print("Country: "); Serial.println(country_name);
            Serial.println("Temperature");
            Serial.print("     "); Serial.print(temp_k, 3); Serial.println(" kelvin");
            Serial.print("     "); Serial.print(temp_c, 3); Serial.println(" deg. celcius");
            Serial.print("     "); Serial.print(temp_f, 3); Serial.println(" deg. fahrenheit");
            Serial.print("Weather Status: "); Serial.println(city_cond);
            Serial.print("Weather Description: "); Serial.println(city_desc);
            Serial.print("Atmospheric Presure: "); Serial.println(atm_pressure + " hPa");
            Serial.print("Humidity: "); Serial.println(humidity + " %rH");
            Serial.print("Clouds: "); Serial.println(clouds + "%");
            Serial.println("\n");
          }
        } else {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
        response = "";
        res = "";
      }
    }

    else if (strstr(lower, temp))
    {

      int i = 0;
      while (lower[i] != 'o' || lower[i + 1] != 'f')
        i++;
      // Serial.println(i);
      String result = (String)lower;
      result = result.substring(i + 3);
      result = result.substring(0, result.length() - 2);

      if ((WiFiMulti.run() == WL_CONNECTED)) {
        Serial.println("Processing....");

        HTTPClient http; //stringOne.startsahdith("HTTP/1.1")
        http.begin("http://api.openweathermap.org/data/2.5/weather?q=" + result + "&APPID=" + WEATHER_API_KEY); //HTTP
        int httpCode = http.GET();

        // httpCode ahd ill be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled


          // file found at server
          if (httpCode == HTTP_CODE_OK) {
            String payload = http.getString();
            char* response = &payload[0];

            Weather weather(response);
            String city_name = weather.city_name(response);
            String country = weather.country_name(response);
            float temp_k = weather.temp_k(response);
            float temp_c = weather.temp_c();
            float temp_f = weather.temp_f();



            Serial.println("\n");
            Serial.print("City: "); Serial.println(city_name);
            Serial.print("Country: "); Serial.println(country);
            Serial.println("Temperature");
            Serial.print("     "); Serial.print(temp_k, 3); Serial.println(" kelvin");
            Serial.print("     "); Serial.print(temp_c, 3); Serial.println(" deg. celcius");
            Serial.print("     "); Serial.print(temp_f, 3); Serial.println(" deg. fahrenheit");
            Serial.println("\n");
          }
        } else {
          Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
        response = "";
        res = "";
      }

    }

    else if (strstr(lower, mean))
    {
      Serial.println("Sorry!!!!!, you don't have data regarding this");
      Serial.println("Wait for the upcoming series on Making your own Smart Assiatant using ESP8266");
      Serial.println("Or you haven't downloaded the latest code, check out my github, Github/techiesms");
      Serial.println(); res = "";  response = "";
    }



    else if (strstr(lower, quo) || strstr(lower, quot))
    {
      Serial.println("Sorry!!!!!, you don't have data regarding this");
      Serial.println("Wait for the upcoming series on Making your own Smart Assiatant using ESP8266");
      Serial.println("Or you haven't downloaded the latest code, check out my github, Github/techiesms");
      Serial.println(); res = "";  response = "";
    }
    else if (strstr(lower, stock))
    {
      Stock stock(lower);
    String resu = stock.Comparison(lower);


    if ((WiFiMulti.run() == WL_CONNECTED)) {
      Serial.println("Processing....");

      HTTPClient http;

      http.begin("http://www.google.com/finance/info?q=NSE:" + resu + ""); //HTTP
      int httpCode = http.GET();

      // httpCode ahd ill be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled


        // file found at server
        if (httpCode == HTTP_CODE_OK) {
          String payload = http.getString();
          stock.result(payload);

        }
      }
      else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }
      http.end();
      response = "";
      res = "";
    }

    }
    else if (strstr(lower, train1))
    {
      Serial.println("Sorry!!!!!, you don't have data regarding this");
      Serial.println("Wait for the upcoming series on Making your own Smart Assiatant using ESP8266");
      Serial.println("Or you haven't downloaded the latest code, check out my github, Github/techiesms");
      Serial.println(); res = "";  response = "";

    }

    else if (strstr(lower, train2))
    {
      Serial.println("Sorry!!!!!, you don't have data regarding this");
      Serial.println("Wait for the upcoming series on Making your own Smart Assiatant using ESP8266");
      Serial.println("Or you haven't downloaded the latest code, check out my github, Github/techiesms");
      Serial.println(); res = "";  response = "";

    }

    else if (strstr(lower, train3))
    {
      Serial.println("Wait for the upcoming series on Making your own Smart Assiatant using ESP8266");
      Serial.println("Or you haven't downloaded the latest code, check out my github, Github/techiesms");
      Serial.println(); res = "";  response = "";
    }

    else if (strstr(lower, train4))
    { Serial.println("Wait for the upcoming series on Making your own Smart Assiatant using ESP8266");
      Serial.println("Or you haven't downloaded the latest code, check out my github, Github/techiesms");
      Serial.println(); res = "";  response = "";
    }


    else if (strstr(lower, train5))
    {
      Serial.println("Sorry!!!!!, you don't have data regarding this");
      Serial.println("Wait for the upcoming series on Making your own Smart Assiatant using ESP8266");
      Serial.println("Or you haven't downloaded the latest code, check out my github, Github/techiesms");
      Serial.println(); res = "";  response = "";

    }

    else if (strstr(lower, help))
    {
      Serial.println(" ");
      Serial.println("Want to ask basic questions regarding me, my inventor, manufacturer, origin etc you can ask");
      Serial.println("eg.");
      Serial.println("         i) who are you?");
      Serial.println("         ii) who is you inventor?");
      Serial.println("         iii) where are you from?");
      Serial.println("         iv) who is techiesms?");
      Serial.println("         v) who is your teacher?");
      Serial.println("         vi) what is your aim?"); Serial.println("\n");
      Serial.println("Want to know the weather information of your city, just type - weather information of CITY_NAME");
      Serial.println("eg. weather information Ahmedabad"); Serial.println("\n");
      Serial.println("Want to know the temperature of your city, just type - temperature of CITY_NAME");
      Serial.println("eg. temperature of Surat"); Serial.println("\n");
      Serial.println("Want to know a quote to get motivated, type - tell me a quote or sayings of great personality");
      Serial.println("eg. tell me a quote"); Serial.println("\n");
      Serial.println("Want to know meaning or synonym of a particular word, type - meaning of WORD");
      Serial.println("eg. meaning of Beguile"); Serial.println("\n");
      Serial.println("Want to know stock price of the share you have, type - stock price of SHARE_NAME(Right now strictly for shares under NSE broker)");
      Serial.println("eg. stock price of MRF"); Serial.println("\n");
      Serial.println("Want to know the route of any train, type - route of train TRAIN_NUMBER(Right now strictly for Indian Railways)");
      Serial.println("eg. route of train 12433"); Serial.println("\n");
      Serial.println("Want to know the live status of any train, type - status of  TRAIN_NUMBER(Right now strictly for Indian Railways)");
      Serial.println("eg. status of 12433"); Serial.println("\n");
      Serial.println("Want to know your PNR status, type - check my pnr PNR_NUMBER(Right now strictly for Indian Railways)");
      Serial.println("eg. check my pnr XXXXXXXXXX"); Serial.println("\n");
      Serial.println("Want to know the train between two station, type - train between SOURCE_STATION_CODE to DESTINATION_STATION_CODE(Right now strictly for Indian Railways)");
      Serial.println("eg. train between adi to lko"); Serial.println("\n");
      Serial.println("Want to know the station code, type - code of station STATION_NAME(Right now strictly for Indian Railways)");
      Serial.println("eg. code of station Ahmedabad"); Serial.println("\n");
      Serial.println("Want to do basic calculations, type - calculate number1 SIGN number2");
      Serial.println("eg. i) calculate 54 / 23");
      Serial.println("    ii) calculate 33 into 8");
      Serial.println("    iii) calculate 45589 + 12332"); Serial.println("\n");
      Serial.println("Want to control your appliances, type - esp listen turn ON/OFF the LIGHT/FAN");
      Serial.println("eg. i) esp listen turn on the light");
      Serial.println("    ii) esp listen turn off the fan"); Serial.println("\n");


      response = "";
      res = "";
    }
    else
    {
      Serial.println(" ");
      Serial.println("I didn't understand what you just typed.");
      Serial.println("I'm not able to answer in following situations");
      Serial.println("         >spelling of the statement is incorrect. Solution:- Please recheck the spelling and type again");
      Serial.println("         >improper format of the statement. Solution:- To know the format of every trick, type \"help format\"");
      Serial.println("         >don't know the answer of the question you asked. Solution:- mail the statement you typed at espsms@techiesms.com so that I can answer this question next time by learning it.");
      Serial.println("");
      response = "";
      res = "";
    }
  }
}


