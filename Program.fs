// -----------------------------------------------------------------------------
// load the Averest dll from nuget.org and open some modules
// -----------------------------------------------------------------------------
// see https://es.cs.uni-kl.de/tools/Averest/AverestLibDoc/reference
// for a documentation of the library functions
// -----------------------------------------------------------------------------
#if INTERACTIVE
#r "nuget: Averest, 3.0.1";; 
#endif

module Program
open Translator.Main


//let mncs = "nat a,b,c; 
//thread t1{ 
//    b = a * 2;
//    c = a + b; 
//}"


let mncs = "bool m_0_0,m_0_1,m_1_0,m_1_1;
 bool t_0_0,t_0_1,t_1_0,t_1_1;
 thread TransHull {
    bool t_1,t_2,t_3,t_4;
    t_1 = m_0_0;
    t_2 = m_0_1;
    t_3 = m_1_0;
    t_4 = m_1_1;
    t_1 = t_1 | t_1 & t_1;
    t_2 = t_2 | t_1 & t_2;
    t_3 = t_3 | t_3 & t_1;
    t_4 = t_4 | t_3 & t_2;
    t_1 = t_1 | t_2 & t_3;
    t_2 = t_2 | t_2 & t_4;
    t_3 = t_3 | t_4 & t_3;
    t_4 = t_4 | t_4 & t_4;
    t_0_0 = t_1;
    t_0_1 = t_2;
    t_1_0 = t_3;
    t_1_1 = t_4;
}"


WriteCLCode mncs 

    

