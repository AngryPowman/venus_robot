// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: QQLoginCaptchaConfirm.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "QQLoginCaptchaConfirm.pb.h"

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

const ::google::protobuf::Descriptor* QQLoginCaptchaConfirm_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  QQLoginCaptchaConfirm_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_QQLoginCaptchaConfirm_2eproto() {
  protobuf_AddDesc_QQLoginCaptchaConfirm_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "QQLoginCaptchaConfirm.proto");
  GOOGLE_CHECK(file != NULL);
  QQLoginCaptchaConfirm_descriptor_ = file->message_type(0);
  static const int QQLoginCaptchaConfirm_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QQLoginCaptchaConfirm, captcha_code_),
  };
  QQLoginCaptchaConfirm_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      QQLoginCaptchaConfirm_descriptor_,
      QQLoginCaptchaConfirm::default_instance_,
      QQLoginCaptchaConfirm_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QQLoginCaptchaConfirm, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(QQLoginCaptchaConfirm, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(QQLoginCaptchaConfirm));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_QQLoginCaptchaConfirm_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    QQLoginCaptchaConfirm_descriptor_, &QQLoginCaptchaConfirm::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_QQLoginCaptchaConfirm_2eproto() {
  delete QQLoginCaptchaConfirm::default_instance_;
  delete QQLoginCaptchaConfirm_reflection_;
}

void protobuf_AddDesc_QQLoginCaptchaConfirm_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::Protocol::protobuf_AddDesc_MessageBase_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\033QQLoginCaptchaConfirm.proto\022\010Protocol\032"
    "\021MessageBase.proto\"-\n\025QQLoginCaptchaConf"
    "irm\022\024\n\014captcha_code\030\001 \002(\t", 105);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "QQLoginCaptchaConfirm.proto", &protobuf_RegisterTypes);
  QQLoginCaptchaConfirm::default_instance_ = new QQLoginCaptchaConfirm();
  QQLoginCaptchaConfirm::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_QQLoginCaptchaConfirm_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_QQLoginCaptchaConfirm_2eproto {
  StaticDescriptorInitializer_QQLoginCaptchaConfirm_2eproto() {
    protobuf_AddDesc_QQLoginCaptchaConfirm_2eproto();
  }
} static_descriptor_initializer_QQLoginCaptchaConfirm_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int QQLoginCaptchaConfirm::kCaptchaCodeFieldNumber;
#endif  // !_MSC_VER

QQLoginCaptchaConfirm::QQLoginCaptchaConfirm()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void QQLoginCaptchaConfirm::InitAsDefaultInstance() {
}

QQLoginCaptchaConfirm::QQLoginCaptchaConfirm(const QQLoginCaptchaConfirm& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void QQLoginCaptchaConfirm::SharedCtor() {
  _cached_size_ = 0;
  captcha_code_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

QQLoginCaptchaConfirm::~QQLoginCaptchaConfirm() {
  SharedDtor();
}

void QQLoginCaptchaConfirm::SharedDtor() {
  if (captcha_code_ != &::google::protobuf::internal::kEmptyString) {
    delete captcha_code_;
  }
  if (this != default_instance_) {
  }
}

void QQLoginCaptchaConfirm::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* QQLoginCaptchaConfirm::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return QQLoginCaptchaConfirm_descriptor_;
}

const QQLoginCaptchaConfirm& QQLoginCaptchaConfirm::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_QQLoginCaptchaConfirm_2eproto();
  return *default_instance_;
}

QQLoginCaptchaConfirm* QQLoginCaptchaConfirm::default_instance_ = NULL;

QQLoginCaptchaConfirm* QQLoginCaptchaConfirm::New() const {
  return new QQLoginCaptchaConfirm;
}

void QQLoginCaptchaConfirm::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_captcha_code()) {
      if (captcha_code_ != &::google::protobuf::internal::kEmptyString) {
        captcha_code_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool QQLoginCaptchaConfirm::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string captcha_code = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_captcha_code()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->captcha_code().data(), this->captcha_code().length(),
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

void QQLoginCaptchaConfirm::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string captcha_code = 1;
  if (has_captcha_code()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->captcha_code().data(), this->captcha_code().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->captcha_code(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* QQLoginCaptchaConfirm::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string captcha_code = 1;
  if (has_captcha_code()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->captcha_code().data(), this->captcha_code().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->captcha_code(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int QQLoginCaptchaConfirm::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string captcha_code = 1;
    if (has_captcha_code()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->captcha_code());
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

void QQLoginCaptchaConfirm::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const QQLoginCaptchaConfirm* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const QQLoginCaptchaConfirm*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void QQLoginCaptchaConfirm::MergeFrom(const QQLoginCaptchaConfirm& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_captcha_code()) {
      set_captcha_code(from.captcha_code());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void QQLoginCaptchaConfirm::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void QQLoginCaptchaConfirm::CopyFrom(const QQLoginCaptchaConfirm& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool QQLoginCaptchaConfirm::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void QQLoginCaptchaConfirm::Swap(QQLoginCaptchaConfirm* other) {
  if (other != this) {
    std::swap(captcha_code_, other->captcha_code_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata QQLoginCaptchaConfirm::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = QQLoginCaptchaConfirm_descriptor_;
  metadata.reflection = QQLoginCaptchaConfirm_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)