#include "XNOR_GATE.h"

void XNOR_GATE::do_xnor() {
    C.write(!(A.read() ^ B.read()));
}
