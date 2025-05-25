#ifndef OR_GATE_H
#define OR_GATE_H

#include <systemc.h>

SC_MODULE(OR_GATE) {
    sc_in<bool> A, B;
    sc_out<bool> C;

    void do_or();

    SC_CTOR(OR_GATE) {
        SC_METHOD(do_or);
        sensitive << A << B;
    }
};

#endif // OR_GATE_H
