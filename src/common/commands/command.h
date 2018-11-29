#ifndef COMMAND_H
#define COMMAND_H

class ICommand
{
public:
    ICommand() = default;
    virtual ~ICommand() = default;

    virtual void execute() = 0;
};

#endif // COMMAND_H
