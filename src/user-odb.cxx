// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "user-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/mysql/traits.hxx>
#include <odb/mysql/database.hxx>
#include <odb/mysql/transaction.hxx>
#include <odb/mysql/connection.hxx>
#include <odb/mysql/statement.hxx>
#include <odb/mysql/statement-cache.hxx>
#include <odb/mysql/simple-object-statements.hxx>
#include <odb/mysql/container-statements.hxx>
#include <odb/mysql/exceptions.hxx>
#include <odb/mysql/simple-object-result.hxx>
#include <odb/mysql/enum.hxx>

namespace odb
{
  // User
  //

  struct access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      mysql::connection&,
      image_type&,
      mysql::binding&,
      mysql::binding&)
    {
    }
  };

  access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::id_type
  access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  id (const image_type& i)
  {
    mysql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        id,
        i.username_value,
        i.username_size,
        i.username_null);
    }

    return id;
  }

  bool access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  grow (image_type& i,
        my_bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // username_
    //
    if (t[0UL])
    {
      i.username_value.capacity (i.username_size);
      grew = true;
    }

    // password_
    //
    if (t[1UL])
    {
      i.password_value.capacity (i.password_size);
      grew = true;
    }

    // name_
    //
    if (t[2UL])
    {
      i.name_value.capacity (i.name_size);
      grew = true;
    }

    // maildir_
    //
    if (t[3UL])
    {
      i.maildir_value.capacity (i.maildir_size);
      grew = true;
    }

    // quota_
    //
    t[4UL] = 0;

    // local_part_
    //
    if (t[5UL])
    {
      i.local_part_value.capacity (i.local_part_size);
      grew = true;
    }

    // domain_
    //
    if (t[6UL])
    {
      i.domain_value.capacity (i.domain_size);
      grew = true;
    }

    // recovery_mail_
    //
    if (t[7UL])
    {
      i.recovery_mail_value.capacity (i.recovery_mail_size);
      grew = true;
    }

    // pubkey_
    //
    if (t[8UL])
    {
      i.pubkey_value.capacity (i.pubkey_size);
      grew = true;
    }

    // created_
    //
    t[9UL] = 0;

    // modified_
    //
    t[10UL] = 0;

    // active_
    //
    t[11UL] = 0;

    return grew;
  }

  void access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  bind (MYSQL_BIND* b,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

    // username_
    //
    if (sk != statement_update)
    {
      b[n].buffer_type = MYSQL_TYPE_STRING;
      b[n].buffer = i.username_value.data ();
      b[n].buffer_length = static_cast<unsigned long> (
        i.username_value.capacity ());
      b[n].length = &i.username_size;
      b[n].is_null = &i.username_null;
      n++;
    }

    // password_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.password_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.password_value.capacity ());
    b[n].length = &i.password_size;
    b[n].is_null = &i.password_null;
    n++;

    // name_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.name_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.name_value.capacity ());
    b[n].length = &i.name_size;
    b[n].is_null = &i.name_null;
    n++;

    // maildir_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.maildir_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.maildir_value.capacity ());
    b[n].length = &i.maildir_size;
    b[n].is_null = &i.maildir_null;
    n++;

    // quota_
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &i.quota_value;
    b[n].is_null = &i.quota_null;
    n++;

    // local_part_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.local_part_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.local_part_value.capacity ());
    b[n].length = &i.local_part_size;
    b[n].is_null = &i.local_part_null;
    n++;

    // domain_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.domain_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.domain_value.capacity ());
    b[n].length = &i.domain_size;
    b[n].is_null = &i.domain_null;
    n++;

    // recovery_mail_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.recovery_mail_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.recovery_mail_value.capacity ());
    b[n].length = &i.recovery_mail_size;
    b[n].is_null = &i.recovery_mail_null;
    n++;

    // pubkey_
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.pubkey_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.pubkey_value.capacity ());
    b[n].length = &i.pubkey_size;
    b[n].is_null = &i.pubkey_null;
    n++;

    // created_
    //
    b[n].buffer_type = MYSQL_TYPE_DATETIME;
    b[n].buffer = &i.created_value;
    b[n].is_null = &i.created_null;
    n++;

    // modified_
    //
    b[n].buffer_type = MYSQL_TYPE_DATETIME;
    b[n].buffer = &i.modified_value;
    b[n].is_null = &i.modified_null;
    n++;

    // active_
    //
    b[n].buffer_type = MYSQL_TYPE_TINY;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.active_value;
    b[n].is_null = &i.active_null;
    n++;
  }

  void access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.id_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.id_value.capacity ());
    b[n].length = &i.id_size;
    b[n].is_null = &i.id_null;
  }

  bool access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  init (image_type& i,
        const object_type& o,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    bool grew (false);

    // username_
    //
    if (sk == statement_insert)
    {
      ::std::string const& v =
        o.username_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.username_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.username_value,
        size,
        is_null,
        v);
      i.username_null = is_null;
      i.username_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.username_value.capacity ());
    }

    // password_
    //
    {
      ::std::string const& v =
        o.password_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.password_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.password_value,
        size,
        is_null,
        v);
      i.password_null = is_null;
      i.password_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.password_value.capacity ());
    }

    // name_
    //
    {
      ::std::string const& v =
        o.name_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.name_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.name_value,
        size,
        is_null,
        v);
      i.name_null = is_null;
      i.name_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.name_value.capacity ());
    }

    // maildir_
    //
    {
      ::std::string const& v =
        o.maildir_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.maildir_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.maildir_value,
        size,
        is_null,
        v);
      i.maildir_null = is_null;
      i.maildir_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.maildir_value.capacity ());
    }

    // quota_
    //
    {
      long long unsigned int const& v =
        o.quota_;

      bool is_null (false);
      mysql::value_traits<
          long long unsigned int,
          mysql::id_ulonglong >::set_image (
        i.quota_value, is_null, v);
      i.quota_null = is_null;
    }

    // local_part_
    //
    {
      ::std::string const& v =
        o.local_part_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.local_part_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.local_part_value,
        size,
        is_null,
        v);
      i.local_part_null = is_null;
      i.local_part_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.local_part_value.capacity ());
    }

    // domain_
    //
    {
      ::std::string const& v =
        o.domain_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.domain_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.domain_value,
        size,
        is_null,
        v);
      i.domain_null = is_null;
      i.domain_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.domain_value.capacity ());
    }

    // recovery_mail_
    //
    {
      ::std::string const& v =
        o.recovery_mail_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.recovery_mail_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.recovery_mail_value,
        size,
        is_null,
        v);
      i.recovery_mail_null = is_null;
      i.recovery_mail_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.recovery_mail_value.capacity ());
    }

    // pubkey_
    //
    {
      ::std::string const& v =
        o.pubkey_;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.pubkey_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.pubkey_value,
        size,
        is_null,
        v);
      i.pubkey_null = is_null;
      i.pubkey_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.pubkey_value.capacity ());
    }

    // created_
    //
    {
      ::boost::posix_time::ptime const& v =
        o.created_;

      bool is_null (true);
      mysql::value_traits<
          ::boost::posix_time::ptime,
          mysql::id_datetime >::set_image (
        i.created_value, is_null, v);
      i.created_null = is_null;
    }

    // modified_
    //
    {
      ::boost::posix_time::ptime const& v =
        o.modified_;

      bool is_null (true);
      mysql::value_traits<
          ::boost::posix_time::ptime,
          mysql::id_datetime >::set_image (
        i.modified_value, is_null, v);
      i.modified_null = is_null;
    }

    // active_
    //
    {
      bool const& v =
        o.active_;

      bool is_null (false);
      mysql::value_traits<
          bool,
          mysql::id_tiny >::set_image (
        i.active_value, is_null, v);
      i.active_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // username_
    //
    {
      ::std::string& v =
        o.username_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.username_value,
        i.username_size,
        i.username_null);
    }

    // password_
    //
    {
      ::std::string& v =
        o.password_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.password_value,
        i.password_size,
        i.password_null);
    }

    // name_
    //
    {
      ::std::string& v =
        o.name_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.name_value,
        i.name_size,
        i.name_null);
    }

    // maildir_
    //
    {
      ::std::string& v =
        o.maildir_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.maildir_value,
        i.maildir_size,
        i.maildir_null);
    }

    // quota_
    //
    {
      long long unsigned int& v =
        o.quota_;

      mysql::value_traits<
          long long unsigned int,
          mysql::id_ulonglong >::set_value (
        v,
        i.quota_value,
        i.quota_null);
    }

    // local_part_
    //
    {
      ::std::string& v =
        o.local_part_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.local_part_value,
        i.local_part_size,
        i.local_part_null);
    }

    // domain_
    //
    {
      ::std::string& v =
        o.domain_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.domain_value,
        i.domain_size,
        i.domain_null);
    }

    // recovery_mail_
    //
    {
      ::std::string& v =
        o.recovery_mail_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.recovery_mail_value,
        i.recovery_mail_size,
        i.recovery_mail_null);
    }

    // pubkey_
    //
    {
      ::std::string& v =
        o.pubkey_;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.pubkey_value,
        i.pubkey_size,
        i.pubkey_null);
    }

    // created_
    //
    {
      ::boost::posix_time::ptime& v =
        o.created_;

      mysql::value_traits<
          ::boost::posix_time::ptime,
          mysql::id_datetime >::set_value (
        v,
        i.created_value,
        i.created_null);
    }

    // modified_
    //
    {
      ::boost::posix_time::ptime& v =
        o.modified_;

      mysql::value_traits<
          ::boost::posix_time::ptime,
          mysql::id_datetime >::set_value (
        v,
        i.modified_value,
        i.modified_null);
    }

    // active_
    //
    {
      bool& v =
        o.active_;

      mysql::value_traits<
          bool,
          mysql::id_tiny >::set_value (
        v,
        i.active_value,
        i.active_null);
    }
  }

  void access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    bool grew (false);
    {
      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.id_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.id_value,
        size,
        is_null,
        id);
      i.id_null = is_null;
      i.id_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.id_value.capacity ());
    }

    if (grew)
      i.version++;
  }

  const char access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::persist_statement[] =
  "INSERT INTO `User` "
  "(`username`, "
  "`password`, "
  "`name`, "
  "`maildir`, "
  "`quota`, "
  "`local_part`, "
  "`domain`, "
  "`recovery_mail`, "
  "`pubkey`, "
  "`created`, "
  "`modified`, "
  "`active`) "
  "VALUES "
  "(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::find_statement[] =
  "SELECT "
  "`User`.`username`, "
  "`User`.`password`, "
  "`User`.`name`, "
  "`User`.`maildir`, "
  "`User`.`quota`, "
  "`User`.`local_part`, "
  "`User`.`domain`, "
  "`User`.`recovery_mail`, "
  "`User`.`pubkey`, "
  "`User`.`created`, "
  "`User`.`modified`, "
  "`User`.`active` "
  "FROM `User` "
  "WHERE `User`.`username`=?";

  const char access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::update_statement[] =
  "UPDATE `User` "
  "SET "
  "`password`=?, "
  "`name`=?, "
  "`maildir`=?, "
  "`quota`=?, "
  "`local_part`=?, "
  "`domain`=?, "
  "`recovery_mail`=?, "
  "`pubkey`=?, "
  "`created`=?, "
  "`modified`=?, "
  "`active`=? "
  "WHERE `username`=?";

  const char access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::erase_statement[] =
  "DELETE FROM `User` "
  "WHERE `username`=?";

  const char access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::query_statement[] =
  "SELECT "
  "`User`.`username`, "
  "`User`.`password`, "
  "`User`.`name`, "
  "`User`.`maildir`, "
  "`User`.`quota`, "
  "`User`.`local_part`, "
  "`User`.`domain`, "
  "`User`.`recovery_mail`, "
  "`User`.`pubkey`, "
  "`User`.`created`, "
  "`User`.`modified`, "
  "`User`.`active` "
  "FROM `User`";

  const char access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::erase_query_statement[] =
  "DELETE FROM `User`";

  const char access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::table_name[] =
  "`User`";

  void access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  persist (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              obj,
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    callback (db,
              obj,
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mysql;
    using mysql::update_statement;

    callback (db, obj, callback_event::pre_update);

    mysql::transaction& tr (mysql::transaction::current ());
    mysql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj.username_);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  erase (database& db, const id_type& id)
  {
    using namespace mysql;

    ODB_POTENTIALLY_UNUSED (db);

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::pointer_type
  access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  find (database& db, const id_type& id)
  {
    using namespace mysql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  reload (database& db, object_type& obj)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.username_);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace mysql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::object_type >
  access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  query (database&, const query_base_type& q)
  {
    using namespace mysql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        false,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) mysql::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::UserManagementInterface::User, id_mysql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>
