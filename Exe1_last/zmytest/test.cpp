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
        std::cout << endl << "Pick the data structure:\n 1-Vector\n 2-List \n 3-Stack \n 4-Queue \n 0-Exit for results." << endl;
        std::cin >> choice;
        switch(choice){
            case 1:
                choiceVectorType(testerr, testnum, numerr);
                break;
            case 2:
                choiceListType(testerr, testnum, numerr);
                break;
            case 3:
                choiceStackType(testerr, testnum, numerr);
                break;
            case 4:
                choiceQueueType(testerr, testnum, numerr);
                break;
            case 0: 
                break;
            default:
                cout << "Invalid choice" << endl;
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
            testListDouble(testerr, testnum, numerr);
            break;
        }
        case 3:{
            testListString(testerr, testnum, numerr);
            break;
        }
        default:
            std::cout << "Invalid choice" << std::endl;
    }
    
}

void choiceStackType(uint& testerr, uint& testnum, stringstream& numerr){
    std::cout << "Pick the data type: \n 1-StackVec<float> \n 2-StackVec<string> \n 3-StackList<float> \n 4-StackList<string>" << std::endl;
    int choice = 1;
    
    std::cin >> choice;
    switch(choice){
        case 1:{
            testStackVecFloat(testerr, testnum, numerr);
            break;
        }
        case 2:{
            testStackVecString(testerr, testnum, numerr);
            break;
        }
        case 3:{
            testStackListFloat(testerr, testnum, numerr);
            break;
        }
        case 4:{
            testStackListString(testerr, testnum, numerr);
            break;
        }
        default:
            std::cout << "Invalid choice" << std::endl;
    }
}

void choiceQueueType(uint& testerr, uint& testnum, stringstream& numerr){
    std::cout << "Pick the data type: \n 1-QueueVec<float> \n 2-QueueVec<string> \n 3-QueueList<float> \n 4-QueueList<string>" << std::endl;
    int choice = 1;
    
    std::cin >> choice;
    switch(choice){
        case 1:{
            testQueueVecFloat(testerr, testnum, numerr);
            break;
        }
        case 2:{
            //testQueueVecString(testerr, testnum, numerr);
            break;
        }
        case 3:{
            //testQueueListFloat(testerr, testnum, numerr);
            break;
        }
        case 4:{
            //testQueueListString(testerr, testnum, numerr);
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

    //Clear di move vec e copy vec
    movvec.Clear();
    copvec.Clear();
    cout << "\t Clear of move vec and copy vec..." << endl;
    // Verifica che il vettore sia vuoto
    chk = copvec.Empty();
    cout << testnum+1 << ") Copy vec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;
    // Verifica che il vettore sia vuoto
    chk = movvec.Empty();
    cout << testnum+1 << ") Move vec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
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

    //Stampa della somma degli elementi di move lst in PostOrderFold
    try{
        int sum = movlst.PostOrderFold(&FoldAdd<int>, 0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;
    
    //Clear di movlst e verifica che sia vuoto
    cout << "\t Clear of move list..." << endl;
    movlst.Clear();
    chk = movlst.Empty();
    cout << testnum+1 << ") Move list is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;



    cout << "---------------------------------End of test List<int>---------------------------------" << endl;

}

void testListDouble(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on List<double>---------------------------------" << endl;

    
    lasd::SortableVector<double> vec(5);
    // Genera numeri casuali e popola il vettore
    default_random_engine gen(random_device{}());
    uniform_real_distribution<double> dist(-500, 500);
    for (uint i = 0; i < vec.Size(); ++i) {
        vec[i] = dist(gen);
    }
    cout << "New SortableVector<double>: ";
    vec.Sort();
    vec.PreOrderTraverse(&TraversePrint<double>);   
    cout << endl;

    

    lasd::List<double> lst;

    //Test per controllare se esiste un elemento
    cout << "New List<double>..." << endl;
    bool chk = lst.Exists(vec[0]);
    cout << testnum+1 << ") Element " << vec[0] <<(chk ? "" : " not ") << "exists in the list" << endl;
    if (chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //aggiunge elementi del vettore nella lista
    try{
        cout << testnum+1 << ") Insert vec elements in list..." << endl ;
        for(uint i = 0; i < vec.Size(); i++){
            lst.Insert(vec[i]);
        }
    } catch(const bad_alloc& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    chk = lst.Empty();
    cout << testnum+1 << ") List is " << (chk ? "" : "not ") << "empty" << endl;
    if (chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;


    //Stampa della lista in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print List in PreOrderTraverse: " << endl << "\t";
        lst.PreOrderTraverse(&TraversePrint<double>);   
        cout << endl;
    } catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    lasd::List<double> movlst(move(vec));
    cout << "Move of vec in move list..." << endl;
    
    //Stampa della lista in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print move list in PreOrderTraverse: " << endl << "\t";
        movlst.PreOrderTraverse(&TraversePrint<double>);   
        cout << endl;
    } catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    //Confronto uguaglianza della somma degli elementi delle liste
    try{
        double sum_lst = lst.PostOrderFold(&FoldAdd<double>, 0.0);
        cout << testnum+1 << ") Sum elements of list: " << sum_lst;

        double sum_movlst = movlst.PostOrderFold(&FoldAdd<double>, 0.0);
        cout << " \t Sum elements of move list: " << sum_movlst << endl;

        if(sum_lst != sum_movlst){
            testerr += 1;
            numerr << testnum +1 << " ";
        }
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Confronto e rimozione degli elementi in testa delle due liste
    try{
        for(uint i = 0; i<lst.Size(); i++){
            cout << testnum+1 << ") " << i+1 << "° element both lists are " << ((lst.Front() == movlst.Front()) ? "" : "not ") << "equal"<< endl;
            testnum++;
        }
        
    }catch(const bad_alloc& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    
    //Rimozione degli elementi di list
    try{
        cout << testnum+1 << ") Remove elements from list..." <<endl;
        for(uint i = lst.Size(); i>0; i--){
            lst.RemoveFromFront();
        }
    }catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Rimozione degli elementi di move list
    try{
        cout << testnum+1 << ") Remove elements from move list..." <<endl;
        for(uint i = movlst.Size(); i>0; i--){
            movlst.RemoveFromFront();
        }
    }catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Controllo che la list sia vuota
    chk = lst.Empty();
    cout << testnum+1 << ") List is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Controllo che la move list sia vuota
    chk = movlst.Empty();
    cout << testnum+1 << ") Move list is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;



    cout << "---------------------------------End of test List<double>---------------------------------" << endl;
}

void testListString(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on List<string>---------------------------------" << endl;
    lasd::List<string> lst;

    //Controllo che la move list sia vuota
    bool chk = lst.Empty();
    cout << testnum+1 << ") List is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    
    // Genera caratteri casuali e popola la lista
    cout << "Insert random elements..." << endl;
    std::string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> randPos(0, table.size()-1);
    string random;
    try{
        for (uint i = 0; i < 5; ++i) {
            random = table[randPos(gen)];
            lst.InsertAtFront(random);
        }
    }catch(const bad_alloc& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    

    
    //Stampa della lista in PreOrderTraverse
    try{
        cout << testnum+1 << ") Print list in PreOrderTraverse: " << endl << "\t";
        lst.PreOrderMap(&TraversePrint<string>);   
        cout << endl;
    } catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    cout << "Copy of the list..." << endl;
    lasd::List<string> coplst(lst);


    //Stampa della somma degli elementi del vettore in PreOrderFold
    try{
        string conc = lst.PreOrderFold(&FoldAdd<string>, string(""));
        cout << testnum+1 << ") Concatenate list in pre order: " << conc << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    //Stampa della somma degli elementi del vettore in PreOrderFold
    try{
        string conc = coplst.PostOrderFold(&FoldAdd<string>, string(""));
        cout << testnum+1 << ") Concatenate copy list in post order: " << conc << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;



    //Rimozione degli elementi di list
    try{
        cout << testnum+1 << ") Remove elements from list..." <<endl;
        for(uint i = lst.Size(); i>0; i--){
            lst.RemoveFromFront();
        }
    }catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Rimozione degli elementi di copy list
    try{
        cout << testnum+1 << ") Remove elements from copy list..." <<endl;
        for(uint i = coplst.Size(); i>0; i--){
            coplst.RemoveFromFront();
        }
    }catch(const exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Creazione nuovo vettore: a b c d e
    lasd::Vector<string> vec(5);
    try{
        char c = 'a';
        for (uint i = 0; i < vec.Size(); ++i) {
            vec[i] = c++;
        }
        cout << testnum+1 << ") New Vector<string>: ";
        vec.PreOrderMap(&TraversePrint<string>);
        cout << endl;
    }
    catch(const out_of_range& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Move of vec in a move list
    lasd::List<string> movlst(move(vec));
    
    //Stampa della somma degli elementi del vettore in PreOrderFold
    try{
        string conc = movlst.PreOrderFold(&FoldAdd<string>, string(""));
        cout << testnum+1 << ") Concatenate move list: " << conc << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    //Controllo uguaglianza di copy vec e move vec
    if(movlst != lst){
        cout << testnum+1 << ") Copy vec is not equals to move vec" << endl;
    }else{
        cout << testnum+1 << ") Copy vec is equals to move vec" << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    cout << "---------------------------------End of test List<string>---------------------------------" << endl;
}



void testStackVecFloat(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on StackVec<float>---------------------------------" << endl; 

    lasd::StackVec<float> stkvec;
    // Controllo size del contenitore
    cout << "StackVec<float> with size: " << stkvec.Size() << endl;


    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") TopNPop from the stack with value: " << stkvec.TopNPop() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    // Genera numeri casuali e popola lo stack
    default_random_engine gen(random_device{}());
    uniform_real_distribution<float> dist(-500, 500);
    try{
        for (uint i = 0; i < 5; ++i) {
            float val = dist(gen);
            cout << testnum+1 << ") Push on the stack of the value: " << val << endl;
            stkvec.Push(val);
            testnum++;
        }
    }catch (std::exception & exc) {
        std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
        testerr += 1; 
        numerr << testnum + 1 << " ";
    }

    // Controllo size del contenitore
    cout << "StackVec<float> with size: " << stkvec.Size() << endl;


    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Top value is: " << stkvec.Top() << endl;
        
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Pop from the stack the top value:" << stkvec.Top() << endl;
        stkvec.Pop();
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Top value is: " << stkvec.Top() << endl;
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << "Clear of StackVec..." << endl;
    stkvec.Clear();

    //Controllo che la move list sia vuota
    bool chk = stkvec.Empty();
    cout << testnum+1 << ") StackVec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << "---------------------------------End of test StackVec<float>---------------------------------" << endl;
}

void testStackVecString(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on StackVec<float>---------------------------------" << endl;
    lasd::StackVec<string> stkvec;
    // Controllo size del vec
    cout << "StackVec<string> with size: " << stkvec.Size() << endl;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Top value is: " << stkvec.Top() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    // Genera valori casuali e popola lo stack
    std::string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> randPos(0, table.size()-1);
    try{
        for (uint i = 0; i < 5; ++i) {
            string val = string(1, table[randPos(gen)]);
            cout << testnum+1 << ") Push on the stack of the value: " << val << endl;
            stkvec.Push(val);
            testnum++;
        }
    }catch (std::exception & exc) {
        std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
        testerr += 1; 
        numerr << testnum + 1 << " ";
    }

    // Controllo size del vec
    cout << "StackVec<string> with size: " << stkvec.Size() << endl;


    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Top value is: " << stkvec.Top() << endl;
        
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << "Copy of stackvec..." << endl;
    lasd::StackVec<string> stkcpy(stkvec);

    // Controllo size del vec
    cout << "StackVec copy with size: " << stkcpy.Size() << endl;

    // Test quando il contenitore è pieno
    try {
        cout << testnum+1 << ") Top value of copy stackvec is: " << stkcpy.Top() << endl;
        
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Controllo uguaglianza di copy vec e move vec
    if(stkcpy == stkvec){
        cout << testnum+1 << ") Copy stackvec is equals to stackvec" << endl;
    }else{
        cout << testnum+1 << ") Copy stackvec is not equals to stackvec" << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    cout << "Move of stackvec..." << endl;
    lasd::StackVec<string> stkmov(move(stkvec));

    // Controllo size del vec
    cout << "StackVec move with size: " << stkmov.Size() << endl;

    // Test quando il contenitore è pieno
    try {
        cout << testnum+1 << ") Top value of move stackvec is: " << stkmov.Top() << endl;
        
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    // Test quando il contenitore è pieno
    try {
        cout << testnum+1 << ") Top value of stackvec is: " << stkvec.Top() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    //Controllo che la move list sia vuota
    bool chk = stkvec.Empty();
    cout << testnum+1 << ") StackVec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;


    //Controllo uguaglianza di copy vec e move vec
    if(stkmov != stkvec){
        cout << testnum+1 << ") Move stackvec is not equals to stackvec" << endl;
    }else{
        cout << testnum+1 << ") Move stackvec is equals to stackvec" << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Controllo uguaglianza di copy vec e move vec
    if(stkcpy == stkmov){
        cout << testnum+1 << ") Copy stackvec is equals to move stackvec" << endl;
    }else{
        cout << testnum+1 << ") Copy stackvec is not equals to move stackvec" << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    cout << "Clear of Copy StackVec..." << endl;
    stkcpy.Clear();

    //Controllo che la move list sia vuota
    chk = stkcpy.Empty();
    cout << testnum+1 << ") Copy StackVec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;


    cout << "Clear of Copy StackVec..." << endl;
    stkmov.Clear();

    //Controllo che la move list sia vuota
    chk = stkmov.Empty();
    cout << testnum+1 << ") Move StackVec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << "---------------------------------End of test StackVec<float>---------------------------------" << endl;

}

void testStackListFloat(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on StackList<float>---------------------------------" << endl;
    lasd::StackLst<float> stklst;

    // Controllo size del contenitore
    cout << "StackLst<float> with size: " << stklst.Size() << endl;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") TopNPop from the stack with value: " << stklst.TopNPop() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    lasd::SortableVector<float> vec(5);
    // Genera numeri casuali e popola il vettore
    default_random_engine gen(random_device{}());
    uniform_real_distribution<float> dist(-500, 500);
    for (uint i = 0; i < vec.Size(); ++i) {
        vec[i] = dist(gen);
    }
    cout << "New SortableVector<float>: ";
    vec.Sort();
    vec.PreOrderTraverse(&TraversePrint<double>);   
    cout << endl;

    cout << "StackLst = vec..." << endl;
    stklst = vec; 

    // Controllo size del contenitore
    cout << "StackLst<float> with size: " << stklst.Size() << endl;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Top from the stack with value: " << stklst.Top() << endl;
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << "Move of StackLst..." << endl;
    lasd::StackLst<float> stkmov(move(stklst));

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Top from the stack with value: " << stklst.Top() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    // Test quando il contenitore non è vuoto
    try {
        cout << testnum+1 << ") TopNPop from the move stack with value: " << stkmov.TopNPop() << endl;
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " ";
    }
    testnum++;

    //Controllo uguaglianza di stklist e stkmov
    if(stkmov != stklst){
        cout << testnum+1 << ") Move stacklst is not equals to stacklst" << endl;
    }else{
        cout << testnum+1 << ") Move stacklst is equals to stacklst" << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    
    try{
        for(uint i = stkmov.Size(); i>0; i--){
            cout << testnum+1 << ") Insert top value of move StackLst: " << stkmov.Top() << ", in StackLst..." << endl;
            stklst.Push(move(stkmov.TopNPop()));
            testnum++;
        }
        cout << "Size of move StackLst: " << stkmov.Size() << endl;
    }catch(const bad_alloc& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }catch(const length_error& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }


    try{
        cout << "Size of StackLst: " << stklst.Size() << endl;
        for(uint i = stklst.Size(); i > 0; i--){
            cout << testnum+1 <<") Top of StackLst is " << stklst.TopNPop() << ", remove..." << endl;
            testnum++;
        }  
        cout << "Size of StackLst: " << stklst.Size() << endl;
    }catch(const length_error& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }


    cout << "---------------------------------End of test StackList<float>---------------------------------" << endl; 
}

void testStackListString(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on StackList<string>---------------------------------" << endl;

        lasd::SortableVector<string> vec(5);

        // Genera valori casuali e popola lo stack
        std::string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        std::default_random_engine gen(std::random_device{}());
        std::uniform_int_distribution<int> randPos(0, table.size()-1);
        cout << "New SortableVector<string>: ";
        try{
            for (uint i = 0; i < vec.Size(); ++i) {
                vec[i] = table[randPos(gen)];
            }
        }catch (const out_of_range& e) {
            std::cout << "\"" << e.what() << "\": " << "Error!" << std::endl;
        }
        vec.Sort();
        vec.Traverse(&TraversePrint<string>);
        cout << endl;


        cout << "Copy of vec in a StackLst<string>..." << endl; 
        lasd::StackLst<string> stklst(vec);

        //Controllo che la move list sia vuota
        bool chk = stklst.Empty();
        cout << testnum+1 << ") StackLst is " << (chk ? "" : "not ") << "empty" << endl;
        if (chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;

        try{
            for(uint i = stklst.Size(); i > 0; i--){
                cout << testnum+1 << ") Top element of Staklst is: " << stklst.TopNPop() << ", remove..." << endl;
                testnum++;
            }
        }catch(const length_error& e){
            cout << e.what() << endl;
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }

        //Controllo che la move list sia vuota
        chk = stklst.Empty();
        cout << testnum+1 << ") StackLst is " << (chk ? "" : "not ") << "empty" << endl;
        if (!chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;

        try{
            cout << "Move Push of vec's elements in StackLst..." << endl;
            for(uint i = 0; i < vec.Size(); i++){
                stklst.Push(move(vec[i]));
                cout << testnum+1 << ") Insert... StackLst Top value: " << stklst.Top() << endl;
                testnum++;
            }
        }catch(const length_error& e){
            cout << e.what() << endl;
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }catch(const out_of_range& e){
            cout << e.what() << endl;
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }

        stklst.Clear();

        cout << "Clear of StackLst..." << endl;
        //Controllo che la move list sia vuota
        chk = stklst.Empty();
        cout << testnum+1 << ") StackLst is " << (chk ? "" : "not ") << "empty" << endl;
        if (!chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;


    cout << "---------------------------------End of test StackList<string>---------------------------------" << endl;

}



void testQueueVecFloat(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on QueueVec<float>---------------------------------" << endl;
    lasd::QueueVec<float> quelst;

    // Controllo size del contenitore
    cout << "QueueVec<float> with size: " << quelst.Size() << endl;


    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Head element: " << quelst.Head() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const std::length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    

    cout << "---------------------------------End of test QueueVec<float>---------------------------------" << endl;
}

void testQueueVecString(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on QueueVec<string>---------------------------------" << endl;


    cout << "---------------------------------End of test QueueVec<string>---------------------------------" << endl;
}

void testQueueListFloat(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on QueueList<float>---------------------------------" << endl;


    cout << "---------------------------------End of test QueueList<float>---------------------------------" << endl;
}

void testQueueListString(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on QueueList<string>---------------------------------" << endl;


    cout << "---------------------------------End of test QueueList<string>---------------------------------" << endl;
}
