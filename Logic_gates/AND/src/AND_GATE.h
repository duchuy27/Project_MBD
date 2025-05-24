#ifndef AND_GATE_H
#define AND_GATE_H

#include <systemc.h>

SC_MODULE(AND_GATE) {
    sc_in<bool> A, B;
    sc_out<bool> C;

    void do_and();

    SC_CTOR(AND_GATE) {
        SC_METHOD(do_and);
        sensitive << A << B;
    }
};

#endif // AND_GATE_H
