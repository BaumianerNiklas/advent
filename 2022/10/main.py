lines = []

with open("./input.txt") as f:
    lines = [l.strip() for l in f.read().split("\n")]

X = 1
cycles = 0
strength = 0
img = ["" for _ in range(6)]

def update():
    # wow such functional programming
    global strength
    global cycles
    global img

    if (cycles - 20) % 40 == 0:
        strength += X * cycles
    
    if cycles // 40 > len(img) - 1:
        return 
    

    img[cycles // 40] += "#" if cycles % 40 in range(X-1, X+2) else "."


for line in lines:
    match line.split(" "):
        case ["noop"]:
            cycles += 1
            update()
        
        case ["addx", num]:
            cycles += 1
            update()
            cycles += 1
            update()

            X += int(num)

print(strength)

for line in img:
    print(*line)