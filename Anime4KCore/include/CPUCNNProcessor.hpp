#pragma once

#ifndef ENABLE_OPENCV_DNN

#include"AC.hpp"

namespace Anime4KCPP
{
    namespace CPU
    {
#ifdef ENABLE_AVX
#define AC_CV_FPC(n) CV_32FC(n)
        typedef float FP;
        typedef float* ChanFP;
        typedef float* LineFP;
        typedef float* PixelFP;
#else
#define AC_CV_FPC(n) CV_64FC(n)
        typedef double FP;
        typedef double* ChanFP;
        typedef double* LineFP;
        typedef double* PixelFP;
#endif // ENABLE_AVX

        class CNNProcessor;
    }
}

class Anime4KCPP::CPU::CNNProcessor
{
protected:
    void conv1To8B(const cv::Mat& img, const FP* kernels, const FP* biases, cv::Mat& tmpMat);
    void conv1To8W(const cv::Mat& img, const FP* kernels, const FP* biases, cv::Mat& tmpMat);
    void conv1To8F(const cv::Mat& img, const FP* kernels, const FP* biases, cv::Mat& tmpMat);
    void conv8To8(const FP* kernels, const FP* biases, cv::Mat& tmpMat);
    void convTranspose8To1B(cv::Mat& img, const FP* kernels, cv::Mat& tmpMat);
    void convTranspose8To1W(cv::Mat& img, const FP* kernels, cv::Mat& tmpMat);
    void convTranspose8To1F(cv::Mat& img, const FP* kernels, cv::Mat& tmpMat);
};

#endif // !ENABLE_OPENCV_DNN
