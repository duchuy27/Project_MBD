#ifndef NOT_GATE_H
#define NOT_GATE_H

#include <systemc.h>

SC_MODULE(NOT_GATE) {
    sc_in<bool> A;
    sc_out<bool> B;

    void do_not();

    SC_CTOR(NOT_GATE) {
        SC_METHOD(do_not);
        sensitive << A;
    }
};

#endif // NOT_GATE_H
