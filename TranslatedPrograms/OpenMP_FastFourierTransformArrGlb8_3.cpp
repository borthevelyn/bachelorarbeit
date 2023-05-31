#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int _bf118, int* _bf89, int* _bf130, int* _bf127, int** _bf114) { 
    int _bf112 = 2;
    int _bf115 = _bf89[_bf112];
    *_bf114 = _bf89;
    int _bf167 = _bf115;
    int _bf168 = _bf167;
    int _bf169 = _bf168;
    int _bf172 = _bf169;
    int _bf173 = _bf172;
    int _bf174 = _bf173;
    int _bf177 = _bf174;
    int _bf178 = _bf177;
    int _bf179 = _bf178;
    int _bf182 = _bf179;
    int _bf119 = _bf182 * _bf118;
    *_bf127 = _bf119;
    *_bf130 = _bf119;
}
void path1(int* _bf114, int* _bf296, int** w) { 
    int _bf141 = 2;
    int _bf144 = _bf114[_bf141];
    *w = _bf114;
    int _bf275 = _bf144;
    int _bf276 = _bf275;
    int _bf277 = _bf276;
    int _bf278 = _bf277;
    int _bf279 = _bf278;
    int _bf280 = _bf279;
    int _bf281 = _bf280;
    int _bf282 = _bf281;
    int _bf283 = _bf282;
    int _bf284 = _bf283;
    int _bf285 = _bf284;
    int _bf286 = _bf285;
    int _bf287 = _bf286;
    int _bf288 = _bf287;
    int _bf289 = _bf288;
    int _bf290 = _bf289;
    int _bf291 = _bf290;
    int _bf292 = _bf291;
    int _bf293 = _bf292;
    int _bf294 = _bf293;
    int _bf295 = _bf294;
    *_bf296 = _bf295;
}
void path2(int* _bf161) { 
    *_bf161 = 0;
}
void path3(int* _bf166) { 
    *_bf166 = 1;
}
void path4(int* _bf171) { 
    *_bf171 = 2;
}
void path5(int* _bf176) { 
    *_bf176 = 3;
}
void path6(int* _bf181) { 
    *_bf181 = 4;
}
void path7(int* _bf186) { 
    *_bf186 = 5;
}
void path8(int* _bf191) { 
    *_bf191 = 6;
}
void path9(int* _bf196) { 
    *_bf196 = 7;
}
void path10(int* _bf48) { 
    *_bf48 = 4;
}
void path11(int _bf166, int _bf95, int _bf79, int _bf63, int* y, int _bf161, int _bf48, int* _bf5, int* _bf1, int* w, int** _bf170, int* _bf153, int* _bf146, int* _bf152, int** x, int* _bf139, int* _bf145, int* _bf138, int* _bf124, int* _bf117, int* _bf123, int* _bf110, int* _bf116, int* _bf109, int** _bf89) { 
    int _bf55 = 1;
    int _bf0 = 0;
    int _bf4 = 4;
    int _bf58 = w[_bf55];
    int* _bf57 = w;
    int _bf71 = 2;
    int _bf3 = _bf1[_bf0];
    int* _bf2 = _bf1;
    int _bf7 = _bf5[_bf4];
    int* _bf6 = _bf5;
    int _bf339 = _bf58;
    int _bf74 = _bf57[_bf71];
    int* _bf73 = _bf57;
    int _bf87 = 3;
    int _bf10 = _bf3 + _bf7;
    int* _bf9 = _bf6;
    int _bf340 = _bf339;
    int _bf356 = _bf74;
    int _bf90 = _bf73[_bf87];
    *_bf89 = _bf73;
    int _bf103 = _bf10;
    *_bf109 = _bf10;
    int _bf11 = 1;
    int _bf15 = 5;
    int* _bf12 = _bf9;
    int* _bf16 = _bf9;
    int _bf341 = _bf340;
    int _bf357 = _bf356;
    int _bf375 = _bf90;
    int _bf8 = _bf103;
    int _bf14 = _bf12[_bf11];
    int* _bf13 = _bf12;
    int _bf18 = _bf16[_bf15];
    int* _bf17 = _bf16;
    int _bf342 = _bf341;
    int _bf358 = _bf357;
    int _bf376 = _bf375;
    int _bf19 = _bf8;
    int _bf21 = _bf14 + _bf18;
    int* _bf20 = _bf17;
    int _bf343 = _bf342;
    int _bf359 = _bf358;
    int _bf377 = _bf376;
    int _bf30 = _bf19;
    int _bf106 = _bf21;
    *_bf116 = _bf21;
    int* _bf23 = _bf20;
    int* _bf27 = _bf20;
    int _bf22 = 2;
    int _bf26 = 6;
    int _bf344 = _bf343;
    int _bf360 = _bf359;
    int _bf378 = _bf377;
    int _bf41 = _bf30;
    int _bf67 = _bf106;
    int _bf25 = _bf23[_bf22];
    int* _bf24 = _bf23;
    int _bf29 = _bf27[_bf26];
    int* _bf28 = _bf27;
    int _bf345 = _bf344;
    int _bf361 = _bf360;
    int _bf379 = _bf378;
    int _bf52 = _bf41;
    int _bf72 = _bf67;
    int _bf32 = _bf25 + _bf29;
    int* _bf31 = _bf28;
    int _bf346 = _bf345;
    int _bf362 = _bf361;
    int _bf380 = _bf379;
    int _bf56 = _bf52;
    int _bf83 = _bf72;
    int _bf104 = _bf32;
    *_bf110 = _bf32;
    int* _bf34 = _bf31;
    int* _bf38 = _bf31;
    int _bf33 = 3;
    int _bf37 = 7;
    int _bf347 = _bf346;
    int _bf363 = _bf362;
    int _bf381 = _bf380;
    int _bf105 = _bf56 + _bf104;
    int _bf88 = _bf83;
    int _bf36 = _bf34[_bf33];
    int* _bf35 = _bf34;
    int _bf40 = _bf38[_bf37];
    int* _bf39 = _bf38;
    int _bf348 = _bf347;
    int _bf364 = _bf363;
    int _bf382 = _bf381;
    int _bf120 = _bf105;
    *_bf123 = _bf105;
    int _bf99 = _bf88;
    int _bf43 = _bf36 + _bf40;
    int* _bf42 = _bf39;
    int _bf349 = _bf348;
    int _bf365 = _bf364;
    int _bf383 = _bf382;
    int _bf193 = _bf120;
    int _bf100 = _bf99;
    int _bf107 = _bf43;
    *_bf117 = _bf43;
    int* _bf45 = _bf42;
    int* _bf49 = _bf42;
    int _bf44 = 0;
    int _bf350 = _bf349;
    int _bf366 = _bf365;
    int _bf384 = _bf383;
    int _bf194 = _bf193;
    int _bf108 = _bf100 + _bf107;
    int _bf51 = _bf49[_bf48];
    int* _bf50 = _bf49;
    int _bf47 = _bf45[_bf44];
    int* _bf46 = _bf45;
    int _bf351 = _bf350;
    int _bf367 = _bf366;
    int _bf385 = _bf384;
    int _bf197 = _bf194;
    int _bf121 = _bf108;
    *_bf124 = _bf108;
    int* _bf53 = _bf50;
    int _bf54 = _bf47 - _bf51;
    int _bf352 = _bf351;
    int _bf368 = _bf367;
    int _bf386 = _bf385;
    int _bf122 = _bf197 + _bf121;
    int* _bf60 = _bf53;
    int* _bf64 = _bf53;
    int _bf132 = _bf54;
    *_bf138 = _bf54;
    int _bf353 = _bf352;
    int _bf59 = 1;
    int _bf369 = _bf368;
    int _bf387 = _bf386;
    y[_bf161] = _bf122;
    int* _bf165 = y;
    int _bf66 = _bf64[_bf63];
    int* _bf65 = _bf64;
    int _bf255 = _bf132;
    int _bf354 = _bf353;
    int _bf62 = _bf60[_bf59];
    int* _bf61 = _bf60;
    int _bf370 = _bf369;
    int _bf388 = _bf387;
    int* _bf327 = _bf165;
    int* _bf68 = _bf65;
    int _bf256 = _bf255;
    int _bf355 = _bf354;
    int _bf69 = _bf62 - _bf66;
    int _bf371 = _bf370;
    int _bf389 = _bf388;
    int* _bf328 = _bf327;
    int* _bf76 = _bf68;
    int* _bf80 = _bf68;
    int _bf257 = _bf256;
    int _bf70 = _bf355 * _bf69;
    int _bf372 = _bf371;
    int _bf75 = 2;
    int _bf390 = _bf389;
    int* _bf329 = _bf328;
    int _bf82 = _bf80[_bf79];
    int* _bf81 = _bf80;
    int _bf258 = _bf257;
    int _bf135 = _bf70;
    *_bf145 = _bf70;
    int _bf373 = _bf372;
    int _bf78 = _bf76[_bf75];
    int* _bf77 = _bf76;
    int _bf391 = _bf390;
    int* _bf330 = _bf329;
    int* _bf84 = _bf81;
    int _bf259 = _bf258;
    int _bf262 = _bf135;
    int _bf374 = _bf373;
    int _bf85 = _bf78 - _bf82;
    int _bf392 = _bf391;
    int* _bf331 = _bf330;
    int* _bf92 = _bf84;
    int* _bf96 = _bf84;
    int _bf260 = _bf259;
    int _bf263 = _bf262;
    int _bf86 = _bf374 * _bf85;
    int _bf393 = _bf392;
    int _bf91 = 3;
    int* _bf332 = _bf331;
    int _bf98 = _bf96[_bf95];
    int* _bf97 = _bf96;
    int _bf261 = _bf260;
    int _bf264 = _bf263;
    int _bf133 = _bf86;
    *_bf139 = _bf86;
    int _bf394 = _bf393;
    int _bf94 = _bf92[_bf91];
    int* _bf93 = _bf92;
    int* _bf333 = _bf332;
    int _bf101 = _bf94 - _bf98;
    int _bf134 = _bf261 + _bf133;
    int _bf265 = _bf264;
    int _bf395 = _bf394;
    *x = _bf97;
    int* _bf334 = _bf333;
    int _bf102 = _bf395 * _bf101;
    int _bf149 = _bf134;
    *_bf152 = _bf134;
    int _bf266 = _bf265;
    int* _bf335 = _bf334;
    int _bf136 = _bf102;
    *_bf146 = _bf102;
    int _bf303 = _bf149;
    int _bf267 = _bf266;
    int* _bf336 = _bf335;
    int _bf304 = _bf303;
    int _bf137 = _bf267 + _bf136;
    int* _bf337 = _bf336;
    int _bf305 = _bf304;
    int _bf150 = _bf137;
    *_bf153 = _bf137;
    int* _bf338 = _bf337;
    int _bf151 = _bf305 + _bf150;
    _bf338[_bf166] = _bf151;
    *_bf170 = _bf338;
}
void path12(int* _bf63) { 
    *_bf63 = 5;
}
void path13(int* _bf79) { 
    *_bf79 = 6;
}
void path14(int* _bf95) { 
    *_bf95 = 7;
}
void path15(int* x, int** _bf5, int** _bf1) { 
    *_bf1 = x;
    *_bf5 = x;
}
void path16(int* _bf170, int _bf171, int _bf127, int _bf110, int _bf109, int** _bf175, int* _bf129) { 
    int _bf113 = _bf109;
    int _bf142 = _bf113;
    int _bf143 = _bf142;
    int _bf162 = _bf143;
    int _bf163 = _bf162;
    int _bf164 = _bf163;
    int _bf111 = _bf164 - _bf110;
    int _bf126 = _bf111;
    *_bf129 = _bf111;
    int _bf217 = _bf126;
    int _bf218 = _bf217;
    int _bf219 = _bf218;
    int _bf220 = _bf219;
    int _bf128 = _bf220 + _bf127;
    int _bf221 = _bf128;
    int _bf222 = _bf221;
    int _bf223 = _bf222;
    int _bf224 = _bf223;
    int _bf225 = _bf224;
    int _bf226 = _bf225;
    int _bf227 = _bf226;
    int _bf228 = _bf227;
    int _bf229 = _bf228;
    int _bf230 = _bf229;
    int _bf231 = _bf230;
    int _bf232 = _bf231;
    int _bf233 = _bf232;
    _bf170[_bf171] = _bf233;
    *_bf175 = _bf170;
}
void path17(int _bf117, int _bf116, int* _bf118) { 
    int _bf183 = _bf116;
    int _bf184 = _bf183;
    int _bf187 = _bf184;
    int _bf188 = _bf187;
    int _bf189 = _bf188;
    int _bf192 = _bf189;
    *_bf118 = _bf192 - _bf117;
}
void path18(int* _bf180, int _bf181, int _bf124, int _bf123, int** _bf185) { 
    int _bf198 = _bf123;
    int _bf199 = _bf198;
    int _bf200 = _bf199;
    int _bf125 = _bf200 - _bf124;
    int _bf201 = _bf125;
    int _bf202 = _bf201;
    int _bf203 = _bf202;
    int _bf204 = _bf203;
    int _bf205 = _bf204;
    int _bf206 = _bf205;
    int _bf207 = _bf206;
    int _bf208 = _bf207;
    int _bf209 = _bf208;
    int _bf210 = _bf209;
    int _bf211 = _bf210;
    int _bf212 = _bf211;
    int _bf213 = _bf212;
    int _bf214 = _bf213;
    int _bf215 = _bf214;
    int _bf216 = _bf215;
    _bf180[_bf181] = _bf216;
    *_bf185 = _bf180;
}
void path19(int* _bf190, int _bf191, int _bf130, int _bf129, int** _bf195) { 
    int _bf234 = _bf129;
    int _bf235 = _bf234;
    int _bf236 = _bf235;
    int _bf237 = _bf236;
    int _bf131 = _bf237 - _bf130;
    int _bf238 = _bf131;
    int _bf239 = _bf238;
    int _bf240 = _bf239;
    int _bf241 = _bf240;
    int _bf242 = _bf241;
    int _bf243 = _bf242;
    int _bf244 = _bf243;
    int _bf245 = _bf244;
    int _bf246 = _bf245;
    int _bf247 = _bf246;
    int _bf248 = _bf247;
    int _bf249 = _bf248;
    int _bf250 = _bf249;
    int _bf251 = _bf250;
    int _bf252 = _bf251;
    int _bf253 = _bf252;
    int _bf254 = _bf253;
    _bf190[_bf191] = _bf254;
    *_bf195 = _bf190;
}
void path20(int* _bf175, int _bf176, int _bf156, int _bf139, int _bf138, int** _bf180, int* _bf158) { 
    int _bf268 = _bf138;
    int _bf269 = _bf268;
    int _bf270 = _bf269;
    int _bf271 = _bf270;
    int _bf272 = _bf271;
    int _bf273 = _bf272;
    int _bf274 = _bf273;
    int _bf140 = _bf274 - _bf139;
    int _bf155 = _bf140;
    *_bf158 = _bf140;
    int _bf313 = _bf155;
    int _bf314 = _bf313;
    int _bf315 = _bf314;
    int _bf316 = _bf315;
    int _bf157 = _bf316 + _bf156;
    int _bf317 = _bf157;
    _bf175[_bf176] = _bf317;
    *_bf180 = _bf175;
}
void path21(int _bf296, int _bf146, int _bf145, int* _bf159, int* _bf156) { 
    int _bf297 = _bf145;
    int _bf298 = _bf297;
    int _bf299 = _bf298;
    int _bf300 = _bf299;
    int _bf301 = _bf300;
    int _bf302 = _bf301;
    int _bf147 = _bf302 - _bf146;
    int _bf148 = _bf296 * _bf147;
    *_bf156 = _bf148;
    *_bf159 = _bf148;
}
void path22(int* _bf185, int _bf186, int _bf153, int _bf152, int** _bf190) { 
    int _bf306 = _bf152;
    int _bf307 = _bf306;
    int _bf308 = _bf307;
    int _bf154 = _bf308 - _bf153;
    int _bf309 = _bf154;
    int _bf310 = _bf309;
    int _bf311 = _bf310;
    int _bf312 = _bf311;
    _bf185[_bf186] = _bf312;
    *_bf190 = _bf185;
}
void path23(int* _bf195, int _bf196, int _bf159, int _bf158, int** y) { 
    int _bf318 = _bf158;
    int _bf319 = _bf318;
    int _bf320 = _bf319;
    int _bf321 = _bf320;
    int _bf160 = _bf321 - _bf159;
    int _bf322 = _bf160;
    int _bf323 = _bf322;
    int _bf324 = _bf323;
    int _bf325 = _bf324;
    int _bf326 = _bf325;
    _bf195[_bf196] = _bf326;
    *y = _bf195;
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

    int* w_arr = new int[8 * DATA_SIZE];
    int* x_arr = new int[8 * DATA_SIZE];
    int* y_arr = new int[8 * DATA_SIZE];
    auto start = chrono::steady_clock::now();
    #pragma omp parallel for 
    for (int i = 0; i < DATA_SIZE; i++) {
       int _bf161;
       int _bf166;
       int _bf171;
       int _bf176;
       int _bf181;
       int _bf186;
       int _bf191;
       int _bf196;
       int _bf48;
       int _bf63;
       int _bf79;
       int _bf95;
       int* _bf5;
       int* _bf1;
       int* _bf170;
       int _bf153;
       int _bf146;
       int _bf152;
       int* x = x_arr + i * 8;
       int _bf139;
       int _bf145;
       int _bf138;
       int _bf124;
       int _bf117;
       int _bf123;
       int _bf110;
       int _bf116;
       int _bf109;
       int* _bf89;
       int _bf118;
       int _bf130;
       int _bf127;
       int* _bf114;
       int _bf296;
       int* w = w_arr + i * 8;
       int* _bf175;
       int _bf129;
       int _bf159;
       int _bf156;
       int* _bf180;
       int _bf158;
       int* _bf185;
       int* _bf190;
       int* _bf195;
       int* y = y_arr + i * 8;

               path2(&_bf161);
               path3(&_bf166);
               path4(&_bf171);
               path5(&_bf176);
               path6(&_bf181);
               path7(&_bf186);
               path8(&_bf191);
               path9(&_bf196);
               path10(&_bf48);
               path12(&_bf63);
               path13(&_bf79);
               path14(&_bf95);
               path15(x, &_bf5, &_bf1);
       path11(_bf166, _bf95, _bf79, _bf63, y, _bf161, _bf48, _bf5, _bf1, w, &_bf170, &_bf153, &_bf146, &_bf152, &x, &_bf139, &_bf145, &_bf138, &_bf124, &_bf117, &_bf123, &_bf110, &_bf116, &_bf109, &_bf89);
       path17(_bf117, _bf116, &_bf118);
       path0(_bf118, _bf89, &_bf130, &_bf127, &_bf114);
               path1(_bf114, &_bf296, &w);
               path16(_bf170, _bf171, _bf127, _bf110, _bf109, &_bf175, &_bf129);
       path21(_bf296, _bf146, _bf145, &_bf159, &_bf156);
       path20(_bf175, _bf176, _bf156, _bf139, _bf138, &_bf180, &_bf158);
       path18(_bf180, _bf181, _bf124, _bf123, &_bf185);
       path22(_bf185, _bf186, _bf153, _bf152, &_bf190);
       path19(_bf190, _bf191, _bf130, _bf129, &_bf195);
       path23(_bf195, _bf196, _bf159, _bf158, &y);

    }
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    if (!onlyTimeOutput) {
           cout << "\nw: ";
       for(int i = 0; i < 8 * DATA_SIZE; i++) {
           cout << w_arr[i] << " ";
       }
       cout << "\nx: ";
       for(int i = 0; i < 8 * DATA_SIZE; i++) {
           cout << x_arr[i] << " ";
       }
       cout << "\ny: ";
       for(int i = 0; i < 8 * DATA_SIZE; i++) {
           cout << y_arr[i] << " ";
       }
    }
}