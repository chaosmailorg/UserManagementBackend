/*
 *  Copyright (C) 2014 by Alexander Fischer <alexander.fischer@chaosmail.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

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
          const std::string & recovery_mail,
          const std::string & pubkey,
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

      const std::string & recovery_mail() const;
      void recovery_mail(std::string & recovery_mail);

      const std::string & pubkey() const;
      void pubkey(std::string & pubkey);

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
      std::string recovery_mail_;
      std::string pubkey_;
      boost::posix_time::ptime created_;
      boost::posix_time::ptime modified_;
      bool active_;
  };

#pragma db object(User)
#pragma db member(User::username_) id

}

#endif
