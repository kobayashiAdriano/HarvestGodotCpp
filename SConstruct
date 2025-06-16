import os

env = SConscript(os.path.join('godot-cpp', 'SConstruct'))

env.Append(CPPPATH=['include'])

sources = ['register_types.cpp'] + Glob('src/*.cpp')

if env['platform'] == 'macos':
    lib = env.SharedLibrary(
        'bin/libHarvestGodotCpp.{}.{}.framework/libHarvestGodotCpp.{}.{}'.format(
            env['platform'], env['target'], env['platform'], env['target']
        ),
        source=sources,
    )
elif env['platform'] == 'ios':
    if env['ios_simulator']:
        lib = env.StaticLibrary(
            'bin/libHarvestGodotCpp.{}.{}.simulator{}'.format(
                env['platform'], env['target'], env['LIBSUFFIX']
            ),
            source=sources,
        )
    else:
        lib = env.StaticLibrary(
            'bin/libHarvestGodotCpp.{}.{}{}'.format(
                env['platform'], env['target'], env['LIBSUFFIX']
            ),
            source=sources,
        )
else:
    lib = env.SharedLibrary(
        'bin/libHarvestGodotCpp{}{}'.format(env['suffix'], env['SHLIBSUFFIX']),
        source=sources,
    )

env.NoCache(lib)
Default(lib)
