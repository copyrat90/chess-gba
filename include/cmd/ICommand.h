#pragma once

namespace chs::cmd
{

class ICommand
{
public:
    virtual ~ICommand() = default;

    virtual void execute() = 0;
    virtual void undo() = 0;
};

} // namespace chs::cmd
