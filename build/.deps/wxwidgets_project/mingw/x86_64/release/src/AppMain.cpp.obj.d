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
            "-std=c++17",
            "-isystem",
            "/home/brickmaster/vcpkg/installed/x64-mingw-static/include"
        }
    }
}