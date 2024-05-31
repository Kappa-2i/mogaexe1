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

#include "../binarytree/binarytree.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../bst/bst.hpp"

#include "../hashtable/hashtable.hpp"
#include "../hashtable/opnadr/htopnadr.hpp"
#include "../hashtable/clsadr/htclsadr.hpp"

#include "../zlasdtest/hashtable/hashtable.hpp"
#include "../zlasdtest/container/container.hpp"
#include "../zlasdtest/container/linear.hpp"
#include "../zlasdtest/container/testable.hpp"
#include "../zlasdtest/container/dictionary.hpp"

#include "../zlasdtest/iterator/iterator.hpp"

#include "../zlasdtest/vector/vector.hpp"

#include "../zlasdtest/list/list.hpp"

#include "../zlasdtest/binarytree/binarytree.hpp"



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
        cout << endl << "Pick the data structure:\n 1-Vector\n 2-List \n 3-Stack \n 4-Queue \n 5-BinaryTree/Iterator \n \n 6-Various \n 0-Exit for results." << endl;
        cin >> choice;
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
            case 5:
                choiceBinaryTreeType(testerr, testnum, numerr);
                break;  
            case 6:
                testhash(testerr, testnum, numerr);
                break;
            case 7:
                testhash2(testerr, testnum, numerr);
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


    cout << "Pick the data type: \n 1-Int \n 2-Double \n 3-String" << endl;
    int choice = 1;
    
    cin >> choice;
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
            cout << "Invalid choice" << endl;
    }
    
}

void choiceListType(uint& testerr, uint& testnum, stringstream& numerr){


    cout << "Pick the data type: \n 1-Int \n 2-Double \n 3-String" << endl;
    int choice = 1;
    
    cin >> choice;
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
            cout << "Invalid choice" << endl;
    }
    
}

void choiceStackType(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "Pick the data type: \n 1-StackVec<float> \n 2-StackVec<string> \n 3-StackList<float> \n 4-StackList<string>" << endl;
    int choice = 1;
    
    cin >> choice;
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
            cout << "Invalid choice" << endl;
    }
}

void choiceQueueType(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "Pick the data type: \n 1-QueueVec<float> \n 2-QueueVec<string> \n 3-QueueList<float> \n 4-QueueList<string>" << endl;
    int choice = 1;
    
    cin >> choice;
    switch(choice){
        case 1:{
            testQueueVecFloat(testerr, testnum, numerr);
            break;
        }
        case 2:{
            testQueueVecString(testerr, testnum, numerr);
            break;
        }
        case 3:{
            testQueueListFloat(testerr, testnum, numerr);
            break;
        }
        case 4:{
            testQueueListString(testerr, testnum, numerr);
            break;
        }
        default:
            cout << "Invalid choice" << endl;
    }
}



void choiceBinaryTreeType(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "Pick the data type: \n 1-BinaryTreeVec<float> \n 2-BinaryTreeVec<string> \n 3-BinaryTreeLnk<float> \n 4-BinaryTreeLnk<string> \n 5-BST<float> \n 6-BST<string>" << endl;
    int choice = 1;
    
    cin >> choice;
    switch(choice){
        case 1:{
            testBinaryTreeVecFloat(testerr, testnum, numerr);
            break;
        }
        case 2:{
            testBinaryTreeVecString(testerr, testnum, numerr);
            break;
        }
        case 3:{
            testBinaryTreeLnkFloat(testerr, testnum, numerr);
            break;
        }
        case 4:{
            testBinaryTreeLnkString(testerr, testnum, numerr);
            break;
        }
        case 5:{
            //testBSTFloat(testerr, testnum, numerr);
            break;
        }
        case 6:{
            //testBSTString(testerr, testnum, numerr);
            break;
        }
        default:
            cout << "Invalid choice" << endl;
    }
}



void testVectorInt(uint& testerr, uint& testnum, stringstream& numerr){
    
    cout << "---------------------------------Test on Vector<int>---------------------------------" << endl;

    lasd::SortableVector<int> vec;
    
    // Controllo size del contenitore
    cout << "Vector<int> with size: " << vec.Size() << endl;

    // Verifica che il contenitore sia vuoto
    bool chk = vec.Empty();
    cout << testnum+1 << ") Vector is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Stampa della somma degli elementi del contenitore in PostOrderFold
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
    } catch (const length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Back value is: " << vec.Back() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Value at index 1 is: " << vec[1] << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const out_of_range& e) {
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


    //Test per il Resize e il popolamento del contenitore
    try{
      vec.Resize(5);
      cout << testnum+1 << ") Resize... New vector size: "<< vec.Size() << endl;
    }catch(const bad_alloc& e){
      cout << e.what() << endl;
      testerr += 1;
      numerr << testnum +1 << " ";
    }
    testnum++;

    
    // Genera numeri casuali e popola il contenitore
    default_random_engine gen(random_device{}());
    uniform_int_distribution<int> dist(-500, 500);
    for (uint i = 0; i < vec.Size(); ++i) {
        vec[i] = dist(gen);
    }

    // Riconferma che il contenitore non sia vuoto dopo aver aggiunto gli elementi
    chk = vec.Empty();
    cout << testnum+1 <<") Vector is " << (chk ? "" : "not ") << "empty after filling" << endl;
    if (chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;
    

    //Stampa del contenitore in PreOrderTraverse
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


    //Stampa della somma degli elementi del contenitore in PreOrderFold
    
    try{
        int sum = vec.PreOrderFold(&FoldAdd<int>, 0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    // Sort del contenitore, con stampa
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

    //Test per il Resize del contenitore
    
    try{
      vec.Resize(3);
      cout << testnum+1 << ") Resize... New vector size: "<< vec.Size() << endl;
    }catch(const bad_alloc& e){
      cout << e.what() << endl;
      testerr += 1;
      numerr << testnum +1 << " ";
    }
    testnum++;

     //Stampa del contenitore in PreOrderTraverse
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


    //Stampa della somma degli elementi del contenitore in PostOrderFold
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
    
    // Controllo size del contenitore
    cout << "Vector<double> with size: " << vec.Size() << endl;

    // Verifica che il contenitore sia vuoto
    bool chk = vec.Empty();
    cout << testnum+1 << ") Vector is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Stampa della somma degli elementi del contenitore in PostOrderFold
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
    } catch (const length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Back value is: " << vec.Back() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Value at index 1 is: " << vec[1] << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const out_of_range& e) {
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


    //Test per il Resize e il poplamento del contenitore
    try{
      vec.Resize(5);
      cout << testnum+1 << ") Resize... New vector size: "<< vec.Size() << endl;
    }catch(const bad_alloc& e){
      cout << e.what() << endl;
      testerr += 1;
      numerr << testnum +1 << " ";
    }
    testnum++;

    // Genera numeri casuali e popola il contenitore
    default_random_engine gen(random_device{}());
    uniform_real_distribution<double> dist(-500, 500);
    for (uint i = 0; i < vec.Size(); ++i) {
        vec[i] = dist(gen);
    }

    // Riconferma che il contenitore non sia vuoto dopo aver aggiunto gli elementi
    chk = vec.Empty();
    cout << testnum+1 <<") Vector is " << (chk ? "" : "not ") << "empty after filling" << endl;
    if (chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;
    

    //Stampa del contenitore in PreOrderTraverse
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


    //Stampa della somma degli elementi del contenitore in PreOrderFold
    try{
        double sum = vec.PreOrderFold(&FoldAdd<double>, 0.0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    // Sort del contenitore e stampa
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

    //Test per il Resize del contenitore
    
    try{
      vec.Resize(3);
      cout << testnum+1 << ") Resize... New vector size: "<< vec.Size() << endl;
    }catch(const bad_alloc& e){
      cout << e.what() << endl;
      testerr += 1;
      numerr << testnum +1 << " ";
    }
    testnum++;

    //Stampa del contenitore in PreOrderTraverse
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


    //Stampa della somma degli elementi del contenitore in PostOrderFold
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

    // Controllo size del contenitore
    cout << "Vector<string> with size: " << vec.Size() << endl;

    // Verifica che il contenitore sia vuoto
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

    //Test per il Resize e il popolamento del contenitore
    try{
      vec.Resize(5);
      cout << testnum+1 << ") Resize... New vector size: "<< vec.Size() << endl;
    }catch(const bad_alloc& e){
      cout << e.what() << endl;
      testerr += 1;
      numerr << testnum +1 << " ";
    }
    testnum++;


    // Genera caratteri casuali e popola il contenitore
    string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    default_random_engine gen(random_device{}());
    uniform_int_distribution<int> randPos(0, table.size()-1);
    for (uint i = 0; i < vec.Size(); ++i) {
        vec[i] = table[randPos(gen)];
    }

    //Stampa del contenitore in PreOrderTraverse
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

    // Sort del contenitore e stampa
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

    //Stampa della somma degli elementi del contenitore in PreOrderFold
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
        cout << "\t" << "Copy of vec in movvec..." << endl;
        cout << testnum+1 << ") Print copy vec in PreOrderTraverse: " << endl << "\t";
        copvec.PreOrderTraverse(&TraversePrint<string>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Stampa del contenitore in PreOrderTraverse
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
        cout << "\t" << "Move of vec in movvec..." << endl;
        cout << testnum+1 << ") Print move vec in PreOrderTraverse: " << endl << "\t";
        movvec.PreOrderTraverse(&TraversePrint<string>);   
        cout << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    // Verifica che il contenitore sia vuoto
    chk = vec.Empty();
    cout << testnum+1 << ") Vector is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Stampa del contenitore in PreOrderTraverse
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

    // Verifica che il contenitore sia vuoto
    chk = copvec.Empty();
    cout << testnum+1 << ") Copy vec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    // Verifica che il contenitore sia vuoto
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

     // Controllo size del contenitore
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
    catch(const length_error& e)
    {
        cout << e.what() << endl;
    }
    testnum++;

    //Verifica per prendere un elemento in coda
    try
    {
        cout << testnum+1 << ") Value in back is: " << lst.Back();
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    catch(const length_error& e)
    {
        cout << e.what() << endl;
    }
    testnum++;
    
    // Genera numeri casuali e popola il contenitore
    cout << testnum+1 << ") Insert random number in back..." << endl;
    default_random_engine gen(random_device{}());
    uniform_int_distribution<int> dist(-500, 500);
    for (uint i = 0; i < 5; ++i) {
        try{
            lst.InsertAtBack(dist(gen));
        }catch(const bad_alloc& e){
            cout << e.what() << endl;
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
    // Genera numeri casuali e popola il contenitore
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

    //aggiunge elementi del contenitore nella lista
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

    //Controlla che la lista non sia vuota
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
    }catch(const length_error& e){
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
    }catch(const length_error& e){
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
    string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    default_random_engine gen(random_device{}());
    uniform_int_distribution<int> randPos(0, table.size()-1);
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


    //Stampa della somma degli elementi del contenitore in PreOrderFold
    try{
        string conc = lst.PreOrderFold(&FoldAdd<string>, string(""));
        cout << testnum+1 << ") Concatenate list in pre order: " << conc << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;


    //Stampa della somma degli elementi del contenitore in PreOrderFold
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
    }catch(const length_error& e){
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
    }catch(const length_error& e){
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
    cout << "Move vec in a Move List..." << endl;
    
    //Stampa della somma degli elementi del contenitore in PreOrderFold
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
    } catch (const length_error& e) {
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
    }catch (exception & e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " ";
    }

    // Controllo size del contenitore
    cout << "StackVec<float> with size: " << stkvec.Size() << endl;


    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Top value is: " << stkvec.Top() << endl;
    } catch (const length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Pop from the stack the top value:" << stkvec.Top() << endl;
        stkvec.Pop();
    } catch (const length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Top value is: " << stkvec.Top() << endl;
    } catch (const length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << "Clear of StackVec..." << endl;
    stkvec.Clear();

    //Controllo che il contenitore sia vuoto
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
    cout << "---------------------------------Test on StackVec<string>---------------------------------" << endl;
    lasd::StackVec<string> stkvec;
    // Controllo size del contenitore
    cout << "StackVec<string> with size: " << stkvec.Size() << endl;

    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Top value is: " << stkvec.Top() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    // Genera valori casuali e popola lo stack
    string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    default_random_engine gen(random_device{}());
    uniform_int_distribution<int> randPos(0, table.size()-1);
    try{
        for (uint i = 0; i < 5; ++i) {
            string val = string(1, table[randPos(gen)]);
            cout << testnum+1 << ") Push on the stack of the value: " << val << endl;
            stkvec.Push(val);
            testnum++;
        }
    }catch (exception & e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " ";
    }

    // Controllo size del contenitore
    cout << "StackVec<string> with size: " << stkvec.Size() << endl;


    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Top value is: " << stkvec.Top() << endl;
        
    } catch (const length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << "Copy of stackvec..." << endl;
    lasd::StackVec<string> stkcpy(stkvec);

    // Controllo size del contenitore
    cout << "StackVec copy with size: " << stkcpy.Size() << endl;

    // Test quando il contenitore è pieno
    try {
        cout << testnum+1 << ") Top value of copy stackvec is: " << stkcpy.Top() << endl;
        
    } catch (const length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Controllo uguaglianza di copy stack e move stack
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

    // Controllo size del contenitore
    cout << "StackVec move with size: " << stkmov.Size() << endl;

    // Test quando il contenitore è pieno
    try {
        cout << testnum+1 << ") Top value of move stackvec is: " << stkmov.Top() << endl;
        
    } catch (const length_error& e) {
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
    } catch (const length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    //Controllo che il contenitore sia vuoto
    bool chk = stkvec.Empty();
    cout << testnum+1 << ") StackVec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;


    //Controllo uguaglianza di move stack e stack
    if(stkmov != stkvec){
        cout << testnum+1 << ") Move stackvec is not equals to stackvec" << endl;
    }else{
        cout << testnum+1 << ") Move stackvec is equals to stackvec" << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    //Controllo uguaglianza di copy stack e move stack
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

    //Controllo che il copy stack sia vuoto
    chk = stkcpy.Empty();
    cout << testnum+1 << ") Copy StackVec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;


    cout << "Clear of Copy StackVec..." << endl;
    stkmov.Clear();

    //Controllo che il move stack sia vuoto
    chk = stkmov.Empty();
    cout << testnum+1 << ") Move StackVec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << "---------------------------------End of test StackVec<string>---------------------------------" << endl;

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
    } catch (const length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    lasd::SortableVector<float> vec(5);
    // Genera numeri casuali e popola il contenitore
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
    } catch (const length_error& e) {
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
    } catch (const length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;

    // Test quando il contenitore non è vuoto
    try {
        cout << testnum+1 << ") TopNPop from the move stack with value: " << stkmov.TopNPop() << endl;
    } catch (const length_error& e) {
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

    //Sposto gli elementi dal move stack allo stack
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

    //Controllo elemento in testa e poi lo rimuovo
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
        string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        default_random_engine gen(random_device{}());
        uniform_int_distribution<int> randPos(0, table.size()-1);
        cout << "New SortableVector<string>: ";
        try{
            for (uint i = 0; i < vec.Size(); ++i) {
                vec[i] = table[randPos(gen)];
            }
        }catch (const out_of_range& e) {
            cout << e.what() << endl;
        }
        vec.Sort();
        vec.Traverse(&TraversePrint<string>);
        cout << endl;


        cout << "Copy of vec in a StackLst<string>..." << endl; 
        lasd::StackLst<string> stklst(vec);

        //Controllo che il contenitore sia vuoto
        bool chk = stklst.Empty();
        cout << testnum+1 << ") StackLst is " << (chk ? "" : "not ") << "empty" << endl;
        if (chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;

        //Controllo l'elemento in testa e poi lo rimuovo
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

        //Controllo che il contenitore sia vuoto
        chk = stklst.Empty();
        cout << testnum+1 << ") StackLst is " << (chk ? "" : "not ") << "empty" << endl;
        if (!chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;

        //Inserisco nello stack gli elementi del vettore con Push move
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
        //Controllo che il contenitore sia vuoto
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
    lasd::QueueVec<float> quevec;

    // Controllo size del contenitore
    cout << "QueueVec<float> with size: " << quevec.Size() << endl;


    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Head element: " << quevec.Head() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;


    // Genera numeri casuali e popola la queue
    default_random_engine gen(random_device{}());
    uniform_real_distribution<float> dist(-500, 500);
    try{
        for (uint i = 0; i < 5; ++i) {
            float val = dist(gen);
            cout << testnum+1 << ") Enqueue of the value: " << val << endl;
            quevec.Enqueue(val);
            testnum++;
        }
    }catch (const exception& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " ";
    }

    // Controllo size del contenitore
    cout << "QueueVec<float> with size: " << quevec.Size() << endl;


    cout << "Copy of Quevec..." << endl;
    lasd::QueueVec<float> quecpy(quevec);

    //Controllo uguaglianza di queuevec e copy queuevec
    if(quevec == quecpy){
        cout << testnum+1 << ") Copy Quevec is equals to Quevec" << endl;
    }else{
        cout << testnum+1 << ") Copy Quevec is not equals to Quevec" << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    // Test quando il contenitore non è vuoto
    try {
        cout << testnum+1 << ") Head element of Copy: " << quecpy.HeadNDequeue() << ", remove..." <<  endl;
    } catch (const length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Confronto elementi in testa dei due contenitori
    if(quevec.Head() != quecpy.Head()){
        cout << testnum+1 << ") Both head elements are not equal" << endl;
    }else{
        cout << testnum+1 << ") Both head elements are equal" << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    
    try{
        cout << testnum+1 << ") Clear of Quevec and copy..." << endl;
        quevec.Clear();
        quecpy.Clear();
    }catch(const bad_alloc& e){
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    // Verifica che il contenitore sia vuoto
    bool chk = quevec.Empty();
    cout << testnum+1 << ") Quevec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    // Verifica che il contenitore sia vuoto
    chk = quecpy.Empty();
    cout << testnum+1 << ") Copy Quevec is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;


    cout << "---------------------------------End of test QueueVec<float>---------------------------------" << endl;
}

void testQueueVecString(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on QueueVec<string>---------------------------------" << endl;
    
    lasd::SortableVector<string> vec(5);

        // Genera valori casuali e popola lo stack
        string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        default_random_engine gen(random_device{}());
        uniform_int_distribution<int> randPos(0, table.size()-1);
        cout << "New SortableVector<string>: ";
        try{
            for (uint i = 0; i < vec.Size(); ++i) {
                vec[i] = table[randPos(gen)];
            }
        }catch (const out_of_range& e) {
            cout << e.what() << endl;
        }
        vec.Sort();
        vec.Traverse(&TraversePrint<string>);
        cout << endl;


        cout << "Copy of vec in a QueVec<string>..." << endl; 
        lasd::QueueVec<string> quevec(vec);

        //Controllo che la move list sia vuota
        bool chk = quevec.Empty();
        cout << testnum+1 << ") QueVec is " << (chk ? "" : "not ") << "empty" << endl;
        if (chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;

        try{
            for(uint i = quevec.Size(); i > 0; i--){
                cout << testnum+1 << ") Head element of QueVec is: " << quevec.HeadNDequeue() << ", remove..." << endl;
                testnum++;
            }
        }catch(const length_error& e){
            cout << e.what() << endl;
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }

        //Controllo che la move list sia vuota
        chk = quevec.Empty();
        cout << testnum+1 << ") QueVec is " << (chk ? "" : "not ") << "empty" << endl;
        if (!chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;


        cout << "Move of vec in QueVec..." << endl; 
        lasd::QueueVec<string> quemov (move(vec));

        //Controllo che la move list sia vuota
        chk = quemov.Empty();
        cout << testnum+1 << ") Move QueVec is " << (chk ? "" : "not ") << "empty" << endl;
        if (chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;

        //Controllo elemento in testa e rimozione
        try{
            for(uint i = quemov.Size(); i > 0; i--){
                cout << testnum+1 << ") Head element of Move QueVec is: " << quemov.HeadNDequeue() << ", remove..." << endl;
                testnum++;
            }
        }catch(const length_error& e){
            cout << e.what() << endl;
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++; 

    cout << "---------------------------------End of test QueueVec<string>---------------------------------" << endl;
}

void testQueueListFloat(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on QueueList<float>---------------------------------" << endl;
    lasd::QueueLst<float> quelst;

    // Controllo size del contenitore
    cout << "QueueLst<float> with size: " << quelst.Size() << endl;


    // Test quando il contenitore è vuoto
    try {
        cout << testnum+1 << ") Head element: " << quelst.Head() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    } catch (const length_error& e) {
        cout << e.what() << endl;
    }
    testnum++;


    // Genera numeri casuali e popola la queue
    default_random_engine gen(random_device{}());
    uniform_real_distribution<float> dist(-500, 500);
    try{
        for (uint i = 0; i < 5; ++i) {
            float val = dist(gen);
            cout << testnum+1 << ") Enqueue of the value: " << val << endl;
            quelst.Enqueue(val);
            testnum++;
        }
    }catch (exception& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " ";
    }

    // Controllo size del contenitore
    cout << "QueueLst<float> with size: " << quelst.Size() << endl;


    cout << "Copy of QueueLst..." << endl;
    lasd::QueueLst<float> quecpy(quelst);

    //Controllo uguaglianza di queuevec e copy queuevec
    if(quelst == quecpy){
        cout << testnum+1 << ") Copy QueueLst is equals to QueueLst" << endl;
    }else{
        cout << testnum+1 << ") Copy QueueLst is not equals to QueueLst" << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    // Test quando il contenitore non è vuoto
    try {
        cout << testnum+1 << ") Head element of Copy: " << quecpy.HeadNDequeue() << ", remove..." <<  endl;
    } catch (const length_error& e) {
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    //Confronto elementi in testa dei due contenitori
    if(quelst.Head() != quecpy.Head()){
        cout << testnum+1 << ") Both head elements are not equal" << endl;
    }else{
        cout << testnum+1 << ") Both head elements are equal" << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    
    try{
        cout << testnum+1 << ") Clear of QueueLst and copy..." << endl;
        quelst.Clear();
        quecpy.Clear();
    }catch(const bad_alloc& e){
        cout << e.what() << endl;
        testerr += 1; 
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    // Verifica che il contenitore sia vuoto
    bool chk = quelst.Empty();
    cout << testnum+1 << ") QueueLst is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    // Verifica che il contenitore sia vuoto
    chk = quecpy.Empty();
    cout << testnum+1 << ") Copy QueueLst is " << (chk ? "" : "not ") << "empty" << endl;
    if (!chk) {
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << "---------------------------------End of test QueueList<float>---------------------------------" << endl;
}

void testQueueListString(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on QueueList<string>---------------------------------" << endl;

    lasd::SortableVector<string> vec(5);

        // Genera valori casuali e popola il contenitore
        string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        default_random_engine gen(random_device{}());
        uniform_int_distribution<int> randPos(0, table.size()-1);
        cout << "New SortableVector<string>: ";
        try{
            for (uint i = 0; i < vec.Size(); ++i) {
                vec[i] = table[randPos(gen)];
            }
        }catch (const out_of_range& e) {
            cout << e.what() << endl;
        }
        vec.Sort();
        vec.Traverse(&TraversePrint<string>);
        cout << endl;


        cout << "Copy of vec in a QueLst<string>..." << endl; 
        lasd::QueueLst<string> quelst(vec);

        //Controllo che il contenitore sia vuoto
        bool chk = quelst.Empty();
        cout << testnum+1 << ") QueLst is " << (chk ? "" : "not ") << "empty" << endl;
        if (chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;

        //Controllo elemento in testa e rimozione
        try{
            for(uint i = quelst.Size(); i > 0; i--){
                cout << testnum+1 << ") Head element of QueLst is: " << quelst.HeadNDequeue() << ", remove..." << endl;
                testnum++;
            }
        }catch(const length_error& e){
            cout << e.what() << endl;
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }

        //Controllo che il contenitore sia vuoto
        chk = quelst.Empty();
        cout << testnum+1 << ") QueLst is " << (chk ? "" : "not ") << "empty" << endl;
        if (!chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;


        cout << "Move of vec in QueLst..." << endl; 
        lasd::QueueLst<string> quemov (move(vec));

        //Controllo che il contenitore sia vuoto
        chk = quemov.Empty();
        cout << testnum+1 << ") Move QueLst is " << (chk ? "" : "not ") << "empty" << endl;
        if (chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;

        //Controllo elemento in testa e rimozione
        try{
            for(uint i = quemov.Size(); i > 0; i--){
                cout << testnum+1 << ") Head element of Move QueLst is: " << quemov.HeadNDequeue() << ", remove..." << endl;
                testnum++;
            }
        }catch(const length_error& e){
            cout << e.what() << endl;
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }

        //Controllo che la move list sia vuota
        chk = quemov.Empty();
        cout << testnum+1 << ") Move QueLst is " << (chk ? "" : "not ") << "empty" << endl;
        if (!chk) {
            testerr += 1;
            numerr << testnum + 1 << " "; 
        }
        testnum++;

    cout << "---------------------------------End of test QueueList<string>---------------------------------" << endl;
}



void testBinaryTreeVecFloat(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on BinaryTreeVec<float>---------------------------------" << endl;

    lasd::SortableVector<float> vec(5);
    // Genera numeri casuali e popola il contenitore
    default_random_engine gen(random_device{}());
    uniform_real_distribution<float> dist(-500, 500);
    for (uint i = 0; i < vec.Size(); ++i) {
        vec[i] = dist(gen);
    }
    vec.Sort();
    cout << "New SortableVector<float>: ";
    vec.Traverse(&TraversePrint<float>);
    cout << endl;


    cout << "\tCopy of Sortable Vector in BinaryTreeVec..." << endl;
    lasd::BinaryTreeVec<float> btvec(vec);

    try{
        cout << testnum+1 << ") PreOrderTraverse of BtVec: ";
        btvec.Traverse(&TraversePrint<float>);
        cout << endl;
        testnum++;

        cout << testnum+1 << ") PostOrderTraverse of BtVec: ";
        btvec.PostOrderTraverse(&TraversePrint<float>);
        cout << endl;
        testnum++;

        cout << testnum+1 << ") InOrderTraverse of BtVec: ";
        btvec.InOrderTraverse(&TraversePrint<float>);
        cout << endl;
        testnum++;

        cout << testnum+1 << ") BreadthTraverse of BtVec: ";
        btvec.BreadthTraverse(&TraversePrint<float>);
        cout << endl;
        testnum++;
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }

    try{
        float sum = btvec.Fold(&FoldAdd<float>, 0.0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    cout << testnum+1 << ") BtVec root: ";
    if(btvec.Root().Element() == vec[0]){
        cout << btvec.Root().Element() << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;


    cout << testnum+1 << ") BtVec left child of root: ";
    if(btvec.Root().LeftChild().Element() == vec[1]){
        cout << btvec.Root().LeftChild().Element() << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << testnum+1 << ") BtVec right child of root: ";
    if(btvec.Root().RightChild().Element() == vec[2]){
        cout << btvec.Root().RightChild().Element() << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << testnum+1 << ") BtVec left child of left child of root: ";
    if(btvec.Root().LeftChild().LeftChild().Element() == vec[3]){
        cout << btvec.Root().LeftChild().LeftChild().Element() << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << testnum+1 << ") BtVec right child of left child of root: ";
    if(btvec.Root().LeftChild().RightChild().Element() == vec[4]){
        cout << btvec.Root().LeftChild().RightChild().Element() << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << "\tCopy of BtVec..." << endl;
    lasd::BinaryTreeVec<float> btvecpy(btvec);

    cout << testnum+1 << ") BtVecCopy Root: ";
    if(!btvecpy.Root().IsLeaf()){
        cout << "is not leaf" << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << testnum+1 << ") BtVecCopy Root: ";
    if(btvecpy.Root().HasLeftChild()){
        cout << "has left child" << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;
    
    cout << testnum+1 << ") BtVecCopy Root: ";
    if(btvecpy.Root().HasRightChild()){
        cout << "has right child" << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << testnum+1 << ") BtVecCopy right child of Root: ";
    if(!btvecpy.Root().RightChild().HasLeftChild()){
        cout << "hasn't left child" << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << testnum+1 << ") BtVecCopy right child of Root: ";
    if(!btvecpy.Root().RightChild().HasRightChild()){
        cout << "hasn't right child" << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << testnum+1 << ") BtVecCopy left child of right child of Root: ";
    try
    {
        cout << btvecpy.Root().RightChild().LeftChild().Element() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    catch(const out_of_range& e)
    {
        cout << e.what() << endl;
    }
    testnum++;

    cout << testnum+1 << ") BtVecCopy right child of right child of Root: ";
    try
    {
        cout << btvecpy.Root().RightChild().RightChild().Element() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    catch(const out_of_range& e)
    {
        cout << e.what() << endl;
    }
    testnum++;
    
    lasd::BinaryTreeVec<float> btvec2;
    cout << "\tCopy Assignment of BtVec in BtVec2" << endl;
    btvec2 = btvec;

    cout << testnum+1 <<") BtVec and BtVec2 are: ";
    if(btvec == btvec2){
        cout << "equal" << endl;
    }
    else{
        cout << "not equal" << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    testnum++;


    cout << testnum+1 <<") BtVecCopy and BtVec2 are: ";
    if(btvecpy == btvec2){
        cout << "equal" << endl;
    }
    else{
        cout << "not equal" << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    testnum++;

    try{
        cout << testnum+1 << ") PreOrderTraverse of BtVec2: ";
        btvec2.Traverse(&TraversePrint<float>);
        cout << endl;
        testnum++;

        cout << testnum+1 << ") PostOrderTraverse of BtVec2: ";
        btvec2.PostOrderTraverse(&TraversePrint<float>);
        cout << endl;
        testnum++;

        cout << testnum+1 << ") InOrderTraverse of BtVec2: ";
        btvec2.InOrderTraverse(&TraversePrint<float>);
        cout << endl;
        testnum++;

        cout << testnum+1 << ") BreadthTraverse of BtVec2: ";
        btvec2.BreadthTraverse(&TraversePrint<float>);
        cout << endl;
        testnum++;
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }

    cout << "\tClear of BtVec..." << endl;
    btvec.Clear();
    
    cout << testnum+1 << ") BtVec Root: ";
    try
    {
        cout << btvec.Root().Element() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    catch(const length_error& e)
    {
        cout << e.what() << endl;
    }
    testnum++;

    cout << testnum+1 << ") BtVec Size: ";
    if(btvec.Size() == 0){
        cout <<  btvec.Size() << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    

    cout << "---------------------------------End of test BinaryTreeVec<float>---------------------------------" << endl;

}

void testBinaryTreeVecString(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on BinaryTreeVec<string>---------------------------------" << endl;
    lasd::SortableVector<string> vec(5);
    // Genera valori casuali e popola il contenitore
        string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        default_random_engine gen(random_device{}());
        uniform_int_distribution<int> randPos(0, table.size()-1);
        cout << "New SortableVector<string>: ";
        try{
            for (uint i = 0; i < vec.Size(); ++i) {
                vec[i] = table[randPos(gen)];
            }
        }catch (const out_of_range& e) {
            cout << e.what() << endl;
        }
        vec.Sort();
        vec.Traverse(&TraversePrint<string>);
        cout << endl;

    cout << "\tMove of Sortable Vector in BinaryTreeVec..." << endl;
    lasd::BinaryTreeVec<string> btvec(move(vec));

    try{
        cout << testnum+1 << ") Writing in Root..." << endl;
        btvec.Root().Element() = "S";
        testnum++;

        cout << testnum+1 << ") Writing in LeftChild of Root..." << endl;
        btvec.Root().LeftChild().Element() = "A";
        testnum++;

        cout << testnum+1 << ") Writing in RightChild of Root..." << endl;
        btvec.Root().RightChild().Element() = "L";
        testnum++;

        cout << testnum+1 << ") Writing in LeftChild of LeftChild of Root..." << endl;
        btvec.Root().LeftChild().LeftChild().Element() = "V";
        testnum++;

        cout << testnum+1 << ") Writing in RightChild of LeftChild of Root..." << endl;
        btvec.Root().LeftChild().RightChild().Element() = "E";
        testnum++;
    }
    catch(const length_error& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    catch(const out_of_range& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    


    try{
        cout << "\tNew BreadthIterator of BtVec..." << endl;
        lasd::BTBreadthIterator<string> BrIt(btvec);
        for(*BrIt; !BrIt.Terminated(); BrIt.operator++()){
            cout << testnum+1 << ") BreadthIterator's Value: '" << *BrIt << "', next..." << endl;
            testnum++;
        }
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    
    

    try{
        cout << "\tNew PreOrderIterator of BtVec..." << endl;
        lasd::BTPreOrderIterator<string> PreIt(btvec);
        for(*PreIt; !PreIt.Terminated(); PreIt.operator++()){
            cout << testnum+1 << ") PreOrderIterator's Value: '" << *PreIt << "', next..." << endl;
            testnum++;
        }
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    

    try{
        cout << "\tNew PostOrderIterator of BtVec..." << endl;
        lasd::BTPostOrderIterator<string> PostIt(btvec);
        for(*PostIt; !PostIt.Terminated(); PostIt.operator++()){
            cout << testnum+1 << ") PreOrderIterator's Value: '" << *PostIt << "', next..." << endl;
            testnum++;
        }
        
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    

    try{
        cout << "\tNew InOrderIterator of BtVec..." << endl;
        lasd::BTInOrderIterator<string> InIt(btvec);
        for(*InIt; !InIt.Terminated(); InIt.operator++()){
            cout << testnum+1 << ") PreOrderIterator's Value: '" << *InIt << "', next..." << endl;
            testnum++;
        }
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }

    cout << "\tMove of BtVec..." << endl;
    lasd::BinaryTreeVec<string> btvecmov(move(btvec));

    try{
        cout << "\tBreadthIterator of BtVec..." << endl;
        lasd::BTBreadthIterator<string> BrIt2(btvec);
        if(BrIt2.Terminated()){
            cout << testnum+1 << ") Iterator Terminated" << endl;
        }
        else{
            testerr += 1;
            numerr << testnum + 1 << " ";
        }
        
    }
    catch(exception& e){
        cout << e.what() << endl;
    }
    testnum++;

    lasd::BTBreadthIterator<string> BrIt3(btvecmov);
    try{
        cout << "\tNew BreadthIterator of BtVecMove..." << endl;
        for(*BrIt3; !BrIt3.Terminated(); BrIt3.operator++()){
            cout << testnum+1 << ") BreadthIterator's Value: '" << *BrIt3 << "', next..." << endl;
            testnum++;
        }
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }

    try{
        BrIt3.Reset();
        cout << testnum+1 <<") Reset of BreadthIterator, current value: '" << *BrIt3 << "'" << endl;
        testnum++;
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }

    lasd::BinaryTreeVec<string> btvec2;
    cout << "\tMove Assignment of BtVecMove in BtVec2" << endl;
    btvec2 = move(btvecmov);

    cout << testnum+1 <<") BtVecMove and BtVec2 are:";
    if(btvecmov != btvec2){
        cout << " not equal" << endl;
    }
    else{
        cout << " equal" << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    testnum++;
    
    cout << "\tClear of BtVec2..." << endl;
    btvec2.Clear();

    cout << testnum+1 << ") BtVec2 Size: ";
    if(btvec2.Size() == 0){
        cout <<  btvec2.Size() << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }

    




    cout << "---------------------------------End of test BinaryTreeVec<string>---------------------------------" << endl;

}

void testBinaryTreeLnkFloat(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on BinaryTreeLnk<float>---------------------------------" << endl;

    lasd::SortableVector<float> vec(5);
    // Genera numeri casuali e popola il contenitore
    default_random_engine gen(random_device{}());
    uniform_real_distribution<float> dist(-10, 10);
    for (uint i = 0; i < vec.Size(); ++i) {
        vec[i] = dist(gen);
    }
    vec.Sort();
    cout << "New SortableVector<float>: ";
    vec.Traverse(&TraversePrint<float>);
    cout << endl;


    cout << "\tCopy of Sortable Vector in BinaryTreeLnk..." << endl;
    lasd::BinaryTreeLnk<float> btlnk(vec);

    try{
        cout << testnum+1 << ") PreOrderTraverse of BtLnk: ";
        btlnk.Traverse(&TraversePrint<float>);
        cout << endl;
        testnum++;

        cout << testnum+1 << ") PostOrderTraverse of BtLnk: ";
        btlnk.PostOrderTraverse(&TraversePrint<float>);
        cout << endl;
        testnum++;

        cout << testnum+1 << ") InOrderTraverse of BtLnk: ";
        btlnk.InOrderTraverse(&TraversePrint<float>);
        cout << endl;
        testnum++;

        cout << testnum+1 << ") BreadthTraverse of BtLnk: ";
        btlnk.BreadthTraverse(&TraversePrint<float>);
        cout << endl;
        testnum++;
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum +1 << " ";
    }

    try{
        float sum = btlnk.Fold(&FoldAdd<float>, 0.0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    cout << testnum+1 << ") BtLnk root: ";
    try{
        cout << btlnk.Root().Element() << endl;
    }
    catch(const length_error& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;
    

    cout << "\tCopy of BtLnk..." << endl;
    lasd::BinaryTreeLnk<float> btlnkcpy(btlnk);

    cout << testnum+1 << ") BtLnkCopy Root: ";
    if(!btlnkcpy.Root().IsLeaf()){
        cout << "is not leaf" << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << testnum+1 << ") BtLnkCopy Root: ";
    if(btlnkcpy.Root().HasLeftChild()){
        cout << "has left child" << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;
    
    cout << testnum+1 << ") BtLnkCopy Root: ";
    if(btlnkcpy.Root().HasRightChild()){
        cout << "has right child" << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << testnum+1 << ") BtLnkCopy right child of Root: ";
    if(!btlnkcpy.Root().RightChild().HasLeftChild()){
        cout << "hasn't left child" << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << testnum+1 << ") BtLnkCopy right child of Root: ";
    if(!btlnkcpy.Root().RightChild().HasRightChild()){
        cout << "hasn't right child" << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " "; 
    }
    testnum++;

    cout << testnum+1 << ") BtLnkCopy left child of right child of Root: ";
    try
    {
        cout << btlnkcpy.Root().RightChild().LeftChild().Element() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    catch(const out_of_range& e)
    {
        cout << e.what() << endl;
    }
    testnum++;

    cout << testnum+1 << ") BtLnkCopy right child of right child of Root: ";
    try
    {
        cout << btlnkcpy.Root().RightChild().RightChild().Element() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    catch(const out_of_range& e)
    {
        cout << e.what() << endl;
    }
    testnum++;
    
    lasd::BinaryTreeLnk<float> btlnk2;
    cout << "\tCopy Assignment of BtLnk in BtLnk2" << endl;
    btlnk2 = btlnkcpy;

    cout << testnum+1 <<") BtLnk and BtLnk2 are: ";
    if(btlnk == btlnk2){
        cout << "equal" << endl;
    }
    else{
        cout << "not equal" << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    testnum++;


    cout << testnum+1 <<") BtLnkCopy and BtLnk2 are: ";
    if(btlnkcpy == btlnk2){
        cout << "equal" << endl;
    }
    else{
        cout << "not equal" << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    testnum++;

    try{
        cout << testnum+1 << ") BreadthTraverse of BtLnk2: ";
        btlnk2.BreadthTraverse(&TraversePrint<float>);
        cout << endl;
        testnum++;
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    


    cout << "\tClear of BtLnk..." << endl;
    btlnk.Clear();
    
    cout << testnum+1 << ") BtLnk Root: ";
    try
    {
        cout << btlnk.Root().Element() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    catch(const length_error& e)
    {
        cout << e.what() << endl;
    }
    testnum++;

    try{
        float sum = btlnk.Fold(&FoldAdd<float>, 0.0);
        cout << testnum+1 << ") Sum elements: " << sum << endl;
    } catch(exception& e){
        cout << e.what();
        testerr += 1;
        numerr << testnum +1 << " ";
    }
    testnum++;

    cout << testnum+1 << ") BtLnk Size: ";
    if(btlnk.Size() == 0){
        cout <<  btlnk.Size() << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }




    cout << "---------------------------------End of test BinaryTreeLnk<float>---------------------------------" << endl;

}   

void testBinaryTreeLnkString(uint& testerr, uint& testnum, stringstream& numerr){
    cout << "---------------------------------Test on BinaryTreeLnk<string>---------------------------------" << endl;
    lasd::SortableVector<string> vec(5);
    // Genera valori casuali e popola il contenitore
        string table = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        default_random_engine gen(random_device{}());
        uniform_int_distribution<int> randPos(0, table.size()-1);
        cout << "New SortableVector<string>: ";
        try{
            for (uint i = 0; i < vec.Size(); ++i) {
                vec[i] = table[randPos(gen)];
            }
        }catch (const out_of_range& e) {
            cout << e.what() << endl;
        }
        vec.Sort();
        vec.Traverse(&TraversePrint<string>);
        cout << endl;

    cout << "\tMove of Sortable Vector in BinaryTreeLnk..." << endl;
    lasd::BinaryTreeLnk<string> btlnk(move(vec));

    try{
        cout << testnum+1 << ") Writing in Root..." << endl;
        btlnk.Root().Element() = "S";
        testnum++;

        cout << testnum+1 << ") Writing in LeftChild of Root..." << endl;
        btlnk.Root().LeftChild().Element() = "A";
        testnum++;

        cout << testnum+1 << ") Writing in RightChild of Root..." << endl;
        btlnk.Root().RightChild().Element() = "L";
        testnum++;

        cout << testnum+1 << ") Writing in LeftChild of LeftChild of Root..." << endl;
        btlnk.Root().LeftChild().LeftChild().Element() = "V";
        testnum++;

        cout << testnum+1 << ") Writing in RightChild of LeftChild of Root..." << endl;
        btlnk.Root().LeftChild().RightChild().Element() = "E";
        testnum++;
    }
    catch(const length_error& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    catch(const out_of_range& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    


    try{
        cout << "\tNew BreadthIterator of BtLnk..." << endl;
        lasd::BTBreadthIterator<string> BrIt(btlnk);
        for(*BrIt; !BrIt.Terminated(); BrIt.operator++()){
            cout << testnum+1 << ") BreadthIterator's Value: '" << *BrIt << "', next..." << endl;
            testnum++;
        }
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    
    

    try{
        cout << "\tNew PreOrderIterator of BtVec..." << endl;
        lasd::BTPreOrderIterator<string> PreIt(btlnk);
        for(*PreIt; !PreIt.Terminated(); PreIt.operator++()){
            cout << testnum+1 << ") PreOrderIterator's Value: '" << *PreIt << "', next..." << endl;
            testnum++;
        }
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    

    try{
        cout << "\tNew PostOrderIterator of BtVec..." << endl;
        lasd::BTPostOrderIterator<string> PostIt(btlnk);
        for(*PostIt; !PostIt.Terminated(); PostIt.operator++()){
            cout << testnum+1 << ") PreOrderIterator's Value: '" << *PostIt << "', next..." << endl;
            testnum++;
        }
        
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    

    try{
        cout << "\tNew InOrderIterator of BtVec..." << endl;
        lasd::BTInOrderIterator<string> InIt(btlnk);
        for(*InIt; !InIt.Terminated(); InIt.operator++()){
            cout << testnum+1 << ") PreOrderIterator's Value: '" << *InIt << "', next..." << endl;
            testnum++;
        }
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }

    cout << "\tMove of BtLnk..." << endl;
    lasd::BinaryTreeLnk<string> btlnkmov(move(btlnk));

    try{
        cout << "\tBreadthIterator of BtLnk..." << endl;
        lasd::BTBreadthIterator<string> BrIt2(btlnk);
        if(BrIt2.Terminated()){
            cout << testnum+1 << ") Iterator Terminated" << endl;
        }
        else{
            testerr += 1;
            numerr << testnum + 1 << " ";
        }
        
    }
    catch(exception& e){
        cout << e.what() << endl;
    }
    testnum++;

    lasd::BTBreadthIterator<string> BrIt3(btlnkmov);
    try{
        cout << "\tNew BreadthIterator of BtLnkMove..." << endl;
        for(*BrIt3; !BrIt3.Terminated(); BrIt3.operator++()){
            cout << testnum+1 << ") BreadthIterator's Value: '" << *BrIt3 << "', next..." << endl;
            testnum++;
        }
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }

    try{
        BrIt3.Reset();
        cout << testnum+1 <<") Reset of BreadthIterator, current value: '" << *BrIt3 << "'" << endl;
        testnum++;
    }
    catch(exception& e){
        cout << e.what() << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }

    lasd::BinaryTreeLnk<string> btlnk2;
    cout << "\tMove Assignment of BtLnkMove in BtLnk2" << endl;
    btlnk2 = move(btlnkmov);

    cout << testnum+1 <<") BtLnkMove and BtLnk2 are:";
    if(btlnkmov != btlnk2){
        cout << " not equal" << endl;
    }
    else{
        cout << " equal" << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }
    testnum++;
    
    cout << "\tClear of BtLnk2..." << endl;
    btlnk2.Clear();

    cout << testnum+1 << ") Btlnk2 Size: ";
    if(btlnk2.Size() == 0){
        cout <<  btlnk2.Size() << endl;
    }
    else{
        cout << endl;
        testerr += 1;
        numerr << testnum + 1 << " ";
    }

    cout << "---------------------------------End of test BinaryTreeVec<string>---------------------------------" << endl;
}


void testhash(uint& testerr, uint& testnum, stringstream& numerr){
    
    cout << "---------------------------------HASHISH<int>---------------------------------" << endl;
    // lasd::Vector<int> vec(50);
    // for(unsigned long i = 0; i < vec.Size(); i++){
    //     vec[i] = i;
    // }

    // lasd::HashTableClsAdr<int> ht(vec);
    // lasd::HashTableClsAdr<int> ht2(ht);
    // lasd::HashTableClsAdr<int> ht3(move(ht2));

    // if(ht == ht2){
    //     cout << "Sono uguali" << endl;
    // }
    // else{
    //     cout << "Sono diversi" << endl;
    // }


    // // cout << "Size: " << ht.Size() << endl;
    // // cout << "TableSize: " << ht.tablesize << endl;
    // // cout << "A: " << ht.a << endl;
    // // cout << "B: " << ht.b << endl;

    

    // // cout << "Size: " << ht.Size() << endl;
    // // cout << "TableSize: " << ht.tablesize << endl;
    // // for(unsigned long i = 0; i<ht.tablesize; i++){
    // //     cout << "Lista " << i << ": ";
    // //     ht.table[i].Traverse(&TraversePrint<int>); 
    // //     cout << endl;   
    // // }

    // // ht.Remove(0);
    // // ht.Remove(1);
    // // ht.Remove(2);
    // // ht.Remove(3);
    // // ht.Remove(4);
    // // ht.Remove(5);
    // // ht.Remove(6);
    // // ht.Remove(7);
    // // ht.Remove(8);
    // // ht.Remove(9);

    // // cout << endl << "Size: " << ht.Size() << endl;
    // // cout << "TableSize: " << ht.tablesize << endl;
    // // for(unsigned long i = 0; i<ht.tablesize; i++){
    // //     cout << "Lista " << i << ": ";
    // //     ht.table[i].Traverse(&TraversePrint<int>); 
    // //     cout << endl;   
    // // }

    // // ht.Clear();

    // // cout << endl << "Size: " << ht.Size() << endl;
    // // cout << "TableSize: " << ht.tablesize << endl;

    unsigned int loctestnum = 0, loctesterr = 0;
    cout << endl << "Begin of HashTable<int> Test" << endl;

    cout << endl << "OPN ADR" << endl;

    
    cout << "-------------------------------------------------------------------------------" << endl;
    // try{
 
    //     lasd::Vector<int> vec(126);
    //     for (uint i = 0; i < 126; i++) {
    //     vec[i] = i;
    //     }

    //     lasd::Vector<int> container(63);
    //     for(uint i = 0; i < 63; i++){
    //         container[i] = 2 * i;
    //     }


//    lasd::HashTableOpnAdr<int> htopnadr(100, vec);
//     Size(loctestnum, loctesterr, htopnadr, true, 126); 




//     CountHT(loctestnum, loctesterr, htopnadr, container, 63);

//     for (int i = 0; i < 63; i++){
//         int j = i*2;
//         Remove(loctestnum, loctesterr, htopnadr, vec[j]);
//     }

//     for (int i = 1; i < 126; i += 2) {
//       Exists(loctestnum, loctesterr, htopnadr, true, vec[i]);
//     }

//     for (int i = 0; i < 126; i += 2) {
//       Exists(loctestnum, loctesterr, htopnadr, false, vec[i]);
//     }

//     for (int i = 0; i < 126; i += 2) {
//       InsertC(loctestnum, loctesterr, htopnadr, vec[i]);
//     }
    
//     for (int i = 1; i < 126; i += 2) {
//       Exists(loctestnum, loctesterr, htopnadr, true, vec[i]);
//     }

//     htopnadr.Resize(4001);
//     Size(loctestnum, loctesterr, htopnadr, true, 126);
//     Empty(loctestnum, loctesterr, htopnadr, false);
//     htopnadr.Clear();
//     Empty(loctestnum, loctesterr, htopnadr, true);
//     Size(loctestnum, loctesterr, htopnadr, true, 0);
//     InsertC(loctestnum, loctesterr, htopnadr, vec);
//     Size(loctestnum, loctesterr, htopnadr, true, 126);

//     lasd::HashTableOpnAdr<int> cophtopnadr(htopnadr);
//     EqualHT(loctestnum, loctesterr, cophtopnadr, htopnadr);
//     lasd::HashTableOpnAdr<int> movhtopnadr(std::move(cophtopnadr));
//     EqualHT(loctestnum, loctesterr, movhtopnadr, htopnadr);
//     //NonEqualHT(loctestnum, loctesterr, cophtopnadr, movhtopnadr);
//     cophtopnadr = htopnadr;
//     EqualHT(loctestnum, loctesterr, movhtopnadr, cophtopnadr);
//     lasd::HashTableOpnAdr<int> cop2htopnadr;
//     cop2htopnadr = std::move(cophtopnadr);
//     EqualHT(loctestnum, loctesterr, cop2htopnadr, htopnadr);
//     lasd::HashTableOpnAdr<int> htdimconstropn(90);
//     lasd::HashTableOpnAdr<int> htdimconstropn2(90000);

//     lasd::Vector<int> vec2(10);
//     for (uint i = 0; i < 10; i++) {
//       vec[i] = i;
//     }

    
//     lasd::HashTableOpnAdr<int> htopnadr2(100, vec2);
//     lasd::HashTableOpnAdr<int> htopnadr3(100, std::move(vec2));
//     EqualHT(loctestnum, loctesterr, htopnadr2, htopnadr3);

//     lasd::Vector<int> vec3(10);
//     for (uint i = 0; i < 10; i++){
//       vec[i] = i;
//     }

//     lasd::HashTableOpnAdr<int> htopnadr4(vec3);
//     lasd::HashTableOpnAdr<int> htopnadr5(std::move(vec3));
//     //EqualHT(loctestnum, loctesterr, htopnadr4, htopnadr5);

try{

    cout << endl << endl << "CLS ADR" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    lasd::Vector<int> vec(126);
    for (uint i = 0; i < 126; i++) {
      vec[i] = i;
    }

    lasd::Vector<int> container(63);
    for(uint i = 0; i < 63; i++){
        container[i] = 2 * i;
    }
/* -------------------------------------------------------------------------------------------------- */

    lasd::HashTableClsAdr<int> htclsadr(100, vec);
    Size(loctestnum, loctesterr, htclsadr, true, 126);

    CountHT(loctestnum, loctesterr, htclsadr, container, 63);

    for (int i = 0; i < 63; i++){
        int j = i*2;
        Remove(loctestnum, loctesterr, htclsadr, vec[j]);
    }

    for (int i = 1; i < 126; i += 2) {
      Exists(loctestnum, loctesterr, htclsadr, true, vec[i]);
    }

    for (int i = 0; i < 126; i += 2) {
      Exists(loctestnum, loctesterr, htclsadr, false, vec[i]);
    }

    for (int i = 0; i < 126; i += 2) {
      InsertC(loctestnum, loctesterr, htclsadr, vec[i]);
    }
    
    for (int i = 1; i < 126; i += 2) {
      Exists(loctestnum, loctesterr, htclsadr, true, vec[i]);
    }

    htclsadr.Resize(4001);
    //cout << endl << "table size dopo Resize 4001: " << htclsadr.tableSize << endl;
    Size(loctestnum, loctesterr, htclsadr, true, 126);
    Empty(loctestnum, loctesterr, htclsadr, false);
    htclsadr.Clear();
    cout<< endl << "COPY HT TableSIZE dopo clear "<< htclsadr.tablesize << endl;
    Empty(loctestnum, loctesterr, htclsadr, true);
    Size(loctestnum, loctesterr, htclsadr, true, 0);
    InsertC(loctestnum, loctesterr, htclsadr, vec);
    Size(loctestnum, loctesterr, htclsadr, true, 126);

    lasd::HashTableClsAdr<int> cophtclsadr(htclsadr);
    Size(loctestnum, loctesterr, htclsadr, true, 126);
    cout<< endl << "COPY HT TableSIZE "<< cophtclsadr.tablesize << endl;
    cout<< endl << "COPY HT SIZE " << cophtclsadr.Size() << endl;
    Size(loctestnum, loctesterr, cophtclsadr, true, 126);
    EqualHT(loctestnum, loctesterr, cophtclsadr, htclsadr);
    lasd::HashTableClsAdr<int> movhtclsadr(std::move(cophtclsadr));
    EqualHT(loctestnum, loctesterr, movhtclsadr, htclsadr);
    NonEqualHT(loctestnum, loctesterr, cophtclsadr, movhtclsadr);
    cophtclsadr = htclsadr;
    EqualHT(loctestnum, loctesterr, movhtclsadr, cophtclsadr);
    lasd::HashTableClsAdr<int> cop2htclsadr;
    cop2htclsadr = std::move(cophtclsadr);
    EqualHT(loctestnum, loctesterr, cop2htclsadr, htclsadr);
    lasd::HashTableClsAdr<int> htdimconstr(90);
    lasd::HashTableClsAdr<int> htdimconstr2(90000);

    lasd::Vector<int> vec4(10);
    for (uint i = 0; i < 10; i++) {
      vec[i] = i;
    }

    
    lasd::HashTableClsAdr<int> htclsadr2(100, vec4);
    lasd::HashTableClsAdr<int> htclsadr3(100, std::move(vec4));
    EqualHT(loctestnum, loctesterr, htclsadr2, htclsadr3);

    lasd::Vector<int> vec5(10);
    for (uint i = 0; i < 10; i++){
      vec[i] = i;
    }

    lasd::HashTableClsAdr<int> htclsadr4(vec5);
    lasd::HashTableClsAdr<int> htclsadr5(std::move(vec5));
    //EqualHT(loctestnum, loctesterr, htclsadr4, htclsadr5);



    }catch(...){
        loctestnum++; loctesterr++;
        cout << endl << "Unmanaged error! " << endl;
    }

    cout << endl << "Errori: " << loctesterr  << " Test: " << loctestnum << endl;
    testnum += loctestnum;
    testerr += loctesterr;


    cout << "---------------------------------HASHISH<int>---------------------------------" << endl;

}


void testhash2(uint& testerr, uint& testnum, stringstream& numerr){

    lasd::Vector<int> vec(126);
    for(unsigned long i = 0; i<vec.Size(); i++){
        vec[i] = i;
    }

    lasd::HashTableClsAdr<int> ht(vec);
    cout << "Size ht: " << ht.Size() << endl;
    cout << "TableSize ht: " << ht.tablesize << endl;
    for(unsigned long i = 0; i<ht.tablesize; i++){
        cout << "Lista " << i << ": ";
        ht.table[i].Traverse(&TraversePrint<int>); 
        cout << endl;   
    }


    lasd::HashTableClsAdr<int> ht2(ht);
    cout << "Size ht2: " << ht2.Size() << endl;
    cout << "TableSize ht2: " << ht2.tablesize << endl;
    for(unsigned long i = 0; i<ht2.tablesize; i++){
        cout << "Lista " << i << ": ";
        ht2.table[i].Traverse(&TraversePrint<int>); 
        cout << endl;   
    }

    if(ht == ht2){
        cout << "Sono uguali" << endl;
    }
    else{
        cout << "Sono diversi" << endl;
    }

    cout << "Size ht: " << ht.Size() << endl;
    cout << "TableSize ht: " << ht.tablesize << endl;
    for(unsigned long i = 0; i<ht.tablesize; i++){
        cout << "Lista " << i << ": ";
        ht.table[i].Traverse(&TraversePrint<int>); 
        cout << endl;   
    }

    cout << "Size ht2: " << ht2.Size() << endl;
    cout << "TableSize ht2: " << ht2.tablesize << endl;
    for(unsigned long i = 0; i<ht2.tablesize; i++){
        cout << "Lista " << i << ": ";
        ht2.table[i].Traverse(&TraversePrint<int>); 
        cout << endl;   
    }








}