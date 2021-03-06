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

