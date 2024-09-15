{
    files = {
        "src/AppMain.cpp"
    },
    depfiles_gcc = "AppMain.o: src/AppMain.cpp src/AppMain.h\
",
    values = {
        "/usr/bin/x86_64-w64-mingw32-g++",
        {
            "-m64",
            "-fvisibility=hidden",
            "-fvisibility-inlines-hidden",
            "-O3",
            "-std=c++2a",
            "-Isrc",
            "-DWXUSINGDLL",
            "-D__WXMSW__",
            "-DwxSUFFIX=ud",
            "-isystem",
            "/home/brickmaster/vcpkg/installed/x64-mingw-static/lib/pkgconfig/../../include",
            "-isystem",
            "/home/brickmaster/.xmake/packages/w/wxwidgets_mingw/3.2.0/468c4daf874a437695964636e29cd93f/include",
            "-DNDEBUG"
        }
    }
}