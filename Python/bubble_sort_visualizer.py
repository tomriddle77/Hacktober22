import pygame
import random
import time

# Initialize Pygame
pygame.init()

# Constants
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 400
BAR_WIDTH = 10
BAR_SPACING = 2
NUM_BARS = SCREEN_WIDTH // (BAR_WIDTH + BAR_SPACING)
WHITE = (255, 255, 255)
RED = (255, 0, 0)

# Create the screen
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Bubble Sort Visualization")

# Generate a random list of numbers to sort
data = [random.randint(10, SCREEN_HEIGHT - 10) for _ in range(NUM_BARS)]

def draw_bars():
    for i, bar_height in enumerate(data):
        pygame.draw.rect(screen, RED, (i * (BAR_WIDTH + BAR_SPACING), SCREEN_HEIGHT - bar_height, BAR_WIDTH, bar_height))

def bubble_sort(data):
    n = len(data)
    for i in range(n):
        for j in range(0, n - i - 1):
            if data[j] > data[j + 1]:
                data[j], data[j + 1] = data[j + 1], data[j]
                screen.fill(WHITE)
                draw_bars()
                pygame.display.update()
                time.sleep(0.01)

# Main loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.fill(WHITE)
    bubble_sort(data)
    draw_bars()
    pygame.display.update()

pygame.quit()
