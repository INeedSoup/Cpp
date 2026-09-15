/* Learn: a project can model a board with an array and isolate drawing, rules, and input in functions.
Why: separate functions keep a game loop readable.
Watch out: validate an index before using it to access the board.
Try next: Add a replay prompt after the final board is displayed. */
#include <array>
#include <iostream>
#include <random>

using Board = std::array<char, 9>;

void draw(const Board& board)
{
    for (int row = 0; row < 3; ++row)
    {
        std::cout << ' ' << board[row * 3] << " | " << board[row * 3 + 1] << " | " << board[row * 3 + 2] << '\n';
        if (row < 2)
            std::cout << "---+---+---\n";
    }
}

bool hasWon(const Board& board, char marker)
{
    constexpr std::array winningLines{
        std::array{0, 1, 2}, std::array{3, 4, 5}, std::array{6, 7, 8},
        std::array{0, 3, 6}, std::array{1, 4, 7}, std::array{2, 5, 8},
        std::array{0, 4, 8}, std::array{2, 4, 6}};
    for (const auto& line : winningLines)
        if (board[line[0]] == marker && board[line[1]] == marker && board[line[2]] == marker)
            return true;
    return false;
}

bool isFull(const Board& board)
{
    for (char square : board)
        if (square == ' ')
            return false;
    return true;
}

int main()
{
    Board board{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    std::mt19937 engine(std::random_device{}());

    while (true)
    {
        draw(board);
        int choice{};
        std::cout << "Choose a square (1-9): ";
        if (!(std::cin >> choice) || choice < 1 || choice > 9 || board[choice - 1] != ' ')
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "That square is unavailable.\n";
            continue;
        }
        board[choice - 1] = 'X';
        if (hasWon(board, 'X') || isFull(board))
            break;

        std::array<int, 9> openSquares{};
        int count = 0;
        for (int index = 0; index < 9; ++index)
            if (board[index] == ' ')
                openSquares[count++] = index;
        std::uniform_int_distribution<int> pick(0, count - 1);
        board[openSquares[pick(engine)]] = 'O';
        if (hasWon(board, 'O') || isFull(board))
            break;
    }

    draw(board);
    if (hasWon(board, 'X'))
        std::cout << "You win!\n";
    else if (hasWon(board, 'O'))
        std::cout << "Computer wins.\n";
    else
        std::cout << "It's a tie.\n";
}
