import os

# Import environment from godot-cpp build
env = SConscript(os.path.join('godot-cpp', 'SConstruct'))

# Include directories
env.Append(
    CPPPATH=[
        os.path.join('godot-cpp', 'include'),
        os.path.join('godot-cpp', 'include', 'godot_cpp'),
        'include',
    ],
    LIBPATH=[os.path.join('godot-cpp', 'bin')],
)

# Source files
sources = Glob(os.path.join('src', '*.cpp'))

# Build Windows DLL
lib = env.SharedLibrary(
    'bin/libHarvestGodotCpp{}{}'.format(env['suffix'], env['SHLIBSUFFIX']),
    source=sources,
)

env.NoCache(lib)
Default(lib)
