#include "Seb.h"
namespace second_alg{
//#include "Miniball.hpp"
}
#include <vector>

using std::vector;

typedef Seb::Point<double> Point;
typedef vector<Point> PointVector;
typedef Seb::Smallest_enclosing_ball<double> Miniball;



double getMinBall(int n, double * result, int n1, int n2, double *coords)
{
    if (n!=n2){
        return -2.;
    }
    PointVector S;
    for(int i=0;i<n1;i++){
        vector<double> vcoords(coords+n2*i, coords+n2+n2*i);
        if (vcoords.size()!=n2){
            return -1.;
        }
        S.push_back(Point(n2,vcoords.begin()));
    }
    Miniball mb(n2, S);
    Miniball::Coordinate_iterator center_it = mb.center_begin();
    for(int i=0;i<n2;i++){
        result[i] = center_it[i];
    }
    return mb.squared_radius();
}

/*

double getMinBall2(int n, double * result, int n1, int n2, double *coords)
{
    if (n!=n2){
        return -2.;
    }
    double **points = new double*[n1];
    for(int i=0;i<n1;i++){
        points[i] = new double[n2];
        for(int j=0;j<n2;j++){
            points[i][j] = coords[j+n2*i];
        }
    }
    typedef double* const* PointIterator; 
    typedef const double* CoordIterator;
    typedef second_alg::Miniball::Miniball <second_alg::Miniball::CoordAccessor<PointIterator, CoordIterator> > MB;
    MB mb (n2, points, points+n1);
    const double* center = mb.center(); 
    for(int i=0;i<n2;i++){
        result[i] = center[i];
    }
    return mb.squared_radius();
}*/