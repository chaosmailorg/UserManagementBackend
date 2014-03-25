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

#include "user.hxx"


namespace UserManagementInterface {

  User::User(const std::string & username,
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
    bool active) : username_(username),
    password_(password),
    name_(name),
    maildir_(maildir),
    quota_(quota),
    local_part_(local_part),
    domain_(domain),
    recovery_mail_(recovery_mail),
    pubkey_(pubkey),
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

  const std::string & User::recovery_mail() const {
    return recovery_mail_;
  }

  void User::recovery_mail(std::string & recovery_mail) {
    recovery_mail_ = recovery_mail;
  }

  const std::string & User::pubkey() const {
    return pubkey_;
  }

  void User::pubkey(std::string & pubkey) {
    pubkey_ = pubkey;
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
