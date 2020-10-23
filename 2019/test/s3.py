import sys
import os


def test(fin, sol, ans):
    grid = []
    with open(ans, 'r') as f:
        for line in f:
            grid.append(list(map(int, line.split())))
    
    for i in range(3):
        assert grid[i][1] - grid[i][0] == grid[i][2] - grid[i][1]
    
    for j in range(3):
        assert grid[1][j] - grid[0][j] == grid[2][j] - grid[1][j]


if __name__ == "__main__":
    if len(sys.argv) != 4:
        print('Usage: python3 s3.py input_file sol_file ans_file')
    else:
        fin, sol, ans = sys.argv[1:]
        test(fin, sol, ans)