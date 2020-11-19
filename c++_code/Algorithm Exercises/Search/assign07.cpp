/*
  * @brief Assignment 7
   * @author Zachary McBride
  */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;
void printTheGrid(char grid[10][10]);
int findTheAtSigns(char (&grid)[10][10], int row, int col);
bool wrapAroundTrue(char grid[10][10], int row, int col);
int findTheAtSignsHelper(char (&grid)[10][10], int row, int col, int& output);
int main()
{
    ifstream inFile;
    inFile.open("grid.txt");
    if(inFile.fail()){
        cout << "Failed to open file." << endl;
        return 0;
    }
    char gridI[10][10];
    for(int row=0; row < 10; row++){
        string tempString;
        getline(inFile, tempString);
        for(int col=0; col < 10; col++){
            gridI[row][col] = tempString.at(col);
        }
    }
    printTheGrid(gridI);
    cout << "Enter row and column" << endl;
    int row, col;
    cin >> row >> col;
    char (*grid)[10][10];
    grid = &gridI;
    cout << findTheAtSigns(*grid, row, col) << " cells" << endl;
    printTheGrid(gridI);
}
void printTheGrid(char grid[10][10]){
    for(int row=0; row < 10; row++){
        for(int col=0; col < 10; col++){
            cout << grid[row][col];
        }
        cout << endl;
    }
}
bool wrapAroundTrue(char (*grid)[10][10], int row, int col){
    bool output = false;
    if(row == 0 || col == 0 || row == 9 || col == 9){
        if (row == 0 && (*grid)[9][col] == '@'){output = true;}
        if (row == 9 && (*grid)[0][col] == '@'){output = true;}
        if (col == 0 && (*grid)[row][9] == '@'){output = true;}
        if (col == 9 && (*grid)[row][0] == '@'){output = true;}
    }
    return output;
}
int findTheAtSignsHelper(char (&grid)[10][10], int row, int col, int& output){
    //    printTheGrid(grid);
    //    system("pause");
    if(grid[row + 1][col] != '@' && grid[row - 1][col] != '@' && grid[row][col + 1] != '@' && grid[row][col - 1] != '@' && wrapAroundTrue((&grid), row, col) == false){
        return output;
    } else{
        if(grid[row][col + 1] == '@'){
            output++;
            grid[row][col + 1] = '!';
            findTheAtSignsHelper(grid, row, col + 1, output);
        }
        if(grid[row][col - 1] == '@'){
            output++;
            grid[row][col - 1] = '!';
            findTheAtSignsHelper(grid, row, col - 1, output);
        }
        if(grid[row + 1][col] == '@'){
            output++;
            grid[row + 1][col] = '!';
            findTheAtSignsHelper(grid, row + 1, col, output);
        }
        if(grid[row - 1][col] == '@'){
            output++;
            grid[row - 1][col] = '!';
            findTheAtSignsHelper(grid, row - 1, col, output);
        }
        if((col == 0 || row == 0) && wrapAroundTrue(&grid, row, col) == true){
            if(row == 0 && grid[9][col] == '@'){
                output++;
                grid[9][col] = '!';
                findTheAtSignsHelper(grid, 9, col, output);
            }
            if(col == 0 && grid[row][9] == '@'){
                output++;
                grid[row][9] = '!';
                findTheAtSignsHelper(grid, row, 9, output);
            }
        }
        if((col == 9 || row == 9) && wrapAroundTrue(&grid, row, col) == true){
            if(row == 9 && grid[0][col] == '@'){
                output++;
                grid[0][col] = '!';
                findTheAtSignsHelper(grid, 0, col, output);
            }
            if(col == 9 && grid[row][0] == '@'){
                output++;
                grid[row][0] = '!';
                findTheAtSignsHelper(grid, row, 0, output);
            }
        }
    }
    return output;
}
int findTheAtSigns(char (&grid)[10][10], int row, int col){
    int output = 0;
    if(grid[row][col] != '@'){
        return output;
    }else{
        grid[row][col] = '!';
        output++;
        return findTheAtSignsHelper(grid, row, col, output);
    }
    return output;
}
