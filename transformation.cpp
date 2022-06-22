#include "transformation.h"
int main() {
  int n, m;
  cout << "n: ";
  cin >> n;
  cout << "No. of vertices: " << endl;
  cin >> m;
  n = n + 1;
  m = m + 1;
  cout << "Enter for matA: " << endl;
  float **matA = input_mat(m, n);
  cout << "MatA: " << endl;
  disp_mat(matA, m, n);
  float t[n];
  cout << "Enter translation vector: " << endl;
  for (int i = 0; i < n - 1; i++) {
    cin >> t[i];
  }
  t[n - 1] = 1;
  float **transMat = get_translation_mat(t, n);

  float s[n];
  cout << "Enter scale vector: " << endl;
  for (int i = 0; i < n - 1; i++) {
    cin >> s[i];
  }
  s[n - 1] = 1;
  float **scaleMat = get_scale_mat(s, n);
  float **rotMat;
  float theta;
  cout << "Enter rotation theta in rad: " << endl;
  cin >> theta;
  float axes[n - 1];
  cout << "Enter axes vector: " << endl;
  for (int i = 0; i < n - 1; i++) {
    cin >> axes[i];
  }
  rotMat = get_rot_mat(theta, axes, n);
  float **composite = create_mat_of_m_by_n(n, n);
  multiply(scaleMat, rotMat, composite, n);
  multiply(composite, transMat, composite, n);
  cout << "Composite: " << endl;
  disp_mat(composite, n, n);
  transform(composite, matA, m, n);
  cout << "Translated matrix: " << endl;
  disp_mat(matA, m - 1, n - 1);
  return 0;
}
void transform(float **transMat, float **mat, int m, int n) {
  float vect[n];
  float updatedVect[n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      vect[j] = mat[i][j];
    }

    vecMultiply(transMat, vect, updatedVect, n);
    for (int k = 0; k < n; k++) {
      mat[i][k] = updatedVect[k];
    }
  }
}
void vecMultiply(float **transMat, float *vect, float *res, int n) {
  for (int i = 0; i < n; i++) {
    float sum = 0;
    for (int k = 0; k < n; k++) {
      sum += (transMat[i][k] * vect[k]);
    }
    res[i] = sum;
  }
  return;
}
void multiply(float **matA, float **matB, float **res, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      float sum = 0;
      for (int k = 0; k < n; k++) {
        sum += (matA[i][k] * matB[k][j]);
      }
      res[i][j] = sum;
    }
  }
  return;
}
float **input_mat(int m, int n) {
  float **mat = create_matrix_of_ones(m, n);
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      cin >> mat[i][j];
    }
    cout << endl;
  }
  return mat;
};
void disp_mat(float **mat, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
};
float **get_translation_mat(float *trans, int n) {
  float **transMat = create_imat_of_m_by_n(n, n);
  for (int i = 0; i < n; i++) {
    transMat[i][n - 1] = trans[i];
  }
  return transMat;
}
float **get_scale_mat(float *trans, int n) {
  float **scaleMat = create_imat_of_m_by_n(n, n);
  for (int i = 0; i < n; i++) {
    scaleMat[i][i] = trans[i];
  }
  return scaleMat;
}
float **get_rot_mat(float theta, float *axes, int n) {
  float **rotMat = create_imat_of_m_by_n(n, n);
  theta = theta * (M_PI / 180);
  float x = axes[0];
  float y = axes[1];
  float s = sin(theta);
  float c = cos(theta);
  float omc = 1 - cos(theta);
  if (n == 3) {
    float z = axes[2];
    rotMat[0][0] = c + x * x * omc;
    rotMat[0][1] = x * y * omc - z * s;
    rotMat[0][2] = x * y * omc + y * s;
    rotMat[1][0] = y * x * omc + z * s;
    rotMat[1][1] = c + y * y * omc;
    rotMat[1][2] = y * z * omc - x * s;
    rotMat[2][0] = z * x * omc - y * s;
    rotMat[2][1] = z * y * omc + x * s;
    rotMat[2][2] = c + z * z * omc;
    return rotMat;
  }
  rotMat[0][0] = c;
  rotMat[0][1] = -s;
  rotMat[0][2] = x * omc + y * s;
  rotMat[1][0] = s;
  rotMat[1][1] = c;
  rotMat[1][2] = y * omc - x * s;
  return rotMat;
}
float **create_mat_of_m_by_n(int m, int n) {
  float **mat = new float *[m];
  for (int i = 0; i < m; i++) {
    mat[i] = new float[n];
  }
  return mat;
}
float **create_imat_of_m_by_n(int m, int n) {
  float **mat = create_mat_of_m_by_n(m, n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        mat[i][j] = 1;
      } else {
        mat[i][j] = 0;
      }
    }
  }
  return mat;
}
float **create_matrix_of_ones(int m, int n) {
  float **mat = create_mat_of_m_by_n(m, n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      mat[i][j] = 1;
    }
  }
  return mat;
}
