#include "SELECTOR4to1.h"

SELECTOR4to1::SELECTOR4to1(sc_module_name name) : sc_module(name) {
    // Instantiate modules
    mux1 = new MUX2to1("mux1");
    mux2 = new MUX2to1("mux2");
    mux3 = new MUX2to1("mux3");

    not1 = new NOT_GATE("not1");
    not2 = new NOT_GATE("not2");

    connect_modules();
}

SELECTOR4to1::~SELECTOR4to1() {
    delete mux1;
    delete mux2;
    delete mux3;
    delete not1;
    delete not2;
}

void SELECTOR4to1::connect_modules() {
        // Wiring first level muxes
        mux1->A(a); mux1->B(b); mux1->sel(s0); mux1->OUT(mux1_out);
        mux2->A(c); mux2->B(d); mux2->sel(s0); mux2->OUT(mux2_out);
    
        // Second level mux
        mux3->A(mux1_out); mux3->B(mux2_out); mux3->sel(s1); mux3->OUT(y);
    
}