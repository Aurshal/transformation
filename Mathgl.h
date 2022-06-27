#include <iostream>
#include <math.h>
using namespace std;
class Mathgl
{
public:
    static float** create_matrix_of_ones(int m, int n);
    static float** get_translation_mat(float* trans, int n);
    static void multiply(float** matA, float** matB, float** res, int n);
    static float** input_mat(int m, int n);
    static void disp_mat(float** mat, int m, int n);
    static float** create_mat_of_m_by_n(int m, int n);
    static float** create_imat_of_m_by_n(int m, int n);
    static void transform(float** transMat, float** mat, int m, int n);
    static void vecMultiply(float** matA, float* matB, float* res, int n);
    static float** get_scale_mat(float* trans, int n);
    static float** get_rot_mat(float theta, float* axes, int n);
};
