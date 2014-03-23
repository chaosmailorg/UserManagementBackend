// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef USER_ODB_HXX
#define USER_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20300UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

// Begin prologue.
//
#include <odb/boost/version.hxx>
#if ODB_BOOST_VERSION != 2030000 // 2.3.0
#  error ODB and C++ compilers see different libodb-boost interface versions
#endif
#include <boost/shared_ptr.hpp>
#include <odb/boost/smart-ptr/pointer-traits.hxx>
#include <odb/boost/smart-ptr/wrapper-traits.hxx>
#include <odb/boost/optional/wrapper-traits.hxx>
#include <odb/boost/unordered/container-traits.hxx>
#include <odb/boost/date-time/mysql/gregorian-traits.hxx>
#include <odb/boost/date-time/mysql/posix-time-traits.hxx>
#include <odb/boost/multi-index/container-traits.hxx>
#include <odb/boost/uuid/mysql/uuid-traits.hxx>
//
// End prologue.

#include "user.hxx"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#ifdef BOOST_TR1_MEMORY_HPP_INCLUDED
#  include <odb/tr1/wrapper-traits.hxx>
#  include <odb/tr1/pointer-traits.hxx>
#endif
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // User
  //
  template <>
  struct class_traits< ::UserManagementInterface::User >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::UserManagementInterface::User >
  {
    public:
    typedef ::UserManagementInterface::User object_type;
    typedef ::boost::shared_ptr< ::UserManagementInterface::User > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::std::string id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/mysql/version.hxx>
#include <odb/mysql/forward.hxx>
#include <odb/mysql/binding.hxx>
#include <odb/mysql/mysql-types.hxx>
#include <odb/mysql/query.hxx>

namespace odb
{
  // User
  //
  template <typename A>
  struct query_columns< ::UserManagementInterface::User, id_mysql, A >
  {
    // username
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    username_type_;

    static const username_type_ username;

    // password
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    password_type_;

    static const password_type_ password;

    // name
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    name_type_;

    static const name_type_ name;

    // maildir
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    maildir_type_;

    static const maildir_type_ maildir;

    // quota
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        long long unsigned int,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    quota_type_;

    static const quota_type_ quota;

    // local_part
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    local_part_type_;

    static const local_part_type_ local_part;

    // domain
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    domain_type_;

    static const domain_type_ domain;

    // recovery_mail
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    recovery_mail_type_;

    static const recovery_mail_type_ recovery_mail;

    // created
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::boost::posix_time::ptime,
        mysql::id_datetime >::query_type,
      mysql::id_datetime >
    created_type_;

    static const created_type_ created;

    // modified
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::boost::posix_time::ptime,
        mysql::id_datetime >::query_type,
      mysql::id_datetime >
    modified_type_;

    static const modified_type_ modified;

    // active
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        bool,
        mysql::id_tiny >::query_type,
      mysql::id_tiny >
    active_type_;

    static const active_type_ active;
  };

  template <typename A>
  const typename query_columns< ::UserManagementInterface::User, id_mysql, A >::username_type_
  query_columns< ::UserManagementInterface::User, id_mysql, A >::
  username (A::table_name, "`username`", 0);

  template <typename A>
  const typename query_columns< ::UserManagementInterface::User, id_mysql, A >::password_type_
  query_columns< ::UserManagementInterface::User, id_mysql, A >::
  password (A::table_name, "`password`", 0);

  template <typename A>
  const typename query_columns< ::UserManagementInterface::User, id_mysql, A >::name_type_
  query_columns< ::UserManagementInterface::User, id_mysql, A >::
  name (A::table_name, "`name`", 0);

  template <typename A>
  const typename query_columns< ::UserManagementInterface::User, id_mysql, A >::maildir_type_
  query_columns< ::UserManagementInterface::User, id_mysql, A >::
  maildir (A::table_name, "`maildir`", 0);

  template <typename A>
  const typename query_columns< ::UserManagementInterface::User, id_mysql, A >::quota_type_
  query_columns< ::UserManagementInterface::User, id_mysql, A >::
  quota (A::table_name, "`quota`", 0);

  template <typename A>
  const typename query_columns< ::UserManagementInterface::User, id_mysql, A >::local_part_type_
  query_columns< ::UserManagementInterface::User, id_mysql, A >::
  local_part (A::table_name, "`local_part`", 0);

  template <typename A>
  const typename query_columns< ::UserManagementInterface::User, id_mysql, A >::domain_type_
  query_columns< ::UserManagementInterface::User, id_mysql, A >::
  domain (A::table_name, "`domain`", 0);

  template <typename A>
  const typename query_columns< ::UserManagementInterface::User, id_mysql, A >::recovery_mail_type_
  query_columns< ::UserManagementInterface::User, id_mysql, A >::
  recovery_mail (A::table_name, "`recovery_mail`", 0);

  template <typename A>
  const typename query_columns< ::UserManagementInterface::User, id_mysql, A >::created_type_
  query_columns< ::UserManagementInterface::User, id_mysql, A >::
  created (A::table_name, "`created`", 0);

  template <typename A>
  const typename query_columns< ::UserManagementInterface::User, id_mysql, A >::modified_type_
  query_columns< ::UserManagementInterface::User, id_mysql, A >::
  modified (A::table_name, "`modified`", 0);

  template <typename A>
  const typename query_columns< ::UserManagementInterface::User, id_mysql, A >::active_type_
  query_columns< ::UserManagementInterface::User, id_mysql, A >::
  active (A::table_name, "`active`", 0);

  template <typename A>
  struct pointer_query_columns< ::UserManagementInterface::User, id_mysql, A >:
    query_columns< ::UserManagementInterface::User, id_mysql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::UserManagementInterface::User, id_mysql >:
    public access::object_traits< ::UserManagementInterface::User >
  {
    public:
    struct id_image_type
    {
      details::buffer id_value;
      unsigned long id_size;
      my_bool id_null;

      std::size_t version;
    };

    struct image_type
    {
      // username_
      //
      details::buffer username_value;
      unsigned long username_size;
      my_bool username_null;

      // password_
      //
      details::buffer password_value;
      unsigned long password_size;
      my_bool password_null;

      // name_
      //
      details::buffer name_value;
      unsigned long name_size;
      my_bool name_null;

      // maildir_
      //
      details::buffer maildir_value;
      unsigned long maildir_size;
      my_bool maildir_null;

      // quota_
      //
      unsigned long long quota_value;
      my_bool quota_null;

      // local_part_
      //
      details::buffer local_part_value;
      unsigned long local_part_size;
      my_bool local_part_null;

      // domain_
      //
      details::buffer domain_value;
      unsigned long domain_size;
      my_bool domain_null;

      // recovery_mail_
      //
      details::buffer recovery_mail_value;
      unsigned long recovery_mail_size;
      my_bool recovery_mail_null;

      // created_
      //
      MYSQL_TIME created_value;
      my_bool created_null;

      // modified_
      //
      MYSQL_TIME modified_value;
      my_bool modified_null;

      // active_
      //
      signed char active_value;
      my_bool active_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          my_bool*);

    static void
    bind (MYSQL_BIND*,
          image_type&,
          mysql::statement_kind);

    static void
    bind (MYSQL_BIND*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef mysql::object_statements<object_type> statements_type;

    typedef mysql::query_base query_base_type;

    static const std::size_t column_count = 11UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, const object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::UserManagementInterface::User, id_common >:
    public access::object_traits_impl< ::UserManagementInterface::User, id_mysql >
  {
  };

  // User
  //
}

#include "user-odb.ixx"

#include <odb/post.hxx>

#endif // USER_ODB_HXX
