#include "ShapeReader.h"

#include <string>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void Shape::_bind_methods()
{
    ClassDB::bind_method( D_METHOD( "set_position", "_position" ), &Shape::set_position );
    ClassDB::bind_method( D_METHOD( "get_position" ), &Shape::get_position );
    ADD_PROPERTY( godot::PropertyInfo( godot::Variant::VECTOR2, "position" ), "set_position",
                  "get_position" );

    ClassDB::bind_method( D_METHOD( "set_name", "_position" ), &Shape::set_name );
    ClassDB::bind_method( D_METHOD( "get_name" ), &Shape::get_name );
    ADD_PROPERTY( godot::PropertyInfo( godot::Variant::STRING, "name" ), "set_name", "get_name" );

    ClassDB::bind_method( D_METHOD( "set_size", "_position" ), &Shape::set_size );
    ClassDB::bind_method( D_METHOD( "get_size" ), &Shape::get_size );
    ADD_PROPERTY( godot::PropertyInfo( godot::Variant::INT, "size" ), "set_size", "get_size" );

    ClassDB::bind_method( D_METHOD( "set_angle", "_position" ), &Shape::set_angle );
    ClassDB::bind_method( D_METHOD( "get_angle" ), &Shape::get_angle );
    ADD_PROPERTY( godot::PropertyInfo( godot::Variant::FLOAT, "angle" ), "set_angle", "get_angle" );
}
godot::Vector2 Shape::get_position() const
{
    return position;
}

void Shape::set_position( godot::Vector2 _position )
{
    position = _position;
}

int Shape::get_size() const
{
    return size;
}
void Shape::set_size( int _size )
{
    size = _size;
}

godot::String Shape::get_name() const
{
    return name;
}
void Shape::set_name( godot::String _name )
{
    name = _name;
}

float Shape::get_angle() const
{
    return angle;
}
void Shape::set_angle( float _angle )
{
    angle = _angle;
}

ShapeReader::ShapeReader() :
    participant( dds::core::null ), subscriber( dds::core::null ), topic( dds::core::null ),
    reader( dds::core::null )
{
}

void ShapeReader::_bind_methods()
{
    ClassDB::bind_method( D_METHOD( "set_participant", "dp" ), &ShapeReader::set_participant );
    ClassDB::bind_method( D_METHOD( "subscribe", "topic_name" ), &ShapeReader::subscribe );
    ClassDB::bind_method( D_METHOD( "read" ), &ShapeReader::read );
}
void ShapeReader::subscribe( const String &topic_name )
{
    if ( participant.is_nil() )
    {
        UtilityFunctions::printerr( "Must call set_participant before subscribe" );
        return;
    }

    topic =
        dds::topic::Topic<::ShapeTypeExtended>( participant, std::string( topic_name.ascii() ) );
    reader = dds::sub::DataReader<::ShapeTypeExtended>( subscriber, topic );
}

void ShapeReader::set_participant( DomainParticipant *dp )
{
    participant = dp->get_participant();
    subscriber = dds::sub::Subscriber( participant );
}

godot::TypedArray<Shape> ShapeReader::read()
{
    // Take all samples
    dds::sub::LoanedSamples<::ShapeTypeExtended> samples = reader.take();

    godot::TypedArray<Shape> arr;
    for ( const auto &sample : samples )
    {
        if ( sample.info().valid() )
        {
            Shape *s = memnew( Shape() );
            auto data = sample.data();
            s->set_position( Vector2( data.x(), data.y() ) );
            s->set_size( data.shapesize() );
            s->set_angle( data.angle() );
            s->set_name( godot::String( data.color().c_str() ) );
            arr.push_back( s );
        }
    }

    return arr;
}