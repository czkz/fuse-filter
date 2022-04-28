project('fuse-filter', 'cpp',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'cpp_args=-Wno-c99-extensions -Wno-pedantic',
    'wrap_mode=forcefallback',
  ],
)

libfuse_dep = dependency('fuse3', fallback : ['libfuse', 'libfuse_dep'])
libkcapi_dep = dependency('libkcapi', fallback : ['libkcapi', 'libkcapi_dep'])

executable('fuse-filter',
           'passthrough_hp.cc',
           dependencies : [ libfuse_dep, libkcapi_dep ],
           install : true)
