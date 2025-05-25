#ifndef XOR_GATE_H
#define XOR_GATE_H

#include <systemc.h>

SC_MODULE(XOR_GATE) {
    sc_in<bool> A, B;
    sc_out<bool> C;

    void do_xor();

    SC_CTOR(XOR_GATE) {
        SC_METHOD(do_xor);
        sensitive << A << B;
    }
};

#endif // XOR_GATE_H
