#ifndef EXCEPTION_H_INCLUDED
#define EXCEPTION_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;
class SetException {
 private:
  string info;

 public:
  SetException(const string& s) : info(s) { cout << info << endl; };
  string getException() { return info; }
};

#endif  // EXCEPTION_H_INCLUDED
