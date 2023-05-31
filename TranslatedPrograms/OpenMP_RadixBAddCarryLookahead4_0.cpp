#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int _bf233, bool* _bf243, bool _bf244, bool** _bf1) { 
    _bf243[_bf233] = _bf244;
    *_bf1 = _bf243;
}
void path1(int* _bf100) { 
    *_bf100 = 255;
}
void path2(int _bf99, int _bf100, bool* _bf101) { 
    *_bf101 = _bf99 == _bf100;
}
void path3(int _bf95, bool* _bf94, bool _bf101, bool** _bf103) { 
    _bf94[_bf95] = _bf101;
    *_bf103 = _bf94;
}
void path4(int* _bf104) { 
    *_bf104 = 2;
}
void path5(int* _bf105) { 
    *_bf105 = 2;
}
void path6(int* _bf109) { 
    *_bf109 = 255;
}
void path7(int _bf6, int _bf10, int* _bf11) { 
    *_bf11 = _bf6 + _bf10;
}
void path8(int _bf108, int _bf109, bool* _bf110) { 
    *_bf110 = _bf108 == _bf109;
}
void path9(int _bf104, bool* _bf103, bool _bf110, bool** _bf112) { 
    _bf103[_bf104] = _bf110;
    *_bf112 = _bf103;
}
void path10(int* _bf113) { 
    *_bf113 = 3;
}
void path11(int* _bf114) { 
    *_bf114 = 3;
}
void path12(int* _bf118) { 
    *_bf118 = 255;
}
void path13(int _bf117, int _bf118, bool* _bf119) { 
    *_bf119 = _bf117 == _bf118;
}
void path14(int _bf113, bool* _bf112, bool _bf119, bool** _bf121) { 
    _bf112[_bf113] = _bf119;
    *_bf121 = _bf112;
}
void path15(int* _bf122) { 
    *_bf122 = 1;
}
void path16(int* _bf123) { 
    *_bf123 = 0;
}
void path17(int* _bf127) { 
    *_bf127 = 1;
}
void path18(int _bf2, int* s, int _bf11, int** _bf13) { 
    s[_bf2] = _bf11;
    *_bf13 = s;
}
void path19(bool _bf12, bool _bf130, bool* _bf131) { 
    *_bf131 = _bf12 && _bf130;
}
void path20(int* _bf132) { 
    *_bf132 = 1;
}
void path21(bool* _bf125, bool* _bf134, bool** _bf137) { 
    *_bf137 = _bf134;
}
void path22(bool _bf131, bool _bf28, bool* _bf138) { 
    *_bf138 = _bf131 || _bf28;
}
void path23(int _bf122, bool* _bf41, bool _bf138, bool** _bf139) { 
    _bf41[_bf122] = _bf138;
    *_bf139 = _bf41;
}
void path24(int* _bf14) { 
    *_bf14 = 1;
}
void path25(int* _bf140) { 
    *_bf140 = 1;
}
void path26(int* _bf141) { 
    *_bf141 = 1;
}
void path27(int* _bf145) { 
    *_bf145 = 0;
}
void path28(int* _bf15) { 
    *_bf15 = 1;
}
void path29(bool* _bf143, bool* _bf147, bool** _bf150) { 
    *_bf150 = _bf147;
}
void path30(bool _bf144, bool _bf148, bool* _bf151) { 
    *_bf151 = _bf144 && _bf148;
}
void path31(int _bf140, bool* _bf150, bool _bf151, bool** _bf152) { 
    _bf150[_bf140] = _bf151;
    *_bf152 = _bf150;
}
void path32(int* _bf153) { 
    *_bf153 = 3;
}
void path33(int* _bf154) { 
    *_bf154 = 2;
}
void path34(int* _bf158) { 
    *_bf158 = 3;
}
void path35(bool _bf157, bool _bf161, bool* _bf162) { 
    *_bf162 = _bf157 && _bf161;
}
void path36(int* _bf163) { 
    *_bf163 = 3;
}
void path37(bool* _bf156, bool* _bf165, bool** _bf168) { 
    *_bf168 = _bf165;
}
void path38(bool _bf162, bool _bf44, bool* _bf169) { 
    *_bf169 = _bf162 || _bf44;
}
void path39(int _bf153, bool* _bf45, bool _bf169, bool** _bf170) { 
    _bf45[_bf153] = _bf169;
    *_bf170 = _bf45;
}
void path40(int* _bf171) { 
    *_bf171 = 3;
}
void path41(int* _bf172) { 
    *_bf172 = 3;
}
void path42(int* _bf176) { 
    *_bf176 = 2;
}
void path43(bool* _bf174, bool* _bf178, bool** _bf181) { 
    *_bf181 = _bf178;
}
void path44(bool _bf175, bool _bf179, bool* _bf182) { 
    *_bf182 = _bf175 && _bf179;
}
void path45(int _bf171, bool* _bf181, bool _bf182, bool** _bf183) { 
    _bf181[_bf171] = _bf182;
    *_bf183 = _bf181;
}
void path46(int* _bf184) { 
    *_bf184 = 3;
}
void path47(int* _bf185) { 
    *_bf185 = 1;
}
void path48(int* _bf189) { 
    *_bf189 = 3;
}
void path49(int* _bf19) { 
    *_bf19 = 1;
}
void path50(bool _bf188, bool _bf192, bool* _bf193) { 
    *_bf193 = _bf188 && _bf192;
}
void path51(int* _bf194) { 
    *_bf194 = 3;
}
void path52(bool* _bf187, bool* _bf196, bool** _bf199) { 
    *_bf199 = _bf196;
}
void path53(int* _bf2) { 
    *_bf2 = 0;
}
void path54(bool _bf193, bool _bf48, bool* _bf200) { 
    *_bf200 = _bf193 || _bf48;
}
void path55(int _bf184, bool* _bf53, bool _bf200, bool** _bf201) { 
    _bf53[_bf184] = _bf200;
    *_bf201 = _bf53;
}
void path56(int* _bf202) { 
    *_bf202 = 3;
}
void path57(int* _bf203) { 
    *_bf203 = 3;
}
void path58(int* _bf207) { 
    *_bf207 = 1;
}
void path59(bool* _bf205, bool* _bf209, bool** _bf212) { 
    *_bf212 = _bf209;
}
void path60(bool _bf206, bool _bf210, bool* _bf213) { 
    *_bf213 = _bf206 && _bf210;
}
void path61(int _bf202, bool* _bf212, bool _bf213, bool** _bf214) { 
    _bf212[_bf202] = _bf213;
    *_bf214 = _bf212;
}
void path62(int* _bf215) { 
    *_bf215 = 2;
}
void path63(int* _bf216) { 
    *_bf216 = 1;
}
void path64(int* _bf220) { 
    *_bf220 = 2;
}
void path65(bool _bf219, bool _bf223, bool* _bf224) { 
    *_bf224 = _bf219 && _bf223;
}
void path66(int* _bf225) { 
    *_bf225 = 2;
}
void path67(int _bf18, int _bf22, int* _bf23) { 
    *_bf23 = _bf18 + _bf22;
}
void path68(bool* _bf218, bool* _bf227, bool** _bf230) { 
    *_bf230 = _bf227;
}
void path69(bool _bf224, bool _bf57, bool* _bf231) { 
    *_bf231 = _bf224 || _bf57;
}
void path70(int _bf215, bool* _bf62, bool _bf231, bool** _bf232) { 
    _bf62[_bf215] = _bf231;
    *_bf232 = _bf62;
}
void path71(int* _bf233) { 
    *_bf233 = 2;
}
void path72(int* _bf234) { 
    *_bf234 = 2;
}
void path73(int* _bf238) { 
    *_bf238 = 1;
}
void path74(bool* _bf236, bool* _bf240, bool** _bf243) { 
    *_bf243 = _bf240;
}
void path75(bool _bf237, bool _bf241, bool* _bf244) { 
    *_bf244 = _bf237 && _bf241;
}
void path76(int* _bf246) { 
    *_bf246 = 0;
}
void path77(int* _bf247) { 
    *_bf247 = 0;
}
void path78(int _bf14, int* _bf13, int _bf23, int** _bf25) { 
    _bf13[_bf14] = _bf23;
    *_bf25 = _bf13;
}
void path79(int* _bf251) { 
    *_bf251 = 256;
}
void path80(int _bf250, int _bf251, int* _bf252) { 
    *_bf252 = _bf250 % _bf251;
}
void path81(int _bf246, int* _bf66, int _bf252, int** _bf253) { 
    _bf66[_bf246] = _bf252;
    *_bf253 = _bf66;
}
void path82(int* _bf254) { 
    *_bf254 = 1;
}
void path83(int* _bf255) { 
    *_bf255 = 1;
}
void path84(int* _bf259) { 
    *_bf259 = 0;
}
void path85(int* _bf26) { 
    *_bf26 = 2;
}
void path86(int* _bf263) { 
    *_bf263 = 1;
}
void path87(int* _bf264) { 
    *_bf264 = 0;
}
void path88(bool _bf262, int _bf263, int _bf264, int* _bf265) { 
    if ( _bf262 ) {
        *_bf265 = _bf263;
    } else  { 
        *_bf265 = _bf264;
    } 
}
void path89(int _bf315, int _bf265, int* _bf266) { 
    *_bf266 = _bf315 + _bf265;
}
void path90(int* _bf267) { 
    *_bf267 = 256;
}
void path91(int _bf266, int _bf267, int* _bf268) { 
    *_bf268 = _bf266 % _bf267;
}
void path92(int _bf254, int* _bf211, int _bf268, int** _bf269) { 
    _bf211[_bf254] = _bf268;
    *_bf269 = _bf211;
}
void path93(int* _bf27) { 
    *_bf27 = 2;
}
void path94(int* _bf270) { 
    *_bf270 = 2;
}
void path95(int* _bf271) { 
    *_bf271 = 2;
}
void path96(int* _bf275) { 
    *_bf275 = 1;
}
void path97(int* _bf279) { 
    *_bf279 = 1;
}
void path98(int* _bf280) { 
    *_bf280 = 0;
}
void path99(bool _bf278, int _bf279, int _bf280, int* _bf281) { 
    if ( _bf278 ) {
        *_bf281 = _bf279;
    } else  { 
        *_bf281 = _bf280;
    } 
}
void path100(int _bf274, int _bf320, int* _bf282) { 
    *_bf282 = _bf274 + _bf320;
}
void path101(int* _bf283) { 
    *_bf283 = 256;
}
void path102(int _bf282, int _bf283, int* _bf284) { 
    *_bf284 = _bf282 % _bf283;
}
void path103(int _bf270, int* _bf317, int _bf284, int** _bf285) { 
    _bf317[_bf270] = _bf284;
    *_bf285 = _bf317;
}
void path104(int* _bf286) { 
    *_bf286 = 3;
}
void path105(int* _bf287) { 
    *_bf287 = 3;
}
void path106(int* _bf291) { 
    *_bf291 = 2;
}
void path107(int* _bf295) { 
    *_bf295 = 1;
}
void path108(int* _bf296) { 
    *_bf296 = 0;
}
void path109(bool _bf294, int _bf295, int _bf296, int* _bf297) { 
    if ( _bf294 ) {
        *_bf297 = _bf295;
    } else  { 
        *_bf297 = _bf296;
    } 
}
void path110(int _bf290, int _bf328, int* _bf298) { 
    *_bf298 = _bf290 + _bf328;
}
void path111(int* _bf299) { 
    *_bf299 = 256;
}
void path112(int* _bf3) { 
    *_bf3 = 0;
}
void path113(int _bf298, int _bf299, int* _bf300) { 
    *_bf300 = _bf298 % _bf299;
}
void path114(int _bf286, int* _bf322, int _bf300, int** _bf301) { 
    _bf322[_bf286] = _bf300;
    *_bf301 = _bf322;
}
void path115(int* _bf302) { 
    *_bf302 = 4;
}
void path116(int* _bf303) { 
    *_bf303 = 3;
}
void path117(int* _bf307) { 
    *_bf307 = 1;
}
void path118(int* _bf308) { 
    *_bf308 = 0;
}
void path119(bool _bf306, int _bf307, int _bf308, int* _bf309) { 
    if ( _bf306 ) {
        *_bf309 = _bf307;
    } else  { 
        *_bf309 = _bf308;
    } 
}
void path120(int* _bf31) { 
    *_bf31 = 2;
}
void path121(int _bf30, int _bf34, int* _bf35) { 
    *_bf35 = _bf30 + _bf34;
}
void path122(int _bf26, int* _bf25, int _bf35, int** _bf37) { 
    _bf25[_bf26] = _bf35;
    *_bf37 = _bf25;
}
void path123(int* _bf38) { 
    *_bf38 = 3;
}
void path124(int* _bf39) { 
    *_bf39 = 3;
}
void path125(int* _bf43) { 
    *_bf43 = 3;
}
void path126(int _bf42, int _bf46, int* _bf47) { 
    *_bf47 = _bf42 + _bf46;
}
void path127(int _bf38, int* _bf37, int _bf47, int** _bf49) { 
    _bf37[_bf38] = _bf47;
    *_bf49 = _bf37;
}
void path128(int* _bf50) { 
    *_bf50 = 0;
}
void path129(int* _bf51) { 
    *_bf51 = 255;
}
void path130(int* _bf52) { 
    *_bf52 = 0;
}
void path131(int _bf51, int _bf55, bool* _bf56) { 
    *_bf56 = _bf51 < _bf55;
}
void path132(int _bf50, bool* _bf0, bool _bf56, bool** _bf58) { 
    _bf0[_bf50] = _bf56;
    *_bf58 = _bf0;
}
void path133(int* _bf59) { 
    *_bf59 = 1;
}
void path134(int* _bf60) { 
    *_bf60 = 255;
}
void path135(int* _bf61) { 
    *_bf61 = 1;
}
void path136(int _bf60, int _bf64, bool* _bf65) { 
    *_bf65 = _bf60 < _bf64;
}
void path137(int _bf59, bool* _bf58, bool _bf65, bool** _bf67) { 
    _bf58[_bf59] = _bf65;
    *_bf67 = _bf58;
}
void path138(int* _bf68) { 
    *_bf68 = 2;
}
void path139(int* _bf69) { 
    *_bf69 = 255;
}
void path140(int* _bf7) { 
    *_bf7 = 0;
}
void path141(int* _bf70) { 
    *_bf70 = 2;
}
void path142(int _bf69, int _bf73, bool* _bf74) { 
    *_bf74 = _bf69 < _bf73;
}
void path143(int _bf68, bool* _bf67, bool _bf74, bool** _bf76) { 
    _bf67[_bf68] = _bf74;
    *_bf76 = _bf67;
}
void path144(int* _bf77) { 
    *_bf77 = 3;
}
void path145(int* _bf78) { 
    *_bf78 = 255;
}
void path146(int* _bf79) { 
    *_bf79 = 3;
}
void path147(int _bf78, int _bf82, bool* _bf83) { 
    *_bf83 = _bf78 < _bf82;
}
void path148(int _bf77, bool* _bf76, bool _bf83, bool** _bf85) { 
    _bf76[_bf77] = _bf83;
    *_bf85 = _bf76;
}
void path149(int* _bf86) { 
    *_bf86 = 0;
}
void path150(int* _bf87) { 
    *_bf87 = 0;
}
void path151(int* _bf91) { 
    *_bf91 = 255;
}
void path152(int _bf90, int _bf91, bool* _bf92) { 
    *_bf92 = _bf90 == _bf91;
}
void path153(int _bf86, bool* _bf1, bool _bf92, bool** _bf94) { 
    _bf1[_bf86] = _bf92;
    *_bf94 = _bf1;
}
void path154(int* _bf95) { 
    *_bf95 = 1;
}
void path155(int* _bf96) { 
    *_bf96 = 1;
}
void path156(int _bf302, int* _bf301, int _bf336, int** s) { 
    _bf301[_bf302] = _bf336;
    *s = _bf301;
}
void path157(int _bf303, bool* _bf293, bool** _bf0, bool* _bf306) { 
    *_bf306 = _bf293[_bf303];
    *_bf0 = _bf293;
}
void path158(int _bf105, int* _bf98, int** _bf107, int* _bf108) { 
    *_bf108 = _bf98[_bf105];
    *_bf107 = _bf98;
}
void path159(int _bf114, int* _bf107, int** _bf116, int* _bf117) { 
    *_bf117 = _bf107[_bf114];
    *_bf116 = _bf107;
}
void path160(bool* _bf85, bool** _bf124, bool** _bf133) { 
    *_bf124 = _bf85;
    *_bf133 = _bf85;
}
void path161(int _bf123, bool* _bf124, bool** _bf125, bool* _bf126) { 
    *_bf126 = _bf124[_bf123];
    *_bf125 = _bf124;
}
void path162(int _bf127, bool* _bf121, bool** _bf129, bool* _bf130) { 
    *_bf130 = _bf121[_bf127];
    *_bf129 = _bf121;
}
void path163(int _bf132, bool* _bf133, bool** _bf134, bool* _bf135) { 
    *_bf135 = _bf133[_bf132];
    *_bf134 = _bf133;
}
void path164(bool* _bf129, bool** _bf142, bool** _bf146) { 
    *_bf142 = _bf129;
    *_bf146 = _bf129;
}
void path165(int _bf141, bool* _bf142, bool** _bf143, bool* _bf144) { 
    *_bf144 = _bf142[_bf141];
    *_bf143 = _bf142;
}
void path166(int _bf145, bool* _bf146, bool** _bf147, bool* _bf148) { 
    *_bf148 = _bf146[_bf145];
    *_bf147 = _bf146;
}
void path167(bool* _bf139, bool** _bf155, bool** _bf164) { 
    *_bf155 = _bf139;
    *_bf164 = _bf139;
}
void path168(int _bf154, bool* _bf155, bool** _bf156, bool* _bf157) { 
    *_bf157 = _bf155[_bf154];
    *_bf156 = _bf155;
}
void path169(int _bf158, bool* _bf152, bool** _bf160, bool* _bf161) { 
    *_bf161 = _bf152[_bf158];
    *_bf160 = _bf152;
}
void path170(int _bf163, bool* _bf164, bool** _bf165, bool* _bf166) { 
    *_bf166 = _bf164[_bf163];
    *_bf165 = _bf164;
}
void path171(int _bf15, int* _bf5, int** _bf17, int* _bf18) { 
    *_bf18 = _bf5[_bf15];
    *_bf17 = _bf5;
}
void path172(bool* _bf160, bool** _bf173, bool** _bf177) { 
    *_bf173 = _bf160;
    *_bf177 = _bf160;
}
void path173(int _bf172, bool* _bf173, bool** _bf174, bool* _bf175) { 
    *_bf175 = _bf173[_bf172];
    *_bf174 = _bf173;
}
void path174(int _bf176, bool* _bf177, bool** _bf178, bool* _bf179) { 
    *_bf179 = _bf177[_bf176];
    *_bf178 = _bf177;
}
void path175(bool* _bf170, bool** _bf186, bool** _bf195) { 
    *_bf186 = _bf170;
    *_bf195 = _bf170;
}
void path176(int _bf185, bool* _bf186, bool** _bf187, bool* _bf188) { 
    *_bf188 = _bf186[_bf185];
    *_bf187 = _bf186;
}
void path177(int _bf189, bool* _bf183, bool** _bf191, bool* _bf192) { 
    *_bf192 = _bf183[_bf189];
    *_bf191 = _bf183;
}
void path178(int _bf194, bool* _bf195, bool** _bf196, bool* _bf197) { 
    *_bf197 = _bf195[_bf194];
    *_bf196 = _bf195;
}
void path179(bool* _bf191, bool** _bf204, bool** _bf208) { 
    *_bf204 = _bf191;
    *_bf208 = _bf191;
}
void path180(int _bf203, bool* _bf204, bool** _bf205, bool* _bf206) { 
    *_bf206 = _bf204[_bf203];
    *_bf205 = _bf204;
}
void path181(int _bf207, bool* _bf208, bool** _bf209, bool* _bf210) { 
    *_bf210 = _bf208[_bf207];
    *_bf209 = _bf208;
}
void path182(int _bf19, int* _bf9, int** _bf21, int* _bf22) { 
    *_bf22 = _bf9[_bf19];
    *_bf21 = _bf9;
}
void path183(bool* _bf201, bool** _bf217, bool** _bf226) { 
    *_bf217 = _bf201;
    *_bf226 = _bf201;
}
void path184(int _bf216, bool* _bf217, bool** _bf218, bool* _bf219) { 
    *_bf219 = _bf217[_bf216];
    *_bf218 = _bf217;
}
void path185(int _bf220, bool* _bf214, bool** _bf222, bool* _bf223) { 
    *_bf223 = _bf214[_bf220];
    *_bf222 = _bf214;
}
void path186(int _bf225, bool* _bf226, bool** _bf227, bool* _bf228) { 
    *_bf228 = _bf226[_bf225];
    *_bf227 = _bf226;
}
void path187(bool* _bf222, bool** _bf235, bool** _bf239) { 
    *_bf235 = _bf222;
    *_bf239 = _bf222;
}
void path188(int _bf234, bool* _bf235, bool** _bf236, bool* _bf237) { 
    *_bf237 = _bf235[_bf234];
    *_bf236 = _bf235;
}
void path189(int _bf238, bool* _bf239, bool** _bf240, bool* _bf241) { 
    *_bf241 = _bf239[_bf238];
    *_bf240 = _bf239;
}
void path190(int _bf247, int* _bf116, int** _bf249, int* _bf250) { 
    *_bf250 = _bf116[_bf247];
    *_bf249 = _bf116;
}
void path191(int _bf255, int* _bf253, int** _bf257, int* _bf258) { 
    *_bf258 = _bf253[_bf255];
    *_bf257 = _bf253;
}
void path192(int _bf259, bool* _bf232, bool** _bf261, bool* _bf262) { 
    *_bf262 = _bf232[_bf259];
    *_bf261 = _bf232;
}
void path193(int _bf271, int* _bf269, int** _bf273, int* _bf274) { 
    *_bf274 = _bf269[_bf271];
    *_bf273 = _bf269;
}
void path194(int _bf275, bool* _bf261, bool** _bf277, bool* _bf278) { 
    *_bf278 = _bf261[_bf275];
    *_bf277 = _bf261;
}
void path195(int _bf287, int* _bf285, int** _bf289, int* _bf290) { 
    *_bf290 = _bf285[_bf287];
    *_bf289 = _bf285;
}
void path196(int _bf27, int* _bf17, int** _bf29, int* _bf30) { 
    *_bf30 = _bf17[_bf27];
    *_bf29 = _bf17;
}
void path197(int _bf291, bool* _bf277, bool** _bf293, bool* _bf294) { 
    *_bf294 = _bf277[_bf291];
    *_bf293 = _bf277;
}
void path198(int _bf31, int* _bf21, int** _bf33, int* _bf34) { 
    *_bf34 = _bf21[_bf31];
    *_bf33 = _bf21;
}
void path199(int _bf3, int* x, int** _bf5, int* _bf6) { 
    *_bf6 = x[_bf3];
    *_bf5 = x;
}
void path200(int _bf52, int* _bf49, int** _bf54, int* _bf55) { 
    *_bf55 = _bf49[_bf52];
    *_bf54 = _bf49;
}
void path201(int _bf61, int* _bf54, int** _bf63, int* _bf64) { 
    *_bf64 = _bf54[_bf61];
    *_bf63 = _bf54;
}
void path202(int _bf70, int* _bf63, int** _bf72, int* _bf73) { 
    *_bf73 = _bf63[_bf70];
    *_bf72 = _bf63;
}
void path203(int _bf79, int* _bf72, int** _bf81, int* _bf82) { 
    *_bf82 = _bf72[_bf79];
    *_bf81 = _bf72;
}
void path204(int _bf87, int* _bf81, int** _bf89, int* _bf90) { 
    *_bf90 = _bf81[_bf87];
    *_bf89 = _bf81;
}
void path205(int _bf7, int* y, int** _bf9, int* _bf10) { 
    *_bf10 = y[_bf7];
    *_bf9 = y;
}
void path206(int _bf96, int* _bf89, int** _bf98, int* _bf99) { 
    *_bf99 = _bf89[_bf96];
    *_bf98 = _bf89;
}
void path207(int _bf39, int* _bf29, int** x, int* _bf42) { 
    *_bf42 = _bf29[_bf39];
    *x = _bf29;
}
void path208(int _bf43, int* _bf33, int** y, int* _bf46) { 
    *_bf46 = _bf33[_bf43];
    *y = _bf33;
}
void path209(bool _bf126, bool* _bf4) { 
    *_bf4 = _bf126;
}
void path210(bool _bf4, bool* _bf8) { 
    *_bf8 = _bf4;
}
void path211(bool _bf8, bool* _bf12) { 
    *_bf12 = _bf8;
}
void path212(bool _bf135, bool* _bf16) { 
    *_bf16 = _bf135;
}
void path213(bool _bf16, bool* _bf20) { 
    *_bf20 = _bf16;
}
void path214(bool _bf20, bool* _bf24) { 
    *_bf24 = _bf20;
}
void path215(bool _bf24, bool* _bf28) { 
    *_bf28 = _bf24;
}
void path216(bool* _bf137, bool** _bf32) { 
    *_bf32 = _bf137;
}
void path217(bool* _bf32, bool** _bf36) { 
    *_bf36 = _bf32;
}
void path218(bool* _bf36, bool** _bf40) { 
    *_bf40 = _bf36;
}
void path219(bool* _bf40, bool** _bf41) { 
    *_bf41 = _bf40;
}
void path220(bool _bf166, bool* _bf44) { 
    *_bf44 = _bf166;
}
void path221(bool* _bf168, bool** _bf45) { 
    *_bf45 = _bf168;
}
void path222(bool _bf197, bool* _bf48) { 
    *_bf48 = _bf197;
}
void path223(bool* _bf199, bool** _bf53) { 
    *_bf53 = _bf199;
}
void path224(bool _bf228, bool* _bf57) { 
    *_bf57 = _bf228;
}
void path225(bool* _bf230, bool** _bf62) { 
    *_bf62 = _bf230;
}
void path226(int* _bf249, int** _bf66) { 
    *_bf66 = _bf249;
}
void path227(int* _bf257, int** _bf71) { 
    *_bf71 = _bf257;
}
void path228(int* _bf71, int** _bf75) { 
    *_bf75 = _bf71;
}
void path229(int* _bf75, int** _bf80) { 
    *_bf80 = _bf75;
}
void path230(int* _bf80, int** _bf84) { 
    *_bf84 = _bf80;
}
void path231(int* _bf84, int** _bf88) { 
    *_bf88 = _bf84;
}
void path232(int* _bf88, int** _bf93) { 
    *_bf93 = _bf88;
}
void path233(int* _bf93, int** _bf97) { 
    *_bf97 = _bf93;
}
void path234(int* _bf97, int** _bf102) { 
    *_bf102 = _bf97;
}
void path235(int* _bf102, int** _bf106) { 
    *_bf106 = _bf102;
}
void path236(int* _bf106, int** _bf111) { 
    *_bf111 = _bf106;
}
void path237(int* _bf111, int** _bf115) { 
    *_bf115 = _bf111;
}
void path238(int* _bf115, int** _bf120) { 
    *_bf120 = _bf115;
}
void path239(int* _bf120, int** _bf128) { 
    *_bf128 = _bf120;
}
void path240(int* _bf128, int** _bf136) { 
    *_bf136 = _bf128;
}
void path241(int* _bf136, int** _bf149) { 
    *_bf149 = _bf136;
}
void path242(int* _bf149, int** _bf159) { 
    *_bf159 = _bf149;
}
void path243(int* _bf159, int** _bf167) { 
    *_bf167 = _bf159;
}
void path244(int* _bf167, int** _bf180) { 
    *_bf180 = _bf167;
}
void path245(int* _bf180, int** _bf190) { 
    *_bf190 = _bf180;
}
void path246(int* _bf190, int** _bf198) { 
    *_bf198 = _bf190;
}
void path247(int* _bf198, int** _bf211) { 
    *_bf211 = _bf198;
}
void path248(int _bf258, int* _bf221) { 
    *_bf221 = _bf258;
}
void path249(int _bf221, int* _bf229) { 
    *_bf229 = _bf221;
}
void path250(int _bf229, int* _bf242) { 
    *_bf242 = _bf229;
}
void path251(int _bf242, int* _bf245) { 
    *_bf245 = _bf242;
}
void path252(int _bf245, int* _bf248) { 
    *_bf248 = _bf245;
}
void path253(int _bf248, int* _bf256) { 
    *_bf256 = _bf248;
}
void path254(int _bf256, int* _bf260) { 
    *_bf260 = _bf256;
}
void path255(int _bf260, int* _bf272) { 
    *_bf272 = _bf260;
}
void path256(int _bf272, int* _bf276) { 
    *_bf276 = _bf272;
}
void path257(int _bf276, int* _bf288) { 
    *_bf288 = _bf276;
}
void path258(int _bf288, int* _bf292) { 
    *_bf292 = _bf288;
}
void path259(int _bf292, int* _bf304) { 
    *_bf304 = _bf292;
}
void path260(int _bf304, int* _bf305) { 
    *_bf305 = _bf304;
}
void path261(int _bf305, int* _bf310) { 
    *_bf310 = _bf305;
}
void path262(int _bf310, int* _bf311) { 
    *_bf311 = _bf310;
}
void path263(int _bf311, int* _bf312) { 
    *_bf312 = _bf311;
}
void path264(int _bf312, int* _bf313) { 
    *_bf313 = _bf312;
}
void path265(int _bf313, int* _bf314) { 
    *_bf314 = _bf313;
}
void path266(int _bf314, int* _bf315) { 
    *_bf315 = _bf314;
}
void path267(int* _bf273, int** _bf316) { 
    *_bf316 = _bf273;
}
void path268(int* _bf316, int** _bf317) { 
    *_bf317 = _bf316;
}
void path269(int _bf281, int* _bf318) { 
    *_bf318 = _bf281;
}
void path270(int _bf318, int* _bf319) { 
    *_bf319 = _bf318;
}
void path271(int _bf319, int* _bf320) { 
    *_bf320 = _bf319;
}
void path272(int* _bf289, int** _bf321) { 
    *_bf321 = _bf289;
}
void path273(int* _bf321, int** _bf322) { 
    *_bf322 = _bf321;
}
void path274(int _bf297, int* _bf323) { 
    *_bf323 = _bf297;
}
void path275(int _bf323, int* _bf324) { 
    *_bf324 = _bf323;
}
void path276(int _bf324, int* _bf325) { 
    *_bf325 = _bf324;
}
void path277(int _bf325, int* _bf326) { 
    *_bf326 = _bf325;
}
void path278(int _bf326, int* _bf327) { 
    *_bf327 = _bf326;
}
void path279(int _bf327, int* _bf328) { 
    *_bf328 = _bf327;
}
void path280(int _bf309, int* _bf329) { 
    *_bf329 = _bf309;
}
void path281(int _bf329, int* _bf330) { 
    *_bf330 = _bf329;
}
void path282(int _bf330, int* _bf331) { 
    *_bf331 = _bf330;
}
void path283(int _bf331, int* _bf332) { 
    *_bf332 = _bf331;
}
void path284(int _bf332, int* _bf333) { 
    *_bf333 = _bf332;
}
void path285(int _bf333, int* _bf334) { 
    *_bf334 = _bf333;
}
void path286(int _bf334, int* _bf335) { 
    *_bf335 = _bf334;
}
void path287(int _bf335, int* _bf336) { 
    *_bf336 = _bf335;
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
       int _bf100;
       int _bf104;
       int _bf105;
       int _bf109;
       int _bf113;
       int _bf114;
       int _bf118;
       int _bf122;
       int _bf123;
       int _bf127;
       int _bf132;
       int _bf14;
       int _bf140;
       int _bf141;
       int _bf145;
       int _bf15;
       int _bf153;
       int _bf154;
       int _bf158;
       int _bf163;
       int _bf171;
       int _bf172;
       int _bf176;
       int _bf184;
       int _bf185;
       int _bf189;
       int _bf19;
       int _bf194;
       int _bf2;
       int _bf202;
       int _bf203;
       int _bf207;
       int _bf215;
       int _bf216;
       int _bf220;
       int _bf225;
       int _bf233;
       int _bf234;
       int _bf238;
       int _bf246;
       int _bf247;
       int _bf251;
       int _bf254;
       int _bf255;
       int _bf259;
       int _bf26;
       int _bf263;
       int _bf264;
       int _bf267;
       int _bf27;
       int _bf270;
       int _bf271;
       int _bf275;
       int _bf279;
       int _bf280;
       int _bf283;
       int _bf286;
       int _bf287;
       int _bf291;
       int _bf295;
       int _bf296;
       int _bf299;
       int _bf3;
       int _bf302;
       int _bf303;
       int _bf307;
       int _bf308;
       int _bf31;
       int _bf38;
       int _bf39;
       int _bf43;
       int _bf50;
       int _bf51;
       int _bf52;
       int _bf59;
       int _bf60;
       int _bf61;
       int _bf68;
       int _bf69;
       int _bf7;
       int _bf70;
       int _bf77;
       int _bf78;
       int _bf79;
       int _bf86;
       int _bf87;
       int _bf91;
       int _bf95;
       int _bf96;
       int* _bf5;
       int _bf6;
       int* _bf9;
       int _bf10;
       int _bf11;
       int* _bf17;
       int _bf18;
       int* _bf21;
       int _bf22;
       int* _bf13;
       int _bf23;
       int* _bf29;
       int _bf30;
       int* _bf33;
       int _bf34;
       int* _bf25;
       int _bf35;
       int* x = x_arr + i * 4;
       int _bf42;
       int* y = y_arr + i * 4;
       int _bf46;
       int* _bf37;
       int _bf47;
       int* _bf49;
       int* _bf54;
       int _bf55;
       bool _bf56;
       int* _bf63;
       int _bf64;
       bool* _bf58;
       bool _bf65;
       int* _bf72;
       int _bf73;
       bool* _bf67;
       bool _bf74;
       int* _bf81;
       int _bf82;
       bool* _bf76;
       bool _bf83;
       int* _bf89;
       int _bf90;
       bool* _bf85;
       bool _bf92;
       int* _bf98;
       int _bf99;
       bool _bf101;
       bool* _bf94;
       int* _bf107;
       int _bf108;
       bool* _bf124;
       bool* _bf133;
       bool* _bf103;
       bool _bf110;
       int* _bf116;
       int _bf117;
       bool* _bf125;
       bool _bf126;
       bool* _bf134;
       bool _bf135;
       bool* _bf112;
       bool _bf119;
       bool* _bf137;
       int* _bf249;
       int _bf250;
       bool _bf4;
       bool _bf16;
       bool* _bf121;
       int _bf252;
       bool _bf8;
       bool _bf20;
       bool* _bf32;
       int* _bf66;
       int* _bf253;
       bool* _bf129;
       bool _bf130;
       bool _bf12;
       bool _bf24;
       bool* _bf36;
       bool _bf131;
       bool* _bf142;
       bool* _bf146;
       int* _bf257;
       int _bf258;
       bool _bf28;
       bool* _bf40;
       bool _bf138;
       bool* _bf143;
       bool _bf144;
       bool* _bf147;
       bool _bf148;
       bool* _bf41;
       int* _bf71;
       int _bf221;
       bool* _bf139;
       bool* _bf150;
       bool _bf151;
       int* _bf75;
       int _bf229;
       bool* _bf152;
       bool* _bf155;
       bool* _bf164;
       int* _bf80;
       int _bf242;
       bool* _bf156;
       bool _bf157;
       bool* _bf160;
       bool _bf161;
       bool* _bf165;
       bool _bf166;
       int* _bf84;
       int _bf245;
       bool _bf162;
       bool* _bf168;
       bool* _bf173;
       bool* _bf177;
       bool _bf44;
       int* _bf88;
       int _bf248;
       bool _bf169;
       bool* _bf174;
       bool _bf175;
       bool* _bf178;
       bool _bf179;
       bool* _bf45;
       int* _bf93;
       int _bf256;
       bool* _bf170;
       bool* _bf181;
       bool _bf182;
       int* _bf97;
       int _bf260;
       bool* _bf183;
       bool* _bf186;
       bool* _bf195;
       int* _bf102;
       int _bf272;
       bool* _bf187;
       bool _bf188;
       bool* _bf191;
       bool _bf192;
       bool* _bf196;
       bool _bf197;
       int* _bf106;
       int _bf276;
       bool _bf193;
       bool* _bf199;
       bool* _bf204;
       bool* _bf208;
       bool _bf48;
       int* _bf111;
       int _bf288;
       bool _bf200;
       bool* _bf205;
       bool _bf206;
       bool* _bf209;
       bool _bf210;
       bool* _bf53;
       int* _bf115;
       int _bf292;
       bool* _bf201;
       bool* _bf212;
       bool _bf213;
       int* _bf120;
       int _bf304;
       bool* _bf214;
       bool* _bf217;
       bool* _bf226;
       int* _bf128;
       int _bf305;
       bool* _bf218;
       bool _bf219;
       bool* _bf222;
       bool _bf223;
       bool* _bf227;
       bool _bf228;
       int* _bf136;
       int _bf310;
       bool _bf224;
       bool* _bf230;
       bool* _bf235;
       bool* _bf239;
       bool _bf57;
       int* _bf149;
       int _bf311;
       bool _bf231;
       bool* _bf236;
       bool _bf237;
       bool* _bf240;
       bool _bf241;
       bool* _bf62;
       int* _bf159;
       int _bf312;
       bool* _bf232;
       bool* _bf243;
       bool _bf244;
       int* _bf167;
       int _bf313;
       bool* _bf1 = _bf1_arr + i * 4;
       bool* _bf261;
       bool _bf262;
       int* _bf180;
       int _bf314;
       int _bf265;
       bool* _bf277;
       bool _bf278;
       int* _bf190;
       int _bf315;
       int _bf266;
       int _bf281;
       bool* _bf293;
       bool _bf294;
       int* _bf198;
       int _bf268;
       int _bf297;
       bool* _bf0 = _bf0_arr + i * 4;
       bool _bf306;
       int* _bf211;
       int _bf318;
       int* _bf269;
       int _bf309;
       int _bf319;
       int _bf323;
       int* _bf273;
       int _bf274;
       int _bf320;
       int _bf324;
       int _bf329;
       int _bf282;
       int* _bf316;
       int _bf325;
       int _bf330;
       int _bf284;
       int* _bf317;
       int _bf326;
       int _bf331;
       int* _bf285;
       int _bf327;
       int _bf332;
       int* _bf289;
       int _bf290;
       int _bf328;
       int _bf333;
       int _bf298;
       int* _bf321;
       int _bf334;
       int _bf300;
       int* _bf322;
       int _bf335;
       int* _bf301;
       int _bf336;
       int* s = s_arr + i * 5;

       #pragma omp parallel sections
       {
           #pragma omp section
               path1(&_bf100);
           #pragma omp section
               path4(&_bf104);
           #pragma omp section
               path5(&_bf105);
           #pragma omp section
               path6(&_bf109);
           #pragma omp section
               path10(&_bf113);
           #pragma omp section
               path11(&_bf114);
           #pragma omp section
               path12(&_bf118);
           #pragma omp section
               path15(&_bf122);
           #pragma omp section
               path16(&_bf123);
           #pragma omp section
               path17(&_bf127);
           #pragma omp section
               path20(&_bf132);
           #pragma omp section
               path24(&_bf14);
           #pragma omp section
               path25(&_bf140);
           #pragma omp section
               path26(&_bf141);
           #pragma omp section
               path27(&_bf145);
           #pragma omp section
               path28(&_bf15);
           #pragma omp section
               path32(&_bf153);
           #pragma omp section
               path33(&_bf154);
           #pragma omp section
               path34(&_bf158);
           #pragma omp section
               path36(&_bf163);
           #pragma omp section
               path40(&_bf171);
           #pragma omp section
               path41(&_bf172);
           #pragma omp section
               path42(&_bf176);
           #pragma omp section
               path46(&_bf184);
           #pragma omp section
               path47(&_bf185);
           #pragma omp section
               path48(&_bf189);
           #pragma omp section
               path49(&_bf19);
           #pragma omp section
               path51(&_bf194);
           #pragma omp section
               path53(&_bf2);
           #pragma omp section
               path56(&_bf202);
           #pragma omp section
               path57(&_bf203);
           #pragma omp section
               path58(&_bf207);
           #pragma omp section
               path62(&_bf215);
           #pragma omp section
               path63(&_bf216);
           #pragma omp section
               path64(&_bf220);
           #pragma omp section
               path66(&_bf225);
           #pragma omp section
               path71(&_bf233);
           #pragma omp section
               path72(&_bf234);
           #pragma omp section
               path73(&_bf238);
           #pragma omp section
               path76(&_bf246);
           #pragma omp section
               path77(&_bf247);
           #pragma omp section
               path79(&_bf251);
           #pragma omp section
               path82(&_bf254);
           #pragma omp section
               path83(&_bf255);
           #pragma omp section
               path84(&_bf259);
           #pragma omp section
               path85(&_bf26);
           #pragma omp section
               path86(&_bf263);
           #pragma omp section
               path87(&_bf264);
           #pragma omp section
               path90(&_bf267);
           #pragma omp section
               path93(&_bf27);
           #pragma omp section
               path94(&_bf270);
           #pragma omp section
               path95(&_bf271);
           #pragma omp section
               path96(&_bf275);
           #pragma omp section
               path97(&_bf279);
           #pragma omp section
               path98(&_bf280);
           #pragma omp section
               path101(&_bf283);
           #pragma omp section
               path104(&_bf286);
           #pragma omp section
               path105(&_bf287);
           #pragma omp section
               path106(&_bf291);
           #pragma omp section
               path107(&_bf295);
           #pragma omp section
               path108(&_bf296);
           #pragma omp section
               path111(&_bf299);
           #pragma omp section
               path112(&_bf3);
           #pragma omp section
               path115(&_bf302);
           #pragma omp section
               path116(&_bf303);
           #pragma omp section
               path117(&_bf307);
           #pragma omp section
               path118(&_bf308);
           #pragma omp section
               path120(&_bf31);
           #pragma omp section
               path123(&_bf38);
           #pragma omp section
               path124(&_bf39);
           #pragma omp section
               path125(&_bf43);
           #pragma omp section
               path128(&_bf50);
           #pragma omp section
               path129(&_bf51);
           #pragma omp section
               path130(&_bf52);
           #pragma omp section
               path133(&_bf59);
           #pragma omp section
               path134(&_bf60);
           #pragma omp section
               path135(&_bf61);
           #pragma omp section
               path138(&_bf68);
           #pragma omp section
               path139(&_bf69);
           #pragma omp section
               path140(&_bf7);
           #pragma omp section
               path141(&_bf70);
           #pragma omp section
               path144(&_bf77);
           #pragma omp section
               path145(&_bf78);
           #pragma omp section
               path146(&_bf79);
           #pragma omp section
               path149(&_bf86);
           #pragma omp section
               path150(&_bf87);
           #pragma omp section
               path151(&_bf91);
           #pragma omp section
               path154(&_bf95);
           #pragma omp section
               path155(&_bf96);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path199(_bf3, x, &_bf5, &_bf6);
           #pragma omp section
               path205(_bf7, y, &_bf9, &_bf10);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path7(_bf6, _bf10, &_bf11);
           #pragma omp section
               path171(_bf15, _bf5, &_bf17, &_bf18);
           #pragma omp section
               path182(_bf19, _bf9, &_bf21, &_bf22);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path18(_bf2, s, _bf11, &_bf13);
           #pragma omp section
               path67(_bf18, _bf22, &_bf23);
           #pragma omp section
               path196(_bf27, _bf17, &_bf29, &_bf30);
           #pragma omp section
               path198(_bf31, _bf21, &_bf33, &_bf34);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path78(_bf14, _bf13, _bf23, &_bf25);
           #pragma omp section
               path121(_bf30, _bf34, &_bf35);
           #pragma omp section
               path207(_bf39, _bf29, &x, &_bf42);
           #pragma omp section
               path208(_bf43, _bf33, &y, &_bf46);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path122(_bf26, _bf25, _bf35, &_bf37);
           #pragma omp section
               path126(_bf42, _bf46, &_bf47);
       }
       path127(_bf38, _bf37, _bf47, &_bf49);
       path200(_bf52, _bf49, &_bf54, &_bf55);
       #pragma omp parallel sections
       {
           #pragma omp section
               path131(_bf51, _bf55, &_bf56);
           #pragma omp section
               path201(_bf61, _bf54, &_bf63, &_bf64);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path132(_bf50, _bf0, _bf56, &_bf58);
           #pragma omp section
               path136(_bf60, _bf64, &_bf65);
           #pragma omp section
               path202(_bf70, _bf63, &_bf72, &_bf73);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path137(_bf59, _bf58, _bf65, &_bf67);
           #pragma omp section
               path142(_bf69, _bf73, &_bf74);
           #pragma omp section
               path203(_bf79, _bf72, &_bf81, &_bf82);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path143(_bf68, _bf67, _bf74, &_bf76);
           #pragma omp section
               path147(_bf78, _bf82, &_bf83);
           #pragma omp section
               path204(_bf87, _bf81, &_bf89, &_bf90);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path148(_bf77, _bf76, _bf83, &_bf85);
           #pragma omp section
               path152(_bf90, _bf91, &_bf92);
           #pragma omp section
               path206(_bf96, _bf89, &_bf98, &_bf99);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path2(_bf99, _bf100, &_bf101);
           #pragma omp section
               path153(_bf86, _bf1, _bf92, &_bf94);
           #pragma omp section
               path158(_bf105, _bf98, &_bf107, &_bf108);
           #pragma omp section
               path160(_bf85, &_bf124, &_bf133);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path3(_bf95, _bf94, _bf101, &_bf103);
           #pragma omp section
               path8(_bf108, _bf109, &_bf110);
           #pragma omp section
               path159(_bf114, _bf107, &_bf116, &_bf117);
           #pragma omp section
               path161(_bf123, _bf124, &_bf125, &_bf126);
           #pragma omp section
               path163(_bf132, _bf133, &_bf134, &_bf135);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path9(_bf104, _bf103, _bf110, &_bf112);
           #pragma omp section
               path13(_bf117, _bf118, &_bf119);
           #pragma omp section
               path21(_bf125, _bf134, &_bf137);
           #pragma omp section
               path190(_bf247, _bf116, &_bf249, &_bf250);
           #pragma omp section
               path209(_bf126, &_bf4);
           #pragma omp section
               path212(_bf135, &_bf16);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path14(_bf113, _bf112, _bf119, &_bf121);
           #pragma omp section
               path80(_bf250, _bf251, &_bf252);
           #pragma omp section
               path210(_bf4, &_bf8);
           #pragma omp section
               path213(_bf16, &_bf20);
           #pragma omp section
               path216(_bf137, &_bf32);
           #pragma omp section
               path226(_bf249, &_bf66);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path81(_bf246, _bf66, _bf252, &_bf253);
           #pragma omp section
               path162(_bf127, _bf121, &_bf129, &_bf130);
           #pragma omp section
               path211(_bf8, &_bf12);
           #pragma omp section
               path214(_bf20, &_bf24);
           #pragma omp section
               path217(_bf32, &_bf36);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path19(_bf12, _bf130, &_bf131);
           #pragma omp section
               path164(_bf129, &_bf142, &_bf146);
           #pragma omp section
               path191(_bf255, _bf253, &_bf257, &_bf258);
           #pragma omp section
               path215(_bf24, &_bf28);
           #pragma omp section
               path218(_bf36, &_bf40);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path22(_bf131, _bf28, &_bf138);
           #pragma omp section
               path165(_bf141, _bf142, &_bf143, &_bf144);
           #pragma omp section
               path166(_bf145, _bf146, &_bf147, &_bf148);
           #pragma omp section
               path219(_bf40, &_bf41);
           #pragma omp section
               path227(_bf257, &_bf71);
           #pragma omp section
               path248(_bf258, &_bf221);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path23(_bf122, _bf41, _bf138, &_bf139);
           #pragma omp section
               path29(_bf143, _bf147, &_bf150);
           #pragma omp section
               path30(_bf144, _bf148, &_bf151);
           #pragma omp section
               path228(_bf71, &_bf75);
           #pragma omp section
               path249(_bf221, &_bf229);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path31(_bf140, _bf150, _bf151, &_bf152);
           #pragma omp section
               path167(_bf139, &_bf155, &_bf164);
           #pragma omp section
               path229(_bf75, &_bf80);
           #pragma omp section
               path250(_bf229, &_bf242);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path168(_bf154, _bf155, &_bf156, &_bf157);
           #pragma omp section
               path169(_bf158, _bf152, &_bf160, &_bf161);
           #pragma omp section
               path170(_bf163, _bf164, &_bf165, &_bf166);
           #pragma omp section
               path230(_bf80, &_bf84);
           #pragma omp section
               path251(_bf242, &_bf245);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path35(_bf157, _bf161, &_bf162);
           #pragma omp section
               path37(_bf156, _bf165, &_bf168);
           #pragma omp section
               path172(_bf160, &_bf173, &_bf177);
           #pragma omp section
               path220(_bf166, &_bf44);
           #pragma omp section
               path231(_bf84, &_bf88);
           #pragma omp section
               path252(_bf245, &_bf248);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path38(_bf162, _bf44, &_bf169);
           #pragma omp section
               path173(_bf172, _bf173, &_bf174, &_bf175);
           #pragma omp section
               path174(_bf176, _bf177, &_bf178, &_bf179);
           #pragma omp section
               path221(_bf168, &_bf45);
           #pragma omp section
               path232(_bf88, &_bf93);
           #pragma omp section
               path253(_bf248, &_bf256);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path39(_bf153, _bf45, _bf169, &_bf170);
           #pragma omp section
               path43(_bf174, _bf178, &_bf181);
           #pragma omp section
               path44(_bf175, _bf179, &_bf182);
           #pragma omp section
               path233(_bf93, &_bf97);
           #pragma omp section
               path254(_bf256, &_bf260);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path45(_bf171, _bf181, _bf182, &_bf183);
           #pragma omp section
               path175(_bf170, &_bf186, &_bf195);
           #pragma omp section
               path234(_bf97, &_bf102);
           #pragma omp section
               path255(_bf260, &_bf272);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path176(_bf185, _bf186, &_bf187, &_bf188);
           #pragma omp section
               path177(_bf189, _bf183, &_bf191, &_bf192);
           #pragma omp section
               path178(_bf194, _bf195, &_bf196, &_bf197);
           #pragma omp section
               path235(_bf102, &_bf106);
           #pragma omp section
               path256(_bf272, &_bf276);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path50(_bf188, _bf192, &_bf193);
           #pragma omp section
               path52(_bf187, _bf196, &_bf199);
           #pragma omp section
               path179(_bf191, &_bf204, &_bf208);
           #pragma omp section
               path222(_bf197, &_bf48);
           #pragma omp section
               path236(_bf106, &_bf111);
           #pragma omp section
               path257(_bf276, &_bf288);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path54(_bf193, _bf48, &_bf200);
           #pragma omp section
               path180(_bf203, _bf204, &_bf205, &_bf206);
           #pragma omp section
               path181(_bf207, _bf208, &_bf209, &_bf210);
           #pragma omp section
               path223(_bf199, &_bf53);
           #pragma omp section
               path237(_bf111, &_bf115);
           #pragma omp section
               path258(_bf288, &_bf292);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path55(_bf184, _bf53, _bf200, &_bf201);
           #pragma omp section
               path59(_bf205, _bf209, &_bf212);
           #pragma omp section
               path60(_bf206, _bf210, &_bf213);
           #pragma omp section
               path238(_bf115, &_bf120);
           #pragma omp section
               path259(_bf292, &_bf304);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path61(_bf202, _bf212, _bf213, &_bf214);
           #pragma omp section
               path183(_bf201, &_bf217, &_bf226);
           #pragma omp section
               path239(_bf120, &_bf128);
           #pragma omp section
               path260(_bf304, &_bf305);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path184(_bf216, _bf217, &_bf218, &_bf219);
           #pragma omp section
               path185(_bf220, _bf214, &_bf222, &_bf223);
           #pragma omp section
               path186(_bf225, _bf226, &_bf227, &_bf228);
           #pragma omp section
               path240(_bf128, &_bf136);
           #pragma omp section
               path261(_bf305, &_bf310);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path65(_bf219, _bf223, &_bf224);
           #pragma omp section
               path68(_bf218, _bf227, &_bf230);
           #pragma omp section
               path187(_bf222, &_bf235, &_bf239);
           #pragma omp section
               path224(_bf228, &_bf57);
           #pragma omp section
               path241(_bf136, &_bf149);
           #pragma omp section
               path262(_bf310, &_bf311);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path69(_bf224, _bf57, &_bf231);
           #pragma omp section
               path188(_bf234, _bf235, &_bf236, &_bf237);
           #pragma omp section
               path189(_bf238, _bf239, &_bf240, &_bf241);
           #pragma omp section
               path225(_bf230, &_bf62);
           #pragma omp section
               path242(_bf149, &_bf159);
           #pragma omp section
               path263(_bf311, &_bf312);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path70(_bf215, _bf62, _bf231, &_bf232);
           #pragma omp section
               path74(_bf236, _bf240, &_bf243);
           #pragma omp section
               path75(_bf237, _bf241, &_bf244);
           #pragma omp section
               path243(_bf159, &_bf167);
           #pragma omp section
               path264(_bf312, &_bf313);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path0(_bf233, _bf243, _bf244, &_bf1);
           #pragma omp section
               path192(_bf259, _bf232, &_bf261, &_bf262);
           #pragma omp section
               path244(_bf167, &_bf180);
           #pragma omp section
               path265(_bf313, &_bf314);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path88(_bf262, _bf263, _bf264, &_bf265);
           #pragma omp section
               path194(_bf275, _bf261, &_bf277, &_bf278);
           #pragma omp section
               path245(_bf180, &_bf190);
           #pragma omp section
               path266(_bf314, &_bf315);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path89(_bf315, _bf265, &_bf266);
           #pragma omp section
               path99(_bf278, _bf279, _bf280, &_bf281);
           #pragma omp section
               path197(_bf291, _bf277, &_bf293, &_bf294);
           #pragma omp section
               path246(_bf190, &_bf198);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path91(_bf266, _bf267, &_bf268);
           #pragma omp section
               path109(_bf294, _bf295, _bf296, &_bf297);
           #pragma omp section
               path157(_bf303, _bf293, &_bf0, &_bf306);
           #pragma omp section
               path247(_bf198, &_bf211);
           #pragma omp section
               path269(_bf281, &_bf318);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path92(_bf254, _bf211, _bf268, &_bf269);
           #pragma omp section
               path119(_bf306, _bf307, _bf308, &_bf309);
           #pragma omp section
               path270(_bf318, &_bf319);
           #pragma omp section
               path274(_bf297, &_bf323);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path193(_bf271, _bf269, &_bf273, &_bf274);
           #pragma omp section
               path271(_bf319, &_bf320);
           #pragma omp section
               path275(_bf323, &_bf324);
           #pragma omp section
               path280(_bf309, &_bf329);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path100(_bf274, _bf320, &_bf282);
           #pragma omp section
               path267(_bf273, &_bf316);
           #pragma omp section
               path276(_bf324, &_bf325);
           #pragma omp section
               path281(_bf329, &_bf330);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path102(_bf282, _bf283, &_bf284);
           #pragma omp section
               path268(_bf316, &_bf317);
           #pragma omp section
               path277(_bf325, &_bf326);
           #pragma omp section
               path282(_bf330, &_bf331);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path103(_bf270, _bf317, _bf284, &_bf285);
           #pragma omp section
               path278(_bf326, &_bf327);
           #pragma omp section
               path283(_bf331, &_bf332);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path195(_bf287, _bf285, &_bf289, &_bf290);
           #pragma omp section
               path279(_bf327, &_bf328);
           #pragma omp section
               path284(_bf332, &_bf333);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path110(_bf290, _bf328, &_bf298);
           #pragma omp section
               path272(_bf289, &_bf321);
           #pragma omp section
               path285(_bf333, &_bf334);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path113(_bf298, _bf299, &_bf300);
           #pragma omp section
               path273(_bf321, &_bf322);
           #pragma omp section
               path286(_bf334, &_bf335);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path114(_bf286, _bf322, _bf300, &_bf301);
           #pragma omp section
               path287(_bf335, &_bf336);
       }
       path156(_bf302, _bf301, _bf336, &s);

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