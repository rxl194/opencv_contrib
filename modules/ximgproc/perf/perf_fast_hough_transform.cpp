/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                           License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2015, Smart Engines Ltd, all rights reserved.
// Copyright (C) 2015, Institute for Information Transmission Problems of the Russian Academy of Sciences (Kharkevich Institute), all rights reserved.
// Copyright (C) 2015, Dmitry Nikolaev, Simon Karpenko, Michail Aliev, Elena Kuznetsova, all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#include "perf_precomp.hpp"

namespace cvtest {

using namespace std;
using namespace cv;
using namespace cv::ximgproc;
using namespace perf;
using namespace testing;

using std::tr1::make_tuple;
using std::tr1::get;

typedef std::tr1::tuple<Size, MatType, MatDepth> srcSize_srcType_dstDepth_t;
typedef perf::TestBaseWithParam<srcSize_srcType_dstDepth_t>
        srcSize_srcType_dstDepth;

#define ALL_MAT_DEPHTS CV_8U, CV_8S, CV_16U, CV_32S, CV_32F, CV_64F

PERF_TEST_P(srcSize_srcType_dstDepth, FastHoughTransform,
            testing::Combine(
                testing::Values(TYPICAL_MAT_SIZES),
                testing::Values(TYPICAL_MAT_TYPES),
                testing::Values(ALL_MAT_DEPHTS)
                )
            )
{
    Size srcSize  = get<0>(GetParam());
    int  srcType  = get<1>(GetParam());
    int  dstDepth = get<2>(GetParam());

    Mat src(srcSize, srcType);
    Mat fht;

    declare.in(src, WARMUP_RNG);

    TEST_CYCLE_N(3)
    {
        FastHoughTransform(src, fht, dstDepth);
    }

    SANITY_CHECK_NOTHING();
}

#undef ALL_MAT_DEPHTS

} // namespace cvtest
