
namespace lasd {

/* ************************************************************************** */

class Hashable<int>{
    public:

        unsigned long operator()(const int& data) const noexcept{
            return (data * data);
        }
};

class Hashable<double>{
    public:
    
        unsigned long operator()(const double& data) const noexcept{
            long intgpart = floor(data); //Prendo la parte intera
            long fracpart = pow(2, 24) * (data - intgpart); //Rimuovo la parte intera e prendo solo la mobile rendendola come un intero attraverso la potenza o uno shift
            return (intgpart * fracpart);
        }
};


class Hashable<std::string>{
    //Va visto come un hash di array: sommare tutti gli hash dei dati, ma dato che stringhe diverse con stessi caratteri danno stesso valor (a+b+c) = (c+b+a), devo trattare in modo diverso
    //Quello che facciamo è Prendere il dato, sommarlo all'hash e shiftarlo di 5, partendo con un valore a caso dell'hash (5381: magic key, spesso utilizzato in molte librerie)
    // 
    public:
    
        unsigned long operator()(const std::string& data) const noexcept{
            unsigned long hash = 5381;
            for(unsigned long i = 0; i < data.length(); ++i){
                hash = (hash << 5) + data[i];
            }
            return hash;
        }
};


template <typename Data>
unsigned long HashTable<Data>::HashKey(const Data& dat) const noexcept{
    return HashKey(enchash(dat));
}


template <typename Data>
unsigned long HashTable<Data>::HashKey(const unsigned long key) const noexcept {
    return (((a * key + b) % prime) % tablesize);
}


/* ************************************************************************** */

}
