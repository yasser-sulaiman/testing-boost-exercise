#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "matrixIO.hpp"

using namespace Eigen;

struct MatrixIOFixture {
  MatrixIOFixture()
  {
    testMatrix = MatrixXd(3, 3);

    testMatrix << 0.680375, 0.59688, -0.329554,
        -0.211234, 0.823295, 0.536459,
        0.566198, -0.604897, -0.444451;
  }

  MatrixXd testMatrix;
};

BOOST_FIXTURE_TEST_SUITE(MatrixIOTests, MatrixIOFixture, *boost::unit_test::tolerance(1e-16))

BOOST_AUTO_TEST_CASE(MyOnlyTest)

{
  MatrixXd loadedMatrix = matrixIO::openData("../data/m3.csv", 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      BOOST_TEST(testMatrix(i, j) == loadedMatrix(i, j));
    }
  }
}

BOOST_AUTO_TEST_SUITE_END()