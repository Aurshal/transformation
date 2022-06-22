#include <iostream>
#include <math.h>
using namespace std;
float **create_matrix_of_ones(int m, int n);
float **get_translation_mat(float *trans, int n);
void multiply(float **matA, float **matB, float **res, int n);
float **input_mat(int m, int n);
void disp_mat(float **mat, int m, int n);
float **create_mat_of_m_by_n(int m, int n);
float **create_imat_of_m_by_n(int m, int n);
void transform(float **transMat, float **mat, int m, int n);
void vecMultiply(float **matA, float *matB, float *res, int n);
float **get_scale_mat(float *trans, int n);
float **get_rot_mat2D(float theta, float *axes, int n);
float **get_rot_mat3D(float theta, float *axes, int n);
