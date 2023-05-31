#include <stdio.h>
#include <omp.h>
#include <chrono>
#include <iostream>
#include <string>
#include <cstring>
#define DATA_SIZE 1

using namespace std;

void path0(int* _bf0) { 
    *_bf0 = 0;
}
void path1(int _bf3, int _bf7, int* _bf10) { 
    *_bf10 = _bf3 + _bf7;
}
void path2(int _bf94, int _bf98, int* _bf101) { 
    *_bf101 = _bf94 - _bf98;
}
void path3(int _bf395, int _bf101, int* _bf102) { 
    *_bf102 = _bf395 * _bf101;
}
void path4(int _bf56, int _bf104, int* _bf105) { 
    *_bf105 = _bf56 + _bf104;
}
void path5(int _bf100, int _bf107, int* _bf108) { 
    *_bf108 = _bf100 + _bf107;
}
void path6(int* _bf11) { 
    *_bf11 = 1;
}
void path7(int _bf164, int _bf110, int* _bf111) { 
    *_bf111 = _bf164 - _bf110;
}
void path8(int* _bf112) { 
    *_bf112 = 2;
}
void path9(int _bf192, int _bf117, int* _bf118) { 
    *_bf118 = _bf192 - _bf117;
}
void path10(int _bf182, int _bf118, int* _bf119) { 
    *_bf119 = _bf182 * _bf118;
}
void path11(int _bf197, int _bf121, int* _bf122) { 
    *_bf122 = _bf197 + _bf121;
}
void path12(int _bf200, int _bf124, int* _bf125) { 
    *_bf125 = _bf200 - _bf124;
}
void path13(int _bf220, int _bf127, int* _bf128) { 
    *_bf128 = _bf220 + _bf127;
}
void path14(int _bf237, int _bf130, int* _bf131) { 
    *_bf131 = _bf237 - _bf130;
}
void path15(int _bf261, int _bf133, int* _bf134) { 
    *_bf134 = _bf261 + _bf133;
}
void path16(int _bf267, int _bf136, int* _bf137) { 
    *_bf137 = _bf267 + _bf136;
}
void path17(int _bf274, int _bf139, int* _bf140) { 
    *_bf140 = _bf274 - _bf139;
}
void path18(int* _bf141) { 
    *_bf141 = 2;
}
void path19(int _bf302, int _bf146, int* _bf147) { 
    *_bf147 = _bf302 - _bf146;
}
void path20(int _bf296, int _bf147, int* _bf148) { 
    *_bf148 = _bf296 * _bf147;
}
void path21(int* _bf15) { 
    *_bf15 = 5;
}
void path22(int _bf305, int _bf150, int* _bf151) { 
    *_bf151 = _bf305 + _bf150;
}
void path23(int _bf308, int _bf153, int* _bf154) { 
    *_bf154 = _bf308 - _bf153;
}
void path24(int _bf316, int _bf156, int* _bf157) { 
    *_bf157 = _bf316 + _bf156;
}
void path25(int _bf321, int _bf159, int* _bf160) { 
    *_bf160 = _bf321 - _bf159;
}
void path26(int* _bf161) { 
    *_bf161 = 0;
}
void path27(int _bf161, int* y, int _bf122, int** _bf165) { 
    y[_bf161] = _bf122;
    *_bf165 = y;
}
void path28(int* _bf166) { 
    *_bf166 = 1;
}
void path29(int _bf166, int* _bf338, int _bf151, int** _bf170) { 
    _bf338[_bf166] = _bf151;
    *_bf170 = _bf338;
}
void path30(int* _bf171) { 
    *_bf171 = 2;
}
void path31(int _bf171, int* _bf170, int _bf233, int** _bf175) { 
    _bf170[_bf171] = _bf233;
    *_bf175 = _bf170;
}
void path32(int* _bf176) { 
    *_bf176 = 3;
}
void path33(int _bf176, int* _bf175, int _bf317, int** _bf180) { 
    _bf175[_bf176] = _bf317;
    *_bf180 = _bf175;
}
void path34(int* _bf181) { 
    *_bf181 = 4;
}
void path35(int _bf181, int* _bf180, int _bf216, int** _bf185) { 
    _bf180[_bf181] = _bf216;
    *_bf185 = _bf180;
}
void path36(int* _bf186) { 
    *_bf186 = 5;
}
void path37(int _bf186, int* _bf185, int _bf312, int** _bf190) { 
    _bf185[_bf186] = _bf312;
    *_bf190 = _bf185;
}
void path38(int* _bf191) { 
    *_bf191 = 6;
}
void path39(int _bf191, int* _bf190, int _bf254, int** _bf195) { 
    _bf190[_bf191] = _bf254;
    *_bf195 = _bf190;
}
void path40(int* _bf196) { 
    *_bf196 = 7;
}
void path41(int* _bf13, int* _bf17, int** _bf20) { 
    *_bf20 = _bf17;
}
void path42(int _bf14, int _bf18, int* _bf21) { 
    *_bf21 = _bf14 + _bf18;
}
void path43(int* _bf22) { 
    *_bf22 = 2;
}
void path44(int* _bf26) { 
    *_bf26 = 6;
}
void path45(int* _bf24, int* _bf28, int** _bf31) { 
    *_bf31 = _bf28;
}
void path46(int _bf25, int _bf29, int* _bf32) { 
    *_bf32 = _bf25 + _bf29;
}
void path47(int* _bf33) { 
    *_bf33 = 3;
}
void path48(int* _bf37) { 
    *_bf37 = 7;
}
void path49(int* _bf4) { 
    *_bf4 = 4;
}
void path50(int* _bf35, int* _bf39, int** _bf42) { 
    *_bf42 = _bf39;
}
void path51(int _bf36, int _bf40, int* _bf43) { 
    *_bf43 = _bf36 + _bf40;
}
void path52(int* _bf44) { 
    *_bf44 = 0;
}
void path53(int* _bf48) { 
    *_bf48 = 4;
}
void path54(int* _bf46, int* _bf50, int** _bf53) { 
    *_bf53 = _bf50;
}
void path55(int _bf47, int _bf51, int* _bf54) { 
    *_bf54 = _bf47 - _bf51;
}
void path56(int* _bf55) { 
    *_bf55 = 1;
}
void path57(int* _bf59) { 
    *_bf59 = 1;
}
void path58(int* _bf63) { 
    *_bf63 = 5;
}
void path59(int* _bf61, int* _bf65, int** _bf68) { 
    *_bf68 = _bf65;
}
void path60(int _bf62, int _bf66, int* _bf69) { 
    *_bf69 = _bf62 - _bf66;
}
void path61(int _bf355, int _bf69, int* _bf70) { 
    *_bf70 = _bf355 * _bf69;
}
void path62(int* _bf71) { 
    *_bf71 = 2;
}
void path63(int* _bf75) { 
    *_bf75 = 2;
}
void path64(int* _bf79) { 
    *_bf79 = 6;
}
void path65(int* _bf77, int* _bf81, int** _bf84) { 
    *_bf84 = _bf81;
}
void path66(int _bf78, int _bf82, int* _bf85) { 
    *_bf85 = _bf78 - _bf82;
}
void path67(int _bf374, int _bf85, int* _bf86) { 
    *_bf86 = _bf374 * _bf85;
}
void path68(int* _bf87) { 
    *_bf87 = 3;
}
void path69(int* _bf2, int* _bf6, int** _bf9) { 
    *_bf9 = _bf6;
}
void path70(int* _bf91) { 
    *_bf91 = 3;
}
void path71(int* _bf95) { 
    *_bf95 = 7;
}
void path72(int* _bf93, int* _bf97, int** x) { 
    *x = _bf97;
}
void path73(int _bf196, int* _bf195, int _bf326, int** y) { 
    _bf195[_bf196] = _bf326;
    *y = _bf195;
}
void path74(int* x, int** _bf1, int** _bf5) { 
    *_bf1 = x;
    *_bf5 = x;
}
void path75(int _bf10, int* _bf103, int* _bf109) { 
    *_bf103 = _bf10;
    *_bf109 = _bf10;
}
void path76(int _bf32, int* _bf104, int* _bf110) { 
    *_bf104 = _bf32;
    *_bf110 = _bf32;
}
void path77(int _bf21, int* _bf106, int* _bf116) { 
    *_bf106 = _bf21;
    *_bf116 = _bf21;
}
void path78(int _bf43, int* _bf107, int* _bf117) { 
    *_bf107 = _bf43;
    *_bf117 = _bf43;
}
void path79(int _bf112, int* _bf89, int** _bf114, int* _bf115) { 
    *_bf115 = _bf89[_bf112];
    *_bf114 = _bf89;
}
void path80(int* _bf9, int** _bf12, int** _bf16) { 
    *_bf12 = _bf9;
    *_bf16 = _bf9;
}
void path81(int _bf105, int* _bf120, int* _bf123) { 
    *_bf120 = _bf105;
    *_bf123 = _bf105;
}
void path82(int _bf108, int* _bf121, int* _bf124) { 
    *_bf121 = _bf108;
    *_bf124 = _bf108;
}
void path83(int _bf111, int* _bf126, int* _bf129) { 
    *_bf126 = _bf111;
    *_bf129 = _bf111;
}
void path84(int _bf119, int* _bf127, int* _bf130) { 
    *_bf127 = _bf119;
    *_bf130 = _bf119;
}
void path85(int _bf11, int* _bf12, int** _bf13, int* _bf14) { 
    *_bf14 = _bf12[_bf11];
    *_bf13 = _bf12;
}
void path86(int _bf54, int* _bf132, int* _bf138) { 
    *_bf132 = _bf54;
    *_bf138 = _bf54;
}
void path87(int _bf86, int* _bf133, int* _bf139) { 
    *_bf133 = _bf86;
    *_bf139 = _bf86;
}
void path88(int _bf70, int* _bf135, int* _bf145) { 
    *_bf135 = _bf70;
    *_bf145 = _bf70;
}
void path89(int _bf102, int* _bf136, int* _bf146) { 
    *_bf136 = _bf102;
    *_bf146 = _bf102;
}
void path90(int _bf134, int* _bf149, int* _bf152) { 
    *_bf149 = _bf134;
    *_bf152 = _bf134;
}
void path91(int _bf137, int* _bf150, int* _bf153) { 
    *_bf150 = _bf137;
    *_bf153 = _bf137;
}
void path92(int _bf140, int* _bf155, int* _bf158) { 
    *_bf155 = _bf140;
    *_bf158 = _bf140;
}
void path93(int _bf148, int* _bf156, int* _bf159) { 
    *_bf156 = _bf148;
    *_bf159 = _bf148;
}
void path94(int _bf15, int* _bf16, int** _bf17, int* _bf18) { 
    *_bf18 = _bf16[_bf15];
    *_bf17 = _bf16;
}
void path95(int _bf0, int* _bf1, int** _bf2, int* _bf3) { 
    *_bf3 = _bf1[_bf0];
    *_bf2 = _bf1;
}
void path96(int* _bf20, int** _bf23, int** _bf27) { 
    *_bf23 = _bf20;
    *_bf27 = _bf20;
}
void path97(int _bf22, int* _bf23, int** _bf24, int* _bf25) { 
    *_bf25 = _bf23[_bf22];
    *_bf24 = _bf23;
}
void path98(int _bf26, int* _bf27, int** _bf28, int* _bf29) { 
    *_bf29 = _bf27[_bf26];
    *_bf28 = _bf27;
}
void path99(int* _bf31, int** _bf34, int** _bf38) { 
    *_bf34 = _bf31;
    *_bf38 = _bf31;
}
void path100(int _bf33, int* _bf34, int** _bf35, int* _bf36) { 
    *_bf36 = _bf34[_bf33];
    *_bf35 = _bf34;
}
void path101(int _bf37, int* _bf38, int** _bf39, int* _bf40) { 
    *_bf40 = _bf38[_bf37];
    *_bf39 = _bf38;
}
void path102(int* _bf42, int** _bf45, int** _bf49) { 
    *_bf45 = _bf42;
    *_bf49 = _bf42;
}
void path103(int _bf44, int* _bf45, int** _bf46, int* _bf47) { 
    *_bf47 = _bf45[_bf44];
    *_bf46 = _bf45;
}
void path104(int _bf48, int* _bf49, int** _bf50, int* _bf51) { 
    *_bf51 = _bf49[_bf48];
    *_bf50 = _bf49;
}
void path105(int _bf55, int* w, int** _bf57, int* _bf58) { 
    *_bf58 = w[_bf55];
    *_bf57 = w;
}
void path106(int _bf4, int* _bf5, int** _bf6, int* _bf7) { 
    *_bf7 = _bf5[_bf4];
    *_bf6 = _bf5;
}
void path107(int* _bf53, int** _bf60, int** _bf64) { 
    *_bf60 = _bf53;
    *_bf64 = _bf53;
}
void path108(int _bf59, int* _bf60, int** _bf61, int* _bf62) { 
    *_bf62 = _bf60[_bf59];
    *_bf61 = _bf60;
}
void path109(int _bf63, int* _bf64, int** _bf65, int* _bf66) { 
    *_bf66 = _bf64[_bf63];
    *_bf65 = _bf64;
}
void path110(int _bf71, int* _bf57, int** _bf73, int* _bf74) { 
    *_bf74 = _bf57[_bf71];
    *_bf73 = _bf57;
}
void path111(int* _bf68, int** _bf76, int** _bf80) { 
    *_bf76 = _bf68;
    *_bf80 = _bf68;
}
void path112(int _bf75, int* _bf76, int** _bf77, int* _bf78) { 
    *_bf78 = _bf76[_bf75];
    *_bf77 = _bf76;
}
void path113(int _bf79, int* _bf80, int** _bf81, int* _bf82) { 
    *_bf82 = _bf80[_bf79];
    *_bf81 = _bf80;
}
void path114(int _bf87, int* _bf73, int** _bf89, int* _bf90) { 
    *_bf90 = _bf73[_bf87];
    *_bf89 = _bf73;
}
void path115(int* _bf84, int** _bf92, int** _bf96) { 
    *_bf92 = _bf84;
    *_bf96 = _bf84;
}
void path116(int _bf91, int* _bf92, int** _bf93, int* _bf94) { 
    *_bf94 = _bf92[_bf91];
    *_bf93 = _bf92;
}
void path117(int _bf95, int* _bf96, int** _bf97, int* _bf98) { 
    *_bf98 = _bf96[_bf95];
    *_bf97 = _bf96;
}
void path118(int _bf141, int* _bf114, int** w, int* _bf144) { 
    *_bf144 = _bf114[_bf141];
    *w = _bf114;
}
void path119(int _bf103, int* _bf8) { 
    *_bf8 = _bf103;
}
void path120(int _bf8, int* _bf19) { 
    *_bf19 = _bf8;
}
void path121(int _bf19, int* _bf30) { 
    *_bf30 = _bf19;
}
void path122(int _bf30, int* _bf41) { 
    *_bf41 = _bf30;
}
void path123(int _bf41, int* _bf52) { 
    *_bf52 = _bf41;
}
void path124(int _bf52, int* _bf56) { 
    *_bf56 = _bf52;
}
void path125(int _bf106, int* _bf67) { 
    *_bf67 = _bf106;
}
void path126(int _bf67, int* _bf72) { 
    *_bf72 = _bf67;
}
void path127(int _bf72, int* _bf83) { 
    *_bf83 = _bf72;
}
void path128(int _bf83, int* _bf88) { 
    *_bf88 = _bf83;
}
void path129(int _bf88, int* _bf99) { 
    *_bf99 = _bf88;
}
void path130(int _bf99, int* _bf100) { 
    *_bf100 = _bf99;
}
void path131(int _bf109, int* _bf113) { 
    *_bf113 = _bf109;
}
void path132(int _bf113, int* _bf142) { 
    *_bf142 = _bf113;
}
void path133(int _bf142, int* _bf143) { 
    *_bf143 = _bf142;
}
void path134(int _bf143, int* _bf162) { 
    *_bf162 = _bf143;
}
void path135(int _bf162, int* _bf163) { 
    *_bf163 = _bf162;
}
void path136(int _bf163, int* _bf164) { 
    *_bf164 = _bf163;
}
void path137(int _bf115, int* _bf167) { 
    *_bf167 = _bf115;
}
void path138(int _bf167, int* _bf168) { 
    *_bf168 = _bf167;
}
void path139(int _bf168, int* _bf169) { 
    *_bf169 = _bf168;
}
void path140(int _bf169, int* _bf172) { 
    *_bf172 = _bf169;
}
void path141(int _bf172, int* _bf173) { 
    *_bf173 = _bf172;
}
void path142(int _bf173, int* _bf174) { 
    *_bf174 = _bf173;
}
void path143(int _bf174, int* _bf177) { 
    *_bf177 = _bf174;
}
void path144(int _bf177, int* _bf178) { 
    *_bf178 = _bf177;
}
void path145(int _bf178, int* _bf179) { 
    *_bf179 = _bf178;
}
void path146(int _bf179, int* _bf182) { 
    *_bf182 = _bf179;
}
void path147(int _bf116, int* _bf183) { 
    *_bf183 = _bf116;
}
void path148(int _bf183, int* _bf184) { 
    *_bf184 = _bf183;
}
void path149(int _bf184, int* _bf187) { 
    *_bf187 = _bf184;
}
void path150(int _bf187, int* _bf188) { 
    *_bf188 = _bf187;
}
void path151(int _bf188, int* _bf189) { 
    *_bf189 = _bf188;
}
void path152(int _bf189, int* _bf192) { 
    *_bf192 = _bf189;
}
void path153(int _bf120, int* _bf193) { 
    *_bf193 = _bf120;
}
void path154(int _bf193, int* _bf194) { 
    *_bf194 = _bf193;
}
void path155(int _bf194, int* _bf197) { 
    *_bf197 = _bf194;
}
void path156(int _bf123, int* _bf198) { 
    *_bf198 = _bf123;
}
void path157(int _bf198, int* _bf199) { 
    *_bf199 = _bf198;
}
void path158(int _bf199, int* _bf200) { 
    *_bf200 = _bf199;
}
void path159(int _bf125, int* _bf201) { 
    *_bf201 = _bf125;
}
void path160(int _bf201, int* _bf202) { 
    *_bf202 = _bf201;
}
void path161(int _bf202, int* _bf203) { 
    *_bf203 = _bf202;
}
void path162(int _bf203, int* _bf204) { 
    *_bf204 = _bf203;
}
void path163(int _bf204, int* _bf205) { 
    *_bf205 = _bf204;
}
void path164(int _bf205, int* _bf206) { 
    *_bf206 = _bf205;
}
void path165(int _bf206, int* _bf207) { 
    *_bf207 = _bf206;
}
void path166(int _bf207, int* _bf208) { 
    *_bf208 = _bf207;
}
void path167(int _bf208, int* _bf209) { 
    *_bf209 = _bf208;
}
void path168(int _bf209, int* _bf210) { 
    *_bf210 = _bf209;
}
void path169(int _bf210, int* _bf211) { 
    *_bf211 = _bf210;
}
void path170(int _bf211, int* _bf212) { 
    *_bf212 = _bf211;
}
void path171(int _bf212, int* _bf213) { 
    *_bf213 = _bf212;
}
void path172(int _bf213, int* _bf214) { 
    *_bf214 = _bf213;
}
void path173(int _bf214, int* _bf215) { 
    *_bf215 = _bf214;
}
void path174(int _bf215, int* _bf216) { 
    *_bf216 = _bf215;
}
void path175(int _bf126, int* _bf217) { 
    *_bf217 = _bf126;
}
void path176(int _bf217, int* _bf218) { 
    *_bf218 = _bf217;
}
void path177(int _bf218, int* _bf219) { 
    *_bf219 = _bf218;
}
void path178(int _bf219, int* _bf220) { 
    *_bf220 = _bf219;
}
void path179(int _bf128, int* _bf221) { 
    *_bf221 = _bf128;
}
void path180(int _bf221, int* _bf222) { 
    *_bf222 = _bf221;
}
void path181(int _bf222, int* _bf223) { 
    *_bf223 = _bf222;
}
void path182(int _bf223, int* _bf224) { 
    *_bf224 = _bf223;
}
void path183(int _bf224, int* _bf225) { 
    *_bf225 = _bf224;
}
void path184(int _bf225, int* _bf226) { 
    *_bf226 = _bf225;
}
void path185(int _bf226, int* _bf227) { 
    *_bf227 = _bf226;
}
void path186(int _bf227, int* _bf228) { 
    *_bf228 = _bf227;
}
void path187(int _bf228, int* _bf229) { 
    *_bf229 = _bf228;
}
void path188(int _bf229, int* _bf230) { 
    *_bf230 = _bf229;
}
void path189(int _bf230, int* _bf231) { 
    *_bf231 = _bf230;
}
void path190(int _bf231, int* _bf232) { 
    *_bf232 = _bf231;
}
void path191(int _bf232, int* _bf233) { 
    *_bf233 = _bf232;
}
void path192(int _bf129, int* _bf234) { 
    *_bf234 = _bf129;
}
void path193(int _bf234, int* _bf235) { 
    *_bf235 = _bf234;
}
void path194(int _bf235, int* _bf236) { 
    *_bf236 = _bf235;
}
void path195(int _bf236, int* _bf237) { 
    *_bf237 = _bf236;
}
void path196(int _bf131, int* _bf238) { 
    *_bf238 = _bf131;
}
void path197(int _bf238, int* _bf239) { 
    *_bf239 = _bf238;
}
void path198(int _bf239, int* _bf240) { 
    *_bf240 = _bf239;
}
void path199(int _bf240, int* _bf241) { 
    *_bf241 = _bf240;
}
void path200(int _bf241, int* _bf242) { 
    *_bf242 = _bf241;
}
void path201(int _bf242, int* _bf243) { 
    *_bf243 = _bf242;
}
void path202(int _bf243, int* _bf244) { 
    *_bf244 = _bf243;
}
void path203(int _bf244, int* _bf245) { 
    *_bf245 = _bf244;
}
void path204(int _bf245, int* _bf246) { 
    *_bf246 = _bf245;
}
void path205(int _bf246, int* _bf247) { 
    *_bf247 = _bf246;
}
void path206(int _bf247, int* _bf248) { 
    *_bf248 = _bf247;
}
void path207(int _bf248, int* _bf249) { 
    *_bf249 = _bf248;
}
void path208(int _bf249, int* _bf250) { 
    *_bf250 = _bf249;
}
void path209(int _bf250, int* _bf251) { 
    *_bf251 = _bf250;
}
void path210(int _bf251, int* _bf252) { 
    *_bf252 = _bf251;
}
void path211(int _bf252, int* _bf253) { 
    *_bf253 = _bf252;
}
void path212(int _bf253, int* _bf254) { 
    *_bf254 = _bf253;
}
void path213(int _bf132, int* _bf255) { 
    *_bf255 = _bf132;
}
void path214(int _bf255, int* _bf256) { 
    *_bf256 = _bf255;
}
void path215(int _bf256, int* _bf257) { 
    *_bf257 = _bf256;
}
void path216(int _bf257, int* _bf258) { 
    *_bf258 = _bf257;
}
void path217(int _bf258, int* _bf259) { 
    *_bf259 = _bf258;
}
void path218(int _bf259, int* _bf260) { 
    *_bf260 = _bf259;
}
void path219(int _bf260, int* _bf261) { 
    *_bf261 = _bf260;
}
void path220(int _bf135, int* _bf262) { 
    *_bf262 = _bf135;
}
void path221(int _bf262, int* _bf263) { 
    *_bf263 = _bf262;
}
void path222(int _bf263, int* _bf264) { 
    *_bf264 = _bf263;
}
void path223(int _bf264, int* _bf265) { 
    *_bf265 = _bf264;
}
void path224(int _bf265, int* _bf266) { 
    *_bf266 = _bf265;
}
void path225(int _bf266, int* _bf267) { 
    *_bf267 = _bf266;
}
void path226(int _bf138, int* _bf268) { 
    *_bf268 = _bf138;
}
void path227(int _bf268, int* _bf269) { 
    *_bf269 = _bf268;
}
void path228(int _bf269, int* _bf270) { 
    *_bf270 = _bf269;
}
void path229(int _bf270, int* _bf271) { 
    *_bf271 = _bf270;
}
void path230(int _bf271, int* _bf272) { 
    *_bf272 = _bf271;
}
void path231(int _bf272, int* _bf273) { 
    *_bf273 = _bf272;
}
void path232(int _bf273, int* _bf274) { 
    *_bf274 = _bf273;
}
void path233(int _bf144, int* _bf275) { 
    *_bf275 = _bf144;
}
void path234(int _bf275, int* _bf276) { 
    *_bf276 = _bf275;
}
void path235(int _bf276, int* _bf277) { 
    *_bf277 = _bf276;
}
void path236(int _bf277, int* _bf278) { 
    *_bf278 = _bf277;
}
void path237(int _bf278, int* _bf279) { 
    *_bf279 = _bf278;
}
void path238(int _bf279, int* _bf280) { 
    *_bf280 = _bf279;
}
void path239(int _bf280, int* _bf281) { 
    *_bf281 = _bf280;
}
void path240(int _bf281, int* _bf282) { 
    *_bf282 = _bf281;
}
void path241(int _bf282, int* _bf283) { 
    *_bf283 = _bf282;
}
void path242(int _bf283, int* _bf284) { 
    *_bf284 = _bf283;
}
void path243(int _bf284, int* _bf285) { 
    *_bf285 = _bf284;
}
void path244(int _bf285, int* _bf286) { 
    *_bf286 = _bf285;
}
void path245(int _bf286, int* _bf287) { 
    *_bf287 = _bf286;
}
void path246(int _bf287, int* _bf288) { 
    *_bf288 = _bf287;
}
void path247(int _bf288, int* _bf289) { 
    *_bf289 = _bf288;
}
void path248(int _bf289, int* _bf290) { 
    *_bf290 = _bf289;
}
void path249(int _bf290, int* _bf291) { 
    *_bf291 = _bf290;
}
void path250(int _bf291, int* _bf292) { 
    *_bf292 = _bf291;
}
void path251(int _bf292, int* _bf293) { 
    *_bf293 = _bf292;
}
void path252(int _bf293, int* _bf294) { 
    *_bf294 = _bf293;
}
void path253(int _bf294, int* _bf295) { 
    *_bf295 = _bf294;
}
void path254(int _bf295, int* _bf296) { 
    *_bf296 = _bf295;
}
void path255(int _bf145, int* _bf297) { 
    *_bf297 = _bf145;
}
void path256(int _bf297, int* _bf298) { 
    *_bf298 = _bf297;
}
void path257(int _bf298, int* _bf299) { 
    *_bf299 = _bf298;
}
void path258(int _bf299, int* _bf300) { 
    *_bf300 = _bf299;
}
void path259(int _bf300, int* _bf301) { 
    *_bf301 = _bf300;
}
void path260(int _bf301, int* _bf302) { 
    *_bf302 = _bf301;
}
void path261(int _bf149, int* _bf303) { 
    *_bf303 = _bf149;
}
void path262(int _bf303, int* _bf304) { 
    *_bf304 = _bf303;
}
void path263(int _bf304, int* _bf305) { 
    *_bf305 = _bf304;
}
void path264(int _bf152, int* _bf306) { 
    *_bf306 = _bf152;
}
void path265(int _bf306, int* _bf307) { 
    *_bf307 = _bf306;
}
void path266(int _bf307, int* _bf308) { 
    *_bf308 = _bf307;
}
void path267(int _bf154, int* _bf309) { 
    *_bf309 = _bf154;
}
void path268(int _bf309, int* _bf310) { 
    *_bf310 = _bf309;
}
void path269(int _bf310, int* _bf311) { 
    *_bf311 = _bf310;
}
void path270(int _bf311, int* _bf312) { 
    *_bf312 = _bf311;
}
void path271(int _bf155, int* _bf313) { 
    *_bf313 = _bf155;
}
void path272(int _bf313, int* _bf314) { 
    *_bf314 = _bf313;
}
void path273(int _bf314, int* _bf315) { 
    *_bf315 = _bf314;
}
void path274(int _bf315, int* _bf316) { 
    *_bf316 = _bf315;
}
void path275(int _bf157, int* _bf317) { 
    *_bf317 = _bf157;
}
void path276(int _bf158, int* _bf318) { 
    *_bf318 = _bf158;
}
void path277(int _bf318, int* _bf319) { 
    *_bf319 = _bf318;
}
void path278(int _bf319, int* _bf320) { 
    *_bf320 = _bf319;
}
void path279(int _bf320, int* _bf321) { 
    *_bf321 = _bf320;
}
void path280(int _bf160, int* _bf322) { 
    *_bf322 = _bf160;
}
void path281(int _bf322, int* _bf323) { 
    *_bf323 = _bf322;
}
void path282(int _bf323, int* _bf324) { 
    *_bf324 = _bf323;
}
void path283(int _bf324, int* _bf325) { 
    *_bf325 = _bf324;
}
void path284(int _bf325, int* _bf326) { 
    *_bf326 = _bf325;
}
void path285(int* _bf165, int** _bf327) { 
    *_bf327 = _bf165;
}
void path286(int* _bf327, int** _bf328) { 
    *_bf328 = _bf327;
}
void path287(int* _bf328, int** _bf329) { 
    *_bf329 = _bf328;
}
void path288(int* _bf329, int** _bf330) { 
    *_bf330 = _bf329;
}
void path289(int* _bf330, int** _bf331) { 
    *_bf331 = _bf330;
}
void path290(int* _bf331, int** _bf332) { 
    *_bf332 = _bf331;
}
void path291(int* _bf332, int** _bf333) { 
    *_bf333 = _bf332;
}
void path292(int* _bf333, int** _bf334) { 
    *_bf334 = _bf333;
}
void path293(int* _bf334, int** _bf335) { 
    *_bf335 = _bf334;
}
void path294(int* _bf335, int** _bf336) { 
    *_bf336 = _bf335;
}
void path295(int* _bf336, int** _bf337) { 
    *_bf337 = _bf336;
}
void path296(int* _bf337, int** _bf338) { 
    *_bf338 = _bf337;
}
void path297(int _bf58, int* _bf339) { 
    *_bf339 = _bf58;
}
void path298(int _bf339, int* _bf340) { 
    *_bf340 = _bf339;
}
void path299(int _bf340, int* _bf341) { 
    *_bf341 = _bf340;
}
void path300(int _bf341, int* _bf342) { 
    *_bf342 = _bf341;
}
void path301(int _bf342, int* _bf343) { 
    *_bf343 = _bf342;
}
void path302(int _bf343, int* _bf344) { 
    *_bf344 = _bf343;
}
void path303(int _bf344, int* _bf345) { 
    *_bf345 = _bf344;
}
void path304(int _bf345, int* _bf346) { 
    *_bf346 = _bf345;
}
void path305(int _bf346, int* _bf347) { 
    *_bf347 = _bf346;
}
void path306(int _bf347, int* _bf348) { 
    *_bf348 = _bf347;
}
void path307(int _bf348, int* _bf349) { 
    *_bf349 = _bf348;
}
void path308(int _bf349, int* _bf350) { 
    *_bf350 = _bf349;
}
void path309(int _bf350, int* _bf351) { 
    *_bf351 = _bf350;
}
void path310(int _bf351, int* _bf352) { 
    *_bf352 = _bf351;
}
void path311(int _bf352, int* _bf353) { 
    *_bf353 = _bf352;
}
void path312(int _bf353, int* _bf354) { 
    *_bf354 = _bf353;
}
void path313(int _bf354, int* _bf355) { 
    *_bf355 = _bf354;
}
void path314(int _bf74, int* _bf356) { 
    *_bf356 = _bf74;
}
void path315(int _bf356, int* _bf357) { 
    *_bf357 = _bf356;
}
void path316(int _bf357, int* _bf358) { 
    *_bf358 = _bf357;
}
void path317(int _bf358, int* _bf359) { 
    *_bf359 = _bf358;
}
void path318(int _bf359, int* _bf360) { 
    *_bf360 = _bf359;
}
void path319(int _bf360, int* _bf361) { 
    *_bf361 = _bf360;
}
void path320(int _bf361, int* _bf362) { 
    *_bf362 = _bf361;
}
void path321(int _bf362, int* _bf363) { 
    *_bf363 = _bf362;
}
void path322(int _bf363, int* _bf364) { 
    *_bf364 = _bf363;
}
void path323(int _bf364, int* _bf365) { 
    *_bf365 = _bf364;
}
void path324(int _bf365, int* _bf366) { 
    *_bf366 = _bf365;
}
void path325(int _bf366, int* _bf367) { 
    *_bf367 = _bf366;
}
void path326(int _bf367, int* _bf368) { 
    *_bf368 = _bf367;
}
void path327(int _bf368, int* _bf369) { 
    *_bf369 = _bf368;
}
void path328(int _bf369, int* _bf370) { 
    *_bf370 = _bf369;
}
void path329(int _bf370, int* _bf371) { 
    *_bf371 = _bf370;
}
void path330(int _bf371, int* _bf372) { 
    *_bf372 = _bf371;
}
void path331(int _bf372, int* _bf373) { 
    *_bf373 = _bf372;
}
void path332(int _bf373, int* _bf374) { 
    *_bf374 = _bf373;
}
void path333(int _bf90, int* _bf375) { 
    *_bf375 = _bf90;
}
void path334(int _bf375, int* _bf376) { 
    *_bf376 = _bf375;
}
void path335(int _bf376, int* _bf377) { 
    *_bf377 = _bf376;
}
void path336(int _bf377, int* _bf378) { 
    *_bf378 = _bf377;
}
void path337(int _bf378, int* _bf379) { 
    *_bf379 = _bf378;
}
void path338(int _bf379, int* _bf380) { 
    *_bf380 = _bf379;
}
void path339(int _bf380, int* _bf381) { 
    *_bf381 = _bf380;
}
void path340(int _bf381, int* _bf382) { 
    *_bf382 = _bf381;
}
void path341(int _bf382, int* _bf383) { 
    *_bf383 = _bf382;
}
void path342(int _bf383, int* _bf384) { 
    *_bf384 = _bf383;
}
void path343(int _bf384, int* _bf385) { 
    *_bf385 = _bf384;
}
void path344(int _bf385, int* _bf386) { 
    *_bf386 = _bf385;
}
void path345(int _bf386, int* _bf387) { 
    *_bf387 = _bf386;
}
void path346(int _bf387, int* _bf388) { 
    *_bf388 = _bf387;
}
void path347(int _bf388, int* _bf389) { 
    *_bf389 = _bf388;
}
void path348(int _bf389, int* _bf390) { 
    *_bf390 = _bf389;
}
void path349(int _bf390, int* _bf391) { 
    *_bf391 = _bf390;
}
void path350(int _bf391, int* _bf392) { 
    *_bf392 = _bf391;
}
void path351(int _bf392, int* _bf393) { 
    *_bf393 = _bf392;
}
void path352(int _bf393, int* _bf394) { 
    *_bf394 = _bf393;
}
void path353(int _bf394, int* _bf395) { 
    *_bf395 = _bf394;
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
       int _bf0;
       int _bf11;
       int _bf112;
       int _bf141;
       int _bf15;
       int _bf161;
       int _bf166;
       int _bf171;
       int _bf176;
       int _bf181;
       int _bf186;
       int _bf191;
       int _bf196;
       int _bf22;
       int _bf26;
       int _bf33;
       int _bf37;
       int _bf4;
       int _bf44;
       int _bf48;
       int _bf55;
       int _bf59;
       int _bf63;
       int _bf71;
       int _bf75;
       int _bf79;
       int _bf87;
       int _bf91;
       int _bf95;
       int* _bf1;
       int* _bf5;
       int* _bf2;
       int _bf3;
       int* _bf57;
       int _bf58;
       int* _bf6;
       int _bf7;
       int _bf10;
       int* _bf9;
       int* _bf73;
       int _bf74;
       int _bf339;
       int _bf103;
       int _bf109;
       int* _bf12;
       int* _bf16;
       int* _bf89;
       int _bf90;
       int _bf340;
       int _bf356;
       int* _bf114;
       int _bf115;
       int* _bf13;
       int _bf14;
       int* _bf17;
       int _bf18;
       int _bf8;
       int _bf113;
       int _bf341;
       int _bf357;
       int _bf375;
       int* _bf20;
       int _bf21;
       int* w = w_arr + i * 8;
       int _bf144;
       int _bf19;
       int _bf142;
       int _bf167;
       int _bf342;
       int _bf358;
       int _bf376;
       int _bf106;
       int _bf116;
       int* _bf23;
       int* _bf27;
       int _bf30;
       int _bf143;
       int _bf168;
       int _bf275;
       int _bf343;
       int _bf359;
       int _bf377;
       int* _bf24;
       int _bf25;
       int* _bf28;
       int _bf29;
       int _bf41;
       int _bf67;
       int _bf162;
       int _bf169;
       int _bf183;
       int _bf276;
       int _bf344;
       int _bf360;
       int _bf378;
       int* _bf31;
       int _bf32;
       int _bf52;
       int _bf72;
       int _bf163;
       int _bf172;
       int _bf184;
       int _bf277;
       int _bf345;
       int _bf361;
       int _bf379;
       int _bf104;
       int _bf110;
       int* _bf34;
       int* _bf38;
       int _bf56;
       int _bf83;
       int _bf164;
       int _bf173;
       int _bf187;
       int _bf278;
       int _bf346;
       int _bf362;
       int _bf380;
       int _bf105;
       int _bf111;
       int* _bf35;
       int _bf36;
       int* _bf39;
       int _bf40;
       int _bf88;
       int _bf174;
       int _bf188;
       int _bf279;
       int _bf347;
       int _bf363;
       int _bf381;
       int* _bf42;
       int _bf43;
       int _bf120;
       int _bf123;
       int _bf126;
       int _bf129;
       int _bf99;
       int _bf177;
       int _bf189;
       int _bf280;
       int _bf348;
       int _bf364;
       int _bf382;
       int _bf107;
       int _bf117;
       int* _bf45;
       int* _bf49;
       int _bf100;
       int _bf178;
       int _bf192;
       int _bf193;
       int _bf198;
       int _bf217;
       int _bf234;
       int _bf281;
       int _bf349;
       int _bf365;
       int _bf383;
       int _bf108;
       int _bf118;
       int* _bf46;
       int _bf47;
       int* _bf50;
       int _bf51;
       int _bf179;
       int _bf194;
       int _bf199;
       int _bf218;
       int _bf235;
       int _bf282;
       int _bf350;
       int _bf366;
       int _bf384;
       int* _bf53;
       int _bf54;
       int _bf121;
       int _bf124;
       int _bf182;
       int _bf197;
       int _bf200;
       int _bf219;
       int _bf236;
       int _bf283;
       int _bf351;
       int _bf367;
       int _bf385;
       int _bf119;
       int _bf122;
       int _bf125;
       int _bf132;
       int _bf138;
       int* _bf60;
       int* _bf64;
       int _bf220;
       int _bf237;
       int _bf284;
       int _bf352;
       int _bf368;
       int _bf386;
       int* _bf165;
       int _bf127;
       int _bf130;
       int* _bf61;
       int _bf62;
       int* _bf65;
       int _bf66;
       int _bf201;
       int _bf255;
       int _bf268;
       int _bf285;
       int _bf353;
       int _bf369;
       int _bf387;
       int _bf128;
       int _bf131;
       int* _bf68;
       int _bf69;
       int _bf202;
       int _bf256;
       int _bf269;
       int _bf286;
       int* _bf327;
       int _bf354;
       int _bf370;
       int _bf388;
       int* _bf76;
       int* _bf80;
       int _bf203;
       int _bf221;
       int _bf238;
       int _bf257;
       int _bf270;
       int _bf287;
       int* _bf328;
       int _bf355;
       int _bf371;
       int _bf389;
       int _bf70;
       int* _bf77;
       int _bf78;
       int* _bf81;
       int _bf82;
       int _bf204;
       int _bf222;
       int _bf239;
       int _bf258;
       int _bf271;
       int _bf288;
       int* _bf329;
       int _bf372;
       int _bf390;
       int* _bf84;
       int _bf85;
       int _bf135;
       int _bf145;
       int _bf205;
       int _bf223;
       int _bf240;
       int _bf259;
       int _bf272;
       int _bf289;
       int* _bf330;
       int _bf373;
       int _bf391;
       int* _bf92;
       int* _bf96;
       int _bf206;
       int _bf224;
       int _bf241;
       int _bf260;
       int _bf262;
       int _bf273;
       int _bf290;
       int _bf297;
       int* _bf331;
       int _bf374;
       int _bf392;
       int _bf86;
       int* _bf93;
       int _bf94;
       int* _bf97;
       int _bf98;
       int _bf207;
       int _bf225;
       int _bf242;
       int _bf261;
       int _bf263;
       int _bf274;
       int _bf291;
       int _bf298;
       int* _bf332;
       int _bf393;
       int _bf101;
       int* x = x_arr + i * 8;
       int _bf133;
       int _bf139;
       int _bf208;
       int _bf226;
       int _bf243;
       int _bf264;
       int _bf292;
       int _bf299;
       int* _bf333;
       int _bf394;
       int _bf134;
       int _bf140;
       int _bf209;
       int _bf227;
       int _bf244;
       int _bf265;
       int _bf293;
       int _bf300;
       int* _bf334;
       int _bf395;
       int _bf102;
       int _bf149;
       int _bf152;
       int _bf155;
       int _bf158;
       int _bf210;
       int _bf228;
       int _bf245;
       int _bf266;
       int _bf294;
       int _bf301;
       int* _bf335;
       int _bf136;
       int _bf146;
       int _bf211;
       int _bf229;
       int _bf246;
       int _bf267;
       int _bf295;
       int _bf302;
       int _bf303;
       int _bf306;
       int _bf313;
       int _bf318;
       int* _bf336;
       int _bf137;
       int _bf147;
       int _bf212;
       int _bf230;
       int _bf247;
       int _bf296;
       int _bf304;
       int _bf307;
       int _bf314;
       int _bf319;
       int* _bf337;
       int _bf148;
       int _bf150;
       int _bf153;
       int _bf213;
       int _bf231;
       int _bf248;
       int _bf305;
       int _bf308;
       int _bf315;
       int _bf320;
       int* _bf338;
       int _bf151;
       int _bf154;
       int _bf156;
       int _bf159;
       int _bf214;
       int _bf232;
       int _bf249;
       int _bf316;
       int _bf321;
       int _bf157;
       int _bf160;
       int* _bf170;
       int _bf215;
       int _bf233;
       int _bf250;
       int _bf309;
       int* _bf175;
       int _bf216;
       int _bf251;
       int _bf310;
       int _bf317;
       int _bf322;
       int* _bf180;
       int _bf252;
       int _bf311;
       int _bf323;
       int* _bf185;
       int _bf253;
       int _bf312;
       int _bf324;
       int* _bf190;
       int _bf254;
       int _bf325;
       int* _bf195;
       int _bf326;
       int* y = y_arr + i * 8;

       #pragma omp parallel sections
       {
           #pragma omp section
               path0(&_bf0);
           #pragma omp section
               path6(&_bf11);
           #pragma omp section
               path8(&_bf112);
           #pragma omp section
               path18(&_bf141);
           #pragma omp section
               path21(&_bf15);
           #pragma omp section
               path26(&_bf161);
           #pragma omp section
               path28(&_bf166);
           #pragma omp section
               path30(&_bf171);
           #pragma omp section
               path32(&_bf176);
           #pragma omp section
               path34(&_bf181);
           #pragma omp section
               path36(&_bf186);
           #pragma omp section
               path38(&_bf191);
           #pragma omp section
               path40(&_bf196);
           #pragma omp section
               path43(&_bf22);
           #pragma omp section
               path44(&_bf26);
           #pragma omp section
               path47(&_bf33);
           #pragma omp section
               path48(&_bf37);
           #pragma omp section
               path49(&_bf4);
           #pragma omp section
               path52(&_bf44);
           #pragma omp section
               path53(&_bf48);
           #pragma omp section
               path56(&_bf55);
           #pragma omp section
               path57(&_bf59);
           #pragma omp section
               path58(&_bf63);
           #pragma omp section
               path62(&_bf71);
           #pragma omp section
               path63(&_bf75);
           #pragma omp section
               path64(&_bf79);
           #pragma omp section
               path68(&_bf87);
           #pragma omp section
               path70(&_bf91);
           #pragma omp section
               path71(&_bf95);
           #pragma omp section
               path74(x, &_bf1, &_bf5);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path95(_bf0, _bf1, &_bf2, &_bf3);
           #pragma omp section
               path105(_bf55, w, &_bf57, &_bf58);
           #pragma omp section
               path106(_bf4, _bf5, &_bf6, &_bf7);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path1(_bf3, _bf7, &_bf10);
           #pragma omp section
               path69(_bf2, _bf6, &_bf9);
           #pragma omp section
               path110(_bf71, _bf57, &_bf73, &_bf74);
           #pragma omp section
               path297(_bf58, &_bf339);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path75(_bf10, &_bf103, &_bf109);
           #pragma omp section
               path80(_bf9, &_bf12, &_bf16);
           #pragma omp section
               path114(_bf87, _bf73, &_bf89, &_bf90);
           #pragma omp section
               path298(_bf339, &_bf340);
           #pragma omp section
               path314(_bf74, &_bf356);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path79(_bf112, _bf89, &_bf114, &_bf115);
           #pragma omp section
               path85(_bf11, _bf12, &_bf13, &_bf14);
           #pragma omp section
               path94(_bf15, _bf16, &_bf17, &_bf18);
           #pragma omp section
               path119(_bf103, &_bf8);
           #pragma omp section
               path131(_bf109, &_bf113);
           #pragma omp section
               path299(_bf340, &_bf341);
           #pragma omp section
               path315(_bf356, &_bf357);
           #pragma omp section
               path333(_bf90, &_bf375);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path41(_bf13, _bf17, &_bf20);
           #pragma omp section
               path42(_bf14, _bf18, &_bf21);
           #pragma omp section
               path118(_bf141, _bf114, &w, &_bf144);
           #pragma omp section
               path120(_bf8, &_bf19);
           #pragma omp section
               path132(_bf113, &_bf142);
           #pragma omp section
               path137(_bf115, &_bf167);
           #pragma omp section
               path300(_bf341, &_bf342);
           #pragma omp section
               path316(_bf357, &_bf358);
           #pragma omp section
               path334(_bf375, &_bf376);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path77(_bf21, &_bf106, &_bf116);
           #pragma omp section
               path96(_bf20, &_bf23, &_bf27);
           #pragma omp section
               path121(_bf19, &_bf30);
           #pragma omp section
               path133(_bf142, &_bf143);
           #pragma omp section
               path138(_bf167, &_bf168);
           #pragma omp section
               path233(_bf144, &_bf275);
           #pragma omp section
               path301(_bf342, &_bf343);
           #pragma omp section
               path317(_bf358, &_bf359);
           #pragma omp section
               path335(_bf376, &_bf377);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path97(_bf22, _bf23, &_bf24, &_bf25);
           #pragma omp section
               path98(_bf26, _bf27, &_bf28, &_bf29);
           #pragma omp section
               path122(_bf30, &_bf41);
           #pragma omp section
               path125(_bf106, &_bf67);
           #pragma omp section
               path134(_bf143, &_bf162);
           #pragma omp section
               path139(_bf168, &_bf169);
           #pragma omp section
               path147(_bf116, &_bf183);
           #pragma omp section
               path234(_bf275, &_bf276);
           #pragma omp section
               path302(_bf343, &_bf344);
           #pragma omp section
               path318(_bf359, &_bf360);
           #pragma omp section
               path336(_bf377, &_bf378);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path45(_bf24, _bf28, &_bf31);
           #pragma omp section
               path46(_bf25, _bf29, &_bf32);
           #pragma omp section
               path123(_bf41, &_bf52);
           #pragma omp section
               path126(_bf67, &_bf72);
           #pragma omp section
               path135(_bf162, &_bf163);
           #pragma omp section
               path140(_bf169, &_bf172);
           #pragma omp section
               path148(_bf183, &_bf184);
           #pragma omp section
               path235(_bf276, &_bf277);
           #pragma omp section
               path303(_bf344, &_bf345);
           #pragma omp section
               path319(_bf360, &_bf361);
           #pragma omp section
               path337(_bf378, &_bf379);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path76(_bf32, &_bf104, &_bf110);
           #pragma omp section
               path99(_bf31, &_bf34, &_bf38);
           #pragma omp section
               path124(_bf52, &_bf56);
           #pragma omp section
               path127(_bf72, &_bf83);
           #pragma omp section
               path136(_bf163, &_bf164);
           #pragma omp section
               path141(_bf172, &_bf173);
           #pragma omp section
               path149(_bf184, &_bf187);
           #pragma omp section
               path236(_bf277, &_bf278);
           #pragma omp section
               path304(_bf345, &_bf346);
           #pragma omp section
               path320(_bf361, &_bf362);
           #pragma omp section
               path338(_bf379, &_bf380);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path4(_bf56, _bf104, &_bf105);
           #pragma omp section
               path7(_bf164, _bf110, &_bf111);
           #pragma omp section
               path100(_bf33, _bf34, &_bf35, &_bf36);
           #pragma omp section
               path101(_bf37, _bf38, &_bf39, &_bf40);
           #pragma omp section
               path128(_bf83, &_bf88);
           #pragma omp section
               path142(_bf173, &_bf174);
           #pragma omp section
               path150(_bf187, &_bf188);
           #pragma omp section
               path237(_bf278, &_bf279);
           #pragma omp section
               path305(_bf346, &_bf347);
           #pragma omp section
               path321(_bf362, &_bf363);
           #pragma omp section
               path339(_bf380, &_bf381);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path50(_bf35, _bf39, &_bf42);
           #pragma omp section
               path51(_bf36, _bf40, &_bf43);
           #pragma omp section
               path81(_bf105, &_bf120, &_bf123);
           #pragma omp section
               path83(_bf111, &_bf126, &_bf129);
           #pragma omp section
               path129(_bf88, &_bf99);
           #pragma omp section
               path143(_bf174, &_bf177);
           #pragma omp section
               path151(_bf188, &_bf189);
           #pragma omp section
               path238(_bf279, &_bf280);
           #pragma omp section
               path306(_bf347, &_bf348);
           #pragma omp section
               path322(_bf363, &_bf364);
           #pragma omp section
               path340(_bf381, &_bf382);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path78(_bf43, &_bf107, &_bf117);
           #pragma omp section
               path102(_bf42, &_bf45, &_bf49);
           #pragma omp section
               path130(_bf99, &_bf100);
           #pragma omp section
               path144(_bf177, &_bf178);
           #pragma omp section
               path152(_bf189, &_bf192);
           #pragma omp section
               path153(_bf120, &_bf193);
           #pragma omp section
               path156(_bf123, &_bf198);
           #pragma omp section
               path175(_bf126, &_bf217);
           #pragma omp section
               path192(_bf129, &_bf234);
           #pragma omp section
               path239(_bf280, &_bf281);
           #pragma omp section
               path307(_bf348, &_bf349);
           #pragma omp section
               path323(_bf364, &_bf365);
           #pragma omp section
               path341(_bf382, &_bf383);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path5(_bf100, _bf107, &_bf108);
           #pragma omp section
               path9(_bf192, _bf117, &_bf118);
           #pragma omp section
               path103(_bf44, _bf45, &_bf46, &_bf47);
           #pragma omp section
               path104(_bf48, _bf49, &_bf50, &_bf51);
           #pragma omp section
               path145(_bf178, &_bf179);
           #pragma omp section
               path154(_bf193, &_bf194);
           #pragma omp section
               path157(_bf198, &_bf199);
           #pragma omp section
               path176(_bf217, &_bf218);
           #pragma omp section
               path193(_bf234, &_bf235);
           #pragma omp section
               path240(_bf281, &_bf282);
           #pragma omp section
               path308(_bf349, &_bf350);
           #pragma omp section
               path324(_bf365, &_bf366);
           #pragma omp section
               path342(_bf383, &_bf384);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path54(_bf46, _bf50, &_bf53);
           #pragma omp section
               path55(_bf47, _bf51, &_bf54);
           #pragma omp section
               path82(_bf108, &_bf121, &_bf124);
           #pragma omp section
               path146(_bf179, &_bf182);
           #pragma omp section
               path155(_bf194, &_bf197);
           #pragma omp section
               path158(_bf199, &_bf200);
           #pragma omp section
               path177(_bf218, &_bf219);
           #pragma omp section
               path194(_bf235, &_bf236);
           #pragma omp section
               path241(_bf282, &_bf283);
           #pragma omp section
               path309(_bf350, &_bf351);
           #pragma omp section
               path325(_bf366, &_bf367);
           #pragma omp section
               path343(_bf384, &_bf385);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path10(_bf182, _bf118, &_bf119);
           #pragma omp section
               path11(_bf197, _bf121, &_bf122);
           #pragma omp section
               path12(_bf200, _bf124, &_bf125);
           #pragma omp section
               path86(_bf54, &_bf132, &_bf138);
           #pragma omp section
               path107(_bf53, &_bf60, &_bf64);
           #pragma omp section
               path178(_bf219, &_bf220);
           #pragma omp section
               path195(_bf236, &_bf237);
           #pragma omp section
               path242(_bf283, &_bf284);
           #pragma omp section
               path310(_bf351, &_bf352);
           #pragma omp section
               path326(_bf367, &_bf368);
           #pragma omp section
               path344(_bf385, &_bf386);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path27(_bf161, y, _bf122, &_bf165);
           #pragma omp section
               path84(_bf119, &_bf127, &_bf130);
           #pragma omp section
               path108(_bf59, _bf60, &_bf61, &_bf62);
           #pragma omp section
               path109(_bf63, _bf64, &_bf65, &_bf66);
           #pragma omp section
               path159(_bf125, &_bf201);
           #pragma omp section
               path213(_bf132, &_bf255);
           #pragma omp section
               path226(_bf138, &_bf268);
           #pragma omp section
               path243(_bf284, &_bf285);
           #pragma omp section
               path311(_bf352, &_bf353);
           #pragma omp section
               path327(_bf368, &_bf369);
           #pragma omp section
               path345(_bf386, &_bf387);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path13(_bf220, _bf127, &_bf128);
           #pragma omp section
               path14(_bf237, _bf130, &_bf131);
           #pragma omp section
               path59(_bf61, _bf65, &_bf68);
           #pragma omp section
               path60(_bf62, _bf66, &_bf69);
           #pragma omp section
               path160(_bf201, &_bf202);
           #pragma omp section
               path214(_bf255, &_bf256);
           #pragma omp section
               path227(_bf268, &_bf269);
           #pragma omp section
               path244(_bf285, &_bf286);
           #pragma omp section
               path285(_bf165, &_bf327);
           #pragma omp section
               path312(_bf353, &_bf354);
           #pragma omp section
               path328(_bf369, &_bf370);
           #pragma omp section
               path346(_bf387, &_bf388);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path111(_bf68, &_bf76, &_bf80);
           #pragma omp section
               path161(_bf202, &_bf203);
           #pragma omp section
               path179(_bf128, &_bf221);
           #pragma omp section
               path196(_bf131, &_bf238);
           #pragma omp section
               path215(_bf256, &_bf257);
           #pragma omp section
               path228(_bf269, &_bf270);
           #pragma omp section
               path245(_bf286, &_bf287);
           #pragma omp section
               path286(_bf327, &_bf328);
           #pragma omp section
               path313(_bf354, &_bf355);
           #pragma omp section
               path329(_bf370, &_bf371);
           #pragma omp section
               path347(_bf388, &_bf389);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path61(_bf355, _bf69, &_bf70);
           #pragma omp section
               path112(_bf75, _bf76, &_bf77, &_bf78);
           #pragma omp section
               path113(_bf79, _bf80, &_bf81, &_bf82);
           #pragma omp section
               path162(_bf203, &_bf204);
           #pragma omp section
               path180(_bf221, &_bf222);
           #pragma omp section
               path197(_bf238, &_bf239);
           #pragma omp section
               path216(_bf257, &_bf258);
           #pragma omp section
               path229(_bf270, &_bf271);
           #pragma omp section
               path246(_bf287, &_bf288);
           #pragma omp section
               path287(_bf328, &_bf329);
           #pragma omp section
               path330(_bf371, &_bf372);
           #pragma omp section
               path348(_bf389, &_bf390);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path65(_bf77, _bf81, &_bf84);
           #pragma omp section
               path66(_bf78, _bf82, &_bf85);
           #pragma omp section
               path88(_bf70, &_bf135, &_bf145);
           #pragma omp section
               path163(_bf204, &_bf205);
           #pragma omp section
               path181(_bf222, &_bf223);
           #pragma omp section
               path198(_bf239, &_bf240);
           #pragma omp section
               path217(_bf258, &_bf259);
           #pragma omp section
               path230(_bf271, &_bf272);
           #pragma omp section
               path247(_bf288, &_bf289);
           #pragma omp section
               path288(_bf329, &_bf330);
           #pragma omp section
               path331(_bf372, &_bf373);
           #pragma omp section
               path349(_bf390, &_bf391);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path115(_bf84, &_bf92, &_bf96);
           #pragma omp section
               path164(_bf205, &_bf206);
           #pragma omp section
               path182(_bf223, &_bf224);
           #pragma omp section
               path199(_bf240, &_bf241);
           #pragma omp section
               path218(_bf259, &_bf260);
           #pragma omp section
               path220(_bf135, &_bf262);
           #pragma omp section
               path231(_bf272, &_bf273);
           #pragma omp section
               path248(_bf289, &_bf290);
           #pragma omp section
               path255(_bf145, &_bf297);
           #pragma omp section
               path289(_bf330, &_bf331);
           #pragma omp section
               path332(_bf373, &_bf374);
           #pragma omp section
               path350(_bf391, &_bf392);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path67(_bf374, _bf85, &_bf86);
           #pragma omp section
               path116(_bf91, _bf92, &_bf93, &_bf94);
           #pragma omp section
               path117(_bf95, _bf96, &_bf97, &_bf98);
           #pragma omp section
               path165(_bf206, &_bf207);
           #pragma omp section
               path183(_bf224, &_bf225);
           #pragma omp section
               path200(_bf241, &_bf242);
           #pragma omp section
               path219(_bf260, &_bf261);
           #pragma omp section
               path221(_bf262, &_bf263);
           #pragma omp section
               path232(_bf273, &_bf274);
           #pragma omp section
               path249(_bf290, &_bf291);
           #pragma omp section
               path256(_bf297, &_bf298);
           #pragma omp section
               path290(_bf331, &_bf332);
           #pragma omp section
               path351(_bf392, &_bf393);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path2(_bf94, _bf98, &_bf101);
           #pragma omp section
               path72(_bf93, _bf97, &x);
           #pragma omp section
               path87(_bf86, &_bf133, &_bf139);
           #pragma omp section
               path166(_bf207, &_bf208);
           #pragma omp section
               path184(_bf225, &_bf226);
           #pragma omp section
               path201(_bf242, &_bf243);
           #pragma omp section
               path222(_bf263, &_bf264);
           #pragma omp section
               path250(_bf291, &_bf292);
           #pragma omp section
               path257(_bf298, &_bf299);
           #pragma omp section
               path291(_bf332, &_bf333);
           #pragma omp section
               path352(_bf393, &_bf394);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path15(_bf261, _bf133, &_bf134);
           #pragma omp section
               path17(_bf274, _bf139, &_bf140);
           #pragma omp section
               path167(_bf208, &_bf209);
           #pragma omp section
               path185(_bf226, &_bf227);
           #pragma omp section
               path202(_bf243, &_bf244);
           #pragma omp section
               path223(_bf264, &_bf265);
           #pragma omp section
               path251(_bf292, &_bf293);
           #pragma omp section
               path258(_bf299, &_bf300);
           #pragma omp section
               path292(_bf333, &_bf334);
           #pragma omp section
               path353(_bf394, &_bf395);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path3(_bf395, _bf101, &_bf102);
           #pragma omp section
               path90(_bf134, &_bf149, &_bf152);
           #pragma omp section
               path92(_bf140, &_bf155, &_bf158);
           #pragma omp section
               path168(_bf209, &_bf210);
           #pragma omp section
               path186(_bf227, &_bf228);
           #pragma omp section
               path203(_bf244, &_bf245);
           #pragma omp section
               path224(_bf265, &_bf266);
           #pragma omp section
               path252(_bf293, &_bf294);
           #pragma omp section
               path259(_bf300, &_bf301);
           #pragma omp section
               path293(_bf334, &_bf335);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path89(_bf102, &_bf136, &_bf146);
           #pragma omp section
               path169(_bf210, &_bf211);
           #pragma omp section
               path187(_bf228, &_bf229);
           #pragma omp section
               path204(_bf245, &_bf246);
           #pragma omp section
               path225(_bf266, &_bf267);
           #pragma omp section
               path253(_bf294, &_bf295);
           #pragma omp section
               path260(_bf301, &_bf302);
           #pragma omp section
               path261(_bf149, &_bf303);
           #pragma omp section
               path264(_bf152, &_bf306);
           #pragma omp section
               path271(_bf155, &_bf313);
           #pragma omp section
               path276(_bf158, &_bf318);
           #pragma omp section
               path294(_bf335, &_bf336);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path16(_bf267, _bf136, &_bf137);
           #pragma omp section
               path19(_bf302, _bf146, &_bf147);
           #pragma omp section
               path170(_bf211, &_bf212);
           #pragma omp section
               path188(_bf229, &_bf230);
           #pragma omp section
               path205(_bf246, &_bf247);
           #pragma omp section
               path254(_bf295, &_bf296);
           #pragma omp section
               path262(_bf303, &_bf304);
           #pragma omp section
               path265(_bf306, &_bf307);
           #pragma omp section
               path272(_bf313, &_bf314);
           #pragma omp section
               path277(_bf318, &_bf319);
           #pragma omp section
               path295(_bf336, &_bf337);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path20(_bf296, _bf147, &_bf148);
           #pragma omp section
               path91(_bf137, &_bf150, &_bf153);
           #pragma omp section
               path171(_bf212, &_bf213);
           #pragma omp section
               path189(_bf230, &_bf231);
           #pragma omp section
               path206(_bf247, &_bf248);
           #pragma omp section
               path263(_bf304, &_bf305);
           #pragma omp section
               path266(_bf307, &_bf308);
           #pragma omp section
               path273(_bf314, &_bf315);
           #pragma omp section
               path278(_bf319, &_bf320);
           #pragma omp section
               path296(_bf337, &_bf338);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path22(_bf305, _bf150, &_bf151);
           #pragma omp section
               path23(_bf308, _bf153, &_bf154);
           #pragma omp section
               path93(_bf148, &_bf156, &_bf159);
           #pragma omp section
               path172(_bf213, &_bf214);
           #pragma omp section
               path190(_bf231, &_bf232);
           #pragma omp section
               path207(_bf248, &_bf249);
           #pragma omp section
               path274(_bf315, &_bf316);
           #pragma omp section
               path279(_bf320, &_bf321);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path24(_bf316, _bf156, &_bf157);
           #pragma omp section
               path25(_bf321, _bf159, &_bf160);
           #pragma omp section
               path29(_bf166, _bf338, _bf151, &_bf170);
           #pragma omp section
               path173(_bf214, &_bf215);
           #pragma omp section
               path191(_bf232, &_bf233);
           #pragma omp section
               path208(_bf249, &_bf250);
           #pragma omp section
               path267(_bf154, &_bf309);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path31(_bf171, _bf170, _bf233, &_bf175);
           #pragma omp section
               path174(_bf215, &_bf216);
           #pragma omp section
               path209(_bf250, &_bf251);
           #pragma omp section
               path268(_bf309, &_bf310);
           #pragma omp section
               path275(_bf157, &_bf317);
           #pragma omp section
               path280(_bf160, &_bf322);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path33(_bf176, _bf175, _bf317, &_bf180);
           #pragma omp section
               path210(_bf251, &_bf252);
           #pragma omp section
               path269(_bf310, &_bf311);
           #pragma omp section
               path281(_bf322, &_bf323);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path35(_bf181, _bf180, _bf216, &_bf185);
           #pragma omp section
               path211(_bf252, &_bf253);
           #pragma omp section
               path270(_bf311, &_bf312);
           #pragma omp section
               path282(_bf323, &_bf324);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path37(_bf186, _bf185, _bf312, &_bf190);
           #pragma omp section
               path212(_bf253, &_bf254);
           #pragma omp section
               path283(_bf324, &_bf325);
       }
       #pragma omp parallel sections
       {
           #pragma omp section
               path39(_bf191, _bf190, _bf254, &_bf195);
           #pragma omp section
               path284(_bf325, &_bf326);
       }
       path73(_bf196, _bf195, _bf326, &y);

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