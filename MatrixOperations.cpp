// Matrix Operations:
//Sum, Transpose inplace, Transpose into other matrix, Multiplication, Is_Symmetric, Display 

#include <iostream>
#include <vector>
using namespace std;
typedef vector<float> Row;
typedef vector<Row> Matrix;
//Sum Function
Matrix sum(const Matrix& A,const Matrix& B)
{
    Matrix C(4,Row(4));
    int rows= A.size();
    int cols=A[0].size();
    for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++)
    {
        
     C[i][j]=A[i][j]+B[i][j];   
    }
    return C;
}
//Swap function
void swap(float& a, float& b)
{
    float temp;
    temp=a;
    a=b;
    b=temp;
}
//Transpose function
void transpose(Matrix& A)
{
    int rows= A.size();
    int cols=A[0].size();
    
    for(int i=0;i<rows;i++)
    for(int j=i+1;j<cols;j++)
    {
        swap(A[i][j],A[j][i]);
    }
}

//Transpose into other matrix
Matrix transpose_nonsquare(Matrix A)
{
    int rows= A.size();
    int cols=A[0].size();
    Matrix E(cols,Row(rows));
    for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++)
    {
        E[j][i]=A[i][j];
    }
    return E;
    
}
//multiplication
Matrix multiply(const Matrix& A,const Matrix& B)
{
    int n=A.size();
    int m=A[0].size();
    int p=B[0].size();
    
    Matrix D(n,Row(p,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            for(int k=0;k<m;k++)
            {
                D[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return D;
}
//Is symmetric
bool is_symmetric(Matrix A)
{
    int rows=A.size();
    int cols=A[0].size();
    for(int i=0;i<rows;i++)
        for(int j=i+1;j<cols;j++)
        {
            if(A[i][j]!=A[j][i])
            return false;
        }
    return true;
}

//Rotate 90
Matrix rotate_90(const Matrix& A)
{
    int rows=A.size();
    int cols=A[0].size();
    Matrix B(cols,Row(rows));
    
    for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++)
    {
        B[j][rows-1-i]=A[i][j];
    }
    return B;
}

//Display
void display(Matrix A)
{
int rows= A.size();
int cols=A[0].size();
for(int i=0;i<rows;i++)
{
    for(int j=0;j<cols;j++)
    {
    cout<< A[i][j]<<"\t";
    }
    cout<< endl;
}

}
int main()
{
    int n=4;
    Matrix A(n,Row(n));
    Matrix B(n, Row(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j]=(i)*j;
            B[i][j]=(j+1)*i;
        }
    }
    display(A);
    Matrix C(4,Row(4)); 
    C= sum(A,B);
    display(C);
    
    transpose(C);
    display(C);
    Matrix D(4,Row(4));
    D=multiply(A,B);
    display(D);
    bool flag;
    flag=is_symmetric(A);
    cout<< "Matrix A is symmetric:"<<flag<<endl;
    flag=is_symmetric(D);
    cout<< "Matrix D is symmetric:"<<flag<<endl;
    Matrix E(2,Row(4));
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            E[i][j]=(i+1)*(j+1);
           
        }
    }
    cout<<"Non Square Matrix:"<<endl;
    display(E);
    Matrix F(4,Row(2));
    F=transpose_nonsquare(E);
    cout<<"Non Square Matrix Transpose"<<endl;
    display(F);
    Matrix G(2,Row(4));
    G=rotate_90(F);
    cout<<"Rotated 90 degeee matrix"<<endl;
    display(G);

    return 0;
    
}

