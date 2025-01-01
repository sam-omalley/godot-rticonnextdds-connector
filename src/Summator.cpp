#include "Summator.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

Summator::Summator() :
    participant( 0 ), subscriber( participant ), topic( participant, "Example ShapeTypeExtended" ),
    reader( subscriber, topic )
{
}

void Summator::_bind_methods()
{
    ClassDB::bind_method( D_METHOD( "hello" ), &Summator::hello );
}

void Summator::hello() const
{
    UtilityFunctions::print( "Hello, world!" );
}
