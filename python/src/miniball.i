%module miniball

%{
    #define SWIG_FILE_WITH_INIT
    
    double getMinBall(int n, double * result, int n1, int n2, double *coords);
  //  double getMinBall2(int n, double * result, int n1, int n2, double *coords);

%}

%include "numpy.i"

%init %{
    import_array();
%}

%apply (int DIM1, double* ARGOUT_ARRAY1) {(int n, double* result)}
%apply (int DIM1, int DIM2, double* IN_ARRAY2){(int n1, int n2, double *coords)}

double getMinBall(int n, double * result, int n1, int n2, double *coords);
//double getMinBall2(int n, double * result, int n1, int n2, double *coords);