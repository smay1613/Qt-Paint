#ifndef PACKAGETYPES_H
#define PACKAGETYPES_H
namespace networking {

enum PType
{
    INVALID,
    INTRODUCING_INFO_REQUEST, // gives info about client mode (slave/master)
    INTRODUCING_INFO_RESPONSE // result from server
};

}

#endif // PACKAGETYPES_H
