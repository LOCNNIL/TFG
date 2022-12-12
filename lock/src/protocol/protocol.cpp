#include "protocol.h"

namespace crypto::protocol{
    void Protocol::state_machine(){
        switch (m_state)
        {
        case crypto::protocol::State::send_any_packet:
            /* code */
            break;
        case crypto::protocol::State::encrypt_packet:
            /* code */
            break;
        case crypto::protocol::State::decrypt_packet:
            /* code */
            break;
        case crypto::protocol::State::wait_for_request:
            /* code */
            break;
        case crypto::protocol::State::check_request_id:
            /* code */
            break;
        case crypto::protocol::State::ask_for_new_id:
            /* code */
            break;
        case crypto::protocol::State::generate_sum_chalenge:
            /* code */
            break;
        case crypto::protocol::State::check_sum_chalenge:
            /* code */
            break;
        case crypto::protocol::State::check_sum_chalenge_id:
            /* code */
            break;
            
        default:
            break;
        }
    }
}



