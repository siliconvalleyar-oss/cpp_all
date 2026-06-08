#include <iostream>
#include <stdint.h>
#include <memory>
#include <vector>
#include "cabin.h"



namespace ANIMALS{

    using cab = PEAJE::Cabina_t<int>;
    
    template <typename A ,typename B >
    struct Animals_t :public cab{
        Animals_t():cab(0), m_a{3} , m_b{1} {
            std::cout<<"struct Animals_t :public cab"<<std::endl;

        }
        ~Animals_t()=default;


        void set(){}
        A getA() { return m_a; }   // getter
        B getB() { return m_b; }   // getter
        private:
            const A m_a;
            const B m_b;
    };

}



namespace HOME{
    template<typename T>
    class Home_t: public ANIMALS::Animals_t<T,T>{
            T m_value;
        public:
            Home_t():m_value(0){

                std::cout<<"class Home_t: public ANIMALS::Animals_t<T,T>"<<std::endl;

            };
            ~Home_t()=default;

            T get(){

        return static_cast<T>(m_value - 1);
            }

            void print_value(){

                auto tmp=get();
                std::cout<< "value: "<< tmp <<std::endl;
            }


    };

}

int main(){

std::vector<HOME::Home_t<int> > home;
 home.emplace_back();   // Llama al constructor Home_t<int>()
    // O bien: home.push_back(HOME::Home_t<int>());

    // Acceder al primer elemento (índice 0) e imprimir su valor
    home[0].print_value();
home.push_back(HOME::Home_t<int>());
    // También puedes añadir más elementos:
    home.emplace_back();   // segundo elemento
    home[1].print_value();

    return 0;
}
