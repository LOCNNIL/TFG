#include "protocol.h"

namespace crypto::protocol{
    void Protocol::state_machine(){
        switch (m_state)
        {
        case crypto::states::State::send_any_packet:
            /* code */
            break;
        case crypto::states::State::encrypt_packet:
            /* code */
            break;
        case crypto::states::State::decrypt_packet:
            /* code */
            break;
        case crypto::states::State::wait_for_request:
            /* code */
            break;
        case crypto::states::State::check_request_id:
            /* code */
            break;
        case crypto::states::State::ask_for_new_id:
            /* code */
            break;
        case crypto::states::State::generate_sum_chalenge:
            /* code */
            break;
        case crypto::states::State::check_sum_chalenge:
            /* code */
            break;
        case crypto::states::State::check_sum_chalenge_id:
            /* code */
            break;
            
        default:
            break;
        }
    }
}



