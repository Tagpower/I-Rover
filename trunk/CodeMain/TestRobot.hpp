#include "precomp.hpp"
#include "robot.hpp"
#include "ennemi.hpp"
#include "coffre.hpp"
#include "clef.hpp"

#pragma once


class TestRobot : public CppUnit::TestCase {

private:
    Robot *robot;
    Ennemi *ennemi;
    Clef *clef;
    Coffre *coffre;
public:
  TestRobot( std::string name ) : CppUnit::TestCase( name );

	 	void setUp();
		void testDeplacer();
	    	void testOuvrir();
		void testRamasser();

};

