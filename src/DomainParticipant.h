#pragma once

#include <godot_cpp/classes/object.hpp>

#include <dds/core/ddscore.hpp>

using namespace godot;

class DomainParticipant : public Object
{
    GDCLASS( DomainParticipant, Object )

public:
    DomainParticipant();
    ~DomainParticipant() override;
    void setup( int domain_id );
    void test(DomainParticipant* me);
    dds::domain::DomainParticipant get_participant() const;

protected:
    static void _bind_methods();

private:
    dds::domain::DomainParticipant participant;
};