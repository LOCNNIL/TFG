#ifndef CRYPTO_STATE_MACHINE_H
#define CRYPTO_STATE_MACHINE_H

namespace crypto::state_machine
{
    enum class states{
        init_lock=1,
        wait_signal=2,
    };
    
} // namespace crypto::state_machine



#endif