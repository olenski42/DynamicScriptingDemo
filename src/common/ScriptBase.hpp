#pragma once

class ScriptBase
{
public:
  ScriptBase() = default;
  virtual ~ScriptBase() = default;
  virtual void OnUpdate() = 0;
};
