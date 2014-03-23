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

module UserManagementInterface {

  enum statuscode {
    SUCCESS,
    FAILURE,
    FAILUREUSEREXISTS,
    FAILUREEMPTYSTRING
  };

  struct addUserRet {
    statuscode returncode;
    string password;
  };

  interface RPCObject {

    /* add user */
    addUserRet addUser(string username, string name, string recoveryMail, long quota, bool active);

    /* change user password */
    statuscode changeUserPassword(string usernam, string newpassword);

    /* change user quota */
    statuscode changeUserQuota(string username, long quota);

    /* returns true if user exists */
    bool existsUser(string username);

    /* returns number of useraccounts */
    int userCount();
    
  };
};
