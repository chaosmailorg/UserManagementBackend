#ifndef DATABASEEXCEPTION_INCLUDED__
#define DATABASEEXCEPTION_INCLUDED__

#include <exception>

class DatabaseException : public std::exception
{
  private:
  const char* _msg;

  public:
  DatabaseException(const char* msg) {
    _msg = msg;
  }

  virtual const char* what() const throw() {
    return _msg;
  }

};


#endif

