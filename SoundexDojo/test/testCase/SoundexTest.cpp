#include <boost/test/unit_test.hpp>
#include<class/Soundex.hpp>
/*                             The Three Laws of TDD
* 1. You are not allowed to write any production code unless it is to make a failing unit test pass.
* 2. You are not allowed to write any more of a unit test than is sufficient to fail; and compilation failures are failures.
* 3. You are not allowed to write any more production code than is sufficient to pass the one failing unit test.
*/

namespace
{
    BOOST_AUTO_TEST_SUITE( SoundexTest );

    BOOST_AUTO_TEST_CASE( empty )
    {
        Soundex* ptr = NULL;
        BOOST_CHECK_MESSAGE(ptr == NULL, "ptr is not NULL!");
        ptr = new Soundex();
        BOOST_CHECK_MESSAGE(ptr != NULL, "ptr is NULL!");
        delete ptr;
    }

    BOOST_AUTO_TEST_SUITE_END();
}
