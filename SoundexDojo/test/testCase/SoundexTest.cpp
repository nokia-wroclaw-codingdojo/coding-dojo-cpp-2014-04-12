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

    BOOST_FIXTURE_TEST_CASE(Singlechar_String, Fixture)
    {
        std::string singleChar("a");
        BOOST_CHECK_MESSAGE("a" == soundex->encode(singleChar), "One char encode bad");
        singleChar = "b";
        BOOST_CHECK_MESSAGE("b" == soundex->encode(singleChar), "One char encode bad");
    }

    BOOST_FIXTURE_TEST_CASE(doubleChar, Fixture)
    {
        std::string doubleChar("ab");
        BOOST_CHECK_MESSAGE("a1" == soundex->encode(doubleChar), "Double char encode bad");
        doubleChar = "cz";
        BOOST_CHECK_MESSAGE("c2" == soundex->encode(doubleChar), "Double char encode bad");
    }

    BOOST_FIXTURE_TEST_CASE(strangeChars, Fixture)
    {
        std::string chars("a!");
        BOOST_CHECK_MESSAGE("a" == soundex->encode(chars), "chars encode bad");
        chars="#a!";
        BOOST_CHECK_MESSAGE("a" == soundex->encode(chars), "chars encode bad");
    }

    BOOST_FIXTURE_TEST_CASE(charToDeleteIsDelete, Fixture)
    {
        std::string chars("aab");
        BOOST_CHECK_MESSAGE("a1" == soundex->encode(chars), "char is not deleted");
        chars="#abab!";
        BOOST_CHECK_MESSAGE("a11" == soundex->encode(chars), "char is not deleted");
    }

    //BOOST_FIXTURE_TEST_CASE(twoCharsNext, Fixture)
    //{
    //    std::string chars("abb");
    //    BOOST_CHECK_MESSAGE("a1" == soundex->encode(chars), "char is bad");
    //}

    BOOST_AUTO_TEST_SUITE_END();
}
