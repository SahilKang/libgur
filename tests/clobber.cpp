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
#include <boost/test/unit_test.hpp>

#include <gur.hpp>
#include <gurmukhi.hpp>

BOOST_AUTO_TEST_SUITE(Clobbers)
	BOOST_AUTO_TEST_SUITE(Clobber)
		BOOST_AUTO_TEST_CASE(String)
		{
			const std::string clobbered(gur::M5 + gur::A4 + gur::E3
				+ gur::H5 + gur::M2 + gur::H1);
			const std::string unclobbered(gur::A1 + gur::I1
				+ gur::A4 + gur::E3 + gur::H5 + gur::A2
				+ gur::H3 + gur::H1);

			gur::String str(unclobbered);
			str = gur::clobber(str);

			BOOST_CHECK_EQUAL(str.str(), clobbered);
		}

		BOOST_AUTO_TEST_CASE(StdString)
		{
			const std::string clobbered(gur::M5 + gur::A4 + gur::E3
				+ gur::H5 + gur::M2 + gur::H1);
			const std::string unclobbered(gur::A1 + gur::I1
				+ gur::A4 + gur::E3 + gur::H5 + gur::A2
				+ gur::H3 + gur::H1);

			std::string str(unclobbered);
			str = gur::clobber(str);

			BOOST_CHECK_EQUAL(str, clobbered);
		}

		BOOST_AUTO_TEST_CASE(CharPointer)
		{
			const std::string clobbered(gur::M5 + gur::A4 + gur::E3
				+ gur::H5 + gur::M2 + gur::H1);
			const std::string unclobbered(gur::A1 + gur::I1
				+ gur::A4 + gur::E3 + gur::H5 + gur::A2
				+ gur::H3 + gur::H1);

			const char* str = unclobbered.c_str();
			str = gur::clobber(str);

			BOOST_CHECK_EQUAL(std::string(str), clobbered);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(Unclobber)
		BOOST_AUTO_TEST_CASE(String)
		{
			const std::string clobbered(gur::M5 + gur::A4 + gur::E3
				+ gur::H5 + gur::M2 + gur::H1);
			const std::string unclobbered(gur::A1 + gur::I1
				+ gur::A4 + gur::E3 + gur::H5 + gur::A2
				+ gur::H3 + gur::H1);

			gur::String str(clobbered);
			str = gur::unclobber(str);

			BOOST_CHECK_EQUAL(str.str(), unclobbered);
		}

		BOOST_AUTO_TEST_CASE(StdString)
		{
			const std::string clobbered(gur::M5 + gur::A4 + gur::E3
				+ gur::H5 + gur::M2 + gur::H1);
			const std::string unclobbered(gur::A1 + gur::I1
				+ gur::A4 + gur::E3 + gur::H5 + gur::A2
				+ gur::H3 + gur::H1);

			std::string str(clobbered);
			str = gur::unclobber(str);

			BOOST_CHECK_EQUAL(str, unclobbered);
		}

		BOOST_AUTO_TEST_CASE(CharPointer)
		{
			const std::string clobbered(gur::M5 + gur::A4 + gur::E3
				+ gur::H5 + gur::M2 + gur::H1);
			const std::string unclobbered(gur::A1 + gur::I1
				+ gur::A4 + gur::E3 + gur::H5 + gur::A2
				+ gur::H3 + gur::H1);

			const char* str = clobbered.c_str();
			str = gur::unclobber(str);

			BOOST_CHECK_EQUAL(std::string(str), unclobbered);
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()
