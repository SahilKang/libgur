/******************************************************************************
 * Copyright (C) 2015, 2016 Sahil Singh Kang <sahil.kang@asilaycomputing.com>
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
#include <array>

template<std::size_t len>
constexpr std::string cat_arr(
	const std::array<const std::string, len> &arr,
	const std::size_t &iter=0)
{
	return (iter == len) ? "" : arr[iter] + cat_arr(arr, iter+1);
}

BOOST_AUTO_TEST_SUITE(String)

BOOST_AUTO_TEST_SUITE(Constructors)
	BOOST_AUTO_TEST_CASE(Default)
	{
		gur::String str;

		BOOST_REQUIRE_EQUAL(str.size(), 0);
	}

	BOOST_AUTO_TEST_CASE(Copy)
	{
		std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
			+ gur::G3);

		gur::String lhs(sahil);
		gur::String rhs(lhs);

		BOOST_REQUIRE_EQUAL(lhs.str(), sahil);
		BOOST_REQUIRE_EQUAL(lhs.str(), rhs.str());
	}

	BOOST_AUTO_TEST_CASE(Move)
	{
		std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
			+ gur::G3);

		gur::String lhs(sahil);
		gur::String rhs(std::move(lhs));

		BOOST_REQUIRE_EQUAL(sahil, rhs.str());
	}

	BOOST_AUTO_TEST_CASE(StdString)
	{
		std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
			+ gur::G3);

		gur::String str(sahil);

		BOOST_REQUIRE_EQUAL(str.str(), sahil);
	}

	BOOST_AUTO_TEST_CASE(CharPointer)
	{
		std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
			+ gur::G3);

		const char* const sahil_p = sahil.c_str();

		gur::String str(sahil_p);

		BOOST_REQUIRE_EQUAL(str.str(), sahil);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(MemberFuncs)
	BOOST_AUTO_TEST_CASE(Size)
	{
		gur::String str;

		BOOST_CHECK_EQUAL(str.size(), 0);

		std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
			+ gur::G3);

		str += sahil;

		BOOST_REQUIRE_EQUAL(str.size(), 5);
	}

	BOOST_AUTO_TEST_CASE(Str)
	{
		gur::String str;

		BOOST_CHECK_EQUAL(str.str(), "");

		std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
			+ gur::G3);

		str += sahil;

		BOOST_REQUIRE_EQUAL(str.str(), sahil);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Iterators)
	BOOST_AUTO_TEST_SUITE(RangeBasedForLoop)
		BOOST_AUTO_TEST_CASE(Const)
		{
			const std::array<const std::string, 5> arr
			{
				gur::A4, gur::H3, gur::A5, gur::H4, gur::G3
			};

			std::string sahil(cat_arr(arr));
			const gur::String str(sahil);

			unsigned int count(0);
			for (auto &&c : str)
			{
				BOOST_CHECK_EQUAL(c, arr.at(count));

				++count;
			}
		}

		BOOST_AUTO_TEST_CASE(NonConst)
		{
			const std::array<const std::string, 5> arr
			{
				gur::A4, gur::H3, gur::A5, gur::H4, gur::G3
			};

			std::string sahil(cat_arr(arr));
			gur::String str(sahil);

			unsigned int count(0);
			for (auto &&c : str)
			{
				BOOST_CHECK_EQUAL(c, arr.at(count));

				++count;
			}
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Operators)
	BOOST_AUTO_TEST_SUITE(OffsetDereference)
		BOOST_AUTO_TEST_CASE(Const)
		{
			const std::array<const std::string, 5> arr
			{
				gur::A4, gur::H3, gur::A5, gur::H4, gur::G3
			};

			std::string sahil(cat_arr(arr));
			const gur::String str(sahil);

			for (std::size_t i = 0; i < str.size(); ++i)
			{
				BOOST_CHECK_EQUAL(str[i], arr.at(i));
			}
		}

		BOOST_AUTO_TEST_CASE(NonConst)
		{
			const std::array<const std::string, 5> arr
			{
				gur::A4, gur::H3, gur::A5, gur::H4, gur::G3
			};

			std::string sahil(cat_arr(arr));
			gur::String str(sahil);

			for (std::size_t i = 0; i < str.size(); ++i)
			{
				BOOST_CHECK_EQUAL(str[i], arr.at(i));
			}
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(PlusEquals)
		BOOST_AUTO_TEST_CASE(String)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str_one(sahil);
			gur::String str_two(kang);

			str_one += str_two;

			BOOST_CHECK_EQUAL(str_one.str(), sahil + kang);
			BOOST_CHECK_EQUAL(str_two.str(), kang);
		}

		BOOST_AUTO_TEST_CASE(StdString)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str(sahil);
			str += kang;

			BOOST_CHECK_EQUAL(str.str(), sahil + kang);
		}

		BOOST_AUTO_TEST_CASE(CharPointer)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str(sahil.c_str());
			str += kang.c_str();

			BOOST_CHECK_EQUAL(str.str(), sahil + kang);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(Plus)
		BOOST_AUTO_TEST_CASE(String)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str_one(sahil);
			gur::String str_two(kang);
			gur::String str_three;

			str_three = str_one + str_two;

			BOOST_CHECK_EQUAL(str_one.str(), sahil);
			BOOST_CHECK_EQUAL(str_two.str(), kang);
			BOOST_CHECK_EQUAL(str_three.str(), sahil + kang);
		}

		BOOST_AUTO_TEST_CASE(StdString)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str_one(kang);
			gur::String str_two;

			str_two = sahil + str_one;

			BOOST_CHECK_EQUAL(str_one.str(), kang);
			BOOST_CHECK_EQUAL(str_two.str(), sahil + kang);
		}

		BOOST_AUTO_TEST_CASE(CharPointer)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str_one(kang.c_str());
			gur::String str_two;

			str_two = sahil.c_str() + str_one;

			BOOST_CHECK_EQUAL(str_one.str(), kang);
			BOOST_CHECK_EQUAL(str_two.str(), sahil + kang);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(Assignment)
		BOOST_AUTO_TEST_CASE(Copy)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str_one(sahil);
			gur::String str_two(kang);

			str_one = str_two;

			BOOST_CHECK_EQUAL(str_one.str(), str_two.str());
			BOOST_CHECK_EQUAL(str_two.str(), kang);
		}

		BOOST_AUTO_TEST_CASE(Move)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str_one(sahil);
			gur::String str_two(kang);

			str_one = std::move(str_two);

			BOOST_CHECK_EQUAL(str_one.str(), kang);
		}

		BOOST_AUTO_TEST_CASE(StdString)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str(sahil);

			str = kang;

			BOOST_CHECK_EQUAL(str.str(), kang);
		}

		BOOST_AUTO_TEST_CASE(CharPointer)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str(sahil);

			str = kang.c_str();

			BOOST_CHECK_EQUAL(str.str(), kang);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(Stream)
		BOOST_AUTO_TEST_CASE(IStream)
		{
			std::string clobbered(gur::M5 + gur::A4 + gur::E3
				+ gur::H5 + gur::M2 + gur::H1);

			std::istringstream iss(clobbered);
			gur::String str(gur::A1);

			iss >> str;

			BOOST_CHECK_EQUAL(
				str.str(),
				gur::unclobber(clobbered));
		}

		BOOST_AUTO_TEST_CASE(OStream)
		{
			std::string unclobbered(gur::A1 + gur::I1 + gur::A4
				+ gur::E3 + gur::H5 + gur::A2 + gur::H3
				+ gur::H1);

			gur::String str(unclobbered);

			boost::test_tools::output_test_stream out;
			out << str;

			BOOST_CHECK(out.is_equal(gur::clobber(unclobbered)));
			BOOST_CHECK_EQUAL(str.str(), unclobbered);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(Relational)
		BOOST_AUTO_TEST_CASE(Equals)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str_one(sahil);
			gur::String str_two(kang);
			gur::String str_three(sahil);

			BOOST_CHECK_EQUAL(str_one == str_two, false);
			BOOST_CHECK_EQUAL(str_one == str_three, true);
			BOOST_CHECK_EQUAL(str_two == str_three, false);
		}

		BOOST_AUTO_TEST_CASE(NotEquals)
		{
			std::string sahil(gur::A4 + gur::H3 + gur::A5 + gur::H4
				+ gur::G3);

			std::string kang(gur::B1 + gur::J3 + gur::B3);

			gur::String str_one(sahil);
			gur::String str_two(kang);
			gur::String str_three(sahil);

			BOOST_CHECK_EQUAL(str_one != str_two, true);
			BOOST_CHECK_EQUAL(str_one != str_three, false);
			BOOST_CHECK_EQUAL(str_two != str_three, true);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
