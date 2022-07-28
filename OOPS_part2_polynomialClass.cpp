#include<iostream>
using namespace std;

class Polynomial{
public:
    int size;
    int* degCoeff;

    
            Polynomial(int n=5){
                degCoeff = new int[n];
                size = n;
           
                for(int i=0;i<size;i++){
                    degCoeff[i] = 0;
                }
            }

            Polynomial(const Polynomial& p){
                this->size = p.size;
                this->degCoeff = new int[size];
                for(int i=0;i<p.size;i++){
                    degCoeff[i] = p.degCoeff[i];
                }

            }

            Polynomial& operator=(const Polynomial& p){
                this->size = p.size;
                delete[] degCoeff;
                
                this->degCoeff = new int[this->size];
                for(int i=0;i<size;i++){
                    this->degCoeff[i] = p.degCoeff[i];
                }
                return *this;

            }

            Polynomial& operator*(const Polynomial& p){
                
                int max_size = this->size+p.size;
                Polynomial* tempPoly = new Polynomial(max_size);

               

                for(int i=0;i<this->size;i++){
                    if(this->degCoeff[i] == 0)
                        continue;
                    for(int j=0;j<p.size;j++){
                        if(p.degCoeff[j] == 0)
                            continue;
                       int tempIndex = i+j;
                       // tempPoly->setCoefficient(tempIndex,this->degCoeff[i]*p.degCoeff[j],false);
                       tempPoly->degCoeff[tempIndex] += this->degCoeff[i]*p.degCoeff[j];
                    }
                }
                
                return *tempPoly;
            }

            Polynomial& operator+(const Polynomial& p){
                int maxsize = max(size,p.size);
                int minsize = min(p.size,size);
                Polynomial *temp = new Polynomial(maxsize);
                temp->degCoeff = new int[maxsize];
                temp->size = maxsize;
                for(int i=0;i<minsize;i++){
                    temp->degCoeff[i] = p.degCoeff[i]+degCoeff[i];
                }
                if(p.size > size){
                    
                    for(int i=minsize;i<p.size;i++){
                        temp->degCoeff[i] = p.degCoeff[i];
                            }
                }else{
                    for(int i=minsize;i<size;i++){
                        temp->degCoeff[i] = degCoeff[i];
                    }
                }
                return *temp;
            }
    
     		Polynomial& operator-(const Polynomial& p){
                int maxsize = max(size,p.size);
                int minsize = min(p.size,size);
                Polynomial *temp = new Polynomial(maxsize);
                temp->degCoeff = new int[maxsize];
                temp->size = maxsize;
                for(int i=0;i<minsize;i++){
                    temp->degCoeff[i] = degCoeff[i]-p.degCoeff[i];
                }
                if(p.size > size){
                    
                    for(int i=minsize;i<p.size;i++){
                        temp->degCoeff[i] = p.degCoeff[i];
                            }
                }else{
                    for(int i=minsize;i<size;i++){
                        temp->degCoeff[i] = degCoeff[i];
                    }
                }
                return *temp;
            }

        void setCoefficient(int deg,int coef){
            int old = size;
            if(deg>size){
            
                while(deg > size){
                    size *=2;
                    // cout<<"hey"<<endl;
                }
                
            int *newdeg=new int[size];
            for(int i=0;i<size;i++){
                newdeg[i] = 0;
            }
            //Copy the contents from original to new
            for(int i=0;i<old;i++)
                newdeg[i]=degCoeff[i];
            
            delete[] this->degCoeff;
            this->degCoeff=newdeg;
            
            //Set the new coeff;
           
       	 	}
        	degCoeff[deg]=coef;
    	}

//             void setCoefficient(int index,int da,bool override=true){
//                 int temp_old_capa = this->size;
//                 if(index > size){
//                 while(index> size){
//                     size *=2;
//                 }
//                 int* temp = new int[size];
//                 for(int i=0;i<size;i++){
//                     temp[i] = 0;
//                 }
//                 for(int i=0;i<temp_old_capa;i++){
//                     temp[i] = this->degCoeff[i];
//                 }
//                 delete[] this->degCoeff;
//                 this->degCoeff = temp;
//                 }
                
//                 if(override){
//                     // cout<<"overrided "<<da<<" at "<<index<<endl;
//                     this->degCoeff[index] = da;
//                 }
//                 else{
//                     // cout<<"setCoefficiented "<<da<<" at "<<index<<endl;
//                     this->degCoeff[index] += da;
//                 }
                
//             }

            void print(){
                for(int i=0;i<size;i++){
                    if(degCoeff[i] != 0){
                    cout<<degCoeff[i]<<"x"<<i<<" ";
                    }
                }cout<<endl;
            }

};


int main(){

    Polynomial p1;
    p1.setCoefficient(2,2);
    p1.setCoefficient(5,5);
    p1.setCoefficient(3,3);
    p1.setCoefficient(6,6);
    p1.setCoefficient(4,4);
    p1.setCoefficient(7,7);
    
    Polynomial p2;
    p2.setCoefficient(1,1);
    p2.setCoefficient(4,4);

    
    p1.print();
    p2.print();
    
    Polynomial p3;
    p3 = p1*p2;
    
    p3.print();

    
   

    return 0;
}