#include "systemc.h"

SC_MODULE(test) 
{
    sc_in<bool> clock;
    sc_out< int > X_in, Y_in;
    sc_in< int > S_out;

    void do_test()
    {
        std::cout   << "time\tX\tY\tS" << std::endl;
        while(true) 
        {
          X_in = 1;
          Y_in = 2;
          print();
          wait(1);

          X_in = 2;
          Y_in = 2;
          print();
          wait(1);

          X_in = 7;
          Y_in = 5;
          print();
          wait(1);

          X_in = 3;
          Y_in = 2;
          print();
          wait(1);

          X_in = 4;
          Y_in = 1;
          print();
          wait(1);

          X_in = 8;
          Y_in = 2;
          print();
          wait(1);

	  X_in = 3;
          Y_in = 9;
          print();
          wait(1);

	  X_in = 0;
          Y_in = 0;
          print();
          wait(1);

	  X_in = 8;
          Y_in = 8;
          print();
          wait(1);

      }
    }



    void print()
    {
      std::cout   << sc_time_stamp() << "\t"
      << X_in << "\t"
      << Y_in << "\t"
      << S_out << "\t"
      << std::endl;
    }

    SC_CTOR(test) 
    {
        SC_CTHREAD(do_test,clock.neg());
    }
};
