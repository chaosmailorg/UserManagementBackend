#include "user.hxx"


namespace UserManagementInterface {

  User::User(const std::string & username,
    const std::string & password,
    const std::string & name,
    const std::string & maildir,
    unsigned long long quota,
    const std::string & local_part,
    const std::string & domain,
    boost::posix_time::ptime created,
    boost::posix_time::ptime modified,
    bool active) : username_(username),
    password_(password),
    name_(name),
    maildir_(maildir),
    quota_(quota),
    local_part_(local_part),
    domain_(domain),
    created_(created),
    modified_(modified),
    active_(active)
    { }

  const std::string & User::username() const {
    return username_;
  }

  void User::username(std::string & username) {
    username_ = username;
  }

  const std::string & User::password() const {
    return password_;
  }

  void User::password(std::string & password) {
    password_ = password;
  }

  const std::string & User::name() const {
    return name_;
  }

  void User::name(std::string & name) {
    name_ = name;
  }

  const std::string & User::maildir() const {
    return maildir_;
  }

  void User::maildir(std::string & maildir) {
    maildir_ = maildir;
  }

  unsigned long long User::quota() const {
    return quota_;
  }

  void User::quota(unsigned long long quota) {
    quota_ = quota;
  }

  const std::string & User::local_part() const {
    return local_part_;
  }

  void User::local_part(std::string & local_part) {
    local_part_ = local_part;
  }

  const std::string & User::domain() const {
    return domain_;
  }

  void User::domain(std::string & domain) {
    domain_ = domain;
  }

  boost::posix_time::ptime User::created() const {
    return created_;
  }

  void User::created(boost::posix_time::ptime created) {
    created_ = created;
  }

  boost::posix_time::ptime User::modified() const {
    return modified_;
  }

  void User::modified(boost::posix_time::ptime modified) {
    modified_ = modified;
  }

  bool User::active() const {
    return active_;
  }

  void User::active(bool active) {
    active_ = active;
  }

}
