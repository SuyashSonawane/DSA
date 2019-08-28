#include<iostream>
using namespace std;

class SparseMatrix{
    public:
    int row,column,total;
    int M[10][3];

    SparseMatrix(){
        
    }
    void display(){
        for(int i=0;i<=M[0][2];i++){
            cout<<endl<<M[i][0]<<"\t"<<M[i][1]<<"\t"<<M[i][2]<<endl;
        }
    }
    void swap(int a,int b){
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    void accept(){
        cout<<"\nEnter number of rows";
        cin>>row;
        cout<<"\nEnter number of columns";
        cin>>column;
        cout<<"\nEnter total number of non-zero elements";
        cin>>total;
        M[0][0]=row;
        M[0][1]=column;
        M[0][2]=total;
        for(int i=1;i<=total;i++){
            cout<<"\nEnter the values for the element\n";
            cin>>M[i][0]>>M[i][1]>>M[i][2];
        }
    }
    SparseMatrix operator+(SparseMatrix s1){
        SparseMatrix s_local;
        int i=1,k=1,j=1;
        if(s1.column!=column || s1.row!=row){
            cout<<"Cannot perform addition";
            return s_local;
        }
        s_local.M[0][0]=M[0][0];
        s_local.M[0][1]=M[0][1];
        while(i<=M[0][2] || j<=s1.M[0][2]){
            if(M[i][0]==s1.M[j][0] && M[i][1]==s1.M[j][1]){
                s_local.M[k][0]=M[j][0];
                s_local.M[k][1]=M[j][1];
                s_local.M[k][2]=M[j][2] + s1.M[j][2];
                k++;i++;j++;
            }
            else{
                if(M[i][0] < s1.M[j][0]){
                    s_local.M[k][0]=M[i][0];
                    s_local.M[k][1]=M[i][1];
                    s_local.M[k][2]=M[i][2];
                    i++;k++;
                }
                else{
                    s_local.M[k][0]=s1.M[j][0];
                    s_local.M[k][1]=s1.M[j][1];
                    s_local.M[k][2]=s1.M[j][2];
                    j++;k++;
                }
            }
        }
        s_local.M[0][2]= k-1;
        s_local.total = k-1;
        return s_local;
        
        
    }
    void SimpleTranspose(){
        int temp;
        for(int i =0 ;i<=M[0][2];i++){
            temp = M[i][0];
            M[i][0]=M[i][1];
            M[i][1]=temp;

        }
        for(int i =1 ;i<=M[0][2];i++){
            for(int j=i;j<M[0][2];j++){
                if(M[j][0]>M[j+1][0]){
                    temp = M[j][0];
                    M[j][0]=M[j+1][0];
                    M[j+1][0]=temp;
                }
            }
        }
    }
    SparseMatrix FastTranspose(){
        SparseMatrix s_local;
        s_local.M[0][0]=M[0][1];
        s_local.M[0][1]=M[0][0];
        s_local.M[0][2]=M[0][2];
        int row = M[0][1],elements = M[0][2];
        int frequencyCounter[row],index[row];
        for(int i =0;i<row;i++){
            frequencyCounter[i]=0;
            index[i]=0;
        }
        for(int j=1;j<elements+1;j++){
            frequencyCounter[M[j][1]]++;
        }
        for(int i=1;i<=row;i++){
            index[0]=1;
            index[i]=index[i-1]+frequencyCounter[i-1];
        }
        for(int k=1;k<row+1;k++){
            s_local.M[index[M[k][1]]][0] = M[k][1];
            s_local.M[index[M[k][1]]][1] = M[k][0];
            s_local.M[index[M[k][1]]][2] = M[k][2];
            index[M[k][1]]++;
        }
        return s_local;
    }
};

int main(){
    SparseMatrix s1 ,s2,s3;
    s1.accept();
    s2= s1.FastTranspose();
    s2.display();
    
    return 0;
}