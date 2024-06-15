#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> hang_doi_cho_nhung_phan_tu_da_duoc_cap_nhat;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j]) mat[i][j] = -1;   // Phẩn tử của ma trận khác 0 thì đặt là -1 ( vô cùng )
                else hang_doi_cho_nhung_phan_tu_da_duoc_cap_nhat.push({i, j});  // Những phần tử ma trận bằng 0 thì thêm vào hàng đợi dùng để cập nhật những phần tử khác
            }
        }
        vector<int> dir = {0, 1, 0, -1, 0}; // Phần này để lấy theo cặp [0, 1], [1, 0], ... 
        while(!hang_doi_cho_nhung_phan_tu_da_duoc_cap_nhat.empty()) {
            auto [hang, cot] = hang_doi_cho_nhung_phan_tu_da_duoc_cap_nhat.front();
            hang_doi_cho_nhung_phan_tu_da_duoc_cap_nhat.pop();
            for(int i = 0; i < 4; i++) {
                int hang_ke = hang + dir[i], cot_ke = cot + dir[i+1];
                if(hang_ke >= m || cot_ke >= n || hang_ke < 0 || cot_ke < 0 || mat[hang_ke][cot_ke] != -1) continue;    // Nếu phần tử nằm ngoài ma trận hoặc là giá trị đó đã cập nhật thì bỏ qua
                mat[hang_ke][cot_ke] = mat[hang][cot] + 1;  // Cập nhật phần tử trong ma trận
                hang_doi_cho_nhung_phan_tu_da_duoc_cap_nhat.push({hang_ke, cot_ke});
            }
        }
        return mat;
    }
};