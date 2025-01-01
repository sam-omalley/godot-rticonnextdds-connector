#include "DomainParticipant.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

DomainParticipant::DomainParticipant() : participant( dds::core::null )
{
}

void DomainParticipant::_bind_methods()
{
    godot::ClassDB::bind_method( godot::D_METHOD( "setup", "domain_id" ),
                                 &DomainParticipant::setup );
    godot::ClassDB::bind_method( godot::D_METHOD( "teardown" ), &DomainParticipant::teardown );
}

void DomainParticipant::setup( int domain_id )
{
    participant = dds::domain::DomainParticipant( domain_id );
}

void DomainParticipant::teardown()
{
    participant->close_contained_entities();
    participant.close();
}

dds::domain::DomainParticipant DomainParticipant::get_participant() const
{
    return participant;
}