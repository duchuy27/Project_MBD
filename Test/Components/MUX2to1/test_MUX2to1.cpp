#include <systemc.h>
#include "MUX2to1.h"

SC_MODULE(Testbench) {
    sc_signal<bool> A, B, sel;
    sc_signal<bool> OUT;

    MUX2to1 mux;

    SC_CTOR(Testbench) : mux("mux") {
        // Kết nối tín hiệu với module mux
        mux.A(A);
        mux.B(B);
        mux.sel(sel);
        mux.OUT(OUT);

        SC_THREAD(test_process);
    }

    void test_process() {
        // Test các trường hợp
        A = 0; B = 0; sel = 0;
        wait(10, SC_NS);
        print_signals();

        A = 0; B = 1; sel = 0;
        wait(10, SC_NS);
        print_signals();

        A = 1; B = 0; sel = 0;
        wait(10, SC_NS);
        print_signals();

        A = 1; B = 1; sel = 0;
        wait(10, SC_NS);
        print_signals();

        A = 0; B = 0; sel = 1;
        wait(10, SC_NS);
        print_signals();

        A = 0; B = 1; sel = 1;
        wait(10, SC_NS);
        print_signals();

        A = 1; B = 0; sel = 1;
        wait(10, SC_NS);
        print_signals();

        A = 1; B = 1; sel = 1;
        wait(10, SC_NS);
        print_signals();

        sc_stop();  // Kết thúc mô phỏng
    }

    void print_signals() {
        cout << sc_time_stamp() << " | "
             << "A=" << A.read() << " "
             << "B=" << B.read() << " "
             << "sel=" << sel.read() << " "
             << "OUT=" << OUT.read() << endl;
    }
};

int sc_main(int argc, char* argv[]) {
    Testbench tb("tb");

    sc_start();  // Chạy mô phỏng cho đến khi sc_stop() được gọi
    return 0;
}
