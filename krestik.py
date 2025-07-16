import pygame
import sys

# Инициализация Pygame
pygame.init()

# Установка размеров экрана
WIDTH, HEIGHT = 300, 300
ROWS, COLS = 3, 3
SQUARE_SIZE = WIDTH // COLS

# Цвета
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)

# Инициализация окна
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Крестики-нолики")

# Функция отрисовки сетки
def draw_grid():
    for x in range(1, COLS):
        pygame.draw.line(screen, BLACK, (x * SQUARE_SIZE, 0), (x * SQUARE_SIZE, HEIGHT), 2)
    for y in range(1, ROWS):
        pygame.draw.line(screen, BLACK, (0, y * SQUARE_SIZE), (WIDTH, y * SQUARE_SIZE), 2)

# Отрисовка фигур на доске
def draw_figures():
    for row in range(ROWS):
        for col in range(COLS):
            if board[row][col] == 'X':
                pygame.draw.line(screen, BLACK, (col * SQUARE_SIZE + 10, row * SQUARE_SIZE + 10),
                                 ((col + 1) * SQUARE_SIZE - 10, (row + 1) * SQUARE_SIZE - 10), 2)
                pygame.draw.line(screen, BLACK, ((col + 1) * SQUARE_SIZE - 10, row * SQUARE_SIZE + 10),
                                 (col * SQUARE_SIZE + 10, (row + 1) * SQUARE_SIZE - 10), 2)
            elif board[row][col] == 'O':
                pygame.draw.circle(screen, BLACK, (col * SQUARE_SIZE + SQUARE_SIZE // 2, row * SQUARE_SIZE + SQUARE_SIZE // 2), SQUARE_SIZE // 2 - 10, 2)

# Проверка выигрыша
def check_win():
    # Проверка строк
    for row in range(ROWS):
        if board[row][0] == board[row][1] == board[row][2] != '-':
            return True
    # Проверка столбцов
    for col in range(COLS):
        if board[0][col] == board[1][col] == board[2][col] != '-':
            return True
    # Проверка диагоналей
    if board[0][0] == board[1][1] == board[2][2] != '-' or \
            board[0][2] == board[1][1] == board[2][0] != '-':
        return True
    return False

# Создание доски
board = [['-' for _ in range(COLS)] for _ in range(ROWS)]
turn = 'X'
game_over = False

# Основной цикл игры
while True:
    screen.fill(WHITE)
    draw_grid()
    draw_figures()

    # Обработка событий
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == pygame.MOUSEBUTTONDOWN and not game_over:
            mouseX, mouseY = pygame.mouse.get_pos()
            row = mouseY // SQUARE_SIZE
            col = mouseX // SQUARE_SIZE
            if board[row][col] == '-':
                board[row][col] = turn
                if check_win():
                    game_over = True
                turn = 'O' if turn == 'X' else 'X'

    # Проверка на выигрыш или ничью
    if game_over:
        font = pygame.font.Font(None, 32)
        if check_win():
            text = font.render(f'Игрок {turn} победил!', True, BLACK)
        else:
            text = font.render('Ничья!', True, BLACK)
        text_rect = text.get_rect(center=(WIDTH // 2, HEIGHT // 2))
        screen.blit(text, text_rect)

    pygame.display.flip()
