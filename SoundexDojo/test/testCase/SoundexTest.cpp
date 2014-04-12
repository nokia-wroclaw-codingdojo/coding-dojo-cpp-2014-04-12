#include <boost/test/unit_test.hpp>
#include <class/Soundex.hpp>
#include <memory>
#include <string>


/*                             The Three Laws of TDD
* 1. You are not allowed to write any production code unless it is to make a failing unit test pass.
* 2. You are not allowed to write any more of a unit test than is sufficient to fail; and compilation failures are failures.
* 3. You are not allowed to write any more production code than is sufficient to pass the one failing unit test.
*/

namespace
{
    struct Fixture 
    {
    public:

        Fixture() : soundex(new Soundex())
        {

        }


        std::unique_ptr<Soundex> soundex;
        


    };


    BOOST_AUTO_TEST_SUITE( SoundexTest );

    BOOST_FIXTURE_TEST_CASE(Empty_String, Fixture)
    {   
        std::string emptyString;
        BOOST_CHECK_MESSAGE(emptyString == soundex->encode(""), "String is not empty");
    }

    BOOST_AUTO_TEST_SUITE_END();
}
