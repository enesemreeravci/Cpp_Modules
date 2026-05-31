#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "\n========== SUBJECT TEST ==========\n" << std::endl;

    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("Enes");

    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("Bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "\n========== INVENTORY LIMIT TEST ==========\n" << std::endl;

    Character hero("Hero");

    hero.equip(new Ice());
    hero.equip(new Ice());
    hero.equip(new Cure());
    hero.equip(new Cure());

    std::cout << "\nTrying to equip a 5th Materia..." << std::endl;
    hero.equip(new Ice());

    std::cout << "\n========== UNEQUIP TEST ==========\n" << std::endl;

    Character target("Target");

    hero.use(0, target);

    std::cout << "\nUnequipping slot 0..." << std::endl;
    hero.unequip(0);

    std::cout << "\nTrying to use slot 0 after unequip..." << std::endl;
    hero.use(0, target);

    std::cout << "\n========== INVALID INDEX TEST ==========\n" << std::endl;

    hero.use(-1, target);
    hero.use(42, target);

    hero.unequip(-1);
    hero.unequip(42);

    std::cout << "\n========== COPY CONSTRUCTOR TEST ==========\n" << std::endl;

    Character original("Original");

    original.equip(new Ice());
    original.equip(new Cure());

    Character copy(original);

    std::cout << "\nOriginal uses inventory:" << std::endl;
    original.use(0, target);
    original.use(1, target);

    std::cout << "\nCopy uses inventory:" << std::endl;
    copy.use(0, target);
    copy.use(1, target);

    std::cout << "\n========== ASSIGNMENT OPERATOR TEST ==========\n" << std::endl;

    Character assigned("Assigned");

    assigned = original;

    assigned.use(0, target);
    assigned.use(1, target);

    std::cout << "\n========== DEEP COPY TEST ==========\n" << std::endl;

    Character first("First");

    first.equip(new Ice());
    first.equip(new Cure());

    Character second(first);

    std::cout << "\nRemoving first inventory slot..." << std::endl;
    first.unequip(0);

    std::cout << "\nFirst uses slot 0:" << std::endl;
    first.use(0, target);

    std::cout << "\nSecond uses slot 0:" << std::endl;
    second.use(0, target);

    std::cout << "\nIf second still uses Ice, deep copy works.\n" << std::endl;

    std::cout << "\n========== MATERIA SOURCE TEST ==========\n" << std::endl;

    MateriaSource storage;

    storage.learnMateria(new Ice());
    storage.learnMateria(new Cure());

    AMateria* ice = storage.createMateria("ice");
    AMateria* cure = storage.createMateria("cure");
    AMateria* unknown = storage.createMateria("fire");

    Character mage("Mage");

    mage.equip(ice);
    mage.equip(cure);

    mage.use(0, target);
    mage.use(1, target);

    if (!unknown)
        std::cout << "[TEST] fire Materia was not found." << std::endl;

    delete unknown;

    std::cout << "\n========== END OF MAIN ==========\n" << std::endl;

    return 0;
}