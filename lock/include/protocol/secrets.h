#ifndef CRYPTO_SECRETS
#define CRYPTO_SECRETS

#include <stdint.h>

namespace crypto::protocol // TODO: Complete this class
{
    class secrets
    {
    private:
        uint32_t standard_private_key[34];
    public:
        secrets(/* args */);
        ~secrets();
    };
    
    secrets::secrets(/* args */)
    {
    }
    
    secrets::~secrets()
    {
    }
    
} // namespace crypto::protocol


#endif
