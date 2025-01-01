#pragma once

#include <godot_cpp/classes/object.hpp>

#include <dds/core/ddscore.hpp>
#include <dds/sub/ddssub.hpp>

#include "ShapeType.hpp"

using namespace godot;

class Summator : public Object
{
    GDCLASS( Summator, Object )

public:
    Summator();
    void hello() const;

protected:
    static void _bind_methods();

private:
    dds::domain::DomainParticipant participant;
    dds::sub::Subscriber subscriber;
    dds::topic::Topic<::ShapeTypeExtended> topic;
    dds::sub::DataReader<::ShapeTypeExtended> reader;
};