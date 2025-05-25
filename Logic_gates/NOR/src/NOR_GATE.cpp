#include "NOR_GATE.h"

void NOR_GATE::do_nor() {
    C.write(!(A.read() || B.read()));
}
