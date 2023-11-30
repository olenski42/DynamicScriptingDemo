#include <iostream>
#include "ScriptBase.hpp"
#include <chrono>

class MyScript : public ScriptBase
{
public:
    MyScript()
    {
        m_startTime = std::chrono::steady_clock::now();
    }

    ~MyScript() = default;

    void OnUpdate() override
    {
        std::cout << "from \'MyScript::OnUpdate()\': " << std::endl;
        std::cout << "  time since creation: " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - m_startTime).count() << " s" << std::endl;
    }

private:
    std::chrono::time_point<std::chrono::steady_clock> m_startTime;
};

extern "C" ScriptBase *scriptFactory()
{
    return new MyScript();
}
