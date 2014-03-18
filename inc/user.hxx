#ifndef USER_INCLUDED__
#define USER_INCLUDED__

#include <string>
#include <ctime>
#include <odb/core.hxx>
#include <boost/date_time/posix_time/posix_time.hpp>

#pragma db value(boost::posix_time::ptime) type("DATETIME")

namespace UserManagementInterface {

  class User
  {

    public:
      User(const std::string & username,
          const std::string & password,
          const std::string & name,
          const std::string & maildir,
          unsigned long long quota,
          const std::string & local_part,
          const std::string & domain,
          boost::posix_time::ptime created,
          boost::posix_time::ptime modified,
          bool active);

      const std::string & username() const;
      void username(std::string & username);

      const std::string & password() const;
      void password(std::string & password);

      const std::string & name() const;
      void name(std::string & name);

      const std::string & maildir() const;
      void maildir(std::string & maildir);

      unsigned long long quota() const;
      void quota(unsigned long long quota);

      const std::string & local_part() const;
      void local_part(std::string & loacl_part);

      const std::string & domain() const;
      void domain(std::string & domain);

      boost::posix_time::ptime created() const;
      void created(boost::posix_time::ptime created);

      boost::posix_time::ptime modified() const;
      void modified(boost::posix_time::ptime modified);

      bool active() const;
      void active(bool active);

    private:
      User () {}

      friend class odb::access;

      std::string username_;
      std::string password_;
      std::string name_;
      std::string maildir_;
      unsigned long long quota_;
      std::string local_part_;
      std::string domain_;
      boost::posix_time::ptime created_;
      boost::posix_time::ptime modified_;
      bool active_;
  };

#pragma db object(User)
#pragma db member(User::username_) id

}

#endif
