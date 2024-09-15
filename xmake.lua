set_project("ViXeL-project-manager")
set_languages("c++20")

add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate")

if is_mode("debug") then
    set_symbols("debug")
    set_optimize("none")
end

if is_mode("release") then
    set_symbols("hidden")
    set_optimize("fastest")
    set_strip("all")
end

add_repositories("packages_local packages_local")

add_requires("vcpkg::libgit2")
add_requires("wxwidgets_mingw")

target("test")
    set_kind("binary")
    add_files("src/**.cpp")
    add_headerfiles("src/**.h")
    add_includedirs("src")
    add_packages("vcpkg::libgit2", "wxwidgets_mingw")
    --add_cxxflags("-static", "-static-libgcc", "-static-libstdc++", {force = true})
target_end()
