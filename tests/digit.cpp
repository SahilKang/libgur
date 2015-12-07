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

BOOST_AUTO_TEST_SUITE(Digit)

BOOST_AUTO_TEST_SUITE(Constructors)
	BOOST_AUTO_TEST_CASE(Default)
	{
		gur::Digit digit;

		BOOST_REQUIRE_EQUAL(digit.str(), "");
	}

	BOOST_AUTO_TEST_CASE(String)
	{
		std::string str(gur::K1);

		gur::Digit digit(str);

		BOOST_REQUIRE_EQUAL(str.c_str(), gur::K1);
		BOOST_REQUIRE_EQUAL(digit.str(), str);
	}

	BOOST_AUTO_TEST_CASE(MoveString)
	{
		std::string str(gur::K1);

		gur::Digit digit(std::move(str));

		BOOST_REQUIRE_EQUAL(str, "");
		BOOST_REQUIRE_EQUAL(digit.str().c_str(), gur::K1);
	}

	BOOST_AUTO_TEST_CASE(CharPointer)
	{
		const char* const c = gur::K1;

		gur::Digit digit(c);

		BOOST_REQUIRE_EQUAL(c, gur::K1);
		BOOST_REQUIRE_EQUAL(digit.str().c_str(), c);
	}

	BOOST_AUTO_TEST_CASE(Copy)
	{
		gur::Digit digit_one(gur::K1);
		gur::Digit digit_two(digit_one);

		BOOST_REQUIRE_EQUAL(digit_one.str().c_str(), gur::K1);
		BOOST_REQUIRE_EQUAL(digit_two.str(), digit_one.str());
	}

	BOOST_AUTO_TEST_CASE(Move)
	{
		gur::Digit digit_one(gur::K1);
		gur::Digit digit_two(std::move(digit_one));

		BOOST_REQUIRE_EQUAL(digit_one.str(), "");
		BOOST_REQUIRE_EQUAL(digit_two.str().c_str(), gur::K1);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(PublicMembers)
	BOOST_AUTO_TEST_CASE(Str)
	{
		gur::Digit digit(gur::K1);

		BOOST_REQUIRE_EQUAL(digit.str().c_str(), gur::K1);
	}

	BOOST_AUTO_TEST_CASE(IsValidChar)
	{
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::K1), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::K2), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::K3), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::K4), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::K5), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::L1), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::L2), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::L3), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::L4), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::L5), true);

		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::N1), false);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(gur::N2), false);
	}

	BOOST_AUTO_TEST_CASE(IsValidString)
	{
		std::string K1(gur::K1);
		std::string K2(gur::K2);
		std::string K3(gur::K3);
		std::string K4(gur::K4);
		std::string K5(gur::K5);
		std::string L1(gur::L1);
		std::string L2(gur::L2);
		std::string L3(gur::L3);
		std::string L4(gur::L4);
		std::string L5(gur::L5);

		std::string N1(gur::N1);
		std::string N2(gur::N2);

		BOOST_CHECK_EQUAL(gur::Digit::is_valid(K1), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(K2), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(K3), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(K4), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(K5), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(L1), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(L2), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(L3), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(L4), true);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(L5), true);

		BOOST_CHECK_EQUAL(gur::Digit::is_valid(N1), false);
		BOOST_CHECK_EQUAL(gur::Digit::is_valid(N2), false);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Operators)
	BOOST_AUTO_TEST_CASE(Assignment)
	{
		gur::Digit digit_one(gur::K1);
		gur::Digit digit_two(gur::K2);

		digit_two = digit_one;

		BOOST_REQUIRE_EQUAL(digit_one.str().c_str(), gur::K1);
		BOOST_REQUIRE_EQUAL(digit_two.str(), digit_one.str());
	}

	BOOST_AUTO_TEST_CASE(AssignmentMove)
	{
		gur::Digit digit_one(gur::K1);
		gur::Digit digit_two(gur::K2);

		const std::string expected = digit_two.str();
		digit_two = std::move(digit_one);

		BOOST_REQUIRE_EQUAL(digit_one.str(), expected);
		BOOST_REQUIRE_EQUAL(digit_two.str().c_str(), gur::K1);
	}

	BOOST_AUTO_TEST_CASE(Ostream)
	{
		boost::test_tools::output_test_stream out;
		gur::Digit digit(gur::K1);

		out << digit;

		BOOST_REQUIRE(out.is_equal(gur::K1));
		BOOST_REQUIRE_EQUAL(digit.str().c_str(), gur::K1);
	}

	BOOST_AUTO_TEST_CASE(Istream)
	{
		std::istringstream iss(gur::K1);
		gur::Digit digit(gur::K2);

		iss >> digit;

		BOOST_REQUIRE_EQUAL(digit.str().c_str(), gur::K1);
	}

	BOOST_AUTO_TEST_CASE(EqualTo)
	{
		gur::Digit digit_one(gur::K1);
		gur::Digit digit_two(gur::K1);
		gur::Digit digit_three(gur::K2);

		BOOST_REQUIRE_EQUAL(digit_one == digit_two, true);
		BOOST_REQUIRE_EQUAL(digit_one == digit_three, false);
	}

	BOOST_AUTO_TEST_CASE(NotEqualTo)
	{
		gur::Digit digit_one(gur::K1);
		gur::Digit digit_two(gur::K2);
		gur::Digit digit_three(gur::K1);

		BOOST_REQUIRE_EQUAL(digit_one != digit_two, true);
		BOOST_REQUIRE_EQUAL(digit_one != digit_three, false);
	}

	BOOST_AUTO_TEST_CASE(LessThan)
	{
		gur::Digit digit_1(gur::K1);
		gur::Digit digit_2(gur::K2);
		gur::Digit digit_3(gur::K3);
		gur::Digit digit_4(gur::K4);
		gur::Digit digit_5(gur::K5);
		gur::Digit digit_6(gur::L1);
		gur::Digit digit_7(gur::L2);
		gur::Digit digit_8(gur::L3);
		gur::Digit digit_9(gur::L4);
		gur::Digit digit_10(gur::L5);

		BOOST_CHECK_EQUAL(digit_1 < digit_2, true);
		BOOST_CHECK_EQUAL(digit_2 < digit_3, true);
		BOOST_CHECK_EQUAL(digit_3 < digit_4, true);
		BOOST_CHECK_EQUAL(digit_4 < digit_5, true);
		BOOST_CHECK_EQUAL(digit_5 < digit_6, true);
		BOOST_CHECK_EQUAL(digit_6 < digit_7, true);
		BOOST_CHECK_EQUAL(digit_7 < digit_8, true);
		BOOST_CHECK_EQUAL(digit_8 < digit_9, true);
		BOOST_CHECK_EQUAL(digit_9 < digit_10, true);
	}

	BOOST_AUTO_TEST_CASE(GreaterThan)
	{
		gur::Digit digit_1(gur::K1);
		gur::Digit digit_2(gur::K2);
		gur::Digit digit_3(gur::K3);
		gur::Digit digit_4(gur::K4);
		gur::Digit digit_5(gur::K5);
		gur::Digit digit_6(gur::L1);
		gur::Digit digit_7(gur::L2);
		gur::Digit digit_8(gur::L3);
		gur::Digit digit_9(gur::L4);
		gur::Digit digit_10(gur::L5);

		BOOST_CHECK_EQUAL(digit_2 > digit_1, true);
		BOOST_CHECK_EQUAL(digit_3 > digit_2, true);
		BOOST_CHECK_EQUAL(digit_4 > digit_3, true);
		BOOST_CHECK_EQUAL(digit_5 > digit_4, true);
		BOOST_CHECK_EQUAL(digit_6 > digit_5, true);
		BOOST_CHECK_EQUAL(digit_7 > digit_6, true);
		BOOST_CHECK_EQUAL(digit_8 > digit_7, true);
		BOOST_CHECK_EQUAL(digit_9 > digit_8, true);
		BOOST_CHECK_EQUAL(digit_10 > digit_9, true);
	}

	BOOST_AUTO_TEST_CASE(LessThanOrEqualTo)
	{
		gur::Digit digit_1(gur::K1);
		gur::Digit digit_2(gur::K2);
		gur::Digit digit_3(gur::K3);
		gur::Digit digit_4(gur::K4);
		gur::Digit digit_5(gur::K5);
		gur::Digit digit_6(gur::L1);
		gur::Digit digit_7(gur::L2);
		gur::Digit digit_8(gur::L3);
		gur::Digit digit_9(gur::L4);
		gur::Digit digit_10(gur::L5);

		BOOST_CHECK_EQUAL(digit_1 <= digit_2, true);
		BOOST_CHECK_EQUAL(digit_2 <= digit_3, true);
		BOOST_CHECK_EQUAL(digit_3 <= digit_4, true);
		BOOST_CHECK_EQUAL(digit_4 <= digit_5, true);
		BOOST_CHECK_EQUAL(digit_5 <= digit_6, true);
		BOOST_CHECK_EQUAL(digit_6 <= digit_7, true);
		BOOST_CHECK_EQUAL(digit_7 <= digit_8, true);
		BOOST_CHECK_EQUAL(digit_8 <= digit_9, true);
		BOOST_CHECK_EQUAL(digit_9 <= digit_10, true);
	}

	BOOST_AUTO_TEST_CASE(GreaterThanOrEqualTo)
	{
		gur::Digit digit_1(gur::K1);
		gur::Digit digit_2(gur::K2);
		gur::Digit digit_3(gur::K3);
		gur::Digit digit_4(gur::K4);
		gur::Digit digit_5(gur::K5);
		gur::Digit digit_6(gur::L1);
		gur::Digit digit_7(gur::L2);
		gur::Digit digit_8(gur::L3);
		gur::Digit digit_9(gur::L4);
		gur::Digit digit_10(gur::L5);

		BOOST_CHECK_EQUAL(digit_2 >= digit_1, true);
		BOOST_CHECK_EQUAL(digit_3 >= digit_2, true);
		BOOST_CHECK_EQUAL(digit_4 >= digit_3, true);
		BOOST_CHECK_EQUAL(digit_5 >= digit_4, true);
		BOOST_CHECK_EQUAL(digit_6 >= digit_5, true);
		BOOST_CHECK_EQUAL(digit_7 >= digit_6, true);
		BOOST_CHECK_EQUAL(digit_8 >= digit_7, true);
		BOOST_CHECK_EQUAL(digit_9 >= digit_8, true);
		BOOST_CHECK_EQUAL(digit_10 >= digit_9, true);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Functionatlity)
	BOOST_AUTO_TEST_CASE(Hash)
	{
		const std::array<gur::Digit, 10> letters
		{
			gur::Digit(gur::A1), gur::Digit(gur::A1),
			gur::Digit(gur::A2), gur::Digit(gur::A2),
			gur::Digit(gur::A3), gur::Digit(gur::A3),
			gur::Digit(gur::A4), gur::Digit(gur::A4),
			gur::Digit(gur::A5), gur::Digit(gur::A5)
		};

		std::set<gur::Digit> set(letters.begin(), letters.end());

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
