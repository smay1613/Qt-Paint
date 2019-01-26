#ifndef PACKAGETYPES_H
#define PACKAGETYPES_H
namespace networking {

enum PType
{
    INVALID,
    INTRODUCING_INFO_REQUEST, // gives info about client mode (slave/master)
    INTRODUCING_INFO_RESPONSE,

    ACTIVE_COMMAND,

    HISTORY_HASH_UPDATE, // changes in history
    COMMAND_HASHES_REQUEST,
    COMMAND_HASHES_RESPONSE,

    COMMANDS_REQUEST
};

}

#endif // PACKAGETYPES_H
