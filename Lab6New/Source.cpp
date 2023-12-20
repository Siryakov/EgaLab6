#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <limits>

int main() {
    // ������������� ������� ����
    setlocale(LC_ALL, "Russian");

    // ���������� ���������� ������ �� �������� �������
    srand(time(NULL));

    // ����������� � ������������ ���������� �������
    int numCities;
    std::cout << "������� ���������� �������: ";
    std::cin >> numCities;


    std::vector<std::vector<double>> cities(numCities, std::vector<double>(numCities, 0.0));
    std::vector<double> temp = { 5.00, 12.53, 5.10, 11.70, 3.00, 13.04, 4.47, 1.00, 8.49, 7.62, 10.00, 13.15, 13.00, 13.60, 13.15,
                                   12.53, 1.00, 10.05, 10.00, 11.40, 7.28, 13.45, 13.04, 13.00, 8.06, 5.39, 8.25, 6.32, 2.83, 4.47,
                                   5.10, 10.05, 6.00, 13.45, 2.24, 13.42, 9.06, 6.08, 12.08, 2.83, 5.83, 13.89, 13.00, 12.04, 12.37,
                                   11.70, 10.00, 13.45, 7.00, 13.04, 3.61, 9.00, 11.40, 5.39, 13.60, 13.00, 2.83, 4.47, 8.25, 6.32,
                                   3.00, 11.40, 2.24, 13.04, 8.00, 13.60, 7.28, 4.00, 10.82, 5.00, 7.81, 13.93, 13.34, 13.04, 13.04,
                                   13.04, 7.28, 13.42, 3.61, 13.60, 9.00, 11.40, 13.00, 8.60, 12.81, 11.40, 1.00, 1.00, 5.00, 3.00,
                                   4.47, 13.45, 9.06, 9.00, 7.28, 11.40, 10.00, 3.61, 4.47, 11.05, 12.65, 11.18, 11.70, 13.60, 12.53,
                                   1.00, 13.04, 6.08, 11.40, 4.00, 13.00, 3.61, 14.00, 7.81, 8.54, 10.82, 13.04, 13.04, 13.93, 13.34,
                                   8.49, 13.00, 12.08, 5.39, 10.82, 8.60, 4.47, 7.81, 11.00, 13.34, 14.00, 8.06, 9.22, 12.21, 10.63,
                                   7.62, 8.06, 2.83, 13.60, 5.00, 12.81, 11.05, 8.54, 13.34, 4.00, 3.16, 13.45, 12.21, 10.44, 11.18,
                                   10.00, 5.39, 5.83, 13.00, 7.81, 11.40, 12.65, 10.82, 14.00, 3.16, 5.00, 12.21, 10.63, 8.06, 9.22,
                                   13.15, 8.25, 13.89, 2.83, 13.93, 1.00, 11.18, 13.04, 8.06, 13.45, 12.21, 7.00, 2.00, 6.00, 4.00,
                                   13.00, 6.32, 13.00, 4.47, 13.34, 1.00, 11.70, 13.04, 9.22, 12.21, 10.63, 2.00, 8.00, 4.00, 2.00,
                                   13.60, 2.83, 12.04, 8.25, 13.04, 5.00, 13.60, 13.93, 12.21, 10.44, 8.06, 6.00, 4.00, 9.00, 2.00,
                                   13.15, 4.47, 12.37, 6.32, 13.04, 3.00, 12.53, 13.34, 10.63, 11.18, 9.22, 4.00, 2.00, 2.00, 10.00 };

    // ��������� ������� �������
    for (int i = 0, k = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j, ++k) {
            cities[i][j] = temp[k];
            // ������������� ���������� 0, ��� ������� � ����� ���� 
            if (i == j) {
                cities[i][j] = 0.0;
            }
            else {
                // ������ ������� ������������
                cities[j][i] = cities[i][j];
            }
        }
    }

    // ������� ������� �������
    std::cout << "\n������� �������:\n";
    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) { 
            std::cout << std::setw(8) << std::fixed << std::setprecision(2) << cities[i][j] << " "; // setw(8)- ������  fixed- ����� � ������������� �������� setprecision-2 ����� ����� ������� 
        }
        std::cout << "\n";
    }

    // ������� ��� �������� ������ ������������ ������� � �������� ����
    std::vector<int> notincludet;
    std::vector<int> travel;

    // ��������� ������ ������������ �������
    for (size_t i = 0; i < cities.size(); ++i) {
        notincludet.push_back(static_cast<int>(i + 1));
    }


    // �������� ��������� ����� ��� ������ ����
    travel.push_back(notincludet[std::rand() % notincludet.size()]);
    std::cout << "��� ���� ���������� � ������ " << travel[0] << "\n";
    // ������� ��������� ����� �� ������ ������������
    notincludet.erase(std::remove(notincludet.begin(), notincludet.end(), travel[0]), notincludet.end());

    // ������� ��� ���������� ��������� ����� �������� � ����
    auto get_dist = [](const std::vector<int>& travel, const std::vector<std::vector<double>>& cities) -> double { //const- ����������� ���������� ��������,  -> double ��������� �� ������������ ��� �������
        double dist = 0;
        for (size_t i = 0; i < travel.size() - 1; ++i) {
            dist += cities[travel[i] - 1][travel[i + 1] - 1];
        }
        return dist;
    };

    int ch = 0;
    while (!notincludet.empty()) {
        // ������ ��� �������� ��� ������� � ���������� �� ���
        std::vector<std::vector<int>> para;
        // ��� ������� ������ � ������� ���� ���� ��������� ������������ �����
        for (int i : travel) {
            auto min_it = std::min_element(notincludet.begin(), notincludet.end(), [&](int a, int b)
                {return cities[i - 1][a - 1] < cities[i - 1][b - 1]; }); //���� ����������� �� � notincludet
            para.push_back({ i, *min_it });
        }

        // ����� ���������� � ���� ��������� ���������
        std::cout << "��� " << ch + 1 << "\n";
        for (auto& p : para) {
            std::cout << "�� ������ " << p[0] << " � ����� " << p[1] << " ���������� " << cities[p[0] - 1][p[1] - 1] << "\n";
        }

        // �������� ������� � ����������� �����������
        auto min_it = std::min_element(para.begin(), para.end(), [&](const std::vector<int>& a, const std::vector<int>& b) {
            return cities[a[0] - 1][a[1] - 1] < cities[b[0] - 1][b[1] - 1];
            });
        std::vector<int> nextC = *min_it;
        double distNext = cities[nextC[0] - 1][nextC[1] - 1];
        // ��������� ����� ����� � ����
        auto insert_pos = std::find(travel.begin(), travel.end(), nextC[0]);
        travel.insert(insert_pos + 1, nextC[1]);
        // ������� ��������� ����� �� ������ ������������
        notincludet.erase(std::remove(notincludet.begin(), notincludet.end(), nextC[1]), notincludet.end());
        ch++; 
        double dist = get_dist(travel, cities); // ������� ������ 
        std::cout << "��������� ������� " << nextC[0] << " - " << nextC[1] << "\n";
        std::cout << "����� �������: ";
        for (int i : travel) {
            std::cout << i << " ";
        }
        std::cout << "\n����� ����� " << dist << "\n";
    }

    // ��������� ����� ��������� � ��������� ���������� �� ���������� ������ �� ����������
    double dist = get_dist(travel, cities);
    dist += cities[travel.back() - 1][travel[0] - 1];
    // ������� ��������� ���� � ���������
    std::cout << "���� [";
    for (int i : travel) {
        std::cout << i << " ";
    }
    std::cout << travel[0] << "], ��������� " << dist << std::endl;

    return 0;
}
