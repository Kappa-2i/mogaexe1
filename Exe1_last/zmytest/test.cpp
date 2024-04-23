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

    
    int choice = 1;
    while(choice){
        std::cout << endl << "Pick the data structure:\n 1-Vector\n 2-List \n 3-VectorList \n 4-Queue \n 0-Exit for results." << std::endl;
        std::cin >> choice;
        switch(choice){
            case 1:
                choiceVectorType(testerr, testnum, numerr);
                break;
            case 2:
                choiceListType(testerr, testnum, numerr);
                break;
            case 3:
                break;
            case 4:
                break;
            case 0: 
                break;
            default:
                std::cout << "Invalid choice" << std::endl;
        }
    }
    cout << "Errors/Tests: " << testerr << "/" << testnum << endl;
    cout << "Number error test: " << numerr.str() << endl;

}


void choiceVectorType(uint& testerr, uint& testnum, stringstream& numerr){


    std::cout << "Pick the data type: \n 1-Int \n 2-Double \n 3-String" << std::endl;
    int choice = 1;
    
    std::cin >> choice;
    switch(choice){
        case 1:{
            testVectorInt(testerr, testnum, numerr);
            break;
        }
        case 2:{
            testVectorDouble(testerr, testnum, numerr);
            break;
        }
        case 3:{
            testVectorString(testerr, testnum, numerr);
            break;
        }
        default:
            std::cout << "Invalid choice" << std::endl;
    }
    
}

void choiceListType(uint& testerr, uint& testnum, stringstream& numerr){


    std::cout << "Pick the data type: \n 1-Int \n 2-Double \n 3-String" << std::endl;
    int choice = 1;
    
    std::cin >> choice;
    switch(choice){
        case 1:{
            testListInt(testerr, testnum, numerr);
            break;
        }
        case 2:{
            //testListDouble(testerr, testnum, numerr);
            break;
        }
        case 3:{
            //testListString(testerr, testnum, numerr);
            break;
        }
        default:
            std::cout << "Invalid choice" << std::endl;
    }
    
}

void testVectorInt(uint& testerr, uint& testnum, stringstream& numerr){
    
    cout << "---------------------------------Test on Vector<int>---------------------------------" << endl;

    lasd::SortableVector<int> vec;
    
    // Controllo size del vec
    cout << "Vector<int> with size: " << vec.Size() << endl;

    // Verifica che il vettore sia vuoto
    bool chk = vec.Empty();
    cout << testnum+1 << ") Vector is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Stampa della somma degli elementi del vettore in PostOrderFold
    try{
        int sum = vec.PostOrderFold(&FoldAdd<int>, 0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
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
        cout << testnum+1 << ") Value at index 1 is: " << vec[1] << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const std::out_of_range& e) {
        cout << e.what() << endl;
    }
    testnum++;


    //Test per controllare se esiste un elemento
    chk = vec.Exists(0);
    cout << testnum+1 << ") Value 0 " << (chk ? "" : "not ") << "exists" << endl;
    if (chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
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
    uniform_int_distribution<int> dist(-500, 500);
    for (uint i = 0; i < vec.Size(); ++i) {
        vec[i] = dist(gen);
    }

    // Riconferma che il vettore non sia vuoto dopo aver aggiunto gli elementi
    chk = vec.Empty();
    cout << testnum+1 <<") Vector is " << (chk ? "" : "not ") << "empty after filling" << endl;
    if (chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;
    

    //Stampa del vettore in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print Vec in PreOrderTraverse: " << endl << "\t";
        vec.PreOrderTraverse(&TraversePrint<int>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    //Stampa della somma degli elementi del vettore in PreOrderFold
    
    try{
        int sum = vec.PreOrderFold(&FoldAdd<int>, 0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    // Sort del vec, con stampa
    try{
        vec.Sort();
        cout << testnum+1 << ") Print Sort vec: " << endl << "\t";
        vec.PreOrderTraverse(&TraversePrint<int>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Test per il Resize e il fill del vettore
    vec.Resize(3);
    try{
      cout << testnum+1 << ") Resize... New vector size: "<< vec.Size() << endl;
    }catch(const std::bad_alloc& e){
      cout << e.what() << endl;
      testerr += 1;
      numerr << testnum +1 << " ";
    }
    testnum++;

     //Stampa del vettore in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print Vec in PostOrderTraverse: " << endl << "\t";
        vec.PostOrderTraverse(&TraversePrint<int>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    //Stampa della somma degli elementi del vettore in PostOrderFold
    try{
        int sum = vec.PostOrderFold(&FoldAdd<int>, 0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    cout << "---------------------------------End of test Vector<int>---------------------------------" << endl;
}

void testVectorDouble(uint& testerr, uint& testnum, stringstream& numerr){

    cout << "---------------------------------Test on Vector<double>---------------------------------" << endl;
    
    lasd::SortableVector<double> vec;
    
    // Controllo size del vec
    cout << "Vector<double> with size: " << vec.Size() << endl;

    // Verifica che il vettore sia vuoto
    bool chk = vec.Empty();
    cout << testnum+1 << ") Vector is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Stampa della somma degli elementi del vettore in PostOrderFold
    try{
        double sum = vec.PostOrderFold(&FoldAdd<double>, 0.0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
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
        cout << testnum+1 << ") Value at index 1 is: " << vec[1] << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const std::out_of_range& e) {
        cout << e.what() << endl;
    }
    testnum++;


    //Test per controllare se esiste un elemento
    chk = vec.Exists(0);
    cout << testnum+1 << ") Value 0 " << (chk ? "" : "not ") << "exists" << endl;
    if (chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
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
    uniform_real_distribution<double> dist(-500, 500);
    for (uint i = 0; i < vec.Size(); ++i) {
        vec[i] = dist(gen);
    }

    // Riconferma che il vettore non sia vuoto dopo aver aggiunto gli elementi
    chk = vec.Empty();
    cout << testnum+1 <<") Vector is " << (chk ? "" : "not ") << "empty after filling" << endl;
    if (chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;
    

    //Stampa del vettore in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print Vec in PreOrderTraverse: " << endl << "\t";
        vec.PreOrderTraverse(&TraversePrint<double>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    //Stampa della somma degli elementi del vettore in PreOrderFold
    try{
        double sum = vec.PreOrderFold(&FoldAdd<double>, 0.0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    // Sort del vec, con stampa
    try{
        vec.Sort();
        cout << testnum+1 << ") Print Sort vec: " << endl << "\t";
        vec.PreOrderTraverse(&TraversePrint<double>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Test per il Resize e il fill del vettore
    vec.Resize(3);
    try{
      cout << testnum+1 << ") Resize... New vector size: "<< vec.Size() << endl;
    }catch(const std::bad_alloc& e){
      cout << e.what() << endl;
      testerr += 1;
      numerr << testnum +1 << " ";
    }
    testnum++;

    //Stampa del vettore in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print Vec in PostOrderTraverse: " << endl << "\t";
        vec.PostOrderTraverse(&TraversePrint<double>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    //Stampa della somma degli elementi del vettore in PostOrderFold
    try{
        double sum = vec.PostOrderFold(&FoldAdd<double>, 0.0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    cout << "---------------------------------End of test Vector<double>---------------------------------" << endl;
}

void testVectorString(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on Vector<string>---------------------------------" << endl;
    lasd::SortableVector<string> vec;

    // Controllo size del vec
    cout << "Vector<string> with size: " << vec.Size() << endl;

    // Verifica che il vettore sia vuoto
    bool chk = vec.Empty();
    cout << testnum+1 << ") Vector is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Test per controllare se esiste un elemento
    chk = vec.Exists("ABC");
    cout << testnum+1 << ") Value 'ABC' " << (chk ? "" : "not ") << "exists" << endl;
    if (chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
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


    // Genera caratteri casuali e popola il vettore
    // Genera numeri casuali e popola il vettore
    std::string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> randPos(0, table.size()-1);
    for (uint i = 0; i < vec.Size(); ++i) {
        vec[i] = table[randPos(gen)];
    }

    //Stampa del vettore in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print Vec in PreOrderTraverse: " << endl << "\t";
        vec.PreOrderTraverse(&TraversePrint<string>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    // Sort del vec, con stampa
    try{
        vec.Sort();
        cout << testnum+1 << ") Print Sort vec: " << endl << "\t";
        vec.PreOrderTraverse(&TraversePrint<string>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Stampa della somma degli elementi del vettore in PreOrderFold
    try{
        string conc = vec.PreOrderFold(&FoldAdd<string>, string(""));
        cout << testnum+1 << ") Concatenate vector: " << conc << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;
    
    lasd::SortableVector<string> copvec(vec);
    //Stampa del copy vec in PreOrderTraverse
    try{
        cout << "\t" << "copy of vec in movvec..." << endl;
        cout << testnum+1 << ") Print copy vec in PreOrderTraverse: " << endl << "\t";
        copvec.PreOrderTraverse(&TraversePrint<string>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Stampa del vettore in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print Vec in PreOrderTraverse: " << endl << "\t";
        vec.PreOrderTraverse(&TraversePrint<string>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    lasd::SortableVector<string> movvec(move(vec));
    //Stampa del move vec in PreOrderTraverse
    try{
        cout << "\t" << "move of vec in movvec..." << endl;
        cout << testnum+1 << ") Print move vec in PreOrderTraverse: " << endl << "\t";
        movvec.PreOrderTraverse(&TraversePrint<string>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    // Verifica che il vettore sia vuoto
    chk = vec.Empty();
    cout << testnum+1 << ") Vector is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Stampa del vettore in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print Vec in PostOrderTraverse: " << endl << "\t";
        vec.PostOrderTraverse(&TraversePrint<string>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Controllo uguaglianza di copy vec e move vec
    if(movvec == copvec){
        cout << testnum+1 << ") Copy vec is equals to move vec" << endl;
    }else{
        cout << testnum+1 << ") Copy vec is not equals to move vec" << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    

    cout << "---------------------------------End of test Vector<string>---------------------------------" << endl;
}

void testListInt(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on List<int>---------------------------------" << endl;
    lasd::List<int> lst;

     // Controllo size del vec
    cout << "List<int> with size: " << lst.Size() << endl;

    //Test per controllare se esiste un elemento
    bool chk = lst.Exists(0);
    cout << testnum+1 << ") Value 0 " << (chk ? "" : "not ") << "exists" << endl;
    if (chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    
    //Verifica per prendere un elemento in testa
    try
    {
        cout << testnum+1 << ") Value in front is: " << lst.Front();
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    catch(const std::length_error& e)
    {
        std::cerr << e.what() << endl;
    }
    testnum++;

    //Verifica per prendere un elemento in coda
    try
    {
        cout << testnum+1 << ") Value in back is: " << lst.Back();
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    catch(const std::length_error& e)
    {
        std::cerr << e.what() << endl;
    }
    testnum++;
    
    // Genera numeri casuali e popola la lista
    cout << testnum+1 << ") Insert random number in back..." << endl;
    default_random_engine gen(random_device{}());
    uniform_int_distribution<int> dist(-500, 500);
    for (uint i = 0; i < 5; ++i) {
        try{
            lst.InsertAtBack(dist(gen));
        }catch(const bad_alloc& e){
            std::cerr << e.what() << endl;
            testerr += 1;
            numerr << testnum + 1 << " ";
        }
    }
    testnum++;

    //Stampa della lista in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print List in PreOrderTraverse: " << endl << "\t";
        lst.PreOrderTraverse(&TraversePrint<int>);   
        cout << endl;
    } catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Rimuove elemento in testa della lista
    try{
        cout << testnum+1 << ") Remove element in head..." << endl;
        lst.RemoveFromFront();
    } catch(const length_error& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Stampa size della lista
    cout << testnum+1 << ") New Size of the list: " << lst.Size() << endl;
    testnum++;

    //Stampa della lista in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print List in PreOrderTraverse: " << endl << "\t";
        lst.PreOrderTraverse(&TraversePrint<int>);   
        cout << endl;
    } catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Aggiunge elemento in testa della lista
    try{
        cout << testnum+1 << ") Insert new element in head..." << endl ;
        lst.InsertAtFront(dist(gen));
    } catch(const bad_alloc& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;
    
    //Stampa della lista in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print List in PreOrderTraverse: " << endl << "\t";
        lst.PreOrderTraverse(&TraversePrint<int>);   
        cout << endl;
    } catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    lasd::List<int> coplst(lst);
    //Stampa della lista in PreOrderTraverse
    try{
        cout << "\t Copy of the list in a new list..." << endl;
        cout << testnum+1 << ") Print copy list in PreOrderTraverse: " << endl << "\t";
        lst.PreOrderTraverse(&TraversePrint<int>);   
        cout << endl;
    } catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    lasd::List<int> movlst(move(coplst));
    //Stampa della lista in PreOrderTraverse
    try{
        cout << "\t Move of the copy list in a new list..." << endl;
        cout << testnum+1 << ") Print move List in PreOrderTraverse: " << endl << "\t";
        lst.PreOrderTraverse(&TraversePrint<int>);   
        cout << endl;
    } catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    //Controllo uguaglianza di copy vec e move vec
    if(lst == movlst){
        cout << testnum+1 << ") List is equals to move list" << endl;
    }else{
        cout << testnum+1 <<") List is not equals to move list" << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Controllo uguaglianza di copy list e list
    if(lst != coplst){
        cout << testnum+1 << ") List is not equals to copy list" << endl;
    }else{
        cout << testnum+1 << ") List is equals to move list" << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Stampa della somma degli elementi del vettore in PostOrderFold
    try{
        int sum = movlst.PostOrderFold(&FoldAdd<int>, 0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;



    cout << "---------------------------------End of test List<int>---------------------------------" << endl;

}