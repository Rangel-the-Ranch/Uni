#include<iostream>
class interval{
    private:     //проблем ли е да го пишем въпреки че е ненужно?
        int A;
        int B;
        bool ValidInputCheck(){
            if(this->A > this->B){
                setPoints(0,0); //алтернативно може this->a = 0; this->b = 0; ако е проблем "рекурсията";
            }
        }
        bool isItPrime(int& number)const{
            for(int i=2; i<= number/2;i++){   //със cmath може num^(1/2)
                if(number%i == 0){
                    return false;
                }
            }
            return true;
        }
        bool isItPalindrome(int& number){
            /*
            int 
            for(){
                if(number%10 == )
            }
            */
        }
        bool MatchingNumbersCheck(int& number)const{
            bool numbers[10];
            for(int i=1;i<=10;i++){
                numbers[i]=0;
            }
            while (number>0){
                if( numbers[number%10] == 1){
                    return false;
                }else{
                    numbers[number%10]=1;
                    number = number/10;
                }
            }
            return true;
        }
        bool isItPowOfTwo(int& number)const{
            while(number>0){
                if(number%2 == 0){
                    number=number/2;
                }else{
                    return false;
                }
            }
            return true;
        }



    public:
        interval(){
            setPoints(0,0);
        };
        interval(int a, int b){
            setPoints(a,b);
        }
        void setPoints(int a ,int b){ //Ако сложа да взима по референции ми дава проблем с lvalue
            this->A = a;
            this->B = b;
            ValidInputCheck();
        }
        int getA() const{
            return this->A; 
        }
        int getB() const {
            return this->B;
        }
        int getLenght()const{
            return this->B - this->A;
        }
        int primaryNumbersCount()const{
            int counter = 0;
            for(int i=this->A;i<=this->B;i++){
                if(isItPrime(i) == true){ //по оптимизирано търсене??
                    counter++;
                }
            }
            return counter;
        }
        int PalindromeCounter()const{
            int counter = 0;
            int startA = this->A;
            if(this->B < 0){
                return counter;
            }
            if(startA < 0){
                startA = 0;
            }                   //оптимизирам ако има отрицателни числа
            for(int i=startA;i<=this->B;i++){
                ////////////////////////////////////////////////
            }
            return counter;

        }
        int matchingNumbersCounter()const{
            int counter=0;
            for(int i=this->A;i<this->B;i++){
                if(MatchingNumbersCheck(i) == false){
                    counter++;
                }
            }
            return counter;
        }
        bool endsPowsofTwo(){
            return isItPowOfTwo(this->A) && isItPowOfTwo(this->B);   //може и да порверим първо едното после другото
        }
        interval intersect(const interval& secondInterval)const{ //сечение //Как работи consт тук правилно ли го позлвам
            interval result;
            if(this->B > secondInterval.A){    
                result.setPoints(secondInterval.A,this->B);
                return result;
            }
            if(this->A < secondInterval.B){    
                result.setPoints(this->A,secondInterval.B);
                return result;
            }else{
                result.setPoints(0,0);
                return result; 
            }
        }
        interval combinationInterval(const interval& secondInterval)const{ 
            int Start;
            int End;
            interval result;
            if(this->B < secondInterval.A){
                result.setPoints(0,0);
                return result;
            }
            if(this->A > secondInterval.B){
                result.setPoints(0,0);
                return result;
            }

            if(this->A > secondInterval.A){
                Start = this->A;
            }else{
                Start = secondInterval.A;
            }

            if(this->B > secondInterval.B){
                End = this->B;
            }else{
                End = secondInterval.B;
            }
            //std::cout<<Start<<End;
            result.setPoints(Start,End);
            
            return result; 
        }

        bool isSuperInterval(interval& secondInterval)const{ //сечение
            
            
            if(this->B >= secondInterval.B && this->A >= secondInterval.A){
                return true;
            }
            return false;
        }
        /*
        setA(int& a){             //Индивидуално или групово да са ми set и get; 
            this->A = a;            //Ако set е индивидуално то има проблеми при валидацията
        }
        setB(int& b){           
            this->B = b;
        }
        */

};
int main(){
    interval t1(3,10);
    interval t2(4,14);
    interval t3;
    
    interval result = t1.intersect(t2);
    //std::cout<<result.getA()<<std::endl;
    //std::cout<<result.getB();
    //std::cout<<t2.isSuperInterval(result);
    //std::cout<<result.primaryNumbersCount();

    //interval resultTwo = t1.combinationInterval(t2);
    //std::cout<<resultTwo.getA()<<" ";
    //std::cout<<resultTwo.getB();
    std::cout<<t1.combinationInterval(t2).getA()<<" ";
    std::cout<<t1.combinationInterval(t2).getB();


}
