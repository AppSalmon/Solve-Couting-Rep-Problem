#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Row {
    int colindex, col1, col2, col3, col4, col5, col6, col7, col8;
};

int find_rep(const std::vector<int>& my_list) {
//    std::cout << my_list.size() << " ";

    int mean_value = 0;
    for (int value : my_list) {
        mean_value += value;
    }
    mean_value /= my_list.size();

    int check = (my_list[0] > mean_value) ? 1 : 0;
    int cnt = 0;

    for (int i = 1; i < my_list.size(); ++i) {
        if (my_list[i] > mean_value && check == 0) {
            cnt += 1;
            check = 1;
        } else if (my_list[i] < mean_value && check == 1) {
            cnt += 1;
            check = 0;
        }
    }

    return cnt / 2;
}



int main() {

    // =============== Đọc file ===========//

    std::ifstream inputFile("F-1234-15.csv");
    std::vector<Row> data;  // Lưu trữ dữ liệu từ file CSV

    if (inputFile.is_open()) {
        std::string line;
        getline(inputFile, line);  // Bỏ qua dòng tiêu đề

        while (getline(inputFile, line)) {
            std::istringstream ss(line);
            Row row;

            char comma;  // Dùng để bỏ qua dấu phẩy
            ss >> row.colindex >> comma >> row.col1 >> comma >> row.col2 >> comma >> row.col3 >> comma >> row.col4
               >> comma >> row.col5 >> comma >> row.col6 >> comma >> row.col7 >> comma >> row.col8;

            data.push_back(row);
        }

        inputFile.close();

        // In ra dữ liệu đọc được (ví dụ)
//        for (const auto& row : data) {
//            std::cout << row.col1 << "," << row.col2 << "," << row.col3 << "," << row.col4
//                      << "," << row.col5 << "," << row.col6 << "," << row.col7 << "," << row.col8
//                      << std::endl;
//        }
    } else {
        std::cerr << "Unable to open the file!" << std::endl;
    }

    // ============== Xử lý ================= //


    std::vector<int> maybe_rep;


    std::vector<int> column;
    for (auto one_row: data) column.push_back(one_row.col1);
    maybe_rep.push_back(find_rep(column));
    column.clear();


    for (auto one_row: data) column.push_back(one_row.col2);
    maybe_rep.push_back(find_rep(column));
    column.clear();


    for (auto one_row: data) column.push_back(one_row.col3);
    maybe_rep.push_back(find_rep(column));
    column.clear();


    for (auto one_row: data) column.push_back(one_row.col4);
    maybe_rep.push_back(find_rep(column));
    column.clear();


    for (auto one_row: data) column.push_back(one_row.col5);
    maybe_rep.push_back(find_rep(column));
    column.clear();


    for (auto one_row: data) column.push_back(one_row.col6);
    maybe_rep.push_back(find_rep(column));
    column.clear();


    for (auto one_row: data) column.push_back(one_row.col7);
    maybe_rep.push_back(find_rep(column));
    column.clear();


    for (auto one_row: data) column.push_back(one_row.col8);
    maybe_rep.push_back(find_rep(column));
    column.clear();

//    for(auto i : maybe_rep) std::cout << i << std::endl;

    std::sort(maybe_rep.begin(), maybe_rep.end());

    int mostFrequentElement = maybe_rep[0];
    int currentElement = maybe_rep[0];
    int currentCount = 1;
    int maxCount = 1;

    // Duyệt qua vector để tìm phần tử xuất hiện nhiều nhất
    for (int i = 1; i < maybe_rep.size(); ++i)
    {
        if (maybe_rep[i] == currentElement)
        {
            currentCount++;
        }
        else
        {
            if (currentCount > maxCount)
            {
                maxCount = currentCount;
                mostFrequentElement = currentElement;
            }

            currentElement = maybe_rep[i];
            currentCount = 1;
        }
    }

    // Kiểm tra phần tử cuối cùng
    if (currentCount > maxCount) {
        mostFrequentElement = currentElement;
    }

    // Đã kiểm tra kết quả đúng - giống file ipynb

    std::cout << "Ans: " << mostFrequentElement;




    return 0;
}
