import re

initial = None
rearrangements = None

with open("./input.txt") as f:
	initial, rearrangements = f.read().rstrip().split("\n\n")

initial_lines = initial.split("\n")[:-1]

lines = []
for i, line in enumerate(initial_lines):
	lines.append([])

	j = 1
	while j < len(line):
		lines[i].append(line[j])
		j += 4

cargo = {}
for i in range(9):
	cargo[i] = []

for i, line in enumerate(lines):
	for j, char in enumerate(line):
		if char != " ":
			cargo[j].append(char)


def get_instructions(move):
	split = move.split(" ")
	amount = int(split[1])
	where = int(split[3]) - 1
	to = int(split[5]) - 1

	return (amount, where, to)


def part1():
	for move in rearrangements.split("\n"):
		amount, where, to = get_instructions(move)

		moved = cargo[where][0:amount]
		cargo[where] = cargo[where][amount:]
		for m in moved:
			cargo[to].insert(0, m)

	res = ""
	for stack in cargo.values():
		res += stack[0]

	print(res)


def part2():
	for move in rearrangements.split("\n"):
		amount, where, to = get_instructions(move)

		moved = cargo[where][0:amount]
		moved.reverse()
		cargo[where] = cargo[where][amount:]
		for m in moved:
			cargo[to].insert(0, m)

	res = ""
	for stack in cargo.values():
		res += stack[0]

	print(res)


# methods have to be called seperately and can't be called after each other because they mutate state (the cargo dict)
# functional programming amirite
#part1()
part2()
