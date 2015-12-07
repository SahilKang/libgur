/******************************************************************************
 * Copyright (C) 2015 Sahil Kang <sahil.kang@asilaycomputing.com>
 *
 * This file is part of libgur.
 *
 * libgur is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libgur is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with libgur.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include <gur.hpp>
#include <gurmukhi.hpp>
#include <sstream>
#include <set>

BOOST_AUTO_TEST_SUITE(Punctuation)

BOOST_AUTO_TEST_SUITE(Constructors)
	BOOST_AUTO_TEST_CASE(Default)
	{
		gur::Punctuation punc;

		BOOST_REQUIRE_EQUAL(punc.str(), "");
	}

	BOOST_AUTO_TEST_CASE(String)
	{
		std::string str(gur::Q1);

		gur::Punctuation punc(str);

		BOOST_REQUIRE_EQUAL(str.c_str(), gur::Q1);
		BOOST_REQUIRE_EQUAL(punc.str(), str);
	}

	BOOST_AUTO_TEST_CASE(MoveString)
	{
		std::string str(gur::Q1);

		gur::Punctuation punc(std::move(str));

		BOOST_REQUIRE_EQUAL(str, "");
		BOOST_REQUIRE_EQUAL(punc.str().c_str(), gur::Q1);
	}

	BOOST_AUTO_TEST_CASE(CharPointer)
	{
		const char* const c = gur::Q1;

		gur::Punctuation punc(c);

		BOOST_REQUIRE_EQUAL(c, gur::Q1);
		BOOST_REQUIRE_EQUAL(punc.str().c_str(), c);
	}

	BOOST_AUTO_TEST_CASE(Copy)
	{
		gur::Punctuation punc_one(gur::Q1);
		gur::Punctuation punc_two(punc_one);

		BOOST_REQUIRE_EQUAL(punc_one.str().c_str(), gur::Q1);
		BOOST_REQUIRE_EQUAL(punc_two.str(), punc_one.str());
	}

	BOOST_AUTO_TEST_CASE(Move)
	{
		gur::Punctuation punc_one(gur::Q1);
		gur::Punctuation punc_two(std::move(punc_one));

		BOOST_REQUIRE_EQUAL(punc_one.str(), "");
		BOOST_REQUIRE_EQUAL(punc_two.str().c_str(), gur::Q1);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(PublicMembers)
	BOOST_AUTO_TEST_CASE(Str)
	{
		gur::Punctuation punc(gur::Q1);

		BOOST_REQUIRE_EQUAL(punc.str().c_str(), gur::Q1);
	}

	BOOST_AUTO_TEST_CASE(IsValidChar)
	{
		BOOST_CHECK_EQUAL(gur::Punctuation::is_valid(gur::O2), true);
		BOOST_CHECK_EQUAL(gur::Punctuation::is_valid(gur::Q1), true);
		BOOST_CHECK_EQUAL(gur::Punctuation::is_valid(gur::Q2), true);

		BOOST_REQUIRE_EQUAL(
			gur::Punctuation::is_valid(gur::L1),
			false);
		BOOST_REQUIRE_EQUAL(
			gur::Punctuation::is_valid(gur::L2),
			false);
	}

	BOOST_AUTO_TEST_CASE(IsValidString)
	{
		std::string O2(gur::O2);
		std::string Q1(gur::Q1);
		std::string Q2(gur::Q2);

		std::string L1(gur::L1);
		std::string L2(gur::L2);

		BOOST_CHECK_EQUAL(gur::Punctuation::is_valid(O2), true);
		BOOST_CHECK_EQUAL(gur::Punctuation::is_valid(Q1), true);
		BOOST_CHECK_EQUAL(gur::Punctuation::is_valid(Q2), true);

		BOOST_REQUIRE_EQUAL(gur::Punctuation::is_valid(L1), false);
		BOOST_REQUIRE_EQUAL(gur::Punctuation::is_valid(L2), false);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Operators)
	BOOST_AUTO_TEST_CASE(Assignment)
	{
		gur::Punctuation punc_one(gur::Q1);
		gur::Punctuation punc_two(gur::Q2);

		punc_two = punc_one;

		BOOST_REQUIRE_EQUAL(punc_one.str().c_str(), gur::Q1);
		BOOST_REQUIRE_EQUAL(punc_two.str(), punc_one.str());
	}

	BOOST_AUTO_TEST_CASE(AssignmentMove)
	{
		gur::Punctuation punc_one(gur::Q1);
		gur::Punctuation punc_two(gur::Q2);

		const std::string expected = punc_two.str();
		punc_two = std::move(punc_one);

		BOOST_REQUIRE_EQUAL(punc_one.str(), expected);
		BOOST_REQUIRE_EQUAL(punc_two.str().c_str(), gur::Q1);
	}

	BOOST_AUTO_TEST_CASE(Ostream)
	{
		boost::test_tools::output_test_stream out;
		gur::Punctuation punc(gur::Q1);

		out << punc;

		BOOST_REQUIRE(out.is_equal(gur::Q1));
		BOOST_REQUIRE_EQUAL(punc.str().c_str(), gur::Q1);
	}

	BOOST_AUTO_TEST_CASE(Istream)
	{
		std::istringstream iss(gur::Q1);
		gur::Punctuation punc(gur::Q2);

		iss >> punc;

		BOOST_REQUIRE_EQUAL(punc.str().c_str(), gur::Q1);
	}

	BOOST_AUTO_TEST_CASE(EqualTo)
	{
		gur::Punctuation punc_one(gur::Q1);
		gur::Punctuation punc_two(gur::Q1);
		gur::Punctuation punc_three(gur::Q2);

		BOOST_REQUIRE_EQUAL(punc_one == punc_two, true);
		BOOST_REQUIRE_EQUAL(punc_one == punc_three, false);
	}

	BOOST_AUTO_TEST_CASE(NotEqualTo)
	{
		gur::Punctuation punc_one(gur::Q1);
		gur::Punctuation punc_two(gur::Q2);
		gur::Punctuation punc_three(gur::Q1);

		BOOST_REQUIRE_EQUAL(punc_one != punc_two, true);
		BOOST_REQUIRE_EQUAL(punc_one != punc_three, false);
	}

	BOOST_AUTO_TEST_CASE(LessThan)
	{
		gur::Punctuation punc_1(gur::O2);
		gur::Punctuation punc_2(gur::Q1);
		gur::Punctuation punc_3(gur::Q2);

		BOOST_CHECK_EQUAL(punc_1 < punc_2, true);
		BOOST_CHECK_EQUAL(punc_2 < punc_3, true);
	}

	BOOST_AUTO_TEST_CASE(GreaterThan)
	{
		gur::Punctuation punc_1(gur::O2);
		gur::Punctuation punc_2(gur::Q1);
		gur::Punctuation punc_3(gur::Q2);

		BOOST_CHECK_EQUAL(punc_2 > punc_1, true);
		BOOST_CHECK_EQUAL(punc_3 > punc_2, true);
	}

	BOOST_AUTO_TEST_CASE(LessThanOrEqualTo)
	{
		gur::Punctuation punc_1(gur::O2);
		gur::Punctuation punc_2(gur::Q1);
		gur::Punctuation punc_3(gur::Q2);

		BOOST_CHECK_EQUAL(punc_1 <= punc_2, true);
		BOOST_CHECK_EQUAL(punc_2 <= punc_3, true);
	}

	BOOST_AUTO_TEST_CASE(GreaterThanOrEqualTo)
	{
		gur::Punctuation punc_1(gur::O2);
		gur::Punctuation punc_2(gur::Q1);
		gur::Punctuation punc_3(gur::Q2);

		BOOST_CHECK_EQUAL(punc_2 >= punc_1, true);
		BOOST_CHECK_EQUAL(punc_3 >= punc_2, true);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Functionatlity)
	BOOST_AUTO_TEST_CASE(Hash)
	{
		const std::array<gur::Punctuation, 10> letters
		{
			gur::Punctuation(gur::A1), gur::Punctuation(gur::A1),
			gur::Punctuation(gur::A2), gur::Punctuation(gur::A2),
			gur::Punctuation(gur::A3), gur::Punctuation(gur::A3),
			gur::Punctuation(gur::A4), gur::Punctuation(gur::A4),
			gur::Punctuation(gur::A5), gur::Punctuation(gur::A5)
		};

		std::set<gur::Punctuation> set(letters.begin(), letters.end());

		unsigned int count = 0;
		for (auto &element : set)
		{
			switch (count)
			{
				case 0 : BOOST_CHECK_EQUAL(
					element, letters[0]); break;
				case 1 : BOOST_CHECK_EQUAL(
					element, letters[2]); break;
				case 2 : BOOST_CHECK_EQUAL(
					element, letters[4]); break;
				case 3 : BOOST_CHECK_EQUAL(
					element, letters[6]); break;
				case 4 : BOOST_CHECK_EQUAL(
					element, letters[8]); break;
			};

			++count;
		}
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
