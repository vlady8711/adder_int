#include "systemc.h"
#include "intAdder.h"
#include "test.h"

int sc_main(int argc, char* argv[]) {
    sc_signal< int > X, Y;
    sc_signal< int > S;

    sc_clock CLK("clock", 10, SC_NS);

    intAdder FA("FA");
    FA(X, Y, S);

    test TEST("TEST");
    TEST(CLK, X, Y, S);

    sc_trace_file *tf = sc_create_vcd_trace_file("wave");
    sc_trace(tf, CLK, "clock");
    sc_trace(tf, X, "X");
    sc_trace(tf, Y, "Y");
    sc_trace(tf, S, "S");

    sc_start(100, SC_NS);
    sc_close_vcd_trace_file(tf);
    return(0);
}
