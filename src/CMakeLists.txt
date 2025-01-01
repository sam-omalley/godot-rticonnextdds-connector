# SPDX-License-Identifier: Unlicense

target_sources( ${PROJECT_NAME}
    PRIVATE
        Example.h
        Example.cpp
        GDExtensionTemplate.h
        GDExtensionTemplate.cpp
        RegisterExtension.cpp
        Summator.cpp
        ShapeType.cxx
        ShapeTypePlugin.cxx
)

target_include_directories( ${PROJECT_NAME}
    PRIVATE
        "src"
)
