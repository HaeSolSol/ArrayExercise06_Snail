#include <iostream>

int main()
{
    const int size{ 5 };
    int result{ 1 }, i{ 0 }, j{ 0 }, variator{ 1 };
    int snail[size][size]{};
    enum changeType
    {
        ROW,
        COLUMN
    };
    int limit = size, changer = ROW;

    while (result <= (size * size))
    {
        switch (changer)
        {
        case ROW:
            for (int k = 0; k < limit; ++k)
            {
                if (snail[i][j] != 0)
                {
                    j += variator;
                    continue;
                }
                snail[i][j] = result;
                j += variator;
                result++;
            }

            changer = COLUMN;
            j -= variator;
            if (result == (size + 1))
            {
                break;
            }
            limit--;
            break;

        case COLUMN:
            for (int k = 0; k < limit; ++k)
            {
                if (snail[i][j] != 0)
                {
                    i += variator;
                    continue;
                }
                snail[i][j] = result;
                i += variator;
                result++;
            }
            changer = ROW;
            i -= variator;
            variator *= -1;
            break;
        }
    }

    for (int m = 0; m < size; ++m)
    {
        for (int n = 0; n < size; ++n)
        {
            if (snail[m][n] < 10)
            {
                std::cout << "0";
            }
            std::cout << snail[m][n] << " ";
        }
        std::cout << "\n";
    }
}