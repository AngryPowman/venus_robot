// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: 20001_S2CQQLoginCaptchaNotify.proto

#ifndef PROTOBUF_20001_5fS2CQQLoginCaptchaNotify_2eproto__INCLUDED
#define PROTOBUF_20001_5fS2CQQLoginCaptchaNotify_2eproto__INCLUDED

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
// @@protoc_insertion_point(includes)

namespace Protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_20001_5fS2CQQLoginCaptchaNotify_2eproto();
void protobuf_AssignDesc_20001_5fS2CQQLoginCaptchaNotify_2eproto();
void protobuf_ShutdownFile_20001_5fS2CQQLoginCaptchaNotify_2eproto();

class S2CQQLoginChaptchaNotify;

// ===================================================================

class S2CQQLoginChaptchaNotify : public ::google::protobuf::Message {
 public:
  S2CQQLoginChaptchaNotify();
  virtual ~S2CQQLoginChaptchaNotify();

  S2CQQLoginChaptchaNotify(const S2CQQLoginChaptchaNotify& from);

  inline S2CQQLoginChaptchaNotify& operator=(const S2CQQLoginChaptchaNotify& from) {
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
  static const S2CQQLoginChaptchaNotify& default_instance();

  void Swap(S2CQQLoginChaptchaNotify* other);

  // implements Message ----------------------------------------------

  S2CQQLoginChaptchaNotify* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const S2CQQLoginChaptchaNotify& from);
  void MergeFrom(const S2CQQLoginChaptchaNotify& from);
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

  // required bytes captcha_data = 1;
  inline bool has_captcha_data() const;
  inline void clear_captcha_data();
  static const int kCaptchaDataFieldNumber = 1;
  inline const ::std::string& captcha_data() const;
  inline void set_captcha_data(const ::std::string& value);
  inline void set_captcha_data(const char* value);
  inline void set_captcha_data(const void* value, size_t size);
  inline ::std::string* mutable_captcha_data();
  inline ::std::string* release_captcha_data();
  inline void set_allocated_captcha_data(::std::string* captcha_data);

  // @@protoc_insertion_point(class_scope:Protocol.S2CQQLoginChaptchaNotify)
 private:
  inline void set_has_captcha_data();
  inline void clear_has_captcha_data();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* captcha_data_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_20001_5fS2CQQLoginCaptchaNotify_2eproto();
  friend void protobuf_AssignDesc_20001_5fS2CQQLoginCaptchaNotify_2eproto();
  friend void protobuf_ShutdownFile_20001_5fS2CQQLoginCaptchaNotify_2eproto();

  void InitAsDefaultInstance();
  static S2CQQLoginChaptchaNotify* default_instance_;
};
// ===================================================================


// ===================================================================

// S2CQQLoginChaptchaNotify

// required bytes captcha_data = 1;
inline bool S2CQQLoginChaptchaNotify::has_captcha_data() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void S2CQQLoginChaptchaNotify::set_has_captcha_data() {
  _has_bits_[0] |= 0x00000001u;
}
inline void S2CQQLoginChaptchaNotify::clear_has_captcha_data() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void S2CQQLoginChaptchaNotify::clear_captcha_data() {
  if (captcha_data_ != &::google::protobuf::internal::kEmptyString) {
    captcha_data_->clear();
  }
  clear_has_captcha_data();
}
inline const ::std::string& S2CQQLoginChaptchaNotify::captcha_data() const {
  return *captcha_data_;
}
inline void S2CQQLoginChaptchaNotify::set_captcha_data(const ::std::string& value) {
  set_has_captcha_data();
  if (captcha_data_ == &::google::protobuf::internal::kEmptyString) {
    captcha_data_ = new ::std::string;
  }
  captcha_data_->assign(value);
}
inline void S2CQQLoginChaptchaNotify::set_captcha_data(const char* value) {
  set_has_captcha_data();
  if (captcha_data_ == &::google::protobuf::internal::kEmptyString) {
    captcha_data_ = new ::std::string;
  }
  captcha_data_->assign(value);
}
inline void S2CQQLoginChaptchaNotify::set_captcha_data(const void* value, size_t size) {
  set_has_captcha_data();
  if (captcha_data_ == &::google::protobuf::internal::kEmptyString) {
    captcha_data_ = new ::std::string;
  }
  captcha_data_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* S2CQQLoginChaptchaNotify::mutable_captcha_data() {
  set_has_captcha_data();
  if (captcha_data_ == &::google::protobuf::internal::kEmptyString) {
    captcha_data_ = new ::std::string;
  }
  return captcha_data_;
}
inline ::std::string* S2CQQLoginChaptchaNotify::release_captcha_data() {
  clear_has_captcha_data();
  if (captcha_data_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = captcha_data_;
    captcha_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void S2CQQLoginChaptchaNotify::set_allocated_captcha_data(::std::string* captcha_data) {
  if (captcha_data_ != &::google::protobuf::internal::kEmptyString) {
    delete captcha_data_;
  }
  if (captcha_data) {
    set_has_captcha_data();
    captcha_data_ = captcha_data;
  } else {
    clear_has_captcha_data();
    captcha_data_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
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

#endif  // PROTOBUF_20001_5fS2CQQLoginCaptchaNotify_2eproto__INCLUDED
