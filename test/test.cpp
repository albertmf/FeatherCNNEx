//Tencent is pleased to support the open source community by making FeatherCNN available.

//Copyright (C) 2018 THL A29 Limited, a Tencent company. All rights reserved.

//Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
//in compliance with the License. You may obtain a copy of the License at
//
//https://opensource.org/licenses/BSD-3-Clause
//
//Unless required by applicable law or agreed to in writing, software distributed
//under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
//CONDITIONS OF ANY KIND, either express or implied. See the License for the
//specific language governing permissions and limitations under the License.

#include <net.h>

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
using namespace feather;
static float C_REF[] =
#if 1
{
 1.005971, -0.595743,  0.302105, -0.370733, -0.597922,  0.360712, -1.480518, -0.535345,  0.542724,  1.290418,  0.549887,  0.644056,  0.154240, -0.349757,  1.595634,  0.524116, 
 0.056623,  0.620412,  0.618478, -0.904609,  0.855202, -0.460138,  0.407092, -0.061750, -0.910297, -0.149187, -1.691114, -0.682861,  1.894711, -0.393226, -0.565687, -2.048255, 
 0.627665, -0.565263,  0.479426, -0.750694, -1.142104, -0.241054,  0.381099, -0.347407,  0.888900,  0.156892, -0.820600,  0.334099, -0.117418, -0.698058, -1.471673, -0.396284, 
 0.570897,  1.694422,  1.218388, -0.625310, -0.454197,  0.632367, -0.669655, -0.082872,  0.733574,  0.947634, -0.191259,  0.159390,  0.042428,  0.397186, -0.220862, -0.394888, 
 0.802191,  1.289754,  0.652644,  0.755423, -0.627655,  0.995957,  0.493603, -0.157553, -0.936564,  0.410491,  1.787145, -1.034663,  0.312727,  1.030059,  0.736975, -1.687477, 
 1.268919, -1.349502,  0.523571, -0.137256,  0.832907, -0.727018, -0.370737, -1.068834, -0.277396, -1.377576,  0.668522,  1.310559, -0.538872, -0.632705, -0.266212, -0.990704, 
-1.818728, -0.270002,  1.226003, -0.506690, -0.508972, -0.189839, -0.983820, -0.479934, -0.814068, -1.007039, -1.071146, -0.283661, -0.551502,  0.525702,  2.248174, -0.174415, 
-1.774617, -0.196685,  0.441728, -1.332354,  0.564568, -1.304306,  0.866906, -1.398330, -1.688912, -0.599101,  1.223500,  0.038054,  1.729880,  0.913836, -1.162626,  0.039797, 
-0.306184, -0.525713, -0.472914,  0.569643, -1.162176, -0.331602, -0.170370,  0.162857,  0.292748,  0.428439,  0.377915, -0.788466, -0.306702,  0.586210,  1.098490, -0.371701, 
-0.010856,  1.543780,  0.137554, -1.265617,  0.026361, -0.462345,  0.108424,  0.041233, -1.518765, -0.192127,  0.428880,  0.656731,  0.986181,  1.103883,  0.246397,  0.350707, 
 0.750538,  0.588480, -1.120485, -0.835524, -0.591113,  0.989002,  1.225141, -0.171089, -0.076561,  1.038375, -0.432824, -0.521088,  1.271390,  0.284414,  0.581474,  0.126895, 
 0.841048,  1.146251,  0.680368, -0.062601,  0.994587,  1.184818,  0.381446, -0.229204,  0.541183, -0.250623, -1.292526,  0.082308,  1.714628,  0.957243, -0.928909,  0.101337, 
-1.318428, -0.056514, -0.017178,  0.641731,  0.724535,  0.648302, -1.087357, -0.894499,  0.802007, -0.004586, -1.375750, -0.931633,  0.371056, -0.151872, -1.253936, -0.968621, 
-0.093065,  1.357372,  0.947172,  0.139816,  0.635034,  0.430815, -0.652914,  0.689954, -0.821156, -0.833333, -0.308966,  0.664077, -0.513105,  0.495344,  1.592538,  0.013050, 
 0.758458,  0.889802,  1.593955,  0.270599, -0.004213,  0.977607, -0.879096, -0.983726,  0.052218, -0.887871, -1.075130, -0.215604,  0.201163,  1.054724, -0.214726,  0.752748, 
 0.966025, -0.921286, -0.205700, -0.472007, -0.537350,  0.854338,  1.151059, -0.674309,  0.128869, -0.162207, -0.305204, -0.075384, -1.642334,  0.771620,  0.289428, -1.459790 
};
#else
{
    0.933749,1.221805,0.942836,2.124435,0.118743,2.065125,0.153669,0.245184,0.024626,0.609957,0.174229,0.199315,0.100794,0.800480,0.000000,0.907268,
    0.053578,0.192186,0.353104,1.124146,3.151727,0.198787,0.245606,0.344097,0.000000,1.002228,0.000000,0.003053,0.388980,0.005686,0.089490,0.779931,
    0.235635,2.439793,0.018313,0.087937,0.974636,2.655642,0.239401,0.251922,0.296813,0.140838,0.512339,0.333062,0.693797,2.921950,0.133481,4.653688,
    0.000000,0.324613,0.098730,0.055202,0.139898,0.052006,0.000000,2.980098,0.000000,0.878949,0.071027,0.144047,2.408242,0.078959,1.027251,2.594565,
    0.000000,0.083480,1.919285,0.936636,0.467862,0.101560,1.675370,0.575522,0.293421,0.000000,0.918900,0.021969,0.363817,0.000000,0.783534,0.028025,
    0.023248,0.875875,0.259790,0.006164,0.384809,0.000000,0.805675,0.000000,0.747398,0.047613,0.859484,0.160446,1.175554,3.521654,0.182936,0.318085,
    0.252131,0.857794,0.144891,0.270708,0.140377,1.974211,1.556120,0.604902,0.316916,3.463933,0.024745,0.144742,0.050238,0.107112,0.117158,1.508855,
    0.265683,2.821200,0.729436,0.359863,0.000000,0.077613,0.236981,0.000067,2.951179,0.764845,1.142701,0.883148,0.032713,0.369207,0.060790,0.717021,
    0.005024,0.009245,0.098420,0.558032,1.519055,0.000000,1.550093,2.587355,0.151327,0.131581,0.805024,0.109998,0.489689,0.269794,0.014104,1.268039,
    0.257407,0.391928,1.388946,0.017771,0.207151,0.028289,0.287073,0.043769,2.109576,1.220630,0.674653,0.659865,0.452613,0.145623,0.007053,0.213908,
    0.000000,0.000000,1.302742,0.102333,0.618102,1.001975,2.542703,0.472270,0.189629,1.050102,0.875248,0.622512,0.542078,0.691874,0.217648,1.494125,
    0.214114,0.179772,0.000000,0.007845,0.148768,0.014195,0.310950,1.328574,0.000000,0.225374,0.188481,1.267861,0.000444,0.011105,0.005157,0.000000,
    0.725186,0.134844,1.988012,0.838980,0.000769,0.076330,0.957824,0.000000,0.496945,0.807306,1.213272,0.009075,0.233134,0.012636,1.828221,2.429213,
    1.805135,0.494339,0.000468,0.271773,0.040806,0.152876,0.559080,0.739888,1.394314,0.001260,0.115379,0.865632,0.015351,1.715788,0.177570,0.074670,
    1.353334,0.087612,0.008405,0.184714,0.357347,0.760473,2.186742,1.167413,1.209644,0.125534,0.008401,0.940463,0.124080,0.010981,2.370603,0.000000,
    1.452327,0.068199,1.480294,0.424987,0.013212,0.001163,0.001657,0.407346,0.000000,0.954632,0.124250,2.211001,0.808913,0.002507,2.235747,0.430729,
    0.032883,0.011492,0.007314,0.777692,0.000000,0.340792,0.550286,1.190970,0.016129,0.000000,1.096821,1.783663,0.690416,1.194808,0.613193,0.794362,
    0.234638,0.093891,0.271944,0.087658,0.479388,0.006724,0.158278,0.000000,0.304574,0.313330,0.417745,0.324008,0.046003,0.039058,0.004781,0.847698,
    1.616466,0.477229,0.000000,4.438352,4.155348,0.371618,0.059839,1.323365,0.345599,0.013765,0.055146,0.008511,0.035057,0.000000,2.652249,0.000000,
    0.550545,0.000000,0.108837,1.088737,0.502754,0.006651,0.019927,0.503464,2.707742,0.043677,0.910347,0.097399,0.806370,0.464375,1.027106,0.044727,
    1.685541,0.002555,0.883808,0.111442,0.005113,0.406282,0.728982,0.087776,2.386451,0.014470,1.875118,0.037259,0.000000,4.279455,0.189061,1.651418,
    0.750136,1.261214,0.336138,0.242002,0.225380,0.360039,0.520607,2.314614,0.099525,0.252469,2.730854,0.835702,0.006621,0.057516,1.059641,0.980411,
    1.929533,1.584694,1.704435,0.341777,1.958663,0.000970,0.039561,3.292661,0.000000,0.093142,1.163145,0.692857,0.008751,0.031535,0.051034,0.026366,
    0.187604,0.158738,0.830309,0.317271,0.148063,0.067554,0.053881,0.127160,0.451525,0.010053,0.000000,1.839725,0.144003,3.097952,0.305813,1.621636,
    0.917974,0.262535,0.000000,0.058486,0.466949,3.664273,0.000000,0.065373,0.075259,0.095304,0.056989,0.498617,0.086833,2.704707,2.525265,0.161862,
    0.104006,0.183719,0.189040,0.000000,0.851539,0.045484,5.567569,1.865962,0.000000,0.006317,1.583390,0.002532,2.545299,0.024614,0.026735,0.000000,
    0.009775,0.112282,0.009802,0.093609,7.617025,0.000000,1.144189,5.722694,1.277627,0.680307,0.889530,0.025324,1.021842,0.010145,0.013431,0.335807,
    0.106149,0.000000,0.000000,0.229720,1.048938,0.078847,0.245025,0.101035,0.000000,0.008202,0.000000,0.912539,0.014006,0.532336,0.016462,0.386075,
    0.296756,1.068002,0.365077,1.293139,1.969919,0.748865,1.290827,1.048145,0.603616,0.458269,0.010459,0.152398,0.284944,0.943705,0.158868,1.034602,
    1.719694,1.510343,0.172517,0.019718,0.000000,0.199998,1.068147,0.203094,1.573467,0.000000,0.225936,4.034974,0.947877,1.141978,0.000000,0.009066,
    0.006376,0.104819,0.057114,1.670206,0.132337,0.495914,0.442948,0.738034,0.883779,3.392052,0.363638,0.101645,0.000000,0.000000,0.012612,0.758066,
    0.019771,0.280428,0.009196,0.355242,0.840791,0.265378,0.008064,1.402990,0.017855,0.678500,0.315003,0.075483,1.213369,0.000000,0.000704,0.000000
};
#endif

int main(int argc, char *argv[])
{
	int colIdx = 0, maxabscol = 0, maxratiocol = 0;
    int i = 1, loopCnt = 1;
    char *pFname = (char *)"face.jpg";
    char *pModel = (char*)"regNet.feathermodel";
    char *pBlob = (char *)"mobilenet_v2_layer9_conv1x1";
    int num_threads = 1;
    struct timeval beg, end;

    printf("e.g.:  ./demo 1.jpg 48net.feathermodel prob1 10 1 \n");

    if (argc > 1) pFname = argv[i++];
    if (argc > 2) pModel = argv[i++];
    if (argc > 3) pBlob = argv[i++];
    if (argc > 4) loopCnt = atoi(argv[i++]);
    if (argc > 5) num_threads = atoi(argv[i++]);

    printf("img: %s model: %s blob: %s loopCnt: %d num_threads: %d\n", pFname, pModel, pBlob, loopCnt, num_threads);

    cv::Mat img = imread(pFname);
    if (img.empty())
    {
        printf("read img failed, %s\n", pFname);
        return -1;
    }

    img.convertTo(img, CV_32F, 1.0 / 128, -127.5/128);
    printf("c: %d w: %d h : %d step: %ld\n", img.channels(), img.cols, img.rows, img.step[0]);

    Net forward_net(num_threads);
    forward_net.InitFromPath(pModel);

    size_t data_size;
    forward_net.GetBlobDataSize(&data_size, pBlob);
    float *pOut = (float *)malloc(data_size*sizeof(float));

    gettimeofday(&beg, NULL);

    for(int loop = 0; loop < loopCnt; loop++)
    {
        int ret = forward_net.Forward((float*)img.data);
        forward_net.ExtractBlob(pOut, pBlob);
    }

    gettimeofday(&end, NULL);
    printf("\ntime: %ld ms, avg time : %.3f ms, loop: %d threads: %d\n\n", (end.tv_sec*1000000 + end.tv_usec - beg.tv_sec*1000000 - beg.tv_usec)/1000, (end.tv_sec*1000000 + end.tv_usec - beg.tv_sec*1000000 - beg.tv_usec)/(1000.0*loopCnt), loopCnt, num_threads);

    printf("out blob size: %lu\n", data_size);

    float maxDiff = .0f;
    float maxDiffRefC =.0f, maxDiffAsm = .0f;
    float maxDiffRatio = .0f;
    float maxDiffRefCRatio =.0f, maxDiffAsmRatio = .0f;

    for(int i = 0 ; i < data_size; i++)
    {
    	if (0 == i) printf("col: %02d ", 0);
        if ((0 != i)&& (0 == i % 8))
            printf("\ncol: %02d ", ++colIdx);
        printf("[%9.6f, %9.6f] ", pOut[i], C_REF[i]);
        if (fabs(*(C_REF + i) - *(pOut + i)) > maxDiff)
        {
            maxDiffRefC = *(C_REF + i);
            maxDiffAsm = *(pOut + i);
            maxDiff = fabs(*(C_REF + i) - *(pOut + i));
			maxabscol = colIdx;
        }
        if (0.f < fabs(*(C_REF + i)))
        {
            if ((fabs(*(C_REF + i) - *(pOut + i)) / fabs(*(C_REF + i))) > maxDiffRatio)
            {
                maxDiffRefCRatio = *(C_REF + i);
                maxDiffAsmRatio = *(pOut + i);
                maxDiffRatio = fabs(*(C_REF + i) - *(pOut + i)) / fabs(*(C_REF + i));
				maxratiocol = colIdx;
            }
        }
    }
    printf("\n\nmaxDiff:\nabs   %9.6f [%9.6f, %9.6f] at cols %02d\nratio %9.6f [%9.6f, %9.6f] at cols %02d\n", maxDiff, maxDiffAsm, maxDiffRefC, maxabscol, maxDiffRefCRatio, maxDiffAsmRatio, maxDiffRefCRatio, maxratiocol);

    free(pOut);
    printf("\n");
    return 0;
}
