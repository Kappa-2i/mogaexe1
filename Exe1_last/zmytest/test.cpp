/* ************************************************************************** */

#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include "test.hpp"

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

    std::cout << "Pick the data structure:\n 1-Vector\n 2-List \n 3-Stack \n 4-Queue" << std::endl;
    int choice = 1;
    while(choice){
        std::cin >> choice;
        switch(choice){
            case 1:
                choiceVectorType(testerr, testnum, numerr);
                return;
                break;
            case 2:
                return;
                break;
            case 3:
                return;
                break;
            case 4:
                return;
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }
    cout << "Errori/Test: " << testerr << "/" << testnum << endl;
    cout << "Errori nei test: " << numerr.str() << endl;

}


void choiceVectorType(uint& testerr, uint& testnum, stringstream& numerr){

    unsigned long length;
    std::cout << "Choose the length of the data structure: "<< std::endl;
    std::cin >> length;

    std::cout << "Pick the data type: \n 1-Int \n 2-Double \n 3-String" << std::endl;
    int choice = 1;
    
    std::cin >> choice;
    switch(choice){
        case 1:{
            lasd::Vector<int> vec = intVector(length) ;
            testVectorInt(vec, testerr, testnum, numerr);
            return;
            break;
        }
        case 2:{
            lasd::Vector<double> vec = doubleVector(length);
            //testVector(vec, testerr, testnum, numerr);
            return;
            break;
        }
        case 3:{
            lasd::Vector<string> vec = stringVector(length);
            //testVector(vec, testerr, testnum, numerr);
            return;
            break;
        }
        default:
            std::cout << "Invalid choice" << std::endl;
    }
    
}

lasd::Vector<int> intVector(const unsigned long len){

    lasd::Vector<int> vector = Vector<int>(len); 
    default_random_engine gen(std::random_device{}());
    uniform_int_distribution<int> dist(0, 200);
    for(unsigned long i = 0; i < vector.Size(); i++){
        vector[i] = dist(gen);
    }
    return vector;

}
              
lasd::Vector<double> doubleVector(const unsigned long len){
    lasd::Vector<double> vector = Vector<double>(len); 
    default_random_engine gen(std::random_device{}());
    uniform_real_distribution<double> dist;
    for(unsigned long i = 0; i < vector.Size(); i++){
        vector[i] = dist(gen);
    }
    return vector;

}
       
lasd::Vector<string> stringVector(const unsigned long len){
    lasd::Vector<std::string> vector = Vector<std::string>(len);

    string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    default_random_engine gen(std::random_device{}());
    uniform_int_distribution<int> dist(1, 10);
    uniform_int_distribution<int> randPos(0, table.size()-1);

    string temp;
    for(unsigned long i = 0; i < len; i++){
        temp = "";
        uint newLen = dist(gen);
        for(unsigned long j = 0; j < newLen; j++){
            temp += table[randPos(gen)];
        }
        vector[i] = temp;
    }

    return vector;
}

void testVectorInt(lasd::Vector<int>& vec, uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on Vector<int>---------------------------------" << endl;

    // Crea un vettore di interi 
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
}
