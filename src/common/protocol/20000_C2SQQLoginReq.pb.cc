// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: 20000_C2SQQLoginReq.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "20000_C2SQQLoginReq.pb.h"

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

const ::google::protobuf::Descriptor* C2SQQLoginReq_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  C2SQQLoginReq_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_20000_5fC2SQQLoginReq_2eproto() {
  protobuf_AddDesc_20000_5fC2SQQLoginReq_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "20000_C2SQQLoginReq.proto");
  GOOGLE_CHECK(file != NULL);
  C2SQQLoginReq_descriptor_ = file->message_type(0);
  static const int C2SQQLoginReq_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SQQLoginReq, account_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SQQLoginReq, password_),
  };
  C2SQQLoginReq_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      C2SQQLoginReq_descriptor_,
      C2SQQLoginReq::default_instance_,
      C2SQQLoginReq_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SQQLoginReq, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(C2SQQLoginReq, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(C2SQQLoginReq));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_20000_5fC2SQQLoginReq_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    C2SQQLoginReq_descriptor_, &C2SQQLoginReq::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_20000_5fC2SQQLoginReq_2eproto() {
  delete C2SQQLoginReq::default_instance_;
  delete C2SQQLoginReq_reflection_;
}

void protobuf_AddDesc_20000_5fC2SQQLoginReq_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\03120000_C2SQQLoginReq.proto\022\010Protocol\"2\n"
    "\rC2SQQLoginReq\022\017\n\007account\030\001 \002(\t\022\020\n\010passw"
    "ord\030\002 \002(\t", 89);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "20000_C2SQQLoginReq.proto", &protobuf_RegisterTypes);
  C2SQQLoginReq::default_instance_ = new C2SQQLoginReq();
  C2SQQLoginReq::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_20000_5fC2SQQLoginReq_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_20000_5fC2SQQLoginReq_2eproto {
  StaticDescriptorInitializer_20000_5fC2SQQLoginReq_2eproto() {
    protobuf_AddDesc_20000_5fC2SQQLoginReq_2eproto();
  }
} static_descriptor_initializer_20000_5fC2SQQLoginReq_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int C2SQQLoginReq::kAccountFieldNumber;
const int C2SQQLoginReq::kPasswordFieldNumber;
#endif  // !_MSC_VER

C2SQQLoginReq::C2SQQLoginReq()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void C2SQQLoginReq::InitAsDefaultInstance() {
}

C2SQQLoginReq::C2SQQLoginReq(const C2SQQLoginReq& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void C2SQQLoginReq::SharedCtor() {
  _cached_size_ = 0;
  account_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

C2SQQLoginReq::~C2SQQLoginReq() {
  SharedDtor();
}

void C2SQQLoginReq::SharedDtor() {
  if (account_ != &::google::protobuf::internal::kEmptyString) {
    delete account_;
  }
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    delete password_;
  }
  if (this != default_instance_) {
  }
}

void C2SQQLoginReq::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* C2SQQLoginReq::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return C2SQQLoginReq_descriptor_;
}

const C2SQQLoginReq& C2SQQLoginReq::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_20000_5fC2SQQLoginReq_2eproto();
  return *default_instance_;
}

C2SQQLoginReq* C2SQQLoginReq::default_instance_ = NULL;

C2SQQLoginReq* C2SQQLoginReq::New() const {
  return new C2SQQLoginReq;
}

void C2SQQLoginReq::Clear() {
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

bool C2SQQLoginReq::MergePartialFromCodedStream(
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

void C2SQQLoginReq::SerializeWithCachedSizes(
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

::google::protobuf::uint8* C2SQQLoginReq::SerializeWithCachedSizesToArray(
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

int C2SQQLoginReq::ByteSize() const {
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

void C2SQQLoginReq::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const C2SQQLoginReq* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const C2SQQLoginReq*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void C2SQQLoginReq::MergeFrom(const C2SQQLoginReq& from) {
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

void C2SQQLoginReq::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void C2SQQLoginReq::CopyFrom(const C2SQQLoginReq& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool C2SQQLoginReq::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void C2SQQLoginReq::Swap(C2SQQLoginReq* other) {
  if (other != this) {
    std::swap(account_, other->account_);
    std::swap(password_, other->password_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata C2SQQLoginReq::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = C2SQQLoginReq_descriptor_;
  metadata.reflection = C2SQQLoginReq_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)