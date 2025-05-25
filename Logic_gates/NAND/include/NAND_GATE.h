#ifndef NAND_GATE_H
#define NAND_GATE_H

#include <systemc.h>

SC_MODULE(NAND_GATE) {
    sc_in<bool> A, B;
    sc_out<bool> C;

    void do_nand();

    SC_CTOR(NAND_GATE) {
        SC_METHOD(do_nand);
        sensitive << A << B;
    }
};

#endif // NAND_GATE_H
