funwithcpp_deps = [
    dependency('gtkmm-3.0', version: '>= 3.18'),
]

gnome = import('gnome')

funwithcpp_sources = [
    'main.cpp'
    ,'funwithcpp-window.cpp'
    ,'MainWindowToolbar.cpp'
    ,'test.cpp'
    ,'test_vector_copy.cpp'
]

funwithcpp_sources += gnome.compile_resources('funwithcpp-resources', 'funwithcpp.gresource.xml', c_name: 'funwithcpp')

cpp_arguments = [
    '-fsanitize-address-use-after-scope'
    ,'-fno-omit-frame-pointer'
    ,'-Wunused'
    ,'-DG_DISABLE_DEPRECATED'
    ,'-DGDK_DISABLE_DEPRECATED'
    ,'-DGDK_PIXBUF_DISABLE_DEPRECATED'
    ,'-DGTK_DISABLE_DEPRECATED'
]

executable('funwithcpp'
    ,funwithcpp_sources
    ,dependencies: funwithcpp_deps
    ,cpp_args: cpp_arguments
    ,install: true
)
