// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: User.proto

#ifndef PROTOBUF_INCLUDED_User_2eproto
#define PROTOBUF_INCLUDED_User_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_User_2eproto 

namespace protobuf_User_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[5];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_User_2eproto
namespace User {
class ReLogin;
class ReLoginDefaultTypeInternal;
extern ReLoginDefaultTypeInternal _ReLogin_default_instance_;
class ReRegister;
class ReRegisterDefaultTypeInternal;
extern ReRegisterDefaultTypeInternal _ReRegister_default_instance_;
class RqLogin;
class RqLoginDefaultTypeInternal;
extern RqLoginDefaultTypeInternal _RqLogin_default_instance_;
class RqRegister;
class RqRegisterDefaultTypeInternal;
extern RqRegisterDefaultTypeInternal _RqRegister_default_instance_;
class role;
class roleDefaultTypeInternal;
extern roleDefaultTypeInternal _role_default_instance_;
}  // namespace User
namespace google {
namespace protobuf {
template<> ::User::ReLogin* Arena::CreateMaybeMessage<::User::ReLogin>(Arena*);
template<> ::User::ReRegister* Arena::CreateMaybeMessage<::User::ReRegister>(Arena*);
template<> ::User::RqLogin* Arena::CreateMaybeMessage<::User::RqLogin>(Arena*);
template<> ::User::RqRegister* Arena::CreateMaybeMessage<::User::RqRegister>(Arena*);
template<> ::User::role* Arena::CreateMaybeMessage<::User::role>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace User {

// ===================================================================

class ReLogin : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:User.ReLogin) */ {
 public:
  ReLogin();
  virtual ~ReLogin();

  ReLogin(const ReLogin& from);

  inline ReLogin& operator=(const ReLogin& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ReLogin(ReLogin&& from) noexcept
    : ReLogin() {
    *this = ::std::move(from);
  }

  inline ReLogin& operator=(ReLogin&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ReLogin& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ReLogin* internal_default_instance() {
    return reinterpret_cast<const ReLogin*>(
               &_ReLogin_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ReLogin* other);
  friend void swap(ReLogin& a, ReLogin& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ReLogin* New() const final {
    return CreateMaybeMessage<ReLogin>(NULL);
  }

  ReLogin* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ReLogin>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ReLogin& from);
  void MergeFrom(const ReLogin& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ReLogin* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // string pswd = 2;
  void clear_pswd();
  static const int kPswdFieldNumber = 2;
  const ::std::string& pswd() const;
  void set_pswd(const ::std::string& value);
  #if LANG_CXX11
  void set_pswd(::std::string&& value);
  #endif
  void set_pswd(const char* value);
  void set_pswd(const char* value, size_t size);
  ::std::string* mutable_pswd();
  ::std::string* release_pswd();
  void set_allocated_pswd(::std::string* pswd);

  // @@protoc_insertion_point(class_scope:User.ReLogin)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr pswd_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_User_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class RqLogin : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:User.RqLogin) */ {
 public:
  RqLogin();
  virtual ~RqLogin();

  RqLogin(const RqLogin& from);

  inline RqLogin& operator=(const RqLogin& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RqLogin(RqLogin&& from) noexcept
    : RqLogin() {
    *this = ::std::move(from);
  }

  inline RqLogin& operator=(RqLogin&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RqLogin& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RqLogin* internal_default_instance() {
    return reinterpret_cast<const RqLogin*>(
               &_RqLogin_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(RqLogin* other);
  friend void swap(RqLogin& a, RqLogin& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RqLogin* New() const final {
    return CreateMaybeMessage<RqLogin>(NULL);
  }

  RqLogin* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<RqLogin>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const RqLogin& from);
  void MergeFrom(const RqLogin& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RqLogin* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int32 code = 1;
  void clear_code();
  static const int kCodeFieldNumber = 1;
  ::google::protobuf::int32 code() const;
  void set_code(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:User.RqLogin)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 code_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_User_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class ReRegister : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:User.ReRegister) */ {
 public:
  ReRegister();
  virtual ~ReRegister();

  ReRegister(const ReRegister& from);

  inline ReRegister& operator=(const ReRegister& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ReRegister(ReRegister&& from) noexcept
    : ReRegister() {
    *this = ::std::move(from);
  }

  inline ReRegister& operator=(ReRegister&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ReRegister& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ReRegister* internal_default_instance() {
    return reinterpret_cast<const ReRegister*>(
               &_ReRegister_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(ReRegister* other);
  friend void swap(ReRegister& a, ReRegister& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ReRegister* New() const final {
    return CreateMaybeMessage<ReRegister>(NULL);
  }

  ReRegister* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ReRegister>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ReRegister& from);
  void MergeFrom(const ReRegister& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ReRegister* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // string pswd = 2;
  void clear_pswd();
  static const int kPswdFieldNumber = 2;
  const ::std::string& pswd() const;
  void set_pswd(const ::std::string& value);
  #if LANG_CXX11
  void set_pswd(::std::string&& value);
  #endif
  void set_pswd(const char* value);
  void set_pswd(const char* value, size_t size);
  ::std::string* mutable_pswd();
  ::std::string* release_pswd();
  void set_allocated_pswd(::std::string* pswd);

  // string phone = 3;
  void clear_phone();
  static const int kPhoneFieldNumber = 3;
  const ::std::string& phone() const;
  void set_phone(const ::std::string& value);
  #if LANG_CXX11
  void set_phone(::std::string&& value);
  #endif
  void set_phone(const char* value);
  void set_phone(const char* value, size_t size);
  ::std::string* mutable_phone();
  ::std::string* release_phone();
  void set_allocated_phone(::std::string* phone);

  // string email = 4;
  void clear_email();
  static const int kEmailFieldNumber = 4;
  const ::std::string& email() const;
  void set_email(const ::std::string& value);
  #if LANG_CXX11
  void set_email(::std::string&& value);
  #endif
  void set_email(const char* value);
  void set_email(const char* value, size_t size);
  ::std::string* mutable_email();
  ::std::string* release_email();
  void set_allocated_email(::std::string* email);

  // @@protoc_insertion_point(class_scope:User.ReRegister)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::internal::ArenaStringPtr pswd_;
  ::google::protobuf::internal::ArenaStringPtr phone_;
  ::google::protobuf::internal::ArenaStringPtr email_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_User_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class RqRegister : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:User.RqRegister) */ {
 public:
  RqRegister();
  virtual ~RqRegister();

  RqRegister(const RqRegister& from);

  inline RqRegister& operator=(const RqRegister& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RqRegister(RqRegister&& from) noexcept
    : RqRegister() {
    *this = ::std::move(from);
  }

  inline RqRegister& operator=(RqRegister&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RqRegister& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RqRegister* internal_default_instance() {
    return reinterpret_cast<const RqRegister*>(
               &_RqRegister_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(RqRegister* other);
  friend void swap(RqRegister& a, RqRegister& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RqRegister* New() const final {
    return CreateMaybeMessage<RqRegister>(NULL);
  }

  RqRegister* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<RqRegister>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const RqRegister& from);
  void MergeFrom(const RqRegister& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RqRegister* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int32 code = 1;
  void clear_code();
  static const int kCodeFieldNumber = 1;
  ::google::protobuf::int32 code() const;
  void set_code(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:User.RqRegister)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 code_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_User_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class role : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:User.role) */ {
 public:
  role();
  virtual ~role();

  role(const role& from);

  inline role& operator=(const role& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  role(role&& from) noexcept
    : role() {
    *this = ::std::move(from);
  }

  inline role& operator=(role&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const role& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const role* internal_default_instance() {
    return reinterpret_cast<const role*>(
               &_role_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    4;

  void Swap(role* other);
  friend void swap(role& a, role& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline role* New() const final {
    return CreateMaybeMessage<role>(NULL);
  }

  role* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<role>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const role& from);
  void MergeFrom(const role& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(role* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string roleName = 1;
  void clear_rolename();
  static const int kRoleNameFieldNumber = 1;
  const ::std::string& rolename() const;
  void set_rolename(const ::std::string& value);
  #if LANG_CXX11
  void set_rolename(::std::string&& value);
  #endif
  void set_rolename(const char* value);
  void set_rolename(const char* value, size_t size);
  ::std::string* mutable_rolename();
  ::std::string* release_rolename();
  void set_allocated_rolename(::std::string* rolename);

  // int32 exp = 2;
  void clear_exp();
  static const int kExpFieldNumber = 2;
  ::google::protobuf::int32 exp() const;
  void set_exp(::google::protobuf::int32 value);

  // int32 money = 3;
  void clear_money();
  static const int kMoneyFieldNumber = 3;
  ::google::protobuf::int32 money() const;
  void set_money(::google::protobuf::int32 value);

  // int32 level = 4;
  void clear_level();
  static const int kLevelFieldNumber = 4;
  ::google::protobuf::int32 level() const;
  void set_level(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:User.role)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr rolename_;
  ::google::protobuf::int32 exp_;
  ::google::protobuf::int32 money_;
  ::google::protobuf::int32 level_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_User_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ReLogin

// string name = 1;
inline void ReLogin::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ReLogin::name() const {
  // @@protoc_insertion_point(field_get:User.ReLogin.name)
  return name_.GetNoArena();
}
inline void ReLogin::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:User.ReLogin.name)
}
#if LANG_CXX11
inline void ReLogin::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:User.ReLogin.name)
}
#endif
inline void ReLogin::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:User.ReLogin.name)
}
inline void ReLogin::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:User.ReLogin.name)
}
inline ::std::string* ReLogin::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:User.ReLogin.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ReLogin::release_name() {
  // @@protoc_insertion_point(field_release:User.ReLogin.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ReLogin::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:User.ReLogin.name)
}

// string pswd = 2;
inline void ReLogin::clear_pswd() {
  pswd_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ReLogin::pswd() const {
  // @@protoc_insertion_point(field_get:User.ReLogin.pswd)
  return pswd_.GetNoArena();
}
inline void ReLogin::set_pswd(const ::std::string& value) {
  
  pswd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:User.ReLogin.pswd)
}
#if LANG_CXX11
inline void ReLogin::set_pswd(::std::string&& value) {
  
  pswd_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:User.ReLogin.pswd)
}
#endif
inline void ReLogin::set_pswd(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  pswd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:User.ReLogin.pswd)
}
inline void ReLogin::set_pswd(const char* value, size_t size) {
  
  pswd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:User.ReLogin.pswd)
}
inline ::std::string* ReLogin::mutable_pswd() {
  
  // @@protoc_insertion_point(field_mutable:User.ReLogin.pswd)
  return pswd_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ReLogin::release_pswd() {
  // @@protoc_insertion_point(field_release:User.ReLogin.pswd)
  
  return pswd_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ReLogin::set_allocated_pswd(::std::string* pswd) {
  if (pswd != NULL) {
    
  } else {
    
  }
  pswd_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), pswd);
  // @@protoc_insertion_point(field_set_allocated:User.ReLogin.pswd)
}

// -------------------------------------------------------------------

// RqLogin

// int32 code = 1;
inline void RqLogin::clear_code() {
  code_ = 0;
}
inline ::google::protobuf::int32 RqLogin::code() const {
  // @@protoc_insertion_point(field_get:User.RqLogin.code)
  return code_;
}
inline void RqLogin::set_code(::google::protobuf::int32 value) {
  
  code_ = value;
  // @@protoc_insertion_point(field_set:User.RqLogin.code)
}

// -------------------------------------------------------------------

// ReRegister

// string name = 1;
inline void ReRegister::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ReRegister::name() const {
  // @@protoc_insertion_point(field_get:User.ReRegister.name)
  return name_.GetNoArena();
}
inline void ReRegister::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:User.ReRegister.name)
}
#if LANG_CXX11
inline void ReRegister::set_name(::std::string&& value) {
  
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:User.ReRegister.name)
}
#endif
inline void ReRegister::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:User.ReRegister.name)
}
inline void ReRegister::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:User.ReRegister.name)
}
inline ::std::string* ReRegister::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:User.ReRegister.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ReRegister::release_name() {
  // @@protoc_insertion_point(field_release:User.ReRegister.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ReRegister::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:User.ReRegister.name)
}

// string pswd = 2;
inline void ReRegister::clear_pswd() {
  pswd_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ReRegister::pswd() const {
  // @@protoc_insertion_point(field_get:User.ReRegister.pswd)
  return pswd_.GetNoArena();
}
inline void ReRegister::set_pswd(const ::std::string& value) {
  
  pswd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:User.ReRegister.pswd)
}
#if LANG_CXX11
inline void ReRegister::set_pswd(::std::string&& value) {
  
  pswd_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:User.ReRegister.pswd)
}
#endif
inline void ReRegister::set_pswd(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  pswd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:User.ReRegister.pswd)
}
inline void ReRegister::set_pswd(const char* value, size_t size) {
  
  pswd_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:User.ReRegister.pswd)
}
inline ::std::string* ReRegister::mutable_pswd() {
  
  // @@protoc_insertion_point(field_mutable:User.ReRegister.pswd)
  return pswd_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ReRegister::release_pswd() {
  // @@protoc_insertion_point(field_release:User.ReRegister.pswd)
  
  return pswd_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ReRegister::set_allocated_pswd(::std::string* pswd) {
  if (pswd != NULL) {
    
  } else {
    
  }
  pswd_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), pswd);
  // @@protoc_insertion_point(field_set_allocated:User.ReRegister.pswd)
}

// string phone = 3;
inline void ReRegister::clear_phone() {
  phone_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ReRegister::phone() const {
  // @@protoc_insertion_point(field_get:User.ReRegister.phone)
  return phone_.GetNoArena();
}
inline void ReRegister::set_phone(const ::std::string& value) {
  
  phone_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:User.ReRegister.phone)
}
#if LANG_CXX11
inline void ReRegister::set_phone(::std::string&& value) {
  
  phone_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:User.ReRegister.phone)
}
#endif
inline void ReRegister::set_phone(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  phone_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:User.ReRegister.phone)
}
inline void ReRegister::set_phone(const char* value, size_t size) {
  
  phone_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:User.ReRegister.phone)
}
inline ::std::string* ReRegister::mutable_phone() {
  
  // @@protoc_insertion_point(field_mutable:User.ReRegister.phone)
  return phone_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ReRegister::release_phone() {
  // @@protoc_insertion_point(field_release:User.ReRegister.phone)
  
  return phone_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ReRegister::set_allocated_phone(::std::string* phone) {
  if (phone != NULL) {
    
  } else {
    
  }
  phone_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), phone);
  // @@protoc_insertion_point(field_set_allocated:User.ReRegister.phone)
}

// string email = 4;
inline void ReRegister::clear_email() {
  email_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& ReRegister::email() const {
  // @@protoc_insertion_point(field_get:User.ReRegister.email)
  return email_.GetNoArena();
}
inline void ReRegister::set_email(const ::std::string& value) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:User.ReRegister.email)
}
#if LANG_CXX11
inline void ReRegister::set_email(::std::string&& value) {
  
  email_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:User.ReRegister.email)
}
#endif
inline void ReRegister::set_email(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:User.ReRegister.email)
}
inline void ReRegister::set_email(const char* value, size_t size) {
  
  email_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:User.ReRegister.email)
}
inline ::std::string* ReRegister::mutable_email() {
  
  // @@protoc_insertion_point(field_mutable:User.ReRegister.email)
  return email_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* ReRegister::release_email() {
  // @@protoc_insertion_point(field_release:User.ReRegister.email)
  
  return email_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void ReRegister::set_allocated_email(::std::string* email) {
  if (email != NULL) {
    
  } else {
    
  }
  email_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), email);
  // @@protoc_insertion_point(field_set_allocated:User.ReRegister.email)
}

// -------------------------------------------------------------------

// RqRegister

// int32 code = 1;
inline void RqRegister::clear_code() {
  code_ = 0;
}
inline ::google::protobuf::int32 RqRegister::code() const {
  // @@protoc_insertion_point(field_get:User.RqRegister.code)
  return code_;
}
inline void RqRegister::set_code(::google::protobuf::int32 value) {
  
  code_ = value;
  // @@protoc_insertion_point(field_set:User.RqRegister.code)
}

// -------------------------------------------------------------------

// role

// string roleName = 1;
inline void role::clear_rolename() {
  rolename_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& role::rolename() const {
  // @@protoc_insertion_point(field_get:User.role.roleName)
  return rolename_.GetNoArena();
}
inline void role::set_rolename(const ::std::string& value) {
  
  rolename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:User.role.roleName)
}
#if LANG_CXX11
inline void role::set_rolename(::std::string&& value) {
  
  rolename_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:User.role.roleName)
}
#endif
inline void role::set_rolename(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  rolename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:User.role.roleName)
}
inline void role::set_rolename(const char* value, size_t size) {
  
  rolename_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:User.role.roleName)
}
inline ::std::string* role::mutable_rolename() {
  
  // @@protoc_insertion_point(field_mutable:User.role.roleName)
  return rolename_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* role::release_rolename() {
  // @@protoc_insertion_point(field_release:User.role.roleName)
  
  return rolename_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void role::set_allocated_rolename(::std::string* rolename) {
  if (rolename != NULL) {
    
  } else {
    
  }
  rolename_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), rolename);
  // @@protoc_insertion_point(field_set_allocated:User.role.roleName)
}

// int32 exp = 2;
inline void role::clear_exp() {
  exp_ = 0;
}
inline ::google::protobuf::int32 role::exp() const {
  // @@protoc_insertion_point(field_get:User.role.exp)
  return exp_;
}
inline void role::set_exp(::google::protobuf::int32 value) {
  
  exp_ = value;
  // @@protoc_insertion_point(field_set:User.role.exp)
}

// int32 money = 3;
inline void role::clear_money() {
  money_ = 0;
}
inline ::google::protobuf::int32 role::money() const {
  // @@protoc_insertion_point(field_get:User.role.money)
  return money_;
}
inline void role::set_money(::google::protobuf::int32 value) {
  
  money_ = value;
  // @@protoc_insertion_point(field_set:User.role.money)
}

// int32 level = 4;
inline void role::clear_level() {
  level_ = 0;
}
inline ::google::protobuf::int32 role::level() const {
  // @@protoc_insertion_point(field_get:User.role.level)
  return level_;
}
inline void role::set_level(::google::protobuf::int32 value) {
  
  level_ = value;
  // @@protoc_insertion_point(field_set:User.role.level)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace User

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_User_2eproto