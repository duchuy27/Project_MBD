#include <systemc.h>
#include "SELECTOR4to1.h"

int sc_main(int argc, char* argv[]) {
    sc_signal<bool> a, b, c, d, s0, s1, y;

    SELECTOR4to1 sel("selector");
    sel.a(a); sel.b(b); sel.c(c); sel.d(d);
    sel.s0(s0); sel.s1(s1); sel.y(y);

    // Test
    sc_start(1, SC_NS); a = 0; b = 1; c = 1; d = 0; s0 = 0; s1 = 0;
    sc_start(1, SC_NS); std::cout << "Y=" << y.read() << std::endl;

    s0 = 1; sc_start(1, SC_NS); std::cout << "Y=" << y.read() << std::endl;
    s0 = 0; s1 = 1; sc_start(1, SC_NS); std::cout << "Y=" << y.read() << std::endl;
    s0 = 1; sc_start(1, SC_NS); std::cout << "Y=" << y.read() << std::endl;

    return 0;
}
