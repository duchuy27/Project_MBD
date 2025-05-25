#include <systemc.h>
#include "XNOR_GATE.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> a, b, c;

    XNOR_GATE xnor1("XNOR1");
    xnor1.A(a);
    xnor1.B(b);
    xnor1.C(c);

    // tạo file vcd trace
    sc_trace_file *wf = sc_create_vcd_trace_file("xnor_wave");
    sc_trace(wf, a, "a");
    sc_trace(wf, b, "b");
    sc_trace(wf, c, "c");

    // mô phỏng tín hiệu
    a = 0; b = 0; sc_start(10, SC_NS);
    a = 0; b = 1; sc_start(10, SC_NS);
    a = 1; b = 0; sc_start(10, SC_NS);
    a = 1; b = 1; sc_start(10, SC_NS);

    sc_close_vcd_trace_file(wf);

    return 0;
}
