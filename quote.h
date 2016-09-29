#ifndef quote_h
#define quote_h

#include <Arduino.h>
#include<String.h>

class Quote
{
  public:
      Quote(String payload);
      String saying_response(String payload);
      String author_response(String paylaod);

  private:
      char* _lower;

};

#endif
