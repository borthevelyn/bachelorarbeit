#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int _bf156, int _bf174, int _bf165, int* _bf260, int* _bf175, int* _bf152, int* _bf170, int* _bf161, int* _bf137, int* _bf134, int* _bf128, int* _bf125, int* _bf101, int* _bf98, int* _bf92, int* _bf89, int* _bf65, int* _bf62, int* _bf140, int* _bf47, int* _bf44, int* _bf104, int* _bf113, int* _bf38, int* _bf35, int* _bf77, int* _bf68, int** y, int** x, int* _bf839, int* _bf50, int* _bf851) { 
    int _bf0 = 0;
    int _bf16 = 0;
    int _bf3 = (*x)[_bf0];
    int* _bf2 = (*x);
    int _bf4 = 1;
    int _bf19 = (*y)[_bf16];
    int* _bf18 = (*y);
    int _bf20 = 1;
    int _bf32 = _bf3;
    int _bf856 = _bf3;
    int _bf7 = _bf2[_bf4];
    int* _bf6 = _bf2;
    int _bf8 = 2;
    int _bf33 = _bf19;
    *_bf851 = _bf19;
    int _bf23 = _bf18[_bf20];
    int* _bf22 = _bf18;
    int _bf24 = 2;
    int _bf41 = _bf856;
    int _bf844 = _bf856;
    int _bf12 = 3;
    int _bf28 = 3;
    *_bf50 = _bf7;
    int _bf838 = _bf7;
    int _bf11 = _bf6[_bf8];
    int* _bf10 = _bf6;
    int _bf34 = _bf32 * _bf33;
    int _bf42 = _bf23;
    *_bf839 = _bf23;
    int _bf27 = _bf22[_bf24];
    int* _bf26 = _bf22;
    int _bf59 = _bf844;
    int _bf86 = _bf844;
    int _bf15 = _bf10[_bf12];
    *x = _bf10;
    int _bf31 = _bf26[_bf28];
    *y = _bf26;
    *_bf68 = _bf838;
    int _bf821 = _bf838;
    *_bf77 = _bf11;
    int _bf815 = _bf11;
    *_bf35 = _bf34;
    *_bf38 = _bf34;
    int _bf43 = _bf41 * _bf42;
    int _bf60 = _bf27;
    int _bf822 = _bf27;
    int _bf669 = _bf86;
    *_bf113 = _bf15;
    int _bf794 = _bf15;
    int _bf87 = _bf31;
    int _bf805 = _bf31;
    int _bf95 = _bf821;
    int _bf122 = _bf821;
    *_bf104 = _bf815;
    int _bf799 = _bf815;
    *_bf44 = _bf43;
    *_bf47 = _bf43;
    int _bf61 = _bf59 * _bf60;
    int _bf96 = _bf822;
    int _bf800 = _bf822;
    int _bf88 = _bf669 * _bf87;
    *_bf140 = _bf794;
    int _bf784 = _bf794;
    int _bf123 = _bf805;
    int _bf789 = _bf805;
    int _bf9 = _bf122;
    int _bf131 = _bf799;
    int _bf149 = _bf799;
    *_bf62 = _bf61;
    *_bf65 = _bf61;
    int _bf132 = _bf800;
    int _bf159 = _bf800;
    int _bf97 = _bf95 * _bf96;
    *_bf89 = _bf88;
    *_bf92 = _bf88;
    int _bf158 = _bf784;
    int _bf167 = _bf784;
    int _bf150 = _bf789;
    int _bf168 = _bf789;
    int _bf124 = _bf9 * _bf123;
    int _bf25 = _bf149;
    int _bf133 = _bf131 * _bf132;
    *_bf98 = _bf97;
    *_bf101 = _bf97;
    int _bf188 = _bf159;
    int _bf160 = _bf158 * _bf188;
    int _bf169 = _bf167 * _bf168;
    *_bf125 = _bf124;
    *_bf128 = _bf124;
    int _bf151 = _bf25 * _bf150;
    *_bf134 = _bf133;
    *_bf137 = _bf133;
    *_bf161 = _bf160;
    int _bf164 = _bf160;
    *_bf170 = _bf169;
    int _bf173 = _bf169;
    *_bf152 = _bf151;
    int _bf155 = _bf151;
    int _bf166 = _bf164 % _bf165;
    *_bf175 = _bf173 % _bf174;
    int _bf157 = _bf155 % _bf156;
    *_bf260 = _bf166 + _bf157;
}
void path1(int _bf94, int _bf101, int* _bf216) { 
    int _bf102 = 256;
    int _bf103 = _bf101 % _bf102;
    *_bf216 = _bf103 + _bf94;
}
void path2(int _bf107, int* _bf109) { 
    int _bf108 = 256;
    *_bf109 = _bf107 / _bf108;
}
void path3(int* _bf111) { 
    *_bf111 = 256;
}
void path4(int _bf109, int _bf116, int* _bf238) { 
    int _bf117 = 256;
    int _bf118 = _bf116 / _bf117;
    *_bf238 = _bf118 + _bf109;
}
void path5(int _bf183, int _bf112, int _bf119, int* _bf184, int* _bf179) { 
    int _bf120 = 256;
    int _bf121 = _bf119 % _bf120;
    int _bf178 = _bf121 + _bf112;
    *_bf179 = _bf178;
    int _bf182 = _bf178;
    *_bf184 = _bf182 % _bf183;
}
void path6(int _bf256, int _bf192, int _bf136, int _bf125, int* _bf269, int* _bf252) { 
    int _bf126 = 256;
    int _bf127 = _bf125 / _bf126;
    int _bf249 = _bf136 + _bf127;
    int _bf258 = _bf249;
    int _bf259 = _bf258;
    int _bf261 = _bf259;
    int _bf251 = _bf261 + _bf192;
    *_bf252 = _bf251;
    int _bf255 = _bf251;
    int _bf257 = _bf255 % _bf256;
    *_bf269 = _bf257;
}
void path7(int _bf194, int _bf187, int _bf128, int* _bf195, int* _bf190) { 
    int _bf129 = 256;
    int _bf130 = _bf128 % _bf129;
    int _bf13 = _bf130;
    int _bf189 = _bf187 + _bf13;
    *_bf190 = _bf189;
    int _bf193 = _bf189;
    *_bf195 = _bf193 % _bf194;
}
void path8(int _bf134, int* _bf136) { 
    int _bf135 = 256;
    *_bf136 = _bf134 / _bf135;
}
void path9(int _bf148, int _bf137, int* _bf187) { 
    int _bf138 = 256;
    int _bf139 = _bf137 % _bf138;
    *_bf187 = _bf148 + _bf139;
}
void path10(int _bf267, int _bf260, int _bf143, int* _bf299, int* _bf263) { 
    int _bf144 = 256;
    int _bf145 = _bf143 / _bf144;
    int _bf17 = _bf145;
    int _bf21 = _bf17;
    int _bf262 = _bf260 + _bf21;
    *_bf263 = _bf262;
    int _bf266 = _bf262;
    int _bf268 = _bf266 % _bf267;
    int _bf287 = _bf268;
    int _bf288 = _bf287;
    int _bf290 = _bf288;
    int _bf298 = _bf290;
    *_bf299 = _bf298;
}
void path11(int _bf146, int* _bf148) { 
    int _bf147 = 256;
    *_bf148 = _bf146 % _bf147;
}
void path12(int _bf279, int _bf254, int _bf152, int* _bf328, int* _bf325) { 
    int _bf153 = 256;
    int _bf154 = _bf152 / _bf153;
    int _bf29 = _bf154;
    int _bf30 = _bf29;
    int _bf176 = _bf30;
    int _bf177 = _bf176;
    int _bf185 = _bf177;
    int _bf186 = _bf185;
    int _bf322 = _bf186 + _bf254;
    int _bf324 = _bf322 + _bf279;
    *_bf325 = _bf324;
    *_bf328 = _bf324;
}
void path13(int* _bf156) { 
    *_bf156 = 256;
}
void path14(int _bf175, int _bf161, int* _bf275, int* _bf272) { 
    int _bf162 = 256;
    int _bf163 = _bf161 / _bf162;
    int _bf271 = _bf175 + _bf163;
    *_bf272 = _bf271;
    *_bf275 = _bf271;
}
void path15(int* _bf165) { 
    *_bf165 = 256;
}
void path16(int _bf170, int* _bf205) { 
    int _bf171 = 256;
    int _bf172 = _bf170 / _bf171;
    int _bf196 = _bf172;
    int _bf197 = _bf196;
    *_bf205 = _bf197;
}
void path17(int* _bf174) { 
    *_bf174 = 256;
}
void path18(int _bf234, int _bf195, int _bf672, int _bf179, int* _bf235, int* _bf230) { 
    int _bf180 = 256;
    int _bf181 = _bf179 / _bf180;
    int _bf227 = _bf672 + _bf181;
    int _bf226 = _bf227;
    int _bf229 = _bf226 + _bf195;
    *_bf230 = _bf229;
    int _bf233 = _bf229;
    *_bf235 = _bf233 % _bf234;
}
void path19(int* _bf183) { 
    *_bf183 = 256;
}
void path20(int _bf190, int* _bf192) { 
    int _bf191 = 256;
    *_bf192 = _bf190 / _bf191;
}
void path21(int* _bf194) { 
    *_bf194 = 256;
}
void path22(int _bf225, int _bf184, int _bf199, int* _bf295, int* _bf292) { 
    int _bf200 = 256;
    int _bf201 = _bf199 / _bf200;
    int _bf206 = _bf201;
    int _bf289 = _bf184 + _bf206;
    int _bf291 = _bf289 + _bf225;
    *_bf292 = _bf291;
    *_bf295 = _bf291;
}
void path23(int* _bf203) { 
    *_bf203 = 256;
}
void path24(int _bf235, int _bf221, int _bf208, int* _bf306, int* _bf303) { 
    int _bf209 = 256;
    int _bf210 = _bf208 / _bf209;
    int _bf214 = _bf210;
    int _bf215 = _bf214;
    int _bf300 = _bf215 + _bf221;
    int _bf341 = _bf300;
    int _bf343 = _bf341;
    int _bf351 = _bf343;
    int _bf302 = _bf351 + _bf235;
    *_bf303 = _bf302;
    *_bf306 = _bf302;
}
void path25(int* _bf212) { 
    *_bf212 = 256;
}
void path26(int _bf219, int* _bf221) { 
    int _bf220 = 256;
    *_bf221 = _bf219 / _bf220;
}
void path27(int* _bf223) { 
    *_bf223 = 256;
}
void path28(int _bf230, int* _bf232) { 
    int _bf231 = 256;
    *_bf232 = _bf230 / _bf231;
}
void path29(int* _bf234) { 
    *_bf234 = 256;
}
void path30(int _bf269, int _bf232, int _bf241, int* _bf317, int* _bf314) { 
    int _bf242 = 256;
    int _bf243 = _bf241 / _bf242;
    int _bf228 = _bf243;
    int _bf236 = _bf228;
    int _bf237 = _bf236;
    int _bf239 = _bf237;
    int _bf311 = _bf232 + _bf239;
    int _bf313 = _bf311 + _bf269;
    *_bf314 = _bf313;
    *_bf317 = _bf313;
}
void path31(int* _bf245) { 
    *_bf245 = 256;
}
void path32(int _bf252, int* _bf254) { 
    int _bf253 = 256;
    *_bf254 = _bf252 / _bf253;
}
void path33(int* _bf256) { 
    *_bf256 = 256;
}
void path34(int _bf263, int* _bf279) { 
    int _bf264 = 256;
    int _bf265 = _bf263 / _bf264;
    int _bf270 = _bf265;
    int _bf278 = _bf270;
    *_bf279 = _bf278;
}
void path35(int* _bf267) { 
    *_bf267 = 256;
}
void path36(int _bf205, int _bf272, int* _bf424) { 
    int _bf273 = 256;
    int _bf274 = _bf272 / _bf273;
    int _bf397 = _bf205 + _bf274;
    int _bf416 = _bf397;
    int _bf418 = _bf416;
    int _bf419 = _bf418;
    int _bf421 = _bf419;
    int _bf422 = _bf421;
    *_bf424 = _bf422;
}
void path37(int _bf275, int* _bf323) { 
    int _bf276 = 256;
    int _bf277 = _bf275 % _bf276;
    int _bf301 = _bf277;
    int _bf309 = _bf301;
    int _bf310 = _bf309;
    int _bf312 = _bf310;
    int _bf320 = _bf312;
    int _bf321 = _bf320;
    *_bf323 = _bf321;
}
void path38(int _bf224, int _bf281, int* _bf395) { 
    int _bf282 = 256;
    int _bf283 = _bf281 / _bf282;
    int _bf331 = _bf283;
    int _bf332 = _bf331;
    int _bf353 = _bf224 + _bf332;
    int _bf387 = _bf353;
    *_bf395 = _bf387;
}
void path39(int _bf284, int* _bf340) { 
    int _bf285 = 256;
    int _bf286 = _bf284 % _bf285;
    *_bf340 = _bf286;
}
void path40(int _bf250, int _bf292, int* _bf406) { 
    int _bf293 = 256;
    int _bf294 = _bf292 / _bf293;
    int _bf364 = _bf250 + _bf294;
    int _bf402 = _bf364;
    int _bf403 = _bf402;
    *_bf406 = _bf403;
}
void path41(int _bf395, int _bf295, int* _bf359, int* _bf356) { 
    int _bf296 = 256;
    int _bf297 = _bf295 % _bf296;
    int _bf355 = _bf395 + _bf297;
    *_bf356 = _bf355;
    *_bf359 = _bf355;
}
void path42(int _bf299, int _bf303, int* _bf375) { 
    int _bf304 = 256;
    int _bf305 = _bf303 / _bf304;
    *_bf375 = _bf299 + _bf305;
}
void path43(int _bf406, int _bf306, int* _bf370, int* _bf367) { 
    int _bf307 = 256;
    int _bf308 = _bf306 % _bf307;
    int _bf366 = _bf406 + _bf308;
    *_bf367 = _bf366;
    *_bf370 = _bf366;
}
void path44(int _bf352, int _bf323, int _bf314, int* _bf392, int* _bf389) { 
    int _bf315 = 256;
    int _bf316 = _bf314 / _bf315;
    int _bf386 = _bf323 + _bf316;
    int _bf388 = _bf386 + _bf352;
    *_bf389 = _bf388;
    *_bf392 = _bf388;
}
void path45(int _bf375, int _bf317, int* _bf381, int* _bf378) { 
    int _bf318 = 256;
    int _bf319 = _bf317 % _bf318;
    int _bf377 = _bf375 + _bf319;
    *_bf378 = _bf377;
    *_bf381 = _bf377;
}
void path46(int _bf404, int _bf424, int _bf325, int* _bf430) { 
    int _bf326 = 256;
    int _bf327 = _bf325 / _bf326;
    int _bf399 = _bf424 + _bf327;
    int _bf405 = _bf399 % _bf404;
    int _bf425 = _bf405;
    *_bf430 = _bf425;
}
void path47(int _bf328, int* _bf352) { 
    int _bf329 = 256;
    int _bf330 = _bf328 % _bf329;
    *_bf352 = _bf330;
}
void path48(int _bf334, int* _bf373) { 
    int _bf335 = 256;
    int _bf336 = _bf334 / _bf335;
    int _bf354 = _bf336;
    int _bf362 = _bf354;
    int _bf363 = _bf362;
    int _bf365 = _bf363;
    *_bf373 = _bf365;
}
void path49(int _bf413, int _bf337, int* _bf685, int* _bf428) { 
    int _bf338 = 256;
    int _bf339 = _bf337 % _bf338;
    int _bf408 = _bf413 + _bf339;
    *_bf428 = _bf408;
    *_bf685 = _bf408;
}
void path50(int _bf345, int* _bf385) { 
    int _bf346 = 256;
    int _bf347 = _bf345 / _bf346;
    int _bf374 = _bf347;
    int _bf376 = _bf374;
    int _bf384 = _bf376;
    *_bf385 = _bf384;
}
void path51(int _bf598, int _bf630, int _bf373, int _bf348, int* _bf599, int* _bf436, int* _bf434) { 
    int _bf349 = 256;
    int _bf350 = _bf348 % _bf349;
    int _bf411 = _bf373 + _bf350;
    *_bf434 = _bf411;
    int _bf682 = _bf411;
    *_bf436 = _bf682;
    int _bf579 = _bf682;
    int _bf584 = _bf579 + _bf630;
    *_bf599 = _bf584 % _bf598;
}
void path52(int _bf356, int* _bf401) { 
    int _bf357 = 256;
    int _bf358 = _bf356 / _bf357;
    int _bf396 = _bf358;
    int _bf398 = _bf396;
    int _bf400 = _bf398;
    *_bf401 = _bf400;
}
void path53(int _bf35, int* _bf413) { 
    int _bf36 = 256;
    int _bf37 = _bf35 / _bf36;
    int _bf409 = _bf37;
    int _bf410 = _bf409;
    int _bf412 = _bf410;
    *_bf413 = _bf412;
}
void path54(int _bf385, int _bf359, int* _bf621, int* _bf442, int* _bf440) { 
    int _bf360 = 256;
    int _bf361 = _bf359 % _bf360;
    int _bf414 = _bf385 + _bf361;
    *_bf440 = _bf414;
    int _bf680 = _bf414;
    *_bf442 = _bf680;
    int _bf573 = _bf680;
    int _bf618 = _bf573;
    *_bf621 = _bf618;
}
void path55(int _bf367, int* _bf407) { 
    int _bf368 = 256;
    int _bf369 = _bf367 / _bf368;
    *_bf407 = _bf369;
}
void path56(int _bf401, int _bf370, int* _bf615, int* _bf448, int* _bf446) { 
    int _bf371 = 256;
    int _bf372 = _bf370 % _bf371;
    int _bf417 = _bf401 + _bf372;
    *_bf446 = _bf417;
    int _bf678 = _bf417;
    *_bf448 = _bf678;
    int _bf567 = _bf678;
    *_bf615 = _bf567;
}
void path57(int _bf378, int* _bf415) { 
    int _bf379 = 256;
    int _bf380 = _bf378 / _bf379;
    *_bf415 = _bf380;
}
void path58(int _bf407, int _bf381, int* _bf612, int* _bf454, int* _bf452) { 
    int _bf382 = 256;
    int _bf383 = _bf381 % _bf382;
    int _bf420 = _bf407 + _bf383;
    *_bf452 = _bf420;
    int _bf676 = _bf420;
    *_bf454 = _bf676;
    int _bf561 = _bf676;
    int _bf594 = _bf561;
    int _bf597 = _bf594;
    int _bf600 = _bf597;
    int _bf603 = _bf600;
    int _bf606 = _bf603;
    int _bf609 = _bf606;
    *_bf612 = _bf609;
}
void path59(int* p, int _bf585, int _bf38, int** _bf636) { 
    int _bf39 = 256;
    int _bf40 = _bf38 % _bf39;
    p[_bf585] = _bf40;
    int* _bf589 = p;
    int* _bf631 = _bf589;
    int* _bf632 = _bf631;
    int* _bf633 = _bf632;
    int* _bf634 = _bf633;
    int* _bf635 = _bf634;
    *_bf636 = _bf635;
}
void path60(int _bf430, int _bf389, int* _bf469) { 
    int _bf390 = 256;
    int _bf391 = _bf389 / _bf390;
    int _bf426 = _bf391 + _bf430;
    int _bf431 = _bf426;
    int _bf432 = _bf431;
    int _bf463 = _bf432;
    int _bf464 = _bf463;
    int _bf465 = _bf464;
    int _bf466 = _bf465;
    int _bf467 = _bf466;
    int _bf468 = _bf467;
    *_bf469 = _bf468;
}
void path61(int _bf415, int _bf392, int* _bf591, int* _bf460, int* _bf458) { 
    int _bf393 = 256;
    int _bf394 = _bf392 % _bf393;
    int _bf423 = _bf415 + _bf394;
    *_bf458 = _bf423;
    int _bf674 = _bf423;
    *_bf460 = _bf674;
    int _bf555 = _bf674;
    int _bf549 = _bf555;
    int _bf550 = _bf549;
    int _bf556 = _bf550;
    int _bf568 = _bf556;
    int _bf586 = _bf568;
    int _bf587 = _bf586;
    int _bf588 = _bf587;
    *_bf591 = _bf588;
}
void path62(int* _bf404) { 
    *_bf404 = 256;
}
void path63(int _bf428, bool* _bf509, bool* _bf580) { 
    int _bf427 = 255;
    bool _bf429 = _bf427 < _bf428;
    bool _bf470 = _bf429;
    *_bf580 = _bf429;
    bool _bf504 = _bf470;
    bool _bf506 = _bf504;
    bool _bf507 = _bf506;
    bool _bf508 = _bf507;
    *_bf509 = _bf508;
}
void path64(int _bf434, bool* _bf474) { 
    int _bf433 = 255;
    bool _bf435 = _bf433 < _bf434;
    bool _bf472 = _bf435;
    *_bf474 = _bf472;
}
void path65(int _bf622, int _bf628, int _bf591, int _bf469, int _bf558, int _bf557, int _bf552, int _bf551, bool _bf666, bool _bf496, bool _bf526, bool _bf480, int _bf460, bool _bf522, int _bf610, int _bf615, int _bf452, int _bf448, int _bf570, int _bf569, bool _bf648, int _bf440, bool _bf474, bool _bf509, int _bf436, int* _bf662, int* _bf623, bool* _bf562, int* _bf611, bool* _bf574) { 
    int _bf437 = 255;
    bool _bf438 = _bf436 == _bf437;
    bool _bf471 = _bf438 && _bf509;
    bool _bf473 = _bf471 || _bf474;
    int _bf439 = 255;
    bool _bf494 = _bf473;
    bool _bf647 = _bf473;
    bool _bf441 = _bf439 < _bf440;
    bool _bf518 = _bf647;
    *_bf574 = _bf647;
    bool _bf478 = _bf441;
    bool _bf520 = _bf441;
    bool _bf528 = _bf494;
    bool _bf539 = _bf518;
    bool _bf510 = _bf478;
    bool _bf529 = _bf528;
    bool _bf540 = _bf520;
    bool _bf519 = _bf648 && _bf539;
    bool _bf511 = _bf510;
    bool _bf530 = _bf529;
    bool _bf541 = _bf540;
    bool _bf521 = _bf519 || _bf541;
    bool _bf512 = _bf511;
    int _bf449 = 255;
    bool _bf531 = _bf530;
    int _bf451 = 255;
    int _bf571;
    if ( _bf521 ) {
        _bf571 = _bf569;
    } else  { 
        _bf571 = _bf570;
    } 
    bool _bf513 = _bf512;
    bool _bf450 = _bf448 == _bf449;
    bool _bf532 = _bf531;
    bool _bf453 = _bf451 < _bf452;
    int _bf572 = _bf615 + _bf571;
    bool _bf514 = _bf513;
    bool _bf477 = _bf450;
    bool _bf482 = _bf450;
    bool _bf533 = _bf532;
    bool _bf486 = _bf453;
    bool _bf536 = _bf453;
    int _bf461 = 255;
    *_bf611 = _bf572 % _bf610;
    bool _bf479 = _bf477 && _bf514;
    bool _bf484 = _bf482 && _bf522;
    bool _bf538 = _bf533;
    bool _bf523 = _bf486;
    bool _bf462 = _bf460 == _bf461;
    bool _bf542 = _bf536;
    bool _bf481 = _bf479 || _bf480;
    bool _bf495 = _bf484 && _bf538;
    bool _bf524 = _bf523;
    bool _bf485 = _bf462;
    bool _bf490 = _bf462;
    bool _bf543 = _bf542;
    bool _bf497 = _bf495 || _bf481;
    bool _bf487 = _bf485 && _bf524;
    bool _bf492 = _bf490 && _bf526;
    bool _bf544 = _bf543;
    bool _bf502 = _bf497;
    bool _bf641 = _bf497;
    bool _bf489 = _bf487 || _bf496;
    bool _bf527 = _bf492;
    bool _bf545 = _bf544;
    bool _bf534 = _bf641;
    *_bf562 = _bf641;
    bool _bf525 = _bf489;
    bool _bf503 = _bf527 && _bf502;
    bool _bf546 = _bf545;
    bool _bf535 = _bf666 && _bf534;
    bool _bf505 = _bf503 || _bf525;
    bool _bf547 = _bf546;
    bool _bf537 = _bf535 || _bf547;
    int _bf553;
    if ( _bf505 ) {
        _bf553 = _bf551;
    } else  { 
        _bf553 = _bf552;
    } 
    int _bf559;
    if ( _bf537 ) {
        _bf559 = _bf557;
    } else  { 
        _bf559 = _bf558;
    } 
    int _bf554 = _bf469 + _bf553;
    int _bf560 = _bf591 + _bf559;
    int _bf629 = _bf554 % _bf628;
    *_bf623 = _bf560 % _bf622;
    int _bf661 = _bf629;
    *_bf662 = _bf661;
}
void path66(int _bf442, bool* _bf522, bool* _bf648) { 
    int _bf443 = 255;
    bool _bf444 = _bf442 == _bf443;
    bool _bf483 = _bf444;
    *_bf648 = _bf444;
    bool _bf515 = _bf483;
    bool _bf516 = _bf515;
    bool _bf517 = _bf516;
    *_bf522 = _bf517;
}
void path67(int _bf446, bool* _bf480) { 
    int _bf445 = 255;
    bool _bf447 = _bf445 < _bf446;
    bool _bf475 = _bf447;
    bool _bf476 = _bf475;
    *_bf480 = _bf476;
}
void path68(int _bf340, int _bf204, int _bf44, int* _bf348, int* _bf345) { 
    int _bf45 = 256;
    int _bf46 = _bf44 / _bf45;
    int _bf498 = _bf46;
    int _bf499 = _bf498;
    int _bf500 = _bf499;
    int _bf501 = _bf500;
    int _bf342 = _bf501 + _bf204;
    int _bf344 = _bf342 + _bf340;
    *_bf345 = _bf344;
    *_bf348 = _bf344;
}
void path69(int _bf454, bool* _bf526, bool* _bf642) { 
    int _bf455 = 255;
    bool _bf456 = _bf454 == _bf455;
    bool _bf491 = _bf456;
    *_bf642 = _bf456;
    *_bf526 = _bf491;
}
void path70(int _bf458, bool* _bf496) { 
    int _bf457 = 255;
    bool _bf459 = _bf457 < _bf458;
    bool _bf488 = _bf459;
    bool _bf493 = _bf488;
    *_bf496 = _bf493;
}
void path71(int _bf58, int _bf47, int* _bf337, int* _bf334) { 
    int _bf48 = 256;
    int _bf49 = _bf47 % _bf48;
    int _bf333 = _bf58 + _bf49;
    *_bf334 = _bf333;
    *_bf337 = _bf333;
}
void path72(int _bf53, int* _bf548) { 
    int _bf54 = 256;
    int _bf55 = _bf53 / _bf54;
    *_bf548 = _bf55;
}
void path73(int* _bf551) { 
    *_bf551 = 1;
}
void path74(int* _bf552) { 
    *_bf552 = 0;
}
void path75(int* _bf557) { 
    *_bf557 = 1;
}
void path76(int* _bf558) { 
    *_bf558 = 0;
}
void path77(int _bf616, int _bf612, int _bf564, bool _bf562, int* _bf617) { 
    int _bf563 = 1;
    int _bf565;
    if ( _bf562 ) {
        _bf565 = _bf563;
    } else  { 
        _bf565 = _bf564;
    } 
    int _bf566 = _bf612 + _bf565;
    *_bf617 = _bf566 % _bf616;
}
void path78(int* _bf564) { 
    *_bf564 = 0;
}
void path79(int* _bf569) { 
    *_bf569 = 1;
}
void path80(int _bf56, int* _bf58) { 
    int _bf57 = 256;
    *_bf58 = _bf56 % _bf57;
}
void path81(int* _bf570) { 
    *_bf570 = 0;
}
void path82(int _bf604, int _bf621, int _bf576, bool _bf574, int* _bf605) { 
    int _bf575 = 1;
    int _bf577;
    if ( _bf574 ) {
        _bf577 = _bf575;
    } else  { 
        _bf577 = _bf576;
    } 
    int _bf578 = _bf621 + _bf577;
    *_bf605 = _bf578 % _bf604;
}
void path83(int* _bf576) { 
    *_bf576 = 0;
}
void path84(int _bf582, bool _bf580, int* _bf630) { 
    int _bf581 = 1;
    int _bf583;
    if ( _bf580 ) {
        _bf583 = _bf581;
    } else  { 
        _bf583 = _bf582;
    } 
    int _bf624 = _bf583;
    int _bf627 = _bf624;
    *_bf630 = _bf627;
}
void path85(int* _bf582) { 
    *_bf582 = 0;
}
void path86(int* _bf585) { 
    *_bf585 = 0;
}
void path87(int _bf593, int* _bf636, int** _bf644) { 
    int _bf590 = 1;
    _bf636[_bf590] = _bf593;
    int* _bf595 = _bf636;
    int* _bf637 = _bf595;
    int* _bf638 = _bf637;
    int* _bf639 = _bf638;
    int* _bf640 = _bf639;
    int* _bf643 = _bf640;
    *_bf644 = _bf643;
}
void path88(int _bf685, int* _bf593) { 
    int _bf592 = 256;
    *_bf593 = _bf685 % _bf592;
}
void path89(int _bf599, int* _bf644, int** _bf651) { 
    int _bf596 = 2;
    _bf644[_bf596] = _bf599;
    int* _bf601 = _bf644;
    int* _bf645 = _bf601;
    int* _bf646 = _bf645;
    int* _bf649 = _bf646;
    int* _bf650 = _bf649;
    *_bf651 = _bf650;
}
void path90(int* _bf598) { 
    *_bf598 = 256;
}
void path91(int _bf605, int* _bf651, int** _bf653) { 
    int _bf602 = 3;
    _bf651[_bf602] = _bf605;
    int* _bf607 = _bf651;
    int* _bf652 = _bf607;
    *_bf653 = _bf652;
}
void path92(int* _bf604) { 
    *_bf604 = 256;
}
void path93(int _bf611, int* _bf653, int** _bf659) { 
    int _bf608 = 4;
    _bf653[_bf608] = _bf611;
    int* _bf613 = _bf653;
    int* _bf654 = _bf613;
    int* _bf655 = _bf654;
    int* _bf656 = _bf655;
    int* _bf657 = _bf656;
    int* _bf658 = _bf657;
    *_bf659 = _bf658;
}
void path94(int* _bf610) { 
    *_bf610 = 256;
}
void path95(int _bf617, int* _bf659, int** _bf660) { 
    int _bf614 = 5;
    _bf659[_bf614] = _bf617;
    int* _bf619 = _bf659;
    *_bf660 = _bf619;
}
void path96(int* _bf616) { 
    *_bf616 = 256;
}
void path97(int _bf662, int _bf626, int _bf623, int* _bf660, int** p) { 
    int _bf620 = 6;
    _bf660[_bf620] = _bf623;
    int* _bf625 = _bf660;
    _bf625[_bf626] = _bf662;
    *p = _bf625;
}
void path98(int* _bf622) { 
    *_bf622 = 256;
}
void path99(int* _bf626) { 
    *_bf626 = 7;
}
void path100(int* _bf628) { 
    *_bf628 = 256;
}
void path101(int _bf212, int _bf73, int _bf62, int* _bf225, int* _bf208) { 
    int _bf63 = 256;
    int _bf64 = _bf62 / _bf63;
    int _bf207 = _bf73 + _bf64;
    *_bf208 = _bf207;
    int _bf211 = _bf207;
    int _bf213 = _bf211 % _bf212;
    int _bf217 = _bf213;
    *_bf225 = _bf217;
}
void path102(int _bf548, int _bf65, int* _bf284, int* _bf281) { 
    int _bf66 = 256;
    int _bf67 = _bf65 % _bf66;
    int _bf280 = _bf67 + _bf548;
    *_bf281 = _bf280;
    *_bf284 = _bf280;
}
void path103(int _bf71, int* _bf73) { 
    int _bf72 = 256;
    *_bf73 = _bf71 / _bf72;
}
void path104(int _bf203, int _bf85, int _bf74, int* _bf204, int* _bf199) { 
    int _bf75 = 256;
    int _bf76 = _bf74 % _bf75;
    int _bf198 = _bf85 + _bf76;
    *_bf199 = _bf198;
    int _bf202 = _bf198;
    *_bf204 = _bf202 % _bf203;
}
void path105(int _bf223, int _bf216, int _bf80, int* _bf224, int* _bf219) { 
    int _bf81 = 256;
    int _bf82 = _bf80 / _bf81;
    int _bf667 = _bf82;
    int _bf668 = _bf667;
    int _bf218 = _bf216 + _bf668;
    *_bf219 = _bf218;
    int _bf222 = _bf218;
    *_bf224 = _bf222 % _bf223;
}
void path106(int _bf83, int* _bf85) { 
    int _bf84 = 256;
    *_bf85 = _bf83 % _bf84;
}
void path107(int _bf89, int* _bf672) { 
    int _bf90 = 256;
    int _bf91 = _bf89 / _bf90;
    int _bf670 = _bf91;
    int _bf671 = _bf670;
    *_bf672 = _bf671;
}
void path108(int _bf92, int* _bf94) { 
    int _bf93 = 256;
    *_bf94 = _bf92 % _bf93;
}
void path109(int _bf245, int _bf238, int _bf98, int* _bf250, int* _bf241) { 
    int _bf99 = 256;
    int _bf100 = _bf98 / _bf99;
    int _bf1 = _bf100;
    int _bf240 = _bf238 + _bf1;
    *_bf241 = _bf240;
    int _bf244 = _bf240;
    int _bf246 = _bf244 % _bf245;
    int _bf247 = _bf246;
    int _bf248 = _bf247;
    *_bf250 = _bf248;
}
void path110(int _bf111, int _bf104, int _bf816, int* _bf112, int* _bf107, int* _bf141) { 
    int _bf105 = _bf816;
    *_bf141 = _bf816;
    int _bf106 = _bf104 * _bf105;
    *_bf107 = _bf106;
    int _bf110 = _bf106;
    *_bf112 = _bf110 % _bf111;
}
void path111(int _bf50, int _bf851, int* _bf56, int* _bf53, int* _bf833) { 
    int _bf51 = _bf851;
    *_bf833 = _bf851;
    int _bf52 = _bf50 * _bf51;
    *_bf53 = _bf52;
    *_bf56 = _bf52;
}
void path112(int _bf68, int _bf839, int* _bf74, int* _bf71, int* _bf816) { 
    int _bf69 = _bf839;
    *_bf816 = _bf839;
    int _bf70 = _bf68 * _bf69;
    *_bf71 = _bf70;
    *_bf74 = _bf70;
}
void path113(int _bf77, int _bf833, int* _bf83, int* _bf80, int* _bf114) { 
    int _bf78 = _bf833;
    *_bf114 = _bf833;
    int _bf79 = _bf77 * _bf78;
    *_bf80 = _bf79;
    *_bf83 = _bf79;
}
void path114(int _bf113, int _bf114, int* _bf119, int* _bf116) { 
    int _bf5 = _bf114;
    int _bf115 = _bf113 * _bf5;
    *_bf116 = _bf115;
    *_bf119 = _bf115;
}
void path115(int _bf140, int _bf141, int* _bf146, int* _bf143) { 
    int _bf14 = _bf141;
    int _bf142 = _bf140 * _bf14;
    *_bf143 = _bf142;
    *_bf146 = _bf142;
}
void path116(bool _bf642, bool* _bf666) { 
    bool _bf663 = _bf642;
    bool _bf664 = _bf663;
    bool _bf665 = _bf664;
    *_bf666 = _bf665;
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

    int* p_arr = new int[8 * DATA_SIZE];
    int* x_arr = new int[4 * DATA_SIZE];
    int* y_arr = new int[4 * DATA_SIZE];
    auto start = chrono::steady_clock::now();
    #pragma omp parallel for 
    for (int i = 0; i < DATA_SIZE; i++) {
       int _bf111;
       int _bf156;
       int _bf165;
       int _bf174;
       int _bf183;
       int _bf194;
       int _bf203;
       int _bf212;
       int _bf223;
       int _bf234;
       int _bf245;
       int _bf256;
       int _bf267;
       int _bf404;
       int _bf551;
       int _bf552;
       int _bf557;
       int _bf558;
       int _bf564;
       int _bf569;
       int _bf570;
       int _bf576;
       int _bf582;
       int _bf585;
       int _bf598;
       int _bf604;
       int _bf610;
       int _bf616;
       int _bf622;
       int _bf626;
       int _bf628;
       int _bf260;
       int _bf175;
       int _bf152;
       int _bf170;
       int _bf161;
       int _bf137;
       int _bf134;
       int _bf128;
       int _bf125;
       int _bf101;
       int _bf98;
       int _bf92;
       int _bf89;
       int _bf65;
       int _bf62;
       int _bf140;
       int _bf47;
       int _bf44;
       int _bf104;
       int _bf113;
       int _bf38;
       int _bf35;
       int _bf77;
       int _bf68;
       int* y = y_arr + i * 4;
       int* x = x_arr + i * 4;
       int _bf839;
       int _bf50;
       int _bf851;
       int _bf136;
       int _bf275;
       int _bf272;
       int _bf205;
       int _bf413;
       int* _bf636;
       int _bf672;
       int _bf94;
       int _bf56;
       int _bf53;
       int _bf833;
       int _bf74;
       int _bf71;
       int _bf816;
       int _bf216;
       int _bf424;
       int _bf323;
       int _bf548;
       int _bf58;
       int _bf73;
       int _bf112;
       int _bf107;
       int _bf141;
       int _bf83;
       int _bf80;
       int _bf114;
       int _bf109;
       int _bf337;
       int _bf334;
       int _bf225;
       int _bf208;
       int _bf284;
       int _bf281;
       int _bf224;
       int _bf219;
       int _bf85;
       int _bf119;
       int _bf116;
       int _bf146;
       int _bf143;
       int _bf238;
       int _bf184;
       int _bf179;
       int _bf299;
       int _bf263;
       int _bf148;
       int _bf221;
       int _bf395;
       int _bf340;
       int _bf373;
       int _bf685;
       int _bf428;
       int _bf204;
       int _bf199;
       int _bf187;
       int _bf295;
       int _bf292;
       int _bf279;
       bool _bf509;
       bool _bf580;
       int _bf348;
       int _bf345;
       int _bf593;
       int _bf250;
       int _bf241;
       int _bf195;
       int _bf190;
       int _bf406;
       int _bf359;
       int _bf356;
       int _bf385;
       int _bf630;
       int* _bf644;
       int _bf235;
       int _bf230;
       int _bf192;
       int _bf599;
       int _bf436;
       int _bf434;
       int _bf401;
       int _bf621;
       int _bf442;
       int _bf440;
       int _bf269;
       int _bf252;
       int _bf306;
       int _bf303;
       int _bf232;
       bool _bf474;
       bool _bf522;
       bool _bf648;
       int* _bf651;
       int _bf317;
       int _bf314;
       int _bf254;
       int _bf375;
       int _bf370;
       int _bf367;
       int _bf328;
       int _bf325;
       int _bf381;
       int _bf378;
       int _bf407;
       int _bf615;
       int _bf448;
       int _bf446;
       int _bf430;
       int _bf352;
       int _bf415;
       int _bf612;
       int _bf454;
       int _bf452;
       bool _bf480;
       int _bf392;
       int _bf389;
       bool _bf526;
       bool _bf642;
       int _bf469;
       int _bf591;
       int _bf460;
       int _bf458;
       bool _bf666;
       bool _bf496;
       int _bf662;
       int _bf623;
       bool _bf562;
       int _bf611;
       bool _bf574;
       int _bf617;
       int _bf605;
       int* _bf653;
       int* _bf659;
       int* _bf660;
       int* p = p_arr + i * 8;

               path3(&_bf111);
               path13(&_bf156);
               path15(&_bf165);
               path17(&_bf174);
               path19(&_bf183);
               path21(&_bf194);
               path23(&_bf203);
               path25(&_bf212);
               path27(&_bf223);
               path29(&_bf234);
               path31(&_bf245);
               path33(&_bf256);
               path35(&_bf267);
               path62(&_bf404);
               path73(&_bf551);
               path74(&_bf552);
               path75(&_bf557);
               path76(&_bf558);
               path78(&_bf564);
               path79(&_bf569);
               path81(&_bf570);
               path83(&_bf576);
               path85(&_bf582);
               path86(&_bf585);
               path90(&_bf598);
               path92(&_bf604);
               path94(&_bf610);
               path96(&_bf616);
               path98(&_bf622);
               path99(&_bf626);
               path100(&_bf628);
       path0(_bf156, _bf174, _bf165, &_bf260, &_bf175, &_bf152, &_bf170, &_bf161, &_bf137, &_bf134, &_bf128, &_bf125, &_bf101, &_bf98, &_bf92, &_bf89, &_bf65, &_bf62, &_bf140, &_bf47, &_bf44, &_bf104, &_bf113, &_bf38, &_bf35, &_bf77, &_bf68, &y, &x, &_bf839, &_bf50, &_bf851);
               path8(_bf134, &_bf136);
               path14(_bf175, _bf161, &_bf275, &_bf272);
               path16(_bf170, &_bf205);
               path53(_bf35, &_bf413);
               path59(p, _bf585, _bf38, &_bf636);
               path107(_bf89, &_bf672);
               path108(_bf92, &_bf94);
               path111(_bf50, _bf851, &_bf56, &_bf53, &_bf833);
               path112(_bf68, _bf839, &_bf74, &_bf71, &_bf816);
               path1(_bf94, _bf101, &_bf216);
               path36(_bf205, _bf272, &_bf424);
               path37(_bf275, &_bf323);
               path72(_bf53, &_bf548);
               path80(_bf56, &_bf58);
               path103(_bf71, &_bf73);
               path110(_bf111, _bf104, _bf816, &_bf112, &_bf107, &_bf141);
               path113(_bf77, _bf833, &_bf83, &_bf80, &_bf114);
               path2(_bf107, &_bf109);
               path71(_bf58, _bf47, &_bf337, &_bf334);
               path101(_bf212, _bf73, _bf62, &_bf225, &_bf208);
               path102(_bf548, _bf65, &_bf284, &_bf281);
               path105(_bf223, _bf216, _bf80, &_bf224, &_bf219);
               path106(_bf83, &_bf85);
               path114(_bf113, _bf114, &_bf119, &_bf116);
               path115(_bf140, _bf141, &_bf146, &_bf143);
               path4(_bf109, _bf116, &_bf238);
               path5(_bf183, _bf112, _bf119, &_bf184, &_bf179);
               path10(_bf267, _bf260, _bf143, &_bf299, &_bf263);
               path11(_bf146, &_bf148);
               path26(_bf219, &_bf221);
               path38(_bf224, _bf281, &_bf395);
               path39(_bf284, &_bf340);
               path48(_bf334, &_bf373);
               path49(_bf413, _bf337, &_bf685, &_bf428);
               path104(_bf203, _bf85, _bf74, &_bf204, &_bf199);
               path9(_bf148, _bf137, &_bf187);
               path22(_bf225, _bf184, _bf199, &_bf295, &_bf292);
               path34(_bf263, &_bf279);
               path63(_bf428, &_bf509, &_bf580);
               path68(_bf340, _bf204, _bf44, &_bf348, &_bf345);
               path88(_bf685, &_bf593);
               path109(_bf245, _bf238, _bf98, &_bf250, &_bf241);
               path7(_bf194, _bf187, _bf128, &_bf195, &_bf190);
               path40(_bf250, _bf292, &_bf406);
               path41(_bf395, _bf295, &_bf359, &_bf356);
               path50(_bf345, &_bf385);
               path84(_bf582, _bf580, &_bf630);
               path87(_bf593, _bf636, &_bf644);
               path18(_bf234, _bf195, _bf672, _bf179, &_bf235, &_bf230);
               path20(_bf190, &_bf192);
               path51(_bf598, _bf630, _bf373, _bf348, &_bf599, &_bf436, &_bf434);
               path52(_bf356, &_bf401);
               path54(_bf385, _bf359, &_bf621, &_bf442, &_bf440);
               path6(_bf256, _bf192, _bf136, _bf125, &_bf269, &_bf252);
               path24(_bf235, _bf221, _bf208, &_bf306, &_bf303);
               path28(_bf230, &_bf232);
               path64(_bf434, &_bf474);
               path66(_bf442, &_bf522, &_bf648);
               path89(_bf599, _bf644, &_bf651);
               path30(_bf269, _bf232, _bf241, &_bf317, &_bf314);
               path32(_bf252, &_bf254);
               path42(_bf299, _bf303, &_bf375);
               path43(_bf406, _bf306, &_bf370, &_bf367);
               path12(_bf279, _bf254, _bf152, &_bf328, &_bf325);
               path45(_bf375, _bf317, &_bf381, &_bf378);
               path55(_bf367, &_bf407);
               path56(_bf401, _bf370, &_bf615, &_bf448, &_bf446);
               path46(_bf404, _bf424, _bf325, &_bf430);
               path47(_bf328, &_bf352);
               path57(_bf378, &_bf415);
               path58(_bf407, _bf381, &_bf612, &_bf454, &_bf452);
               path67(_bf446, &_bf480);
               path44(_bf352, _bf323, _bf314, &_bf392, &_bf389);
               path69(_bf454, &_bf526, &_bf642);
               path60(_bf430, _bf389, &_bf469);
               path61(_bf415, _bf392, &_bf591, &_bf460, &_bf458);
               path116(_bf642, &_bf666);
       path70(_bf458, &_bf496);
       path65(_bf622, _bf628, _bf591, _bf469, _bf558, _bf557, _bf552, _bf551, _bf666, _bf496, _bf526, _bf480, _bf460, _bf522, _bf610, _bf615, _bf452, _bf448, _bf570, _bf569, _bf648, _bf440, _bf474, _bf509, _bf436, &_bf662, &_bf623, &_bf562, &_bf611, &_bf574);
               path77(_bf616, _bf612, _bf564, _bf562, &_bf617);
               path82(_bf604, _bf621, _bf576, _bf574, &_bf605);
       path91(_bf605, _bf651, &_bf653);
       path93(_bf611, _bf653, &_bf659);
       path95(_bf617, _bf659, &_bf660);
       path97(_bf662, _bf626, _bf623, _bf660, &p);

    }
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    if (!onlyTimeOutput) {
           cout << "\np: ";
       for(int i = 0; i < 8 * DATA_SIZE; i++) {
           cout << p_arr[i] << " ";
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