#include <Arduino.h>
#include "calculator.h"
#include<String.h>

float result;

//-------------------------------------- constants
char* plus1 = "+";
char* plus2 = "plus";
char* minus1 = "-";
char* minus2 = "minus";
char* mul1 = "*";
char* mul2 = "multiply";
char* mul3 = "multiplied";
char* mul4 = "into";
char* div1 = "/";
char* div2 = "divided";
char* div3 = "divide";
char* div4 = "by";


calculate::calculate(char* lower)
{
  _lower = lower;
}

float calculate::calculator(char* _lower)
{
  
 
  String response = (String)_lower;

  String filtered = response.substring(10); //---------- filtering upto "calculate"
  
  int i = 0;
  while (filtered.charAt(i) != ' ')//---------- filtering for the first number by polling "space"
    i++;
 
  String first_num = filtered.substring(0, i);
  i++;
  
  int j = 0;
  while (filtered.charAt(j + i) != ' ')//---------- filtering for the sign by polling 2nd space
    j++;
  
  String sign = filtered.substring(i, j + i);
  j++;
  char* s_con = &sign[0];

 
  int k = 0;
  while (filtered.charAt(k + i + j) != '\0' )//---------- filtering for the second number by polling "new line"
    k++;
 
  String second_num = filtered.substring(j + i, k + j + i);
 

  float first = first_num.toFloat();//---------- converting String to
  float secondd = second_num.toFloat();//------- float

  {
    if (strstr(s_con, plus1) || strstr(s_con, plus2))
    {
      result = first + secondd;
      return (result);
    }
    else if (strstr(s_con, minus1) || strstr(s_con, minus2))
    {
      result = first - secondd;
      return (result);
    }
    else if (strstr(s_con, mul1) || strstr(s_con, mul2) || strstr(s_con, mul3) || strstr(s_con, mul4))
    {
      result = first * secondd;
      return (result);
    }
    else if (strstr(s_con,div1) || strstr(s_con,div2) || strstr(s_con,div3) || strstr(s_con,div4))
    {
      result = first / secondd;
      return (result);
    }

    else
    {
      Serial.println("");
      Serial.println("Please write in proper format, number1 sign number2. for eg. 1 + 2");
      Serial.println("Or check out the spelling");
      Serial.println("");

  }
}
}

