#include<iostream>
#include<cstring>
class product{
    private:
        char* name;
    public:
        product(){
            this->name = new char[strlen("unknown") + 1];
            strcpy(this->name , "unknown");
        }
        product(const char* name){
            this->name = new char[strlen(name) + 1];
            strcpy(this->name , name);
        }
        void free(){
            delete []this->name;
        }
        ~product(){
            free();
        }
        void setName(const char* name){
            delete[] this->name;
            this->name = new char[strlen(name) + 1];
            strcpy(this->name , name);
        }
        const char* getName() const {
            return this->name;
        }
        void copyFrom(const product& other){
            name = new char[ strlen( other.getName() ) + 1 ];
            strcpy(this->name , other.getName() );
        }
        product&  operator=(const product& other){
            if(this != &other){
                free();
                copyFrom(other);
            }
            return *this;
        }

};
class restrant{
    private:
        const unsigned int maxNameSize = 25;
        //char name[maxNameSize];
        product* products;
        int numberOfProducts = 0;
        int arraySize = 16;
    public:
        restrant(){
            product* products = new product[this->arraySize];
        }

        void addProduct(const product& newItem){
            if(arraySize <= (this->numberOfProducts) + 1 ){
                this->arraySize = this->arraySize*2;

                product* productsBuff = new product[arraySize];

                for(int i = 0; i<numberOfProducts; i++){
                    productsBuff[i] = products[i];
                }


                free();
                this->numberOfProducts++;
                this->products = productsBuff;

                products[numberOfProducts] = newItem;
                productsBuff = nullptr;

            }else{
                //std::cout<<newItem.getName();
                //std::cout<< ( products[0].getName() );

                products[numberOfProducts] = newItem;
                this->numberOfProducts++;
                //std::cout<<newItem.getName();
                //std::cout<<products[0].getName();
            }

        }
        void free(){
            delete []this->products;
        }
        void listProducts()const {
            //std::cout<<this->numberOfProducts;
            for(int i = 0; i < this->numberOfProducts; i++){

                std::cout<<i<<". "<<products[i].getName()<<std::endl;
            }
        }
};

int main(){
    product A("A");
    product B("B");
    product C("C");
    A.setName("AA");
    //std::cout<<A.getName();
    restrant X;
    X.addProduct(A);
    //X.addProduct(B);
    //X.addProduct(C);
    //X.listProducts();

}
