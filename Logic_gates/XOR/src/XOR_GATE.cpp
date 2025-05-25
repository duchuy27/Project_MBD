#include "XOR_GATE.h"

void XOR_GATE::do_xor() {
    C.write(A.read() ^ B.read());
}
