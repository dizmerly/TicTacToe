//This is a program for tic tac toe


#include <iostream>
#include <ctime>
using namespace std;
const int rows = 3;
const int colums = 3;

int x; 
int y; 


int ctrx = 1;
int ctro = 1; 

int * px = &x;
int * py = &y;


char matrix[rows][colums];



    
void Start()
{                                       //Sets all elements of array to E as in empty
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < colums; j++)
        {
            matrix[i][j] = 'E';
        }
    }
}


void Display()
{                                                       // Iterates through the area to display it
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j < colums; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
 
int SetX()
{                                                               // Takes two inputs, and uses them to X
   int row, column;

    cout << "Enter a position to place X" << endl;
    cin >> row >> column;

    if(row <= 2 and row >= 0 and column <= 2 and column >= 0)
    {
        matrix[row][column] = 'X';
        cout << endl;
        cout << "Placed X at row " << row << ", column " << column << endl; 
    }
    else
    {
        cout << "Enter a position between 0 and 2 for row and column." << endl;
    }

    *px = row;
    *py = column;
}




int SetO()
{                                                       //Uses two inputs to set to Y
   int row, column;

    cout << "Enter a position to place O" << endl;
    cin >> row >> column;

    if(row <= 2 && row >= 0 && column <= 2 && column >= 0)
    {
        matrix[row][column] = 'O';
        cout << endl;
        cout << "Placed O at row " << row << ", column " << column << endl; 
    }
    else
    {
        cout << "Enter a position between 0 and 2 for row and column." << endl;
    }

    *px = row;
    *py = column; 
    
}






bool Win(int i, int j)
{
    
    if(matrix[i][j] == 'X')
    {
        if(matrix[i + 1][j] == 'X' || matrix[i + 1][j + 1] == 'X' || matrix[i][j + 1] == 'X' || matrix[i - 1][j] == 'X' || matrix[i - 1][j - 1] == 'X' || matrix[i][j - 1] == 'X')
        {
            ctrx++;
        }
        cout << ctrx << " X's total"<< endl;
    }
    else if(matrix[i][j] == 'O')
    {
        if(matrix[i + 1][j] == 'O' || matrix[i + 1][j + 1] == 'O' || matrix[i][j + 1] == 'O' || matrix[i - 1][j] == 'O' || matrix[i - 1][j - 1] == 'O' || matrix[i][j - 1] == 'O')
        {
            ctro++;   
           
        }
        cout << ctro << " O's total" <<  endl;

    }



    else
    {
        cout << "Found nothing" << endl;
    }
}





int main()
{
    cout << endl;

    Start();
    Display();


    while(ctrx < 3 && ctro < 3)
    {
        SetX();
        Display();
        Win(x, y);
        SetO();
        Display();
        Win(x, y);
        
    }
    

    cout << "Someone won!" << endl; 

    return 0;


}
