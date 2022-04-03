import time
import turtle
t = turtle.Turtle()
t.penup()

turtle.setup(width=0.9, height=0.9, startx=10, starty=10)
ws = turtle.Screen()
ws.title("Fractal Circles")

def draw_circle(x_pos, y_pos, radius):
    t.setpos(x_pos, y_pos - radius)
    t.pendown()
    t.circle(radius)
    t.penup()

def fractal_circle(x_pos, y_pos, radius):
    draw_circle(x_pos, y_pos, radius)
    if (radius / 2) >= 10:
        fractal_circle(x_pos + radius, y_pos, radius / 2)
        fractal_circle(x_pos - radius, y_pos, radius / 2)

if __name__ == '__main__':
    fractal_circle(0, 0, 256)
    time.sleep(10)
