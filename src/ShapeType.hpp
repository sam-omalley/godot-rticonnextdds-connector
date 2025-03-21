

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ShapeType.idl
using RTI Code Generator (rtiddsgen) version 4.3.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ShapeType_434673741_hpp
#define ShapeType_434673741_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/External.hpp"
#include "rti/core/LongDouble.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/core/array.hpp"
#include "rti/topic/TopicTraits.hpp"

#include "omg/types/string_view.hpp"

#include "rti/core/BoundedSequence.hpp"
#include "dds/core/Optional.hpp"

#ifndef NDDS_STANDALONE_TYPE
#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

enum class ShapeFillKind {
    SOLID_FILL, 
    TRANSPARENT_FILL, 
    HORIZONTAL_HATCH_FILL, 
    VERTICAL_HATCH_FILL
};

NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const ShapeFillKind& sample);

class NDDSUSERDllExport ShapeType {
  public:

    ShapeType();

    ShapeType(const std::string& color_,int32_t x_,int32_t y_,int32_t shapesize_);

    std::string& color() noexcept {
        return m_color_;
    }

    const std::string& color() const noexcept {
        return m_color_;
    }

    void color(const std::string& value) {

        m_color_ = value;
    }

    void color(std::string&& value) {
        m_color_ = std::move(value);
    }
    int32_t& x() noexcept {
        return m_x_;
    }

    const int32_t& x() const noexcept {
        return m_x_;
    }

    void x(int32_t value) {

        m_x_ = value;
    }

    int32_t& y() noexcept {
        return m_y_;
    }

    const int32_t& y() const noexcept {
        return m_y_;
    }

    void y(int32_t value) {

        m_y_ = value;
    }

    int32_t& shapesize() noexcept {
        return m_shapesize_;
    }

    const int32_t& shapesize() const noexcept {
        return m_shapesize_;
    }

    void shapesize(int32_t value) {

        m_shapesize_ = value;
    }

    bool operator == (const ShapeType& other_) const;
    bool operator != (const ShapeType& other_) const;

    void swap(ShapeType& other_) noexcept ;

  private:

    std::string m_color_;
    int32_t m_x_;
    int32_t m_y_;
    int32_t m_shapesize_;

};

inline void swap(ShapeType& a, ShapeType& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ShapeType& sample);

class NDDSUSERDllExport ShapeTypeExtended
: public ::ShapeType {
  public:

    ShapeTypeExtended();

    ShapeTypeExtended(const std::string& color_,int32_t x_,int32_t y_,int32_t shapesize_,const ::ShapeFillKind& fillKind_,float angle_);

    ::ShapeFillKind& fillKind() noexcept {
        return m_fillKind_;
    }

    const ::ShapeFillKind& fillKind() const noexcept {
        return m_fillKind_;
    }

    void fillKind(const ::ShapeFillKind& value) {

        m_fillKind_ = value;
    }

    void fillKind(::ShapeFillKind&& value) {
        m_fillKind_ = std::move(value);
    }
    float& angle() noexcept {
        return m_angle_;
    }

    const float& angle() const noexcept {
        return m_angle_;
    }

    void angle(float value) {

        m_angle_ = value;
    }

    bool operator == (const ShapeTypeExtended& other_) const;
    bool operator != (const ShapeTypeExtended& other_) const;

    void swap(ShapeTypeExtended& other_) noexcept ;

  private:

    ::ShapeFillKind m_fillKind_;
    float m_angle_;

};

inline void swap(ShapeTypeExtended& a, ShapeTypeExtended& b)  noexcept 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ShapeTypeExtended& sample);

#ifdef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace topic {
        template <>
        struct default_enumerator< ::ShapeFillKind>
        {
            static const ::ShapeFillKind value;
        };
    }
}
#else

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< ::ShapeType > {
            NDDSUSERDllExport static std::string value() {
                return "ShapeType";
            }
        };

        template<>
        struct is_topic_type< ::ShapeType > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::ShapeType > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::ShapeType& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::ShapeType& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::ShapeType& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::ShapeType& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< ::ShapeTypeExtended > {
            NDDSUSERDllExport static std::string value() {
                return "ShapeTypeExtended";
            }
        };

        template<>
        struct is_topic_type< ::ShapeTypeExtended > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ::ShapeTypeExtended > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ::ShapeTypeExtended& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(::ShapeTypeExtended& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(::ShapeTypeExtended& sample);

            NDDSUSERDllExport 
            static void allocate_sample(::ShapeTypeExtended& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
    }
}

namespace rti { 
    namespace topic {

        template <>
        struct default_enumerator< ::ShapeFillKind>
        {
            static const ::ShapeFillKind value;
        };
        template<>
        struct dynamic_type< ::ShapeFillKind > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };

        template <>
        struct extensibility< ::ShapeFillKind > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::ShapeType > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::ShapeType > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        template<>
        struct dynamic_type< ::ShapeTypeExtended > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };

        template <>
        struct extensibility< ::ShapeTypeExtended > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

    }
}

#endif // NDDS_STANDALONE_TYPE
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // ShapeType_434673741_hpp

