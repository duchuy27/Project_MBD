#ifndef SELECTOR4TO1_H
#define SELECTOR4TO1_H

#include <systemc.h>
#include "MUX2to1.h"
#include "NOT_GATE.h"

SC_MODULE(SELECTOR4to1) {
    // Inputs
    sc_in<bool> a, b, c, d;
    sc_in<bool> s0, s1;

    // Output
    sc_out<bool> y;

    // Internal signals
    sc_signal<bool> mux1_out, mux2_out;
    sc_signal<bool> not_s0, not_s1;

    // Submodules
    MUX2to1 *mux1, *mux2, *mux3;
    NOT_GATE *not1, *not2;

    SC_CTOR(SELECTOR4to1);
    ~SELECTOR4to1();
    
private:
    void connect_modules();
};

#endif
