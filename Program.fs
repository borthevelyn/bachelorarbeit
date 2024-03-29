﻿// These regex strings are used for generated dot files for dpns to show the buffer names as labels and can be ignored.
// Search regex: (.+) -> (.+) \[label=""(,style="(.+)")?,color="([a-zA-Z]+)"(,arrowhead="(.+)")?\]; \/\/ (.+)
// Replace string: $1 -> $2 [label="$8",color="$5"]; // $8
module Program

open Translator.Main

// First Example
let mncs1 =
    "
nat a,b,c; 
thread t1{ 
    b = a * 2;
    c = a + b; 
}"
// Ten benchmarks used for evaluation in my thesis
// http://www.averest.org/examples/MiniC/UnrolledPRAM/TransHull_SclLoc_2.html
let mncs2 =
    "
bool m_0_0,m_0_1,m_1_0,m_1_1;
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
//http://www.averest.org/examples/MiniC/UnrolledPRAM/BitonicSort_4.html
let mncs3 =
    "
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
// http://www.averest.org/examples/MiniC/UnrolledPRAM/BinaryTree_Arr_16.html
let mncs4 =
    "
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
// http://www.averest.org/examples/MiniC/UnrolledPRAM/MatrixMultSimple_ArrLoc_2.html
let mncs5 =
    "
[2][2]nat a;
[2][2]nat b;
[2][2]nat c;
thread MatrixMult {
    nat t_1,t_2,t_3,t_4,t_5,t_6,t_7,t_8,t_9,t_10,t_11,t_12,t_13,t_14,t_15,t_16,t_17,t_18,t_19,t_20;
    t_1 = a[0][0];
    t_2 = a[0][1];
    t_3 = a[1][0];
    t_4 = a[1][1];
    t_5 = b[0][0];
    t_6 = b[0][1];
    t_7 = b[1][0];
    t_8 = b[1][1];
    t_9 = t_1 * t_5;
    t_10 = t_2 * t_7;
    t_11 = t_9 + t_10;
    t_12 = t_1 * t_6;
    t_13 = t_2 * t_8;
    t_14 = t_12 + t_13;
    t_15 = t_3 * t_5;
    t_16 = t_4 * t_7;
    t_17 = t_15 + t_16;
    t_18 = t_3 * t_6;
    t_19 = t_4 * t_8;
    t_20 = t_18 + t_19;
    c[0][0] = t_11;
    c[0][1] = t_14;
    c[1][0] = t_17;
    c[1][1] = t_20;
}
"
// http://www.averest.org/examples/MiniC/UnrolledPRAM/FastFourierTransform_ArrGlb_8.html
let mncs6 =
    "
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
// http://www.averest.org/examples/MiniC/UnrolledPRAM/FastFourierTransform_SclGlb_8.html
let mncs7 =
    "
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
// http://www.averest.org/examples/MiniC/UnrolledPRAM/MatrixMultCannon_SclGlb_4.html
let mncs8 =
    "
nat a_0_0,a_0_1,a_0_2,a_0_3,a_1_0,a_1_1,a_1_2,a_1_3,a_2_0,a_2_1,a_2_2,a_2_3,a_3_0,a_3_1,a_3_2,a_3_3;
nat b_0_0,b_0_1,b_0_2,b_0_3,b_1_0,b_1_1,b_1_2,b_1_3,b_2_0,b_2_1,b_2_2,b_2_3,b_3_0,b_3_1,b_3_2,b_3_3;
nat c_0_0,c_0_1,c_0_2,c_0_3,c_1_0,c_1_1,c_1_2,c_1_3,c_2_0,c_2_1,c_2_2,c_2_3,c_3_0,c_3_1,c_3_2,c_3_3;
thread MatrixMultCannon {
    b_0_0 = b_1_0;
    a_0_0 = a_0_1;
    c_0_0 = c_0_0 + a_0_0 * b_0_0;
    b_0_0 = b_1_0;
    a_0_0 = a_0_1;
    c_0_0 = c_0_0 + a_0_0 * b_0_0;
    b_0_0 = b_1_0;
    a_0_0 = a_0_1;
    c_0_0 = c_0_0 + a_0_0 * b_0_0;
    b_0_0 = b_1_0;
    a_0_0 = a_0_1;
    c_0_0 = c_0_0 + a_0_0 * b_0_0;
    b_0_1 = b_1_1;
    a_0_1 = a_0_2;
    c_0_1 = c_0_1 + a_0_1 * b_0_1;
    b_0_1 = b_1_1;
    a_0_1 = a_0_2;
    c_0_1 = c_0_1 + a_0_1 * b_0_1;
    b_0_1 = b_1_1;
    a_0_1 = a_0_2;
    c_0_1 = c_0_1 + a_0_1 * b_0_1;
    b_0_1 = b_1_1;
    a_0_1 = a_0_2;
    c_0_1 = c_0_1 + a_0_1 * b_0_1;
    b_0_2 = b_1_2;
    a_0_2 = a_0_3;
    c_0_2 = c_0_2 + a_0_2 * b_0_2;
    b_0_2 = b_1_2;
    a_0_2 = a_0_3;
    c_0_2 = c_0_2 + a_0_2 * b_0_2;
    b_0_2 = b_1_2;
    a_0_2 = a_0_3;
    c_0_2 = c_0_2 + a_0_2 * b_0_2;
    b_0_2 = b_1_2;
    a_0_2 = a_0_3;
    c_0_2 = c_0_2 + a_0_2 * b_0_2;
    b_0_3 = b_1_3;
    a_0_3 = a_0_0;
    c_0_3 = c_0_3 + a_0_3 * b_0_3;
    b_0_3 = b_1_3;
    a_0_3 = a_0_0;
    c_0_3 = c_0_3 + a_0_3 * b_0_3;
    b_0_3 = b_1_3;
    a_0_3 = a_0_0;
    c_0_3 = c_0_3 + a_0_3 * b_0_3;
    b_0_3 = b_1_3;
    a_0_3 = a_0_0;
    c_0_3 = c_0_3 + a_0_3 * b_0_3;
    b_1_0 = b_2_0;
    a_1_0 = a_1_1;
    c_1_0 = c_1_0 + a_1_0 * b_1_0;
    b_1_0 = b_2_0;
    a_1_0 = a_1_1;
    c_1_0 = c_1_0 + a_1_0 * b_1_0;
    b_1_0 = b_2_0;
    a_1_0 = a_1_1;
    c_1_0 = c_1_0 + a_1_0 * b_1_0;
    b_1_0 = b_2_0;
    a_1_0 = a_1_1;
    c_1_0 = c_1_0 + a_1_0 * b_1_0;
    b_1_1 = b_2_1;
    a_1_1 = a_1_2;
    c_1_1 = c_1_1 + a_1_1 * b_1_1;
    b_1_1 = b_2_1;
    a_1_1 = a_1_2;
    c_1_1 = c_1_1 + a_1_1 * b_1_1;
    b_1_1 = b_2_1;
    a_1_1 = a_1_2;
    c_1_1 = c_1_1 + a_1_1 * b_1_1;
    b_1_1 = b_2_1;
    a_1_1 = a_1_2;
    c_1_1 = c_1_1 + a_1_1 * b_1_1;
    b_1_2 = b_2_2;
    a_1_2 = a_1_3;
    c_1_2 = c_1_2 + a_1_2 * b_1_2;
    b_1_2 = b_2_2;
    a_1_2 = a_1_3;
    c_1_2 = c_1_2 + a_1_2 * b_1_2;
    b_1_2 = b_2_2;
    a_1_2 = a_1_3;
    c_1_2 = c_1_2 + a_1_2 * b_1_2;
    b_1_2 = b_2_2;
    a_1_2 = a_1_3;
    c_1_2 = c_1_2 + a_1_2 * b_1_2;
    b_1_3 = b_2_3;
    a_1_3 = a_1_0;
    c_1_3 = c_1_3 + a_1_3 * b_1_3;
    b_1_3 = b_2_3;
    a_1_3 = a_1_0;
    c_1_3 = c_1_3 + a_1_3 * b_1_3;
    b_1_3 = b_2_3;
    a_1_3 = a_1_0;
    c_1_3 = c_1_3 + a_1_3 * b_1_3;
    b_1_3 = b_2_3;
    a_1_3 = a_1_0;
    c_1_3 = c_1_3 + a_1_3 * b_1_3;
    b_2_0 = b_3_0;
    a_2_0 = a_2_1;
    c_2_0 = c_2_0 + a_2_0 * b_2_0;
    b_2_0 = b_3_0;
    a_2_0 = a_2_1;
    c_2_0 = c_2_0 + a_2_0 * b_2_0;
    b_2_0 = b_3_0;
    a_2_0 = a_2_1;
    c_2_0 = c_2_0 + a_2_0 * b_2_0;
    b_2_0 = b_3_0;
    a_2_0 = a_2_1;
    c_2_0 = c_2_0 + a_2_0 * b_2_0;
    b_2_1 = b_3_1;
    a_2_1 = a_2_2;
    c_2_1 = c_2_1 + a_2_1 * b_2_1;
    b_2_1 = b_3_1;
    a_2_1 = a_2_2;
    c_2_1 = c_2_1 + a_2_1 * b_2_1;
    b_2_1 = b_3_1;
    a_2_1 = a_2_2;
    c_2_1 = c_2_1 + a_2_1 * b_2_1;
    b_2_1 = b_3_1;
    a_2_1 = a_2_2;
    c_2_1 = c_2_1 + a_2_1 * b_2_1;
    b_2_2 = b_3_2;
    a_2_2 = a_2_3;
    c_2_2 = c_2_2 + a_2_2 * b_2_2;
    b_2_2 = b_3_2;
    a_2_2 = a_2_3;
    c_2_2 = c_2_2 + a_2_2 * b_2_2;
    b_2_2 = b_3_2;
    a_2_2 = a_2_3;
    c_2_2 = c_2_2 + a_2_2 * b_2_2;
    b_2_2 = b_3_2;
    a_2_2 = a_2_3;
    c_2_2 = c_2_2 + a_2_2 * b_2_2;
    b_2_3 = b_3_3;
    a_2_3 = a_2_0;
    c_2_3 = c_2_3 + a_2_3 * b_2_3;
    b_2_3 = b_3_3;
    a_2_3 = a_2_0;
    c_2_3 = c_2_3 + a_2_3 * b_2_3;
    b_2_3 = b_3_3;
    a_2_3 = a_2_0;
    c_2_3 = c_2_3 + a_2_3 * b_2_3;
    b_2_3 = b_3_3;
    a_2_3 = a_2_0;
    c_2_3 = c_2_3 + a_2_3 * b_2_3;
    b_3_0 = b_0_0;
    a_3_0 = a_3_1;
    c_3_0 = c_3_0 + a_3_0 * b_3_0;
    b_3_0 = b_0_0;
    a_3_0 = a_3_1;
    c_3_0 = c_3_0 + a_3_0 * b_3_0;
    b_3_0 = b_0_0;
    a_3_0 = a_3_1;
    c_3_0 = c_3_0 + a_3_0 * b_3_0;
    b_3_0 = b_0_0;
    a_3_0 = a_3_1;
    c_3_0 = c_3_0 + a_3_0 * b_3_0;
    b_3_1 = b_0_1;
    a_3_1 = a_3_2;
    c_3_1 = c_3_1 + a_3_1 * b_3_1;
    b_3_1 = b_0_1;
    a_3_1 = a_3_2;
    c_3_1 = c_3_1 + a_3_1 * b_3_1;
    b_3_1 = b_0_1;
    a_3_1 = a_3_2;
    c_3_1 = c_3_1 + a_3_1 * b_3_1;
    b_3_1 = b_0_1;
    a_3_1 = a_3_2;
    c_3_1 = c_3_1 + a_3_1 * b_3_1;
    b_3_2 = b_0_2;
    a_3_2 = a_3_3;
    c_3_2 = c_3_2 + a_3_2 * b_3_2;
    b_3_2 = b_0_2;
    a_3_2 = a_3_3;
    c_3_2 = c_3_2 + a_3_2 * b_3_2;
    b_3_2 = b_0_2;
    a_3_2 = a_3_3;
    c_3_2 = c_3_2 + a_3_2 * b_3_2;
    b_3_2 = b_0_2;
    a_3_2 = a_3_3;
    c_3_2 = c_3_2 + a_3_2 * b_3_2;
    b_3_3 = b_0_3;
    a_3_3 = a_3_0;
    c_3_3 = c_3_3 + a_3_3 * b_3_3;
    b_3_3 = b_0_3;
    a_3_3 = a_3_0;
    c_3_3 = c_3_3 + a_3_3 * b_3_3;
    b_3_3 = b_0_3;
    a_3_3 = a_3_0;
    c_3_3 = c_3_3 + a_3_3 * b_3_3;
    b_3_3 = b_0_3;
    a_3_3 = a_3_0;
    c_3_3 = c_3_3 + a_3_3 * b_3_3;
    c_0_0 = c_0_0;
    c_0_1 = c_0_1;
    c_0_2 = c_0_2;
    c_0_3 = c_0_3;
    c_1_0 = c_1_0;
    c_1_1 = c_1_1;
    c_1_2 = c_1_2;
    c_1_3 = c_1_3;
    c_2_0 = c_2_0;
    c_2_1 = c_2_1;
    c_2_2 = c_2_2;
    c_2_3 = c_2_3;
    c_3_0 = c_3_0;
    c_3_1 = c_3_1;
    c_3_2 = c_3_2;
    c_3_3 = c_3_3;
}
"
//http://www.averest.org/examples/MiniC/UnrolledPRAM/RadixBAddCarryLookahead_ArrGlb_4.html
let mncs9 =
    "
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
//http://www.averest.org/examples/MiniC/UnrolledPRAM/RadixBMulDadda_ArrLoc_4.html
let mncs10 =
    "
[4]nat x;
[4]nat y;
[8]nat p;
thread RadixBMulDadda {
nat t0,t1,t10,t100,t101,t102,t103,t104,t105,t106,t107,t108,t109,t11,t110,t111,t112,t113,t114,t115,t116,t117,t118,t119,t12,t120,t121,t122,t123,t124,t125,t126,t127,t128,t13,t14,t15,t16,t17,t18,t19,t2,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t3,t30,t31,t32,t33,t34,t35,t36,t37,t38,t39,t4,t40,t41,t42,t43,t44,t45,t46,t47,t48,t49,t5,t50,t51,t52,t53,t54,t55,t56,t57,t58,t59,t6,t60,t61,t62,t63,t64,t65,t66,t67,t68,t69,t7,t70,t71,t72,t73,t74,t75,t76,t77,t78,t79,t8,t80,t81,t82,t83,t84,t85,t86,t87,t88,t89,t9,t90,t91,t92,t93,t94,t95,t96,t97,t98,t99;
bool t129,t130,t131,t132,t133,t134,t135,t136,t137,t138,t139,t140,t141,t142;
    t0 = x[0];
    t1 = x[1];
    t2 = x[2];
    t3 = x[3];
    t4 = y[0];
    t5 = y[1];
    t6 = y[2];
    t7 = y[3];
    // compute partial products
    t8 = t0 * t4;
    t9 = t8 / 256;
    t10 = t8 % 256;
    t11 = t0 * t5;
    t12 = t11 / 256;
    t13 = t11 % 256;
    t14 = t1 * t4;
    t15 = t14 / 256;
    t16 = t14 % 256;
    t17 = t0 * t6;
    t18 = t17 / 256;
    t19 = t17 % 256;
    t20 = t1 * t5;
    t21 = t20 / 256;
    t22 = t20 % 256;
    t23 = t2 * t4;
    t24 = t23 / 256;
    t25 = t23 % 256;
    t26 = t0 * t7;
    t27 = t26 / 256;
    t28 = t26 % 256;
    t29 = t1 * t6;
    t30 = t29 / 256;
    t31 = t29 % 256;
    t32 = t2 * t5;
    t33 = t32 / 256;
    t34 = t32 % 256;
    t35 = t3 * t4;
    t36 = t35 / 256;
    t37 = t35 % 256;
    t38 = t1 * t7;
    t39 = t38 / 256;
    t40 = t38 % 256;
    t41 = t2 * t6;
    t42 = t41 / 256;
    t43 = t41 % 256;
    t44 = t3 * t5;
    t45 = t44 / 256;
    t46 = t44 % 256;
    t47 = t2 * t7;
    t48 = t47 / 256;
    t49 = t47 % 256;
    t50 = t3 * t6;
    t51 = t50 / 256;
    t52 = t50 % 256;
    t53 = t3 * t7;
    t54 = t53 / 256;
    t55 = t53 % 256;
    // reduce heights of each column to 6
    t56 = t37 + t34;
    t57 = t56 / 256;
    t58 = t56 % 256;
    t59 = t46 + t43 + t40;
    t60 = t59 / 256;
    t61 = t59 % 256;
    // reduce heights of each column to 4
    t62 = t25 + t22;
    t63 = t62 / 256;
    t64 = t62 % 256;
    t65 = t21 + t18;
    t66 = t65 / 256;
    t67 = t65 % 256;
    t68 = t31 + t28 + t24;
    t69 = t68 / 256;
    t70 = t68 % 256;
    t71 = t27 + t57 + t61;
    t72 = t71 / 256;
    t73 = t71 % 256;
    t74 = t36 + t33 + t30;
    t75 = t74 / 256;
    t76 = t74 % 256;
    t77 = t42 + t39 + t60;
    t78 = t77 / 256;
    t79 = t77 % 256;
    t80 = t52 + t49 + t45;
    t81 = t80 / 256;
    t82 = t80 % 256;
    t83 = t55 + t51;
    t84 = t83 / 256;
    t85 = t83 % 256;
    // reduce heights of each column to 3
    t86 = t19 + t15;
    t87 = t86 / 256;
    t88 = t86 % 256;
    t89 = t58 + t63 + t67;
    t90 = t89 / 256;
    t91 = t89 % 256;
    t92 = t66 + t69 + t73;
    t93 = t92 / 256;
    t94 = t92 % 256;
    t95 = t72 + t75 + t79;
    t96 = t95 / 256;
    t97 = t95 % 256;
    t98 = t48 + t78 + t81;
    t99 = t98 / 256;
    t100 = t98 % 256;
    // reduce heights of each column to 2
    t101 = t16 + t13;
    t102 = t101 / 256;
    t103 = t101 % 256;
    t104 = t12 + t64 + t88;
    t105 = t104 / 256;
    t106 = t104 % 256;
    t107 = t70 + t87 + t91;
    t108 = t107 / 256;
    t109 = t107 % 256;
    t110 = t76 + t90 + t94;
    t111 = t110 / 256;
    t112 = t110 % 256;
    t113 = t82 + t93 + t97;
    t114 = t113 / 256;
    t115 = t113 % 256;
    t116 = t85 + t96 + t100;
    t117 = t116 / 256;
    t118 = t116 % 256;
    t119 = t54 + t84 + t99;
    t120 = t119 / 256;
    t121 = t119 % 256;
    // preliminary addition of the two remaining numbers
    t122 = t9 + t103;
    t123 = t102 + t106;
    t124 = t105 + t109;
    t125 = t108 + t112;
    t126 = t111 + t115;
    t127 = t114 + t118;
    t128 = t117 + t121;
    // compute generate and propagate pairs
    t129 = t122 > 255;
    t130 = t122 == 255;
    t131 = t123 > 255;
    t132 = t123 == 255;
    t133 = t124 > 255;
    t134 = t124 == 255;
    t135 = t125 > 255;
    t136 = t125 == 255;
    t137 = t126 > 255;
    t138 = t126 == 255;
    t139 = t127 > 255;
    t140 = t127 == 255;
    t141 = t128 > 255;
    t142 = t128 == 255;
    // parallel prefix tree for computing carry bits
    // up-level 1
    t131 = t132 & t129 | t131;
    t132 = t132 & t130;
    t135 = t136 & t133 | t135;
    t136 = t136 & t134;
    t139 = t140 & t137 | t139;
    t140 = t140 & t138;
    // up-level 2
    t135 = t136 & t131 | t135;
    t136 = t136 & t132;
    // down-level 4
    t139 = t140 & t135 | t139;
    t140 = t140 & t136;
    // down-level 5
    t141 = t142 & t139 | t141;
    t142 = t142 & t140;
    t133 = t134 & t131 | t133;
    t134 = t134 & t132;
    t141 = t142 & t139 | t141;
    t142 = t142 & t140;
    t137 = t138 & t135 | t137;
    t138 = t138 & t136;
    t141 = t142 & t139 | t141;
    t142 = t142 & t140;
    // compute final sum digits as the digits of the product
    t128 = t128+(t139?1:0);
    t127 = t127+(t137?1:0);
    t126 = t126+(t135?1:0);
    t125 = t125+(t133?1:0);
    t124 = t124+(t131?1:0);
    t123 = t123+(t129?1:0);
    // get the product digits
    p[0] = t10;
    p[1] = t122 % 256;
    p[2] = t123 % 256;
    p[3] = t124 % 256;
    p[4] = t125 % 256;
    p[5] = t126 % 256;
    p[6] = t127 % 256;
    p[7] = t128 % 256;
}
"

// Examples described in my bachelor thesis
// Simple example
let mncs11 =     
    "
nat a,b,c; 
thread t1 {  
    b = a * 2;
    c = a * 3 + b;        
}  
"

// Complex examples
//http://www.averest.org/examples/MiniC/UnrolledPRAM/MatrixMultCannon_SclGlb_2.html
let mncs12 =     
    "

nat a_0_0,a_0_1,a_1_0,a_1_1;
nat b_0_0,b_0_1,b_1_0,b_1_1;
nat c_0_0,c_0_1,c_1_0,c_1_1;
thread MatrixMultCannon {
    b_0_0 = b_1_0;
    a_0_0 = a_0_1;
    c_0_0 = c_0_0 + a_0_0 * b_0_0;
    b_0_0 = b_1_0;
    a_0_0 = a_0_1;
    c_0_0 = c_0_0 + a_0_0 * b_0_0;
    b_0_1 = b_1_1;
    a_0_1 = a_0_0;
    c_0_1 = c_0_1 + a_0_1 * b_0_1;
    b_0_1 = b_1_1;
    a_0_1 = a_0_0;
    c_0_1 = c_0_1 + a_0_1 * b_0_1;
    b_1_0 = b_0_0;
    a_1_0 = a_1_1;
    c_1_0 = c_1_0 + a_1_0 * b_1_0;
    b_1_0 = b_0_0;
    a_1_0 = a_1_1;
    c_1_0 = c_1_0 + a_1_0 * b_1_0;
    b_1_1 = b_0_1;
    a_1_1 = a_1_0;
    c_1_1 = c_1_1 + a_1_1 * b_1_1;
    b_1_1 = b_0_1;
    a_1_1 = a_1_0;
    c_1_1 = c_1_1 + a_1_1 * b_1_1;
    c_0_0 = c_0_0;
    c_0_1 = c_0_1;
    c_1_0 = c_1_0;
    c_1_1 = c_1_1;
}

"

//http://www.averest.org/examples/MiniC/UnrolledPRAM/MatrixMultCannon_ArrGlb_2.html
let mncs13 = "
[2][2]nat a;
[2][2]nat b;
[2][2]nat c;
thread MatrixMultCannonArr2 {
    nat t_1,t_2,t_3,t_4,t_5,t_6,t_7,t_8,t_9,t_10,t_11,t_12;
    t_1 = a[0][0];
    t_2 = a[0][1];
    t_3 = a[1][1];
    t_4 = a[1][0];
    t_5 = b[0][0];
    t_6 = b[1][1];
    t_7 = b[1][0];
    t_8 = b[0][1];
    t_5 = t_7;
    t_1 = t_2;
    t_9 = t_9 + t_1 * t_5;
    t_5 = t_7;
    t_1 = t_2;
    t_9 = t_9 + t_1 * t_5;
    t_6 = t_8;
    t_2 = t_1;
    t_10 = t_10 + t_2 * t_6;
    t_6 = t_8;
    t_2 = t_1;
    t_10 = t_10 + t_2 * t_6;
    t_7 = t_5;
    t_3 = t_4;
    t_11 = t_11 + t_3 * t_7;
    t_7 = t_5;
    t_3 = t_4;
    t_11 = t_11 + t_3 * t_7;
    t_8 = t_6;
    t_4 = t_3;
    t_12 = t_12 + t_4 * t_8;
    t_8 = t_6;
    t_4 = t_3;
    t_12 = t_12 + t_4 * t_8;
    c[0][0] = t_9;
    c[0][1] = t_10;
    c[1][0] = t_11;
    c[1][1] = t_12;
}"

// the following line may be uncommented to produce output for any single program
//WriteCode mncs13 "Mult" |> ignore

// the following line produces code for all programs in the MiniCPrograms folder
mncPrgToCppPrg ()
