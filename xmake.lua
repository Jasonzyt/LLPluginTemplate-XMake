target("MyPlugin")
    set_plat("windows")
    set_arch("x64")
    set_toolchains("msvc")
    set_rules("mode.release")

    set_kind("shared")
    add_files("src/*.cpp")
    add_files("src/*.rc")
    add_headerfiles("include/*.h")
    add_headerfiles("include/*.hpp")
    add_includedirs("SDK/include")
    add_includedirs("include")
    add_defines(
        "UNICODE",
        "_UNICODE",
        "NDEBUG",
        "WIN32_LEAN_AND_MEAN",
        "_CRT_SECURE_NO_WARNINGS",
        "_WINDOWS",
        "_USRDLL",
        "_AMD64_",
        "NOMINMAX"
    )
    set_warnings("all")
    set_optimize("fastest")
    set_runtimes("MD")
    set_languages("c17", "cxx20")
    add_linkdirs(
        "SDK/lib"
    )
    add_links(
        "LiteLoader",
        "SymDBHelper",
        "bedrock_server_api",
        "bedrock_server_var",
        "delayimp"
    )
    add_cxflags(
        "/utf-8",
        "/EHsc",
        "/GL",
        "/permissive-",
        "/sdl",
        "/Zc:inline",
        "/Zi",
        "/FS"
    )
    add_shflags(
        "/DELAYLOAD:bedrock_server.dll",
        "/DEBUG",
        "/SUBSYSTEM:CONSOLE"
    )
    on_load(function (target)
        if (not os.exists("SDK/lib/bedrock_server_api.lib") or not os.exists("SDK/lib/bedrock_server_var.lib")) then
            os.cd("SDK/tools")
            os.exec("./PeEditor.exe -c -l -o ../lib")
        end
    end)
    after_build(function (target)
        local plugin_header_file = "include/myplugin/Resource.h"
        local basename = target:basename()
        local filename = target:filename()
        import("lib.detect.find_tool")
        local cl = find_tool("cl.exe")
        if cl then
            io.writefile("preprocess.cpp", "#include \"" .. plugin_header_file .. "\"\nPLUGIN_VERSION_STRING")
            os.run('"' .. cl.program .. "\" /P /EP preprocess.cpp")
            local text = io.readfile("./preprocess.i")
            os.rm("./preprocess.*")
            local startIndex = -1
            local endIndex = -1
            for i=#text,1,-1 do 
                local ch = string.sub(text, i, i)
                if ch == '"' then
                    if endIndex == -1 then
                        endIndex = i
                    else 
                        startIndex = i
                        break
                    end
                end
            end
            local version = string.sub(text, startIndex + 1, endIndex - 1)
            filename = basename .. "-v" .. version .. ".dll"
        end
        os.cp(target:targetfile(), "./release/" .. filename)
        os.cp(target:targetdir() .. '/' .. basename .. ".pdb", "./release/")
    end)