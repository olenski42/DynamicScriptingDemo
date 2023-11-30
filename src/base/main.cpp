#include <iostream>
#include <dlfcn.h>
#include "ScriptBase.hpp"

using scriptFactory = ScriptBase *(*)();

class ScriptLoader
{
public:
    ScriptLoader(const char *path)
        : m_path(path)
    {
        load();
    }

    ~ScriptLoader()
    {
        unload();
    }

    void reload()
    {
        unload();
        load();
    }

    void set_path(const char* path)
    {
        m_path = path;
    }

    ScriptBase *script = nullptr;

private:
    void load()
    {
        handle = dlopen(m_path, RTLD_NOW);
        if (handle == NULL)
        {
            std::cout << "[ERROR]: unable to load library \"" << m_path << "\"." << std::endl;
            exit(1);
        }

        const char *symbolName = "scriptFactory";
        scriptFactory factory = (scriptFactory)dlsym(handle, symbolName);
        const char *dlsym_error = dlerror();
        if (dlsym_error)
        {
            std::cout << "[ERROR]: unable to load symbol (function) \"" << symbolName << "\": " << dlsym_error << '\n';
            dlclose(handle);
            exit(1);
        }

        script = factory();
    }

    void unload()
    {
        if (script)
        {
            delete script;
        }

        if (handle != NULL)
        {
            dlclose(handle);
        }
    }

    const char *m_path;
    void *handle;
};

void print_help()
{
    std::cout << "commands:\n";
    std::cout << "  q - quit\n";
    std::cout << "  r - reload script\n";
    std::cout << "  a - call script's OnUpdate()\n";
    std::cout << "  h - help\n";
}

int main()
{
    ScriptLoader scriptLoader(LIB_PATH "libMyScript.so");

    print_help();

    bool isRunning = true;
    while (isRunning)
    {
        std::cout << ">> ";

        char c;
        std::cin >> c;

        if (c == 'q')
        {
            isRunning = false;
        }

        else if (c == 'r')
        {
            scriptLoader.reload();
            std::cout << "script reloaded" << std::endl;
        }

        else if (c == 'a')
        {
            scriptLoader.script->OnUpdate();
        }

        else if (c == 'h')
        {
            print_help();
        }

        else
        {
            std::cout << "unknown command: \'" << c << "\'" << std::endl;
        }
    }

    return 0;
}
