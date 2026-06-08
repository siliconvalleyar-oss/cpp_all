#pragma once 

namespace PEAJE{

    template<typename T>
    struct Cabina_t{

        Cabina_t(T tmp):m_id{tmp}{
           

            std::cout<<"Cabina_t(T tmp):m_id{tmp}  : " << id <<std::endl;
            id++;
        }
        ~Cabina_t()=default;


        private:
            int m_id{0};
            std::string client{};
            inline static int id {0};
    };

}