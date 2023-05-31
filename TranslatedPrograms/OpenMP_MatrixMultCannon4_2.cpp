#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int _bf187, int _bf178, int _bf168, int _bf152, int _bf154, int* c_1_0) { 
    int _bf159 = _bf154 * _bf152;
    int _bf160 = *c_1_0 + _bf159;
    int _bf169 = _bf160 + _bf168;
    int _bf179 = _bf169 + _bf178;
    *c_1_0 = _bf179 + _bf187;
}
void path1(int _bf161, int _bf163, int* _bf168) { 
    *_bf168 = _bf163 * _bf161;
}
void path2(int _bf171, int _bf173, int* _bf178) { 
    *_bf178 = _bf173 * _bf171;
}
void path3(int _bf225, int _bf216, int _bf206, int _bf190, int _bf192, int* c_1_1) { 
    int _bf197 = _bf192 * _bf190;
    int _bf198 = *c_1_1 + _bf197;
    int _bf207 = _bf198 + _bf206;
    int _bf217 = _bf207 + _bf216;
    *c_1_1 = _bf217 + _bf225;
}
void path4(int _bf199, int _bf201, int* _bf206) { 
    *_bf206 = _bf201 * _bf199;
}
void path5(int _bf209, int _bf211, int* _bf216) { 
    *_bf216 = _bf211 * _bf209;
}
void path6(int _bf263, int _bf254, int _bf244, int _bf228, int _bf230, int* c_1_2) { 
    int _bf235 = _bf230 * _bf228;
    int _bf236 = *c_1_2 + _bf235;
    int _bf245 = _bf236 + _bf244;
    int _bf255 = _bf245 + _bf254;
    *c_1_2 = _bf255 + _bf263;
}
void path7(int _bf237, int _bf239, int* _bf244) { 
    *_bf244 = _bf239 * _bf237;
}
void path8(int _bf247, int _bf249, int* _bf254) { 
    *_bf254 = _bf249 * _bf247;
}
void path9(int _bf19, int _bf21, int* _bf26) { 
    *_bf26 = _bf21 * _bf19;
}
void path10(int _bf339, int _bf330, int _bf320, int _bf304, int _bf306, int* c_2_0) { 
    int _bf311 = _bf306 * _bf304;
    int _bf312 = *c_2_0 + _bf311;
    int _bf321 = _bf312 + _bf320;
    int _bf331 = _bf321 + _bf330;
    *c_2_0 = _bf331 + _bf339;
}
void path11(int _bf313, int _bf315, int* _bf320) { 
    *_bf320 = _bf315 * _bf313;
}
void path12(int _bf323, int _bf325, int* _bf330) { 
    *_bf330 = _bf325 * _bf323;
}
void path13(int _bf377, int _bf368, int _bf358, int _bf342, int _bf344, int* c_2_1) { 
    int _bf349 = _bf344 * _bf342;
    int _bf350 = *c_2_1 + _bf349;
    int _bf359 = _bf350 + _bf358;
    int _bf369 = _bf359 + _bf368;
    *c_2_1 = _bf369 + _bf377;
}
void path14(int _bf351, int _bf353, int* _bf358) { 
    *_bf358 = _bf353 * _bf351;
}
void path15(int _bf361, int _bf363, int* _bf368) { 
    *_bf368 = _bf363 * _bf361;
}
void path16(int _bf415, int _bf406, int _bf396, int _bf380, int _bf382, int* c_2_2) { 
    int _bf387 = _bf382 * _bf380;
    int _bf388 = *c_2_2 + _bf387;
    int _bf397 = _bf388 + _bf396;
    int _bf407 = _bf397 + _bf406;
    *c_2_2 = _bf407 + _bf415;
}
void path17(int _bf389, int _bf391, int* _bf396) { 
    *_bf396 = _bf391 * _bf389;
}
void path18(int _bf399, int _bf401, int* _bf406) { 
    *_bf406 = _bf401 * _bf399;
}
void path19(int c_0_1, int _bf38, int _bf40, int* _bf46) { 
    int _bf45 = _bf40 * _bf38;
    *_bf46 = c_0_1 + _bf45;
}
void path20(int _bf64, int _bf46, int _bf47, int _bf49, int* _bf227) { 
    int _bf54 = _bf49 * _bf47;
    int _bf55 = _bf46 + _bf54;
    int _bf65 = _bf55 + _bf64;
    *_bf227 = _bf65;
}
void path21(int _bf605, int _bf596, int _bf586, int _bf570, int _bf572, int* c_3_3) { 
    int _bf577 = _bf572 * _bf570;
    int _bf578 = *c_3_3 + _bf577;
    int _bf587 = _bf578 + _bf586;
    int _bf597 = _bf587 + _bf596;
    *c_3_3 = _bf597 + _bf605;
}
void path22(int _bf35, int _bf26, int _bf16, int _bf0, int _bf2, int* c_0_0) { 
    int _bf7 = _bf2 * _bf0;
    int _bf8 = *c_0_0 + _bf7;
    int _bf17 = _bf8 + _bf16;
    int _bf27 = _bf17 + _bf26;
    int _bf50 = _bf27;
    *c_0_0 = _bf50 + _bf35;
}
void path23(int _bf92, int c_0_2, int _bf76, int _bf78, int* _bf93) { 
    int _bf83 = _bf78 * _bf76;
    int _bf84 = c_0_2 + _bf83;
    *_bf93 = _bf84 + _bf92;
}
void path24(int _bf11, int b_1_0, int* _bf16, int* _bf755, int* _bf0) { 
    *_bf0 = b_1_0;
    int _bf757 = b_1_0;
    int _bf9 = _bf757;
    *_bf755 = _bf757;
    *_bf16 = _bf11 * _bf9;
}
void path25(int _bf1, int _bf110, int _bf106, int* c_0_2, int* a_0_2) { 
    int _bf109 = _bf106;
    *a_0_2 = _bf106;
    int _bf3 = _bf109;
    int _bf111 = _bf3 * _bf110;
    *c_0_2 = _bf1 + _bf111;
}
void path26(int _bf756, int* _bf731, int* _bf116, int* a_0_0, int* _bf33, int* _bf21, int* _bf11) { 
    *_bf11 = _bf756;
    int _bf754 = _bf756;
    *_bf21 = _bf754;
    int _bf30 = _bf754;
    *_bf33 = _bf30;
    int _bf37 = _bf30;
    int _bf733 = _bf37;
    *a_0_0 = _bf37;
    *_bf116 = _bf733;
    *_bf731 = _bf733;
}
void path27(int b_1_3, int* b_3_3, int* _bf604, int* _bf589, int* _bf579, int* _bf570, int* _bf148, int* b_0_3, int* _bf133, int* _bf123, int* _bf114) { 
    *_bf114 = b_1_3;
    int _bf732 = b_1_3;
    *_bf123 = _bf732;
    int _bf730 = _bf732;
    *_bf133 = _bf730;
    int _bf142 = _bf730;
    int _bf727 = _bf142;
    *b_0_3 = _bf142;
    *_bf148 = _bf727;
    int _bf646 = _bf727;
    *_bf570 = _bf646;
    int _bf644 = _bf646;
    *_bf579 = _bf644;
    int _bf642 = _bf644;
    *_bf589 = _bf642;
    int _bf598 = _bf642;
    *_bf604 = _bf598;
    *b_3_3 = _bf598;
}
void path28(int _bf731, int* _bf729, int* _bf125) { 
    *_bf125 = _bf731;
    *_bf729 = _bf731;
}
void path29(int _bf729, int* _bf144, int* _bf135) { 
    *_bf135 = _bf729;
    *_bf144 = _bf729;
}
void path30(int _bf141, int _bf39, int _bf144, int* c_0_3, int* a_0_3) { 
    int _bf147 = _bf144;
    *a_0_3 = _bf144;
    int _bf149 = _bf147 * _bf39;
    *c_0_3 = _bf141 + _bf149;
}
void path31(int b_2_0, int* _bf724, int* _bf152) { 
    *_bf152 = b_2_0;
    *_bf724 = b_2_0;
}
void path32(int a_1_1, int* _bf723, int* _bf154) { 
    *_bf154 = a_1_1;
    *_bf723 = a_1_1;
}
void path33(int _bf185, int _bf724, int* _bf187, int* b_1_0, int* _bf171, int* _bf161) { 
    *_bf161 = _bf724;
    int _bf722 = _bf724;
    *_bf171 = _bf722;
    int _bf180 = _bf722;
    int _bf186 = _bf180;
    *b_1_0 = _bf180;
    *_bf187 = _bf185 * _bf186;
}
void path34(int _bf77, int _bf723, int* _bf301, int* a_1_3, int* _bf287, int* _bf277, int* _bf268, int* a_1_0, int* _bf185, int* _bf173, int* _bf163) { 
    *_bf163 = _bf723;
    int _bf721 = _bf723;
    *_bf173 = _bf721;
    int _bf182 = _bf721;
    *_bf185 = _bf182;
    int _bf189 = _bf182;
    int _bf703 = _bf189;
    *a_1_0 = _bf189;
    *_bf268 = _bf703;
    int _bf701 = _bf703;
    *_bf277 = _bf701;
    int _bf699 = _bf701;
    *_bf287 = _bf699;
    int _bf296 = _bf699;
    int _bf299 = _bf296;
    *a_1_3 = _bf296;
    *_bf301 = _bf299 * _bf77;
}
void path35(int _bf151, int _bf755, int* _bf491, int* b_3_0, int* _bf475, int* _bf465, int* _bf456, int* _bf34, int* b_0_0, int* _bf19) { 
    *_bf19 = _bf755;
    int _bf28 = _bf755;
    int _bf752 = _bf28;
    *b_0_0 = _bf28;
    *_bf34 = _bf752;
    int _bf668 = _bf752;
    *_bf456 = _bf668;
    int _bf666 = _bf668;
    *_bf465 = _bf666;
    int _bf664 = _bf666;
    *_bf475 = _bf664;
    int _bf484 = _bf664;
    int _bf490 = _bf484;
    *b_3_0 = _bf484;
    *_bf491 = _bf151 * _bf490;
}
void path36(int b_2_1, int* b_1_1, int* _bf224, int* _bf209, int* _bf199, int* _bf190) { 
    *_bf190 = b_2_1;
    int _bf716 = b_2_1;
    *_bf199 = _bf716;
    int _bf714 = _bf716;
    *_bf209 = _bf714;
    int _bf218 = _bf714;
    *_bf224 = _bf218;
    *b_1_1 = _bf218;
}
void path37(int _bf224, int a_1_2, int* _bf225, int* a_1_1, int* _bf211, int* _bf201, int* _bf192) { 
    *_bf192 = a_1_2;
    int _bf715 = a_1_2;
    *_bf201 = _bf715;
    int _bf713 = _bf715;
    *_bf211 = _bf713;
    int _bf220 = _bf713;
    int _bf223 = _bf220;
    *a_1_1 = _bf220;
    *_bf225 = _bf223 * _bf224;
}
void path38(int a_0_1, int* _bf756, int* _bf2) { 
    *_bf2 = a_0_1;
    *_bf756 = a_0_1;
}
void path39(int b_2_2, int* b_1_2, int* _bf262, int* _bf247, int* _bf237, int* _bf228) { 
    *_bf228 = b_2_2;
    int _bf709 = b_2_2;
    *_bf237 = _bf709;
    int _bf707 = _bf709;
    *_bf247 = _bf707;
    int _bf256 = _bf707;
    *_bf262 = _bf256;
    *b_1_2 = _bf256;
}
void path40(int _bf262, int a_1_3, int* _bf263, int* a_1_2, int* _bf249, int* _bf239, int* _bf230) { 
    *_bf230 = a_1_3;
    int _bf708 = a_1_3;
    *_bf239 = _bf708;
    int _bf706 = _bf708;
    *_bf249 = _bf706;
    int _bf258 = _bf706;
    int _bf261 = _bf258;
    *a_1_2 = _bf258;
    *_bf263 = _bf261 * _bf262;
}
void path41(int b_2_3, int* _bf77, int* b_1_3, int* _bf285, int* _bf275, int* _bf266) { 
    *_bf266 = b_2_3;
    int _bf702 = b_2_3;
    *_bf275 = _bf702;
    int _bf700 = _bf702;
    *_bf285 = _bf700;
    int _bf294 = _bf700;
    int _bf300 = _bf294;
    *b_1_3 = _bf294;
    int _bf69 = _bf300;
    int _bf70 = _bf69;
    int _bf74 = _bf70;
    int _bf75 = _bf74;
    *_bf77 = _bf75;
}
void path42(int _bf337, int b_3_0, int* _bf339, int* b_2_0, int* _bf323, int* _bf313, int* _bf304) { 
    *_bf304 = b_3_0;
    int _bf695 = b_3_0;
    *_bf313 = _bf695;
    int _bf693 = _bf695;
    *_bf323 = _bf693;
    int _bf332 = _bf693;
    int _bf338 = _bf332;
    *b_2_0 = _bf332;
    *_bf339 = _bf337 * _bf338;
}
void path43(int _bf115, int a_2_1, int* _bf453, int* a_2_3, int* _bf439, int* _bf429, int* _bf420, int* a_2_0, int* _bf337, int* _bf325, int* _bf315, int* _bf306) { 
    *_bf306 = a_2_1;
    int _bf694 = a_2_1;
    *_bf315 = _bf694;
    int _bf692 = _bf694;
    *_bf325 = _bf692;
    int _bf334 = _bf692;
    *_bf337 = _bf334;
    int _bf341 = _bf334;
    int _bf674 = _bf341;
    *a_2_0 = _bf341;
    *_bf420 = _bf674;
    int _bf672 = _bf674;
    *_bf429 = _bf672;
    int _bf670 = _bf672;
    *_bf439 = _bf670;
    int _bf448 = _bf670;
    int _bf451 = _bf448;
    *a_2_3 = _bf448;
    *_bf453 = _bf451 * _bf115;
}
void path44(int b_3_1, int* b_2_1, int* _bf376, int* _bf361, int* _bf351, int* _bf342) { 
    *_bf342 = b_3_1;
    int _bf687 = b_3_1;
    *_bf351 = _bf687;
    int _bf685 = _bf687;
    *_bf361 = _bf685;
    int _bf370 = _bf685;
    *_bf376 = _bf370;
    *b_2_1 = _bf370;
}
void path45(int _bf376, int a_2_2, int* _bf377, int* a_2_1, int* _bf363, int* _bf353, int* _bf344) { 
    *_bf344 = a_2_2;
    int _bf686 = a_2_2;
    *_bf353 = _bf686;
    int _bf684 = _bf686;
    *_bf363 = _bf684;
    int _bf372 = _bf684;
    int _bf375 = _bf372;
    *a_2_1 = _bf372;
    *_bf377 = _bf375 * _bf376;
}
void path46(int _bf188, int b_1_1, int* _bf529, int* b_3_1, int* _bf513, int* _bf503, int* _bf494, int* _bf72, int* b_0_1, int* _bf57, int* _bf47, int* _bf38) { 
    *_bf38 = b_1_1;
    int _bf748 = b_1_1;
    *_bf47 = _bf748;
    int _bf746 = _bf748;
    *_bf57 = _bf746;
    int _bf66 = _bf746;
    int _bf743 = _bf66;
    *b_0_1 = _bf66;
    *_bf72 = _bf743;
    int _bf660 = _bf743;
    *_bf494 = _bf660;
    int _bf658 = _bf660;
    *_bf503 = _bf658;
    int _bf656 = _bf658;
    *_bf513 = _bf656;
    int _bf522 = _bf656;
    int _bf528 = _bf522;
    *b_3_1 = _bf522;
    *_bf529 = _bf188 * _bf528;
}
void path47(int b_3_2, int* b_2_2, int* _bf414, int* _bf399, int* _bf389, int* _bf380) { 
    *_bf380 = b_3_2;
    int _bf680 = b_3_2;
    *_bf389 = _bf680;
    int _bf678 = _bf680;
    *_bf399 = _bf678;
    int _bf408 = _bf678;
    *_bf414 = _bf408;
    *b_2_2 = _bf408;
}
void path48(int _bf414, int a_2_3, int* _bf415, int* a_2_2, int* _bf401, int* _bf391, int* _bf382) { 
    *_bf382 = a_2_3;
    int _bf679 = a_2_3;
    *_bf391 = _bf679;
    int _bf677 = _bf679;
    *_bf401 = _bf677;
    int _bf410 = _bf677;
    int _bf413 = _bf410;
    *a_2_2 = _bf410;
    *_bf415 = _bf413 * _bf414;
}
void path49(int a_0_2, int* _bf747, int* _bf40) { 
    *_bf40 = a_0_2;
    *_bf747 = a_0_2;
}
void path50(int b_3_3, int* _bf115, int* b_2_3, int* _bf437, int* _bf427, int* _bf418) { 
    *_bf418 = b_3_3;
    int _bf673 = b_3_3;
    *_bf427 = _bf673;
    int _bf671 = _bf673;
    *_bf437 = _bf671;
    int _bf446 = _bf671;
    int _bf452 = _bf446;
    *b_2_3 = _bf446;
    int _bf107 = _bf452;
    int _bf108 = _bf107;
    int _bf112 = _bf108;
    int _bf113 = _bf112;
    *_bf115 = _bf113;
}
void path51(int a_3_1, int* _bf643, int* _bf572, int* a_3_0, int* _bf489, int* _bf477, int* _bf467, int* _bf458) { 
    *_bf458 = a_3_1;
    int _bf665 = a_3_1;
    *_bf467 = _bf665;
    int _bf663 = _bf665;
    *_bf477 = _bf663;
    int _bf486 = _bf663;
    *_bf489 = _bf486;
    int _bf493 = _bf486;
    int _bf645 = _bf493;
    *a_3_0 = _bf493;
    *_bf572 = _bf645;
    *_bf643 = _bf645;
}
void path52(int _bf747, int* _bf745, int* _bf49) { 
    *_bf49 = _bf747;
    *_bf745 = _bf747;
}
void path53(int a_3_2, int* _bf188, int* a_3_1, int* _bf515, int* _bf505, int* _bf496) { 
    *_bf496 = a_3_2;
    int _bf657 = a_3_2;
    *_bf505 = _bf657;
    int _bf655 = _bf657;
    *_bf515 = _bf655;
    int _bf524 = _bf655;
    int _bf527 = _bf524;
    *a_3_1 = _bf524;
    int _bf177 = _bf527;
    int _bf181 = _bf177;
    int _bf183 = _bf181;
    int _bf184 = _bf183;
    *_bf188 = _bf184;
}
void path54(int a_3_3, int* _bf226, int* a_3_2, int* _bf553, int* _bf543, int* _bf534) { 
    *_bf534 = a_3_3;
    int _bf650 = a_3_3;
    *_bf543 = _bf650;
    int _bf648 = _bf650;
    *_bf553 = _bf648;
    int _bf562 = _bf648;
    int _bf565 = _bf562;
    *a_3_2 = _bf562;
    int _bf215 = _bf565;
    int _bf219 = _bf215;
    int _bf221 = _bf219;
    int _bf222 = _bf221;
    *_bf226 = _bf222;
}
void path55(int _bf579, int _bf643, int* _bf586, int* _bf641) { 
    int _bf581 = _bf643;
    *_bf641 = _bf643;
    *_bf586 = _bf581 * _bf579;
}
void path56(int _bf57, int _bf745, int* _bf64, int* _bf68) { 
    int _bf59 = _bf745;
    *_bf68 = _bf745;
    *_bf64 = _bf59 * _bf57;
}
void path57(int _bf589, int _bf641, int* _bf596, int* _bf600) { 
    int _bf591 = _bf641;
    *_bf600 = _bf641;
    *_bf596 = _bf591 * _bf589;
}
void path58(int _bf604, int _bf600, int* _bf605, int* a_3_3) { 
    int _bf603 = _bf600;
    *a_3_3 = _bf600;
    *_bf605 = _bf603 * _bf604;
}
void path59(int _bf227, int _bf72, int _bf68, int* c_0_1, int* a_0_1) { 
    int _bf71 = _bf68;
    *a_0_1 = _bf68;
    int _bf229 = _bf71;
    int _bf73 = _bf229 * _bf72;
    *c_0_1 = _bf227 + _bf73;
}
void path60(int _bf226, int b_1_2, int* _bf567, int* b_3_2, int* _bf551, int* _bf541, int* _bf532, int* _bf110, int* b_0_2, int* _bf95, int* _bf85, int* _bf76) { 
    *_bf76 = b_1_2;
    int _bf740 = b_1_2;
    *_bf85 = _bf740;
    int _bf738 = _bf740;
    *_bf95 = _bf738;
    int _bf104 = _bf738;
    int _bf735 = _bf104;
    *b_0_2 = _bf104;
    *_bf110 = _bf735;
    int _bf653 = _bf735;
    *_bf532 = _bf653;
    int _bf651 = _bf653;
    *_bf541 = _bf651;
    int _bf649 = _bf651;
    *_bf551 = _bf649;
    int _bf560 = _bf649;
    int _bf566 = _bf560;
    *b_3_2 = _bf560;
    *_bf567 = _bf226 * _bf566;
}
void path61(int a_0_3, int* _bf739, int* _bf78) { 
    *_bf78 = a_0_3;
    *_bf739 = a_0_3;
}
void path62(int _bf85, int _bf739, int* _bf92, int* _bf737) { 
    int _bf87 = _bf739;
    *_bf737 = _bf739;
    *_bf92 = _bf87 * _bf85;
}
void path63(int _bf93, int _bf95, int _bf737, int* _bf1, int* _bf106) { 
    int _bf97 = _bf737;
    *_bf106 = _bf737;
    int _bf102 = _bf97 * _bf95;
    int _bf103 = _bf93 + _bf102;
    *_bf1 = _bf103;
}
void path64(int _bf140, int _bf130, int c_0_3, int _bf116, int _bf114, int* _bf141) { 
    int _bf4 = _bf114;
    int _bf5 = _bf4;
    int _bf6 = _bf5;
    int _bf10 = _bf6;
    int _bf12 = _bf10;
    int _bf121 = _bf116 * _bf12;
    int _bf122 = c_0_3 + _bf121;
    int _bf131 = _bf122 + _bf130;
    *_bf141 = _bf131 + _bf140;
}
void path65(int _bf125, int _bf123, int* _bf130) { 
    int _bf13 = _bf123;
    int _bf14 = _bf13;
    int _bf15 = _bf14;
    int _bf18 = _bf15;
    int _bf20 = _bf18;
    *_bf130 = _bf125 * _bf20;
}
void path66(int _bf135, int _bf133, int* _bf140) { 
    int _bf22 = _bf133;
    int _bf23 = _bf22;
    int _bf24 = _bf23;
    int _bf25 = _bf24;
    int _bf29 = _bf25;
    *_bf140 = _bf135 * _bf29;
}
void path67(int _bf148, int* _bf39) { 
    int _bf31 = _bf148;
    int _bf32 = _bf31;
    int _bf36 = _bf32;
    *_bf39 = _bf36;
}
void path68(int _bf301, int _bf292, int _bf282, int _bf268, int _bf266, int* c_1_3) { 
    int _bf41 = _bf266;
    int _bf42 = _bf41;
    int _bf43 = _bf42;
    int _bf44 = _bf43;
    int _bf48 = _bf44;
    int _bf273 = _bf268 * _bf48;
    int _bf274 = *c_1_3 + _bf273;
    int _bf283 = _bf274 + _bf282;
    int _bf293 = _bf283 + _bf292;
    *c_1_3 = _bf293 + _bf301;
}
void path69(int _bf277, int _bf275, int* _bf282) { 
    int _bf51 = _bf275;
    int _bf52 = _bf51;
    int _bf53 = _bf52;
    int _bf56 = _bf53;
    int _bf58 = _bf56;
    *_bf282 = _bf277 * _bf58;
}
void path70(int _bf287, int _bf285, int* _bf292) { 
    int _bf60 = _bf285;
    int _bf61 = _bf60;
    int _bf62 = _bf61;
    int _bf63 = _bf62;
    int _bf67 = _bf63;
    *_bf292 = _bf287 * _bf67;
}
void path71(int _bf34, int _bf33, int* _bf35) { 
    int _bf79 = _bf33;
    *_bf35 = _bf79 * _bf34;
}
void path72(int _bf453, int _bf444, int _bf434, int _bf420, int _bf418, int* c_2_3) { 
    int _bf80 = _bf418;
    int _bf81 = _bf80;
    int _bf82 = _bf81;
    int _bf86 = _bf82;
    int _bf88 = _bf86;
    int _bf425 = _bf420 * _bf88;
    int _bf426 = *c_2_3 + _bf425;
    int _bf435 = _bf426 + _bf434;
    int _bf445 = _bf435 + _bf444;
    *c_2_3 = _bf445 + _bf453;
}
void path73(int _bf429, int _bf427, int* _bf434) { 
    int _bf89 = _bf427;
    int _bf90 = _bf89;
    int _bf91 = _bf90;
    int _bf94 = _bf91;
    int _bf96 = _bf94;
    *_bf434 = _bf429 * _bf96;
}
void path74(int _bf439, int _bf437, int* _bf444) { 
    int _bf98 = _bf437;
    int _bf99 = _bf98;
    int _bf100 = _bf99;
    int _bf101 = _bf100;
    int _bf105 = _bf101;
    *_bf444 = _bf439 * _bf105;
}
void path75(int _bf491, int _bf482, int _bf472, int _bf456, int _bf458, int* c_3_0) { 
    int _bf117 = _bf458;
    int _bf118 = _bf117;
    int _bf119 = _bf118;
    int _bf120 = _bf119;
    int _bf124 = _bf120;
    int _bf463 = _bf124 * _bf456;
    int _bf464 = *c_3_0 + _bf463;
    int _bf473 = _bf464 + _bf472;
    int _bf483 = _bf473 + _bf482;
    *c_3_0 = _bf483 + _bf491;
}
void path76(int _bf465, int _bf467, int* _bf472) { 
    int _bf126 = _bf467;
    int _bf127 = _bf126;
    int _bf128 = _bf127;
    int _bf129 = _bf128;
    int _bf132 = _bf129;
    *_bf472 = _bf132 * _bf465;
}
void path77(int _bf475, int _bf477, int* _bf482) { 
    int _bf134 = _bf477;
    int _bf136 = _bf134;
    int _bf137 = _bf136;
    int _bf138 = _bf137;
    int _bf139 = _bf138;
    *_bf482 = _bf139 * _bf475;
}
void path78(int _bf489, int* _bf151) { 
    int _bf143 = _bf489;
    int _bf145 = _bf143;
    int _bf146 = _bf145;
    int _bf150 = _bf146;
    *_bf151 = _bf150;
}
void path79(int _bf529, int _bf520, int _bf510, int _bf494, int _bf496, int* c_3_1) { 
    int _bf153 = _bf496;
    int _bf155 = _bf153;
    int _bf156 = _bf155;
    int _bf157 = _bf156;
    int _bf158 = _bf157;
    int _bf501 = _bf158 * _bf494;
    int _bf502 = *c_3_1 + _bf501;
    int _bf511 = _bf502 + _bf510;
    int _bf521 = _bf511 + _bf520;
    *c_3_1 = _bf521 + _bf529;
}
void path80(int _bf503, int _bf505, int* _bf510) { 
    int _bf162 = _bf505;
    int _bf164 = _bf162;
    int _bf165 = _bf164;
    int _bf166 = _bf165;
    int _bf167 = _bf166;
    *_bf510 = _bf167 * _bf503;
}
void path81(int _bf513, int _bf515, int* _bf520) { 
    int _bf170 = _bf515;
    int _bf172 = _bf170;
    int _bf174 = _bf172;
    int _bf175 = _bf174;
    int _bf176 = _bf175;
    *_bf520 = _bf176 * _bf513;
}
void path82(int _bf567, int _bf558, int _bf548, int _bf532, int _bf534, int* c_3_2) { 
    int _bf191 = _bf534;
    int _bf193 = _bf191;
    int _bf194 = _bf193;
    int _bf195 = _bf194;
    int _bf196 = _bf195;
    int _bf539 = _bf196 * _bf532;
    int _bf540 = *c_3_2 + _bf539;
    int _bf549 = _bf540 + _bf548;
    int _bf559 = _bf549 + _bf558;
    *c_3_2 = _bf559 + _bf567;
}
void path83(int _bf541, int _bf543, int* _bf548) { 
    int _bf200 = _bf543;
    int _bf202 = _bf200;
    int _bf203 = _bf202;
    int _bf204 = _bf203;
    int _bf205 = _bf204;
    *_bf548 = _bf205 * _bf541;
}
void path84(int _bf551, int _bf553, int* _bf558) { 
    int _bf208 = _bf553;
    int _bf210 = _bf208;
    int _bf212 = _bf210;
    int _bf213 = _bf212;
    int _bf214 = _bf213;
    *_bf558 = _bf214 * _bf551;
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


    int* inputs = new int[DATA_SIZE * 40 ]; 
    memset(inputs, 0, 40 * DATA_SIZE * sizeof(int));
    int* outputs = new int[DATA_SIZE * 48 ]; 
    auto start = chrono::steady_clock::now();
    #pragma omp parallel for 
    for (int i = 0; i < DATA_SIZE; i++) {
       int a_0_1 = inputs[i * 40 + 0];
       int a_0_2 = inputs[i * 40 + 1];
       int a_0_3 = inputs[i * 40 + 2];
       int a_1_1 = inputs[i * 40 + 3];
       int a_1_2 = inputs[i * 40 + 4];
       int a_1_3 = inputs[i * 40 + 5];
       int a_2_1 = inputs[i * 40 + 6];
       int a_2_2 = inputs[i * 40 + 7];
       int a_2_3 = inputs[i * 40 + 8];
       int a_3_1 = inputs[i * 40 + 9];
       int a_3_2 = inputs[i * 40 + 10];
       int a_3_3 = inputs[i * 40 + 11];
       int b_1_0 = inputs[i * 40 + 12];
       int b_1_1 = inputs[i * 40 + 13];
       int b_1_2 = inputs[i * 40 + 14];
       int b_1_3 = inputs[i * 40 + 15];
       int b_2_0 = inputs[i * 40 + 16];
       int b_2_1 = inputs[i * 40 + 17];
       int b_2_2 = inputs[i * 40 + 18];
       int b_2_3 = inputs[i * 40 + 19];
       int b_3_0 = inputs[i * 40 + 20];
       int b_3_1 = inputs[i * 40 + 21];
       int b_3_2 = inputs[i * 40 + 22];
       int b_3_3 = inputs[i * 40 + 23];
       int c_0_0 = inputs[i * 40 + 24];
       int c_0_1 = inputs[i * 40 + 25];
       int c_0_2 = inputs[i * 40 + 26];
       int c_0_3 = inputs[i * 40 + 27];
       int c_1_0 = inputs[i * 40 + 28];
       int c_1_1 = inputs[i * 40 + 29];
       int c_1_2 = inputs[i * 40 + 30];
       int c_1_3 = inputs[i * 40 + 31];
       int c_2_0 = inputs[i * 40 + 32];
       int c_2_1 = inputs[i * 40 + 33];
       int c_2_2 = inputs[i * 40 + 34];
       int c_2_3 = inputs[i * 40 + 35];
       int c_3_0 = inputs[i * 40 + 36];
       int c_3_1 = inputs[i * 40 + 37];
       int c_3_2 = inputs[i * 40 + 38];
       int c_3_3 = inputs[i * 40 + 39];
       int _bf604;
       int _bf589;
       int _bf579;
       int _bf570;
       int _bf148;
       int b_0_3;
       int _bf133;
       int _bf123;
       int _bf114;
       int _bf724;
       int _bf152;
       int _bf723;
       int _bf154;
       int _bf224;
       int _bf209;
       int _bf199;
       int _bf190;
       int _bf756;
       int _bf2;
       int _bf262;
       int _bf247;
       int _bf237;
       int _bf228;
       int _bf77;
       int _bf285;
       int _bf275;
       int _bf266;
       int _bf376;
       int _bf361;
       int _bf351;
       int _bf342;
       int _bf414;
       int _bf399;
       int _bf389;
       int _bf380;
       int _bf747;
       int _bf40;
       int _bf115;
       int _bf437;
       int _bf427;
       int _bf418;
       int _bf643;
       int _bf572;
       int a_3_0;
       int _bf489;
       int _bf477;
       int _bf467;
       int _bf458;
       int _bf188;
       int _bf515;
       int _bf505;
       int _bf496;
       int _bf226;
       int _bf553;
       int _bf543;
       int _bf534;
       int _bf739;
       int _bf78;
       int _bf731;
       int _bf116;
       int a_0_0;
       int _bf33;
       int _bf21;
       int _bf11;
       int _bf301;
       int _bf287;
       int _bf277;
       int _bf268;
       int a_1_0;
       int _bf185;
       int _bf173;
       int _bf163;
       int _bf225;
       int _bf211;
       int _bf201;
       int _bf192;
       int _bf263;
       int _bf249;
       int _bf239;
       int _bf230;
       int _bf453;
       int _bf439;
       int _bf429;
       int _bf420;
       int a_2_0;
       int _bf337;
       int _bf325;
       int _bf315;
       int _bf306;
       int _bf377;
       int _bf363;
       int _bf353;
       int _bf344;
       int _bf529;
       int _bf513;
       int _bf503;
       int _bf494;
       int _bf72;
       int b_0_1;
       int _bf57;
       int _bf47;
       int _bf38;
       int _bf415;
       int _bf401;
       int _bf391;
       int _bf382;
       int _bf745;
       int _bf49;
       int _bf586;
       int _bf641;
       int _bf567;
       int _bf551;
       int _bf541;
       int _bf532;
       int _bf110;
       int b_0_2;
       int _bf95;
       int _bf85;
       int _bf76;
       int _bf39;
       int _bf151;
       int _bf206;
       int _bf216;
       int _bf244;
       int _bf254;
       int _bf358;
       int _bf368;
       int _bf396;
       int _bf406;
       int _bf46;
       int _bf16;
       int _bf755;
       int _bf0;
       int _bf729;
       int _bf125;
       int _bf187;
       int _bf171;
       int _bf161;
       int _bf339;
       int _bf323;
       int _bf313;
       int _bf304;
       int _bf64;
       int _bf68;
       int _bf596;
       int _bf600;
       int _bf92;
       int _bf737;
       int _bf282;
       int _bf292;
       int _bf434;
       int _bf444;
       int _bf510;
       int _bf520;
       int _bf548;
       int _bf558;
       int _bf168;
       int _bf178;
       int _bf320;
       int _bf330;
       int _bf227;
       int _bf93;
       int _bf144;
       int _bf135;
       int _bf491;
       int _bf475;
       int _bf465;
       int _bf456;
       int _bf34;
       int b_0_0;
       int _bf19;
       int _bf605;
       int _bf130;
       int _bf26;
       int _bf1;
       int _bf106;
       int _bf140;
       int _bf35;
       int _bf472;
       int _bf482;
       int _bf141;

       #pragma omp parallel sections
       {
           #pragma omp section
               path27(b_1_3, &b_3_3, &_bf604, &_bf589, &_bf579, &_bf570, &_bf148, &b_0_3, &_bf133, &_bf123, &_bf114);
           #pragma omp section
               path31(b_2_0, &_bf724, &_bf152);
           #pragma omp section
               path32(a_1_1, &_bf723, &_bf154);
           #pragma omp section
               path36(b_2_1, &b_1_1, &_bf224, &_bf209, &_bf199, &_bf190);
           #pragma omp section
               path38(a_0_1, &_bf756, &_bf2);
           #pragma omp section
               path39(b_2_2, &b_1_2, &_bf262, &_bf247, &_bf237, &_bf228);
           #pragma omp section
               path41(b_2_3, &_bf77, &b_1_3, &_bf285, &_bf275, &_bf266);
           #pragma omp section
               path44(b_3_1, &b_2_1, &_bf376, &_bf361, &_bf351, &_bf342);
           #pragma omp section
               path47(b_3_2, &b_2_2, &_bf414, &_bf399, &_bf389, &_bf380);
           #pragma omp section
               path49(a_0_2, &_bf747, &_bf40);
           #pragma omp section
               path50(b_3_3, &_bf115, &b_2_3, &_bf437, &_bf427, &_bf418);
           #pragma omp section
               path51(a_3_1, &_bf643, &_bf572, &a_3_0, &_bf489, &_bf477, &_bf467, &_bf458);
           #pragma omp section
               path53(a_3_2, &_bf188, &a_3_1, &_bf515, &_bf505, &_bf496);
           #pragma omp section
               path54(a_3_3, &_bf226, &a_3_2, &_bf553, &_bf543, &_bf534);
           #pragma omp section
               path61(a_0_3, &_bf739, &_bf78);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path26(_bf756, &_bf731, &_bf116, &a_0_0, &_bf33, &_bf21, &_bf11);
           #pragma omp section
               path34(_bf77, _bf723, &_bf301, &a_1_3, &_bf287, &_bf277, &_bf268, &a_1_0, &_bf185, &_bf173, &_bf163);
           #pragma omp section
               path37(_bf224, a_1_2, &_bf225, &a_1_1, &_bf211, &_bf201, &_bf192);
           #pragma omp section
               path40(_bf262, a_1_3, &_bf263, &a_1_2, &_bf249, &_bf239, &_bf230);
           #pragma omp section
               path43(_bf115, a_2_1, &_bf453, &a_2_3, &_bf439, &_bf429, &_bf420, &a_2_0, &_bf337, &_bf325, &_bf315, &_bf306);
           #pragma omp section
               path45(_bf376, a_2_2, &_bf377, &a_2_1, &_bf363, &_bf353, &_bf344);
           #pragma omp section
               path46(_bf188, b_1_1, &_bf529, &b_3_1, &_bf513, &_bf503, &_bf494, &_bf72, &b_0_1, &_bf57, &_bf47, &_bf38);
           #pragma omp section
               path48(_bf414, a_2_3, &_bf415, &a_2_2, &_bf401, &_bf391, &_bf382);
           #pragma omp section
               path52(_bf747, &_bf745, &_bf49);
           #pragma omp section
               path55(_bf579, _bf643, &_bf586, &_bf641);
           #pragma omp section
               path60(_bf226, b_1_2, &_bf567, &b_3_2, &_bf551, &_bf541, &_bf532, &_bf110, &b_0_2, &_bf95, &_bf85, &_bf76);
           #pragma omp section
               path67(_bf148, &_bf39);
           #pragma omp section
               path78(_bf489, &_bf151);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path4(_bf199, _bf201, &_bf206);
           #pragma omp section
               path5(_bf209, _bf211, &_bf216);
           #pragma omp section
               path7(_bf237, _bf239, &_bf244);
           #pragma omp section
               path8(_bf247, _bf249, &_bf254);
           #pragma omp section
               path14(_bf351, _bf353, &_bf358);
           #pragma omp section
               path15(_bf361, _bf363, &_bf368);
           #pragma omp section
               path17(_bf389, _bf391, &_bf396);
           #pragma omp section
               path18(_bf399, _bf401, &_bf406);
           #pragma omp section
               path19(c_0_1, _bf38, _bf40, &_bf46);
           #pragma omp section
               path24(_bf11, b_1_0, &_bf16, &_bf755, &_bf0);
           #pragma omp section
               path28(_bf731, &_bf729, &_bf125);
           #pragma omp section
               path33(_bf185, _bf724, &_bf187, &b_1_0, &_bf171, &_bf161);
           #pragma omp section
               path42(_bf337, b_3_0, &_bf339, &b_2_0, &_bf323, &_bf313, &_bf304);
           #pragma omp section
               path56(_bf57, _bf745, &_bf64, &_bf68);
           #pragma omp section
               path57(_bf589, _bf641, &_bf596, &_bf600);
           #pragma omp section
               path62(_bf85, _bf739, &_bf92, &_bf737);
           #pragma omp section
               path69(_bf277, _bf275, &_bf282);
           #pragma omp section
               path70(_bf287, _bf285, &_bf292);
           #pragma omp section
               path73(_bf429, _bf427, &_bf434);
           #pragma omp section
               path74(_bf439, _bf437, &_bf444);
           #pragma omp section
               path80(_bf503, _bf505, &_bf510);
           #pragma omp section
               path81(_bf513, _bf515, &_bf520);
           #pragma omp section
               path83(_bf541, _bf543, &_bf548);
           #pragma omp section
               path84(_bf551, _bf553, &_bf558);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path1(_bf161, _bf163, &_bf168);
           #pragma omp section
               path2(_bf171, _bf173, &_bf178);
           #pragma omp section
               path3(_bf225, _bf216, _bf206, _bf190, _bf192, &c_1_1);
           #pragma omp section
               path6(_bf263, _bf254, _bf244, _bf228, _bf230, &c_1_2);
           #pragma omp section
               path11(_bf313, _bf315, &_bf320);
           #pragma omp section
               path12(_bf323, _bf325, &_bf330);
           #pragma omp section
               path13(_bf377, _bf368, _bf358, _bf342, _bf344, &c_2_1);
           #pragma omp section
               path16(_bf415, _bf406, _bf396, _bf380, _bf382, &c_2_2);
           #pragma omp section
               path20(_bf64, _bf46, _bf47, _bf49, &_bf227);
           #pragma omp section
               path23(_bf92, c_0_2, _bf76, _bf78, &_bf93);
           #pragma omp section
               path29(_bf729, &_bf144, &_bf135);
           #pragma omp section
               path35(_bf151, _bf755, &_bf491, &b_3_0, &_bf475, &_bf465, &_bf456, &_bf34, &b_0_0, &_bf19);
           #pragma omp section
               path58(_bf604, _bf600, &_bf605, &a_3_3);
           #pragma omp section
               path65(_bf125, _bf123, &_bf130);
           #pragma omp section
               path68(_bf301, _bf292, _bf282, _bf268, _bf266, &c_1_3);
           #pragma omp section
               path72(_bf453, _bf444, _bf434, _bf420, _bf418, &c_2_3);
           #pragma omp section
               path79(_bf529, _bf520, _bf510, _bf494, _bf496, &c_3_1);
           #pragma omp section
               path82(_bf567, _bf558, _bf548, _bf532, _bf534, &c_3_2);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path0(_bf187, _bf178, _bf168, _bf152, _bf154, &c_1_0);
           #pragma omp section
               path9(_bf19, _bf21, &_bf26);
           #pragma omp section
               path10(_bf339, _bf330, _bf320, _bf304, _bf306, &c_2_0);
           #pragma omp section
               path21(_bf605, _bf596, _bf586, _bf570, _bf572, &c_3_3);
           #pragma omp section
               path59(_bf227, _bf72, _bf68, &c_0_1, &a_0_1);
           #pragma omp section
               path63(_bf93, _bf95, _bf737, &_bf1, &_bf106);
           #pragma omp section
               path66(_bf135, _bf133, &_bf140);
           #pragma omp section
               path71(_bf34, _bf33, &_bf35);
           #pragma omp section
               path76(_bf465, _bf467, &_bf472);
           #pragma omp section
               path77(_bf475, _bf477, &_bf482);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path22(_bf35, _bf26, _bf16, _bf0, _bf2, &c_0_0);
           #pragma omp section
               path25(_bf1, _bf110, _bf106, &c_0_2, &a_0_2);
           #pragma omp section
               path64(_bf140, _bf130, c_0_3, _bf116, _bf114, &_bf141);
           #pragma omp section
               path75(_bf491, _bf482, _bf472, _bf456, _bf458, &c_3_0);
       }
       path30(_bf141, _bf39, _bf144, &c_0_3, &a_0_3);

       outputs[i * 48 + 0] = a_0_0;
       outputs[i * 48 + 1] = a_0_1;
       outputs[i * 48 + 2] = a_0_2;
       outputs[i * 48 + 3] = a_0_3;
       outputs[i * 48 + 4] = a_1_0;
       outputs[i * 48 + 5] = a_1_1;
       outputs[i * 48 + 6] = a_1_2;
       outputs[i * 48 + 7] = a_1_3;
       outputs[i * 48 + 8] = a_2_0;
       outputs[i * 48 + 9] = a_2_1;
       outputs[i * 48 + 10] = a_2_2;
       outputs[i * 48 + 11] = a_2_3;
       outputs[i * 48 + 12] = a_3_0;
       outputs[i * 48 + 13] = a_3_1;
       outputs[i * 48 + 14] = a_3_2;
       outputs[i * 48 + 15] = a_3_3;
       outputs[i * 48 + 16] = b_0_0;
       outputs[i * 48 + 17] = b_0_1;
       outputs[i * 48 + 18] = b_0_2;
       outputs[i * 48 + 19] = b_0_3;
       outputs[i * 48 + 20] = b_1_0;
       outputs[i * 48 + 21] = b_1_1;
       outputs[i * 48 + 22] = b_1_2;
       outputs[i * 48 + 23] = b_1_3;
       outputs[i * 48 + 24] = b_2_0;
       outputs[i * 48 + 25] = b_2_1;
       outputs[i * 48 + 26] = b_2_2;
       outputs[i * 48 + 27] = b_2_3;
       outputs[i * 48 + 28] = b_3_0;
       outputs[i * 48 + 29] = b_3_1;
       outputs[i * 48 + 30] = b_3_2;
       outputs[i * 48 + 31] = b_3_3;
       outputs[i * 48 + 32] = c_0_0;
       outputs[i * 48 + 33] = c_0_1;
       outputs[i * 48 + 34] = c_0_2;
       outputs[i * 48 + 35] = c_0_3;
       outputs[i * 48 + 36] = c_1_0;
       outputs[i * 48 + 37] = c_1_1;
       outputs[i * 48 + 38] = c_1_2;
       outputs[i * 48 + 39] = c_1_3;
       outputs[i * 48 + 40] = c_2_0;
       outputs[i * 48 + 41] = c_2_1;
       outputs[i * 48 + 42] = c_2_2;
       outputs[i * 48 + 43] = c_2_3;
       outputs[i * 48 + 44] = c_3_0;
       outputs[i * 48 + 45] = c_3_1;
       outputs[i * 48 + 46] = c_3_2;
       outputs[i * 48 + 47] = c_3_3;
    }
    auto end = chrono::steady_clock::now();

    if (!onlyTimeOutput)
        printf("time: %ld ms", chrono::duration_cast<chrono::milliseconds>(end - start).count());
    else
        printf("%ld", chrono::duration_cast<chrono::nanoseconds>(end - start).count());

    if (!onlyTimeOutput) {
        printf("a_0_0: %i, a_0_1: %i, a_0_2: %i, a_0_3: %i, a_1_0: %i, a_1_1: %i, a_1_2: %i, a_1_3: %i, a_2_0: %i, a_2_1: %i, a_2_2: %i, a_2_3: %i, a_3_0: %i, a_3_1: %i, a_3_2: %i, a_3_3: %i, b_0_0: %i, b_0_1: %i, b_0_2: %i, b_0_3: %i, b_1_0: %i, b_1_1: %i, b_1_2: %i, b_1_3: %i, b_2_0: %i, b_2_1: %i, b_2_2: %i, b_2_3: %i, b_3_0: %i, b_3_1: %i, b_3_2: %i, b_3_3: %i, c_0_0: %i, c_0_1: %i, c_0_2: %i, c_0_3: %i, c_1_0: %i, c_1_1: %i, c_1_2: %i, c_1_3: %i, c_2_0: %i, c_2_1: %i, c_2_2: %i, c_2_3: %i, c_3_0: %i, c_3_1: %i, c_3_2: %i, c_3_3: %i", outputs[0], outputs[1], outputs[2], outputs[3], outputs[4], outputs[5], outputs[6], outputs[7], outputs[8], outputs[9], outputs[10], outputs[11], outputs[12], outputs[13], outputs[14], outputs[15], outputs[16], outputs[17], outputs[18], outputs[19], outputs[20], outputs[21], outputs[22], outputs[23], outputs[24], outputs[25], outputs[26], outputs[27], outputs[28], outputs[29], outputs[30], outputs[31], outputs[32], outputs[33], outputs[34], outputs[35], outputs[36], outputs[37], outputs[38], outputs[39], outputs[40], outputs[41], outputs[42], outputs[43], outputs[44], outputs[45], outputs[46], outputs[47]);
    }
}