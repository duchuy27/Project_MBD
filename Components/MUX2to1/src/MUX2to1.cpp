#include "MUX2to1.h"

MUX2to1::MUX2to1(sc_core::sc_module_name name)
    : sc_module(name),  // gọi constructor lớp cha
      not_gate("not_gate"),
      and1("and1"), and2("and2"),
      or_gate("or_gate")
{
    connect_modules();
}

void MUX2to1::connect_modules() {
    // Connect NOT sel
    not_gate.A(sel);
    not_gate.B(not_sel);

    // A AND NOT(sel)
    and1.A(A);
    and1.B(not_sel);
    and1.C(and1_out);

    // B AND sel
    and2.A(B);
    and2.B(sel);
    and2.C(and2_out);

    // OR the two ANDs
    or_gate.A(and1_out);
    or_gate.B(and2_out);
    or_gate.C(OUT);
}
