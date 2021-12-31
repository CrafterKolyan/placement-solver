#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> calculateAttacks(const vector<vector<char>> &field) {
    vector<vector<int>> attacks(field.size(), decltype(attacks)::value_type(field[0].size(), 0));
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field[i].size(); ++j) {
            if (field[i][j] == '0' || field[i][j] == '1') continue;

            switch(field[i][j]) {
            case 'Q':
                for (size_t k = 1; k <= i; ++k) {
                    ++attacks[i - k][j];
                    if (field[i - k][j] != '0') break;
                }
                for (size_t k = i + 1; k < field.size(); ++k) {
                    ++attacks[k][j];
                    if (field[k][j] != '0') break;
                }

                for (size_t k = 1; k <= j; ++k) {
                    ++attacks[i][j - k];
                    if (field[i][j - k] != '0') break;
                }
                for (size_t k = j + 1; k < field[i].size(); ++k) {
                    ++attacks[i][k];
                    if (field[i][k] != '0') break;
                }
                for (size_t k = 1; k <= min(i, j); ++k) {
                    ++attacks[i - k][j - k];
                    if (field[i - k][j - k] != '0') break;
                }
                for (size_t k = 1; k <= min(i, field[i].size() - 1 - j); ++k) {
                    ++attacks[i - k][j + k];
                    if (field[i - k][j + k] != '0') break;
                }
                for (size_t k = 1; k <= min(field.size() - i - 1, field[i].size() - 1 - j); ++k) {
                    ++attacks[i + k][j + k];
                    if (field[i + k][j + k] != '0') break;
                }
                for (size_t k = 1; k <= min(field.size() - i - 1, j); ++k) {
                    ++attacks[i + k][j - k];
                    if (field[i + k][j - k] != '0') break;
                }
                break;
            case 'K':
                if (i > 0) {
                    if (j > 0) ++attacks[i - 1][j - 1];
                    ++attacks[i - 1][j];
                    if (j + 1 < field[i].size()) ++attacks[i - 1][j + 1];
                }

                if (j > 0) ++attacks[i][j - 1];
                if (j + 1 < field[i].size()) ++attacks[i][j + 1];

                if (i + 1 < field.size()) {
                    if (j > 0) ++attacks[i + 1][j - 1];
                    ++attacks[i + 1][j];
                    if (j + 1 < field[i].size()) ++attacks[i + 1][j + 1];
                }

                break;
            case 'N':
                if (i > 1) {
                    if (j > 0) ++attacks[i - 2][j - 1];
                    if (j + 1 < field[i].size()) ++attacks[i - 2][j + 1];
                }
                if (i > 0) {
                    if (j > 1) ++attacks[i - 1][j - 2];
                    if (j + 2 < field[i].size()) ++attacks[i - 1][j + 2];
                }
                if (i + 1 < field.size()) {
                    if (j > 1) ++attacks[i + 1][j - 2];
                    if (j + 2 < field[i].size()) ++attacks[i + 1][j + 2];
                }
                if (i + 2 < field.size()) {
                    if (j > 0) ++attacks[i + 2][j - 1];
                    if (j + 1 < field[i].size()) ++attacks[i + 2][j + 1];
                }

                break;
            case 'B':
                for (size_t k = 1; k <= min(i, j); ++k) {
                    ++attacks[i - k][j - k];
                    if (field[i - k][j - k] != '0') break;
                }
                for (size_t k = 1; k <= min(i, field[i].size() - 1 - j); ++k) {
                    ++attacks[i - k][j + k];
                    if (field[i - k][j + k] != '0') break;
                }
                for (size_t k = 1; k <= min(field.size() - i - 1, field[i].size() - 1 - j); ++k) {
                    ++attacks[i + k][j + k];
                    if (field[i + k][j + k] != '0') break;
                }
                for (size_t k = 1; k <= min(field.size() - i - 1, j); ++k) {
                    ++attacks[i + k][j - k];
                    if (field[i + k][j - k] != '0') break;
                }
                break;
            case 'R':
                for (size_t k = 1; k <= i; ++k) {
                    ++attacks[i - k][j];
                    if (field[i - k][j] != '0') break;
                }
                for (size_t k = i + 1; k < field.size(); ++k) {
                    ++attacks[k][j];
                    if (field[k][j] != '0') break;
                }

                for (size_t k = 1; k <= j; ++k) {
                    ++attacks[i][j - k];
                    if (field[i][j - k] != '0') break;
                }
                for (size_t k = j + 1; k < field[i].size(); ++k) {
                    ++attacks[i][k];
                    if (field[i][k] != '0') break;
                }

                break;
            case 'P':
                if (i > 0) {
                    if (j > 0) ++attacks[i - 1][j - 1];
                    if (j + 1 < field[i].size()) ++attacks[i - 1][j + 1];
                }
                break;

            default:
                break;
            }

        }
    }

    return attacks;
}

vector<vector<int>> surelyAttacks(const vector<vector<char>> &field) {
    vector<vector<int>> attacks(field.size(), decltype(attacks)::value_type(field[0].size(), 0));
    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field[i].size(); ++j) {
            if (field[i][j] == '0' || field[i][j] == '1') continue;

            switch(field[i][j]) {
            case 'Q':
            case 'K':
                if (i > 0) {
                    if (j > 0) ++attacks[i - 1][j - 1];
                    ++attacks[i - 1][j];
                    if (j + 1 < field[i].size()) ++attacks[i - 1][j + 1];
                }

                if (j > 0) ++attacks[i][j - 1];
                if (j + 1 < field[i].size()) ++attacks[i][j + 1];

                if (i + 1 < field.size()) {
                    if (j > 0) ++attacks[i + 1][j - 1];
                    ++attacks[i + 1][j];
                    if (j + 1 < field[i].size()) ++attacks[i + 1][j + 1];
                }

                break;
            case 'N':
                if (i > 1) {
                    if (j > 0) ++attacks[i - 2][j - 1];
                    if (j + 1 < field[i].size()) ++attacks[i - 2][j + 1];
                }
                if (i > 0) {
                    if (j > 1) ++attacks[i - 1][j - 2];
                    if (j + 2 < field[i].size()) ++attacks[i - 1][j + 2];
                }
                if (i + 1 < field.size()) {
                    if (j > 1) ++attacks[i + 1][j - 2];
                    if (j + 2 < field[i].size()) ++attacks[i + 1][j + 2];
                }
                if (i + 2 < field.size()) {
                    if (j > 0) ++attacks[i + 2][j - 1];
                    if (j + 1 < field[i].size()) ++attacks[i + 2][j + 1];
                }

                break;
            case 'B':
                if (i > 0) {
                    if (j > 0) ++attacks[i - 1][j - 1];
                    if (j + 1 < field[i].size()) ++attacks[i - 1][j + 1];
                }

                if (i + 1 < field.size()) {
                    if (j > 0) ++attacks[i + 1][j - 1];
                    if (j + 1 < field[i].size()) ++attacks[i + 1][j + 1];
                }
                break;
            case 'R':
                if (i > 0) {
                    ++attacks[i - 1][j];
                }

                if (j > 0) ++attacks[i][j - 1];
                if (j + 1 < field[i].size()) ++attacks[i][j + 1];

                if (i + 1 < field.size()) {
                    ++attacks[i + 1][j];
                }

                break;
            case 'P':
                if (i > 0) {
                    if (j > 0) ++attacks[i - 1][j - 1];
                    if (j + 1 < field[i].size()) ++attacks[i - 1][j + 1];
                }
                break;

            default:
                break;
            }

        }
    }

    return attacks;
}

void solve(vector<vector<char>> &field, string pieces, size_t index = 0) {
    if (index == pieces.size()) {
        auto attacks = calculateAttacks(field);
        for (size_t i = 0; i < field.size(); ++i) {
            for (size_t j = 0; j < field[i].size(); ++j) {
                if (field[i][j] != '0' && field[i][j] != '1') {
                    if (attacks[i][j] != 1) {
                        return;
                    }
                }
            }
        }

        for (auto &row : field) {
            for (auto &value : row) {
                cout << value;
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    size_t count = 0;
    for (size_t i = 0; i < index; ++i) {
        if (pieces[i] == pieces[index]) {
            ++count;
        }
    }

    auto sureAttacks = surelyAttacks(field);

    for (size_t i = 0; i < field.size(); ++i) {
        for (size_t j = 0; j < field[i].size(); ++j) {
            auto &value = field[i][j];
            if (count > 0 && value == pieces[index]) {
                --count;
                continue;
            }
            if (value != '0' || count > 0 || sureAttacks[i][j] > 1) continue;
            value = pieces[index];
            solve(field, pieces, index + 1);
            value = '0';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    while (true) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> field(n, decltype(field)::value_type(m, {}));
        for (auto &row : field) {
            for (auto &value : row) {
                cin >> value;
            }
        }
        string pieces;
        cin >> pieces;
        for (auto &c : pieces) {
            c = toupper(c);
        }
        solve(field, pieces);
        cout << "Done!" << endl;
    }
    return 0;
}
