#include <iostream>
#include <vector>

using namespace std;

int originColor;
int newColor;

void changeColor(vector<vector<int>> &image, int i, int j){
    if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size()) return;
    if(image[i][j] != originColor) return;
    if(image[i][j] == newColor) return;

    image[i][j] = newColor;

    changeColor(image, i+1, j);
    changeColor(image, i-1, j);
    changeColor(image, i, j+1);
    changeColor(image, i, j-1);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color){
    originColor = image[sr][sc];
    newColor = color;
    if(originColor == newColor) return image;
    changeColor(image, sr, sc);
    return image;
}

int main(){
    // Test
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    floodFill(image, 1, 1, 2);
    for(int i = 0; i < image.size(); i++){
        for(int j = 0; j < image[0].size(); j++){
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}