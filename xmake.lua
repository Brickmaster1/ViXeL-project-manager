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

add_requires("libui", "glfw", "rocket", "vcpkg::boost-hana", "glaze", "libgit2", "quickjs-ng", "quickjspp")

target("test")
    set_kind("binary")
    add_files("src/**.cpp")
    add_headerfiles("src/**.h")
    add_includedirs("src")
    add_packages("libui", "glfw", "rocket", "vcpkg::boost-hana", "glaze", "libgit2", "quickjs-ng", "quickjspp")
    add_cxxflags("-static", "-static-libgcc", "-static-libstdc++", {force = true})
    if is_plat("windows", "msys", "mingw") then
        add_files("resources/windows/res/resources.rc")
    end
target_end()
