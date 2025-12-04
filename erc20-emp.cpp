#include <emp-tool/emp-tool.h>
#include <fstream>
using namespace emp;

/*
    Computes: if (bal >= amt) new_bal = bal - amt else new_bal = bal

    Solidity: 256-bit unsigned integers
*/

Integer erc20_transfer(const Integer &bal, const Integer &amt) {
    Bit ok = bal >= amt;           // 256-bit comparator → many AND gates
    Integer masked_amt = amt & ok; // if ok=1 subtract amt, else subtract 0
    return bal - masked_amt;       // ripple-carry subtraction
}

int main() {
    // Switch EMP into "circuit output" mode
    auto circ = new BristolFormat("");
    CircuitExecution::circ_exec = circ;
    ProtocolExecution::prot_exec = new ProtocolExecution();

    // Build 256-bit circuit
    Integer bal(256, 0, PUBLIC);
    Integer amt(256, 0, PUBLIC);
    Integer new_bal = erc20_transfer(bal, amt);

    // Write circuit to file
    std::ofstream out("erc20_transfer.bristol");
    circ->print(out);
    out.close();

    return 0;
}
