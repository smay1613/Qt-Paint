#ifndef COMMAND_H
#define COMMAND_H

class ICommand
{
public:
    ICommand();
    virtual ~ICommand();

    virtual void execute() = 0;
};

#endif // COMMAND_H
