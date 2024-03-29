#!/usr/bin/env python
import os
import sys

env = SConscript("C:/Users/zemek/Desktop/CODE/Godot/GodotBindings_4.2/godot-cpp/SConstruct")

# For reference:
# - CCFLAGS are compilation flags shared between C and C++
# - CFLAGS are for C-specific compilation flags
# - CXXFLAGS are for C++-specific compilation flags
# - CPPFLAGS are for pre-processor flags
# - CPPDEFINES are for pre-processor defines
# - LINKFLAGS are for linking flags

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["Project1/sauce/"])
sources = Glob("Project1/*.cpp")

if env["platform"] == "macos":
    library = env.SharedLibrary(
        "C:/Users/zemek/Desktop/CODE/C++/malyjir/Zapoctak/godot-rts/DLLs/lib.{}.{}.framework/lib.{}.{}".format(
            env["platform"], env["target"], env["platform"], env["target"]
        ),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "C:/Users/zemek/Desktop/CODE/C++/malyjir/Zapoctak/godot-rts/DLLs/lib{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)
