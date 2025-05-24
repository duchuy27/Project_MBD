#include <systemc.h>

SC_MODULE(AND_GATE) {
    sc_in<bool> A, B;
    sc_out<bool> C;

    void do_and() {
        C.write(A.read() & B.read());
    }

    SC_CTOR(AND_GATE) {
        SC_METHOD(do_and);
        sensitive << A << B;
    }
};
