#include "stdafx.h"
#include "CppUnitTest.h"

#include "catch.hpp"
#include "flyweight_pattern.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unit_tests
{		
	TEST_CASE("dry_area_youngs")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(1, 1000);
		int youngs = model->get_youngs(0);
		REQUIRE(youngs == 390);
	};

	TEST_CASE("dry_area_middles")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(1, 1000);
		int middles = model->get_middles(0);
		int olds = model->get_olds(0);
		REQUIRE(middles == 650);
	};

	TEST_CASE("dry_area_olds")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(1, 1000);
		int olds = model->get_olds(0);
		REQUIRE(olds == 260);
	};

	//////////////////

	TEST_CASE("mid_area_youngs")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(2, 1000);
		int youngs = model->get_youngs(0);
		REQUIRE(youngs == 465);
	};

	TEST_CASE("mid_area_middles")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(2, 1000);
		int middles = model->get_middles(0);
		int olds = model->get_olds(0);
		REQUIRE(middles == 775);
	};

	TEST_CASE("mid_area_olds")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(2, 1000);
		int olds = model->get_olds(0);
		REQUIRE(olds == 310);
	};

	/////////////////

	TEST_CASE("wet_area_youngs")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(3, 1000);
		int youngs = model->get_youngs(0);
		REQUIRE(youngs == 570);
	};

	TEST_CASE("wet_area_middles")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(3, 1000);
		int middles = model->get_middles(0);
		int olds = model->get_olds(0);
		REQUIRE(middles == 950);
	};

	TEST_CASE("wet_area_olds")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(3, 1000);
		int olds = model->get_olds(0);
		REQUIRE(olds == 380);
	};

	TEST_CASE("wet_area_next_lev_olds")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(3, 1000);
		model->next_level(0);
		int olds = model->get_olds(0);
		REQUIRE(olds == 304);
	};

	TEST_CASE("wet_area_next_lev_mids")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(3, 1000);
		model->next_level(0);
		int middles = model->get_middles(0);
		REQUIRE(middles == 760);
	};

	TEST_CASE("wet_area_next_lev_youngs")
	{
		bacteria_factory *model = new bacteria_factory();
		model->add(3, 1000);
		model->next_level(0);
		int youngs = model->get_youngs(0);
		REQUIRE(youngs == 456);
	};
}