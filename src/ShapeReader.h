#pragma once

#include <godot_cpp/classes/object.hpp>

#include <dds/core/ddscore.hpp>
#include <dds/sub/ddssub.hpp>

#include "DomainParticipant.h"
#include "ShapeType.hpp"

using namespace godot;

class Shape : public Object
{
    GDCLASS( Shape, Object )

public:
    godot::Vector2 get_position() const;
    void set_position( godot::Vector2 _position );

    int get_size() const;
    void set_size( int _size );

    godot::String get_name() const;
    void set_name( godot::String _name );

    float get_angle() const;
    void set_angle( float _angle );

private:
    godot::Vector2 position;
    int size;
    godot::String name;
    float angle;

protected:
    static void _bind_methods();
};

class ShapeReader : public Object
{
    GDCLASS( ShapeReader, Object )

public:
    ShapeReader();
    ~ShapeReader() override;
    void subscribe( const String &topic_name );
    void set_participant( DomainParticipant *dp );
    godot::TypedArray<Shape> get_data();
    godot::TypedArray<String> get_dead_data();

protected:
    static void _bind_methods();

private:
    dds::domain::DomainParticipant participant;
    dds::sub::Subscriber subscriber;
    dds::topic::Topic<::ShapeTypeExtended> topic;
    dds::sub::DataReader<::ShapeTypeExtended> reader;
};