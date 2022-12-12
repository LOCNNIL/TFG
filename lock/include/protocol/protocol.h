#ifndef CRYPTO_PROTOCOL_H
#define CRYPTO_PROTOCOL_H

#include "states.h"

namespace crypto::protocol
{
    inline constexpr int standard_msg_size = 22;
    inline constexpr int keybits = 128;

class Protocol
{
private:
    crypto::protocol::State m_state;
public:
    Protocol(){};
    ~Protocol(){};
    void set_state(crypto::protocol::State st);
    void state_machine();
};



} // namespace 


#endif