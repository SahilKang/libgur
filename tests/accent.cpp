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

BOOST_AUTO_TEST_SUITE(Accent)

BOOST_AUTO_TEST_SUITE(Constructors)
	BOOST_AUTO_TEST_CASE(Default)
	{
		gur::Accent accent;

		BOOST_REQUIRE_EQUAL(accent.str(), "");
	}

	BOOST_AUTO_TEST_CASE(String)
	{
		std::string str("\u0a3e");

		gur::Accent accent(str);

		BOOST_REQUIRE_EQUAL(str, "\u0a3e");
		BOOST_REQUIRE_EQUAL(accent.str(), str);
	}

	BOOST_AUTO_TEST_CASE(MoveString)
	{
		std::string str("\u0a3f");

		gur::Accent accent(std::move(str));

		BOOST_REQUIRE_EQUAL(str, "");
		BOOST_REQUIRE_EQUAL(accent.str(), "\u0a3f");
	}

	BOOST_AUTO_TEST_CASE(CharPointer)
	{
		const char* const c = gur::I4;

		gur::Accent accent(c);

		BOOST_REQUIRE_EQUAL(c, gur::I4);
		BOOST_REQUIRE_EQUAL(accent.str().c_str(), c);
	}

	BOOST_AUTO_TEST_CASE(Copy)
	{
		gur::Accent accent_one("\u0a02");
		gur::Accent accent_two(accent_one);

		BOOST_REQUIRE_EQUAL(accent_one.str(), "\u0a02");
		BOOST_REQUIRE_EQUAL(accent_two.str(), accent_one.str());
	}

	BOOST_AUTO_TEST_CASE(Move)
	{
		gur::Accent accent_one("\u0a4c");
		gur::Accent accent_two(std::move(accent_one));

		BOOST_REQUIRE_EQUAL(accent_one.str(), "");
		BOOST_REQUIRE_EQUAL(accent_two.str(), "\u0a4c");
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(PublicMembers)
	BOOST_AUTO_TEST_CASE(Str)
	{
		gur::Accent accent("\u0a3f");

		BOOST_REQUIRE_EQUAL(accent.str(), "\u0a3f");
	}

	BOOST_AUTO_TEST_CASE(IsValidChar)
	{
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::H1), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::H2), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::H3), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::H4), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::H5), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::I1), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::I2), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::I3), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::I4), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::I5), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::J1), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::J2), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::J3), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::J4), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::O1), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::O5), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(gur::P5), true);

		BOOST_REQUIRE_EQUAL(gur::Accent::is_valid(gur::L1), false);
		BOOST_REQUIRE_EQUAL(gur::Accent::is_valid(gur::L2), false);
	}

	BOOST_AUTO_TEST_CASE(IsValidString)
	{
		std::string H1(gur::H1);
		std::string H2(gur::H2);
		std::string H3(gur::H3);
		std::string H4(gur::H4);
		std::string H5(gur::H5);
		std::string I1(gur::I1);
		std::string I2(gur::I2);
		std::string I3(gur::I3);
		std::string I4(gur::I4);
		std::string I5(gur::I5);
		std::string J1(gur::J1);
		std::string J2(gur::J2);
		std::string J3(gur::J3);
		std::string J4(gur::J4);
		std::string O1(gur::O1);
		std::string O5(gur::O5);
		std::string P5(gur::P5);

		std::string L1(gur::L1);
		std::string L2(gur::L2);

		BOOST_CHECK_EQUAL(gur::Accent::is_valid(H1), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(H2), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(H3), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(H4), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(H5), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(I1), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(I2), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(I3), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(I4), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(I5), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(J1), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(J2), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(J3), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(J4), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(O1), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(O5), true);
		BOOST_CHECK_EQUAL(gur::Accent::is_valid(P5), true);

		BOOST_REQUIRE_EQUAL(gur::Accent::is_valid(L1), false);
		BOOST_REQUIRE_EQUAL(gur::Accent::is_valid(L2), false);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Operators)
	BOOST_AUTO_TEST_CASE(Assignment)
	{
		gur::Accent accent_one(gur::H3);
		gur::Accent accent_two(gur::H4);

		accent_two = accent_one;

		BOOST_REQUIRE_EQUAL(accent_one.str().c_str(), gur::H3);
		BOOST_REQUIRE_EQUAL(accent_two.str(), accent_one.str());
	}

	BOOST_AUTO_TEST_CASE(AssignmentMove)
	{
		gur::Accent accent_one(gur::H3);
		gur::Accent accent_two(gur::H4);

		const std::string expected = accent_two.str();
		accent_two = std::move(accent_one);

		BOOST_REQUIRE_EQUAL(accent_one.str(), expected);
		BOOST_REQUIRE_EQUAL(accent_two.str().c_str(), gur::H3);
	}

	BOOST_AUTO_TEST_CASE(Ostream)
	{
		boost::test_tools::output_test_stream out;
		gur::Accent accent(gur::H3);

		out << accent;

		BOOST_REQUIRE(out.is_equal(gur::H3));
		BOOST_REQUIRE_EQUAL(accent.str().c_str(), gur::H3);
	}

	BOOST_AUTO_TEST_CASE(Istream)
	{
		std::istringstream iss(gur::H3);
		gur::Accent accent(gur::H4);

		iss >> accent;

		BOOST_REQUIRE_EQUAL(accent.str().c_str(), gur::H3);
	}

	BOOST_AUTO_TEST_CASE(EqualTo)
	{
		gur::Accent accent_one(gur::H1);
		gur::Accent accent_two(gur::H1);
		gur::Accent accent_three(gur::H2);

		BOOST_REQUIRE_EQUAL(accent_one == accent_two, true);
		BOOST_REQUIRE_EQUAL(accent_one == accent_three, false);
	}

	BOOST_AUTO_TEST_CASE(NotEqualTo)
	{
		gur::Accent accent_one(gur::H1);
		gur::Accent accent_two(gur::H2);
		gur::Accent accent_three(gur::H1);

		BOOST_REQUIRE_EQUAL(accent_one != accent_two, true);
		BOOST_REQUIRE_EQUAL(accent_one != accent_three, false);
	}

	BOOST_AUTO_TEST_CASE(LessThan)
	{
		gur::Accent accent_1(gur::H3);
		gur::Accent accent_2(gur::H4);
		gur::Accent accent_3(gur::H5);
		gur::Accent accent_4(gur::I1);
		gur::Accent accent_5(gur::I2);
		gur::Accent accent_6(gur::I3);
		gur::Accent accent_7(gur::I4);
		gur::Accent accent_8(gur::I5);
		gur::Accent accent_9(gur::J1);
		gur::Accent accent_10(gur::J3);
		gur::Accent accent_11(gur::J4);
		gur::Accent accent_12(gur::H1);
		gur::Accent accent_13(gur::J2);
		gur::Accent accent_14(gur::P5);
		gur::Accent accent_15(gur::O5);
		gur::Accent accent_16(gur::O1);
		gur::Accent accent_17(gur::H2);

		BOOST_CHECK_EQUAL(accent_1 < accent_2, true);
		BOOST_CHECK_EQUAL(accent_2 < accent_3, true);
		BOOST_CHECK_EQUAL(accent_3 < accent_4, true);
		BOOST_CHECK_EQUAL(accent_4 < accent_5, true);
		BOOST_CHECK_EQUAL(accent_5 < accent_6, true);
		BOOST_CHECK_EQUAL(accent_6 < accent_7, true);
		BOOST_CHECK_EQUAL(accent_7 < accent_8, true);
		BOOST_CHECK_EQUAL(accent_8 < accent_9, true);
		BOOST_CHECK_EQUAL(accent_9 < accent_10, true);
		BOOST_CHECK_EQUAL(accent_10 < accent_11, true);
		BOOST_CHECK_EQUAL(accent_11 < accent_12, true);
		BOOST_CHECK_EQUAL(accent_12 < accent_13, true);
		BOOST_CHECK_EQUAL(accent_13 < accent_14, true);
		BOOST_CHECK_EQUAL(accent_14 < accent_15, true);
		BOOST_CHECK_EQUAL(accent_15 < accent_16, true);
		BOOST_CHECK_EQUAL(accent_16 < accent_17, true);
	}

	BOOST_AUTO_TEST_CASE(GreaterThan)
	{
		gur::Accent accent_1(gur::H3);
		gur::Accent accent_2(gur::H4);
		gur::Accent accent_3(gur::H5);
		gur::Accent accent_4(gur::I1);
		gur::Accent accent_5(gur::I2);
		gur::Accent accent_6(gur::I3);
		gur::Accent accent_7(gur::I4);
		gur::Accent accent_8(gur::I5);
		gur::Accent accent_9(gur::J1);
		gur::Accent accent_10(gur::J3);
		gur::Accent accent_11(gur::J4);
		gur::Accent accent_12(gur::H1);
		gur::Accent accent_13(gur::J2);
		gur::Accent accent_14(gur::P5);
		gur::Accent accent_15(gur::O5);
		gur::Accent accent_16(gur::O1);
		gur::Accent accent_17(gur::H2);

		BOOST_CHECK_EQUAL(accent_2 > accent_1, true);
		BOOST_CHECK_EQUAL(accent_3 > accent_2, true);
		BOOST_CHECK_EQUAL(accent_4 > accent_3, true);
		BOOST_CHECK_EQUAL(accent_5 > accent_4, true);
		BOOST_CHECK_EQUAL(accent_6 > accent_5, true);
		BOOST_CHECK_EQUAL(accent_7 > accent_6, true);
		BOOST_CHECK_EQUAL(accent_8 > accent_7, true);
		BOOST_CHECK_EQUAL(accent_9 > accent_8, true);
		BOOST_CHECK_EQUAL(accent_10 > accent_9, true);
		BOOST_CHECK_EQUAL(accent_11 > accent_10, true);
		BOOST_CHECK_EQUAL(accent_12 > accent_11, true);
		BOOST_CHECK_EQUAL(accent_13 > accent_12, true);
		BOOST_CHECK_EQUAL(accent_14 > accent_13, true);
		BOOST_CHECK_EQUAL(accent_15 > accent_14, true);
		BOOST_CHECK_EQUAL(accent_16 > accent_15, true);
		BOOST_CHECK_EQUAL(accent_17 > accent_16, true);
	}

	BOOST_AUTO_TEST_CASE(LessThanOrEqualTo)
	{
		gur::Accent accent_1(gur::H3);
		gur::Accent accent_2(gur::H4);
		gur::Accent accent_3(gur::H5);
		gur::Accent accent_4(gur::I1);
		gur::Accent accent_5(gur::I2);
		gur::Accent accent_6(gur::I3);
		gur::Accent accent_7(gur::I4);
		gur::Accent accent_8(gur::I5);
		gur::Accent accent_9(gur::J1);
		gur::Accent accent_10(gur::J3);
		gur::Accent accent_11(gur::J4);
		gur::Accent accent_12(gur::H1);
		gur::Accent accent_13(gur::J2);
		gur::Accent accent_14(gur::P5);
		gur::Accent accent_15(gur::O5);
		gur::Accent accent_16(gur::O1);
		gur::Accent accent_17(gur::H2);

		BOOST_CHECK_EQUAL(accent_1 <= accent_2, true);
		BOOST_CHECK_EQUAL(accent_2 <= accent_3, true);
		BOOST_CHECK_EQUAL(accent_3 <= accent_4, true);
		BOOST_CHECK_EQUAL(accent_4 <= accent_5, true);
		BOOST_CHECK_EQUAL(accent_5 <= accent_6, true);
		BOOST_CHECK_EQUAL(accent_6 <= accent_7, true);
		BOOST_CHECK_EQUAL(accent_7 <= accent_8, true);
		BOOST_CHECK_EQUAL(accent_8 <= accent_9, true);
		BOOST_CHECK_EQUAL(accent_9 <= accent_10, true);
		BOOST_CHECK_EQUAL(accent_10 <= accent_11, true);
		BOOST_CHECK_EQUAL(accent_11 <= accent_12, true);
		BOOST_CHECK_EQUAL(accent_12 <= accent_13, true);
		BOOST_CHECK_EQUAL(accent_13 <= accent_14, true);
		BOOST_CHECK_EQUAL(accent_14 <= accent_15, true);
		BOOST_CHECK_EQUAL(accent_15 <= accent_16, true);
		BOOST_CHECK_EQUAL(accent_16 <= accent_17, true);
	}

	BOOST_AUTO_TEST_CASE(GreaterThanOrEqualTo)
	{
		gur::Accent accent_1(gur::H3);
		gur::Accent accent_2(gur::H4);
		gur::Accent accent_3(gur::H5);
		gur::Accent accent_4(gur::I1);
		gur::Accent accent_5(gur::I2);
		gur::Accent accent_6(gur::I3);
		gur::Accent accent_7(gur::I4);
		gur::Accent accent_8(gur::I5);
		gur::Accent accent_9(gur::J1);
		gur::Accent accent_10(gur::J3);
		gur::Accent accent_11(gur::J4);
		gur::Accent accent_12(gur::H1);
		gur::Accent accent_13(gur::J2);
		gur::Accent accent_14(gur::P5);
		gur::Accent accent_15(gur::O5);
		gur::Accent accent_16(gur::O1);
		gur::Accent accent_17(gur::H2);

		BOOST_CHECK_EQUAL(accent_2 >= accent_1, true);
		BOOST_CHECK_EQUAL(accent_3 >= accent_2, true);
		BOOST_CHECK_EQUAL(accent_4 >= accent_3, true);
		BOOST_CHECK_EQUAL(accent_5 >= accent_4, true);
		BOOST_CHECK_EQUAL(accent_6 >= accent_5, true);
		BOOST_CHECK_EQUAL(accent_7 >= accent_6, true);
		BOOST_CHECK_EQUAL(accent_8 >= accent_7, true);
		BOOST_CHECK_EQUAL(accent_9 >= accent_8, true);
		BOOST_CHECK_EQUAL(accent_10 >= accent_9, true);
		BOOST_CHECK_EQUAL(accent_11 >= accent_10, true);
		BOOST_CHECK_EQUAL(accent_12 >= accent_11, true);
		BOOST_CHECK_EQUAL(accent_13 >= accent_12, true);
		BOOST_CHECK_EQUAL(accent_14 >= accent_13, true);
		BOOST_CHECK_EQUAL(accent_15 >= accent_14, true);
		BOOST_CHECK_EQUAL(accent_16 >= accent_15, true);
		BOOST_CHECK_EQUAL(accent_17 >= accent_16, true);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Functionality)
	BOOST_AUTO_TEST_CASE(Hash)
	{
		const std::array<gur::Accent, 10> letters
		{
			gur::Accent(gur::A1), gur::Accent(gur::A1),
			gur::Accent(gur::A2), gur::Accent(gur::A2),
			gur::Accent(gur::A3), gur::Accent(gur::A3),
			gur::Accent(gur::A4), gur::Accent(gur::A4),
			gur::Accent(gur::A5), gur::Accent(gur::A5)
		};

		std::set<gur::Accent> set(letters.begin(), letters.end());

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
