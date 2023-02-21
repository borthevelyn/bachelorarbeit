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

let mncs1 = "nat a,b,c; 
thread t1{ 
    b = a * 2;
    c = a + b; 
}"
let mncs2 = "bool m_0_0,m_0_1,m_1_0,m_1_1;
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
// BitonicSort 4
let mncs3 = "
nat x_0_0,x_1_0,x_2_0,x_3_0;
nat x_0_3,x_1_3,x_2_3,x_3_3;
thread BitonicSort_4 {
    bool c_0_1_0,c_0_1_2,c_0_3_1,c_1_2_1,c_2_3_0,c_3_2_2;
nat x_0_1,x_1_1,x_2_1,x_3_1;
nat x_0_2,x_1_2,x_2_2,x_3_2;
    c_0_1_0 = x_0_0<x_1_0;
    x_0_1 = (c_0_1_0?x_0_0:x_1_0);
    x_1_1 = (c_0_1_0?x_1_0:x_0_0);
    c_2_3_0 = x_2_0<x_3_0;
    x_2_1 = (c_2_3_0?x_2_0:x_3_0);
    x_3_1 = (c_2_3_0?x_3_0:x_2_0);
    c_0_3_1 = x_0_1<x_3_1;
    x_0_2 = (c_0_3_1?x_0_1:x_3_1);
    x_3_2 = (c_0_3_1?x_3_1:x_0_1);
    c_1_2_1 = x_1_1<x_2_1;
    x_1_2 = (c_1_2_1?x_1_1:x_2_1);
    x_2_2 = (c_1_2_1?x_2_1:x_1_1);
    c_0_1_2 = x_0_2<x_1_2;
    x_0_3 = (c_0_1_2?x_0_2:x_1_2);
    x_1_3 = (c_0_1_2?x_1_2:x_0_2);
    c_3_2_2 = x_3_2<x_2_2;
    x_3_3 = (c_3_2_2?x_3_2:x_2_2);
    x_2_3 = (c_3_2_2?x_2_2:x_3_2);
}
"
// BinaryTree Arr_16
let mncs4 = "
[16]nat x;
nat z;

thread BinaryTree_16 {
    nat y0,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12,y13,y14,y15;
    y0 = x[0];
    y1 = x[1];
    y2 = x[2];
    y3 = x[3];
    y4 = x[4];
    y5 = x[5];
    y6 = x[6];
    y7 = x[7];
    y8 = x[8];
    y9 = x[9];
    y10 = x[10];
    y11 = x[11];
    y12 = x[12];
    y13 = x[13];
    y14 = x[14];
    y15 = x[15];
    // level 0
    y0 = y0 + y1;
    y1 = y2 + y3;
    y2 = y4 + y5;
    y3 = y6 + y7;
    y4 = y8 + y9;
    y5 = y10 + y11;
    y6 = y12 + y13;
    y7 = y14 + y15;
    // level 0
    y0 = y0 + y1;
    y1 = y2 + y3;
    y2 = y4 + y5;
    y3 = y6 + y7;
    // level 0
    y0 = y0 + y1;
    y1 = y2 + y3;
    // level 0
    y0 = y0 + y1;
    z = y0;
}
"
// geht nicht
let mncs5 = "
int p0,p1,p2,p3,p4;
int x,y;
thread EvalPolynomial {
    int t0,t1,t2,t3,t4;
    t0 = +1;
    t1 = x;
    t2 = x;
    t3 = x;
    t4 = x;
    // up-level 0
    t1 = t0 * t1;
    t3 = t2 * t3;
    // up-level 1
    t3 = t1 * t3;
    // up-level 2
    // down-level 3
    // down-level 4
    t2 = t1 * t2;
    t4 = t3 * t4;
    // multiply p[i] with x^i
    t0 = p0 * t0;
    t1 = p1 * t1;
    t2 = p2 * t2;
    t3 = p3 * t3;
    t4 = p4 * t4;
    // sum up p[i]*x^i by a binary tree
    // level 0
    t0 = t0 + t1;
    t1 = t2 + t3;
    t2 = t4;
    // level 0
    t0 = t0 + t1;
    t1 = t2;
    // level 0
    t0 = t0 + t1;
    // final result
    y = t0;
    }
"
 // FastFourierTransform ArrGlb_8
let mncs6 = "
[8]int w;
[8]int x;
[8]int y;
thread FastFourierTransform {
    int t_1,t_2,t_3,t_4,t_5,t_6,t_7,t_8,t_9,t_10,t_11,t_12,t_13,t_14,t_15,t_16,t_17,t_18,t_19,t_20,t_21,t_22,t_23,t_24;
    t_1 = x[0] + x[4];
    t_2 = x[1] + x[5];
    t_3 = x[2] + x[6];
    t_4 = x[3] + x[7];
    t_5 = x[0] - x[4];
    t_6 = w[1] * (x[1] - x[5]);
    t_7 = w[2] * (x[2] - x[6]);
    t_8 = w[3] * (x[3] - x[7]);
    t_9 = t_1 + t_3;
    t_10 = t_2 + t_4;
    t_11 = t_1 - t_3;
    t_12 = w[2] * (t_2 - t_4);
    t_13 = t_9 + t_10;
    t_14 = t_9 - t_10;
    t_15 = t_11 + t_12;
    t_16 = t_11 - t_12;
    t_17 = t_5 + t_7;
    t_18 = t_6 + t_8;
    t_19 = t_5 - t_7;
    t_20 = w[2] * (t_6 - t_8);
    t_21 = t_17 + t_18;
    t_22 = t_17 - t_18;
    t_23 = t_19 + t_20;
    t_24 = t_19 - t_20;
    y[0] = t_13;
    y[1] = t_21;
    y[2] = t_15;
    y[3] = t_23;
    y[4] = t_14;
    y[5] = t_22;
    y[6] = t_16;
    y[7] = t_24;
}

"
 //FastFourierTransform SclGlb_8
let mncs7 = "
int w_0,w_1,w_2,w_3,w_4,w_5,w_6,w_7;
int x_0,x_1,x_2,x_3,x_4,x_5,x_6,x_7;
int y_0,y_1,y_2,y_3,y_4,y_5,y_6,y_7;
thread FastFourierTransform {
    int t_1,t_2,t_3,t_4,t_5,t_6,t_7,t_8,t_9,t_10,t_11,t_12,t_13,t_14,t_15,t_16,t_17,t_18,t_19,t_20,t_21,t_22,t_23,t_24;
    t_1 = x_0 + x_4;
    t_2 = x_1 + x_5;
    t_3 = x_2 + x_6;
    t_4 = x_3 + x_7;
    t_5 = x_0 - x_4;
    t_6 = w_1 * (x_1 - x_5);
    t_7 = w_2 * (x_2 - x_6);
    t_8 = w_3 * (x_3 - x_7);
    t_9 = t_1 + t_3;
    t_10 = t_2 + t_4;
    t_11 = t_1 - t_3;
    t_12 = w_2 * (t_2 - t_4);
    t_13 = t_9 + t_10;
    t_14 = t_9 - t_10;
    t_15 = t_11 + t_12;
    t_16 = t_11 - t_12;
    t_17 = t_5 + t_7;
    t_18 = t_6 + t_8;
    t_19 = t_5 - t_7;
    t_20 = w_2 * (t_6 - t_8);
    t_21 = t_17 + t_18;
    t_22 = t_17 - t_18;
    t_23 = t_19 + t_20;
    t_24 = t_19 - t_20;
    y_0 = t_13;
    y_1 = t_21;
    y_2 = t_15;
    y_3 = t_23;
    y_4 = t_14;
    y_5 = t_22;
    y_6 = t_16;
    y_7 = t_24;
}
"
 // ToDo Implement store, geht nicht
let mncs8 = "
[2][2]nat a;
[2][2]nat b;
[2][2]nat c;
thread MatrixMultCannon {
    b[0][0] = b[1][0];
    a[0][0] = a[0][1];
    c[0][0] = c[0][0] + a[0][0] * b[0][0];
    b[0][0] = b[1][0];
    a[0][0] = a[0][1];
    c[0][0] = c[0][0] + a[0][0] * b[0][0];
    b[0][1] = b[1][1];
    a[0][1] = a[0][0];
    c[0][1] = c[0][1] + a[0][1] * b[0][1];
    b[0][1] = b[1][1];
    a[0][1] = a[0][0];
    c[0][1] = c[0][1] + a[0][1] * b[0][1];
    b[1][0] = b[0][0];
    a[1][0] = a[1][1];
    c[1][0] = c[1][0] + a[1][0] * b[1][0];
    b[1][0] = b[0][0];
    a[1][0] = a[1][1];
    c[1][0] = c[1][0] + a[1][0] * b[1][0];
    b[1][1] = b[0][1];
    a[1][1] = a[1][0];
    c[1][1] = c[1][1] + a[1][1] * b[1][1];
    b[1][1] = b[0][1];
    a[1][1] = a[1][0];
    c[1][1] = c[1][1] + a[1][1] * b[1][1];
    c[0][0] = c[0][0];
    c[0][1] = c[0][1];
    c[1][0] = c[1][0];
    c[1][1] = c[1][1];
}
"
//RadixBAddCarryLookahead4
let mncs9 = "
[4]nat x;
[4]nat y;
[5]nat s;

thread RadixBAddCarryLookahead4 {
    [4]bool g;
    [4]bool p;
    // preliminary sum digits
    s[0] = x[0] + y[0];
    s[1] = x[1] + y[1];
    s[2] = x[2] + y[2];
    s[3] = x[3] + y[3];
    // initial generate conditions
    g[0] = s[0]>255;
    g[1] = s[1]>255;
    g[2] = s[2]>255;
    g[3] = s[3]>255;
    // initial propagate conditions
    p[0] = s[0]==255;
    p[1] = s[1]==255;
    p[2] = s[2]==255;
    p[3] = s[3]==255;
    // carry propagation prefix tree
    // up-level 1
    g[1] = g[0] & p[1] | g[1];
    p[1] = p[1] & p[0];
    g[3] = g[2] & p[3] | g[3];
    p[3] = p[3] & p[2];
    // up-level 2
    g[3] = g[1] & p[3] | g[3];
    p[3] = p[3] & p[1];
    // down-level 4
    // down-level 5
    g[2] = g[1] & p[2] | g[2];
    p[2] = p[2] & p[1];
    // compute final sum digits
    s[0] = s[0] % 256;
    s[1] = (s[1]+(g[0]?1:0)) % 256;
    s[2] = (s[2]+(g[1]?1:0)) % 256;
    s[3] = (s[3]+(g[2]?1:0)) % 256;
    s[4] = (g[3]?1:0);
}
"
// MatrixMult
let mncs10 = "
[3][3]nat a;
[3][3]nat b;
[3][3]nat c;
thread MatrixMult {
    nat t_1,t_2,t_3,t_4,t_5,t_6,t_7,t_8,t_9,t_10,t_11,t_12,t_13,t_14,t_15,t_16,t_17,t_18,t_19,t_20,t_21,t_22,t_23,t_24,t_25,t_26,t_27,t_28,t_29,t_30,t_31,t_32,t_33,t_34,t_35,t_36,t_37,t_38,t_39,t_40,t_41,t_42,t_43,t_44,t_45;
    t_1 = a[0][0] * b[0][0];
    t_2 = a[0][1] * b[1][0];
    t_3 = a[0][2] * b[2][0];
    t_4 = t_1 + t_2;
    t_5 = t_4 + t_3;
    t_6 = a[0][0] * b[0][1];
    t_7 = a[0][1] * b[1][1];
    t_8 = a[0][2] * b[2][1];
    t_9 = t_6 + t_7;
    t_10 = t_9 + t_8;
    t_11 = a[0][0] * b[0][2];
    t_12 = a[0][1] * b[1][2];
    t_13 = a[0][2] * b[2][2];
    t_14 = t_11 + t_12;
    t_15 = t_14 + t_13;
    t_16 = a[1][0] * b[0][0];
    t_17 = a[1][1] * b[1][0];
    t_18 = a[1][2] * b[2][0];
    t_19 = t_16 + t_17;
    t_20 = t_19 + t_18;
    t_21 = a[1][0] * b[0][1];
    t_22 = a[1][1] * b[1][1];
    t_23 = a[1][2] * b[2][1];
    t_24 = t_21 + t_22;
    t_25 = t_24 + t_23;
    t_26 = a[1][0] * b[0][2];
    t_27 = a[1][1] * b[1][2];
    t_28 = a[1][2] * b[2][2];
    t_29 = t_26 + t_27;
    t_30 = t_29 + t_28;
    t_31 = a[2][0] * b[0][0];
    t_32 = a[2][1] * b[1][0];
    t_33 = a[2][2] * b[2][0];
    t_34 = t_31 + t_32;
    t_35 = t_34 + t_33;
    t_36 = a[2][0] * b[0][1];
    t_37 = a[2][1] * b[1][1];
    t_38 = a[2][2] * b[2][1];
    t_39 = t_36 + t_37;
    t_40 = t_39 + t_38;
    t_41 = a[2][0] * b[0][2];
    t_42 = a[2][1] * b[1][2];
    t_43 = a[2][2] * b[2][2];
    t_44 = t_41 + t_42;
    t_45 = t_44 + t_43;
    c[0][0] = t_5;
    c[0][1] = t_10;
    c[0][2] = t_15;
    c[1][0] = t_20;
    c[1][1] = t_25;
    c[1][2] = t_30;
    c[2][0] = t_35;
    c[2][1] = t_40;
    c[2][2] = t_45;
}

"
WriteCLCode mncs9
    

