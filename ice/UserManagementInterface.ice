module UserManagementInterface {

  enum statuscode {
    SUCCESS,
    FAILURE,
    FAILUREUSEREXISTS,
    FAILUREEMPTYSTRING
  };

  interface RPCObject {

    /* add user */
    statuscode addUser(string username, string name, string password, string domain, long quota, bool active);

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
