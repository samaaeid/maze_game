import random

N, M = 15, 25
a, b = -1, -1
grid = [['.' for x in range(M)] for y in range(N)]

n = random.randint(0, N - 1)
n2 = random.randint(0, N - 1)


# This function prints the grid of Gomoku as the game progresses
def print_grid():
    print('__' + '___' * M + '__')
    for i in range(N):
        if i == n:
            print(end="   ")
        else:
            print(end='|  ')
        for j in range(M):
            print(grid[i][j], end='  ')
        if i == n2:
            print(end=" ")
        else:
            print(end='|')
        print()
    print('|_' + '___' * M + '_|')


# This function checks if the game has a win state or not
def check_win():
    if a == n2 and b + 1 == M:
        return True
    else:
        return False


# This function checks if given position is valid or not
def check_valid_direction(i):
    if i == 1 or i == 2 or i == 3 or i == 4:
        return True
    else:
        return False


# This function generates man
def generate_man():
    global a
    global b
    a = n
    b = 0
    grid[a][b] = 'M'


def check_available_move(i):
    if i == 3:
        if b + 1 > M - 1:
            return False  # right
    elif i == 1:
        if a - 1 < 0:
            return False  # up
    elif i == 2:
        if a + 1 > N - 1:
            return False  # down
    elif i == 4:
        if b - 1 < 0:
            return False  # left
    return True


# This function checks if the game has a tie state or not for the given mark
def check_lose(i):
    if i == 3:
        if grid[a][b + 1] == 'G':
            return True
    elif i == 1:
        if grid[a - 1][b] == 'G':
            return True
    elif i == 2:
        if grid[a + 1][b] == 'G':
            return True
    elif i == 4:
        if grid[a][b - 1] == 'G':
            return True
    return False


def check_wall(i):
    if i == 3:
        if grid[a][b + 1] == '|' or grid[a][b + 1] == '-':
            return True
    elif i == 1:
        if grid[a - 1][b] == '|' or grid[a][b + 1] == '-':
            return True
    elif i == 2:
        if grid[a + 1][b] == '|' or grid[a][b + 1] == '-':
            return True
    elif i == 4:
        if grid[a][b - 1] == '|' or grid[a][b + 1] == '-':
            return True
    return False


def move(i):
    global a
    global b

    grid[a][b] = '.'
    if i == 3:  # right
        grid[a][b + 1] = 'M'
        b += 1

    elif i == 1:  # up

        grid[a - 1][b] = 'M'
        a -= 1

    elif i == 2:  # down

        grid[a + 1][b] = 'M'
        a += 1

    elif i == 4:  # left

        grid[a][b - 1] = 'M'
        b -= 1


# This function generates ghosts
def generate_():
    f = N * M * 1 // 6
    while f > 0:
        a = random.randint(0, N - 1)
        b = random.randint(0, M - 1)
        while grid[a][b] == 'M' or (a == n2 and b == M - 1) or (a == n2 - 1 and b == M - 1) or (
                a == n2 + 1 and b == M - 1) or (a == n and b == 1) or (a == n - 1 and b == 0) or (
                a == n + 1 and b == 0) or (a == n - 1 and b == 1) or (a == n + 1 and b == 1):
            a = random.randint(0, N - 1)
            b = random.randint(0, M - 1)
        grid[a][b] = '_'
        f -= 1

    # This function generates a wall


def generate_wall():
    f = N * M * 1 // 8
    while f > 0:
        a = random.randint(0, N - 1)
        b = random.randint(0, M - 1)
        while grid[a][b] == 'M' or grid[a][b] == '_' or (a == n2 and b == M - 1) or (a == n2 - 1 and b == M - 1) or (
                a == n2 + 1 and b == M - 1) or (a == n and b == 1) or (a == n - 1 and b == 0) or (
                a == n + 1 and b == 0) or (a == n - 1 and b == 1) or (a == n + 1 and b == 1):
            a = random.randint(0, N - 1)
            b = random.randint(0, M - 1)
        grid[a][b] = '|'
        f -= 1


# This function clears the game structures
def grid_clear():
    global grid
    grid = [['.' for x in range(M)] for y in range(N)]

    global a, b
    a, b = -1, -1


# This function reads a valid position input
def read_input():
    i = int(input('Enter Direction : '))
    while not check_valid_direction(i):
        i = int(input('Enter a valid direction: '))
    return i


# MAIN FUNCTION
def play_game():
    print("Maze  Game!")
    print("Welcome...")
    print("============================")
    while True:
        # Prints the grid
        print_grid()
        i = read_input()
        if check_wall(i):
            print("WHATCH OUT you hit a wall !! please ", end=' ')
            i = read_input()
        # Move with the input direction
        move(i)
        # Check if the state of the grid has a win state
        if check_win():
            # Prints the grid
            print_grid()
            # Announcement of the final statement
            print("Congrats, you won!\n")
            break


while True:
    grid_clear()
    generate_man()
    generate_()
    generate_wall()
    play_game()
    c = input('Play Again [Y/N] ')
    if c not in 'yY':
        break
