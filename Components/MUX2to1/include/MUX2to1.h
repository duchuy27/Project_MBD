#ifndef MUX2TO1_H
#define MUX2TO1_H

#include <systemc.h>
#include "AND_GATE.h"
#include "OR_GATE.h"
#include "NOT_GATE.h"

SC_MODULE(MUX2to1) {
    sc_in<bool> A, B, sel;
    sc_out<bool> OUT;

    // Internal signals
    sc_signal<bool> not_sel, and1_out, and2_out;

    // Sub-modules
    NOT_GATE not_gate;
    AND_GATE and1, and2;
    OR_GATE or_gate;

    // Constructor declaration only
    SC_CTOR(MUX2to1);

private:
    void connect_modules();
};

#endif // MUX2TO1_H
