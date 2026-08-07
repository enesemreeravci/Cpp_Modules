#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

void test_with_const()
{
    try
    {
        MutantStack<int> stack;
        
        stack.push(10);
        stack.push(20);
        stack.push(30);
        
        const MutantStack<int> constStack = stack;
        MutantStack<int>::const_iterator const_it = constStack.begin();
        // from now I am not able to push, because it is const.
        std::cout << "Top element is:  " <<  constStack.top() << std::endl;
        std::cout << "Size : " << constStack.size() << std::endl; 

        while(const_it != constStack.end())
        {
            std::cout << *const_it << std::endl;
            const_it++; 
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        
}
void test_with_list()
{
    try
    {
        
        MutantStack<int, std::list<int> > mList;
        mList.push(50);
        mList.push(100);
        mList.push(150);
        mList.push(200);

        unsigned int size = mList.size();
        std::cout << "Size of list: " << size << std::endl;
        std::cout << "Top of the list: " << mList.top() << std::endl;
        MutantStack<int, std::list<int> >::iterator it = mList.begin();
        while(it != mList.end())
        {
            std::cout << *it << std::endl;
            it++;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_with_vector()
{
    try
    {
        
        MutantStack<std::string, std::vector<std::string> > mVector;
        mVector.push("This is");
        mVector.push("a");
        mVector.push("test");
        
        unsigned int  size = mVector.size();
        std::cout << "Size of vector: " << size << std::endl;
        MutantStack<std::string, std::vector<std::string> >::iterator it = mVector.begin();
        while(it != mVector.end())
        {
            std::cout << *it << std::endl;
            it++;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


int main()
{
    // test_with_list();
    //test_with_vector();
    test_with_const();

    // MutantStack<int> mstack;
    // mstack.push(5);
    // mstack.push(17);
    // std::cout << mstack.top() << std::endl;
    // mstack.pop();
    // std::cout << mstack.size() << std::endl;
    // mstack.push(3);
    // mstack.push(5);
    // mstack.push(737);
    // //[...]
    // mstack.push(0);
    
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();

    // ++it;
    // --it;
    // while (it != ite)
    // {
    //     std::cout << *it << std::endl;
    //     ++it;
    // }
    // std::stack<int> s(mstack);



    return 0;
}