#ifndef CRYPTO_PROTOCOL_H
#define CRYPTO_PROTOCOL_H

#include "states.h"

namespace crypto::protocol
{

class Protocol
{
private:
    crypto::states::State m_state;
public:
    Protocol(){};
    ~Protocol(){};
    void set_state(crypto::states::State st);
    void state_machine();
};



} // namespace 


#endif