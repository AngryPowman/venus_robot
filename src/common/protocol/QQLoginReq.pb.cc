// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: QQLoginReq.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "QQLoginReq.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Protocol {

namespace {

const ::google::protobuf::Descriptor* QQLoginReq_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  QQLoginReq_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_QQLoginReq_2eproto() {
  protobuf_AddDesc_QQLoginReq_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "QQLoginReq.proto");
  GOOGLE_CHECK(file != NULL);
  QQLoginReq_descriptor_ = file->message_type(0);
  static const int QQLoginReq_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QQLoginReq, account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QQLoginReq, password_),
  };
  QQLoginReq_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      QQLoginReq_descriptor_,
      QQLoginReq::default_instance_,
      QQLoginReq_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QQLoginReq, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QQLoginReq, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(QQLoginReq));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_QQLoginReq_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    QQLoginReq_descriptor_, &QQLoginReq::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_QQLoginReq_2eproto() {
  delete QQLoginReq::default_instance_;
  delete QQLoginReq_reflection_;
}

void protobuf_AddDesc_QQLoginReq_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::Protocol::protobuf_AddDesc_MessageBase_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020QQLoginReq.proto\022\010Protocol\032\021MessageBas"
    "e.proto\"/\n\nQQLoginReq\022\017\n\007account\030\001 \002(\t\022\020"
    "\n\010password\030\002 \002(\t", 96);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "QQLoginReq.proto", &protobuf_RegisterTypes);
  QQLoginReq::default_instance_ = new QQLoginReq();
  QQLoginReq::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_QQLoginReq_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_QQLoginReq_2eproto {
  StaticDescriptorInitializer_QQLoginReq_2eproto() {
    protobuf_AddDesc_QQLoginReq_2eproto();
  }
} static_descriptor_initializer_QQLoginReq_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int QQLoginReq::kAccountFieldNumber;
const int QQLoginReq::kPasswordFieldNumber;
#endif  // !_MSC_VER

QQLoginReq::QQLoginReq()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void QQLoginReq::InitAsDefaultInstance() {
}

QQLoginReq::QQLoginReq(const QQLoginReq& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void QQLoginReq::SharedCtor() {
  _cached_size_ = 0;
  account_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

QQLoginReq::~QQLoginReq() {
  SharedDtor();
}

void QQLoginReq::SharedDtor() {
  if (account_ != &::google::protobuf::internal::kEmptyString) {
    delete account_;
  }
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    delete password_;
  }
  if (this != default_instance_) {
  }
}

void QQLoginReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* QQLoginReq::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return QQLoginReq_descriptor_;
}

const QQLoginReq& QQLoginReq::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_QQLoginReq_2eproto();
  return *default_instance_;
}

QQLoginReq* QQLoginReq::default_instance_ = NULL;

QQLoginReq* QQLoginReq::New() const {
  return new QQLoginReq;
}

void QQLoginReq::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_account()) {
      if (account_ != &::google::protobuf::internal::kEmptyString) {
        account_->clear();
      }
    }
    if (has_password()) {
      if (password_ != &::google::protobuf::internal::kEmptyString) {
        password_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool QQLoginReq::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string account = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_account()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->account().data(), this->account().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_password;
        break;
      }

      // required string password = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_password:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_password()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->password().data(), this->password().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void QQLoginReq::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string account = 1;
  if (has_account()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->account().data(), this->account().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->account(), output);
  }

  // required string password = 2;
  if (has_password()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->password().data(), this->password().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->password(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* QQLoginReq::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string account = 1;
  if (has_account()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->account().data(), this->account().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->account(), target);
  }

  // required string password = 2;
  if (has_password()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->password().data(), this->password().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->password(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int QQLoginReq::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string account = 1;
    if (has_account()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->account());
    }

    // required string password = 2;
    if (has_password()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->password());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void QQLoginReq::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const QQLoginReq* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const QQLoginReq*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void QQLoginReq::MergeFrom(const QQLoginReq& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_account()) {
      set_account(from.account());
    }
    if (from.has_password()) {
      set_password(from.password());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void QQLoginReq::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void QQLoginReq::CopyFrom(const QQLoginReq& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool QQLoginReq::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void QQLoginReq::Swap(QQLoginReq* other) {
  if (other != this) {
    std::swap(account_, other->account_);
    std::swap(password_, other->password_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata QQLoginReq::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = QQLoginReq_descriptor_;
  metadata.reflection = QQLoginReq_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)