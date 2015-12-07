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
#define BOOST_TEST_MODULE libgur
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include <gur.hpp>
#include <gurmukhi.hpp>
#include <sstream>
#include <set>

BOOST_AUTO_TEST_SUITE(Letter)

BOOST_AUTO_TEST_SUITE(Constructors)
	BOOST_AUTO_TEST_CASE(Default)
	{
		gur::Letter letter;

		BOOST_REQUIRE_EQUAL(letter.str(), "");

	}

	BOOST_AUTO_TEST_CASE(String)
	{
		std::string str("Hello");

		gur::Letter letter(str);

		BOOST_REQUIRE_EQUAL(str, "Hello");
		BOOST_REQUIRE_EQUAL(letter.str(), str);
	}

	BOOST_AUTO_TEST_CASE(MoveString)
	{
		std::string str("Hello");

		gur::Letter letter(std::move(str));

		BOOST_REQUIRE_EQUAL(str, "");
		BOOST_REQUIRE_EQUAL(letter.str(), "Hello");
	}

	BOOST_AUTO_TEST_CASE(CharPointer)
	{
		const char* const c = gur::A1;

		gur::Letter letter(c);

		BOOST_REQUIRE_EQUAL(c, gur::A1);
		BOOST_REQUIRE_EQUAL(letter.str().c_str(), c);
	}

	BOOST_AUTO_TEST_CASE(Copy)
	{
		gur::Letter letter_one("Hello");
		gur::Letter letter_two(letter_one);

		BOOST_REQUIRE_EQUAL(letter_one.str(), "Hello");
		BOOST_REQUIRE_EQUAL(letter_two.str(), letter_one.str());
	}

	BOOST_AUTO_TEST_CASE(Move)
	{
		gur::Letter letter_one("Hello");
		gur::Letter letter_two(std::move(letter_one));

		BOOST_REQUIRE_EQUAL(letter_one.str(), "");
		BOOST_REQUIRE_EQUAL(letter_two.str(), "Hello");
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(PublicMembers)
	BOOST_AUTO_TEST_CASE(Str)
	{
		gur::Letter letter("Hello");

		BOOST_REQUIRE_EQUAL(letter.str(), "Hello");
	}

	BOOST_AUTO_TEST_CASE(IsValidChar)
	{
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::A1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::A2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::A3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::A4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::A5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::B1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::B2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::B3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::B4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::B5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::C1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::C2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::C3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::C4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::C5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::D1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::D2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::D3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::D4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::D5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::E1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::E2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::E3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::E4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::E5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::F1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::F2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::F3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::F4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::F5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::G1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::G2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::G3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::G4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(gur::G5), true);

		BOOST_REQUIRE_EQUAL(gur::Letter::is_valid(gur::L1), false);
		BOOST_REQUIRE_EQUAL(gur::Letter::is_valid(gur::L2), false);
	}

	BOOST_AUTO_TEST_CASE(IsValidString)
	{
		std::string A1(gur::A1);
		std::string A2(gur::A2);
		std::string A3(gur::A3);
		std::string A4(gur::A4);
		std::string A5(gur::A5);
		std::string B1(gur::B1);
		std::string B2(gur::B2);
		std::string B3(gur::B3);
		std::string B4(gur::B4);
		std::string B5(gur::B5);
		std::string C1(gur::C1);
		std::string C2(gur::C2);
		std::string C3(gur::C3);
		std::string C4(gur::C4);
		std::string C5(gur::C5);
		std::string D1(gur::D1);
		std::string D2(gur::D2);
		std::string D3(gur::D3);
		std::string D4(gur::D4);
		std::string D5(gur::D5);
		std::string E1(gur::E1);
		std::string E2(gur::E2);
		std::string E3(gur::E3);
		std::string E4(gur::E4);
		std::string E5(gur::E5);
		std::string F1(gur::F1);
		std::string F2(gur::F2);
		std::string F3(gur::F3);
		std::string F4(gur::F4);
		std::string F5(gur::F5);
		std::string G1(gur::G1);
		std::string G2(gur::G2);
		std::string G3(gur::G3);
		std::string G4(gur::G4);
		std::string G5(gur::G5);

		std::string L1(gur::L1);
		std::string L2(gur::L2);

		BOOST_CHECK_EQUAL(gur::Letter::is_valid(A1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(A2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(A3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(A4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(A5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(B1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(B2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(B3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(B4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(B5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(C1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(C2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(C3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(C4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(C5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(D1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(D2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(D3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(D4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(D5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(E1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(E2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(E3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(E4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(E5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(F1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(F2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(F3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(F4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(F5), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(G1), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(G2), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(G3), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(G4), true);
		BOOST_CHECK_EQUAL(gur::Letter::is_valid(G5), true);

		BOOST_REQUIRE_EQUAL(gur::Letter::is_valid(L1), false);
		BOOST_REQUIRE_EQUAL(gur::Letter::is_valid(L2), false);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Operators)
	BOOST_AUTO_TEST_CASE(Assignment)
	{
		gur::Letter letter_one("Hello");
		gur::Letter letter_two("World");

		letter_two = letter_one;

		BOOST_REQUIRE_EQUAL(letter_one.str(), "Hello");
		BOOST_REQUIRE_EQUAL(letter_two.str(), letter_one.str());
	}

	BOOST_AUTO_TEST_CASE(AssignmentMove)
	{
		gur::Letter letter_one("Hello");
		gur::Letter letter_two("World");

		const std::string expected = letter_two.str();
		letter_two = std::move(letter_one);

		BOOST_REQUIRE_EQUAL(letter_one.str(), expected);
		BOOST_REQUIRE_EQUAL(letter_two.str(), "Hello");
	}

	BOOST_AUTO_TEST_CASE(Ostream)
	{
		boost::test_tools::output_test_stream out;
		gur::Letter letter(gur::M2);

		out << letter;

		BOOST_REQUIRE(out.is_equal(gur::M2));
		BOOST_REQUIRE_EQUAL(letter.str().c_str(), gur::M2);
	}

	BOOST_AUTO_TEST_CASE(Istream)
	{
		std::istringstream iss(gur::M2);
		gur::Letter letter(gur::M3);

		iss >> letter;

		BOOST_REQUIRE_EQUAL(letter.str().c_str(), gur::M2);
	}

	BOOST_AUTO_TEST_CASE(EqualTo)
	{
		gur::Letter letter_one(gur::A1);
		gur::Letter letter_two(gur::A1);
		gur::Letter letter_three(gur::A2);

		BOOST_REQUIRE_EQUAL(letter_one == letter_two, true);
		BOOST_REQUIRE_EQUAL(letter_one == letter_three, false);
	}

	BOOST_AUTO_TEST_CASE(NotEqualTo)
	{
		gur::Letter letter_one(gur::A1);
		gur::Letter letter_two(gur::A2);
		gur::Letter letter_three(gur::A1);

		BOOST_REQUIRE_EQUAL(letter_one != letter_two, true);
		BOOST_REQUIRE_EQUAL(letter_one != letter_three, false);
	}

	BOOST_AUTO_TEST_CASE(LessThan)
	{
		gur::Letter letter_A1(gur::A1);
		gur::Letter letter_A2(gur::A2);
		gur::Letter letter_A3(gur::A3);
		gur::Letter letter_A4(gur::A4);
		gur::Letter letter_A5(gur::A5);
		gur::Letter letter_B1(gur::B1);
		gur::Letter letter_B2(gur::B2);
		gur::Letter letter_B3(gur::B3);
		gur::Letter letter_B4(gur::B4);
		gur::Letter letter_B5(gur::B5);
		gur::Letter letter_C1(gur::C1);
		gur::Letter letter_C2(gur::C2);
		gur::Letter letter_C3(gur::C3);
		gur::Letter letter_C4(gur::C4);
		gur::Letter letter_C5(gur::C5);
		gur::Letter letter_D1(gur::D1);
		gur::Letter letter_D2(gur::D2);
		gur::Letter letter_D3(gur::D3);
		gur::Letter letter_D4(gur::D4);
		gur::Letter letter_D5(gur::D5);
		gur::Letter letter_E1(gur::E1);
		gur::Letter letter_E2(gur::E2);
		gur::Letter letter_E3(gur::E3);
		gur::Letter letter_E4(gur::E4);
		gur::Letter letter_E5(gur::E5);
		gur::Letter letter_F1(gur::F1);
		gur::Letter letter_F2(gur::F2);
		gur::Letter letter_F3(gur::F3);
		gur::Letter letter_F4(gur::F4);
		gur::Letter letter_F5(gur::F5);
		gur::Letter letter_G1(gur::G1);
		gur::Letter letter_G2(gur::G2);
		gur::Letter letter_G3(gur::G3);
		gur::Letter letter_G4(gur::G4);
		gur::Letter letter_G5(gur::G5);

		BOOST_CHECK_EQUAL(letter_A1 < letter_A2, true);
		BOOST_CHECK_EQUAL(letter_A2 < letter_A3, true);
		BOOST_CHECK_EQUAL(letter_A3 < letter_A4, true);
		BOOST_CHECK_EQUAL(letter_A4 < letter_A5, true);
		BOOST_CHECK_EQUAL(letter_B1 < letter_B2, true);
		BOOST_CHECK_EQUAL(letter_B2 < letter_B3, true);
		BOOST_CHECK_EQUAL(letter_B3 < letter_B4, true);
		BOOST_CHECK_EQUAL(letter_B4 < letter_B5, true);
		BOOST_CHECK_EQUAL(letter_C1 < letter_C2, true);
		BOOST_CHECK_EQUAL(letter_C2 < letter_C3, true);
		BOOST_CHECK_EQUAL(letter_C3 < letter_C4, true);
		BOOST_CHECK_EQUAL(letter_C4 < letter_C5, true);
		BOOST_CHECK_EQUAL(letter_D1 < letter_D2, true);
		BOOST_CHECK_EQUAL(letter_D2 < letter_D3, true);
		BOOST_CHECK_EQUAL(letter_D3 < letter_D4, true);
		BOOST_CHECK_EQUAL(letter_D4 < letter_D5, true);
		BOOST_CHECK_EQUAL(letter_E1 < letter_E2, true);
		BOOST_CHECK_EQUAL(letter_E2 < letter_E3, true);
		BOOST_CHECK_EQUAL(letter_E3 < letter_E4, true);
		BOOST_CHECK_EQUAL(letter_E4 < letter_E5, true);
		BOOST_CHECK_EQUAL(letter_F1 < letter_F2, true);
		BOOST_CHECK_EQUAL(letter_F2 < letter_F3, true);
		BOOST_CHECK_EQUAL(letter_F3 < letter_F4, true);
		BOOST_CHECK_EQUAL(letter_F4 < letter_F5, true);
		BOOST_CHECK_EQUAL(letter_G1 < letter_G2, true);
		BOOST_CHECK_EQUAL(letter_G2 < letter_G3, true);
		BOOST_CHECK_EQUAL(letter_G3 < letter_G4, true);
		BOOST_CHECK_EQUAL(letter_G4 < letter_G5, true);
	}

	BOOST_AUTO_TEST_CASE(GreaterThan)
	{
		gur::Letter letter_A1(gur::A1);
		gur::Letter letter_A2(gur::A2);
		gur::Letter letter_A3(gur::A3);
		gur::Letter letter_A4(gur::A4);
		gur::Letter letter_A5(gur::A5);
		gur::Letter letter_B1(gur::B1);
		gur::Letter letter_B2(gur::B2);
		gur::Letter letter_B3(gur::B3);
		gur::Letter letter_B4(gur::B4);
		gur::Letter letter_B5(gur::B5);
		gur::Letter letter_C1(gur::C1);
		gur::Letter letter_C2(gur::C2);
		gur::Letter letter_C3(gur::C3);
		gur::Letter letter_C4(gur::C4);
		gur::Letter letter_C5(gur::C5);
		gur::Letter letter_D1(gur::D1);
		gur::Letter letter_D2(gur::D2);
		gur::Letter letter_D3(gur::D3);
		gur::Letter letter_D4(gur::D4);
		gur::Letter letter_D5(gur::D5);
		gur::Letter letter_E1(gur::E1);
		gur::Letter letter_E2(gur::E2);
		gur::Letter letter_E3(gur::E3);
		gur::Letter letter_E4(gur::E4);
		gur::Letter letter_E5(gur::E5);
		gur::Letter letter_F1(gur::F1);
		gur::Letter letter_F2(gur::F2);
		gur::Letter letter_F3(gur::F3);
		gur::Letter letter_F4(gur::F4);
		gur::Letter letter_F5(gur::F5);
		gur::Letter letter_G1(gur::G1);
		gur::Letter letter_G2(gur::G2);
		gur::Letter letter_G3(gur::G3);
		gur::Letter letter_G4(gur::G4);
		gur::Letter letter_G5(gur::G5);

		BOOST_CHECK_EQUAL(letter_A2 > letter_A1, true);
		BOOST_CHECK_EQUAL(letter_A3 > letter_A2, true);
		BOOST_CHECK_EQUAL(letter_A4 > letter_A3, true);
		BOOST_CHECK_EQUAL(letter_A5 > letter_A4, true);
		BOOST_CHECK_EQUAL(letter_B2 > letter_B1, true);
		BOOST_CHECK_EQUAL(letter_B3 > letter_B2, true);
		BOOST_CHECK_EQUAL(letter_B4 > letter_B3, true);
		BOOST_CHECK_EQUAL(letter_B5 > letter_B4, true);
		BOOST_CHECK_EQUAL(letter_C2 > letter_C1, true);
		BOOST_CHECK_EQUAL(letter_C3 > letter_C2, true);
		BOOST_CHECK_EQUAL(letter_C4 > letter_C3, true);
		BOOST_CHECK_EQUAL(letter_C5 > letter_C4, true);
		BOOST_CHECK_EQUAL(letter_D2 > letter_D1, true);
		BOOST_CHECK_EQUAL(letter_D3 > letter_D2, true);
		BOOST_CHECK_EQUAL(letter_D4 > letter_D3, true);
		BOOST_CHECK_EQUAL(letter_D5 > letter_D4, true);
		BOOST_CHECK_EQUAL(letter_E2 > letter_E1, true);
		BOOST_CHECK_EQUAL(letter_E3 > letter_E2, true);
		BOOST_CHECK_EQUAL(letter_E4 > letter_E3, true);
		BOOST_CHECK_EQUAL(letter_E5 > letter_E4, true);
		BOOST_CHECK_EQUAL(letter_F2 > letter_F1, true);
		BOOST_CHECK_EQUAL(letter_F3 > letter_F2, true);
		BOOST_CHECK_EQUAL(letter_F4 > letter_F3, true);
		BOOST_CHECK_EQUAL(letter_F5 > letter_F4, true);
		BOOST_CHECK_EQUAL(letter_G2 > letter_G1, true);
		BOOST_CHECK_EQUAL(letter_G3 > letter_G2, true);
		BOOST_CHECK_EQUAL(letter_G4 > letter_G3, true);
		BOOST_CHECK_EQUAL(letter_G5 > letter_G4, true);
	}

	BOOST_AUTO_TEST_CASE(LessThanOrEqualTo)
	{
		gur::Letter letter_A1(gur::A1);
		gur::Letter letter_A2(gur::A2);
		gur::Letter letter_A3(gur::A3);
		gur::Letter letter_A4(gur::A4);
		gur::Letter letter_A5(gur::A5);
		gur::Letter letter_B1(gur::B1);
		gur::Letter letter_B2(gur::B2);
		gur::Letter letter_B3(gur::B3);
		gur::Letter letter_B4(gur::B4);
		gur::Letter letter_B5(gur::B5);
		gur::Letter letter_C1(gur::C1);
		gur::Letter letter_C2(gur::C2);
		gur::Letter letter_C3(gur::C3);
		gur::Letter letter_C4(gur::C4);
		gur::Letter letter_C5(gur::C5);
		gur::Letter letter_D1(gur::D1);
		gur::Letter letter_D2(gur::D2);
		gur::Letter letter_D3(gur::D3);
		gur::Letter letter_D4(gur::D4);
		gur::Letter letter_D5(gur::D5);
		gur::Letter letter_E1(gur::E1);
		gur::Letter letter_E2(gur::E2);
		gur::Letter letter_E3(gur::E3);
		gur::Letter letter_E4(gur::E4);
		gur::Letter letter_E5(gur::E5);
		gur::Letter letter_F1(gur::F1);
		gur::Letter letter_F2(gur::F2);
		gur::Letter letter_F3(gur::F3);
		gur::Letter letter_F4(gur::F4);
		gur::Letter letter_F5(gur::F5);
		gur::Letter letter_G1(gur::G1);
		gur::Letter letter_G2(gur::G2);
		gur::Letter letter_G3(gur::G3);
		gur::Letter letter_G4(gur::G4);
		gur::Letter letter_G5(gur::G5);

		BOOST_CHECK_EQUAL(letter_A1 <= letter_A2, true);
		BOOST_CHECK_EQUAL(letter_A2 <= letter_A3, true);
		BOOST_CHECK_EQUAL(letter_A3 <= letter_A4, true);
		BOOST_CHECK_EQUAL(letter_A4 <= letter_A5, true);
		BOOST_CHECK_EQUAL(letter_B1 <= letter_B2, true);
		BOOST_CHECK_EQUAL(letter_B2 <= letter_B3, true);
		BOOST_CHECK_EQUAL(letter_B3 <= letter_B4, true);
		BOOST_CHECK_EQUAL(letter_B4 <= letter_B5, true);
		BOOST_CHECK_EQUAL(letter_C1 <= letter_C2, true);
		BOOST_CHECK_EQUAL(letter_C2 <= letter_C3, true);
		BOOST_CHECK_EQUAL(letter_C3 <= letter_C4, true);
		BOOST_CHECK_EQUAL(letter_C4 <= letter_C5, true);
		BOOST_CHECK_EQUAL(letter_D1 <= letter_D2, true);
		BOOST_CHECK_EQUAL(letter_D2 <= letter_D3, true);
		BOOST_CHECK_EQUAL(letter_D3 <= letter_D4, true);
		BOOST_CHECK_EQUAL(letter_D4 <= letter_D5, true);
		BOOST_CHECK_EQUAL(letter_E1 <= letter_E2, true);
		BOOST_CHECK_EQUAL(letter_E2 <= letter_E3, true);
		BOOST_CHECK_EQUAL(letter_E3 <= letter_E4, true);
		BOOST_CHECK_EQUAL(letter_E4 <= letter_E5, true);
		BOOST_CHECK_EQUAL(letter_F1 <= letter_F2, true);
		BOOST_CHECK_EQUAL(letter_F2 <= letter_F3, true);
		BOOST_CHECK_EQUAL(letter_F3 <= letter_F4, true);
		BOOST_CHECK_EQUAL(letter_F4 <= letter_F5, true);
		BOOST_CHECK_EQUAL(letter_G1 <= letter_G2, true);
		BOOST_CHECK_EQUAL(letter_G2 <= letter_G3, true);
		BOOST_CHECK_EQUAL(letter_G3 <= letter_G4, true);
		BOOST_CHECK_EQUAL(letter_G4 <= letter_G5, true);
	}

	BOOST_AUTO_TEST_CASE(GreaterThanOrEqualTo)
	{
		gur::Letter letter_A1(gur::A1);
		gur::Letter letter_A2(gur::A2);
		gur::Letter letter_A3(gur::A3);
		gur::Letter letter_A4(gur::A4);
		gur::Letter letter_A5(gur::A5);
		gur::Letter letter_B1(gur::B1);
		gur::Letter letter_B2(gur::B2);
		gur::Letter letter_B3(gur::B3);
		gur::Letter letter_B4(gur::B4);
		gur::Letter letter_B5(gur::B5);
		gur::Letter letter_C1(gur::C1);
		gur::Letter letter_C2(gur::C2);
		gur::Letter letter_C3(gur::C3);
		gur::Letter letter_C4(gur::C4);
		gur::Letter letter_C5(gur::C5);
		gur::Letter letter_D1(gur::D1);
		gur::Letter letter_D2(gur::D2);
		gur::Letter letter_D3(gur::D3);
		gur::Letter letter_D4(gur::D4);
		gur::Letter letter_D5(gur::D5);
		gur::Letter letter_E1(gur::E1);
		gur::Letter letter_E2(gur::E2);
		gur::Letter letter_E3(gur::E3);
		gur::Letter letter_E4(gur::E4);
		gur::Letter letter_E5(gur::E5);
		gur::Letter letter_F1(gur::F1);
		gur::Letter letter_F2(gur::F2);
		gur::Letter letter_F3(gur::F3);
		gur::Letter letter_F4(gur::F4);
		gur::Letter letter_F5(gur::F5);
		gur::Letter letter_G1(gur::G1);
		gur::Letter letter_G2(gur::G2);
		gur::Letter letter_G3(gur::G3);
		gur::Letter letter_G4(gur::G4);
		gur::Letter letter_G5(gur::G5);

		BOOST_CHECK_EQUAL(letter_A2 >= letter_A1, true);
		BOOST_CHECK_EQUAL(letter_A3 >= letter_A2, true);
		BOOST_CHECK_EQUAL(letter_A4 >= letter_A3, true);
		BOOST_CHECK_EQUAL(letter_A5 >= letter_A4, true);
		BOOST_CHECK_EQUAL(letter_B2 >= letter_B1, true);
		BOOST_CHECK_EQUAL(letter_B3 >= letter_B2, true);
		BOOST_CHECK_EQUAL(letter_B4 >= letter_B3, true);
		BOOST_CHECK_EQUAL(letter_B5 >= letter_B4, true);
		BOOST_CHECK_EQUAL(letter_C2 >= letter_C1, true);
		BOOST_CHECK_EQUAL(letter_C3 >= letter_C2, true);
		BOOST_CHECK_EQUAL(letter_C4 >= letter_C3, true);
		BOOST_CHECK_EQUAL(letter_C5 >= letter_C4, true);
		BOOST_CHECK_EQUAL(letter_D2 >= letter_D1, true);
		BOOST_CHECK_EQUAL(letter_D3 >= letter_D2, true);
		BOOST_CHECK_EQUAL(letter_D4 >= letter_D3, true);
		BOOST_CHECK_EQUAL(letter_D5 >= letter_D4, true);
		BOOST_CHECK_EQUAL(letter_E2 >= letter_E1, true);
		BOOST_CHECK_EQUAL(letter_E3 >= letter_E2, true);
		BOOST_CHECK_EQUAL(letter_E4 >= letter_E3, true);
		BOOST_CHECK_EQUAL(letter_E5 >= letter_E4, true);
		BOOST_CHECK_EQUAL(letter_F2 >= letter_F1, true);
		BOOST_CHECK_EQUAL(letter_F3 >= letter_F2, true);
		BOOST_CHECK_EQUAL(letter_F4 >= letter_F3, true);
		BOOST_CHECK_EQUAL(letter_F5 >= letter_F4, true);
		BOOST_CHECK_EQUAL(letter_G2 >= letter_G1, true);
		BOOST_CHECK_EQUAL(letter_G3 >= letter_G2, true);
		BOOST_CHECK_EQUAL(letter_G4 >= letter_G3, true);
		BOOST_CHECK_EQUAL(letter_G5 >= letter_G4, true);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Functionatlity)
	BOOST_AUTO_TEST_CASE(Hash)
	{
		const std::array<gur::Letter, 10> letters
		{
			gur::Letter(gur::A1), gur::Letter(gur::A1),
			gur::Letter(gur::A2), gur::Letter(gur::A2),
			gur::Letter(gur::A3), gur::Letter(gur::A3),
			gur::Letter(gur::A4), gur::Letter(gur::A4),
			gur::Letter(gur::A5), gur::Letter(gur::A5)
		};

		std::set<gur::Letter> set(letters.begin(), letters.end());

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
