#include <systemc.h>

SC_MODULE(intAdder) 
{
    sc_in< int > A;
    sc_in< int > B;
    sc_out< int > S;
    
    void doit(void)
    {
      int tmp_A, tmp_B, tmp_S;

      tmp_A=(int)A.read();
      tmp_B=(int)B.read();

      tmp_S=tmp_A + tmp_B;

      S.write((int)tmp_S);
   }
    
    SC_CTOR(intAdder) 
    {
        SC_METHOD(doit);
        sensitive << A;
        sensitive << B;
    }
};
