// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: QQLoginReq.proto

#ifndef PROTOBUF_QQLoginReq_2eproto__INCLUDED
#define PROTOBUF_QQLoginReq_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "MessageBase.pb.h"
// @@protoc_insertion_point(includes)

namespace Protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_QQLoginReq_2eproto();
void protobuf_AssignDesc_QQLoginReq_2eproto();
void protobuf_ShutdownFile_QQLoginReq_2eproto();

class QQLoginReq;

// ===================================================================

class QQLoginReq : public ::google::protobuf::Message {
 public:
  QQLoginReq();
  virtual ~QQLoginReq();

  QQLoginReq(const QQLoginReq& from);

  inline QQLoginReq& operator=(const QQLoginReq& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const QQLoginReq& default_instance();

  void Swap(QQLoginReq* other);

  // implements Message ----------------------------------------------

  QQLoginReq* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const QQLoginReq& from);
  void MergeFrom(const QQLoginReq& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string account = 1;
  inline bool has_account() const;
  inline void clear_account();
  static const int kAccountFieldNumber = 1;
  inline const ::std::string& account() const;
  inline void set_account(const ::std::string& value);
  inline void set_account(const char* value);
  inline void set_account(const char* value, size_t size);
  inline ::std::string* mutable_account();
  inline ::std::string* release_account();
  inline void set_allocated_account(::std::string* account);

  // required string password = 2;
  inline bool has_password() const;
  inline void clear_password();
  static const int kPasswordFieldNumber = 2;
  inline const ::std::string& password() const;
  inline void set_password(const ::std::string& value);
  inline void set_password(const char* value);
  inline void set_password(const char* value, size_t size);
  inline ::std::string* mutable_password();
  inline ::std::string* release_password();
  inline void set_allocated_password(::std::string* password);

  // @@protoc_insertion_point(class_scope:Protocol.QQLoginReq)
 private:
  inline void set_has_account();
  inline void clear_has_account();
  inline void set_has_password();
  inline void clear_has_password();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* account_;
  ::std::string* password_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_QQLoginReq_2eproto();
  friend void protobuf_AssignDesc_QQLoginReq_2eproto();
  friend void protobuf_ShutdownFile_QQLoginReq_2eproto();

  void InitAsDefaultInstance();
  static QQLoginReq* default_instance_;
};
// ===================================================================


// ===================================================================

// QQLoginReq

// required string account = 1;
inline bool QQLoginReq::has_account() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void QQLoginReq::set_has_account() {
  _has_bits_[0] |= 0x00000001u;
}
inline void QQLoginReq::clear_has_account() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void QQLoginReq::clear_account() {
  if (account_ != &::google::protobuf::internal::kEmptyString) {
    account_->clear();
  }
  clear_has_account();
}
inline const ::std::string& QQLoginReq::account() const {
  return *account_;
}
inline void QQLoginReq::set_account(const ::std::string& value) {
  set_has_account();
  if (account_ == &::google::protobuf::internal::kEmptyString) {
    account_ = new ::std::string;
  }
  account_->assign(value);
}
inline void QQLoginReq::set_account(const char* value) {
  set_has_account();
  if (account_ == &::google::protobuf::internal::kEmptyString) {
    account_ = new ::std::string;
  }
  account_->assign(value);
}
inline void QQLoginReq::set_account(const char* value, size_t size) {
  set_has_account();
  if (account_ == &::google::protobuf::internal::kEmptyString) {
    account_ = new ::std::string;
  }
  account_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* QQLoginReq::mutable_account() {
  set_has_account();
  if (account_ == &::google::protobuf::internal::kEmptyString) {
    account_ = new ::std::string;
  }
  return account_;
}
inline ::std::string* QQLoginReq::release_account() {
  clear_has_account();
  if (account_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = account_;
    account_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void QQLoginReq::set_allocated_account(::std::string* account) {
  if (account_ != &::google::protobuf::internal::kEmptyString) {
    delete account_;
  }
  if (account) {
    set_has_account();
    account_ = account;
  } else {
    clear_has_account();
    account_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string password = 2;
inline bool QQLoginReq::has_password() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void QQLoginReq::set_has_password() {
  _has_bits_[0] |= 0x00000002u;
}
inline void QQLoginReq::clear_has_password() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void QQLoginReq::clear_password() {
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    password_->clear();
  }
  clear_has_password();
}
inline const ::std::string& QQLoginReq::password() const {
  return *password_;
}
inline void QQLoginReq::set_password(const ::std::string& value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(value);
}
inline void QQLoginReq::set_password(const char* value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(value);
}
inline void QQLoginReq::set_password(const char* value, size_t size) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* QQLoginReq::mutable_password() {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  return password_;
}
inline ::std::string* QQLoginReq::release_password() {
  clear_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = password_;
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void QQLoginReq::set_allocated_password(::std::string* password) {
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    delete password_;
  }
  if (password) {
    set_has_password();
    password_ = password;
  } else {
    clear_has_password();
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_QQLoginReq_2eproto__INCLUDED