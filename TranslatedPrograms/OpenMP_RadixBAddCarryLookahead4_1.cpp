#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int _bf99, bool* _bf101) { 
    int _bf100 = 255;
    *_bf101 = _bf99 == _bf100;
}
void path1(int* _bf104) { 
    *_bf104 = 2;
}
void path2(int* _bf105) { 
    *_bf105 = 2;
}
void path3(int* _bf109) { 
    *_bf109 = 255;
}
void path4(int* _bf127) { 
    *_bf127 = 1;
}
void path5(int* _bf132) { 
    *_bf132 = 1;
}
void path6(int* _bf14) { 
    *_bf14 = 1;
}
void path7(int* _bf145) { 
    *_bf145 = 0;
}
void path8(int* _bf153) { 
    *_bf153 = 3;
}
void path9(int* _bf158) { 
    *_bf158 = 3;
}
void path10(int* _bf163) { 
    *_bf163 = 3;
}
void path11(int* _bf176) { 
    *_bf176 = 2;
}
void path12(int* _bf184) { 
    *_bf184 = 3;
}
void path13(int* _bf189) { 
    *_bf189 = 3;
}
void path14(int* _bf19) { 
    *_bf19 = 1;
}
void path15(int* _bf194) { 
    *_bf194 = 3;
}
void path16(int* _bf2) { 
    *_bf2 = 0;
}
void path17(int* _bf207) { 
    *_bf207 = 1;
}
void path18(int* _bf215) { 
    *_bf215 = 2;
}
void path19(int* _bf220) { 
    *_bf220 = 2;
}
void path20(int* _bf225) { 
    *_bf225 = 2;
}
void path21(bool _bf244, bool* _bf243, bool** _bf1) { 
    int _bf233 = 2;
    _bf243[_bf233] = _bf244;
    *_bf1 = _bf243;
}
void path22(int* _bf238) { 
    *_bf238 = 1;
}
void path23(int* _bf246) { 
    *_bf246 = 0;
}
void path24(int* _bf247) { 
    *_bf247 = 0;
}
void path25(int* _bf254) { 
    *_bf254 = 1;
}
void path26(int* _bf255) { 
    *_bf255 = 1;
}
void path27(int* _bf259) { 
    *_bf259 = 0;
}
void path28(int* _bf26) { 
    *_bf26 = 2;
}
void path29(int* _bf264) { 
    *_bf264 = 0;
}
void path30(int* _bf267) { 
    *_bf267 = 256;
}
void path31(int* _bf27) { 
    *_bf27 = 2;
}
void path32(int* _bf270) { 
    *_bf270 = 2;
}
void path33(int* _bf271) { 
    *_bf271 = 2;
}
void path34(int* _bf275) { 
    *_bf275 = 1;
}
void path35(int* _bf279) { 
    *_bf279 = 1;
}
void path36(int* _bf280) { 
    *_bf280 = 0;
}
void path37(int* _bf283) { 
    *_bf283 = 256;
}
void path38(int _bf336, int _bf302, int _bf300, int* _bf322, int** s) { 
    int _bf286 = 3;
    _bf322[_bf286] = _bf300;
    int* _bf301 = _bf322;
    _bf301[_bf302] = _bf336;
    *s = _bf301;
}
void path39(int* _bf287) { 
    *_bf287 = 3;
}
void path40(bool* _bf277, bool* _bf294, bool** _bf293) { 
    int _bf291 = 2;
    *_bf294 = _bf277[_bf291];
    *_bf293 = _bf277;
}
void path41(int _bf299, int _bf290, int _bf296, bool _bf294, int* _bf300) { 
    int _bf295 = 1;
    int _bf297;
    if ( _bf294 ) {
        _bf297 = _bf295;
    } else  { 
        _bf297 = _bf296;
    } 
    int _bf323 = _bf297;
    int _bf324 = _bf323;
    int _bf325 = _bf324;
    int _bf326 = _bf325;
    int _bf327 = _bf326;
    int _bf328 = _bf327;
    int _bf298 = _bf290 + _bf328;
    *_bf300 = _bf298 % _bf299;
}
void path42(int* _bf296) { 
    *_bf296 = 0;
}
void path43(int* _bf299) { 
    *_bf299 = 256;
}
void path44(int _bf52, int _bf38, int _bf26, int _bf14, int* s, int _bf2, int _bf27, int _bf19, int* _bf55, int** _bf54, int** y, int** x) { 
    int _bf3 = 0;
    int _bf7 = 0;
    int _bf15 = 1;
    int _bf6 = (*x)[_bf3];
    int* _bf5 = (*x);
    int _bf10 = (*y)[_bf7];
    int* _bf9 = (*y);
    int _bf18 = _bf5[_bf15];
    int* _bf17 = _bf5;
    int _bf11 = _bf6 + _bf10;
    int _bf22 = _bf9[_bf19];
    int* _bf21 = _bf9;
    int _bf31 = 2;
    int _bf30 = _bf17[_bf27];
    int* _bf29 = _bf17;
    s[_bf2] = _bf11;
    int* _bf13 = s;
    int _bf23 = _bf18 + _bf22;
    int _bf34 = _bf21[_bf31];
    int* _bf33 = _bf21;
    int _bf39 = 3;
    int _bf43 = 3;
    int _bf35 = _bf30 + _bf34;
    _bf13[_bf14] = _bf23;
    int* _bf25 = _bf13;
    int _bf42 = _bf29[_bf39];
    *x = _bf29;
    int _bf46 = _bf33[_bf43];
    *y = _bf33;
    _bf25[_bf26] = _bf35;
    int* _bf37 = _bf25;
    int _bf47 = _bf42 + _bf46;
    _bf37[_bf38] = _bf47;
    int* _bf49 = _bf37;
    *_bf55 = _bf49[_bf52];
    *_bf54 = _bf49;
}
void path45(int* _bf302) { 
    *_bf302 = 4;
}
void path46(bool* _bf293, bool* _bf306, bool** _bf0) { 
    int _bf303 = 3;
    *_bf306 = _bf293[_bf303];
    *_bf0 = _bf293;
}
void path47(int _bf308, bool _bf306, int* _bf336) { 
    int _bf307 = 1;
    int _bf309;
    if ( _bf306 ) {
        _bf309 = _bf307;
    } else  { 
        _bf309 = _bf308;
    } 
    int _bf329 = _bf309;
    int _bf330 = _bf329;
    int _bf331 = _bf330;
    int _bf332 = _bf331;
    int _bf333 = _bf332;
    int _bf334 = _bf333;
    int _bf335 = _bf334;
    *_bf336 = _bf335;
}
void path48(int* _bf308) { 
    *_bf308 = 0;
}
void path49(int* _bf38) { 
    *_bf38 = 3;
}
void path50(int _bf287, int _bf270, int _bf283, int _bf271, int _bf254, int _bf267, int _bf280, int _bf279, int _bf264, int _bf275, int _bf259, int _bf215, int _bf238, int _bf220, int _bf225, int _bf184, int _bf207, int _bf189, int _bf194, int _bf153, int _bf176, int _bf158, int _bf163, int _bf145, int _bf255, int _bf246, int _bf127, bool* _bf112, int _bf247, int _bf132, int* _bf107, bool _bf83, int _bf77, bool _bf74, int _bf68, bool _bf65, int _bf59, bool _bf56, bool* _bf0, int** _bf322, int* _bf290, bool** _bf277, bool* _bf244, bool** _bf243) { 
    int _bf50 = 0;
    _bf0[_bf50] = _bf56;
    bool* _bf58 = _bf0;
    _bf58[_bf59] = _bf65;
    bool* _bf67 = _bf58;
    _bf67[_bf68] = _bf74;
    bool* _bf76 = _bf67;
    _bf76[_bf77] = _bf83;
    bool* _bf85 = _bf76;
    int _bf114 = 3;
    int _bf123 = 0;
    bool* _bf124 = _bf85;
    bool* _bf133 = _bf85;
    int _bf117 = _bf107[_bf114];
    int* _bf116 = _bf107;
    int _bf118 = 255;
    bool _bf126 = _bf124[_bf123];
    bool* _bf125 = _bf124;
    bool _bf135 = _bf133[_bf132];
    bool* _bf134 = _bf133;
    int _bf113 = 3;
    int _bf250 = _bf116[_bf247];
    int* _bf249 = _bf116;
    bool _bf119 = _bf117 == _bf118;
    bool _bf4 = _bf126;
    bool* _bf137 = _bf134;
    int _bf251 = 256;
    bool _bf16 = _bf135;
    _bf112[_bf113] = _bf119;
    bool* _bf121 = _bf112;
    int* _bf66 = _bf249;
    bool _bf8 = _bf4;
    bool* _bf32 = _bf137;
    int _bf252 = _bf250 % _bf251;
    bool _bf20 = _bf16;
    bool _bf130 = _bf121[_bf127];
    bool* _bf129 = _bf121;
    _bf66[_bf246] = _bf252;
    int* _bf253 = _bf66;
    bool _bf12 = _bf8;
    bool* _bf36 = _bf32;
    bool _bf24 = _bf20;
    bool* _bf142 = _bf129;
    bool* _bf146 = _bf129;
    int _bf258 = _bf253[_bf255];
    int* _bf257 = _bf253;
    bool _bf131 = _bf12 && _bf130;
    int _bf141 = 1;
    bool* _bf40 = _bf36;
    bool _bf28 = _bf24;
    bool _bf148 = _bf146[_bf145];
    bool* _bf147 = _bf146;
    int* _bf71 = _bf257;
    int _bf122 = 1;
    bool _bf138 = _bf131 || _bf28;
    int _bf221 = _bf258;
    bool _bf144 = _bf142[_bf141];
    bool* _bf143 = _bf142;
    bool* _bf41 = _bf40;
    bool* _bf150 = _bf147;
    int* _bf75 = _bf71;
    _bf41[_bf122] = _bf138;
    bool* _bf139 = _bf41;
    int _bf229 = _bf221;
    int _bf140 = 1;
    bool _bf151 = _bf144 && _bf148;
    int* _bf80 = _bf75;
    bool* _bf155 = _bf139;
    bool* _bf164 = _bf139;
    int _bf154 = 2;
    int _bf242 = _bf229;
    _bf150[_bf140] = _bf151;
    bool* _bf152 = _bf150;
    int* _bf84 = _bf80;
    bool _bf166 = _bf164[_bf163];
    bool* _bf165 = _bf164;
    bool _bf157 = _bf155[_bf154];
    bool* _bf156 = _bf155;
    int _bf245 = _bf242;
    bool _bf161 = _bf152[_bf158];
    bool* _bf160 = _bf152;
    int* _bf88 = _bf84;
    bool _bf44 = _bf166;
    bool _bf162 = _bf157 && _bf161;
    bool* _bf168 = _bf165;
    int _bf248 = _bf245;
    bool* _bf173 = _bf160;
    bool* _bf177 = _bf160;
    int _bf172 = 3;
    int* _bf93 = _bf88;
    bool _bf169 = _bf162 || _bf44;
    bool* _bf45 = _bf168;
    int _bf256 = _bf248;
    bool _bf179 = _bf177[_bf176];
    bool* _bf178 = _bf177;
    bool _bf175 = _bf173[_bf172];
    bool* _bf174 = _bf173;
    int* _bf97 = _bf93;
    _bf45[_bf153] = _bf169;
    bool* _bf170 = _bf45;
    int _bf260 = _bf256;
    bool* _bf181 = _bf178;
    int _bf171 = 3;
    bool _bf182 = _bf175 && _bf179;
    int* _bf102 = _bf97;
    bool* _bf186 = _bf170;
    bool* _bf195 = _bf170;
    int _bf185 = 1;
    int _bf272 = _bf260;
    _bf181[_bf171] = _bf182;
    bool* _bf183 = _bf181;
    int* _bf106 = _bf102;
    bool _bf197 = _bf195[_bf194];
    bool* _bf196 = _bf195;
    bool _bf188 = _bf186[_bf185];
    bool* _bf187 = _bf186;
    int _bf276 = _bf272;
    bool _bf192 = _bf183[_bf189];
    bool* _bf191 = _bf183;
    int* _bf111 = _bf106;
    bool _bf48 = _bf197;
    bool _bf193 = _bf188 && _bf192;
    bool* _bf199 = _bf196;
    int _bf288 = _bf276;
    bool* _bf204 = _bf191;
    bool* _bf208 = _bf191;
    int _bf203 = 3;
    int* _bf115 = _bf111;
    bool _bf200 = _bf193 || _bf48;
    bool* _bf53 = _bf199;
    int _bf292 = _bf288;
    bool _bf210 = _bf208[_bf207];
    bool* _bf209 = _bf208;
    bool _bf206 = _bf204[_bf203];
    bool* _bf205 = _bf204;
    int* _bf120 = _bf115;
    _bf53[_bf184] = _bf200;
    bool* _bf201 = _bf53;
    int _bf304 = _bf292;
    bool* _bf212 = _bf209;
    int _bf202 = 3;
    bool _bf213 = _bf206 && _bf210;
    int* _bf128 = _bf120;
    bool* _bf217 = _bf201;
    bool* _bf226 = _bf201;
    int _bf216 = 1;
    int _bf305 = _bf304;
    _bf212[_bf202] = _bf213;
    bool* _bf214 = _bf212;
    int* _bf136 = _bf128;
    bool _bf228 = _bf226[_bf225];
    bool* _bf227 = _bf226;
    bool _bf219 = _bf217[_bf216];
    bool* _bf218 = _bf217;
    int _bf310 = _bf305;
    bool _bf223 = _bf214[_bf220];
    bool* _bf222 = _bf214;
    int* _bf149 = _bf136;
    bool _bf57 = _bf228;
    bool _bf224 = _bf219 && _bf223;
    bool* _bf230 = _bf227;
    int _bf311 = _bf310;
    bool* _bf235 = _bf222;
    bool* _bf239 = _bf222;
    int _bf234 = 2;
    int* _bf159 = _bf149;
    bool _bf231 = _bf224 || _bf57;
    bool* _bf62 = _bf230;
    int _bf312 = _bf311;
    bool _bf241 = _bf239[_bf238];
    bool* _bf240 = _bf239;
    bool _bf237 = _bf235[_bf234];
    bool* _bf236 = _bf235;
    int* _bf167 = _bf159;
    _bf62[_bf215] = _bf231;
    bool* _bf232 = _bf62;
    int _bf313 = _bf312;
    *_bf243 = _bf240;
    *_bf244 = _bf237 && _bf241;
    int* _bf180 = _bf167;
    bool _bf262 = _bf232[_bf259];
    bool* _bf261 = _bf232;
    int _bf263 = 1;
    int _bf314 = _bf313;
    int* _bf190 = _bf180;
    bool _bf278 = _bf261[_bf275];
    *_bf277 = _bf261;
    int _bf265;
    if ( _bf262 ) {
        _bf265 = _bf263;
    } else  { 
        _bf265 = _bf264;
    } 
    int _bf315 = _bf314;
    int* _bf198 = _bf190;
    int _bf281;
    if ( _bf278 ) {
        _bf281 = _bf279;
    } else  { 
        _bf281 = _bf280;
    } 
    int _bf266 = _bf315 + _bf265;
    int* _bf211 = _bf198;
    int _bf318 = _bf281;
    int _bf268 = _bf266 % _bf267;
    _bf211[_bf254] = _bf268;
    int* _bf269 = _bf211;
    int _bf319 = _bf318;
    int _bf274 = _bf269[_bf271];
    int* _bf273 = _bf269;
    int _bf320 = _bf319;
    int* _bf316 = _bf273;
    int _bf282 = _bf274 + _bf320;
    int* _bf317 = _bf316;
    int _bf284 = _bf282 % _bf283;
    _bf317[_bf270] = _bf284;
    int* _bf285 = _bf317;
    *_bf290 = _bf285[_bf287];
    int* _bf289 = _bf285;
    int* _bf321 = _bf289;
    *_bf322 = _bf321;
}
void path51(int _bf55, bool* _bf56) { 
    int _bf51 = 255;
    *_bf56 = _bf51 < _bf55;
}
void path52(int* _bf52) { 
    *_bf52 = 0;
}
void path53(int* _bf59) { 
    *_bf59 = 1;
}
void path54(int _bf64, bool* _bf65) { 
    int _bf60 = 255;
    *_bf65 = _bf60 < _bf64;
}
void path55(int* _bf54, int* _bf64, int** _bf63) { 
    int _bf61 = 1;
    *_bf64 = _bf54[_bf61];
    *_bf63 = _bf54;
}
void path56(int* _bf68) { 
    *_bf68 = 2;
}
void path57(int _bf73, bool* _bf74) { 
    int _bf69 = 255;
    *_bf74 = _bf69 < _bf73;
}
void path58(int* _bf63, int* _bf73, int** _bf72) { 
    int _bf70 = 2;
    *_bf73 = _bf63[_bf70];
    *_bf72 = _bf63;
}
void path59(int* _bf77) { 
    *_bf77 = 3;
}
void path60(int _bf82, bool* _bf83) { 
    int _bf78 = 255;
    *_bf83 = _bf78 < _bf82;
}
void path61(int* _bf72, int* _bf82, int** _bf81) { 
    int _bf79 = 3;
    *_bf82 = _bf72[_bf79];
    *_bf81 = _bf72;
}
void path62(int* _bf86) { 
    *_bf86 = 0;
}
void path63(int* _bf81, int* _bf90, int** _bf89) { 
    int _bf87 = 0;
    *_bf90 = _bf81[_bf87];
    *_bf89 = _bf81;
}
void path64(int _bf90, bool* _bf92) { 
    int _bf91 = 255;
    *_bf92 = _bf90 == _bf91;
}
void path65(bool _bf110, int _bf104, bool _bf101, int _bf95, bool _bf92, bool* _bf1, int _bf86, bool** _bf112) { 
    _bf1[_bf86] = _bf92;
    bool* _bf94 = _bf1;
    _bf94[_bf95] = _bf101;
    bool* _bf103 = _bf94;
    _bf103[_bf104] = _bf110;
    *_bf112 = _bf103;
}
void path66(int* _bf95) { 
    *_bf95 = 1;
}
void path67(int _bf109, int _bf105, int* _bf89, bool* _bf110, int** _bf107, int* _bf99) { 
    int _bf96 = 1;
    *_bf99 = _bf89[_bf96];
    int* _bf98 = _bf89;
    int _bf108 = _bf98[_bf105];
    *_bf107 = _bf98;
    *_bf110 = _bf108 == _bf109;
}

int main(int argc, char** argv)
{
    bool onlyTimeOutput = [&]() {
        if (argc < 2) return false;

        if (std::string(argv[1]) == "--onlytime")
            return true;
        else
            return false;
    }();

    bool* _bf0_arr = new bool[4 * DATA_SIZE];
    bool* _bf1_arr = new bool[4 * DATA_SIZE];
    int* s_arr = new int[5 * DATA_SIZE];
    int* x_arr = new int[4 * DATA_SIZE];
    int* y_arr = new int[4 * DATA_SIZE];
    auto start = chrono::steady_clock::now();
    #pragma omp parallel for 
    for (int i = 0; i < DATA_SIZE; i++) {
       int _bf104;
       int _bf105;
       int _bf109;
       int _bf127;
       int _bf132;
       int _bf14;
       int _bf145;
       int _bf153;
       int _bf158;
       int _bf163;
       int _bf176;
       int _bf184;
       int _bf189;
       int _bf19;
       int _bf194;
       int _bf2;
       int _bf207;
       int _bf215;
       int _bf220;
       int _bf225;
       int _bf238;
       int _bf246;
       int _bf247;
       int _bf254;
       int _bf255;
       int _bf259;
       int _bf26;
       int _bf264;
       int _bf267;
       int _bf27;
       int _bf270;
       int _bf271;
       int _bf275;
       int _bf279;
       int _bf280;
       int _bf283;
       int _bf287;
       int _bf296;
       int _bf299;
       int _bf302;
       int _bf308;
       int _bf38;
       int _bf52;
       int _bf59;
       int _bf68;
       int _bf77;
       int _bf86;
       int _bf95;
       int _bf55;
       int* _bf54;
       int* y = y_arr + i * 4;
       int* x = x_arr + i * 4;
       bool _bf56;
       int _bf64;
       int* _bf63;
       bool _bf65;
       int _bf73;
       int* _bf72;
       bool _bf74;
       int _bf82;
       int* _bf81;
       bool _bf83;
       int _bf90;
       int* _bf89;
       bool _bf92;
       bool _bf110;
       int* _bf107;
       int _bf99;
       bool _bf101;
       bool* _bf112;
       int* _bf322;
       int _bf290;
       bool* _bf277;
       bool _bf244;
       bool* _bf243;
       bool* _bf1 = _bf1_arr + i * 4;
       bool _bf294;
       bool* _bf293;
       int _bf300;
       bool _bf306;
       bool* _bf0 = _bf0_arr + i * 4;
       int _bf336;
       int* s = s_arr + i * 5;

       #pragma omp parallel sections
       {
           #pragma omp section
               path1(&_bf104);
           #pragma omp section
               path2(&_bf105);
           #pragma omp section
               path3(&_bf109);
           #pragma omp section
               path4(&_bf127);
           #pragma omp section
               path5(&_bf132);
           #pragma omp section
               path6(&_bf14);
           #pragma omp section
               path7(&_bf145);
           #pragma omp section
               path8(&_bf153);
           #pragma omp section
               path9(&_bf158);
           #pragma omp section
               path10(&_bf163);
           #pragma omp section
               path11(&_bf176);
           #pragma omp section
               path12(&_bf184);
           #pragma omp section
               path13(&_bf189);
           #pragma omp section
               path14(&_bf19);
           #pragma omp section
               path15(&_bf194);
           #pragma omp section
               path16(&_bf2);
           #pragma omp section
               path17(&_bf207);
           #pragma omp section
               path18(&_bf215);
           #pragma omp section
               path19(&_bf220);
           #pragma omp section
               path20(&_bf225);
           #pragma omp section
               path22(&_bf238);
           #pragma omp section
               path23(&_bf246);
           #pragma omp section
               path24(&_bf247);
           #pragma omp section
               path25(&_bf254);
           #pragma omp section
               path26(&_bf255);
           #pragma omp section
               path27(&_bf259);
           #pragma omp section
               path28(&_bf26);
           #pragma omp section
               path29(&_bf264);
           #pragma omp section
               path30(&_bf267);
           #pragma omp section
               path31(&_bf27);
           #pragma omp section
               path32(&_bf270);
           #pragma omp section
               path33(&_bf271);
           #pragma omp section
               path34(&_bf275);
           #pragma omp section
               path35(&_bf279);
           #pragma omp section
               path36(&_bf280);
           #pragma omp section
               path37(&_bf283);
           #pragma omp section
               path39(&_bf287);
           #pragma omp section
               path42(&_bf296);
           #pragma omp section
               path43(&_bf299);
           #pragma omp section
               path45(&_bf302);
           #pragma omp section
               path48(&_bf308);
           #pragma omp section
               path49(&_bf38);
           #pragma omp section
               path52(&_bf52);
           #pragma omp section
               path53(&_bf59);
           #pragma omp section
               path56(&_bf68);
           #pragma omp section
               path59(&_bf77);
           #pragma omp section
               path62(&_bf86);
           #pragma omp section
               path66(&_bf95);
       }
       path44(_bf52, _bf38, _bf26, _bf14, s, _bf2, _bf27, _bf19, &_bf55, &_bf54, &y, &x);
       #pragma omp parallel sections
       {
           #pragma omp section
               path51(_bf55, &_bf56);
           #pragma omp section
               path55(_bf54, &_bf64, &_bf63);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path54(_bf64, &_bf65);
           #pragma omp section
               path58(_bf63, &_bf73, &_bf72);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path57(_bf73, &_bf74);
           #pragma omp section
               path61(_bf72, &_bf82, &_bf81);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path60(_bf82, &_bf83);
           #pragma omp section
               path63(_bf81, &_bf90, &_bf89);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path64(_bf90, &_bf92);
           #pragma omp section
               path67(_bf109, _bf105, _bf89, &_bf110, &_bf107, &_bf99);
       }
       path0(_bf99, &_bf101);
       path65(_bf110, _bf104, _bf101, _bf95, _bf92, _bf1, _bf86, &_bf112);
       path50(_bf287, _bf270, _bf283, _bf271, _bf254, _bf267, _bf280, _bf279, _bf264, _bf275, _bf259, _bf215, _bf238, _bf220, _bf225, _bf184, _bf207, _bf189, _bf194, _bf153, _bf176, _bf158, _bf163, _bf145, _bf255, _bf246, _bf127, _bf112, _bf247, _bf132, _bf107, _bf83, _bf77, _bf74, _bf68, _bf65, _bf59, _bf56, _bf0, &_bf322, &_bf290, &_bf277, &_bf244, &_bf243);
       #pragma omp parallel sections
       {
           #pragma omp section
               path21(_bf244, _bf243, &_bf1);
           #pragma omp section
               path40(_bf277, &_bf294, &_bf293);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path41(_bf299, _bf290, _bf296, _bf294, &_bf300);
           #pragma omp section
               path46(_bf293, &_bf306, &_bf0);
       }
       path47(_bf308, _bf306, &_bf336);
       path38(_bf336, _bf302, _bf300, _bf322, &s);

    }
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    if (!onlyTimeOutput) {
           cout << "\n_bf0: ";
       for(int i = 0; i < 4 * DATA_SIZE; i++) {
           cout << _bf0_arr[i] << " ";
       }
       cout << "\n_bf1: ";
       for(int i = 0; i < 4 * DATA_SIZE; i++) {
           cout << _bf1_arr[i] << " ";
       }
       cout << "\ns: ";
       for(int i = 0; i < 5 * DATA_SIZE; i++) {
           cout << s_arr[i] << " ";
       }
       cout << "\nx: ";
       for(int i = 0; i < 4 * DATA_SIZE; i++) {
           cout << x_arr[i] << " ";
       }
       cout << "\ny: ";
       for(int i = 0; i < 4 * DATA_SIZE; i++) {
           cout << y_arr[i] << " ";
       }
    }
}