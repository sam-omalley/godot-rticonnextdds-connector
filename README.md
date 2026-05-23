# RTI Connext DDS Connector for Godot

A [GDExtension](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/index.html) that integrates [RTI Connext DDS](https://www.rti.com/products/connext-dds-professional) into [Godot 4](https://godotengine.org/), exposing DDS publish/subscribe to GDScript.

![Screenshot](https://raw.githubusercontent.com/sam-omalley/godot-rticonnextdds-connector-demo/main/screenshots/shapes_demo.png)

See [godot-rticonnextdds-connector-demo](https://github.com/sam-omalley/godot-rticonnextdds-connector-demo) for a working example.

## Exposed Classes

| Class | Description |
|-------|-------------|
| `DomainParticipant` | Creates and manages a DDS domain participant |
| `ShapeReader` | Subscribes to a DDS topic and reads ShapeType data |
| `Shape` | Represents a single DDS shape sample |

Currently implements the [DDS Shapes Demo](https://www.rti.com/developers/rti-labs/shapes-demo) topic type.

## Prerequisites

- [RTI Connext DDS Professional](https://www.rti.com/products/connext-dds-professional) (with `NDDSHOME` set)
- CMake ≥ 3.23
- Ninja
- Godot 4

## Build

```sh
cmake --preset linux-release   # or windows-release / macOS-release
cmake --build ../build_RtiConnextDdsConnector_Linux-x86_64
```

Copy the resulting `.so` / `.dll` / `.dylib` into your Godot project's extension folder.

## Using Your Own IDL

The files `ShapeType.cxx`, `ShapeType.hpp`, `ShapeTypePlugin.cxx`, and `ShapeTypePlugin.hpp` are generated from `ShapeType.idl` using `rtiddsgen`, which is bundled with RTI Connext DDS. The pre-generated files are included for convenience, but if you want to adapt this connector for your own DDS types, regenerate them from your own IDL:

```sh
rtiddsgen -language C++11 YourType.idl
```

Then replace the ShapeType source files and update `ShapeReader` to match your type.
