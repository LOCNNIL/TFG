#ifndef CRYPTO_STATES_H
#define CRYPTO_STATES_H


namespace crypto::protocol{

enum class State{
    send_any_packet=1,
    encrypt_packet,
    decrypt_packet,
    wait_for_request,
    check_request_id,
    ask_for_new_id,
    generate_sum_chalenge,
    check_sum_chalenge,
    check_sum_chalenge_id,
};

}



#endif