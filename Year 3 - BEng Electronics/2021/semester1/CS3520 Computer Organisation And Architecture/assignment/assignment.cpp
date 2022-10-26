#include<iostream>
using namespace std;
int primefactors(int n);

int main(){
    int n;
    int number =24;
    primefactors(n);
 int num1 = primefactors(number);

   //while(num1 ==4 and num1 +1==4 and num1 + 2 ==4 and num1 + 3==4 and num1+4 ==4){
   	//number++;
   	//std::cout<<number;

//}/
//while((primefactors(number)<=1) and (primefactors(number+1)<=2) and (primefactors(number+1)<=2) ){
//number++;
//}
  while(1){
    if(primefactors(number)==4){
      if(primefactors(number+1)==4){
        if(primefactors(number+2)==4){
          if(primefactors(number+3)==4){
            std::cout<<number;
            break;
          }
          else{
            number++;
          }


        }
        else{
          number++;
        }
      }
      else{
        number++;
      }
    }
    else{
      number++;
    }

  }
//	num1 = primefactors(number);
	
  	//std::cout<<number<<"\n";
	
return 0;

}


int primefactors(int n){
    int devisor = 2;
    int counter =0;
    
    for(devisor = 2 ; devisor < n ; devisor++)
    {   if(n % devisor == 0 )
    
        {
            counter++;
            int factorcardi = 0;
            while(n % devisor == 0)
            {
                n = n / devisor;
                factorcardi++; 
            }
            //std::cout<< devisor <<"^"<< factorcardi << " ";
        }
    }
    if(n != 1){
    	counter = counter+1;
    	
        //std::cout << counter;
    }
	return counter; 
}
