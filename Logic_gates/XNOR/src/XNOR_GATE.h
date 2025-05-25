#ifndef XNOR_GATE_H
#define XNOR_GATE_H

#include <systemc.h>

SC_MODULE(XNOR_GATE) {
    sc_in<bool> A, B;
    sc_out<bool> C;

    void do_xnor();

    SC_CTOR(XNOR_GATE) {
        SC_METHOD(do_xnor);
        sensitive << A << B;
    }
};

#endif // XNOR_GATE_H
