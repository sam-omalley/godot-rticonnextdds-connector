#pragma once

#include <godot_cpp/classes/object.hpp>

#include <dds/core/ddscore.hpp>
#include <dds/sub/ddssub.hpp>

#include "DomainParticipant.h"
#include "ShapeType.hpp"

using namespace godot;

class ShapeReader : public Object
{
    GDCLASS( ShapeReader, Object )

public:
    ShapeReader();
    void subscribe(const String& topic_name);
    void set_participant( DomainParticipant *dp );

protected:
    static void _bind_methods();

private:
    dds::domain::DomainParticipant participant;
    dds::sub::Subscriber subscriber;
    dds::topic::Topic<::ShapeTypeExtended> topic;
    dds::sub::DataReader<::ShapeTypeExtended> reader;
};