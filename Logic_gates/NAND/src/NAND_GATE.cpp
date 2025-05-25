#include "NAND_GATE.h"

void NAND_GATE::do_nand() {
    C.write(!(A.read() && B.read()));
}
