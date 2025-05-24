#include "AND_GATE.h"

void AND_GATE::do_and() {
    C.write(A.read() && B.read());
}
