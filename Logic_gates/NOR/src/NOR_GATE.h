#ifndef NOR_GATE_H
#define NOR_GATE_H

#include <systemc.h>

SC_MODULE(NOR_GATE) {
    sc_in<bool> A, B;
    sc_out<bool> C;

    void do_nor();

    SC_CTOR(NOR_GATE) {
        SC_METHOD(do_nor);
        sensitive << A << B;
    }
};

#endif // NOR_GATE_H
