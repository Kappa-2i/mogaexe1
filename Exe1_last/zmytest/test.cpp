/* ************************************************************************** */

#include <iostream>
#include <random>
#include <string>
#include <sstream>
/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/testable.hpp"
#include "../container/dictionary.hpp"
#include "../container/traversable.hpp"
#include "../container/mappable.hpp"
#include "../container/linear.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void mytest() {
    cout << endl << "~*~#~*~ Welcome in My Test - By Casolare Francesco ~*~#~*~ " << endl; 
    uint testerr = 0;
    uint testnum = 0;
    stringstream numerr;
    cout << "---------------------------------Test on Vector<int>---------------------------------" << endl;

    // Crea un vettore di interi 
    lasd::Vector<int> vec;
    cout << "Vector<int> with size: " << vec.Size() << endl;

    // Verifica che il vettore sia vuoto
    bool chk = vec.Empty();
    cout << testnum+1 << ") Vector is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Front value is: " << vec.Front() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Back value is: " << vec.Back() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    // Test quando il contenitore è vuoto
    try {
        int ind = 1;
        cout << testnum+1 << ") Value at index 1 is: " << vec[ind] << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const std::out_of_range& e) {
        cout << e.what() << endl;
    }
    testnum++;

    //Test per il Resize e il fill del vettore
    vec.Resize(5);
    try{
      cout << testnum+1 << ") Resize... New vector size: "<< vec.Size() << endl;
    }catch(const std::bad_alloc& e){
      cout << e.what() << endl;
      testerr += 1;
      numerr << testnum +1 << " ";
    }
    testnum++;



    // Genera numeri casuali e popola il vettore
    default_random_engine gen(random_device{}());
    uniform_int_distribution<int> dist(1, 100);
    for (uint i = 0; i < vec.Size(); ++i) {
        vec[i] = dist(gen);
        cout <<"\t [" << vec[i] << "] ";
    }
    cout << endl;

    // Riconferma che il vettore non sia vuoto dopo aver aggiunto gli elementi
    chk = vec.Empty();
    cout << testnum+1 <<") Vector is " << (chk ? "" : "not ") << "empty after filling" << endl;
    if (chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;
    
    cout << "Errori/Test: " << testerr << "/" << testnum << endl;
    cout << "Errori nei test: " << numerr.str() << endl;

}
