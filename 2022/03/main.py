rucksacks = []
groups = []

with open("./input.txt") as f:
	rucksacks = f.read().split("\n")

i = 0
while i < len(rucksacks):
	groups.append(rucksacks[i:i + 3])
	i += 3


def item_priority(item):
	return ord(item) - 96 if item.islower() else ord(item) - 38


letters = "abcdefghijklmnopqrstuvwxyz"
letters += letters.upper()

total = 0
for rucksack in rucksacks:
	half_len = len(rucksack) // 2
	first, second = [rucksack[:half_len], rucksack[half_len:]]

	for letter in letters:
		if letter in first and letter in second:
			total += item_priority(letter)

total2 = 0
for group in groups:
	common = ""
	for letter in letters:
		if letter in group[0] and letter in group[1] and letter in group[2]:
			common = letter

	total2 += item_priority(common)

print(total)
print(total2)
