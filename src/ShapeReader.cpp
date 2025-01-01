#include "ShapeReader.h"

#include <string>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

ShapeReader::ShapeReader() :
    participant( dds::core::null ), subscriber( dds::core::null ), topic( dds::core::null ),
    reader( dds::core::null )
{
}

void ShapeReader::_bind_methods()
{
    ClassDB::bind_method( D_METHOD( "set_participant", "dp" ), &ShapeReader::set_participant );
    ClassDB::bind_method( D_METHOD( "subscribe", "topic_name" ), &ShapeReader::subscribe );
}
void ShapeReader::subscribe( const String &topic_name )
{
    if ( participant.is_nil() )
    {
        UtilityFunctions::printerr( "Must call set_participant before subscribe" );
        return;
    }

    topic = dds::topic::Topic<::ShapeTypeExtended>( participant, std::string(topic_name.ascii()) );
    reader = dds::sub::DataReader<::ShapeTypeExtended>( subscriber, topic );
}

void ShapeReader::set_participant( DomainParticipant *dp )
{
    participant = dp->get_participant();
    subscriber = dds::sub::Subscriber( participant );
}
