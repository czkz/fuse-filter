libkcapi = static_library('kcapi',
  'kcapi-kernel-if.c',
  'kcapi-sym.c',
  'kcapi-utils.c',
  c_args : ['-DKCAPI_MAJVERSION=1', '-DKCAPI_MINVERSION=4', '-DKCAPI_PATCHLEVEL=0'],
  # link_args : ['--version-script,version.lds'],
  install : true)

libkcapi_dep = declare_dependency(
  include_directories : '.',
  link_with : libkcapi
)
