#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;


BOOST_AUTO_TEST_SUITE(MatrixIOTests)

BOOST_AUTO_TEST_CASE(OpenDataDimension)
{
    int rowsNumber = 3;
    int columnsNumber = 3;
    MatrixXd LoadedMatrix = matrixIO::openData("../data/m3.csv", 3);
    BOOST_TEST(LoadedMatrix.rows() == rowsNumber);
    BOOST_TEST(LoadedMatrix.cols() == columnsNumber);
}


BOOST_AUTO_TEST_SUITE_END()