#include "OR_GATE.h"

void OR_GATE::do_or() {
    C.write(A.read() || B.read());
}
