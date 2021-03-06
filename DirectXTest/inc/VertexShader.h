#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 6.3.9600.16384
//
// Parameters:
//
//   float4x4 projectionMatrix;
//   float4x4 viewMatrix;
//   float4x4 worldMatrix;
//
//
// Registers:
//
//   Name             Reg   Size
//   ---------------- ----- ----
//   projectionMatrix c0       4
//   viewMatrix       c4       4
//   worldMatrix      c8       4
//

    vs_2_0
    def c12, 1, 0, 0, 0
    dcl_position v0  // IN<0,1,2>
    dcl_color v1  // IN<3,4,5>

#line 32 "E:\Work\gamedev\DirectX\DirectXTest\DirectXTest\Shaders\SimpleVertexShader.hlsl"
    mov r0, c4  // PerFrame::viewMatrix<0,4,8,12>
    mul r1, r0, c8.x
    mov r2, c5  // PerFrame::viewMatrix<1,5,9,13>
    mul r3, r2, c8.y
    add r1, r1, r3
    mov r3, c6  // PerFrame::viewMatrix<2,6,10,14>
    mul r4, r3, c8.z
    add r1, r1, r4
    mov r4, c7  // PerFrame::viewMatrix<3,7,11,15>
    mul r5, r4, c8.w
    add r1, r1, r5
    mul r5, r0, c9.x
    mul r6, r2, c9.y
    add r5, r5, r6
    mul r6, r3, c9.z
    add r5, r5, r6
    mul r6, r4, c9.w
    add r5, r5, r6
    mul r6, r0, c10.x
    mul r7, r2, c10.y
    add r6, r6, r7
    mul r7, r3, c10.z
    add r6, r6, r7
    mul r7, r4, c10.w
    add r6, r6, r7
    mul r0, r0, c11.x
    mul r2, r2, c11.y
    add r0, r0, r2
    mul r2, r3, c11.z
    add r0, r0, r2
    mul r2, r4, c11.w
    add r0, r0, r2
    mul r2, r1.x, c0
    mul r3, r1.y, c1
    add r2, r2, r3
    mul r3, r1.z, c2
    add r2, r2, r3
    mul r1, r1.w, c3
    add r1, r1, r2
    mul r2, r5.x, c0
    mul r3, r5.y, c1
    add r2, r2, r3
    mul r3, r5.z, c2
    add r2, r2, r3
    mul r3, r5.w, c3
    add r2, r2, r3
    mul r3, r6.x, c0
    mul r4, r6.y, c1
    add r3, r3, r4
    mul r4, r6.z, c2
    add r3, r3, r4
    mul r4, r6.w, c3
    add r3, r3, r4
    mul r4, r0.x, c0
    mul r5, r0.y, c1
    add r4, r4, r5
    mul r5, r0.z, c2
    add r4, r4, r5
    mul r0, r0.w, c3
    add r0, r0, r4
    mov r4.x, r1.x  // ::mvp<0>
    mov r4.y, r2.x  // ::mvp<1>
    mov r4.z, r3.x  // ::mvp<2>
    mov r4.w, r0.x  // ::mvp<3>
    mov r5.x, r1.y  // ::mvp<4>
    mov r5.y, r2.y  // ::mvp<5>
    mov r5.z, r3.y  // ::mvp<6>
    mov r5.w, r0.y  // ::mvp<7>
    mov r6.x, r1.z  // ::mvp<8>
    mov r6.y, r2.z  // ::mvp<9>
    mov r6.z, r3.z  // ::mvp<10>
    mov r6.w, r0.z  // ::mvp<11>
    mov r0.x, r1.w  // ::mvp<12>
    mov r0.y, r2.w  // ::mvp<13>
    mov r0.z, r3.w  // ::mvp<14>
    mov r0.w, r0.w  // ::mvp<15>
    mul r1, v0.xyzx, c12.xxxy
    add r1, r1, c12.yyyx
    dp4 r1.x, r4, r1  // ::OUT<4>
    mul r2, v0.xyzx, c12.xxxy
    add r2, r2, c12.yyyx
    dp4 r1.y, r5, r2  // ::OUT<5>
    mul r2, v0.xyzx, c12.xxxy
    add r2, r2, c12.yyyx
    dp4 r1.z, r6, r2  // ::OUT<6>
    mul r2, v0.xyzx, c12.xxxy
    add r2, r2, c12.yyyx
    dp4 r1.w, r0, r2  // ::OUT<7>
    mul r0, v1.xyzx, c12.xxxy
    add r0, r0, c12.yyyx  // ::OUT<0,1,2,3>
    mov oD0, r0  // ::SimpleVertexShader<0,1,2,3>
    mov oPos, r1  // ::SimpleVertexShader<4,5,6,7>

// approximately 92 instruction slots used
#endif

const BYTE g_vs[] =
{
      0,   2, 254, 255, 254, 255, 
    144,   1,  68,  66,  85,  71, 
     40,   0,   0,   0,   8,   6, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0, 120,   0, 
      0,   0,  95,   0,   0,   0, 
    124,   0,   0,   0,   5,   0, 
      0,   0, 164,   5,   0,   0, 
    116,   3,   0,   0,  69,  58, 
     92,  87, 111, 114, 107,  92, 
    103,  97, 109, 101, 100, 101, 
    118,  92,  68, 105, 114, 101, 
     99, 116,  88,  92,  68, 105, 
    114, 101,  99, 116,  88,  84, 
    101, 115, 116,  92,  68, 105, 
    114, 101,  99, 116,  88,  84, 
    101, 115, 116,  92,  83, 104, 
     97, 100, 101, 114, 115,  92, 
     83, 105, 109, 112, 108, 101, 
     86, 101, 114, 116, 101, 120, 
     83, 104,  97, 100, 101, 114, 
     46, 104, 108, 115, 108,   0, 
     40,   0,   0,   0,   0,   0, 
    255, 255,  28,   7,   0,   0, 
      0,   0, 255, 255,  52,   7, 
      0,   0,   0,   0, 255, 255, 
     64,   7,   0,   0,  32,   0, 
      0,   0,  76,   7,   0,   0, 
     32,   0,   0,   0,  88,   7, 
      0,   0,  32,   0,   0,   0, 
    104,   7,   0,   0,  32,   0, 
      0,   0, 116,   7,   0,   0, 
     32,   0,   0,   0, 132,   7, 
      0,   0,  32,   0,   0,   0, 
    148,   7,   0,   0,  32,   0, 
      0,   0, 160,   7,   0,   0, 
     32,   0,   0,   0, 176,   7, 
      0,   0,  32,   0,   0,   0, 
    192,   7,   0,   0,  32,   0, 
      0,   0, 204,   7,   0,   0, 
     32,   0,   0,   0, 220,   7, 
      0,   0,  32,   0,   0,   0, 
    236,   7,   0,   0,  32,   0, 
      0,   0, 252,   7,   0,   0, 
     32,   0,   0,   0,  12,   8, 
      0,   0,  32,   0,   0,   0, 
     28,   8,   0,   0,  32,   0, 
      0,   0,  44,   8,   0,   0, 
     32,   0,   0,   0,  60,   8, 
      0,   0,  32,   0,   0,   0, 
     76,   8,   0,   0,  32,   0, 
      0,   0,  92,   8,   0,   0, 
     32,   0,   0,   0, 108,   8, 
      0,   0,  32,   0,   0,   0, 
    124,   8,   0,   0,  32,   0, 
      0,   0, 140,   8,   0,   0, 
     32,   0,   0,   0, 156,   8, 
      0,   0,  32,   0,   0,   0, 
    172,   8,   0,   0,  32,   0, 
      0,   0, 188,   8,   0,   0, 
     32,   0,   0,   0, 204,   8, 
      0,   0,  32,   0,   0,   0, 
    220,   8,   0,   0,  32,   0, 
      0,   0, 236,   8,   0,   0, 
     32,   0,   0,   0, 252,   8, 
      0,   0,  32,   0,   0,   0, 
     12,   9,   0,   0,  32,   0, 
      0,   0,  28,   9,   0,   0, 
     32,   0,   0,   0,  44,   9, 
      0,   0,  32,   0,   0,   0, 
     60,   9,   0,   0,  32,   0, 
      0,   0,  76,   9,   0,   0, 
     32,   0,   0,   0,  92,   9, 
      0,   0,  32,   0,   0,   0, 
    108,   9,   0,   0,  32,   0, 
      0,   0, 124,   9,   0,   0, 
     32,   0,   0,   0, 140,   9, 
      0,   0,  32,   0,   0,   0, 
    156,   9,   0,   0,  32,   0, 
      0,   0, 172,   9,   0,   0, 
     32,   0,   0,   0, 188,   9, 
      0,   0,  32,   0,   0,   0, 
    204,   9,   0,   0,  32,   0, 
      0,   0, 220,   9,   0,   0, 
     32,   0,   0,   0, 236,   9, 
      0,   0,  32,   0,   0,   0, 
    252,   9,   0,   0,  32,   0, 
      0,   0,  12,  10,   0,   0, 
     32,   0,   0,   0,  28,  10, 
      0,   0,  32,   0,   0,   0, 
     44,  10,   0,   0,  32,   0, 
      0,   0,  60,  10,   0,   0, 
     32,   0,   0,   0,  76,  10, 
      0,   0,  32,   0,   0,   0, 
     92,  10,   0,   0,  32,   0, 
      0,   0, 108,  10,   0,   0, 
     32,   0,   0,   0, 124,  10, 
      0,   0,  32,   0,   0,   0, 
    140,  10,   0,   0,  32,   0, 
      0,   0, 156,  10,   0,   0, 
     32,   0,   0,   0, 172,  10, 
      0,   0,  32,   0,   0,   0, 
    188,  10,   0,   0,  32,   0, 
      0,   0, 204,  10,   0,   0, 
     32,   0,   0,   0, 220,  10, 
      0,   0,  32,   0,   0,   0, 
    236,  10,   0,   0,  32,   0, 
      0,   0, 252,  10,   0,   0, 
     32,   0,   0,   0,   8,  11, 
      0,   0,  32,   0,   0,   0, 
     20,  11,   0,   0,  32,   0, 
      0,   0,  32,  11,   0,   0, 
     32,   0,   0,   0,  44,  11, 
      0,   0,  32,   0,   0,   0, 
     56,  11,   0,   0,  32,   0, 
      0,   0,  68,  11,   0,   0, 
     32,   0,   0,   0,  80,  11, 
      0,   0,  32,   0,   0,   0, 
     92,  11,   0,   0,  32,   0, 
      0,   0, 104,  11,   0,   0, 
     32,   0,   0,   0, 116,  11, 
      0,   0,  32,   0,   0,   0, 
    128,  11,   0,   0,  32,   0, 
      0,   0, 140,  11,   0,   0, 
     32,   0,   0,   0, 152,  11, 
      0,   0,  32,   0,   0,   0, 
    164,  11,   0,   0,  32,   0, 
      0,   0, 176,  11,   0,   0, 
     33,   0,   0,   0, 188,  11, 
      0,   0,  33,   0,   0,   0, 
    204,  11,   0,   0,  33,   0, 
      0,   0, 220,  11,   0,   0, 
     33,   0,   0,   0, 236,  11, 
      0,   0,  33,   0,   0,   0, 
    252,  11,   0,   0,  33,   0, 
      0,   0,  12,  12,   0,   0, 
     33,   0,   0,   0,  28,  12, 
      0,   0,  33,   0,   0,   0, 
     44,  12,   0,   0,  33,   0, 
      0,   0,  60,  12,   0,   0, 
     33,   0,   0,   0,  76,  12, 
      0,   0,  33,   0,   0,   0, 
     92,  12,   0,   0,  33,   0, 
      0,   0, 108,  12,   0,   0, 
     34,   0,   0,   0, 124,  12, 
      0,   0,  34,   0,   0,   0, 
    140,  12,   0,   0,  36,   0, 
      0,   0, 156,  12,   0,   0, 
     36,   0,   0,   0, 168,  12, 
      0,   0,  83, 105, 109, 112, 
    108, 101,  86, 101, 114, 116, 
    101, 120,  83, 104,  97, 100, 
    101, 114,   0,  73,  78,   0, 
    112, 111, 115, 105, 116, 105, 
    111, 110,   0, 171,   1,   0, 
      3,   0,   1,   0,   3,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  99, 111, 108, 111, 
    114,   0, 171, 171, 138,   3, 
      0,   0, 148,   3,   0,   0, 
    164,   3,   0,   0, 148,   3, 
      0,   0,   5,   0,   0,   0, 
      1,   0,   6,   0,   1,   0, 
      2,   0, 172,   3,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
      2,   0,   0,   0,   3,   0, 
      4,   0,   5,   0, 255, 255, 
     79,  85,  84,   0,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 164,   3,   0,   0, 
    232,   3,   0,   0, 138,   3, 
      0,   0, 232,   3,   0,   0, 
      5,   0,   0,   0,   1,   0, 
      8,   0,   1,   0,   2,   0, 
    248,   3,   0,   0,  81,   0, 
      0,   0,   4,   0, 255, 255, 
    255, 255, 255, 255,  84,   0, 
      0,   0, 255, 255,   5,   0, 
    255, 255, 255, 255,  87,   0, 
      0,   0, 255, 255, 255, 255, 
      6,   0, 255, 255,  90,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,   7,   0,  92,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0,   3,   0,   5,   0, 
      0,   0,   1,   0,   8,   0, 
      1,   0,   2,   0, 248,   3, 
      0,   0,  93,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
      3,   0,  94,   0,   0,   0, 
      4,   0,   5,   0,   6,   0, 
      7,   0, 109, 118, 112,   0, 
      3,   0,   3,   0,   4,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  63,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255, 255, 255,  64,   0, 
      0,   0, 255, 255,   1,   0, 
    255, 255, 255, 255,  65,   0, 
      0,   0, 255, 255, 255, 255, 
      2,   0, 255, 255,  66,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,   3,   0,  67,   0, 
      0,   0,   4,   0, 255, 255, 
    255, 255, 255, 255,  68,   0, 
      0,   0, 255, 255,   5,   0, 
    255, 255, 255, 255,  69,   0, 
      0,   0, 255, 255, 255, 255, 
      6,   0, 255, 255,  70,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,   7,   0,  71,   0, 
      0,   0,   8,   0, 255, 255, 
    255, 255, 255, 255,  72,   0, 
      0,   0, 255, 255,   9,   0, 
    255, 255, 255, 255,  73,   0, 
      0,   0, 255, 255, 255, 255, 
     10,   0, 255, 255,  74,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,  11,   0,  75,   0, 
      0,   0,  12,   0, 255, 255, 
    255, 255, 255, 255,  76,   0, 
      0,   0, 255, 255,  13,   0, 
    255, 255, 255, 255,  77,   0, 
      0,   0, 255, 255, 255, 255, 
     14,   0, 255, 255,  78,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,  15,   0,  80, 101, 
    114,  70, 114,  97, 109, 101, 
      0, 118, 105, 101, 119,  77, 
     97, 116, 114, 105, 120,   0, 
      3,   0,   3,   0,   4,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   4,   0, 
      8,   0,  12,   0,   5,   0, 
      0,   0,   1,   0,   5,   0, 
      9,   0,  13,   0,   8,   0, 
      0,   0,   2,   0,   6,   0, 
     10,   0,  14,   0,  11,   0, 
      0,   0,   3,   0,   7,   0, 
     11,   0,  15,   0, 116,   3, 
      0,   0, 135,   3,   0,   0, 
    188,   3,   0,   0,   2,   0, 
      0,   0, 204,   3,   0,   0, 
      0,   0,   0,   0, 228,   3, 
      0,   0,   8,   4,   0,   0, 
      5,   0,   0,   0,  24,   4, 
      0,   0,   0,   0,   0,   0, 
    116,   3,   0,   0,  84,   4, 
      0,   0,   2,   0,   0,   0, 
    100,   4,   0,   0,   0,   0, 
      0,   0, 124,   4,   0,   0, 
    128,   4,   0,   0,  16,   0, 
      0,   0, 144,   4,   0,   0, 
     80,   5,   0,   0,  89,   5, 
      0,   0, 100,   5,   0,   0, 
      4,   0,   0,   0, 116,   5, 
      0,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  54,  46,  51,  46,  57, 
     54,  48,  48,  46,  49,  54, 
     51,  56,  52,   0, 171, 171, 
    254, 255,  52,   0,  67,  84, 
     65,  66,  28,   0,   0,   0, 
    154,   0,   0,   0,   0,   2, 
    254, 255,   3,   0,   0,   0, 
     28,   0,   0,   0,   5,   1, 
      0,   0, 147,   0,   0,   0, 
     88,   0,   0,   0,   2,   0, 
      0,   0,   4,   0,   0,   0, 
    108,   0,   0,   0,   0,   0, 
      0,   0, 124,   0,   0,   0, 
      2,   0,   4,   0,   4,   0, 
      0,   0, 108,   0,   0,   0, 
      0,   0,   0,   0, 135,   0, 
      0,   0,   2,   0,   8,   0, 
      4,   0,   0,   0, 108,   0, 
      0,   0,   0,   0,   0,   0, 
    112, 114, 111, 106, 101,  99, 
    116, 105, 111, 110,  77,  97, 
    116, 114, 105, 120,   0, 171, 
    171, 171,   3,   0,   3,   0, 
      4,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
    118, 105, 101, 119,  77,  97, 
    116, 114, 105, 120,   0, 119, 
    111, 114, 108, 100,  77,  97, 
    116, 114, 105, 120,   0, 118, 
    115,  95,  50,  95,  48,   0, 
     77, 105,  99, 114, 111, 115, 
    111, 102, 116,  32,  40,  82, 
     41,  32,  72,  76,  83,  76, 
     32,  83, 104,  97, 100, 101, 
    114,  32,  67, 111, 109, 112, 
    105, 108, 101, 114,  32,  54, 
     46,  51,  46,  57,  54,  48, 
     48,  46,  49,  54,  51,  56, 
     52,   0,  81,   0,   0,   5, 
     12,   0,  15, 160,   0,   0, 
    128,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  31,   0,   0,   2, 
      0,   0,   0, 128,   0,   0, 
     15, 144,  31,   0,   0,   2, 
     10,   0,   0, 128,   1,   0, 
     15, 144,   1,   0,   0,   2, 
      0,   0,  15, 128,   4,   0, 
    228, 160,   5,   0,   0,   3, 
      1,   0,  15, 128,   0,   0, 
    228, 128,   8,   0,   0, 160, 
      1,   0,   0,   2,   2,   0, 
     15, 128,   5,   0, 228, 160, 
      5,   0,   0,   3,   3,   0, 
     15, 128,   2,   0, 228, 128, 
      8,   0,  85, 160,   2,   0, 
      0,   3,   1,   0,  15, 128, 
      1,   0, 228, 128,   3,   0, 
    228, 128,   1,   0,   0,   2, 
      3,   0,  15, 128,   6,   0, 
    228, 160,   5,   0,   0,   3, 
      4,   0,  15, 128,   3,   0, 
    228, 128,   8,   0, 170, 160, 
      2,   0,   0,   3,   1,   0, 
     15, 128,   1,   0, 228, 128, 
      4,   0, 228, 128,   1,   0, 
      0,   2,   4,   0,  15, 128, 
      7,   0, 228, 160,   5,   0, 
      0,   3,   5,   0,  15, 128, 
      4,   0, 228, 128,   8,   0, 
    255, 160,   2,   0,   0,   3, 
      1,   0,  15, 128,   1,   0, 
    228, 128,   5,   0, 228, 128, 
      5,   0,   0,   3,   5,   0, 
     15, 128,   0,   0, 228, 128, 
      9,   0,   0, 160,   5,   0, 
      0,   3,   6,   0,  15, 128, 
      2,   0, 228, 128,   9,   0, 
     85, 160,   2,   0,   0,   3, 
      5,   0,  15, 128,   5,   0, 
    228, 128,   6,   0, 228, 128, 
      5,   0,   0,   3,   6,   0, 
     15, 128,   3,   0, 228, 128, 
      9,   0, 170, 160,   2,   0, 
      0,   3,   5,   0,  15, 128, 
      5,   0, 228, 128,   6,   0, 
    228, 128,   5,   0,   0,   3, 
      6,   0,  15, 128,   4,   0, 
    228, 128,   9,   0, 255, 160, 
      2,   0,   0,   3,   5,   0, 
     15, 128,   5,   0, 228, 128, 
      6,   0, 228, 128,   5,   0, 
      0,   3,   6,   0,  15, 128, 
      0,   0, 228, 128,  10,   0, 
      0, 160,   5,   0,   0,   3, 
      7,   0,  15, 128,   2,   0, 
    228, 128,  10,   0,  85, 160, 
      2,   0,   0,   3,   6,   0, 
     15, 128,   6,   0, 228, 128, 
      7,   0, 228, 128,   5,   0, 
      0,   3,   7,   0,  15, 128, 
      3,   0, 228, 128,  10,   0, 
    170, 160,   2,   0,   0,   3, 
      6,   0,  15, 128,   6,   0, 
    228, 128,   7,   0, 228, 128, 
      5,   0,   0,   3,   7,   0, 
     15, 128,   4,   0, 228, 128, 
     10,   0, 255, 160,   2,   0, 
      0,   3,   6,   0,  15, 128, 
      6,   0, 228, 128,   7,   0, 
    228, 128,   5,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    228, 128,  11,   0,   0, 160, 
      5,   0,   0,   3,   2,   0, 
     15, 128,   2,   0, 228, 128, 
     11,   0,  85, 160,   2,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   2,   0, 
    228, 128,   5,   0,   0,   3, 
      2,   0,  15, 128,   3,   0, 
    228, 128,  11,   0, 170, 160, 
      2,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 128, 
      2,   0, 228, 128,   5,   0, 
      0,   3,   2,   0,  15, 128, 
      4,   0, 228, 128,  11,   0, 
    255, 160,   2,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    228, 128,   2,   0, 228, 128, 
      5,   0,   0,   3,   2,   0, 
     15, 128,   1,   0,   0, 128, 
      0,   0, 228, 160,   5,   0, 
      0,   3,   3,   0,  15, 128, 
      1,   0,  85, 128,   1,   0, 
    228, 160,   2,   0,   0,   3, 
      2,   0,  15, 128,   2,   0, 
    228, 128,   3,   0, 228, 128, 
      5,   0,   0,   3,   3,   0, 
     15, 128,   1,   0, 170, 128, 
      2,   0, 228, 160,   2,   0, 
      0,   3,   2,   0,  15, 128, 
      2,   0, 228, 128,   3,   0, 
    228, 128,   5,   0,   0,   3, 
      1,   0,  15, 128,   1,   0, 
    255, 128,   3,   0, 228, 160, 
      2,   0,   0,   3,   1,   0, 
     15, 128,   1,   0, 228, 128, 
      2,   0, 228, 128,   5,   0, 
      0,   3,   2,   0,  15, 128, 
      5,   0,   0, 128,   0,   0, 
    228, 160,   5,   0,   0,   3, 
      3,   0,  15, 128,   5,   0, 
     85, 128,   1,   0, 228, 160, 
      2,   0,   0,   3,   2,   0, 
     15, 128,   2,   0, 228, 128, 
      3,   0, 228, 128,   5,   0, 
      0,   3,   3,   0,  15, 128, 
      5,   0, 170, 128,   2,   0, 
    228, 160,   2,   0,   0,   3, 
      2,   0,  15, 128,   2,   0, 
    228, 128,   3,   0, 228, 128, 
      5,   0,   0,   3,   3,   0, 
     15, 128,   5,   0, 255, 128, 
      3,   0, 228, 160,   2,   0, 
      0,   3,   2,   0,  15, 128, 
      2,   0, 228, 128,   3,   0, 
    228, 128,   5,   0,   0,   3, 
      3,   0,  15, 128,   6,   0, 
      0, 128,   0,   0, 228, 160, 
      5,   0,   0,   3,   4,   0, 
     15, 128,   6,   0,  85, 128, 
      1,   0, 228, 160,   2,   0, 
      0,   3,   3,   0,  15, 128, 
      3,   0, 228, 128,   4,   0, 
    228, 128,   5,   0,   0,   3, 
      4,   0,  15, 128,   6,   0, 
    170, 128,   2,   0, 228, 160, 
      2,   0,   0,   3,   3,   0, 
     15, 128,   3,   0, 228, 128, 
      4,   0, 228, 128,   5,   0, 
      0,   3,   4,   0,  15, 128, 
      6,   0, 255, 128,   3,   0, 
    228, 160,   2,   0,   0,   3, 
      3,   0,  15, 128,   3,   0, 
    228, 128,   4,   0, 228, 128, 
      5,   0,   0,   3,   4,   0, 
     15, 128,   0,   0,   0, 128, 
      0,   0, 228, 160,   5,   0, 
      0,   3,   5,   0,  15, 128, 
      0,   0,  85, 128,   1,   0, 
    228, 160,   2,   0,   0,   3, 
      4,   0,  15, 128,   4,   0, 
    228, 128,   5,   0, 228, 128, 
      5,   0,   0,   3,   5,   0, 
     15, 128,   0,   0, 170, 128, 
      2,   0, 228, 160,   2,   0, 
      0,   3,   4,   0,  15, 128, 
      4,   0, 228, 128,   5,   0, 
    228, 128,   5,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    255, 128,   3,   0, 228, 160, 
      2,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 128, 
      4,   0, 228, 128,   1,   0, 
      0,   2,   4,   0,   1, 128, 
      1,   0,   0, 128,   1,   0, 
      0,   2,   4,   0,   2, 128, 
      2,   0,   0, 128,   1,   0, 
      0,   2,   4,   0,   4, 128, 
      3,   0,   0, 128,   1,   0, 
      0,   2,   4,   0,   8, 128, 
      0,   0,   0, 128,   1,   0, 
      0,   2,   5,   0,   1, 128, 
      1,   0,  85, 128,   1,   0, 
      0,   2,   5,   0,   2, 128, 
      2,   0,  85, 128,   1,   0, 
      0,   2,   5,   0,   4, 128, 
      3,   0,  85, 128,   1,   0, 
      0,   2,   5,   0,   8, 128, 
      0,   0,  85, 128,   1,   0, 
      0,   2,   6,   0,   1, 128, 
      1,   0, 170, 128,   1,   0, 
      0,   2,   6,   0,   2, 128, 
      2,   0, 170, 128,   1,   0, 
      0,   2,   6,   0,   4, 128, 
      3,   0, 170, 128,   1,   0, 
      0,   2,   6,   0,   8, 128, 
      0,   0, 170, 128,   1,   0, 
      0,   2,   0,   0,   1, 128, 
      1,   0, 255, 128,   1,   0, 
      0,   2,   0,   0,   2, 128, 
      2,   0, 255, 128,   1,   0, 
      0,   2,   0,   0,   4, 128, 
      3,   0, 255, 128,   1,   0, 
      0,   2,   0,   0,   8, 128, 
      0,   0, 255, 128,   5,   0, 
      0,   3,   1,   0,  15, 128, 
      0,   0,  36, 144,  12,   0, 
     64, 160,   2,   0,   0,   3, 
      1,   0,  15, 128,   1,   0, 
    228, 128,  12,   0,  21, 160, 
      9,   0,   0,   3,   1,   0, 
      1, 128,   4,   0, 228, 128, 
      1,   0, 228, 128,   5,   0, 
      0,   3,   2,   0,  15, 128, 
      0,   0,  36, 144,  12,   0, 
     64, 160,   2,   0,   0,   3, 
      2,   0,  15, 128,   2,   0, 
    228, 128,  12,   0,  21, 160, 
      9,   0,   0,   3,   1,   0, 
      2, 128,   5,   0, 228, 128, 
      2,   0, 228, 128,   5,   0, 
      0,   3,   2,   0,  15, 128, 
      0,   0,  36, 144,  12,   0, 
     64, 160,   2,   0,   0,   3, 
      2,   0,  15, 128,   2,   0, 
    228, 128,  12,   0,  21, 160, 
      9,   0,   0,   3,   1,   0, 
      4, 128,   6,   0, 228, 128, 
      2,   0, 228, 128,   5,   0, 
      0,   3,   2,   0,  15, 128, 
      0,   0,  36, 144,  12,   0, 
     64, 160,   2,   0,   0,   3, 
      2,   0,  15, 128,   2,   0, 
    228, 128,  12,   0,  21, 160, 
      9,   0,   0,   3,   1,   0, 
      8, 128,   0,   0, 228, 128, 
      2,   0, 228, 128,   5,   0, 
      0,   3,   0,   0,  15, 128, 
      1,   0,  36, 144,  12,   0, 
     64, 160,   2,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    228, 128,  12,   0,  21, 160, 
      1,   0,   0,   2,   0,   0, 
     15, 208,   0,   0, 228, 128, 
      1,   0,   0,   2,   0,   0, 
     15, 192,   1,   0, 228, 128, 
    255, 255,   0,   0
};
