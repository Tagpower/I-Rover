/*!
 * \brief Classe TestRobot.
 * \details Tests de la classe Robot avec CPPUnit.
 * \author Geoffrey DESBROSSES
 * \version 1
 * \date 2015-12-10
 */

#include "robot.hpp"
#include "ennemi.hpp"
#include "coffre.hpp"
#include "clef.hpp"


class TestRobot : public CppUnit::TestCase {

private:
    Robot *robot;
    Ennemi *ennemi;
    Clef *clef;
    Coffre *coffre;
public:
  TestRobot( std::string name ) : CppUnit::TestCase( name ) {}

  void setUp()
  {
    robot = new Robot();
    robot->setPositionX(0);
    robot->setPositionY(0);
    robot->setPuissance(10);
    robot->setInventaire(1);

    ennemi = new Ennemi();
    ennemi->setPositionX(2);
    ennemi->setPositionY(2);
    ennemi->setPuissance(0);

    clef = new Clef();
    clef->setPositionX(4);
    clef->setPositionY(4);

    coffre = new Coffre();
    coffre->setPositionX(6);
    coffre->setPositionY(6);
  }


  void testDeplacer(){
    robot->deplacer(1,0);
    CPPUNIT_ASSERT(robot->getPositionX() == 1);
    CPPUNIT_ASSERT(robot->getPositionY() == 0);
  }

  void testDeplacer(){
    robot->deplacer(2,0);
    CPPUNIT_ASSERT(robot->getPositionX() == 0);
    CPPUNIT_ASSERT(robot->getPositionY() == 0);
  }
    void testDeplacer(){
    robot->deplacer(0,0);
    CPPUNIT_ASSERT(robot->getPositionX() == 0);
    CPPUNIT_ASSERT(robot->getPositionY() == 0);
  }

    void testDeplacer(){
    robot->deplacer(0,1);
    CPPUNIT_ASSERT(robot->getPositionX() == 0);
    CPPUNIT_ASSERT(robot->getPositionY() == 1);
  }

    void testDeplacer(){
    robot->deplacer(1,1);
    CPPUNIT_ASSERT(robot->getPositionX() == 0);
    CPPUNIT_ASSERT(robot->getPositionY() == 0);
  }

    void testDeplacer(){
    robot->deplacer(-1,0);
    CPPUNIT_ASSERT(robot->getPositionX() == 0);
    CPPUNIT_ASSERT(robot->getPositionY() == 0);
  }

    void testDeplacer(){
    robot->setPositionX(1);
    robot->deplacer(-1,0);
    CPPUNIT_ASSERT(robot->getPositionX() == 0);
    CPPUNIT_ASSERT(robot->getPositionY() == 0);
  }

    void testOuvrir(){
    robot->setPositionX(6);
    robot->setPositionY(6);
    robot->ouvrir(coffre*);
    CPPUNIT_ASSERT(robot->getInventaire() == 0);
    CPPUNIT_ASSERT(coffre->isOuvert());
    }

    void testOuvrir(){
    robot->ouvrir(coffre*);
    CPPUNIT_ASSERT(robot->getInventaire() == 1);
    CPPUNIT_ASSERT(!coffre->isOuvert());
    }

    void testOuvrir(){
    robot->setPositionX(6);
    robot->setPositionY(6);
    robot->setInventaire(0);
    robot->ouvrir(coffre*);
    CPPUNIT_ASSERT(robot->getInventaire() == 0);
    CPPUNIT_ASSERT(!coffre->isOuvert());
    }

    void testOuvrir(){
    robot->setPositionX(6);
    robot->setPositionY(6);
    coffre->setOuvert(true);
    robot->ouvrir(coffre*);
    CPPUNIT_ASSERT(robot->getInventaire() == 1);
    CPPUNIT_ASSERT(coffre->isOuvert());
    }

    void testRamasser(){
    robot->setPositionX(4);
    robot->setPositionY(4);
    robot->ramasser(clef*);
    CPPUNIT_ASSERT(robot->getInventaire() == 2);
    }

    void testRamasser(){
    robot->ramasser(clef*);
    CPPUNIT_ASSERT(robot->getInventaire() == 1);
    }

};
