#include "NOT_GATE.h"

void NOT_GATE::do_not() {
    B.write(!A.read());
}
