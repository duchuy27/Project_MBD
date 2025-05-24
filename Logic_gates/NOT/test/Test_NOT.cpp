#include <systemc.h>
#include "NOT_GATE.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> a, b;

    NOT_GATE not1("NOT1");
    not1.A(a);
    not1.B(b);

    // tạo file vcd trace
    sc_trace_file *wf = sc_create_vcd_trace_file("not_wave");
    sc_trace(wf, a, "a");
    sc_trace(wf, b, "b");

    // mô phỏng tín hiệu
    a = 0; sc_start(10, SC_NS);
    a = 1; sc_start(10, SC_NS);

    sc_close_vcd_trace_file(wf);

    return 0;
}
