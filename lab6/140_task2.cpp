#include <bits/stdc++.h>
using namespace std;

class Matrix3D
{
private:
    double indices[3][3];
    double x,y,z;
    int row;
    int column;
    double det;
public:
    Matrix3D(double a00, double a01, double a02, double a10, double a11, double a12, double a20, double a21, double a22)
    {
        indices[0][0]=a00; indices[0][1]=a01; indices[0][2]=a02; indices[1][0]=a10; indices[1][1]=a11;
        indices[1][2]=a12; indices[2][0]=a20; indices[2][1]=a21; indices[2][2]=a22;
    };
    Matrix3D()
    {};
    ~Matrix3D()
    {};

    void fillMatrix()
    {
        cout << "\nEnter them entries from row to row\n";
        for(row = 0; row < 3; row++)	
        {
            for(column = 0; column < 3; column++) 
            {
                cin >> indices[row][column];
            }		
        }
    }

    void view()
    {
        for(row = 0; row < 3; row++)	
        {
            for(column = 0; column < 3; column++) 
            {
                cout<<indices[row][column]<<"  ";
            }
            cout<<endl;		
        }
    }

    double deter()
    {
        x = ((indices[1][1] * indices[2][2]) - (indices[2][1] * indices[1][2]));
        y = ((indices[1][0] * indices[2][2]) - (indices[2][0] * indices[1][2]));
        z = ((indices[1][0] * indices[2][1]) - (indices[2][0] * indices[1][1]));


        det = ((indices[0][0] * x) - (indices[0][1] * y) + (indices[0][2] * z));   

        return det;
    }    

    Matrix3D inverse() const
    {
        Matrix3D temp(0, 0, 0, 0, 0, 0, 0, 0, 0);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                temp.indices[i][j] = (indices[(j + 1) % 3][(i + 1) % 3]
                            * indices[(j + 2) % 3][(i + 2) % 3]
                            - indices[(j + 1) % 3][(i + 2) % 3]
                            * indices[(j + 2) % 3][(i + 1) % 3])
                            / det;
        return temp;
    }

    Matrix3D operator + (Matrix3D mx)
    {
        Matrix3D temp;

        for(row = 0; row < 3; row++)
        {
            for(column = 0; column < 3; column++)
            {
              temp.indices[row][column] = indices[row][column] + mx.indices[row][column];
            }
        }

        return temp;
    }

    Matrix3D operator - (Matrix3D mx)
    {
        Matrix3D temp;

        for(row = 0; row < 3; row++)
        {
            for(column = 0; column < 3; column++)
            {
              temp.indices[row][column] = indices[row][column] - mx.indices[row][column];
            }
        }

        return temp;
    }

    Matrix3D operator * (Matrix3D mx)
    {   
        Matrix3D temp;

        for (row = 0; row < 3; row++) 
        {
            for (column = 0; column < 3; column++) 
            {
            temp.indices[row][column] = 0;
            for (int k = 0; k < 3; k++)
                temp.indices[row][column] += indices[row][k] * mx.indices[k][column];
            }
        }

        return temp;   
    }

};


int main()
{
    
    Matrix3D m1(3,3,-1,-2,-2,1,-4,-5,2), m2;

    m1.view();

    cout<<m1.deter()<<endl;

    cout<<endl<<endl;

    m2 = m1.inverse();
    m2.view();

    m1 = m1 * m2;


    cout<<endl<<endl<<endl;
    m1.view();

    return 0;
}