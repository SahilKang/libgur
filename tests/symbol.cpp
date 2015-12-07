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

BOOST_AUTO_TEST_SUITE(Symbol)

BOOST_AUTO_TEST_SUITE(Constructors)
	BOOST_AUTO_TEST_CASE(Default)
	{
		gur::Symbol sym;

		BOOST_REQUIRE_EQUAL(sym.str(), "");
	}

	BOOST_AUTO_TEST_CASE(String)
	{
		std::string str(gur::J5);

		gur::Symbol sym(str);

		BOOST_REQUIRE_EQUAL(str.c_str(), gur::J5);
		BOOST_REQUIRE_EQUAL(sym.str(), str);
	}

	BOOST_AUTO_TEST_CASE(MoveString)
	{
		std::string str(gur::J5);

		gur::Symbol sym(std::move(str));

		BOOST_REQUIRE_EQUAL(str, "");
		BOOST_REQUIRE_EQUAL(sym.str().c_str(), gur::J5);
	}

	BOOST_AUTO_TEST_CASE(CharPointer)
	{
		const char* const c = gur::J5;

		gur::Symbol sym(c);

		BOOST_REQUIRE_EQUAL(c, gur::J5);
		BOOST_REQUIRE_EQUAL(sym.str().c_str(), c);
	}

	BOOST_AUTO_TEST_CASE(Copy)
	{
		gur::Symbol sym_one(gur::J5);
		gur::Symbol sym_two(sym_one);

		BOOST_REQUIRE_EQUAL(sym_one.str().c_str(), gur::J5);
		BOOST_REQUIRE_EQUAL(sym_two.str(), sym_one.str());
	}

	BOOST_AUTO_TEST_CASE(Move)
	{
		gur::Symbol sym_one(gur::J5);
		gur::Symbol sym_two(std::move(sym_one));

		BOOST_REQUIRE_EQUAL(sym_one.str(), "");
		BOOST_REQUIRE_EQUAL(sym_two.str().c_str(), gur::J5);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(PublicMembers)
	BOOST_AUTO_TEST_CASE(Str)
	{
		gur::Symbol sym(gur::J5);

		BOOST_REQUIRE_EQUAL(sym.str().c_str(), gur::J5);
	}

	BOOST_AUTO_TEST_CASE(IsValid)
	{
		BOOST_CHECK_EQUAL(gur::Symbol::is_valid(gur::J5), true);
		BOOST_CHECK_EQUAL(gur::Symbol::is_valid(gur::M1), true);

		BOOST_CHECK_EQUAL(gur::Symbol::is_valid(gur::A1), false);
		BOOST_CHECK_EQUAL(gur::Symbol::is_valid(gur::A2), false);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Operators)
	BOOST_AUTO_TEST_CASE(Assignment)
	{
		gur::Symbol sym_one(gur::J5);
		gur::Symbol sym_two(gur::M1);

		sym_two = sym_one;

		BOOST_REQUIRE_EQUAL(sym_one.str().c_str(), gur::J5);
		BOOST_REQUIRE_EQUAL(sym_two.str(), sym_one.str());
	}

	BOOST_AUTO_TEST_CASE(AssignmentMove)
	{
		gur::Symbol sym_one(gur::J5);
		gur::Symbol sym_two(gur::M1);

		const std::string expected = sym_two.str();
		sym_two = std::move(sym_one);

		BOOST_REQUIRE_EQUAL(sym_one.str(), expected);
		BOOST_REQUIRE_EQUAL(sym_two.str().c_str(), gur::J5);
	}

	BOOST_AUTO_TEST_CASE(Ostream)
	{
		boost::test_tools::output_test_stream out;
		gur::Symbol sym(gur::J5);

		out << sym;

		BOOST_REQUIRE(out.is_equal(gur::J5));
		BOOST_REQUIRE_EQUAL(sym.str().c_str(), gur::J5);
	}

	BOOST_AUTO_TEST_CASE(Istream)
	{
		std::istringstream iss(gur::J5);
		gur::Symbol sym(gur::M1);

		iss >> sym;

		BOOST_REQUIRE_EQUAL(sym.str().c_str(), gur::J5);
	}

	BOOST_AUTO_TEST_CASE(EqualTo)
	{
		gur::Symbol sym_one(gur::J5);
		gur::Symbol sym_two(gur::J5);
		gur::Symbol sym_three(gur::M1);

		BOOST_REQUIRE_EQUAL(sym_one == sym_two, true);
		BOOST_REQUIRE_EQUAL(sym_one == sym_three, false);
	}

	BOOST_AUTO_TEST_CASE(NotEqualTo)
	{
		gur::Symbol sym_one(gur::J5);
		gur::Symbol sym_two(gur::M1);
		gur::Symbol sym_three(gur::J5);

		BOOST_REQUIRE_EQUAL(sym_one != sym_two, true);
		BOOST_REQUIRE_EQUAL(sym_one != sym_three, false);
	}

	BOOST_AUTO_TEST_CASE(LessThan)
	{
		gur::Symbol sym_1(gur::J5);
		gur::Symbol sym_2(gur::M1);

		BOOST_CHECK_EQUAL(sym_1 < sym_2, true);
	}

	BOOST_AUTO_TEST_CASE(GreaterThan)
	{
		gur::Symbol sym_1(gur::J5);
		gur::Symbol sym_2(gur::M1);

		BOOST_CHECK_EQUAL(sym_2 > sym_1, true);
	}

	BOOST_AUTO_TEST_CASE(LessThanOrEqualTo)
	{
		gur::Symbol sym_1(gur::J5);
		gur::Symbol sym_2(gur::M1);

		BOOST_CHECK_EQUAL(sym_1 <= sym_2, true);
	}

	BOOST_AUTO_TEST_CASE(GreaterThanOrEqualTo)
	{
		gur::Symbol sym_1(gur::J5);
		gur::Symbol sym_2(gur::M1);

		BOOST_CHECK_EQUAL(sym_2 >= sym_1, true);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Functionatlity)
	BOOST_AUTO_TEST_CASE(Hash)
	{
		const std::array<gur::Symbol, 10> letters
		{
			gur::Symbol(gur::A1), gur::Symbol(gur::A1),
			gur::Symbol(gur::A2), gur::Symbol(gur::A2),
			gur::Symbol(gur::A3), gur::Symbol(gur::A3),
			gur::Symbol(gur::A4), gur::Symbol(gur::A4),
			gur::Symbol(gur::A5), gur::Symbol(gur::A5)
		};

		std::set<gur::Symbol> set(letters.begin(), letters.end());

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
